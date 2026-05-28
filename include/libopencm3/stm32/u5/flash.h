/** @defgroup flash_defines FLASH Defines
 * @brief <b>Defined Constants and Types for the STM32U5xx Flash
 * controller</b>
 * @ingroup STM32U5xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2025
 * Rachel Mant <git@dragonmux.network>
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define FLASH_FPEC1_BASE (FLASH_MEM_INTERFACE_BASE + 0x000U)

/** @defgroup flash_registers Flash Registers
 * @ingroup flash_defines
@{*/
/** Flash Access Control register */
#define FLASH_ACR MMIO32(FLASH_FPEC1_BASE + 0x000U)
/** Flash Non-secure Key register */
#define FLASH_NSKEYR MMIO32(FLASH_FPEC1_BASE + 0x008U)
/** Flash Secure Key register */
#define FLASH_SECKEYR MMIO32(FLASH_FPEC1_BASE + 0x00cU)
/** Flash Option bytes key register */
#define FLASH_OPTKEYR MMIO32(FLASH_FPEC1_BASE + 0x010U)
/** Flash Bank 1 power-down key register */
#define FLASH_PDKEY1R MMIO32(FLASH_FPEC1_BASE + 0x018U)
/** Flash Bank 2 power-down key register */
#define FLASH_PDKEY2R MMIO32(FLASH_FPEC1_BASE + 0x01cU)
/** Flash Non-secure Status register */
#define FLASH_NSSR MMIO32(FLASH_FPEC1_BASE + 0x020U)
/** Flash Secure Status register */
#define FLASH_SECSR MMIO32(FLASH_FPEC1_BASE + 0x024U)
/** Flash Non-secure Control register */
#define FLASH_NSCR MMIO32(FLASH_FPEC1_BASE + 0x28U)
/** Flash Secure Control register */
#define FLASH_SECCR MMIO32(FLASH_FPEC1_BASE + 0x2cU)
/** Flash ECC register */
#define FLASH_ECCR MMIO32(FLASH_FPEC1_BASE + 0x030U)
/** Flash Operation Status register */
#define FLASH_OPSR MMIO32(FLASH_FPEC1_BASE + 0x034U)
/** Flash Option register */
#define FLASH_OPTR MMIO32(FLASH_FPEC1_BASE + 0x040U)
/**@}*/

/* --- FLASH_ACR values ---------------------------------------------------- */

/** SLEEP_PD: Flash memory power-down during Sleep mode */
#define FLASH_ACR_SLEEP_PD (1U << 14U)
/** PDREQ1: Bank 1 power-down mode request */
#define FLASH_ACR_PDREQ1 (1U << 13U)
/** PDREQ2: Bank 2 power-down mode request */
#define FLASH_ACR_PDREQ2 (1U << 12U)
/** LPM: Low-power read mode */
#define FLASH_ACR_LPM (1U << 11U)
/** PRFTEN: Prefetch enable */
#define FLASH_ACR_PRFTEN (1U << 8U)

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY(w)   ((w) & FLASH_ACR_LATENCY_MASK)
#define FLASH_ACR_LATENCY_0WS  FLASH_ACR_LATENCY(0U)
#define FLASH_ACR_LATENCY_1WS  FLASH_ACR_LATENCY(1U)
#define FLASH_ACR_LATENCY_2WS  FLASH_ACR_LATENCY(2U)
#define FLASH_ACR_LATENCY_3WS  FLASH_ACR_LATENCY(3U)
#define FLASH_ACR_LATENCY_4WS  FLASH_ACR_LATENCY(4U)
#define FLASH_ACR_LATENCY_5WS  FLASH_ACR_LATENCY(5U)
#define FLASH_ACR_LATENCY_6WS  FLASH_ACR_LATENCY(6U)
#define FLASH_ACR_LATENCY_7WS  FLASH_ACR_LATENCY(7U)
#define FLASH_ACR_LATENCY_8WS  FLASH_ACR_LATENCY(8U)
#define FLASH_ACR_LATENCY_9WS  FLASH_ACR_LATENCY(9U)
#define FLASH_ACR_LATENCY_10WS FLASH_ACR_LATENCY(10U)
#define FLASH_ACR_LATENCY_11WS FLASH_ACR_LATENCY(11U)
#define FLASH_ACR_LATENCY_12WS FLASH_ACR_LATENCY(12U)
#define FLASH_ACR_LATENCY_13WS FLASH_ACR_LATENCY(13U)
#define FLASH_ACR_LATENCY_14WS FLASH_ACR_LATENCY(14U)
#define FLASH_ACR_LATENCY_15WS FLASH_ACR_LATENCY(15U)
/**@}*/
#define FLASH_ACR_LATENCY_SHIFT 0U
#define FLASH_ACR_LATENCY_MASK  0x0fU

/* --- FLASH_NSKEYR values ------------------------------------------------ */

#define FLASH_NSKEYR_KEY1 0x45670123U
#define FLASH_NSKEYR_KEY2 0xcdef89abU

/* --- FLASH_OPTKEYR values ------------------------------------------------ */

#define FLASH_OPTKEYR_KEY1 0x08192a3bU
#define FLASH_OPTKEYR_KEY2 0x4c5d6e7fU

/* --- FLASH_NSSR values --------------------------------------------------- */

