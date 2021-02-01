#include <linux/math64.h>
#include <linux/kernel.h>
#include <linux/string.h>

#include "rtkdemux_debug.h"
#include "rtkdemux_common.h"
#include "rtkdemux_LinearRegression.h"

#define MULTIPLE_PRECISION 10000
#define SLOPE_PRECISION    1000

#ifndef abs64
#define abs64 abs
#endif

void LRegress_Reset(DEMUX_LINEARREGRESSION_T *pLRegress)
{

    pLRegress->m_a = 0;
    pLRegress->m_b = 0;

    pLRegress->m_pairNum = 0;
    pLRegress->m_pairIdx = 0;

    memset(&pLRegress->m_BasePair, 0, sizeof(LINEARPAIR));
    memset(&pLRegress->m_restoredPair, 0, sizeof(LINEARPAIR));
    memset(&pLRegress->m_dataPair, 0, sizeof(LINEARPAIR)*LINEAR_REGRESSION_SAMPLE_NUM);
    dmx_mask_print(DEMUX_LR_DEBUG|DEMUX_NOTICE_PRINT, "%s %d LRegress_Reset !!!\n",__func__, __LINE__);
}

int LRegress_InsertDataPair(DEMUX_LINEARREGRESSION_T *pLRegress , LINEARPAIR pair)
{
    if(pLRegress->m_pairNum == 0)
    {
        pLRegress->m_BasePair.x = pair.x;
        pLRegress->m_BasePair.y = pair.y;
    }
    pLRegress->m_restoredPair.x    = pLRegress->m_dataPair[pLRegress->m_pairIdx].x; 
    pLRegress->m_restoredPair.y    = pLRegress->m_dataPair[pLRegress->m_pairIdx].y;

	/* Because PCR and STC are 64-bits, it is easy to reach overflow when calculate sum. 
	 * That is why we transform X/Y to difference.
	 */
    pLRegress->m_dataPair[pLRegress->m_pairIdx].x = pair.x - pLRegress->m_BasePair.x;
    pLRegress->m_dataPair[pLRegress->m_pairIdx].y = pair.y - pLRegress->m_BasePair.y;

    //if pcr not change , drop it
    
    if ((pLRegress->m_pairNum > 0) && 
        (pLRegress->m_dataPair[(pLRegress->m_pairIdx-1+LINEAR_REGRESSION_SAMPLE_NUM)%LINEAR_REGRESSION_SAMPLE_NUM].y== pLRegress->m_dataPair[pLRegress->m_pairIdx].y))
    {
        pLRegress->m_dataPair[pLRegress->m_pairIdx].x = pLRegress->m_restoredPair.x;
        pLRegress->m_dataPair[pLRegress->m_pairIdx].y = pLRegress->m_restoredPair.y;
        dmx_mask_print(DEMUX_LR_DEBUG, "%s,%d :: pcr not change drop it: pcr:%lld, stc:%lld \n", __func__, __LINE__, pair.y, pair.x);
        return -1;
    }
    
    if(pLRegress->m_pairNum < LINEAR_REGRESSION_SAMPLE_NUM)
        pLRegress->m_pairNum++;

    pLRegress->m_pairIdx++;
    if(pLRegress->m_pairIdx >= LINEAR_REGRESSION_SAMPLE_NUM)
        pLRegress->m_pairIdx = 0;

    return 0;
}
void LRegress_PopDataPair(DEMUX_LINEARREGRESSION_T *pLRegress)
{
    if (pLRegress->m_pairNum >0)
    {        
        dmx_mask_print(DEMUX_LR_DEBUG|DEMUX_NOTICE_PRINT,"[LRegress] [%s_%d] LR drop data: (%lld,%lld), base(%lld, %lld)\n",
            __func__, __LINE__, pLRegress->m_dataPair[pLRegress->m_pairIdx].x, pLRegress->m_dataPair[pLRegress->m_pairIdx].y, pLRegress->m_BasePair.x, pLRegress->m_BasePair.y);
        
        pLRegress->m_pairIdx = (pLRegress->m_pairIdx+LINEAR_REGRESSION_SAMPLE_NUM -1)%LINEAR_REGRESSION_SAMPLE_NUM;
        pLRegress->m_dataPair[pLRegress->m_pairIdx].x =pLRegress->m_restoredPair.x;
        pLRegress->m_dataPair[pLRegress->m_pairIdx].y =pLRegress->m_restoredPair.y;
        if (pLRegress->m_pairNum <LINEAR_REGRESSION_SAMPLE_NUM ||(pLRegress->m_restoredPair.x==0 && pLRegress->m_restoredPair.y==0))/*pop at first round insert*/
            pLRegress->m_pairNum--;
    } 
}

