#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <asm/page.h>
#include <asm/io.h>
#include "rtk_ice-bw.h"
#include "../core/rtk_ice-aux.h"
#include "../core/rtk_ice-debug.h"
#include <rbus/sys_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include "rbus/scpu_core_reg.h"
#include <rbus/pll27x_reg_reg.h>
#include <rbus/dc_phy_reg.h>
#include <rbus/dc_sys_reg.h>
#include <linux/timer.h>
#include <linux/string.h>
#include <asm-generic/bug.h>

//#define SUPPORT_DCU2
#define SKIP_FOREFRONT_CNT 1 /*< Throw result on the forefront checking time.*/
#define TRIPLET_IP(x) ((x) && (x)->p_next && (x)->p_next->p_next)

#define NA_VALUE 0xFFFFFFFF
#define LAT_NA_VALUE 0xFFFF

#define BW_DATA_CLR(x) {\
	if((x) != NULL){\
		(x)->m_curBw = NA_VALUE;\
		(x)->m_maxBw = NA_VALUE;\
		(x)->m_minBw = NA_VALUE;\
		(x)->m_sumBw = 0;\
		(x)->m_hisLen = 0;\
		(x)->m_curLat = LAT_NA_VALUE;\
		(x)->m_maxLat = LAT_NA_VALUE;\
		(x)->m_minLat = LAT_NA_VALUE;\
		(x)->m_sumLat = 0;\
		(x)->m_hisLenLat = 0;\
	}\
}

#define BW_DATA_W(x,y) {\
	if(x != NULL){\
		(x)->m_curBw = (y);\
		if((x)->m_minBw == NA_VALUE || (x)->m_curBw < (x)->m_minBw){\
			(x)->m_minBw = (x)->m_curBw;\
		}\
		if((x)->m_maxBw == NA_VALUE || (x)->m_curBw > (x)->m_maxBw){\
			(x)->m_maxBw = (x)->m_curBw;\
		}\
		{\
			u64 BW_DATA_u64 = (x)->m_sumBw + (x)->m_curBw;\
			if(BW_DATA_u64 < (x)->m_sumBw){\
				(x)->m_sumBw = (x)->m_curBw;\
				(x)->m_hisLen = 0;\
			}else{\
				(x)->m_hisLen = (x)->m_hisLen + 1;\
				(x)->m_sumBw = BW_DATA_u64;\
			}\
		}\
	}\
}


#define BW_LAT_DATA_W(x,y,z) {\
	if(x != NULL){\
		(x)->m_curBw = (y);\
		if((x)->m_minBw == NA_VALUE || (x)->m_curBw < (x)->m_minBw){\
			(x)->m_minBw = (x)->m_curBw;\
		}\
		if((x)->m_maxBw == NA_VALUE || (x)->m_curBw > (x)->m_maxBw){\
			(x)->m_maxBw = (x)->m_curBw;\
		}\
		{\
			u64 BW_DATA_u64 = (x)->m_sumBw + (x)->m_curBw;\
			if(BW_DATA_u64 < (x)->m_sumBw){\
				(x)->m_sumBw = (x)->m_curBw;\
				(x)->m_hisLen = 0;\
			}else{\
				(x)->m_hisLen = (x)->m_hisLen + 1;\
				(x)->m_sumBw = BW_DATA_u64;\
			}\
		}\
		(x)->m_curLat = (z);\
		if((x)->m_minLat == LAT_NA_VALUE || (x)->m_curLat < (x)->m_minLat){\
			(x)->m_minLat = (x)->m_curLat;\
		}\
		if((x)->m_maxLat == LAT_NA_VALUE || (x)->m_curLat > (x)->m_maxLat){\
			(x)->m_maxLat = (x)->m_curLat;\
		}\
		{\
			u64 Lat_DATA_u64 = (x)->m_sumLat + (x)->m_curLat;\
			if(Lat_DATA_u64 < (x)->m_sumLat){\
				(x)->m_sumLat = (x)->m_curLat;\
				(x)->m_hisLenLat = 0;\
			}else{\
				(x)->m_hisLenLat = (x)->m_hisLenLat + 1;\
				(x)->m_sumLat = Lat_DATA_u64;\
			}\
		}\
	}\
}

#define BW_DATA_R(x,y) ((y) == BW_IP_QUERY_CURRENT ? (x)->m_curBw : \
	((y) == BW_IP_QUERY_MIN ? (x)->m_minBw : \
	((y) == BW_IP_QUERY_MAX ? (x)->m_maxBw : \
	((y) == BW_IP_QUERY_MEAN ? ((x)->m_hisLen == 0 ? \
	(x)->m_curBw : (UINT32)div64_u64((x)->m_sumBw,(x)->m_hisLen)) : 0))))

#define LAT_DATA_R(x,y) ((y) == BW_IP_QUERY_CURRENT ? (x)->m_curLat : \
	((y) == BW_IP_QUERY_MIN ? (x)->m_minLat : \
	((y) == BW_IP_QUERY_MAX ? (x)->m_maxLat : \
	((y) == BW_IP_QUERY_MEAN ? ((x)->m_hisLenLat == 0 ? \
	(x)->m_curLat : (UINT32)div64_u64((x)->m_sumLat,(x)->m_hisLenLat)) : 0))))


/*#define SUPPORT_SB_BW_CHECK*/
#define MAX_BW_CHECK_IP 300
#define BW_SCALEUP 100
/*event*/
static DECLARE_WAIT_QUEUE_HEAD (rtice_bw_wait_thread);
static DECLARE_WAIT_QUEUE_HEAD (rtice_bw_wait_main);
/*param and info struct for bw checking*/
static CBwCheck g_bwCheck = {
#ifdef RTICE_BW_TIMER
	NULL		/*checking timer*/,\
	0		/*Current check count*/,\
	NULL		/*Next checked ip*/,
#else
	NULL		/*checking thread handler*/,
#endif
	FALSE		/*Run flag of thread*/,\
	FALSE		/*Do not send stop signal to checking thread.*/,\
	FALSE		/*Current checking thread is stopped.*/,\
	BW_CHECK_MODE_SIZE      /*Invalid check mode*/,\
	256		/*256ms check period*/,\
	256		/*256ms measure period*/,\
	0		/*group number*/,
	0		/*ip info list is empty*/,\
	NULL		/*ip list header point to null*/,\
	NULL		/*ip list tail point to null*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*pc total*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*pc ack*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*pc idle*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*scpu*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*effi total*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*effi rd*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*effi wr*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*bank conflict*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*w2r count*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*r2w count*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*dcu2 pc total*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*dcu2 pc ack*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*dcu2 pc idle*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*dcu2 scpu*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*effi total2*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*effi rd2*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*effi wr2*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*bank2 conflict*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*w2r2 count*/,\
	{0,0,0xFFFFffff,0,0,0,NULL,NULL}  /*r2w2 count*/\
};

