//Copyright (C) 2007-2015 Realtek Semiconductor Corporation.

#include <linux/interrupt.h>
#include <asm/io.h>
//#include <linux/nmi.h>
#include <asm/sections.h>
#include <mach/rtk_platform.h>

// SET 4
#define SCPU_MEM_TRASH_DBG_START_0 0xB805C020
#define SCPU_MEM_TRASH_DBG_END_0 0xB805C030
#define SCPU_MEM_TRASH_DBG_CTRL_0 0xB805C040

#define SCPU_MEM_TRASH_DBG_INT 0xB805C050
#define SCPU_MEM_TRASH_DBG_ADDR 0xB805C054
#define SCPU_MEM_TRASH_DBG_RW 0xB805C058

#define WRAPPER_NUM 4

typedef enum
{
    WRAPPER_READ_WRITE=0,
    WRAPPER_READ=1,
    WRAPPER_WRTIE=2,
}WRAPPER_RW;

static int arm_wrapper_set_id=1;
static unsigned int wrapper_start[WRAPPER_NUM];
static unsigned int wrapper_end[WRAPPER_NUM];
static unsigned int wrapper_ctrl[WRAPPER_NUM];

void arm_wrapper_dump (void)
{
    int i=0;
    pr_err("\n\n");

    for (i=0; i<WRAPPER_NUM; i++)
    {
        pr_err("set%d: 0x%08x [0x%08x]  - 0x%08x [0x%08x], 0x%08x [0x%08x]\n",
            i+1,(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),
            (SCPU_MEM_TRASH_DBG_END_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
            (SCPU_MEM_TRASH_DBG_CTRL_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i));
    }

    pr_err("dbg_int:   0x%08x [0x%08x]\n",SCPU_MEM_TRASH_DBG_INT,rtd_inl(SCPU_MEM_TRASH_DBG_INT));
    pr_err("dbg_addr:  0x%08x [0x%08x]\n",SCPU_MEM_TRASH_DBG_ADDR,rtd_inl(SCPU_MEM_TRASH_DBG_ADDR));

    pr_err("\n\n");
}

irqreturn_t arm_wrapper_intr (int irq, void *dev_id);

void dump_stacks (void);
int clear_arm_wrapper_arange (int set_id)
{
    int id=set_id-1;
    if (set_id<1||id>WRAPPER_NUM)
    {
        return -1;
    }

    unsigned int start_reg=SCPU_MEM_TRASH_DBG_START_0+id*4;
    unsigned int end_reg =SCPU_MEM_TRASH_DBG_END_0+id*4;
    unsigned int ctrl_reg =SCPU_MEM_TRASH_DBG_CTRL_0+id*4;

    unsigned int arm_wrapper_disable=BIT(4) | BIT(1);
    //printk("arm_wrapper_enable=%x\n",arm_wrapper_enable);

    rtd_outl(ctrl_reg,arm_wrapper_disable);
    rtd_outl(start_reg, 0);
    rtd_outl(end_reg, 0);
    return 0;
}

int set_arm_wrapper_arange (unsigned int start,unsigned int end,int set_id,WRAPPER_RW rw)
{
    int id=set_id-1;//int id=find_free_dbg_register();
    unsigned int start_reg=SCPU_MEM_TRASH_DBG_START_0+id*4;
    unsigned int end_reg =SCPU_MEM_TRASH_DBG_END_0+id*4;
    unsigned int ctrl_reg =SCPU_MEM_TRASH_DBG_CTRL_0+id*4;
    
    if (id<0||id>3)
    {
        return -1;
    }

    int arm_wrapper_enable=BIT(1)|BIT(0)|BIT(4)|((int)rw<<2);
    int arm_wrapper_disable=BIT(1);
    //printk("arm_wrapper_enable=%x\n",arm_wrapper_enable);

    rtd_outl(ctrl_reg,arm_wrapper_disable);

    rtd_outl(start_reg, start);
    rtd_outl(end_reg, end);

#if 1
    rtd_outl(ctrl_reg,arm_wrapper_enable);
#else
    rtd_outl(ctrl_reg,arm_wrapper_enable|BIT(4)|BIT(2));
#endif
        arm_wrapper_set_id = (set_id%WRAPPER_NUM)+1;

    return 0;
}

//cat /sys/realtek_boards/arm_wrapper
void arm_wrapper_get (void)
{
    int i=0;

    //char* cpu_enable;
    char* read_write[]= {"R/W  ","read","write","R/W  "};
    unsigned int ctrl;

    for (i=0; i<WRAPPER_NUM; i++)
    {
        ctrl=rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+i*4);
        if (ctrl&BIT(0))
        {
            pr_err("set%d: 0x%08x-0x%08x, 0x%08x[ctrl]. \e[1;31m %s monitor enabled!\e[0m\n",
                i+1,rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
                rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i),read_write[ctrl>>2&0x3]);
        }
        else
        {
            pr_err("set%d: 0x%08x-0x%08x, 0x%08x[ctrl].\n",
                i+1,rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
                rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i));
        }
    }

    pr_err("dbg_int:   0x%08x-0x%08x\n",SCPU_MEM_TRASH_DBG_INT,rtd_inl(SCPU_MEM_TRASH_DBG_INT));
    pr_err("dbg_addr:  0x%08x-0x%08x\n",SCPU_MEM_TRASH_DBG_ADDR,rtd_inl(SCPU_MEM_TRASH_DBG_ADDR));
    pr_err("\n\n");
}

