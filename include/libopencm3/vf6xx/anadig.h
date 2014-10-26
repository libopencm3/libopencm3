/** @defgroup anadig_defines ANADIG Defines
 *
 * @brief <b>Defined Constants and Types for the VF6xx Analog components
 * control digital interface</b>
 *
 * @ingroup VF6xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Stefan Agner <stefan@agner.ch>
 *
 * @date 01 July 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#ifndef LIBOPENCM3_ANADIG_H
#define LIBOPENCM3_ANADIG_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/vf6xx/memorymap.h>

/* --- ANADIG registers ---------------------------------------------------- */

#define ANADIG_PLL3_CTRL		MMIO32(ANADIG_BASE + 0x010)
#define ANADIG_PLL7_CTRL		MMIO32(ANADIG_BASE + 0x020)
#define ANADIG_PLL2_CTRL		MMIO32(ANADIG_BASE + 0x030)
#define ANADIG_PLL2_SS			MMIO32(ANADIG_BASE + 0x040)
#define ANADIG_PLL2_NUM			MMIO32(ANADIG_BASE + 0x050)
#define ANADIG_PLL2_DENOM		MMIO32(ANADIG_BASE + 0x060)
#define ANADIG_PLL4_CTRL		MMIO32(ANADIG_BASE + 0x070)
#define ANADIG_PLL4_NUM			MMIO32(ANADIG_BASE + 0x080)
#define ANADIG_PLL4_DENOM		MMIO32(ANADIG_BASE + 0x090)
#define ANADIG_PLL6_CTRL		MMIO32(ANADIG_BASE + 0x0A0)
#define ANADIG_PLL6_NUM			MMIO32(ANADIG_BASE + 0x0B0)
#define ANADIG_PLL6_DENOM		MMIO32(ANADIG_BASE + 0x0C0)
#define ANADIG_PLL5_CTRL		MMIO32(ANADIG_BASE + 0x0E0)
#define ANADIG_PLL3_PFD			MMIO32(ANADIG_BASE + 0x0F0)
#define ANADIG_PLL2_PFD			MMIO32(ANADIG_BASE + 0x100)
#define ANADIG_REG_1P1			MMIO32(ANADIG_BASE + 0x110)
#define ANADIG_REG_3P0			MMIO32(ANADIG_BASE + 0x120)
#define ANADIG_REG_2P5			MMIO32(ANADIG_BASE + 0x130)
#define ANADIG_ANA_MISC0		MMIO32(ANADIG_BASE + 0x150)
#define ANADIG_ANA_MISC1		MMIO32(ANADIG_BASE + 0x160)
#define ANADIG_ANADIG_DIGPROG		MMIO32(ANADIG_BASE + 0x260)
#define ANADIG_PLL1_CTRL		MMIO32(ANADIG_BASE + 0x270)
#define ANADIG_PLL1_SS			MMIO32(ANADIG_BASE + 0x280)
#define ANADIG_PLL1_NUM			MMIO32(ANADIG_BASE + 0x290)
#define ANADIG_PLL1_DENOM		MMIO32(ANADIG_BASE + 0x2A0)
#define ANADIG_PLL1_PFD			MMIO32(ANADIG_BASE + 0x2B0)
#define ANADIG_PLL_LOCK			MMIO32(ANADIG_BASE + 0x2C0)

/* --- ANADIG values -....-------------------------------------------------- */

/* ANADIG_PLL3_CTRL: PLL3 Control Register (480MHz PLL of USB0) */
#define ANADIG_PLL3_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL3_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL3_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL3_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL3_CTRL_POWER			(1 << 12)
#define ANADIG_PLL3_CTRL_EN_USB_CLKS		(1 << 6)
#define ANADIG_PLL3_CTRL_DIV_SELECT		(1 << 1)

/* ANADIG_PLL7_CTRL: PLL7 Control Register (480MHz PLL of USB1) */
#define ANADIG_PLL7_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL7_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL7_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL7_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL7_CTRL_POWER			(1 << 12)
#define ANADIG_PLL7_CTRL_EN_USB_CLKS		(1 << 6)
#define ANADIG_PLL7_CTRL_DIV_SELECT		(1 << 1)