/**
 * \brief Realocate address of dcu accroding to dcu type.
 * \param a Source addr.
 * \param fdcu2 Wheather query address about dcu2.
 * \return Returns stand.
**/
static unsigned int dcu_addr(unsigned int a,int fdcu2)
{
	unsigned int naddr = a;
#ifdef SUPPORT_DCU2
    RTICE_DEBUG("[%s:%d]support dcu2\r\n", __func__,__LINE__);
	if(fdcu2){
		if(naddr >= 0xb8007000 && naddr <= 0xb8007500)
			naddr = (naddr & 0xffff0fff) | 0x00003000;
		else if(naddr >= 0xb8008800 && naddr <= 0xb8008fff)
			naddr = (naddr & 0xffff0fff) | 0x00004000;
	}
#endif
	return naddr;
}
/**
 * \brief  Get or find ip info by id.
 * \param id : Id of the ip.
 * \return : Returns founded ip info pointer.
**/
static CBwIp* get_bw_ip(unsigned char id)
{
	CBwIp* pIp = g_bwCheck.p_ipHeader;
	while(pIp){
		if(pIp->id == id)
			return pIp;
		pIp = pIp->p_next;
	}
	return pIp;
}
/**
 * \brief  Insert an ip info into global ip info list.
 * \param pIp : Pointer of inserted ip info.
 * \param index : Order index for inserting.
 * \return : Returns order index of the operation while successed insert,
 * otherwise returns -1 .
**/
static int bw_ip_list_insert(CBwIp*pIp,unsigned int index)
{
	if(!pIp)
		return -1;
	if(index == 0){/*< insert into header*/
		if(g_bwCheck.p_ipHeader)
			g_bwCheck.p_ipHeader->p_prev = pIp;
		pIp->p_next = g_bwCheck.p_ipHeader;
		pIp->p_prev = NULL;
		g_bwCheck.p_ipHeader = pIp;
		if(index == g_bwCheck.m_ipListCnt)
			g_bwCheck.p_ipTail = pIp;
	}else if(index == g_bwCheck.m_ipListCnt){
		if(g_bwCheck.p_ipTail)
			g_bwCheck.p_ipTail->p_next = pIp;
		pIp->p_next = NULL;
		pIp->p_prev = g_bwCheck.p_ipTail;
		g_bwCheck.p_ipTail = pIp;
	}else if(index < g_bwCheck.m_ipListCnt){
		unsigned int i = index;
		CBwIp *pNext = g_bwCheck.p_ipHeader;
		if(index < g_bwCheck.m_ipListCnt - index){
			while(i-- && pNext){
				pNext = pNext->p_next;
			}
		}else{
			unsigned int i = g_bwCheck.m_ipListCnt - index;
			pNext = g_bwCheck.p_ipTail;
			while(i-- && pNext){
				pNext = pNext->p_prev;
			}
		}
		if(pNext && pNext->p_prev && pNext->p_next){
			pIp->p_next = pNext;
			pIp->p_prev = pNext->p_prev;
			pNext->p_prev = pIp;
			pNext->p_prev->p_next = pIp;
		}else{
			return -1;
		}

	}
	else
		return -1;
	g_bwCheck.m_ipListCnt++;
	return index;
}

static void bw_ip_list_clear(void)
{
	CBwIp* pIp = g_bwCheck.p_ipHeader;
	g_bwCheck.m_ipListCnt = 0;
	g_bwCheck.p_ipHeader = NULL;
	g_bwCheck.p_ipTail = NULL;
	while(pIp){
		CBwIp* pNext = pIp->p_next;
		kfree(pIp);
		pIp = pNext;
	}
}
/**
 * \brief  Init or Reorder bw check ip list..
 * \param ipCnt : Count of ips needed checking.
 * \param ips : Reorder ip checking list according to the id of ip specified by
 * 'ips'.No work while ips is null.
 * \return : Returns count of current checking ips in bw checking list.
**/
static int bw_ip_list_init(unsigned int ipCnt,unsigned char*ips)
{
	unsigned int i = 0;
	unsigned cnt = 0;
	for(i = 0;i < ipCnt;i++){
		CBwIp *pIp = NULL;
		unsigned char id = *ips++;
		/*pIp = get_bw_ip(id);*/
		if(pIp){/*<remove founded ip from global list first.*/
			if(!pIp->p_prev){
				g_bwCheck.p_ipHeader = pIp->p_next;
				if(pIp->p_next)
					pIp->p_next->p_prev = NULL;
			}else if(!pIp->p_next){
				g_bwCheck.p_ipTail = pIp->p_prev;
				if(pIp->p_prev)
					pIp->p_prev->p_next = NULL;
			}else{
				pIp->p_prev->p_next = pIp->p_next;
				pIp->p_next->p_prev = pIp->p_prev;
			}
			pIp->p_prev = NULL;
			pIp->p_next = NULL;
			g_bwCheck.m_ipListCnt--;
		}else{
			pIp = (CBwIp*)kmalloc(sizeof(CBwIp),GFP_ATOMIC);
			BUG_ON(!pIp);
			pIp->id = id;
			pIp->p_next = NULL;
			pIp->p_prev = NULL;
		}
		/*clear data of ip bw result*/
		if(pIp)
			BW_DATA_CLR(pIp);
		/*insert ip info to global list.*/
		if(bw_ip_list_insert(pIp,i) == i){
			/*RTICE_DEBUG("[%s:%d]i=%d;pIp=%x\r\n", \
			 * __func__,__LINE__,i,pIp);*/
			cnt++;
		}
	}
	return cnt;
}

static int bw_select_ip(UINT8 ip0,UINT8 ip1,UINT8 ip2)
{
    unsigned int value = 0;
    value |= DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_1(1);
    value |= DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog0_sel(ip0);
    value |= DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_2(1);
    value |= DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog1_sel(ip1);
    value |= DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_3(1);
    value |= DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog2_sel(ip2);
#ifdef SUPPORT_DCU2
    rtd_outl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_ctrl_reg,ip0 & 0x80),\
					value);
#else
    rtd_outl(DC_SYS_DC_PC_SYSH_prog_ctrl_reg,value);
#endif
	/*dc_pc_sysh_prog_ctrl_RBUS     reg_dc_pc_sysh_prog_ctrl;
	reg_dc_pc_sysh_prog_ctrl.regValue = 0;
	/*reg_dc_pc_sysh_prog_ctrl.regValue =  \
	 * rtd_inl(DC_PC_SYSH_PROG_CTRL_VADDR);*/

	/*reg_dc_pc_sysh_prog_ctrl.write_en_1 = 1;
	reg_dc_pc_sysh_prog_ctrl.pc_sysh_prog0_sel = ip0 & 0x7f;
	reg_dc_pc_sysh_prog_ctrl.write_en_2 = 1;
	reg_dc_pc_sysh_prog_ctrl.pc_sysh_prog1_sel = ip1 & 0x7f;
	reg_dc_pc_sysh_prog_ctrl.write_en_3 = 1;
	reg_dc_pc_sysh_prog_ctrl.pc_sysh_prog2_sel = ip2 & 0x7f;

	rtd_outl(dcu_addr(DC_PC_SYSH_PROG_CTRL_VADDR,ip0 & 0x80),\
					reg_dc_pc_sysh_prog_ctrl.regValue);*/
	/*RTICE_DEBUG("[%s:%d]ip0=%d,ip1=%d,ip2=%d\r\n", \
	 * __func__,__LINE__,ip0,ip1,ip2);*/
	return 0;
}

/**
  * \brief Enable_PC_go Set pc_go bit to start counting.
  * Reset this to stop counting
  * \param pc_go Counter start counting or not
  * \param fdcu2 Whether checking ips belongs to DCU2.
  * \return : 0 - success, others fail
**/
static int set_pc_go_status(char pc_go,int fdcu2)
{
#ifndef SUPPORT_DCU2
    if(fdcu2)
        return 0;
#endif
	dc_sys_dc_pc_ctrl_RBUS         reg_dc_pc_ctrl;
	dc_phy_scpu_pc_ctrl_RBUS      reg_scpu_pc_ctrl;

	/*dcu*/
	reg_dc_pc_ctrl.regValue = rtd_inl(dcu_addr(DC_SYS_DC_PC_CTRL_reg,fdcu2));
	reg_dc_pc_ctrl.pc_go = pc_go ? 1 : 0;
	rtd_outl(dcu_addr(DC_SYS_DC_PC_CTRL_reg,fdcu2), reg_dc_pc_ctrl.regValue);
#ifdef SUPPORT_DCU2
	if(pc_go == 0){
		reg_dc_pc_ctrl.regValue = rtd_inl(dcu_addr(DC_SYS_DC_PC_CTRL_reg,TRUE));
		reg_dc_pc_ctrl.pc_go = pc_go;
		rtd_outl(dcu_addr(DC_SYS_DC_PC_CTRL_reg,TRUE), reg_dc_pc_ctrl.regValue);
	}
#endif
	/*scpu on DCU1*/
	reg_scpu_pc_ctrl.regValue = rtd_inl(dcu_addr(DC_PHY_SCPU_PC_CTRL_reg,FALSE));
	reg_scpu_pc_ctrl.pc_go = pc_go ? 1 : 0;
	rtd_outl(dcu_addr(DC_PHY_SCPU_PC_CTRL_reg,FALSE), reg_scpu_pc_ctrl.regValue);
#ifdef SUPPORT_DCU2
	/*scpu on DCU2*/
	reg_scpu_pc_ctrl.regValue = rtd_inl(dcu_addr(DC_PHY_SCPU_PC_CTRL_reg,TRUE));
	reg_scpu_pc_ctrl.pc_go = pc_go ? 1 : 0;
	rtd_outl(dcu_addr(DC_PHY_SCPU_PC_CTRL_reg,TRUE), reg_scpu_pc_ctrl.regValue);
#endif
	return 0;
}

