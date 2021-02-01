#ifndef RTKDEMUX_LINEARREGRESSION_H
#define RTKDEMUX_LINEARREGRESSION_H

#define LINEAR_REGRESSION_SAMPLE_NUM 200
#define GROUP_SAMPLE_NUM 100
#define SUM_GROUP_NUM (LINEAR_REGRESSION_SAMPLE_NUM/GROUP_SAMPLE_NUM)



typedef struct
{
    int64_t x;  /* stc */
    int64_t y;  /* pcr */
} LINEARPAIR;


typedef struct DEMUX_LINEARREGRESSION_T_ {
	int64_t m_a;  /*Slope*/
	int64_t m_b;  /*y-intercept, is a point where the graph of a function or relation intersects with the y-axis of the coordinate system. */

	int64_t m_pairNum;
	int m_pairIdx;

	LINEARPAIR m_dataPair[LINEAR_REGRESSION_SAMPLE_NUM];
	LINEARPAIR m_BasePair;
	LINEARPAIR m_restoredPair;

} DEMUX_LINEARREGRESSION_T;


void LRegress_Reset(DEMUX_LINEARREGRESSION_T *pLRegress );
int LRegress_InsertDataPair(DEMUX_LINEARREGRESSION_T *pLRegress , LINEARPAIR pair);
int64_t LRegress_GetPredictY(DEMUX_LINEARREGRESSION_T *pLRegress , int64_t x);

void LRegress_dumpDatabase(DEMUX_LINEARREGRESSION_T *pLRegress, const char * caller, const int callLine);




#endif /*RTKDEMUX_LINEARREGRESSION_H*/

