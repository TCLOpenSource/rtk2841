#include <linux/slab.h> //kzalloc
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <mach/platform.h>
#include <linux/io.h>
#include <rtk_kdriver/rtk_clock.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <asm/delay.h>
#include <rbus/stb_reg.h>
#include <rtk_kdriver/rtk_otp_util.h>

static LIST_HEAD(clock_list);
static DEFINE_SPINLOCK(clock_lock);
static DEFINE_MUTEX(clock_list_sem);
static int is_bga_package=1;
static unsigned int boot_freq=900000;

#if defined(CONFIG_ARCH_RTK289X)||defined(CONFIG_ARCH_RTK284X) 
#define SYS_PLL_SCPU (0xb8000404)
#define SYS_PLL_DVFS_SCPU (0xb8000440)
#define SYS_DYN_SW_CPU_SCPU_MASK 0xFFFFFFF0
#define SYS_DYN_SW_CPU 0xb8000220
#define SYS_OC_EN_BIT     0
#define SYS_OC_DONE_BIT     20
#define N_CODE_START 8  //integer portion, 8 bits
#define F_CODE_START 16 //float portion, 11 bits
#define N_CODE_MAX   0xFF   //8 bits
#define F_CODE_MAX   0x7FF  // 11 bits
#define FREQ_ADDITION  3
#define FREQ_XTAL_MHZ	27
#else
#error "You must define platform specific PLL register"
#endif
static int dvfs_pin=0;
static int dvfs_gpio_group=0;

typedef struct  rtk_dvfs_freq_reg
{
	unsigned int cpu_freq;
	unsigned int oc_control;
	unsigned int oc_status;
}tRtkDvfs;

tRtkDvfs  rtk_dvfs_reg[2]=
{
	/*sys_pll2_scpu2, sys_scpu2_dvfs*/
	/*{0xB805B024,0xB805B028,0xB805B02C},*/
	/*sys_pll_scpu2, sys_scpu_dvfs*/
	{0xB805B004,0xB805B008,0xB805B00C},
	{0xB805B004,0xB805B008,0xB805B00C}
};


#define FREQ_LEVEL 12
#define FREQ_STEP 100000   //khz
#define FREQ_XTAL 27000    //khz

static struct clk rtk_cpuclk = {
	.name = "cpu_clk",
	.flags = CLK_ALWAYS_ENABLED | CLK_RATE_PROPAGATES,
	.rate = 800000, //kHz
};

struct clk *__rtk_clk_get(struct device *dev, const char *id)
{
	return &rtk_cpuclk;
}
EXPORT_SYMBOL(__rtk_clk_get);

static void __rtk_propagate_rate(struct clk *clk)
{
	struct clk *clkp;

	list_for_each_entry(clkp, &clock_list, node) {
		if (likely(clkp->parent != clk))
			continue;
		if (likely(clkp->ops && clkp->ops->recalc))
			clkp->ops->recalc(clkp);
		if (unlikely(clkp->flags & CLK_RATE_PROPAGATES))
			__rtk_propagate_rate(clkp);
	}
}

unsigned long __rtk_clk_get_rate(struct clk *clk)
{
	//pr_debug("get_rate, %lu\n", (unsigned long)clk->rate);
	return (unsigned long)clk->rate;
}
EXPORT_SYMBOL(__rtk_clk_get_rate);

int __rtk_clk_set_rate(struct clk *clk, unsigned long rate)
{
	return __rtk_clk_set_rate_ex(clk, rate, 0);
}
EXPORT_SYMBOL_GPL(__rtk_clk_set_rate);

#ifdef CONFIG_REALTEK_VOLTAGE_CTRL 
//Adding freq table
enum VOLTAGE_LEVEL
{
	SCPU_H_H,	// 3rd level
#if (defined CONFIG_ARCH_RTK289X)
	SCPU_H_L, // 2nd level
	SCPU_L_H,
#endif
	SCPU_L_L,
};

struct rtk_level_freq
{
	enum VOLTAGE_LEVEL gpio_level;
	unsigned int freq;
};

