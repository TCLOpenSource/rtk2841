/*
 * $Id: RPCintr.c,v 1.10 2004/8/4 09:25 Jacky Exp $
 */
#include <linux/module.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>     /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/ioctl.h>    /* needed for the _IOW etc stuff used later */
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/freezer.h>
#include <linux/kmsg_dump.h>
#include <rtk_kdriver/RPCDriver.h>

#include <asm/io.h>
#include <asm/uaccess.h>    /* copy_to_user() copy_from_user() */


enum log_flags {
	LOG_NOCONS	= 1,	/* already flushed, do not print to console */
	LOG_NEWLINE	= 2,	/* text ended with a newline */
	LOG_PREFIX	= 4,	/* text started with a prefix */
	LOG_CONT	= 8,	/* text is a fragment of a continuation line */
};

#define __RPCLOG_BUF_LEN (32*1024)
#define LOG_LINE_MAX     (1024)
#define PREFIX_MAX		0

struct rpclog {
	u16 len;		/* length of entire record */
	u16 text_len;		/* length of text buffer */
	u16 flags;		/* internal record flags */
	u16 level;		/* syslog level */	
};

#define RPCLOG_ALIGN __alignof__(struct rpclog)

/* index and sequence number of the first record stored in the buffer */
static u64 log_first_seq;
static u32 log_first_idx;

/* index and sequence number of the next record to store in the buffer */
static u64 log_next_seq;
static u32 log_next_idx;

/* the next printk record to read after the last 'clear' command */
static u64 clear_seq;
static u32 clear_idx;


static char __rpclog_buf[__RPCLOG_BUF_LEN] __aligned(RPCLOG_ALIGN);
static char *rpclog_buf = __rpclog_buf;
static u32 rpclog_buf_len = __RPCLOG_BUF_LEN;
static DEFINE_RAW_SPINLOCK(rpclogbuf_lock);

int enable_print =1;

/* human readable text of the record */
static char *log_text(const struct rpclog *msg)
{
	return (char *)msg + sizeof(struct rpclog);
}

/* get record by index; idx must point to valid msg */
static struct rpclog *log_from_idx(u32 idx)
{
	struct rpclog *msg = (struct rpclog *)(rpclog_buf + idx);

	/*
	 * A length == 0 record is the end of buffer marker. Wrap around and
	 * read the message at the start of the buffer.
	 */
	if (!msg->len)
		return (struct rpclog *)rpclog_buf;
	return msg;
}

static u32 log_next(u32 idx)
{
	struct rpclog *msg = (struct rpclog *)(rpclog_buf + idx);

	/* length == 0 indicates the end of the buffer; wrap */
	/*
	 * A length == 0 record is the end of buffer marker. Wrap around and
	 * read the message at the start of the buffer as *this* one, and
	 * return the one after that.
	 */
	if (!msg->len) {
		msg = (struct rpclog *)rpclog_buf;
		//enable_print = 0;
		return msg->len;
	}
	return idx + msg->len;
}

static size_t print_time(u64 ts, char *buf)
{
	unsigned long rem_nsec;

	rem_nsec = do_div(ts, 1000000000);

	if (!buf)
		return snprintf(NULL, 0, "[%5lu.000000] ", (unsigned long)ts);

	return sprintf(buf, "[%5lu.%06lu] ",
		       (unsigned long)ts, rem_nsec / 1000);
}

static size_t msg_print_text(const struct rpclog *msg, enum log_flags prev,
			     bool syslog, char *buf, size_t size)
{
	const char *text = log_text(msg);
	size_t text_size = msg->text_len;
	bool prefix = true;
	bool newline = true;
	size_t len = 0;

	if ((prev & LOG_CONT) && !(msg->flags & LOG_PREFIX))
		prefix = false;

	if (msg->flags & LOG_CONT) {
		if ((prev & LOG_CONT) && !(prev & LOG_NEWLINE))
			prefix = false;

		if (!(msg->flags & LOG_NEWLINE))
			newline = false;
	}

	do {
		const char *next = memchr(text, '\n', text_size);
		size_t text_len;


		if (next) {
			text_len = next - text;
			next++;
			text_size -= next - text;
		} else {
			text_len = text_size;
		}
		if (buf) {
			memcpy(buf + len, text, text_len);
			len += text_len;
			if (next || newline) {
				buf[len++] = '\n';
			}
			
				
		} else {
			/* SYSLOG_ACTION_* buffer size only calculation */
/*			
			if (prefix)
				len += print_prefix(msg, syslog, NULL);
*/				
			len += text_len;
			//if (next || newline)
			//	len++;
		}

		prefix = true;
		text = next;
	} while (text);

	return len;
}


