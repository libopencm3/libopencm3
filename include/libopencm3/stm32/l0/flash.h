/** @defgroup flash_defines FLASH Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L0xx Flash memory</b>
 *
 * @ingroup STM32L0xx_defines
 *
 * @version 1.0.0
 *
 * @date 19 November 2015
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/common/flash_common_f01.h>

// TODO: WEŹUPEWNIJSIEŻEJESTTOOK!
#define FLASH_PECR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_PEKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
/* Program/erase key register (FLASH_PEKEYR) */
#define FLASH_PEKEYR_PEKEY1		((uint32_t)0x89ABCDEF)
#define FLASH_PEKEYR_PEKEY2		((uint32_t)0x02030405)
/* --- FLASH_PECR values. Program/erase control register */
#define FLASH_PECR_OBL_LAUNCH		(1 << 18)
#define FLASH_PECR_ERRIE		(1 << 17)
#define FLASH_PECR_EOPIE		(1 << 16)
#define FLASH_PECR_PARALLBANK		(1 << 15)
#define FLASH_PECR_FPRG			(1 << 10)
#define FLASH_PECR_ERASE		(1 << 9)
#define FLASH_PECR_FTDW			(1 << 8)
#define FLASH_PECR_FTDW			(1 << 8)
#define FLASH_PECR_DATA			(1 << 4)
#define FLASH_PECR_PROG			(1 << 3)
#define FLASH_PECR_OPTLOCK		(1 << 2)
#define FLASH_PECR_PRGLOCK		(1 << 1)
#define FLASH_PECR_PELOCK		(1 << 0)


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

#define FLASH_OBR_RAM_PARITY_CHECK	(1 << 14)
#define FLASH_OBR_VDDA_MONITOR		(1 << 13)
#define FLASH_OBR_NBOOT1		(1 << 12)
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