#ifdef CONFIG_CUSTOMER_TV006
#define FREQ_TABLE_SIZE 4
#else
#define FREQ_TABLE_SIZE 6
#endif
struct rtk_voltage_desc 
{
#if (defined CONFIG_ARCH_RTK289X)
	unsigned char scpu_vid1_level;
#endif
	unsigned char scpu_vid0_level;
        RTK_GPIO_GROUP gpio_group;
	struct rtk_level_freq level[FREQ_TABLE_SIZE];
};

struct rtk_voltage_desc voltage_level=
{
#if (defined CONFIG_ARCH_RTK289X) //K3L
	SCPU_VID1,
#endif
	SCPU_VID0,
	VID_GPIO_GROUP,
#if (defined CONFIG_ARCH_RTK289X) //K3L
	{ {SCPU_L_L,SCPU_FREQ_STEP0},
	  {SCPU_L_H,SCPU_FREQ_STEP1},
	  {SCPU_H_L,SCPU_FREQ_STEP2},
#ifdef CONFIG_CUSTOMER_TV006
	  {SCPU_H_H,SCPU_FREQ_STEP3},
	  {SCPU_H_H,SCPU_FREQ_STEP4}},
#else
	  {SCPU_H_H,SCPU_FREQ_STEP3},
	  {SCPU_H_H,SCPU_FREQ_STEP3}, //reserved 
	  {SCPU_H_H,SCPU_FREQ_STEP3}}, //reserved
#endif

#elif (defined CONFIG_ARCH_RTK284X) //S4 defined SCPU_L_L and SCPU_H_H only
	{ {SCPU_L_L,SCPU_FREQ_STEP0},
          {SCPU_L_L,SCPU_FREQ_STEP1},
          {SCPU_L_L,SCPU_FREQ_STEP2},
#ifdef CONFIG_CUSTOMER_TV006
          {SCPU_H_H,SCPU_FREQ_STEP3},
          {SCPU_H_H,SCPU_FREQ_STEP4}},
#else
          {SCPU_L_L,SCPU_FREQ_STEP3},
          {SCPU_H_H,SCPU_FREQ_STEP4}, //reserved 
          {SCPU_H_H,SCPU_FREQ_STEP4}}, //reserved
#endif

#endif
};

void rtk_set_voltage(int freq)
{
	int i=0,delay_flag=0;
	static int old_freq=0;

	if(!is_bga_package)	//if not bga package, should not control gpio
		return ;
	for(i=0;i<FREQ_TABLE_SIZE;i++)
	{
		if(voltage_level.level[i].freq == freq)
			break;
	}
	delay_flag=0;

	if(freq == -1 || freq == -2)
		delay_flag=1;

		
	if((i<FREQ_TABLE_SIZE) && (freq!=-1 && freq!=-2))
	{
		if(freq > old_freq || old_freq==0)
			delay_flag=1;	
	
		old_freq=freq;
		pr_debug("level:%d %d %d\n",i,voltage_level.level[i].gpio_level,freq);
		switch(voltage_level.level[i].gpio_level)
		{
			case SCPU_L_L:
#if (defined CONFIG_ARCH_RTK289X)		
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1); 
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 0);
#endif
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 0);
				pr_debug("set vid0 low\n");
				break;
#if (defined CONFIG_ARCH_RTK289X)		
			case SCPU_L_H:
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1); 
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 0);
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
				break;
			case SCPU_H_L:
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1); 
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1);
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 0);
				break;
#endif
			case SCPU_H_H:
#if (defined CONFIG_ARCH_RTK289X)		
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1); 
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1);
#endif
				rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
				rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
				pr_debug("set vid0 high\n");
				break;
		}
	}
	else if(freq==-1)//set to max
	{
#if (defined CONFIG_ARCH_RTK289X)		
		rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 0); 
		//rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1);
#endif
		rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 0);
		pr_debug("set vid0 high\n");
		//rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
		//printk("set pin status as input \n");
	}
	else if(freq==-2)//set to max
	{
#if (defined CONFIG_ARCH_RTK289X)		
		rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1);
#endif
		rtk_gpio_output(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);	
#if (defined CONFIG_ARCH_RTK289X)		
		rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level), 1); 
#endif
		rtk_gpio_set_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level), 1);
		pr_debug("set vid0 high\n");
		//printk("set pin status as output \n");
	}
	if(delay_flag)
		udelay(15);