#define FLASH_NSSR_PD1      (1U << 21U)
#define FLASH_NSSR_PD2      (1U << 20U)
#define FLASH_NSSR_OEM2LOCK (1U << 19U)
#define FLASH_NSSR_OEM1LOCK (1U << 18U)
#define FLASH_NSSR_WDW      (1U << 17U)
#define FLASH_NSSR_BSY      (1U << 16U)
#define FLASH_NSSR_OPTWERR  (1U << 13U)
#define FLASH_NSSR_PGSERR   (1U << 7U)
#define FLASH_NSSR_SIZERR   (1U << 6U)
#define FLASH_NSSR_PGAERR   (1U << 5U)
#define FLASH_NSSR_WRPERR   (1U << 4U)
#define FLASH_NSSR_PROGERR  (1U << 3U)
#define FLASH_NSSR_OPERR    (1U << 1U)
#define FLASH_NSSR_EOP      (1U << 0U)

#define FLASH_NSSR_ERROR_MASK                                                                             \
	(FLASH_NSSR_PGSERR | FLASH_NSSR_SIZERR | FLASH_NSSR_PGAERR | FLASH_NSSR_WRPERR | FLASH_NSSR_PROGERR | \
		FLASH_NSSR_OPERR)

/* --- FLASH_SECSR values -------------------------------------------------- */

/* --- FLASH_NSCR values --------------------------------------------------- */

#define FLASH_NSCR_LOCK      (1U << 31U)
#define FLASH_NSCR_OPTLOCK   (1U << 30U)
#define FLASH_NSCR_OPTSTRT   (1U << 17U)
#define FLASH_NSCR_STRT      (1U << 16U)
#define FLASH_NSCR_MER2      (1U << 15U)
#define FLASH_NSCR_BWR       (1U << 14U)
#define FLASH_NSCR_BKER      (1U << 11U)
#define FLASH_NSCR_PNB_SHIFT 3U
#define FLASH_NSCR_PNB_MASK  0xffU
#define FLASH_NSCR_PNB       (FLASH_NSCR_PNB_MASK << FLASH_NSCR_PNB_SHIFT)
#define FLASH_NSCR_MER1      (1U << 2U)
#define FLASH_NSCR_PER       (1U << 1U)
#define FLASH_NSCR_PG        (1U << 0U)

#define FLASH_NSCR_OP_MASK                                                                                  \
	(FLASH_NSCR_PG | FLASH_NSCR_PER | FLASH_NSCR_MER1 | FLASH_NSCR_PNB | FLASH_NSCR_BKER | FLASH_NSCR_BWR | \
		FLASH_NSCR_MER2)

/* --- Function prototypes ------------------------------------------------- */

typedef enum flash_bank {
	FLASH_BANK_1 = 1,
	FLASH_BANK_2,
} flash_bank_e;

BEGIN_DECLS

/** Enable prefetch for C-Bus accesses
 *
 * This buffer is used for instruction fetches and is not enabled by default.
 *
 * The prefetch buffer is designed to improve C-Bus (instruction and literal pool)
 * access performance and may only be enabled if at least 1 wait state is required
 * to access Flash - when the clock speeds are low enough to use 0WS, prefetch must
 * be disabled and makes no sense anyway.
 */
void flash_prefetch_enable(void);

/** Disable prefetch (for example, to improve power consumption in low power modes) */
void flash_prefetch_disable(void);

/** Set the Number of Wait States.
 *
 * Used to match the system clock to the Flash memory access time. See the
 * programming manual for more information on clock speed ranges. The latency must
 * be changed to the appropriate value <b>before</b> any increase in clock
 * speed, or <b>after</b> any decrease in clock speed.
 *
 * @param[in] ws values from @ref flash_latency.
 */
void flash_set_ws(uint32_t ws);

/** Lock the Flash Program and Erase Controller
 * Used to prevent spurious writes to Flash.
 */
void flash_lock(void);

/** Unlock the Flash Program and Erase Controller
 * This enables write access to the Flash memory. It is locked by default on reset.
 */
void flash_unlock(void);

/** Lock the Option Byte Access.
 * This disables write access to the option bytes. It is locked by default on reset.
 */
void flash_lock_option_bytes(void);

/** Unlock the Option Byte Access.
 * This enables write access to the option bytes. It is locked by default on reset.
 */
void flash_unlock_option_bytes(void);

/** Check if the FPEC is currently busy with an operation */
bool flash_is_busy(void);
/** Clear the End of OPeration flag. */
void flash_clear_eop_flag(void);

/** Wait until Last Operation has Ended.
 * This loops indefinitely until an operation (write or erase) has completed by
 * testing for EOP.
 *
 * Returns whether the operation was a success or not
 */
bool flash_wait_for_last_operation(void);

/** Erases a page of a bank of Flash.
 *
 * @param[in] bank one of the FLASH_BANK_* constants indicating which bank to erase
 * @param[in] sector the sector number in the bank to erase
 */
void flash_erase_page(flash_bank_e bank, uint8_t page);

/** Erases a whole bank of Flash.
 *
 * @param[in] bank one of the FLASH_BANK_* constants indicating which bank to erase
 */
void flash_erase_bank(flash_bank_e bank);

/** Program a block of data to Flash (forced) */
bool flash_program(uintptr_t address, const uint8_t *data, size_t len);

END_DECLS
/**@}*/

#endif