void LRegress_CalculateAB(DEMUX_LINEARREGRESSION_T *pLRegress)
{
/*
least square error :
                       _          _
             sum((Xi - X) * (Yi - Y))             sum(Yi - aXi)
        a = --------------------------        b = -------------
                        _          _                   n
              sum((Xi - X) * (Xi - X))

Y = aX + b
Y is PCR and X is STC.
*/
    int64_t x_sum[SUM_GROUP_NUM] = {0}, y_sum[SUM_GROUP_NUM] = {0};
    int32_t x_remain = 0, y_remain = 0;
    int64_t x_ave = 0, y_ave = 0;
    int64_t x_dif = 0, y_dif = 0;
    int64_t xy_dif_sum = 0;
    int64_t x_dif_sqr_sum = 0;
    int sum_idx = 0;
    int64_t xy_sum_dif = 0;
	int i=0;

	x_sum[sum_idx] = 0;
	y_sum[sum_idx] = 0;
	x_remain = 0;
	y_remain = 0;

    for(i=0; i<pLRegress->m_pairNum; i++)
    {
        x_sum[sum_idx] += pLRegress->m_dataPair[i].x;
        y_sum[sum_idx] += pLRegress->m_dataPair[i].y;

		if(((i+1) % GROUP_SAMPLE_NUM) == 0 || (i+1) == pLRegress->m_pairNum) {
			x_ave += div64_s64((x_sum[sum_idx] + x_remain) , pLRegress->m_pairNum );
			y_ave += div64_s64((y_sum[sum_idx] + y_remain) , pLRegress->m_pairNum );

			sum_idx++;
			if(sum_idx < SUM_GROUP_NUM) {
				div_s64_rem( x_sum[sum_idx-1] , pLRegress->m_pairNum , &x_remain );
				div_s64_rem( y_sum[sum_idx-1] , pLRegress->m_pairNum , &y_remain );
			}
		}
    }

	for(i=0; i<pLRegress->m_pairNum; i++)
	{
		x_dif = pLRegress->m_dataPair[i].x - x_ave;
		y_dif = pLRegress->m_dataPair[i].y - y_ave;
		xy_dif_sum += x_dif * y_dif;
		x_dif_sqr_sum += x_dif * x_dif;
	}

	/* In order not to declare as float, we enlarge it 10000 times */
	pLRegress->m_a =  div64_s64((MULTIPLE_PRECISION * xy_dif_sum) , x_dif_sqr_sum);

	for(i=0; i<SUM_GROUP_NUM; i++)
	{
		xy_sum_dif += ( (MULTIPLE_PRECISION * y_sum[i]) - (pLRegress->m_a * x_sum[i]) );
	}
	pLRegress->m_b = div64_s64(xy_sum_dif , pLRegress->m_pairNum);
}

int64_t LRegress_GetPredictY(DEMUX_LINEARREGRESSION_T *pLRegress , int64_t x)
{
    int64_t tmp_y = 0;

	/*
	dmx_dbg("\033[1;36m [%s %d] [%d, %lld][%lld, %lld] \033[m\n",__func__ , __LINE__ ,pLRegress->m_pairIdx, pLRegress->m_pairNum, pLRegress->m_BasePair.x, pLRegress->m_BasePair.y);
	dmx_dbg("\033[1;36m [%s %d] [%d, %lld][%lld, %lld] \033[m\n",__func__ , __LINE__ ,pLRegress->m_pairIdx, pLRegress->m_pairNum, pLRegress->m_a, pLRegress->m_b);
	*/

    if(pLRegress->m_pairNum < 10)
        tmp_y = 0;
    else
    {
        LRegress_CalculateAB(pLRegress);

		/*When slope was negative means wrap around.*/
        if(pLRegress->m_a < 0) {
			LRegress_Reset(pLRegress);
        }

		/*Slope too big*/
        if(abs64(pLRegress->m_a - MULTIPLE_PRECISION) > SLOPE_PRECISION){
            tmp_y = 0;
            dmx_mask_print(DEMUX_LR_DEBUG|DEMUX_NOTICE_PRINT,"LRegress-> abnomal ma \n");
        }
        else {
			tmp_y = div64_s64((pLRegress->m_a * (x - pLRegress->m_BasePair.x) + pLRegress->m_b) , MULTIPLE_PRECISION );
			tmp_y += pLRegress->m_BasePair.y;
        }
    }

    return tmp_y;
}




void LRegress_dumpDatabase(DEMUX_LINEARREGRESSION_T *pLRegress, const char * caller, const int callLine)
{
    int index = 0;
    dmx_mask_print(DEMUX_LR_DEBUG|DEMUX_NOTICE_PRINT,"LRegress ->LRegress_dumpDatabase callerInfomation:%s %d\n", caller, callLine);
    dmx_mask_print(DEMUX_LR_DEBUG|DEMUX_NOTICE_PRINT,"LRegress ->ma:%lld, mb:%lld, size:%lld, base:(%lld,%lld)\n", pLRegress->m_a, pLRegress->m_b, pLRegress->m_pairNum, pLRegress->m_BasePair.x, pLRegress->m_BasePair.y);
    for (index = pLRegress->m_pairIdx - pLRegress->m_pairNum; index<pLRegress->m_pairIdx; index++)
    {
        int pindex = (index+LINEAR_REGRESSION_SAMPLE_NUM)%LINEAR_REGRESSION_SAMPLE_NUM;
        dmx_mask_print(DEMUX_LR_DEBUG|DEMUX_NOTICE_PRINT,"LRegress-> (%lld, %lld)\n", pLRegress->m_dataPair[pindex].x, pLRegress->m_dataPair[pindex].y)
    }
}