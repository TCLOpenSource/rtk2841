/**
 *      basic HDCP 2.2 APIs for HDMI control
 *
 *      TODO items:
 *          - [V] provide other necessary callback functions.
 *          - [V] before thread join, caller should stop rx_status polling loop
 *          - [ ] handle nego failed condition, maybe disable vout or something
 */
#define LOG_TAG "RTKHDCPAPI"



#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/HDCPTX22.h>

#define START_HDCP_DELAY    4
#define FORCE_ALWAYS_REPORT_HDCP22  0

#define RX_INFO_STORED_FILE "/mnt/hdcpRxInfo"

// refer to HDCP spec 2.14 HDCP Port define.
#define HDCP_SLAVE_ADDR     0x3A

#define OFFSET_HDCP2VSN     0x50
#define OFFSET_WRITE_MSG    0x60
#define OFFSET_RX_STATUS    0x70
#define OFFSET_READ_MSG     0x80

// ****************************************************************
// ugly coding style, copy i2c_msg structure from linux i2c header
// master interface.
struct i2c_msg {
  unsigned short addr;
  unsigned short flags;
#define I2C_M_TEN		    0x0010
#define I2C_M_RD		    0x0001
#define I2C_M_NOSTART		0x4000
#define I2C_M_REV_DIR_ADDR	0x2000
#define I2C_M_IGNORE_NAK	0x1000
#define I2C_M_NO_RD_ACK		0x0800
#define I2C_M_RECV_LEN		0x0400
  unsigned short len;
  unsigned char * buf;
};

struct i2c_rdwr_ioctl_data {
    struct i2c_msg *msgs;     /* pointers to i2c_msgs */
    unsigned int nmsgs;      /* number of i2c_msgs */
};

#define I2C_RDWR            0x0707
// ****************************************************************
#define LOG printk

//static HDCPTx22 *mHDCP=NULL;
extern HdcpTxParam hdcptx_parm;

typedef void (*auth_complete_handler)(UINT8 *riv, UINT32 riv_size, UINT8 *ks, UINT32 ks_size);
typedef void (*disable_hdcp_session_handler)(void);

// basic handlers
static auth_complete_handler mAuthCompleteHandler=NULL;
static disable_hdcp_session_handler mDisableHDCPHandler=NULL;

//static pthread_t hdcp_thread=0;
//static int mfd=-1;
//static unsigned char read_addr = OFFSET_READ_MSG;
//static unsigned char rx_status_addr = OFFSET_RX_STATUS;
//static unsigned char hdcp2vns_addr = OFFSET_HDCP2VSN;
static char m_keep_hdcp_nego=1;

static struct file *pf=NULL;

void init_rx_info_storage(void);
void deinit_rx_info_storage(void);

void save_rx_record(UINT8 *rID, INT32 rIDSize,
		UINT8 *km, INT32 kmSize,
		UINT8 *ekhkm, INT32 ekhkmSize,
		UINT8* m, INT32 mSize);
INT32 find_km_ekhkm_by_rId(
		UINT8* rID, INT32 rIDSize,
		UINT8 *km, INT32 kmSize,
		UINT8 *ekhkm, INT32 ekhkmSize,
		UINT8* m, INT32 mSize);

void hexline_to_char_array(
        UINT8* line,
        INT32 length,
        UINT8* char_array,
        INT32 char_array_size);

#if 0
static void i2c_init()
{
    mfd = open("/dev/i2c-1",O_RDWR);
    LOG("i2c_init mfd: %d\n",mfd);
}

static void i2c_uninit()
{
    if(mfd>=0)
    {
        close(mfd);
        mfd=-1;
    }
}

static int XferMsg(struct i2c_msg* p_msgs, unsigned char n_msg)
{
    struct i2c_rdwr_ioctl_data  msgset;
    
    msgset.msgs  = p_msgs;
    msgset.nmsgs = n_msg;

    if (ioctl(mfd, I2C_RDWR, &msgset) < 0)
        return -1;
    else
        return 1;
}

// some static I/O functions that using I2C Bus.
static HDCP_RST i2c_read_rx_status(INT8 *reauth, INT8 *ready, INT32 *msg_size)
{
    if(mfd<0) return HDCP_FALSE;

    struct i2c_msg msgs[2];
    INT8 rx_status[2]={0};

    msgs[0].addr = HDCP_SLAVE_ADDR;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = &rx_status_addr;

    msgs[1].addr = HDCP_SLAVE_ADDR;
    msgs[1].flags = I2C_M_RD;
    msgs[1].len = 2;
    msgs[1].buf = (unsigned char *)rx_status;

    int rst = XferMsg(msgs,2);
    if(rst<=0)
        return HDCP_FALSE;

    *msg_size = (INT32)((rx_status[0]&0xff) | ((rx_status[1]&0x3)<<8));
    *ready = (rx_status[1]>>2)&0x1;
    *reauth = (rx_status[1]>>3)&0x1;
    return HDCP_TRUE;
}

