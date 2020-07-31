/** @defgroup flash_defines FLASH Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Flash memory</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 14 January 2014
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H
/**@{*/

#include <libopencm3/stm32/common/flash_common_all.h>
#include <libopencm3/stm32/common/flash_common_f.h>
#include <libopencm3/stm32/common/flash_common_f01.h>

/* --- FLASH_OPTION values ------------------------------------------------- */

/** @defgroup flash_options Option Byte Addresses
@ingroup flash_defines
@{*/
#define FLASH_OPTION_BYTE_0             FLASH_OPTION_BYTE(0)
#define FLASH_OPTION_BYTE_1             FLASH_OPTION_BYTE(1)
#define FLASH_OPTION_BYTE_2             FLASH_OPTION_BYTE(2)
#define FLASH_OPTION_BYTE_3             FLASH_OPTION_BYTE(3)
#define FLASH_OPTION_BYTE_4             FLASH_OPTION_BYTE(4)
#define FLASH_OPTION_BYTE_5             FLASH_OPTION_BYTE(5)
/**@}*/

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- FLASH_ACR values ---------------------------------------------------- */

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY_000_024MHZ	0
#define FLASH_ACR_LATENCY_024_048MHZ	1
#define FLASH_ACR_LATENCY_0WS		0
#define FLASH_ACR_LATENCY_1WS		1
/**@}*/

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_EOP			(1 << 5)
#define FLASH_SR_WRPRTERR		(1 << 4)
#define FLASH_SR_PGERR			(1 << 2)
#define FLASH_SR_BSY			(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_OBL_LAUNCH		(1 << 13)

/* --- FLASH_OBR values ---------------------------------------------------- */

#define FLASH_OBR_DATA1_SHIFT		24
#define FLASH_OBR_DATA1			(0xFF << FLASH_OBR_DATA1_SHIFT)
#define FLASH_OBR_DATA0_SHIFT		16
#define FLASH_OBR_DATA0			(0xFF << FLASH_OBR_DATA0_SHIFT)

#define FLASH_OBR_BOOT_SEL		(1 << 15)
#define FLASH_OBR_RAM_PARITY_CHECK	(1 << 14)
#define FLASH_OBR_VDDA_MONITOR		(1 << 13)
#define FLASH_OBR_NBOOT1		(1 << 12)
#define FLASH_OBR_NBOOT0		(1 << 11)
#define FLASH_OBR_NRST_STDBY		(1 << 10)
#define FLASH_OBR_NRST_STOP		(1 << 9)
#define FLASH_OBR_WDG_SW		(1 << 8)
#define FLASH_OBR_RDPRT			(3 << FLASH_OBR_RDPRT_SHIFT)
#define FLASH_OBR_RDPRT_L0		(0 << FLASH_OBR_RDPRT_SHIFT)
#define FLASH_OBR_RDPRT_L1		(1 << FLASH_OBR_RDPRT_SHIFT)
#define FLASH_OBR_RDPRT_L2		(3 << FLASH_OBR_RDPRT_SHIFT)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/* Read protection option byte protection level setting */
#define FLASH_RDP_L0			((uint8_t)0xaa)
#define FLASH_RDP_L1			((uint8_t)0xf0) /* any value */
#define FLASH_RDP_L2			((uint8_t)0xcc)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS
/**@}*/

#endif
