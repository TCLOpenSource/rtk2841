#ifndef _VD_REG_H_INCLUDED_
#define _VD_REG_H_INCLUDED_
#include "vd/VDPQ_fw.h"
#include "vd/VDTop_fw.h"


//Remove 
// reg_pal_malpha_lut  & reg_1d_blend_en in Magellan
#ifndef ADAP_BPF_Y_TH2_pal_malpha_lut
#define ADAP_BPF_Y_TH2_pal_malpha_lut(A)  (0)
#endif
#ifndef ALPHA_2D_MOD_ENABLE_blend_1d_enable
#define ALPHA_2D_MOD_ENABLE_blend_1d_enable(A) (0)
#endif

#endif
