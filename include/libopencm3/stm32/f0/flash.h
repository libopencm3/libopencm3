/** @defgroup flash_defines FLASH Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Flash memory</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
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

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/


/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_KEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
#define FLASH_CR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
#define FLASH_AR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_OBR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1C)
#define FLASH_WRPR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_ACR_PRFTBS		(1 << 5)
#define FLASH_ACR_PRFTBE		(1 << 4)
#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY		7
#define FLASH_ACR_LATENCY_000_024MHZ	0
#define FLASH_ACR_LATENCY_024_048MHZ	1
#define FLASH_ACR_LATENCY_0WS		0
#define FLASH_ACR_LATENCY_1WS		1


/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_EOP			(1 << 5)
#define FLASH_SR_WRPRTERR		(1 << 4)
#define FLASH_SR_PGERR			(1 << 2)
#define FLASH_SR_BSY			(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_OBL_LAUNCH		(1 << 13)
#define FLASH_CR_EOPIE			(1 << 12)
#define FLASH_CR_ERRIE			(1 << 10)
#define FLASH_CR_OPTWRE			(1 << 9)
#define FLASH_CR_LOCK			(1 << 7)
#define FLASH_CR_STRT			(1 << 6)
#define FLASH_CR_OPTER			(1 << 5)
#define FLASH_CR_OPTPG			(1 << 4)
#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_PER			(1 << 1)
#define FLASH_CR_PG			(1 << 0)

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
#define FLASH_OBR_RDPRT_SHIFT		1
#define FLASH_OBR_RDPRT			(3 << FLASH_OBR_RDPRT_SHIFT)
#define FLASH_OBR_RDPRT_L0		(0 << FLASH_OBR_RDPRT_SHIFT)
#define FLASH_OBR_RDPRT_L1		(1 << FLASH_OBR_RDPRT_SHIFT)
#define FLASH_OBR_RDPRT_L2		(2 << FLASH_OBR_RDPRT_SHIFT)

#define FLASH_OBR_OPTERR		(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

#define FLASH_RDP_L0			((uint8_t)0xaa)
#define FLASH_RDP_L1			((uint8_t)0xf0) /* any value */
#define FLASH_RDP_L2			((uint8_t)0xcc)
#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void flash_prefetch_buffer_enable(void);
void flash_prefetch_buffer_disable(void);
void flash_set_ws(uint32_t ws);
void flash_wait_busy(void);
void flash_program_u32(uint32_t address, uint32_t data);
void flash_program_u16(uint32_t address, uint16_t data);
void flash_erase_page(uint32_t page_address);
void flash_erase_all_pages(void);

END_DECLS

#endif