static INT32 i2c_read_burst(INT8 *buf, INT32 size)
{
    if(mfd<0) return -1;
    
    // prepare parameters..
    struct i2c_msg msgs[2];
    
    msgs[0].addr = HDCP_SLAVE_ADDR;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = &read_addr;

    msgs[1].addr = HDCP_SLAVE_ADDR;
    msgs[1].flags = I2C_M_RD;
    msgs[1].len = size;
    msgs[1].buf = (unsigned char *)buf;

    int rst = XferMsg(msgs,2);

    if(rst<=0)
    {
        LOG("i2c_read_burst failed!\n");
        return 0;
    }
    
    return size;
}

// un-used function
static INT32 i2c_read(INT8 *buf, INT32 size)
{
    if(mfd<0) return -1;
    
    // prepare parameters..
    struct i2c_msg msgs[2];
    INT8 msg_buf[1]={0};

    for(int i=0;i<size;i++)
    {
        msgs[0].addr = HDCP_SLAVE_ADDR;
        msgs[0].flags = 0;
        msgs[0].len = 1;
        msgs[0].buf = &read_addr;

        msgs[1].addr = HDCP_SLAVE_ADDR;
        msgs[1].flags = I2C_M_RD;
        msgs[1].len = 1;
        msgs[1].buf = (unsigned char *)msg_buf;

        int rst = XferMsg(msgs,2);

        if(rst<=0)
        {
            LOG("i2c_read failed!\n");
            return 0;
        }
        else
        {
            buf[i]=msg_buf[0];
        }
    }
    return size;
}

static INT32 i2c_write_burst(INT8 *buf, INT32 size)
{
    //LOG("i2c_write (burst mode) mfd: %d\n",mfd);
    if(mfd<0) return -1;

    unsigned char *msg_buf=(unsigned char *)malloc(size+1);
    msg_buf[0]=OFFSET_WRITE_MSG;
    memcpy(msg_buf+1,buf,size);
    
    struct i2c_msg msg;
    
    msg.addr = HDCP_SLAVE_ADDR;
    msg.flags = 0;
    msg.len = size+1;
    msg.buf = (unsigned char *)msg_buf;

    int rst = XferMsg(&msg,1);
    // failed condition
    if(rst<=0)
    {
        LOG("i2c_write_burst failed!\n");
        return 0;
    }
    free(msg_buf);
    //LOG("i2c_write success!\n");
    return size;
}

// un-used function
static INT32 i2c_write(INT8 *buf, INT32 size)
{
    if(mfd<0) return -1;

    struct i2c_msg msg;
    INT8 msg_buf[2]={0};
    msg_buf[0]=OFFSET_WRITE_MSG;
    
    for(int i=0;i<size;i++)
    {
        msg_buf[1]=buf[i];
        msg.addr = HDCP_SLAVE_ADDR;
        msg.flags = 0;
        msg.len = 2;
        msg.buf = (unsigned char *)msg_buf;

        int rst = XferMsg(&msg,1);
        // failed condition
        if(rst<=0)
        {
            return 0;
        }
    }
    return size;
}