static int effi_measure_en(char fen,int fdcu2)
{
#ifndef SUPPORT_DCU2
    if(fdcu2)
        return 0;
#endif
	dc_phy_eff_meas_ctrl_RBUS  reg_eff_meas_ctrl;
	static unsigned int refresh_org_1 = 0,refresh_org_2 = 0;
	/*efficiency*/
	reg_eff_meas_ctrl.regValue = rtd_inl(dcu_addr(DC_PHY_EFF_MEAS_CTRL_reg,fdcu2));
	if(reg_eff_meas_ctrl.eff_meas_en != fen ||
		      reg_eff_meas_ctrl.meas_period != g_bwCheck.m_measPeriod){
		reg_eff_meas_ctrl.eff_meas_en = fen;
		if(g_bwCheck.m_measPeriod)
			reg_eff_meas_ctrl.meas_period = g_bwCheck.m_measPeriod;
		rtd_outl(dcu_addr(DC_PHY_EFF_MEAS_CTRL_reg,fdcu2),\
						reg_eff_meas_ctrl.regValue);
		//reg_eff_meas_ctrl.regValue = rtd_inl(EFF_MEAS_CTRL_VADDR);
		RTICE_DEBUG("[%s:%d]en=%d,period=%d\r\n",__func__,__LINE__, \
			reg_eff_meas_ctrl.eff_meas_en, \
			reg_eff_meas_ctrl.meas_period);
	}
	return 0;
}

static int is_effi_finish(int fdcu2)
{
#ifndef SUPPORT_DCU2
    if(fdcu2)
        return 0;
#endif
	dc_phy_eff_meas_ctrl_RBUS reg_eff_meas_ctrl;
	reg_eff_meas_ctrl.regValue = rtd_inl(dcu_addr(DC_PHY_EFF_MEAS_CTRL_reg,fdcu2));
	return reg_eff_meas_ctrl.eff_meas_en == 0 ? TRUE : FALSE;
}

/*------------------------------------------------------------------
 * Func : check_result
 *
 * Desc : Caculate and Save the BW value in buffer by mode
 *
 * Parm : ipGroup,group index,it decides what ips' BW value is saved
 * (pc total para& scpu bw is updated every time)
 *
 * Retn : 0 - success, others fail
 *------------------------------------------------------------------*/
static int check_result(UINT32*pRet,unsigned int len,int fdcu2)
{
	/*UINT32 M , N , O , F;*/
	UINT32 M =0, N = 0,  F = 0,PDIV = 0;
    	int i=0;
    
	UINT32 ipbw[3];
	UINT32 FreqH,tmp;
	u64 dividend,divisor;
	UINT32 *ptotal_num = &pRet[0],*ptotal_ack = &pRet[1],*ptotal_idle = &pRet[2];
	UINT32 *pscup_bw = &pRet[3];
	UINT32 *eff = &pRet[4];
	UINT32 *ptotal_num2 = &pRet[10],*ptotal_ack2 = &pRet[11];
	UINT32 *ptotal_idle2 = &pRet[12],*pscpu_bw2 = &pRet[13];
	UINT32 *eff2 = &pRet[14];
	UINT32 *ip = &pRet[20];
	/*for scpu para caculate*/
	dc_phy_scpu_pc_tota_mon_num_RBUS       reg_scpu_pc_tota_mon_num;
	dc_phy_scpu_pc_ack_num_RBUS            reg_scpu_pc_ack_num;
	pll_reg_sys_pll_bush1_RBUS      reg_sys_pll_bush1;
	pll_reg_sys_pll_bush2_RBUS      reg_sys_pll_bush2;
	scpu_core_sys_pll_scpu1_RBUS reg_sys_pll_scpu1;
	scpu_core_sys_pll_scpu2_RBUS reg_sys_pll_scpu2;
	
	dc_phy_read_cmd_RBUS  reg_read_cmd;
	dc_phy_write_cmd_RBUS reg_write_cmd;
	dc_phy_tmctrl3_RBUS    reg_tmctrl3;
	dc_phy_eff_meas_ctrl_RBUS    reg_eff_meas_ctrl;
	dc_phy_read_chop_cmd_RBUS reg_read_chop_cmd;
	dc_phy_write_chop_cmd_RBUS reg_write_chop_cmd;
	

	/*total cycle,ack,idle number of dcu1~2*/
	*ptotal_num = rtd_inl(DC_SYS_DC_PC_TOTA_MON_NUM_reg);
	*ptotal_ack = rtd_inl(DC_SYS_DC_PC_TOTA_ACK_NUM_reg);
	*ptotal_idle = rtd_inl(DC_SYS_DC_PC_TOTA_IDL_NUM_reg);
#ifdef SUPPORT_DCU2
	*ptotal_num2 = rtd_inl(dcu_addr(DC_SYS_DC_PC_TOTA_MON_NUM_reg,TRUE));
	*ptotal_ack2 = rtd_inl(dcu_addr(DC_SYS_DC_PC_TOTA_ACK_NUM_reg,TRUE));
	*ptotal_idle2 = rtd_inl(dcu_addr(DC_SYS_DC_PC_TOTA_IDL_NUM_reg,TRUE));
#else
    	*ptotal_num2 = 0;
	*ptotal_ack2 = 0;
	*ptotal_idle2 = 0;
#endif
	/*RTICE_DEBUG("dcu1:total=%u;ack=%u;idle=%u\r\n",*ptotal_num, \
	*				*ptotal_ack,*ptotal_idle);*/
	/*RTICE_DEBUG("dcu2:total=%u;ack=%u;idle=%u\r\n",*ptotal_num2, \
	*				*ptotal_ack2,*ptotal_idle2);*/
	/*efficiency measure*/
	reg_eff_meas_ctrl.regValue = rtd_inl(DC_PHY_EFF_MEAS_CTRL_reg);
	reg_tmctrl3.regValue = rtd_inl(DC_PHY_TMCTRL3_reg);
	reg_read_cmd.regValue = rtd_inl(DC_PHY_READ_CMD_reg);
	reg_write_cmd.regValue = rtd_inl(DC_PHY_WRITE_CMD_reg);
	reg_read_chop_cmd.regValue = rtd_inl(DC_PHY_READ_CHOP_CMD_reg);
	reg_write_chop_cmd.regValue = rtd_inl(DC_PHY_WRITE_CHOP_CMD_reg);
	/*RTICE_DEBUG("total:refcycle=%u;period=%u;rd_cnt=%u;wr_cnt=%u;\r\n", \
	 * reg_tmctrl3.refcycle,reg_eff_meas_ctrl.meas_period, \
	 * reg_read_cmd.rd_cnt,reg_write_cmd.wr_cnt);*/
	dividend = (u64)40000 * reg_read_cmd.rd_cnt - (u64)20000 * reg_read_chop_cmd.rd_chop_cnt;
	divisor = (u64)16 * (reg_tmctrl3.refcycle + 1) * \
		  reg_eff_meas_ctrl.meas_period * 4;
	eff[1] = reg_eff_meas_ctrl.meas_period == 0 ? \
		 (u64)0 : div64_u64(dividend,divisor);
	dividend = (u64)40000 * reg_write_cmd.wr_cnt - (u64)20000 * reg_write_chop_cmd.wr_chop_cnt;
	eff[2] = reg_eff_meas_ctrl.meas_period == 0 ? \
		 (u64)0 : div64_u64(dividend,divisor);
	eff[0] = eff[1] + eff[2];
	/*efficient extension info(conflict ,w2r,r2w count)*/
	eff[3] = rtd_inl(DC_PHY_BANK_CONFLICT_reg);
	eff[4] = rtd_inl(DC_PHY_WRITE_TO_READ_reg);
	eff[5] = rtd_inl(DC_PHY_READ_TO_WRITE_reg);
#ifdef SUPPORT_DCU2
	/*efficiency measure of dcu2*/
	reg_eff_meas_ctrl.regValue = rtd_inl(dcu_addr(DC_PHY_EFF_MEAS_CTRL_reg,TRUE));
	reg_tmctrl3.regValue = rtd_inl(dcu_addr(DC_PHY_TMCTRL3_reg,TRUE));
	reg_read_cmd.regValue = rtd_inl(dcu_addr(DC_PHY_READ_CMD_reg,TRUE));
	reg_write_cmd.regValue = rtd_inl(dcu_addr(DC_PHY_WRITE_CMD_reg,TRUE));
	reg_read_chop_cmd.regValue = rtd_inl(dcu_addr(DC_PHY_READ_CHOP_CMD_reg,TRUE));
	reg_write_chop_cmd.regValue = rtd_inl(dcu_addr(DC_PHY_WRITE_CHOP_CMD_reg,TRUE));
	dividend = (u64)40000 * reg_read_cmd.rd_cnt - (u64)20000 * reg_read_chop_cmd.rd_chop_cnt;
	divisor = (u64)16 * (reg_tmctrl3.refcycle + 1) * \
		  reg_eff_meas_ctrl.meas_period * 4;
	eff2[1] = reg_eff_meas_ctrl.meas_period == 0 ? \
		 (u64)0 : div64_u64(dividend,divisor);
	dividend = (u64)40000 * reg_write_cmd.wr_cnt - (u64)20000 * reg_write_chop_cmd.wr_chop_cnt;
	eff2[2] = reg_eff_meas_ctrl.meas_period == 0 ? \
		 (u64)0 : div64_u64(dividend,divisor);
	eff2[0] = eff2[1] + eff2[2];
	/*efficient extension info(conflict ,w2r,r2w count)*/
	eff2[3] = rtd_inl(dcu_addr(DC_PHY_BANK_CONFLICT_reg,TRUE));
	eff2[4] = rtd_inl(dcu_addr(DC_PHY_WRITE_TO_READ_reg,TRUE));
	eff2[5] = rtd_inl(dcu_addr(DC_PHY_READ_TO_WRITE_reg,TRUE));
#else
    for(i=0;i<=5;i++){
        eff2[i] = 0;
    }
#endif
        /*PLL Frequency = 27*(NCODE + 3 + FCODE/2048) / (pllbush_pdiv + 1)*/
        reg_sys_pll_bush1.regValue = rtd_inl(PLL_REG_SYS_PLL_BUSH1_reg);
        reg_sys_pll_bush2.regValue = rtd_inl(PLL_REG_SYS_PLL_BUSH2_reg);
        N = reg_sys_pll_bush2.pllbus_ncode_h;
        F = reg_sys_pll_bush2.pllbus_fcode_h;
        PDIV = reg_sys_pll_bush1.pllbus_pdiv_h + 1;
        FreqH = 2700 * ((N + 3) * 2048 + F) / 2048  / 100 / PDIV;
	if(len > 14 && (len - 14) % 3 == 0){
		/*RTICE_DEBUG( \
		 * "[%s:%d]%d = 2700 * (%d +2) / (%d +1) /(%d + 1) 100\r\n",\
		 * __func__,__LINE__-1,FreqH,M,N,O);*/
		/*ack num of ips*/
#ifdef SUPPORT_DCU2
		ipbw[0] = rtd_inl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg,fdcu2));
		ipbw[1] = rtd_inl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg,fdcu2));
		ipbw[2] = rtd_inl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg,fdcu2));