void arm_wrapper_show_last_set(void)
{
        char* cpu_enable;
        char* read_write[]= {"R/W  ","read","write","R/W  "};
        unsigned int ctrl;
        int i;
        int last_set_id = ((arm_wrapper_set_id-1)?(arm_wrapper_set_id-1):4);
        
        for (i=0; i<WRAPPER_NUM; i++){
                ctrl=rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+i*4);
                if((i+1) == last_set_id){
                        if (ctrl&BIT(0))
                        {
                            pr_err("\e[1;33mset%d: 0x%08x-0x%08x, 0x%08x[ctrl]. %s monitor enabled!\e[0m\n",
                                i+1,rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
                                rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i),read_write[ctrl>>2&0x3]);
                        }
                        else
                        {
                            pr_err("\e[1;33mset%d: 0x%08x-0x%08x, 0x%08x[ctrl].\e[0m\n",
                                i+1,rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
                                rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i));
                        }
                }else{
                        if (ctrl&BIT(0))
                        {
                            pr_err("set%d: 0x%08x-0x%08x, 0x%08x[ctrl]. \e[1;31m %s monitor enabled!\e[0m\n",
                                i+1,rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
                                rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i),read_write[ctrl>>2&0x3]);
                        }
                        else
                        {
                            pr_err("set%d: 0x%08x-0x%08x, 0x%08x[ctrl].\n",
                                i+1,rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i),rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i),
                                rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i));
                        }
                }
        }
        pr_err("\n\n");
    
}

//echo "set2,18061500," > /sys/realtek_boards/arm_wrapper
void arm_wrapper_set (const char *buffer)
{
    unsigned int start,end;
    unsigned int set_id;
    char str_rw[3];
    WRAPPER_RW rw;
    str_rw[2]=0;
    unsigned int access_addr = 0;
	
        if(strncmp("show_set",buffer,strlen("show_set")) == 0)
        {
                arm_wrapper_show_last_set();
                return;
        }

    if (strncmp("set",buffer,strlen("set")))
    {
        goto Fail;
    }

    if (buffer[3]-'0'<1 ||buffer[3]-'0'>WRAPPER_NUM)
    {   
        pr_err("arm wrapper set failed, expected range[1-%d] \n", WRAPPER_NUM);
        goto Fail;
    }
    set_id=buffer[3]-'0';

    if (strncmp(&buffer[5],"clear",5)==0)
    {
        clear_arm_wrapper_arange(set_id);
        return;
    }

    //eg:  echo "set1 read 0x18404000" > /sys/realtek_boards/arm_wrapper
    if (strncmp(&buffer[5],"read",4)==0)
    {
        if(sscanf(buffer, "set%d read %x", &set_id, &start)<1)
        {
            pr_err("arm wrapper read failed, invalid argument - %s\n", buffer);
            goto Fail;               
        }
        pr_info("[%s,%d,%s] read addr = 0x%x\n",__FILE__,__LINE__,__FUNCTION__,start); 
        access_addr = phys_to_virt(start);
        rtd_inl(access_addr);

        return;
    }
    //eg:  echo "set1 write 0x18404000" > /sys/realtek_boards/arm_wrapper
    if (strncmp(&buffer[5],"write",5)==0)
    {
        if(sscanf(buffer, "set%d write %x", &set_id, &start)<1)
        {
            pr_err("arm wrapper write failed, invalid argument - %s\n", buffer);
            goto Fail;            
        }
        pr_info("[%s,%d,%s] write addr = 0x%x\n",__FILE__,__LINE__,__FUNCTION__,start);
        access_addr = phys_to_virt(start);
        rtd_outl(access_addr,0);
        
        return;
    }

    if (sscanf(buffer, "set%d %x-%x %2s", &set_id,&start,&end,str_rw)<1)
    {
        pr_err("arm wrapper set failed, invalid argument - %s\n", buffer);
        goto Fail;
    }
    else
    {
        if(start > end)
        {
            pr_err("\n arm wrapper set failed, MT start range:0x%08x > end range:0x%08x\n", start,end);
            goto Fail;  
        }
        if (strncmp("r",str_rw,1)==0)
        {
            rw=WRAPPER_READ;
        }
        else if (strncmp("w",str_rw,1)==0)
        {
            rw=WRAPPER_WRTIE;
        }
        else if (strncmp("rw",str_rw,2)==0)
        {
            rw=WRAPPER_READ_WRITE;
        }
        else
        {
            goto Fail;
        }
    }

    if(set_arm_wrapper_arange(start,end,set_id,rw)==0)
    {
        rtd_outl(SCPU_MEM_TRASH_DBG_INT, BIT(3)| BIT(0));
        //printk("arm wrapper set OK\n");
        //arm_wrapper_dump();
        return;
    }

Fail:
    pr_err("%s fail.  %s\n\n\n",__func__,buffer);//0x00cd2d00[start], 0xb805c030-0x00cd2d40

    pr_err("\e[1;32marm wrapper related commands as follow\e[0m: (set no must between 1 and 4)\n");
    pr_err("cat /sys/realtek_boards/arm_wrapper\n");
    pr_err("echo \"set2 0x00cd2d00-0x00cd2d40 rw\" > /sys/realtek_boards/arm_wrapper\n");
    pr_err("echo \"set2 clear\" > /sys/realtek_boards/arm_wrapper\n\n\n");
    return ;
}

