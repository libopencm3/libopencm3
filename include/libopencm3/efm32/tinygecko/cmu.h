/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *
 * Definitions for the CMU (Clock Management Unit).
 *
 * This corresponds to the description in d0034_efm32tg_reference_manual.pdf
 * section 11.
 *
 * @see CMU_registers
 */
/* FIXME: i'd prefer not to @see CMU_registers but have some direct link placed
 * automatically from a file to its groups */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_CMU_H
#define LIBOPENCM3_EFM32_TINYGECKO_CMU_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>

/** These definitions reflect d0034_efm32tg_reference_manual.pdf section 11.4.
 *
 * @defgroup CMU_registers CMU registers
 * @{ */

#define CMU_CTRL		MMIO32(CMU_BASE + 0x000)
#define CMU_HFCORECLKDIV	MMIO32(CMU_BASE + 0x004)
#define CMU_HFPERCLKDIV		MMIO32(CMU_BASE + 0x008)
#define CMU_HFRCOCTRL		MMIO32(CMU_BASE + 0x00C)
#define CMU_LFRCOCTRL		MMIO32(CMU_BASE + 0x010)
#define CMU_AUXHFRCOCTRL	MMIO32(CMU_BASE + 0x014)
#define CMU_CALCTRL		MMIO32(CMU_BASE + 0x018)
#define CMU_CALCNT		MMIO32(CMU_BASE + 0x01C)
#define CMU_OSCENCMD		MMIO32(CMU_BASE + 0x020)
#define CMU_CMD			MMIO32(CMU_BASE + 0x024)
#define CMU_LFCLKSEL		MMIO32(CMU_BASE + 0x028)
#define CMU_STATUS		MMIO32(CMU_BASE + 0x02C)
#define CMU_IF			MMIO32(CMU_BASE + 0x030)
#define CMU_IFS			MMIO32(CMU_BASE + 0x034)
#define CMU_IFC			MMIO32(CMU_BASE + 0x038)
#define CMU_IEN			MMIO32(CMU_BASE + 0x03C)
#define CMU_HFCORECLKEN0	MMIO32(CMU_BASE + 0x040)
#define CMU_HFPERCLKEN0		MMIO32(CMU_BASE + 0x044)
#define CMU_SYNCBUSY		MMIO32(CMU_BASE + 0x050)
#define CMU_FREEZE		MMIO32(CMU_BASE + 0x054)
#define CMU_LFACLKEN0		MMIO32(CMU_BASE + 0x058)
#define CMU_LFBCLKEN0		MMIO32(CMU_BASE + 0x060)
#define CMU_LFAPRESC0		MMIO32(CMU_BASE + 0x068)
#define CMU_LFBPRESC0		MMIO32(CMU_BASE + 0x070)
#define CMU_PCNTCTRL		MMIO32(CMU_BASE + 0x078)
#define CMU_LCDCTRL		MMIO32(CMU_BASE + 0x07C)
#define CMU_ROUTE		MMIO32(CMU_BASE + 0x080)
#define CMU_LOCK		MMIO32(CMU_BASE + 0x084)

/** @} */

/**
 * This section is incomplete because i'm impatient and want a working result
 * quickly
 *
 * @todo Include all bits and bit groups from the manual.
 */

#define CMU_HFPERCLKEN0_GPIO (1<<6)

#endif
