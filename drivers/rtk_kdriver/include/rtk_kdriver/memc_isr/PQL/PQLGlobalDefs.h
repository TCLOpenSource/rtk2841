#ifndef _PQLGLOBALDEFS_H
#define _PQLGLOBALDEFS_H

//////////////////////////////////////////////////////////////////////////
#define _PHASE_FLBK_LVL_PRECISION    7
#define _PHASE_ME_NEAR_IP_PRECISION  4
/////////////////////////////////////////////////////////////////////////
typedef enum {
	_PQL_3D_FRAME_L = 0,
	_PQL_3D_FRAME_R,
}_PQL_3D_FRAME_TYPE;

//////////////////////////////////////////////////////////////////////////
#define _ABS_(x)   ((x)<0? (-1*(x)) : (x))
#define _MIN_(x,y) (((x)<=(y))? (x) : (y))
#define _MAX_(x,y) (((x)>=(y))? (x) : (y))

#define _MED3_(x, y, z)                       ((x)>(y)? ((y)>(z)? (y):((x)>(z)? (z):(x))):((x)>(z)? (x):((y)>(z)? (z):(y))))
#define _IDX_MAX3_(x, y, z)                   ((x)>(y)? ((x)>(z)? (0):(2)):((y)>(z)? (1):(2)))
#define _IDX_MIN3_(x, y, z)                   ((x)<(y)? ((x)<(z)? (0):(2)):((y)<(z)? (1):(2)))

#define _CLIP_(x,dmin, dmax)                  ((x)>(dmax)? (dmax):(x)<(dmin)?(dmin):(x))
#define _CLIP_UBOUND_(x,dmax)                  ((x)>(dmax)? (dmax):(x))

#define _ABS_DIFF_(x, y)                      ((x)<(y)? ((y)-(x)) : ((x)-(y)))
#define _2Val_RndBlending_(v0, v1, a0, p)     (((v0)*(a0)+(v1)*((1<<(p))-(a0)) + (1<<(p)>>1))>>(p))
#define _2Val_FlrBlending_(v0, v1, a0, p)     (((v0)*(a0)+(v1)*((1<<(p))-(a0))              )>>(p))

#define _IncreaseCurveMapping(v, th, min, max, slp, p) (_CLIP_((_MAX_((SINT32)(v) - (SINT32)(th), 0))*(slp)>>(p), (min), (max)))
#define _IncreaseCurveMapping2(v, th, max, slp, p) (_CLIP_UBOUND_((_MAX_((SINT32)(v) - (SINT32)(th), 0))*(slp)>>(p), (max)))

#define _DecreaseCurveMapping(v, th, min, max, slp, p) (_CLIP_(((max) - ((_MAX_((SINT32)(th) - (SINT32)(v), 0))*(slp)>>(p))), (min), (max)))

#define _AB_Threshold_Status(preS, cond_0to1, cond_1to0) (((preS) == 0 && ((cond_0to1) == 1))? 1 : \
                                                         (((preS) == 1 && ((cond_1to0) == 1))? 0 : (preS)))

//////////////////////////////////////////////////////////////////////////


#endif

