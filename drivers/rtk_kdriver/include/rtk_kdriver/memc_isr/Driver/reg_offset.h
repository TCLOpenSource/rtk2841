/**
 * @file reg_offset.h
 * @brief This header file defines register read/write api for other module to use.
 * @date August.29.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par Register Define V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifndef _REG_OFFSET_HEADER_
#define _REG_OFFSET_HEADER_

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT //#ifdef RTK_MEMC
#define BASE_OFFSET 0xB8099000
#else
#define BASE_OFFSET 0x00000000
#endif

#endif