/* ANADIG_PLL2_CTRL: PLL2 Control Register (528MHz PLL) */
#define ANADIG_PLL2_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL2_CTRL_PFD_OFFSET_EN		(1 << 18)
#define ANADIG_PLL2_CTRL_DITHER_ENABLE		(1 << 17)
#define ANADIG_PLL2_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL2_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL2_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL2_CTRL_POWERDOWN		(1 << 12)
#define ANADIG_PLL2_CTRL_DIV_SELECT		(1 << 1)

/* ANADIG_PLL2_SS: PLL2 Spread Spectrum definition register */
#define ANADIG_PLL2_SS_STOP_MASK		(0xffff << 16)
#define ANADIG_PLL2_SS_ENABLE			(1 << 15)
#define ANADIG_PLL2_SS_STEP_MASK		0x8fff

/* ANADIG_PLL2_NUM: PLL2 Numerator definition register */
#define ANADIG_PLL2_NUM_MFN_MASK		0x3fffffff

/* ANADIG_PLL2_DENOM: PLL2 Denominator definition register */
#define ANADIG_PLL2_DENOM_MFN_MASK		0x3fffffff

/* ANADIG_PLL4_CTRL: PLL4 Control Register (audio PLL) */
#define ANADIG_PLL4_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL4_CTRL_PFD_OFFSET_EN		(1 << 18)
#define ANADIG_PLL4_CTRL_DITHER_ENABLE		(1 << 17)
#define ANADIG_PLL4_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL4_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL4_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL4_CTRL_POWERDOWN		(1 << 12)
#define ANADIG_PLL4_CTRL_DIV_SELECT_MASK	(0x7f)

/* ANADIG_PLL4_NUM: PLL4 Numerator definition register */
#define ANADIG_PLL4_NUM_MFN_MASK		0x3fffffff

/* ANADIG_PLL4_DENOM: PLL4 Denominator definition register */
#define ANADIG_PLL4_DENOM_MFN_MASK		0x3fffffff

/* ANADIG_PLL6_CTRL: PLL6 Control Register (video PLL) */
#define ANADIG_PLL6_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL6_CTRL_PFD_OFFSET_EN		(1 << 18)
#define ANADIG_PLL6_CTRL_DITHER_ENABLE		(1 << 17)
#define ANADIG_PLL6_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL6_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL6_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL6_CTRL_POWERDOWN		(1 << 12)
#define ANADIG_PLL6_CTRL_DIV_SELECT_MASK	(0x7f)

/* ANADIG_PLL6_NUM: PLL6 Numerator definition register */
#define ANADIG_PLL6_NUM_MFN_MASK		0x3fffffff

/* ANADIG_PLL6_DENOM: PLL6 Denominator definition register */
#define ANADIG_PLL6_DENOM_MFN_MASK		0x3fffffff

/* ANADIG_PLL5_CTRL: PLL5 Control Register (video PLL) */
#define ANADIG_PLL5_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL5_CTRL_PFD_OFFSET_EN		(1 << 18)
#define ANADIG_PLL5_CTRL_DITHER_ENABLE		(1 << 17)
#define ANADIG_PLL5_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL5_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL5_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL5_CTRL_POWERDOWN		(1 << 12)
#define ANADIG_PLL5_CTRL_DIV_SELECT_MASK	(0x3)

/* ANADIG_PLL_PFD: PLL1/PLL2/PLL3 PFD Clocks */
#define ANADIG_PLL_PFD4_CLKGATE			(1 << 31)
#define ANADIG_PLL_PFD4_STABLE			(1 << 30)
#define ANADIG_PLL_PFD4_FRAC_SHIFT		24
#define ANADIG_PLL_PFD4_FRAC_MASK		(0x3f << 24)
#define ANADIG_PLL_PFD3_CLKGATE			(1 << 23)
#define ANADIG_PLL_PFD3_STABLE			(1 << 22)
#define ANADIG_PLL_PFD3_FRAC_SHIFT		16
#define ANADIG_PLL_PFD3_FRAC_MASK		(0x3f << 16)
#define ANADIG_PLL_PFD2_CLKGATE			(1 << 15)
#define ANADIG_PLL_PFD2_STABLE			(1 << 14)
#define ANADIG_PLL_PFD2_FRAC_SHIFT		8
#define ANADIG_PLL_PFD2_FRAC_MASK		(0x3f << 8)
#define ANADIG_PLL_PFD1_CLKGATE			(1 << 7)
#define ANADIG_PLL_PFD1_STABLE			(1 << 6)
#define ANADIG_PLL_PFD1_FRAC_SHIFT		0
#define ANADIG_PLL_PFD1_FRAC_MASK		(0x3f << 0)

