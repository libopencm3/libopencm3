/** @addtogroup flash_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 *
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
 * PM0081 Programming manual: STM32F40xxx and STM32F41xxx Flash programming
 * September 2011, Doc ID 018520 Rev 1
 * https://github.com/libopencm3/libopencm3-archive/blob/master/st_micro/DM00023388.pdf
 */

/** @cond */
#ifdef LIBOPENCM3_FLASH_H
/** @endcond */
#ifndef LIBOPENCM3_FLASH_COMMON_F234_H
#define LIBOPENCM3_FLASH_COMMON_F234_H
/**@{*/

/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_KEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
#define FLASH_CR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_ACR_LATENCY_MASK		0x07
#define FLASH_ACR_LATENCY_0WS		0x00
#define FLASH_ACR_LATENCY_1WS		0x01
#define FLASH_ACR_LATENCY_2WS		0x02
#define FLASH_ACR_LATENCY_3WS		0x03
#define FLASH_ACR_LATENCY_4WS		0x04
#define FLASH_ACR_LATENCY_5WS		0x05
#define FLASH_ACR_LATENCY_6WS		0x06
#define FLASH_ACR_LATENCY_7WS		0x07

/* --- FLASH_SR values ----------------------------------------------------- */

/* --- FLASH_CR values ----------------------------------------------------- */

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_set_ws(uint32_t ws);
void flash_unlock(void);
void flash_lock(void);
void flash_clear_pgperr_flag(void);
void flash_clear_eop_flag(void);
void flash_clear_bsy_flag(void);
void flash_clear_status_flags(void);
void flash_wait_for_last_operation(void);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "flash_common_f234.h should not be included direcitly,"
#warning "only via flash.h"
#endif
/** @endcond */
