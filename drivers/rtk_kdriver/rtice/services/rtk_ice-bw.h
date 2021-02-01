#ifndef __RTICE_BW_H__
#define __RTICE_BW_H__
#include "../core/rtk_ice.h"
#include <linux/math64.h>

#define RTICE_BW_TIMER
#define BW_RESULT_HIS_LEN 256
/*                   self def data type                  */
/*bw check mode*/
typedef enum{
	BW_CHECK_CONTINUE = 0,
	BW_CHECK_SINGLE,
	BW_CHECK_COUNTER,
	BW_CHECK_MODE_SIZE/*< total size of checking mode.*/
}ENUM_BW_CHECK_MODE;
/*bw check status*/
typedef enum{
	BW_CHECK_STATUS_STOP = 0,/*< End or Stop of current check thread.*/
	BW_CHECK_STATUS_RUN,       /*< Check thread is running now.*/

	BW_CHECK_STATUS_SIZE     /*< Total size of check status.*/
}ENUM_BW_CHECK_STATUS;
/*ip bw info data type*/
typedef enum{
	BW_IP_QUERY_CURRENT = 0,/*< query current bw*/
	BW_IP_QUERY_MAX,/*< Maxmum of history bw*/
	BW_IP_QUERY_MIN,/*< Minmum of history bw*/
	BW_IP_QUERY_MEAN,/*< Mean of history bw*/
	BW_IP_QUERY_HISTORY,      /*< query history bw*/
	BW_IP_QUERY_SIZE
} ENUM_BW_QUERY;
/*bw check ip and check result*/
typedef struct _CBwIp{
	UINT8 id;/*< id of current ip*/
	UINT32 m_curBw;/*< current bw*/
	UINT32 m_maxBw;/*< max bw of history checking*/
	UINT32 m_minBw;/*< min bw of history checking*/
	u64 m_sumBw;/*< mean bw of history checking*/
	u64 m_hisLen;/*< Length of valid history result data in sum section.*/
	UINT16 m_curLat;/*current latency*/
	UINT16 m_maxLat;/*max latency*/
	UINT16 m_minLat;/*min latency*/
	u64 m_sumLat;/* sum lat of history checking*/
	u64 m_hisLenLat;/*< Length of valid history result data in sum section.*/
	struct _CBwIp *p_prev;
	struct _CBwIp *p_next;
} CBwIp;
/*bw check param*/
typedef struct{
#ifdef RTICE_BW_TIMER
	struct timer_list *p_timer;/*< timer list for bw checking*/
	UINT32 m_curCnt;/*< Current count.*/
	CBwIp *p_curIp;/*< Point to the next ip that is need checking.*/
#else
	struct task_struct *p_thread;/*< thread handler of bw checking.*/
#endif
	BOOL f_run;/*< whether thread function has been or need to return.*/
	BOOL f_stop;/*< Send stop single to check thread.*/
	BOOL f_stoped;/*< whether current check thread is stoped.*/
/*< Total count of checking (0:means continue check till recieve end check cmd*/
	UINT8 m_count;
	UINT16 m_period;/*< interval between twice check.(ms unit)*/
	UINT16 m_measPeriod;/*< Period of efficient measure.*/
	UINT8 m_grpNum;/*< Number of group for checking.*/
	UINT32 m_ipListCnt;/*< Total count of buffer that can save info of ip.*/
	CBwIp *p_ipHeader;/*< point to the header of ips list..*/
	CBwIp *p_ipTail;/*< point to the tail of ips list..*/
	CBwIp m_total_cycle;
	CBwIp m_total_ack;
	CBwIp m_total_idle;
	CBwIp m_scpu;
	CBwIp m_eff_total;
	CBwIp m_eff_rd;
	CBwIp m_eff_wr;
	CBwIp m_bankConflict;
	CBwIp m_w2rCnt;
	CBwIp m_r2wCnt;
	CBwIp m_total_cycle_dcu2;
	CBwIp m_total_ack_dcu2;
	CBwIp m_total_idle_dcu2;
	CBwIp m_scpu2;
	CBwIp m_eff_total2;
	CBwIp m_eff_rd2;
	CBwIp m_eff_wr2;
	CBwIp m_bankConflict2;
	CBwIp m_w2rCnt2;
	CBwIp m_r2wCnt2;
} CBwCheck;
/*macro def          */
/*OPCode Code*/
/*enter bw check process*/
#define RTICE_IOMEM_CMD_ENTER_BW_CHECK \
	RTICE_OP_CODE(RTICE_CMD_GROUP_BW_CHECK, 0)
/*query bw check result.*/
#define RTICE_IOMEM_CMD_BW_CHECK_RESULT \
	RTICE_OP_CODE(RTICE_CMD_GROUP_BW_CHECK, 1)
/*exit bw check process*/
#define RTICE_IOMEM_CMD_EXIT_BW_CHECK \
	RTICE_OP_CODE(RTICE_CMD_GROUP_BW_CHECK, 2)
/*status of bw check process*/
#define RTICE_IOMEM_CMD_BW_CHECK_STATUS \
	RTICE_OP_CODE(RTICE_CMD_GROUP_BW_CHECK, 3)
/* Error Code*/
#define RTICE_IOMEM_BW_INVALID_PARAM			RTICE_FUNC_ERR(0)
#define RTICE_IOMEM_BW_INVALID_MODE			RTICE_FUNC_ERR(1)
#define RTICE_IOMEM_BW_CHECK_BUSY			RTICE_FUNC_ERR(2)
#define RTICE_IOMEM_BW_CHECK_THREAD			RTICE_FUNC_ERR(3)
#define RTICE_IOMEM_BW_WRONG_GROUPNUM		RTICE_FUNC_ERR(4)
#define RTICE_IOMEM_BW_WAKEUP_TIMEOUT		RTICE_FUNC_ERR(5)
#define RTICE_IOMEM_BW_STOP_FAIL			RTICE_FUNC_ERR(6)
#define RTICE_IOMEM_BW_BUSY				RTICE_FUNC_ERR(7)

#endif/*~__RTICE_BW_H__*/