#if 0
	printk("clamp %d %d %d %d/%d %d/%d\n",freq,i,FREQ_TABLE_SIZE,
	       rtk_gpio_get_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level),0), rtk_gpio_output_get(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid1_level)),
	       rtk_gpio_get_dir(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level),0), rtk_gpio_output_get(rtk_gpio_id(voltage_level.gpio_group, voltage_level.scpu_vid0_level)));
#endif
	
}
#endif

typedef struct scpu_freq_map
{
	unsigned int reg_value;
	unsigned int freq_kHz;
}tscpu_freq_map;

tscpu_freq_map rtk_scpu_freq_map[]= {
	{ 0x07B43B00, 1700000 },//1.7
	{ 0x02123800, 1600000 }, //1.6
	{ 0x04713400, 1500000 }, //1.5
	{ 0x06D13000, 1400000 }, //1.4
	{ 0x012F2D00, 1300000 }, //1.3
	{ 0x038E2900, 1200000 }, //1.2
	{ 0x05ED2500, 1100000 }, //1.1
	{ 0x004C2200, 1000000 }, //1.0
	{ 0x02AB1E00, 900000 }, //900
	{ 0x05091A00, 800000 }, //800
	{ 0x07681600, 700000 }, //700
};

unsigned int rtk_get_boot_freq(void)
{
	static int get_boot_freq=0;
	int i;
	if(get_boot_freq==0) {
		for(i=0;i<(sizeof(rtk_scpu_freq_map)/sizeof(tscpu_freq_map));i++)
		{
			if((rtd_inl(0xB805B004) & 0xFFFFFFF0)==rtk_scpu_freq_map[i].reg_value)
			{
				boot_freq=rtk_scpu_freq_map[i].freq_kHz;
				break;
			}
		}
		printk("boot_freq:%d %x i=%d\n",boot_freq,(rtd_inl(0xB805B004) & 0xFFFFFFF0),i);
		get_boot_freq=1;
	}
	return boot_freq;
}