#else
        	ipbw[0] = fdcu2?0:rtd_inl(DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg);
		ipbw[1] = fdcu2?0:rtd_inl(DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg);
		ipbw[2] = fdcu2?0:rtd_inl(DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg);
#endif
		divisor = (fdcu2 ? (u64)*ptotal_num2 : (u64)*ptotal_num);
		/*RTICE_DEBUG("[%s:%d]%llu = %u\r\n", \
		  *		__func__,__LINE__-1,divisor,*ptotal_num);*/
		dividend = (u64)1600 * (u64)ipbw[0] * (u64)FreqH;
		/*RTICE_DEBUG("[%s:%d]%llu = %u * %u * %u\r\n", \
		 *	__func__,__LINE__-1,dividend,1600,ipbw[0],FreqH);*/
		dividend =  divisor == 0 ? 0 :div64_u64(dividend,divisor);
		/*RTICE_DEBUG("[%s:%d]%llu = dividend / %llu\r\n", \
		 * __func__,__LINE__-1,dividend,divisor);*/
		ip[0] = dividend;
		/*RTICE_DEBUG("[%s:%d]%u = %llu\r\n", \
		 * __func__,__LINE__-1,ip[0],dividend);*/
		dividend = (u64)1600 * (u64)ipbw[1] * (u64)FreqH;
		/*RTICE_DEBUG("[%s:%d]%llu = %u * %u * %u\r\n", \
		 * __func__,__LINE__-1,dividend,1600,ipbw[1],FreqH);*/
		dividend =  divisor == 0 ? 0 :div64_u64(dividend,divisor);
		/*RTICE_DEBUG("[%s:%d]%llu = dividend / %llu\r\n", \
		 * __func__,__LINE__-1,dividend,divisor);*/
		ip[1] = dividend;
		/*RTICE_DEBUG("[%s:%d]%u = %llu\r\n", \
		 * __func__,__LINE__-1,ip[1],dividend);*/
		dividend = (u64)1600 * (u64)ipbw[2] * (u64)FreqH;
		/*RTICE_DEBUG("[%s:%d]%llu = %u * %u * %u\r\n", \
		 * __func__,__LINE__-1,dividend,1600,ipbw[2],FreqH);*/
		dividend =  divisor == 0 ? 0 :div64_u64(dividend,divisor);
		/*RTICE_DEBUG("[%s:%d]%llu = dividend / %llu\r\n", \
		 * __func__,__LINE__-1,dividend,divisor);*/
		ip[2] = dividend;
		/*RTICE_DEBUG("[%s:%d]%u= %llu\r\n", \
		 * __func__,__LINE__-1,ip[2],dividend);*/
		/*Max Latency*/
#ifdef SUPPORT_DCU2
		ip[3] = rtd_inl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg,fdcu2)) & 0xFFFF;
		ip[4] = rtd_inl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg,fdcu2)) & 0xFFFF;
		ip[5] = rtd_inl(dcu_addr(DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg,fdcu2)) & 0xFFFF;
#else
        ip[3] = fdcu2?0:(rtd_inl(DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg) & 0xFFFF);
		ip[4] = fdcu2?0:(rtd_inl(DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg) & 0xFFFF);
		ip[5] = fdcu2?0:(rtd_inl(DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg) & 0xFFFF);        
#endif
	}
	/*scpu bw*/
	reg_scpu_pc_tota_mon_num.regValue = \
		rtd_inl(DC_PHY_SCPU_PC_TOTA_MON_NUM_reg);
	reg_scpu_pc_ack_num.regValue = rtd_inl(DC_PHY_SCPU_PC_TOTA_ACK_NUM_reg);
#if 0
	reg_sys_pll_scpu1.regValue = rtd_inl(SCPU_CORE_sys_pll_scpu1_reg);
	reg_sys_pll_scpu2.regValue = rtd_inl(SCPU_CORE_sys_pll_scpu2_reg);
	N = reg_sys_pll_scpu2.pllscpu_ncode;
	F = reg_sys_pll_scpu2.pllscpu_fcode;
	if(reg_sys_pll_scpu1.pllscpu_pdiv_bps)
		PDIV = 1;
	else
		PDIV = reg_sys_pll_scpu1.pllscpu_pdiv + 2;
	PDIV = 1;
	/*FreqH = 27*(NCODE + 3 + FCODE/2048) / PDIV*/
	/*bw = 16 * reg_scpu_pc_ack_num.ack_num *
	 *   FreqH / reg_scpu_pc_tota_mon_num.tota_mon_num*/
	dividend = 2700 * ((N + 3) * 2048 + F) / 2048 / 100 / PDIV;