int get_arm_wraper_set_id(void)
{
        return arm_wrapper_set_id;
}

irqreturn_t arm_wrapper_intr (int irq, void *dev_id)
{
    int value=0;
    int read_write=rtd_inl(SCPU_MEM_TRASH_DBG_RW)&BIT(0);
    int trap_address=rtd_inl(SCPU_MEM_TRASH_DBG_ADDR);

    //SCPU or ACPU,VCPU issued an invalid address access
    value=rtd_inl(SCPU_MEM_TRASH_DBG_INT);
    if(!(value & BIT(4)))
    {
        pr_err("%s %d. 0x%08x\n",__func__,__LINE__,value);
        return IRQ_NONE;
    }

    //printk("%s %d\n",__func__,__LINE__);
    pr_err("\n\n\n\n");
    pr_err("[Memory trash] SCPU has trashed itself: \e[1;31m%s 0x%08x\e[0m invalid.\n\n",
           read_write?"write":"read",trap_address);

	arm_wrapper_dump();
    //value=(value&(~ (BIT(0)|BIT(3))))|BIT(4);
    //printk("%s %d. value=0x%08x\n",__func__,__LINE__,value);

#if 0
    rtd_outl(SCPU_A12_DBG_INT_reg,value);
#else
    rtd_outl(SCPU_MEM_TRASH_DBG_INT, BIT(4)|BIT(3));
#endif

    //arm_wrapper_get();

    dump_stacks();
    panic("SCPU has trashed itself ... ");
    return IRQ_HANDLED;
}

void arm_wrapper_intr_ (void)
{
    arm_wrapper_intr(0,NULL);
}

#define IRQ_ARM_WRAPPER IRQ_AUDIO_DMA

#include <mach/rtk_platform.h>

//c0108000 T _text IRQ_DCSYS IRQ_SECURE_SB2
void arm_wrapper_set_kernel_protect (void);
void __init arm_wrapper_intr_setup (void)
{
    unsigned long addr, size;
    
    /* Request IRQ */
    if(request_irq(IRQ_ARM_WRAPPER,
                   arm_wrapper_intr,
                   IRQF_SHARED,
                   "ARM_WRAPPER",
                   arm_wrapper_intr))
    {
        pr_err("%s error. cannot register IRQ %d\n", __func__,IRQ_ARM_WRAPPER);//IRQ_DCSYS
        return ;
    }

    arm_wrapper_set_kernel_protect();

    size = carvedout_buf_query(CARVEDOUT_AV_OS, &addr);
    set_arm_wrapper_arange(addr, addr + size - 1, 3, WRAPPER_WRTIE);//protect av area

#if defined(CONFIG_REALTEK_SECURE)
    //size = carvedout_buf_query(CARVEDOUT_K_OS, &addr);
   //warning: use set3 moniter optee text, don't change set3
    //set_arm_wrapper_arange(addr + 0x4000, addr + size -1, 4, WRAPPER_WRTIE);//protect k area
#endif

    //enable arm wrapper interrupt
    rtd_outl(SCPU_MEM_TRASH_DBG_INT,(BIT(3)|BIT(0)) );
    pr_info("@%s:    enable arm wrapper interrupt [reserved dbus address for SCPU]\n",__func__);
}