int __rtk_clk_set_rate_ex(struct clk *clk, unsigned long rate, int algo_id)
{
	static int old_rate=0;
	int ret = 0;
	unsigned int  n_code, f_code, cpu_freq_reg_val;
        	register unsigned int dvfs_reg_val;
	unsigned long flags;
	int real_rate;
//	int digital_adjust_freq=0;
	int cluster_id=0; //make default to zero

	real_rate=rate;
#ifdef CONFIG_FIXED_CLOCK_TEST
	//fixed the rate into 150MHz for test dhrystone time to know clock actually change or not
	real_rate=150000;
	rate=300000;
//	real_rate=900000;
#else
//	if(real_rate<300000)
//	        rate=300000;
#endif
	

	if (likely(clk->ops && clk->ops->set_rate))
	{
		spin_lock_irqsave(&clock_lock, flags);
		ret = clk->ops->set_rate(clk, rate, algo_id);
		spin_unlock_irqrestore(&clock_lock, flags);
	}

	if (unlikely(clk->flags & CLK_RATE_PROPAGATES))
		__rtk_propagate_rate(clk);

	clk->rate = rate;

	spin_lock_irqsave(&clock_lock, flags);

#if defined(CONFIG_ARCH_RTK289X)||defined(CONFIG_ARCH_RTK284X) 
#ifdef CONFIG_REALTEK_VOLTAGE_CTRL
	if(old_rate < rate)	//frequency up
	{
		rtk_set_voltage(rate);
	}
#endif
	dvfs_reg_val = rtd_inl(rtk_dvfs_reg[cluster_id].oc_control);
	cpu_freq_reg_val = rtd_inl(rtk_dvfs_reg[cluster_id].cpu_freq);
	n_code = (cpu_freq_reg_val >> N_CODE_START) & N_CODE_MAX;  //8 bits
	f_code = (cpu_freq_reg_val >> F_CODE_START) & F_CODE_MAX; //11 bits
	pr_debug("*********** original freq=%d MHz\n", ( FREQ_XTAL_MHZ * ((n_code+FREQ_ADDITION)*1000+f_code*1000/2048))/1000);

	//mask off scpu freq bits
	cpu_freq_reg_val &=(~(N_CODE_MAX<<N_CODE_START | F_CODE_MAX << F_CODE_START));
	//recalculate n/f code , rate,FREQ_XTAL is kHz
	n_code= (rate/FREQ_XTAL) - FREQ_ADDITION;
	f_code= (unsigned int )((rate - (n_code+3)*FREQ_XTAL)*2048/FREQ_XTAL)+1;

	//write scpu relate bits
	cpu_freq_reg_val|=(((n_code<<N_CODE_START)|f_code <<F_CODE_START)& (N_CODE_MAX<<N_CODE_START | F_CODE_MAX << F_CODE_START));
	rtd_outl(rtk_dvfs_reg[cluster_id].oc_control, dvfs_reg_val&(~(1<<SYS_OC_EN_BIT)));
	dvfs_reg_val=rtd_inl(rtk_dvfs_reg[cluster_id].oc_control);
	rtd_outl(rtk_dvfs_reg[cluster_id].cpu_freq, cpu_freq_reg_val);
	//adjust digital freq


	rtd_outl(rtk_dvfs_reg[cluster_id].oc_control, dvfs_reg_val|(1<<SYS_OC_EN_BIT));
	//firing oc action
	//	rtd_outl(SYS_PLL_DVFS_SCPU, dvfs_reg_val|(1<<SYS_OC_EN_BIT));
	//Waiting
	dvfs_reg_val=rtd_inl(rtk_dvfs_reg[cluster_id].oc_status);
	while((dvfs_reg_val & (1<<SYS_OC_DONE_BIT))==0)
	dvfs_reg_val=rtd_inl(rtk_dvfs_reg[cluster_id].oc_status);
	//dump result
	cpu_freq_reg_val = rtd_inl(rtk_dvfs_reg[cluster_id].cpu_freq);
	n_code = (cpu_freq_reg_val >> N_CODE_START) &0xFF;  //8 bits
	f_code = (cpu_freq_reg_val >> F_CODE_START) &0x7FF; //11 bits
	//pr_debug("*********** original freq=%d MHz\n", ( FREQ_XTAL_MHZ * ((n_code+FREQ_ADDITION)*1000+f_code*1000/2048))/1000);
	//pr_debug("**********rate:%lx set freq=%lu MHz\n",rate, ( FREQ_XTAL_MHZ * ((n_code+FREQ_ADDITION)*1000+f_code*1000/2048))/1000);
#ifdef CONFIG_REALTEK_VOLTAGE_CTRL
	if(old_rate > rate)	//frequency down
	{
		rtk_set_voltage(rate);
	}
	old_rate=rate;
#endif
#else
	#error "You must write platform specific code for set CPU clock"
#endif

	spin_unlock_irqrestore(&clock_lock, flags);

	return ret;
}
EXPORT_SYMBOL_GPL(__rtk_clk_set_rate_ex);

long __rtk_clk_round_rate(struct clk *clk, unsigned long rate)
{
	if (likely(clk->ops && clk->ops->round_rate))
	{
		unsigned long flags, rounded;

		spin_lock_irqsave(&clock_lock, flags);
		rounded = clk->ops->round_rate(clk, rate);
		spin_unlock_irqrestore(&clock_lock, flags);

		return rounded;
	}

	return rate;
}
EXPORT_SYMBOL_GPL(__rtk_clk_round_rate);

static int freqTbl4[]={
	SCPU_FREQ_STEP0,	
	SCPU_FREQ_STEP1,	
	SCPU_FREQ_STEP2,	
	SCPU_FREQ_STEP3,
	SCPU_FREQ_STEP4,
};

static int freqTbl2[]={
	SCPU_FREQ_STEP0,	
	SCPU_FREQ_STEP3,
	SCPU_FREQ_STEP4,
};