#else
	#define REG_DDR_NCODE_SSC 0xb8008028
	#define REG_DDR_FCODE_SSC 0xb8008024
	tmp = rtd_inl(REG_DDR_FCODE_SSC);
	F = ((tmp & 0x07FF0000) >> 16);
	tmp = rtd_inl(REG_DDR_NCODE_SSC);
	N = ((tmp & 0x0000FF00) >> 8);
	PDIV = 2;
	dividend = 2700 * ((N + 3) * 2048 + F) / 2048  / 100 / PDIV;
#endif
	/*RTICE_DEBUG("[%s:%d]%llu = 2700 * ((%u + 2) * 8192 + %u)  / 4\r\n",
	 * __func__,__LINE__-1,dividend,N,F);*/
	dividend = dividend * (u64)1600 * (u64)reg_scpu_pc_ack_num.ack_num;
	/*RTICE_DEBUG("[%s:%d]%llu = dividend * 16 * %u\r\n",
	 * __func__,__LINE__-1,dividend,reg_scpu_pc_ack_num.ack_num);*/

	/*<2 * 8192  *  2 * 100;*/
	divisor = reg_scpu_pc_tota_mon_num.tota_mon_num ;
	if(divisor == 0)
		dividend = 0;
	else
		dividend = div64_u64(dividend,divisor);
	/*RTICE_DEBUG("[%s:%d]%llu = dividend / %llu\r\n", \
	 * __func__,__LINE__-1,dividend,divisor);*/
	*pscup_bw  = dividend;
	/*RTICE_DEBUG("[%s:%d]%u = %llu \r\n", \
	 * __func__,__LINE__-1,*pscup_bw,dividend);*/
#ifdef SUPPORT_DCU2
	/*scpu bw of dcu2*/
	reg_scpu_pc_tota_mon_num.regValue = \
		rtd_inl(dcu_addr(DC_PHY_SCPU_PC_TOTA_MON_NUM_reg,TRUE));
	reg_scpu_pc_ack_num.regValue = rtd_inl(dcu_addr(DC_PHY_SCPU_PC_ack_num_reg,TRUE));
#if 0 //FIXME
	reg_sys_pll_ddr2.regValue = rtd_inl(PLL27X_REG_SYS_PLL_DDR2_reg);
	N = reg_sys_pll_ddr2.reg_dpi_n_code;
	F = reg_sys_pll_ddr2.reg_dpi_f_code;
#endif
	dividend = 2700 * ((N + 2) * 8192 + F)  / 32768;
	dividend = dividend * (u64)16 * (u64)reg_scpu_pc_ack_num.ack_num;
	divisor = reg_scpu_pc_tota_mon_num.tota_mon_num ;
	if(divisor == 0)
		dividend = 0;
	else
		dividend = div64_u64(dividend,divisor);
	*pscpu_bw2  = dividend;
#else
    *pscpu_bw2  = 0;    
#endif
	return 0;

}

#ifdef RTICE_BW_TIMER
static void check_entry(unsigned long data);
#else
static int bw_check_thread(void*data);
static void start_bw_check(void)
{
	if(g_bwCheck.f_run){
		if(g_bwCheck.f_stop == TRUE){
			g_bwCheck.f_stop = FALSE;
			wait_event_timeout(rtice_bw_wait_thread, \
				g_bwCheck.f_stoped == FALSE,100);
			/*msleep(100);*/
			RTICE_DEBUG("[%s:%d]Wake up thread\r\n", \
				__func__,__LINE__);
		}
	}
}

static int stop_bw_check(void)
{
	RTICE_DEBUG(\
	"[%s:%d]Thread Status:Thread=0x%08x;f_run=%d;f_stop=%d;f_stoped=%d\r\n",\
	__func__,__LINE__,(UINT32)g_bwCheck.p_thread,g_bwCheck.f_run,\
	g_bwCheck.f_stop,g_bwCheck.f_stoped);
	if(g_bwCheck.f_run){
		g_bwCheck.f_stop = TRUE;
		RTICE_DEBUG("[%s:%d]Try Stop thread\r\n",__func__,__LINE__);
		if(g_bwCheck.f_stoped == FALSE)
			wait_event_timeout(rtice_bw_wait_main, \
				g_bwCheck.f_stoped == TRUE,100);
		RTICE_DEBUG("[%s:%d]Checking thread is stoped:%d\r\n", \
			__func__,__LINE__,g_bwCheck.f_stoped);
	}
	return g_bwCheck.f_run ? g_bwCheck.f_stoped : TRUE;
}
#endif
/**
 * \brief Create or Start bw check thread.
**/
static int enter_bw_check(void)
{
	int ret = 0;
#ifdef RTICE_BW_TIMER
	g_bwCheck.p_timer = \
	    (struct timer_list*)kmalloc(sizeof(struct timer_list),GFP_ATOMIC);
	if(g_bwCheck.p_timer == NULL)
		return -RTICE_IOMEM_BW_CHECK_THREAD;
	/*check param init*/
	g_bwCheck.m_curCnt = 0;
	g_bwCheck.p_curIp = g_bwCheck.p_ipHeader;
	/*start dc check*/
	if(TRIPLET_IP(g_bwCheck.p_curIp))
		bw_select_ip(g_bwCheck.p_curIp->id,\
		g_bwCheck.p_curIp->p_next->id,\
		g_bwCheck.p_curIp->p_next->p_next->id);
	set_pc_go_status(1,FALSE);
	set_pc_go_status(1,TRUE);
	effi_measure_en(1,FALSE);
	effi_measure_en(1,TRUE);
	/* timer init*/
	init_timer(g_bwCheck.p_timer);
	g_bwCheck.p_timer->data = (unsigned long)&g_bwCheck;
	g_bwCheck.p_timer->function = check_entry;
	g_bwCheck.p_timer->expires = jiffies + (g_bwCheck.m_period ? \
		HZ * g_bwCheck.m_period / 1000 : HZ);
	RTICE_DEBUG("[%s:%d]Period=%d;HZ=%d;expires=%d\r\n", \
		__func__,__LINE__,g_bwCheck.m_period,HZ, \
		HZ * g_bwCheck.m_period / 1000);
	/*add timer*/
	add_timer(g_bwCheck.p_timer);
	/*check start flag*/
	g_bwCheck.f_run = TRUE;
#else
	/*create new checking thread*/
	g_bwCheck.p_thread = kthread_run(bw_check_thread, &g_bwCheck,\
	       	"BW Checking Thread");
	wait_event_timeout(rtice_bw_wait_main, g_bwCheck.f_run  == TRUE,100);
	if(IS_ERR(g_bwCheck.p_thread) || g_bwCheck.f_run  == FALSE){
		g_bwCheck.p_thread = NULL;
		RTICE_DEBUG("[%s]Fail to create bw checking thread\r\n", \
			__func__);
		ret = -RTICE_IOMEM_BW_CHECK_THREAD;
	}
	RTICE_DEBUG("[%s:%d]Success start check thread.\r\n", \
		__func__,__LINE__);
#endif
	return ret;
}
/**
 * \brief Exit and destory bw check thread.
**/
static int exit_bw_check(void)
{
	int ret = 0;
#ifdef RTICE_BW_TIMER
	if(g_bwCheck.p_timer){
		/*RTICE_DEBUG("[%s:%d]Free timer\r\n",__func__,__LINE__);*/
		del_timer(g_bwCheck.p_timer);
		kfree(g_bwCheck.p_timer);
		g_bwCheck.p_timer = NULL;
	}
	/*check start flag*/
	g_bwCheck.f_run = FALSE;
	/*try stop all check or measure flow*/
	set_pc_go_status(0,FALSE);
	effi_measure_en(0,FALSE);
	effi_measure_en(0,TRUE);
#else
	/*wake up checking thread*/
	RTICE_DEBUG(\
	"[%s:%d]Thread Status:Thread=0x%08x;f_run=%d;f_stop=%d;f_stoped=%d\r\n", \
	__func__,__LINE__,g_bwCheck.p_thread,g_bwCheck.f_run, \
	g_bwCheck.f_stop,g_bwCheck.f_stoped);
	if(g_bwCheck.f_run == TRUE){
		RTICE_DEBUG("[%s:%d]Thread is running.\r\n",__func__,__LINE__);
		if(g_bwCheck.f_stop ==TRUE){
			RTICE_DEBUG("[%s:%d]Thread is stopped\r\n", \
				__func__,__LINE__);
			g_bwCheck.f_stop = FALSE;
			wake_up(&rtice_bw_wait_thread);
		}else{
			g_bwCheck.f_stoped = FALSE;
		}
		/*< iterrupt and exit from running thread func*/
		g_bwCheck.f_run = FALSE;
	}
	if(g_bwCheck.p_thread && !IS_ERR(g_bwCheck.p_thread))
		kthread_stop(g_bwCheck.p_thread);
	msleep(100);
	g_bwCheck.p_thread = NULL;
#endif
	RTICE_DEBUG("[%s:%d]Exit From 'exit_bw_check'\r\n",__func__,__LINE__);
	return ret;
}