void rpclog_store(const char *text, u16 text_len)
{
	struct rpclog *msg;
	u32 size, time_text_len;	
	char time_text[32];

	time_text_len = print_time(local_clock(),time_text);

	size = sizeof(struct rpclog) + time_text_len + text_len;


	while (log_first_seq < log_next_seq) {
		u32 free;

		if (log_next_idx > log_first_idx)
			free = max(rpclog_buf_len - log_next_idx, log_first_idx);
		else
			free = log_first_idx - log_next_idx;

		if (free > size + sizeof(struct rpclog))
			break;

		/* drop old messages until we have enough contiuous space */
		log_first_idx = log_next(log_first_idx);
		log_first_seq++;
	}

	if (log_next_idx + size + sizeof(struct rpclog) >= rpclog_buf_len) {
		/*
		 * This message + an additional empty header does not fit
		 * at the end of the buffer. Add an empty header with len == 0
		 * to signify a wrap around.
		 */
		memset(rpclog_buf + log_next_idx, 0, sizeof(struct rpclog));
		log_next_idx = 0;
	}

	/* fill message */
	msg = (struct rpclog *)(rpclog_buf + log_next_idx);
	memcpy(log_text(msg), time_text, time_text_len);
	memcpy(log_text(msg)+time_text_len, text, text_len);
	msg->text_len = text_len + time_text_len;
	msg->len = sizeof(struct rpclog) + text_len + time_text_len;


	/* insert message */
	log_next_idx += msg->len;
	log_next_seq++;
}


static int rpclog_vprintk_emit(const char *fmt, va_list args)
{
	static char textbuf[LOG_LINE_MAX];
	char *text = textbuf;
	size_t text_len;

	raw_spin_lock(&rpclogbuf_lock);

	text_len = vscnprintf(text, sizeof(textbuf), fmt, args);
	rpclog_store(textbuf, text_len);

	raw_spin_unlock(&rpclogbuf_lock);
	return 1;
}


int rpclog_printk(const char *fmt, ...)
{
	va_list args;
	int r;

	if (!enable_print) return 0;

	va_start(args, fmt);
	r = rpclog_vprintk_emit(fmt, args);
	va_end(args);

	return r;
}

int rpclog_dump_all(int size, bool clear)
{
	char *text;
	int len = 0;

	text = kmalloc(LOG_LINE_MAX + PREFIX_MAX, GFP_KERNEL);
	if (!text)
		return -ENOMEM;

	raw_spin_lock_irq(&rpclogbuf_lock);
	/* if (buf)*/ 
	{ 
		u64 next_seq;
		u64 seq;
		u32 idx;
		enum log_flags prev;

		if (clear_seq < log_first_seq) {
			/* messages are gone, move to first available one */
			clear_seq = log_first_seq;
			clear_idx = log_first_idx;
		}

		/* move first record forward until length fits into the buffer */
		seq = clear_seq;
		idx = clear_idx;
		prev = 0;
		while (len > size && seq < log_next_seq) {
			struct rpclog *msg = log_from_idx(idx);

			len -= msg_print_text(msg, prev, true, NULL, 0);
			prev = msg->flags;
			idx = log_next(idx);
			seq++;
		}

		/* last message fitting into this dump */
		next_seq = log_next_seq;

		len = 0;
		prev = 0;
		while (len >= 0 && seq < next_seq) {
			struct rpclog *msg = log_from_idx(idx);
			int textlen;

			textlen = msg_print_text(msg, prev, true, text,
						 LOG_LINE_MAX + PREFIX_MAX);
			if (textlen < 0) {
				len = textlen;
				break;
			}
			idx = log_next(idx);
			seq++;
			prev = msg->flags;

			raw_spin_unlock_irq(&rpclogbuf_lock);
			pr_alert("%s",text);

			/*
			if (copy_to_user(buf + len, text, textlen))
				len = -EFAULT;
			else
				len += textlen;
			*/
			raw_spin_lock_irq(&rpclogbuf_lock);

			if (seq < log_first_seq) {
				/* messages are gone, move to next one */
				seq = log_first_seq;
				idx = log_first_idx;
				prev = 0;
			}
		}
	} 

	if (clear) {
		clear_seq = log_next_seq;
		clear_idx = log_next_idx;
	}
	raw_spin_unlock_irq(&rpclogbuf_lock);

	kfree(text);
	return len;
}