int __rtk_init_cpufreq_table(struct cpufreq_frequency_table **table)
{
#if defined(CONFIG_ARCH_RTK289X)||defined(CONFIG_ARCH_RTK284X) 
	//[21:20]=N, [19:12]=M, [8:7]=O
	int boot_freqnum=platform_get_dvfs();
	unsigned int max_freq, next_freq, step_freq;
	unsigned int i,  over_shoot=0;
	unsigned int num_freq;

	struct cpufreq_frequency_table *freq_table;
	
	rtk_get_boot_freq();
#ifdef CONFIG_REALTEK_VOLTAGE_CTRL
	int qfp_otp=1; //default set to qfp to prevent issues
//	otp_read_bits(0x078,4,3,qfp_otp);
	qfp_otp=(rtd_inl(0xb8038078)>>3)&0x03;
	if(dvfs_pin==0 && qfp_otp) //pin and qfp's otp
	{
		pr_err("this is qfp ic\n");
		is_bga_package=0;
		freqTbl4[4]=SCPU_FREQ_STEP3;
		freqTbl2[2]=SCPU_FREQ_STEP3;
	}
	if(dvfs_pin!=0) //hack pin
	{
		if(dvfs_gpio_group==1)
			voltage_level.gpio_group=ISO_GPIO;
		else
			voltage_level.gpio_group=MIS_GPIO;
			
		voltage_level.scpu_vid0_level=dvfs_pin;
		pr_err("set the group:%d pin:%d %d\n",voltage_level.gpio_group,voltage_level.scpu_vid0_level,dvfs_pin);
	}
#endif
	if(boot_freqnum==2){
		freq_table = kzalloc(sizeof(struct cpufreq_frequency_table) * (sizeof(freqTbl2)/4+1), GFP_KERNEL);
#ifdef  CONFIG_ARCH_RTK284X
		if(rtd_inl(STB_SC_VerID_reg) == 0x64760000)
		{
			freqTbl2[1]=freqTbl2[0];
			freqTbl2[2]=freqTbl2[0];
		}
#endif
		max_freq = freqTbl2[sizeof(freqTbl2)/4 -1 ];
		num_freq=sizeof(freqTbl2)/4;
	}
	else{
		freq_table = kzalloc(sizeof(struct cpufreq_frequency_table) * (sizeof(freqTbl4)/4+1), GFP_KERNEL);
#ifdef  CONFIG_ARCH_RTK284X
		if(rtd_inl(STB_SC_VerID_reg) == 0x64760000)
		{
			freqTbl4[1]=freqTbl4[0];
			freqTbl4[2]=freqTbl4[0];
			freqTbl4[3]=freqTbl4[0];
			freqTbl4[4]=freqTbl4[0];
		}
#endif
		max_freq = freqTbl4[sizeof(freqTbl4)/4 -1 ];
		num_freq=sizeof(freqTbl4)/4;
	}
	if (!freq_table) {
		pr_err("fail to alloc freq table\n");
		return -ENOMEM;
	}

	next_freq = max_freq;
	for (i = num_freq ; i > 0; i--)
	{
		//freq_table[i-1].index = i;
		freq_table[i-1].frequency = next_freq;
		//pr_debug("table[%d].index=%d, table[%d].freq=%dkHz\n", i-1, freq_table[i-1].index, i-1, freq_table[i-1].frequency);
		pr_debug("table[%d].freq=%dkHz\n", i-1, freq_table[i-1].frequency);

		if (over_shoot == 1)
			next_freq -= step_freq;
		else {
			if(i>=2)
				if(boot_freqnum==2)
					next_freq = freqTbl2[i - 2];
				else
					next_freq = freqTbl4[i - 2];
		}
	}

	freq_table[num_freq].frequency = CPUFREQ_TABLE_END;

	*table = &freq_table[0];

	return 0;
#else
	#error "You must write platform specific code for init freq table"
#endif
}
//EXPORT_SYMBOL_GPL(__rtk_init_cpufreq_table);

void __rtk_free_cpufreq_table(struct cpufreq_frequency_table **table)
{
	if (!table)
		return;

	kfree(*table);
	*table = NULL;
}

void __rtk_freqtable_switch(struct cpufreq_frequency_table **table)
{
	__rtk_free_cpufreq_table(table);

}

static int __init early_parse_dvfs_pin (char *str)
{
    if(str) {
        dvfs_pin= simple_strtoull(str, NULL, 16);
    }
    pr_err("dvfs_pin:%d\n",dvfs_pin);

    return 0 ;
}

static int __init early_parse_gpio_group (char *str)
{
    if(str)
        dvfs_gpio_group= simple_strtoull(str, NULL, 16);
    pr_err("dvfs_gpio_group:%d\n",dvfs_gpio_group);

    return 0 ;
}
early_param("dvs_pin", early_parse_dvfs_pin);
early_param("dvs_gpio_group", early_parse_gpio_group);
//EXPORT_SYMBOL_GPL(__rtk_free_cpufreq_table);
