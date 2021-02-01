/**
 * @file hal_dm.h
 * @brief This file is the header for DM controller.
 * @date September.12.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _HAL_DM_HEADER_INCLUDE_
#define _HAL_DM_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function get kmc 00 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress0(VOID);

/**
 * @brief This function get kmc 00 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress1(VOID);

/**
 * @brief This function get kmc 00 start address 2
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress2(VOID);

/**
 * @brief This function get kmc 00 start address 3
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress3(VOID);

/**
 * @brief This function get kmc 00 start address 4
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress4(VOID);

/**
 * @brief This function get kmc 00 start address 5
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress5(VOID);

/**
 * @brief This function get kmc 00 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00LineOffsetAddress(VOID);

/**
 * @brief This function set kmc 00 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress2(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress3(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress4(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress5(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress6(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress7(UINT32 u32Address);

/**
 * @brief This function get kmc 01 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress0(VOID);

/**
 * @brief This function get kmc 01 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress1(VOID);
/**
 * @brief This function get kmc 00 start address 2
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress2(VOID);

/**
 * @brief This function get kmc 00 start address 3
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress3(VOID);
/**
 * @brief This function get kmc 00 start address 4
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress4(VOID);

/**
 * @brief This function get kmc 00 start address 5
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress5(VOID);

/**
 * @brief This function get kmc 00 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01LineOffsetAddress(VOID);

/**
 * @brief This function set kmc 00 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress2(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress3(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress4(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress5(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress6(UINT32 u32Address);

/**
 * @brief This function set kmc 00 end address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress7(UINT32 u32Address);

/**
 * @brief This function set kmc vtotal
 * @param [in] UINT32 u32Vtotal
 * @retval VOID
*/
VOID HAL_DM_SetKmcVtotal(UINT32 u32Vtotal);