// warning: use set3 moniter optee text, don't change set3
void arm_wrapper_clear_kcpu_text(void) 
{
	int i = 3;
	wrapper_start[i]=rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i);
       wrapper_end[i]=rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i);
       wrapper_ctrl[i]=rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i);

       clear_arm_wrapper_arange (i+1);   
}

// warning: use set3 moniter optee text, don't change set3
void arm_wrapper_restore_kcpu_text(void)
{
	int i =3;
	if (wrapper_ctrl[i]&BIT(0))
       {
            rtd_outl(SCPU_MEM_TRASH_DBG_START_0+4*i,wrapper_start[i]);
            rtd_outl(SCPU_MEM_TRASH_DBG_END_0+4*i,wrapper_end[i]);
            rtd_outl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i,wrapper_ctrl[i]|BIT(1)|BIT(0)|BIT(4));
        }
}

volatile int arm_wrapper_flag;
int get_arm_wrapper_flag (void)
{
    return arm_wrapper_flag;
}

void set_arm_wrapper_flag (void)
{
    arm_wrapper_flag=1;
}

void arm_wrapper_suspend (void)
{
    int i;
    for(i=0;i<WRAPPER_NUM;i++)
    {
        wrapper_start[i]=rtd_inl(SCPU_MEM_TRASH_DBG_START_0+4*i);
        wrapper_end[i]=rtd_inl(SCPU_MEM_TRASH_DBG_END_0+4*i);
        wrapper_ctrl[i]=rtd_inl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i);
    }
}

void arm_wrapper_resume (void)
{
    int i;
    for(i=0;i<WRAPPER_NUM;i++)
    {
        if (wrapper_ctrl[i]&BIT(0))
        {
            rtd_outl(SCPU_MEM_TRASH_DBG_START_0+4*i,wrapper_start[i]);
            rtd_outl(SCPU_MEM_TRASH_DBG_END_0+4*i,wrapper_end[i]);
            rtd_outl(SCPU_MEM_TRASH_DBG_CTRL_0+4*i,wrapper_ctrl[i]|BIT(1)|BIT(0)|BIT(4));
        }
    }
    rtd_outl(SCPU_MEM_TRASH_DBG_INT,(BIT(3)|BIT(0)) );
}

void arm_wrapper_save_and_clear (void)
{
    int i=1;
    arm_wrapper_suspend();
    for (;i<=WRAPPER_NUM;i++)
    {
        clear_arm_wrapper_arange(i);
    }
}

extern char __end_rodata[], _text[], _etext[],__end_builtin_fw[];
extern char __v7_setup_stack[];

#if 0
void arm_wrapper_set_kernel_protect (void)
{
    #if 0
    //0x0011fffc--> 0x00116000-->0x0010c000  c0108000

    //c011fffc T __v7_setup_stack c0127780  c0ace000 R __start_rodata
    //protect scpu text section   
    set_arm_wrapper_arange(virt_to_phys(_text),virt_to_phys(((unsigned int)__v7_setup_stack & 0xffffff00)-1),1,WRAPPER_WRTIE);    
    //set_arm_wrapper_arange(virt_to_phys(_text),(0x0010c000-1),1,WRAPPER_WRTIE);//0x0010b680

    set_arm_wrapper_arange(virt_to_phys((void *)(((unsigned int)__v7_setup_stack + 0x100) & 0xffffff00)),0x00800000-1,2,WRAPPER_WRTIE);
    //set_arm_wrapper_arange(virt_to_phys((void *)(((unsigned int)__v7_setup_stack + 0x100) & 0xffffff00)),virt_to_phys(__start_rodata)-1,2,WRAPPER_WRTIE);
    //set_arm_wrapper_arange(0x00140000,virt_to_phys(__start_rodata)-1,2,WRAPPER_WRTIE);//0xc01166c0  0x00128000
    #else
    set_arm_wrapper_arange(virt_to_phys(_text),virt_to_phys(__start_rodata)-1,1,WRAPPER_WRTIE);   
    #endif
}

void arm_wrapper_unset_kernel_protect (void)
{
    clear_arm_wrapper_arange(1);
    //clear_arm_wrapper_arange(2);
}
#else
void arm_wrapper_set_kernel_protect (void) {}
void arm_wrapper_unset_kernel_protect (void) {}
#endif


