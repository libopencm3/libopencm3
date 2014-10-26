/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32F1xx_defines
 *
 * @brief Defined Constants and Types for the STM32F1xx FLASH Memory
 *
 * @version 1.0.0
 *
 * @date 14 January 2014
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * For details see:
 * PM0075 programming manual: STM32F10xxx Flash programming
 * August 2010, Doc ID 17863 Rev 1
 * https://github.com/libopencm3/libopencm3-archive/blob/master/st_micro/CD00283419.pdf
 */

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

/**@{*/

#include <libopencm3/stm32/common/flash_common_f01.h>

/* --- FLASH_OPTION bytes ------------------------------------------------- */

/** @defgroup flash_options Option Byte Addresses
@ingroup flash_defines
@{*/
#define FLASH_OPTION_BYTE_0             FLASH_OPTION_BYTE(0)
#define FLASH_OPTION_BYTE_1             FLASH_OPTION_BYTE(1)
#define FLASH_OPTION_BYTE_2             FLASH_OPTION_BYTE(2)
#define FLASH_OPTION_BYTE_3             FLASH_OPTION_BYTE(3)
#define FLASH_OPTION_BYTE_4             FLASH_OPTION_BYTE(4)
#define FLASH_OPTION_BYTE_5             FLASH_OPTION_BYTE(5)
#define FLASH_OPTION_BYTE_6             FLASH_OPTION_BYTE(6)
#define FLASH_OPTION_BYTE_7             FLASH_OPTION_BYTE(7)
/**@}*/

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- FLASH_ACR values ---------------------------------------------------- */

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY_0WS		0x00
#define FLASH_ACR_LATENCY_1WS		0x01
#define FLASH_ACR_LATENCY_2WS		0x02
/**@}*/
#define FLASH_ACR_HLFCYA		(1 << 3)

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_EOP			(1 << 5)
#define FLASH_SR_WRPRTERR		(1 << 4)
#define FLASH_SR_PGERR			(1 << 2)
#define FLASH_SR_BSY			(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

/* --- FLASH_OBR values ---------------------------------------------------- */

/* FLASH_OBR[25:18]: Data1 */
/* FLASH_OBR[17:10]: Data0 */
#define FLASH_OBR_NRST_STDBY		(1 << 4)
#define FLASH_OBR_NRST_STOP		(1 << 3)
#define FLASH_OBR_WDG_SW		(1 << 2)
#define FLASH_OBR_RDPRT_EN		(1 << FLASH_OBR_RDPRT_SHIFT)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/* Read protection option byte protection enable key */
#define FLASH_RDP_KEY			((uint16_t)0x00a5)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_halfcycle_enable(void);
void flash_halfcycle_disable(void);
void flash_unlock_upper(void);
void flash_lock_upper(void);
void flash_clear_pgerr_flag_upper(void);
void flash_clear_eop_flag_upper(void);
void flash_clear_wrprterr_flag_upper(void);
void flash_clear_bsy_flag_upper(void);

END_DECLS

/**@}*/

#endif