/**
 * @brief This function set kmc input 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmcInput3DEnable(BOOL bEnable);

/**
 * @brief This function set kmc input 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmcInput3DMode(UINT32 u32Mode);

/**
 * @brief This function set kmc output 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmcOutput3DEnable(BOOL bEnable);

/**
 * @brief This function set kmc output 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmcOutput3DMode(UINT32 u32Mode);

/**
 * @brief This function set kmc 422 enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc422Enable(BOOL bEnable);

/**
 * @brief This function set kmc vflip enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmcVflipEnable(BOOL bEnable);

/**
 * @brief This function set dm pr mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetPRMode(UINT32 u32Mode);

/**
 * @brief This function set kmc 00 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc00WriteEnable(BOOL bEnable);

/**
 * @brief This function set kmc 01 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc01WriteEnable(BOOL bEnable);

/**
 * @brief This function set kmc 04 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc04ReadEnable(BOOL bEnable);

/**
 * @brief This function set kmc 05 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc05ReadEnable(BOOL bEnable);

/**
 * @brief This function set kmc 06 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc06ReadEnable(BOOL bEnable);

/**
 * @brief This function set kmc 07 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc07ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 08 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme08WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 09 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme09ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 10 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme10WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 11 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme11ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 12 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme12WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 13 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme13ReadEnable(BOOL bEnable);
/**
 * @brief This function set kme 14 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme14WriteEnable(BOOL bEnable);
/**
 * @brief This function set kme 15 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme15ReadEnable(BOOL bEnable);
/**
 * @brief This function get kme 00 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress0(VOID);

/**
 * @brief This function get kme 00 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress1(VOID);

/**
 * @brief This function get kme 00 start address 2
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress2(VOID);

/**
 * @brief This function get kme 00 start address 3
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress3(VOID);

/**
 * @brief This function get kme 00 start address 4
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress4(VOID);

/**
 * @brief This function get kme 00 start address 5
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress5(VOID);

/**
 * @brief This function get kme 00 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00LineOffsetAddress(VOID);

/**
 * @brief This function set kme 00 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 00 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 00 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress2(UINT32 u32Address);

/**
 * @brief This function set kme 00 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress3(UINT32 u32Address);

/**
 * @brief This function set kme 00 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress4(UINT32 u32Address);

/**
 * @brief This function set kme 00 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress5(UINT32 u32Address);

/**
 * @brief This function set kmc 00 lr offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmc 00 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress2(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress3(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress4(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress5(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress6(UINT32 u32Address);

/**
 * @brief This function set kmc 00 start address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress7(UINT32 u32Address);

/**
 * @brief This function set kmc 01 lr offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmc 01 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress2(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress3(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress4(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress5(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress6(UINT32 u32Address);

/**
 * @brief This function set kmc 01 start address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress7(UINT32 u32Address);

/**
 * @brief This function get kme 12 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme12StartAddress0(VOID);

/**
 * @brief This function get kme 12 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme12StartAddress1(VOID);

/**
 * @brief This function get kme 12 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme12LineOffsetAddress(VOID);

/**
 * @brief This function set kme 12 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 12 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 00 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme00WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 01 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme01ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 02 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme02ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 03 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme03ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 04 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme04WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 05 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme05WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 06 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme06ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 07 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme07ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme input 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeInput3DEnable(BOOL bEnable);

/**
 * @brief This function set kme input 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmeInput3DMode(UINT32 u32Mode);

/**
 * @brief This function set kme output 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeOutput3DEnable(BOOL bEnable);

/**
 * @brief This function set kme output 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmeOutput3DMode(UINT32 u32Mode);

/**
 * @brief This function set kme ME H/V active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmeMEActive(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kme MV H/V active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmeMVActive(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kme me hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmeMEHNum(UINT32 u32Hnum);

/**
 * @brief This function set kme mv hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmeMVHNum(UINT32 u32Hnum);

/**
 * @brief This function set kme ppi hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmePPIHNum(UINT32 u32Hnum);

/**
 * @brief This function set kme vflip enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeVflipEnable(BOOL bEnable);

/**
 * @brief This function set kme logo vflip enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeLogoVflipEnable(BOOL bEnable);

/**
 * @brief This function set kme 00 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress0(UINT32 u32Address);
/**
 * @brief This function set kme 00 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 00 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress2(UINT32 u32Address);

/**
 * @brief This function set kme 00 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress3(UINT32 u32Address);

/**
 * @brief This function set kme 00 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress4(UINT32 u32Address);

/**
 * @brief This function set kme 00 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress5(UINT32 u32Address);

/**
 * @brief This function set kme 04 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme04StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 04 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme04StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 05 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme05StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 05 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme05StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 08 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme08StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 08 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme08StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 10 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme10StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 10 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme10StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 12 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 12 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kme 14 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme14StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kme 14 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme14StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 01 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 02 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 04 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 04 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 04 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04StartAddress2(UINT32 u32Address);

/**
 * @brief This function set kmv 05 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 05 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress2(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress3(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress4(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress5(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress6(UINT32 u32Address);

/**
 * @brief This function set kmv 12 start address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress7(UINT32 u32Address);

/**
 * @brief This function set kmv 01 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 02 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 04 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 04 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 04 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04EndAddress2(UINT32 u32Address);

/**
 * @brief This function set kmv 05 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 05 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress0(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress1(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress2(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress3(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress4(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress5(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress6(UINT32 u32Address);

/**
 * @brief This function set kmv 12 end address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress7(UINT32 u32Address);

/**
 * @brief This function set kmv 01 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01LineOffsetAddress(UINT32 u32Address);
/**
 * @brief This function set kmv 01 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 02 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 02 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 04 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 04 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 05 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 05 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05LROffsetAddress(UINT32 u32Address);
/**
 * @brief This function set kmv 12 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kmv 12 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kme 01 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv01WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 02 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv02WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 04 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv04WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 05 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv05WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 12 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv12WriteEnable(BOOL bEnable);

/**
 * @brief This function set kme 03 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv03ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 06 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv06ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 07 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv07ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 08 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv08ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 09 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv09ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 10 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv10ReadEnable(BOOL bEnable);

/**
 * @brief This function set kme 11 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv11ReadEnable(BOOL bEnable);

/**
 * @brief This function set kmv 01 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv01Hnum(UINT32 u32Hnum);

/**
 * @brief This function set kmv 02 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv02Hnum(UINT32 u32Hnum);

/**
 * @brief This function set kmv 04 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv04Hnum(UINT32 u32Hnum);

/**
 * @brief This function set kmv 05 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv05Hnum(UINT32 u32Hnum);

/**
 * @brief This function set kmv 12 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv12Hnum(UINT32 u32Hnum);

/**
 * @brief This function set kmv 01 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv01Active(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kmv 02 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv02Active(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kmv 04 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv04Active(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kmv 05 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv05Active(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kmv 12 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv12Active(UINT32 u32Hactive, UINT32 u32Vactive);

/**
 * @brief This function set kmv input 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmvInput3DEnable(BOOL bEnable);

/**
 * @brief This function set kmv output 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmvOutput3DEnable(BOOL bEnable);

/**
 * @brief This function set kmv me1 output 3d mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmvME1Output3DMode(UINT32 u32Mode);

/**
 * @brief This function set kmv me2 output 3d mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmvME2Output3DMode(UINT32 u32Mode);

/**
 * @brief This function set kme 00 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00LROffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kme 00 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kme 08 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme08LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kme 10 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme10LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kme 12 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12LineOffsetAddress(UINT32 u32Address);

/**
 * @brief This function set kme 14 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme14LineOffsetAddress(UINT32 u32Address);

#endif