/* AANADIG_ANA_MISC0: miscellaneous analog blocks */
#define ANADIG_ANA_MISC0_OSC_XTALOK_EN		(1 << 17)
#define ANADIG_ANA_MISC0_OSC_XTALOK		(1 << 16)
#define ANADIG_ANA_MISC0_CLK_24M_IRC_XTAL_SEL	(1 << 13)
#define ANADIG_ANA_MISC0_STOP_MODE_CONFIG	(1 << 12)
#define ANADIG_ANA_MISC0_REFTOP_VBGUP		(1 << 7)
#define ANADIG_ANA_MISC0_REFTOP_SELBIASOFF	(1 << 3)
#define ANADIG_ANA_MISC0_REFTOP_LOWPOWER	(1 << 2)
#define ANADIG_ANA_MISC0_REFTOP_PWDVBGUP	(1 << 1)
#define ANADIG_ANA_MISC0_REFTOP_PWD		(1 << 0)

/* AANADIG_ANA_MISC0: miscellaneous analog blocks */
#define ANADIG_ANA_MISC1_IRQ_ANA_BO		(1 << 30)
#define ANADIG_ANA_MISC1_IRQ_TEMPSENSE		(1 << 29)
#define ANADIG_ANA_MISC1_LVDSCLK1_IBEN		(1 << 12)
#define ANADIG_ANA_MISC1_LVDSCLK1_OBEN		(1 << 10)

/* AANADIG_ANA_DIGPROG: Digital Program register */
#define ANADIG_ANADIG_DIGPROG_MAJOR_MASK	(0xffff << 8)
#define ANADIG_ANADIG_DIGPROG_MINOR_MASK	(0xff << 0)

/* ANADIG_PLL1_CTRL: PLL1 Control Register (video PLL) */
#define ANADIG_PLL1_CTRL_LOCK			(1 << 31)
#define ANADIG_PLL1_CTRL_PFD_OFFSET_EN		(1 << 18)
#define ANADIG_PLL1_CTRL_DITHER_ENABLE		(1 << 17)
#define ANADIG_PLL1_CTRL_BYPASS			(1 << 16)
#define ANADIG_PLL1_CTRL_BYPASS_CLK_SRC		(1 << 14)
#define ANADIG_PLL1_CTRL_ENABLE			(1 << 13)
#define ANADIG_PLL1_CTRL_POWERDOWN		(1 << 12)
#define ANADIG_PLL1_CTRL_DIV_SELECT		(1 << 1)

/* ANADIG_PLL1_SS: PLL1 Spread Spectrum definition register */
#define ANADIG_PLL1_SS_STOP_MASK		(0xffff << 16)
#define ANADIG_PLL1_SS_ENABLE			(1 << 15)
#define ANADIG_PLL1_SS_STEP_MASK		0x8fff

/* ANADIG_PLL1_NUM: PLL1 Numerator definition register */
#define ANADIG_PLL1_NUM_MFN_MASK		0x3fffffff

/* ANADIG_PLL1_DENOM: PLL1 Denominator definition register */
#define ANADIG_PLL1_DENOM_MFN_MASK		0x3fffffff

/* ANADIG_PLL_LOCK: PLL Lock Register */
#define ANADIG_PLL_LOCK_PLL1			(1 << 6)
#define ANADIG_PLL_LOCK_PLL2			(1 << 5)
#define ANADIG_PLL_LOCK_PLL4			(1 << 4)
#define ANADIG_PLL_LOCK_PLL6			(1 << 3)
#define ANADIG_PLL_LOCK_PLL5			(1 << 2)
#define ANADIG_PLL_LOCK_PLL3			(1 << 1)
#define ANADIG_PLL_LOCK_PLL7			(1 << 0)

#endif
