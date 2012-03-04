/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 * @see EFM32TG_EMU
 */

/** Definitions for the EMU subsystem (Energy Management Unit).
 *
 * This corresponds to the description in d0034_efm32tg_reference_manual.pdf
 * section 10.
 *
 * @ingroup EFM32TG
 * @defgroup EFM32TG_EMU EMU (Energy Management Unit)
 * @{
 */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_EMU_H
#define LIBOPENCM3_EFM32_TINYGECKO_EMU_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>

/** Register definitions and register value definitions for the EMU subsystem
 *
 * @defgroup EFM32TG_EMU_regsandvals EMU registers and values
 * @{
 */

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 10.4
 *
 * @defgroup EFM32TG_EMU_registers EMU registers
 * @{
 */

#define EMU_CTRL                MMIO32(EMU_BASE + 0x000) /**< @see EFM32TG_EMU_CTRL_bits */
#define EMU_LOCK                MMIO32(EMU_BASE + 0x008) /**< @see EFM32TG_EMU_LOCK_values */
#define EMU_AUXCTRL             MMIO32(EMU_BASE + 0x024) /**< @see EFM32TG_EMU_AUXCTRL_bits */

/** @} */

/** Bit states for the EMU_CTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 10.5.1 for definitions, and
 * 10.3.2 for details (especially on why EM4CTRL_TWO and _THREE are defined).
 *
 * @defgroup EFM32TG_EMU_CTRL_bits EMU CTRL bits
 * @{
 */

#define EMU_CTRL_EM4CTRL_TWO    (2<<2)
#define EMU_CTRL_EM4CTRL_THREE  (3<<2)
#define EMU_CTRL_EM4CTRL_MASK   (0x3<<2)
#define EMU_CTRL_EM2BLOCK       (1<<1) /**< When this bit is set, no mode lower than EM1 will be entered */
#define EMU_CTRL_EMVREG         (1<<0) /**< When this bit is set, the voltage regulator will stay on in modes lower than EM1 */

/** @} */

/** Values for the EMU_LOCK register
 *
 * See d0034_efm32tg_reference_manual.pdf section 10.5.2 for definitions. There
 * seems not to be another mention of it.
 *
 * @defgroup EFM32TG_EMU_LOCK_values EMU LOCK values
 * @{
 */

#define EMU_LOCK_IS_UNLOCKED    0 /**< When the LOCK register reads as this value, it is open */
#define EMU_LOCK_IS_LOCKED      1 /**< When the LOCK register reads as this value, it is locked */
#define EMU_LOCK_SET_LOCKED     0 /**< Write this to the LOCK register to lock the EMU */
#define EMU_LOCK_SET_UNLOCKED   0xade8 /**< Write this to the LOCK register to unlock the EMU */

/** @} */

/** Bit states for the EMU_AUXCTRL register
 *
 * See d0034_efm32tg_reference_manual.pdf section 10.5.3 for definitions, and
 * 9.5.3 for details.
 *
 * @defgroup EFM32TG_EMU_AUXCTRL_bits EMU AUXCTRL bits
 * @{
 */

#define EMU_AUXCTRL_HRCCLR      (1<<0)

/** @} */

/** @} */

/** EMU convenience functions
 *
 * These functions can be used to send the chip to low energy modes.
 *
 * @todo Implement other sleep modes than EM1. Implement WFI vs WFE waits.
 *
 * @defgroup EFM32TG_EMU_convenience EMU convenience functions
 * @{
 */

/** Put the system into EM1 low energy mode. */
static void emu_sleep_em1(void)
{
	/* FIXME: set SLEEPDEEP to 0 */
	__asm__("wfi");
}

/** @} */

/** @} */

#endif