static INT32 i2c_can_read(INT32 size)
{
    if(mfd<0) return -1;

    unsigned char rx_status[2]={0};    
    struct i2c_msg msgs[2];

    msgs[0].addr = HDCP_SLAVE_ADDR;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = &rx_status_addr;
    
    msgs[1].addr = HDCP_SLAVE_ADDR;
    msgs[1].flags = I2C_M_RD;
    msgs[1].len = 2;
    msgs[1].buf = rx_status;

    int rst = XferMsg(msgs,2);
    if(rst>0)
    {
        INT32 message_size = rx_status[0] | ((rx_status[1]&0x3)<<8);
        INT8 reauth_req = (rx_status[1]>>3)&0x1;
#if 0
        if(message_size>0 || reauth_req>0)
        {
            LOG("\033[0;33;33mi2c_can_read msg_size: %d reauth_req: %d rx_status[1]=%.2x\033[m\n",
                message_size,
                reauth_req,
                rx_status[1]&0xff);
        }
#endif
        if(message_size==size)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}
#endif
void *pthread_entry(void *x_void_ptr)
{
	int i;
	HDCP_ERR err_code=HDCP_ERR_UNDEFINED;
    LOG("\033[0;31;31m[HDCP] pthread_entrt start\033[m\n");
    // delay 10 seconds
    for(i=0;i<START_HDCP_DELAY;i++)
    {
        if(m_keep_hdcp_nego!=1)
            break;
        LOG("\033[0;31;31m[HDCP] down count %d seconds before start\033[m\n",(START_HDCP_DELAY-i));
        //sleep(1);
    }
    
    
    err_code = start_hdcp_nego();
    LOG("\033[0;31;31m exit HDCP nego thread error_code = %s\033[m\n",hdcp_err_str[err_code]);
    // TODO: disable VOut or other policy..
    return NULL;
}

static void start_hdcp_nego_process(void)
{
   // pthread_create(&hdcp_thread,NULL,pthread_entry,NULL);
	pthread_entry(NULL);
}

int disable_hdcptx_22(void)
{
    LOG("\033[0;31;31m[HDCP]disable_hdcptx_22\033[m\n");
    // make sure that the thread has been released
   // if(hdcp_thread>0)
    {
        //if(mHDCP!=NULL)
        {
            stop_hdcp_nego();
            stop_hdcp_polling_rx_status();
        }
        //pthread_join(hdcp_thread,NULL);
        //hdcp_thread=0;
        LOG("\033[0;31;31m[HDCP]join hdcp thread complete.\033[m\n");
    }
    // release hdcp core engine.
    //if(mHDCP!=NULL)
    //{
     //   delete mHDCP;
      //  mHDCP=NULL;
    //}

    //i2c_uninit();
    deinit_rx_info_storage();
    // disable HDCP 
    if(mDisableHDCPHandler!=NULL)
        mDisableHDCPHandler();
    
    return 1;
}

int enable_hdcptx_22(void)
{
    LOG("\033[0;31;31m[HDCP]enable_hdcptx_22\033[m\n");

    // remove current session.
   // disable_hdcptx_22(); //zhaodong_yin
    
   // if(mHDCP!=NULL)
   // {
    //    delete mHDCP;
    //    mHDCP = NULL;
  // }
    //init_rx_info_storage();
   // i2c_init();
    m_keep_hdcp_nego=1;
    // init HDCP core engine.
    //mHDCP = new HDCPTx22();
    // feed all necessary IO functions, here a I2C interface is applied.
   // read_fun = &i2c_read_burst;
    //write_fun = &i2c_write_burst;
   // check_read_fun = &i2c_can_read;
    hdcptx_parm.store_rx_info_fun = &save_rx_record;
    hdcptx_parm.find_km_ekhkm_fun = &find_km_ekhkm_by_rId;
   // read_rx_status_fun = &i2c_read_rx_status;
    hdcptx_parm.auth_complete_fun = mAuthCompleteHandler;
    // when re-auth is requested, disable current HDCP session.
    hdcptx_parm.reauth_handler_fun = mDisableHDCPHandler;

    start_hdcp_nego_process();
    
    return 1;
}
#if 0
int get_hdcp_22_version_bit()
{
#if(FORCE_ALWAYS_REPORT_HDCP22)
    return 1;
#endif

    i2c_init();
    // if open I2C failed, just report no HDCP 2.2 feature.
    if(mfd<0)
    {
        LOG("\033[0;31;31m[HDCP] get_hdcp_22_version_bit get i2c failed.\033[m\n");
        return 0;
    }

    struct i2c_msg msgs[2];
    INT8 hdcp2vsn[1]={0};

    msgs[0].addr = HDCP_SLAVE_ADDR;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = &hdcp2vns_addr;
    
    msgs[1].addr = HDCP_SLAVE_ADDR;
    msgs[1].flags = I2C_M_RD;
    msgs[1].len = 1;
    msgs[1].buf = (unsigned char *)hdcp2vsn;

    int rst = XferMsg(msgs,2);
    i2c_uninit();
    
    if(rst<=0)
        return 0;
    
    LOG("\033[0;32;32m[HDCP22]get_hdcp_22_version_bit 0x%.2x.\033[m\n",hdcp2vsn[0]);
    if(hdcp2vsn[0]==0x4)
        return 1;
    else
        return 0;
}
#endif
void set_hdcp_22_auth_complete_handler(auth_complete_handler handler)
{
    mAuthCompleteHandler=handler;
}

void set_hdcp_22_disable_hdcp_session_handler(disable_hdcp_session_handler handler)
{
    mDisableHDCPHandler=handler;
}

// service routine of ake_stored_km
void init_rx_info_storage(void)
{
    if(pf==NULL)
    {
        pf = filp_open(RX_INFO_STORED_FILE, O_RDWR | O_CREAT, 0444);
    }
}

void deinit_rx_info_storage()
{
    if(pf!=NULL)
    {
        filp_close(pf, 0);
        pf=NULL;
    }
}

void save_rx_record(UINT8 *rID, INT32 rIDSize,
		UINT8 *km, INT32 kmSize,
		UINT8 *ekhkm, INT32 ekhkmSize,
		UINT8* m, INT32 mSize)
{
	//int i;
	UINT8 temp_buf[128] = {0};
	mm_segment_t fs;
	loff_t pos;
	struct file *file = filp_open(RX_INFO_STORED_FILE, O_RDWR | O_CREAT, 0444);
	if(file==NULL)
	{
		pr_debug("open RX_INFO_STORED_FILE ERROR!\n");
		return ;
	}
	fs = get_fs();
	set_fs(KERNEL_DS);
	pos = 0;
	
	memcpy(temp_buf, rID, rIDSize);
	memcpy(temp_buf+rIDSize, km, kmSize);
	memcpy(temp_buf+rIDSize+kmSize, ekhkm, ekhkmSize);
	memcpy(temp_buf+rIDSize+kmSize+ekhkmSize, m, mSize);
	*(temp_buf+rIDSize+kmSize+ekhkmSize+mSize) = '\n';
	*(temp_buf+rIDSize+kmSize+ekhkmSize+mSize+1) = '\0';

	vfs_write(file, temp_buf, rIDSize+kmSize+ekhkmSize+mSize+1, &pos);
	filp_close(file, 0);
	set_fs(fs);
#if 0
	for(i=0;i<rIDSize;i++)
	{
		//fprintf(file,"%.2x",(UINT8)(rID[i]&0xff));
	}

	for(i=0;i<kmSize;i++)
	{
		//fprintf(file,"%.2x",(UINT8)(km[i]&0xff));
	}

	for(i=0;i<ekhkmSize;i++)
	{
		//fprintf(file,"%.2x",(UINT8)(ekhkm[i]&0xff));
	}

	for(i=0;i<mSize;i++)
	{
		//fprintf(file,"%.2x",(UINT8)(m[i]&0xff));
	}

	//fprintf(file,"\n");
#endif
}


void hexline_to_char_array(UINT8* line, INT32 length, UINT8* char_array, INT32 char_array_size)
{
	INT32 loop = length/2;
	UINT8 buf[2];
	UINT8 *pt=line;
	INT32 j=0;
	int i;
	UINT8 number;
	for(i=0;i<loop;i++)
	{
		// copy 2 characters to buf
		buf[0]=*pt;
		buf[1]=*(pt+1);

		number = (UINT8)simple_strtoul((const char *)buf, NULL, 16);
		char_array[j]=number;

		// update j
		j=j+1;
		// update pt
		pt = pt+2;
	}
}


INT32 find_km_ekhkm_by_rId(
		UINT8* rID, INT32 rIDSize,
		UINT8 *km, INT32 kmSize,
		UINT8 *ekhkm, INT32 ekhkmSize,
		UINT8* m, INT32 mSize)
{
	struct file *file = filp_open(RX_INFO_STORED_FILE,O_RDONLY, 0444);
	// malloc rID buffer
	UINT8* pRID = (UINT8*)kcalloc(rIDSize, sizeof(unsigned char), GFP_KERNEL);

	UINT8 * line = (UINT8*)kcalloc(54, sizeof(unsigned char), GFP_KERNEL);
	size_t len = 54;
	ssize_t read;
	INT32 foundLine=-1;
	size_t pos = 0;
	UINT8* pKm;
	UINT8* pEkhkm;
	UINT8* pM;
	if(file==NULL)
	{
		pr_debug("open RX_INFO_STORED_FILE ERROR!\n");
		return -1;
	}
	
	while ((read = kernel_read(file, pos, line, len)) != -1)
	{
		//LOG("[HDCP] find ekhkm in record - read size:%d\n",read);
		//LOG("[HDCP] find ekhkm in record - read line:[%s]\n",line);

		//if(read==107)
		{
			// read rID
			//hexline_to_char_array((UINT8*)line,rIDSize*2,pRID,rIDSize);
			memcpy(pRID, line, rIDSize);
			// compare rID
			if(memcmp(pRID,rID,rIDSize)==0)
			{
				//LOG("[HDCP] find ekhkm in record - Found rID in record.\n");
				// report km
				pKm = (UINT8*)(line+(rIDSize));
				memcpy(km, pKm, kmSize);
				//hexline_to_char_array(pKm,kmSize*2,km,kmSize);
				// report ekhkm
				pEkhkm = pKm+(kmSize);
				memcpy(ekhkm, pEkhkm, ekhkmSize);
				//hexline_to_char_array(pEkhkm,ekhkmSize*2,ekhkm,ekhkmSize);
				// report m
				pM = pEkhkm+(ekhkmSize);
				memcpy(m, pM, mSize);
				//hexline_to_char_array(pM,mSize*2,m,mSize);
				foundLine=1;
				break;
			}
			else
				pos += len;
		}

	}

	if(line) kfree(line);
	filp_close(file, 0);
	if(pRID!=NULL) kfree(pRID);
	return foundLine;
}
