/**
* @file rbusIFD49Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IFD49_REG_H_
#define _RBUS_IFD49_REG_H_

#include "rbus_types.h"



//  IFD49 Register Address
#define  IFD49_FIFO_CRC49_result                                                 0x18032558
#define  IFD49_FIFO_CRC49_result_reg_addr                                        "0xB8032558"
#define  IFD49_FIFO_CRC49_result_reg                                             0xB8032558
#define  IFD49_FIFO_CRC49_result_inst_addr                                       "0x0000"
#define  set_IFD49_FIFO_CRC49_result_reg(data)                                   (*((volatile unsigned int*)IFD49_FIFO_CRC49_result_reg)=data)
#define  get_IFD49_FIFO_CRC49_result_reg                                         (*((volatile unsigned int*)IFD49_FIFO_CRC49_result_reg))
#define  IFD49_FIFO_CRC49_result_fifo_crc49_result_shift                         (0)
#define  IFD49_FIFO_CRC49_result_fifo_crc49_result_mask                          (0x0000FFFF)
#define  IFD49_FIFO_CRC49_result_fifo_crc49_result(data)                         (0x0000FFFF&(data))
#define  IFD49_FIFO_CRC49_result_get_fifo_crc49_result(data)                     (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IFD49 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  fifo_crc49_result:16;
    };
}ifd49_fifo_crc49_result_RBUS;

#else //apply LITTLE_ENDIAN

//======IFD49 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_crc49_result:16;
        RBus_UInt32  res1:16;
    };
}ifd49_fifo_crc49_result_RBUS;




#endif 


#endif 
