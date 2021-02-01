#include <linux/init.h>
#include <linux/kmsg_dump.h>
#include <linux/console.h>

extern void printch(int);

static void raw_write(const char *s, unsigned n)
{
	while (n-- > 0) {
		if (*s == '\n')
			printch('\r');
		printch(*s);
		s++;
	}
}

static void raw_kmsg_dump(struct kmsg_dumper *dumper,
                         enum kmsg_dump_reason reason)
{
	static char line[1024];
	size_t len;

	if(!is_console_locked())
		return;

	kmsg_dump_forward_to_console_idx(dumper);
	while (kmsg_dump_get_line(dumper, true, line, sizeof(line), &len))
		raw_write(line, len);
}

static struct kmsg_dumper raw_dumper = {
	.dump = raw_kmsg_dump,
};

static int __init setup_raw_kmsg_dump(char *buf)
{
	kmsg_dump_register(&raw_dumper);
	return 0;
}
early_param("suspendprintk", setup_raw_kmsg_dump);
