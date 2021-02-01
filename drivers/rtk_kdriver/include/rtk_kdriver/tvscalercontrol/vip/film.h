#ifndef _FILM_H_
#define _FILM_H_

/*============================ Module dependency  ===========================*/
/*#include "rtd_types.h"*/
/*================================  definitions ===============================*/

typedef struct {
	unsigned char film_status;
} DRV_film_mode;

typedef struct {
	unsigned char film_fw_en;
	unsigned char film_sawtooth_choose;
	unsigned char film_LeaveQuick_en;
	unsigned char film_VerScrollingText_en;
	unsigned char film_thumbnail_en;
	unsigned char film_pair1_en;
	unsigned char film_pair2_en;
	unsigned char film_pair_en_auto;
	unsigned char film_violate_strict_en;
	unsigned char film_PairRatio_all1;
	unsigned char film_PairRatio_all2;
	unsigned char film_PairRatio_sub1;
	unsigned char film_PairRatio_sub2;
	unsigned char film_SawtoothThl;
	unsigned char film_FrMotionThl;
	unsigned char film_FieldMotionSumThl;
	unsigned char film_SubFieldMotionSumThl;
	unsigned char film_FrStaticSThl;
	unsigned char film_SubFrStaticsSTh1;
	unsigned char film_FiStaticSThl;
	unsigned char film_SubFiStaticsSTh1;
	unsigned char film_FiMinSThl;
	unsigned char film_SubFiMinSTh1;
	unsigned short film_FiMaxSThl;
	unsigned short film_SubFiMaxSTh1;
	unsigned char film_film32_debounce_fieldnum;
	unsigned char film_film22_debounce_fieldnum;
	unsigned char film_film22_SawtoothTh1;
	unsigned char film_film22_FiStaticSThl;
	unsigned char film_film22_FieldMotionSumThl;
	unsigned char film_film22_SubFieldMotionSumThl;
} DRV_film_table_t;

/*================================== Variables ==============================*/

/*================================== functions ==============================*/
void drvif_module_film_mode(DRV_film_mode *ptr);
void drvif_module_film_setting(DRV_film_table_t *ptr);
void drvif_module_32_pseudo_memc_select(unsigned char display, unsigned char mode, unsigned char weight);
void drvif_module_22_pseudo_memc_select(unsigned char display, unsigned char mode, unsigned char weight);



#endif /* _FILM_H_ */