#ifndef RTICE_BW_TIMER
static int bw_check_thread(void*data)
{
	int ret = 0;
	unsigned int i = 0,j = 0;
	CBwIp *pIp = NULL;
	CBwCheck*pCheck = (CBwCheck*)data;
	UINT32 result_buf[10];
	UINT32 *pbuf;
	UINT32 sleepMs;

	RTICE_DEBUG("[%s:%d]f_run=%d,m_count =%d,m_period=%d\r\n", \
		__func__,__LINE__,pCheck->f_run,pCheck->m_count, \
		pCheck->m_period);
	pCheck->f_run = TRUE;
	wake_up(&rtice_bw_wait_main);

	if(!pCheck){
		ret = -1;
		goto BW_THREAD_EXIT;
	}
	for(i = 0;!kthread_should_stop() &&  \
		(!pCheck->m_count || i < pCheck->m_count) && pCheck->f_run;i++){
		/*msleep(25);*/
		/*one time check*/
		pIp = pCheck->p_ipHeader;/*< first checking ip.*/
		while(!kthread_should_stop() && pCheck->f_run &&  \
			(pCheck->p_ipHeader == NULL || TRIPLET_IP(pIp) ) ){

			RTICE_DEBUG("[%s:%d]Step -- Start Checking .\r\n", \
				__func__,__LINE__);
			/*select ip*/
			if(TRIPLET_IP(pIp))
				bw_select_ip(pIp->id, pIp->p_next->id,\
					pIp->p_next->p_next->id);
			/*start pc check*/
			set_pc_go_status(1);
			/*period sleep*/
			sleepMs = pCheck->m_period;
			while(sleepMs > 0 && !g_bwCheck.f_stop && \
			       	pCheck->f_run && !kthread_should_stop()){
				unsigned int tms = sleepMs >= 25 ? 25 : sleepMs;
				if(sleepMs >= 25)
					sleepMs -= 25;
				else
					sleepMs = 0;
				if(tms)
					/*msleep(tms);*/
					schedule_timeout(tms);
			}
			RTICE_DEBUG("[%s:%d]sleepMs=%d.\r\n", \
				__func__,__LINE__,sleepMs);
			/*stop pc check*/
			set_pc_go_status(0);
			/*check whether need stop current checking flow*/
			RTICE_DEBUG("[%s:%d]Thread Status:Thread=0x%08x;
				f_run=%d;f_stop=%d;f_stoped=%d\r\n", \
				__func__,__LINE__, \
				(UINT32)g_bwCheck.p_thread,g_bwCheck.f_run, \
				g_bwCheck.f_stop,g_bwCheck.f_stoped);
			if(g_bwCheck.f_stop == TRUE){
				/*wake up main and pending itself*/
				g_bwCheck.f_stoped = TRUE;
				wake_up(&rtice_bw_wait_main);
				RTICE_DEBUG( \
					"[%s:%d]Wait g_bwCheck.f_stop == FALSE
					\r\n",__func__,__LINE__);
				wait_event_timeout(rtice_bw_wait_thread, \
					g_bwCheck.f_stop == FALSE,100);
				RTICE_DEBUG("[%s:%d]Wait Up g_bwCheck.f_stop =%d
					\r\n",__func__,__LINE__, \
					g_bwCheck.f_stop);
			}
			if(g_bwCheck.f_stop == FALSE){
				/*< continue running*/
				g_bwCheck.f_stoped = FALSE;
				/*record check result*/
				if(TRIPLET_IP(pIp)){
					RTICE_DEBUG("[%s:%d]check_result...has
						ips.\r\n",__func__,__LINE__);
					check_result(result_buf, \
						sizeof(result_buf));
				}else{
					RTICE_DEBUG("[%s:%d]check_result..no ips
						.\r\n",__func__,__LINE__);
					check_result(result_buf,7);
				}
				/*saving result to ip list.*/
				pbuf = result_buf;
				pCheck->m_pc_total_cycle = *pbuf++;
				if(pCheck->m_pc_total_cycle >  \
					pCheck->m_pc_total_cycle_max)
					pCheck->m_pc_total_cycle_max = \
						pCheck->m_pc_total_cycle;
				pCheck->m_pc_total_ack = *pbuf++;
				if(pCheck->m_pc_total_ack > \
					pCheck->m_pc_total_ack_max)
					pCheck->m_pc_total_ack_max = \
						pCheck->m_pc_total_ack;
				pCheck->m_pc_total_idle = *pbuf++;
				if(pCheck->m_pc_total_idle < \
					pCheck->m_pc_total_idle_min)
					pCheck->m_pc_total_idle_min = \
						pCheck->m_pc_total_idle;
				pCheck->m_scpu_bw = *pbuf++;
				if(pCheck->m_scpu_bw > pCheck->m_scpu_bw_max)
					pCheck->m_scpu_bw_max = \
						pCheck->m_scpu_bw;
				pCheck->m_effi_total = *pbuf & 0xffff;
				if(pCheck->m_effi_total > \
					pCheck->m_effi_total_max)
					pCheck->m_effi_total_max = \
						pCheck->m_effi_total;
				pbuf++;
				pCheck->m_effi_rd= *pbuf & 0xffff;
				if(pCheck->m_effi_rd > pCheck->m_effi_rd_max)
					pCheck->m_effi_rd_max = \
						pCheck->m_effi_rd;
				pbuf++;
				pCheck->m_effi_wr = *pbuf & 0xffff;
				if(pCheck->m_effi_wr  > pCheck->m_effi_wr_max)
					pCheck->m_effi_wr_max = \
						pCheck->m_effi_wr ;
				pbuf++;
				if(TRIPLET_IP(pIp)){
			/*update current and history max to ip element*/
					j = 0;
					while(j < 3){
						pIp->m_curBw = *pbuf++;
						if(pIp && pIp->m_curBw >  \
							pIp->m_maxBw)
							pIp->m_maxBw = \
								pIp->m_curBw;
						j++;
						pIp = pIp->p_next;
					}
					RTICE_DEBUG( \
						"[%s:%d]p0:%u;p1:%u;p2:%u\r\n", \
						__func__,__LINE__,pIp->m_curBw, \
						pIp->p_next->m_curBw, \
						pIp->p_next->p_next->m_curBw);
				}
			}
			RTICE_DEBUG("[%s:%d]Step  -- Finish Checking.\r\n", \
				__func__,__LINE__);
		}
		/*finish once check*/
		RTICE_DEBUG("[%s:%d]Check Progress:%d/%d.\r\n" \
			,__func__,__LINE__,i+1,pCheck->m_count);
	}

BW_THREAD_EXIT:
	RTICE_DEBUG("===========\r\n[%s:%d]All Finish\r\n============\r\n", \
		__func__,__LINE__);
	pCheck->f_run = FALSE;
	while(!kthread_should_stop()) msleep(5);
	/*wait_event(rtice_bw_wait_thread,pCheck->f_run == TRUE);
	 * \ suspended itself and wait thread_stop();*/
	return ret;
}
#else
static void check_entry(unsigned long data)
{
	CBwIp *pIp = NULL;
	CBwCheck*pCheck = (CBwCheck*)data;
	UINT32 result_buf[26] = {0};
	UINT32 *pbuf = NULL;
	int j = 0;

	if(!pCheck)
		return;

	/*stop dc check*/
	set_pc_go_status(0,FALSE);
	/*acquire check result*/
	pIp = pCheck->p_curIp;
	if(TRIPLET_IP(pIp)){
		/*RTICE_DEBUG("[%s:%d]check_result...has ips.\r\n"
		 * ,__func__,__LINE__);*/
		check_result(result_buf,sizeof(result_buf),pIp->id & 0x80);
	}else{
		/*RTICE_DEBUG("[%s:%d]check_result...no ips.\r\n",
		 * __func__,__LINE__);*/
		check_result(result_buf,sizeof(result_buf) - 3,FALSE);
	}
	/*saving result to ip list.*/
	pbuf = &result_buf[0];
	if(pCheck->m_curCnt >= SKIP_FOREFRONT_CNT){
		BW_DATA_W(&pCheck->m_total_cycle, pbuf[0]);
		BW_DATA_W(&pCheck->m_total_ack,pbuf[1]);
		BW_DATA_W(&pCheck->m_total_idle,pbuf[2]);
		BW_DATA_W(&pCheck->m_scpu,pbuf[3]);
		if(is_effi_finish(FALSE) != 0){/*< dcu1 measure is finished*/
			RTICE_DEBUG("[%s:%d]DCU1 Upgrade Efficiency Result.\r\n", \
				__func__,__LINE__);
			BW_DATA_W(&pCheck->m_eff_total,pbuf[4]);
			BW_DATA_W(&pCheck->m_eff_rd,pbuf[5]);
			BW_DATA_W(&pCheck->m_eff_wr,pbuf[6]);
			BW_DATA_W(&pCheck->m_bankConflict,pbuf[7]);
			BW_DATA_W(&pCheck->m_w2rCnt,pbuf[8]);
			BW_DATA_W(&pCheck->m_r2wCnt,pbuf[9]);
		}
		BW_DATA_W(&pCheck->m_total_cycle_dcu2, pbuf[10]);
		BW_DATA_W(&pCheck->m_total_ack_dcu2,pbuf[11]);
		BW_DATA_W(&pCheck->m_total_idle_dcu2,pbuf[12]);
		BW_DATA_W(&pCheck->m_scpu2,pbuf[13]);
		if(is_effi_finish(TRUE) != 0){/*< dcu2 measure is finished*/
			RTICE_DEBUG("[%s:%d]DCU2 Upgrade Efficiency Result.\r\n", \
				__func__,__LINE__);
			BW_DATA_W(&pCheck->m_eff_total2,pbuf[14]);
			BW_DATA_W(&pCheck->m_eff_rd2,pbuf[15]);
			BW_DATA_W(&pCheck->m_eff_wr2,pbuf[16]);
			BW_DATA_W(&pCheck->m_bankConflict2,pbuf[17]);
			BW_DATA_W(&pCheck->m_w2rCnt2,pbuf[18]);
			BW_DATA_W(&pCheck->m_r2wCnt2,pbuf[19]);
		}
	}
	pbuf += 20;
	if(TRIPLET_IP(pIp)){
		CBwIp *ptIp = pIp;
		/*update current and history max to ip element*/
		j = 0;
		while(j < 3 && ptIp){
			/*RTICE_DEBUG("-[ptIp]sum=%llu;his=%llu;cur=%u;max=%u; \
			 * min=%u;\r\n",ptIp->m_sumBw,ptIp->m_hisLen,pbuf[0], \
			 * ptIp->m_maxBw,ptIp->m_minBw);*/
			if(pCheck->m_curCnt >= SKIP_FOREFRONT_CNT){
				BW_LAT_DATA_W(ptIp,pbuf[0],(UINT16)pbuf[3]);
	RTICE_DEBUG("+[id:%02x]cur=%u;sum=%llu;his=%llu;max=%u;min=%u;\r\n",\
					ptIp->id,ptIp->m_curBw,ptIp->m_sumBw, \
					ptIp->m_hisLen,ptIp->m_maxBw, \
					ptIp->m_minBw);
			}
			pbuf++;
			j++;
			ptIp = ptIp->p_next;
		}
		/*
		RTICE_DEBUG("[%s:%d]Result:%d=%u;%d=%u;%d=%u\r\n",
			__func__,__LINE__,\
			pIp->id,pIp->m_curBw,\
			pIp->p_next->id,pIp->p_next->m_curBw,\
			pIp->p_next->p_next->id,pIp->p_next->p_next->m_curBw);
		*/
	}
	/*finished once checking?*/
	if(TRIPLET_IP(pIp))
		pCheck->p_curIp = pIp->p_next->p_next->p_next;
	if(pCheck->p_ipHeader == NULL || !TRIPLET_IP(pCheck->p_curIp)){
		pCheck->m_curCnt++;
		pCheck->p_curIp = pCheck->p_ipHeader;
		/*finish once check*/
		RTICE_DEBUG("[%s:%d]Check Progress:%d/%d.\r\n", \
			__func__,__LINE__,pCheck->m_curCnt,pCheck->m_count);
	}
	/*finished all checking?*/
	if(pCheck->m_count == 0 || pCheck->m_curCnt <  \
		pCheck->m_count + SKIP_FOREFRONT_CNT){/*< need continue check*/
		/*start dc check*/
		if(TRIPLET_IP(pCheck->p_curIp))
			bw_select_ip(pCheck->p_curIp->id, \
				pCheck->p_curIp->p_next->id, \
				pCheck->p_curIp->p_next->p_next->id);
		set_pc_go_status(1,FALSE);
		set_pc_go_status(1,TRUE);
		effi_measure_en(1,FALSE);
		effi_measure_en(1,TRUE);
		/*restart timer*/
		pCheck->p_timer->function = check_entry;
		pCheck->p_timer->expires = jiffies + \
			(pCheck->m_period ? HZ * pCheck->m_period / 1000 : HZ);
		add_timer(pCheck->p_timer);
	}else{
		pCheck->f_run = FALSE;
		RTICE_DEBUG("===========\r\nAll Finish.\r\n=============\r\n");
	}
}
#endif
/*------------------------------------------------------------------
 * Func : rtice_iomem2_command_handler
 *
 * Desc : proc iomem command
 *
 * Parm : cmd_data : command data
 *        command_data_len  : command data len
 *
 * Retn :  < 0    : error
 *         others : length of response data
 *------------------------------------------------------------------*/
int rtice_iomem2_command_handler(
    unsigned char       opcode,
    unsigned char*      cmd_data,
    unsigned int        command_data_len,
    unsigned char*      response_data,
    unsigned int        response_buff_size
    )
{
	int ret = 0;
	switch(opcode){
	case RTICE_IOMEM_CMD_ENTER_BW_CHECK:
		/*stop bw check thread if it is runing now.*/
		exit_bw_check();
		/*check param init*/
		memset(&g_bwCheck,0,sizeof(CBwCheck));
		BW_DATA_CLR(&g_bwCheck.m_total_cycle);
		BW_DATA_CLR(&g_bwCheck.m_total_ack);
		BW_DATA_CLR(&g_bwCheck.m_total_idle);
		BW_DATA_CLR(&g_bwCheck.m_scpu);
		BW_DATA_CLR(&g_bwCheck.m_eff_total);
		BW_DATA_CLR(&g_bwCheck.m_eff_rd);
		BW_DATA_CLR(&g_bwCheck.m_eff_wr);
		BW_DATA_CLR(&g_bwCheck.m_eff_total);
		BW_DATA_CLR(&g_bwCheck.m_eff_rd);
		BW_DATA_CLR(&g_bwCheck.m_eff_wr);
		BW_DATA_CLR(&g_bwCheck.m_total_cycle_dcu2);
		BW_DATA_CLR(&g_bwCheck.m_total_ack_dcu2);
		BW_DATA_CLR(&g_bwCheck.m_total_idle_dcu2);
		BW_DATA_CLR(&g_bwCheck.m_eff_total2);
		BW_DATA_CLR(&g_bwCheck.m_eff_rd2);
		BW_DATA_CLR(&g_bwCheck.m_eff_wr2);
		BW_DATA_CLR(&g_bwCheck.m_eff_total2);
		BW_DATA_CLR(&g_bwCheck.m_eff_rd2);
		BW_DATA_CLR(&g_bwCheck.m_eff_wr2);
		/*checking params length*/
		if(command_data_len < 6 || \
			command_data_len != 3 * (2+cmd_data[5]))
			return -RTICE_IOMEM_BW_INVALID_PARAM;
		/*
		check mode
		if(cmd_data[0] >= BW_CHECK_MODE_SIZE)
			return -RTICE_IOMEM_BW_INVALID_MODE;
		else
			g_bwCheck.m_mode = cmd_data[0];
		*/
		g_bwCheck.m_count = cmd_data[0];
		g_bwCheck.m_measPeriod = B2TS(cmd_data[1], cmd_data[2]);
		/*check interval*/
		g_bwCheck.m_period = B2TS( cmd_data[3], cmd_data[4]);
		g_bwCheck.m_grpNum = cmd_data[5];
		RTICE_DEBUG("[%s:%d]DC Period:%d,Meas Period=%d\r\n", \
			__func__,__LINE__,g_bwCheck.m_period, \
			g_bwCheck.m_measPeriod);
		/*if(g_bwCheck.m_ipListCnt + g_bwCheck.m_grpNum * 3 > \
		 * MAX_BW_CHECK_IP)*/
		bw_ip_list_clear();
		/*alocate checking ips*/
		bw_ip_list_init(g_bwCheck.m_grpNum*3, &cmd_data[6]);
		return enter_bw_check();
	case RTICE_IOMEM_CMD_BW_CHECK_RESULT:
	{
		UINT8* presData = response_data;
		CBwIp *pIp = NULL;
		UINT8 grpNum = g_bwCheck.m_grpNum;
		UINT8 i = 0;
		UINT32 bws[4],t32 = 0;
		UINT16 lats[3] = {0};
		UINT16 global_data_len = 0;
		/*
		if(g_bwCheck.f_run && g_bwCheck.f_stop) thread has been stopped
			return -RTICE_IOMEM_BW_BUSY;
		*/

		if(command_data_len != 1 || cmd_data[0] >= BW_IP_QUERY_SIZE)
			return -RTICE_IOMEM_BW_INVALID_PARAM;
		/*
		stop bw checking.
		if(stop_bw_check()  == 0)
			return -RTICE_IOMEM_BW_STOP_FAIL;
		*/
		/**query info*/
		*presData++ = 0x80 + 1;/*extend data type*/
		/*global area length*/
		global_data_len = 69 + 2;
		STB2(global_data_len,presData[0],presData[1]);
		presData += 2;
		/*global dc & scpu value*/
		t32  = BW_DATA_R(&g_bwCheck.m_total_cycle,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32 = BW_DATA_R(&g_bwCheck.m_total_ack,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_total_idle,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_scpu,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		/*dcu1 efficiency value*/
		t32  = BW_DATA_R(&g_bwCheck.m_eff_total,cmd_data[0]);
		STB2(t32  ,presData[0],presData[1]);
		presData += 2;
		t32   = BW_DATA_R(&g_bwCheck.m_eff_rd,cmd_data[0]);
		STB2(t32  ,presData[0],presData[1]);
		presData += 2;
		t32   = BW_DATA_R(&g_bwCheck.m_eff_wr,cmd_data[0]);
		STB2(t32  ,presData[0],presData[1]);
		presData += 2;
		t32  = BW_DATA_R(&g_bwCheck.m_bankConflict,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_w2rCnt,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_r2wCnt,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		/*dcu2 total param*/
		t32  = BW_DATA_R(&g_bwCheck.m_total_cycle_dcu2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32 = BW_DATA_R(&g_bwCheck.m_total_ack_dcu2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_total_idle_dcu2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_scpu2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		/*dcu2 efficiency value*/
		t32  = BW_DATA_R(&g_bwCheck.m_eff_total2,cmd_data[0]);
		STB2(t32  ,presData[0],presData[1]);
		presData += 2;
		t32   = BW_DATA_R(&g_bwCheck.m_eff_rd2,cmd_data[0]);
		STB2(t32  ,presData[0],presData[1]);
		presData += 2;
		t32   = BW_DATA_R(&g_bwCheck.m_eff_wr2,cmd_data[0]);
		STB2(t32  ,presData[0],presData[1]);
		presData += 2;
		t32  = BW_DATA_R(&g_bwCheck.m_bankConflict2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_w2rCnt2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		t32  = BW_DATA_R(&g_bwCheck.m_r2wCnt2,cmd_data[0]);
		LTB4(t32 , presData[0], presData[1], presData[2],presData[3]);
		presData += 4;
		/*ip bw value*/
		pIp = g_bwCheck.p_ipHeader;
		/*RTICE_DEBUG("[%s::%d]grpNum=%d\r\n", \
		 * __func__,__LINE__,grpNum);*/
		while(pIp && grpNum){
			bws[i] = BW_DATA_R(pIp,cmd_data[0]);
			lats[i] = LAT_DATA_R(pIp,cmd_data[0]);
			/*RTICE_DEBUG("[%s::%d]bw=%u;sum=%u;hisLen=%u\r\n", \
			 * __func__,__LINE__,bws[i],pIp->m_sumBw, \
			 * pIp->m_hisLen);*/
			if(i == 2){
				bws[3] = bws[0] + bws[1] + bws[2];
				for(i = 0; i < 4;i++){
					LTB4(bws[i], presData[0], presData[1], \
					       	presData[2],presData[3]);
					presData += 4;
				}
				for(i = 0;i < 3;i++){
					STB2(lats[i], presData[0], presData[1]);
					presData += 2;
				}
				grpNum--;
				i = 0;
			}else{
				i++;
			}
			pIp = pIp->p_next;
		}
		/*RTICE_DEBUG("[%s::%d]grpNum=%d\r\n",\
		 * __func__,__LINE__,grpNum);*/
		/*start bw checking*/
		/*start_bw_check();*/
		if(grpNum != 0)
			return -RTICE_IOMEM_BW_WRONG_GROUPNUM;
		/*ret*/
		ret = g_bwCheck.m_grpNum * (4 * 4 + 6) + global_data_len;
	}
	break;
	case RTICE_IOMEM_CMD_EXIT_BW_CHECK:
		return exit_bw_check();
	case RTICE_IOMEM_CMD_BW_CHECK_STATUS:
		if(g_bwCheck.f_run)
			response_data[0] = BW_CHECK_STATUS_RUN;
		else
			response_data[0] = BW_CHECK_STATUS_STOP;
		ret = 1;
	break;
	default:
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
	}/*~switch(opcode)*/
	return ret;
}

/*------------------------------------------------------------------
 * Func : rtice_i2c_command_probe
 *
 * Desc : proc i2c command
 *
 * Parm : opcode
 *
 * Retn :
 *------------------------------------------------------------------*/
int rtice_iomem2_command_probe(unsigned char op_code)
{
	return 1;
}



rtice_command_handler_t iomem2_cmd_handler[] =
{
	{
		RTICE_CMD_GROUP_BW_CHECK,
		rtice_iomem2_command_probe,
		rtice_iomem2_command_handler
	},
};


/*------------------------------------------------------------------
 * Func : rtice_iomem_tool_init
 *
 * Desc : register rtice io/mem tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/

static int __init rtice_iomem2_tool_init(void)
{
	rtice_register_command_handler(iomem2_cmd_handler, \
		sizeof(iomem2_cmd_handler)/sizeof(rtice_command_handler_t));
	return 0;
}



/*------------------------------------------------------------------
 * Func : rtice_iomem_tool_exit
 *
 * Desc : exit rtice io/mem tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_iomem2_tool_exit(void)
{
	rtice_unregister_command_handler(iomem2_cmd_handler, \
		sizeof(iomem2_cmd_handler)/sizeof(rtice_command_handler_t));
	printk("rtice_unregister_command_handler() has been executed.\n");
	/*stop and exit from bw checking thread and destory it.*/
	exit_bw_check();
	/*clear bw checking ip list.*/
	bw_ip_list_clear();
}


module_init(rtice_iomem2_tool_init);
module_exit(rtice_iomem2_tool_exit);
