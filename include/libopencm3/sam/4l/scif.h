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

#ifndef LIBOPENCM3_SCIF_H
#define LIBOPENCM3_SCIF_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* ------------ SCIF Registers ------------------------------ */

/* Interrupt Enable Register IER Write Only */
#define SCIF_IER			MMIO32(SCIF_BASE)

/* Interrupt Disable Register IDR Write Only */
#define SCIF_IDR			MMIO32(SCIF_BASE + 0x0004)

/* Interrupt Mask Register IMR Read Only */
#define SCIF_IMR			MMIO32(SCIF_BASE + 0x0008)

/* Interrupt Status Register ISR Read Only */
#define SCIF_ISR			MMIO32(SCIF_BASE + 0x000C)

/* Interrupt Clear Register ICR Write Only */
#define SCIF_ICR			MMIO32(SCIF_BASE + 0x0010)

/* Power and Clocks Status Register PCLKSR Read Only */
#define SCIF_PCLKSR			MMIO32(SCIF_BASE + 0x0014)

/* Unlock Register UNLOCK Write Only */
#define SCIF_UNLOCK			MMIO32(SCIF_BASE + 0x0018)
#define SCIF_UNLOCK_KEY		(0xaa << 24)

/* Chip Specific Configuration Register CSCR Read/Write */
#define SCIF_CSCR			MMIO32(SCIF_BASE + 0x001C)

/* Oscillator Control Register OSCCTRL0 Read/Write */
#define SCIF_OSCCTRL0			MMIO32(SCIF_BASE + 0x0020)
#define SCIF_OSCCTRL0_KEY		(SCIF_UNLOCK_KEY | 0x0020)

/* PLL0 Control Register PLL0 Read/Write */
#define SCIF_PLL0			MMIO32(SCIF_BASE + 0x0024)
#define SCIF_PLL0_KEY			(SCIF_UNLOCK_KEY | 0x0024)

/* DFLL0 Config Register DFLL0CONF Read/Write */
#define SCIF_DFLL0CONF			MMIO32(SCIF_BASE + 0x0028)

/* DFLL Value Register DFLL0VAL Read/Write */
#define SCIF_DFLL0VAL			MMIO32(SCIF_BASE + 0x002C)

/* DFLL0 Multiplier Register DFLL0MUL Read/Write */
#define SCIF_DFLL0MUL			MMIO32(SCIF_BASE + 0x0030)

/* DFLL0 Step Register DFLL0STEP Read/Write */
#define SCIF_DFLL0STEP			MMIO32(SCIF_BASE + 0x0034)

/* DFLL0 Spread Spectrum Generator Control Register DFLL0SSG Read/Write */
#define SCIF_DFLL0SSG			MMIO32(SCIF_BASE + 0x0038)

/* DFLL0 Ratio Register DFLL0RATIO Read Only */
#define SCIF_DFLL0RATIO			MMIO32(SCIF_BASE + 0x003C)

/* DFLL0 Synchronization Register DFLL0SYNC Write Only */
#define SCIF_DFLL0SYNC			MMIO32(SCIF_BASE + 0x0040)

/* System RC Oscillator Calibration Register RCCR Read/Write */
#define SCIF_RCCR			MMIO32(SCIF_BASE + 0x0044)

/* 4/8/12MHz RC Oscillator Configuration Register RCFASTCFG Read/Write */
#define SCIF_RCFASTCFG			MMIO32(SCIF_BASE + 0x0048)

/* 4/8/12MHz RC Oscillator Status Register RCFASTSR Read Only */
#define SCIF_RCFASTSR			MMIO32(SCIF_BASE + 0x004C)

/* 80MHz RC Oscillator Register RC80MCR Read/Write */
#define SCIF_RC80MCR			MMIO32(SCIF_BASE + 0x0050)

/* High Resolution Prescaler Control Register HRPCR Read/Write */
#define SCIF_HPPCR			MMIO32(SCIF_BASE + 0x0064)

/* Fractional Prescaler Control Register FPCR Read/Write */
#define SCIF_FPCR			MMIO32(SCIF_BASE + 0x0068)

/* Fractional Prescaler Multiplier Register FPMUL Read/Write */
#define SCIF_FPMUL			MMIO32(SCIF_BASE + 0x006C)

/* Fractional Prescaler DIVIDER Register FPDIV Read/Write */
#define SCIF_FPDIV			MMIO32(SCIF_BASE + 0x006C)

/* Generic Clock Control1 GCCTRL0 Read/Write */
#define SCIF_GCCTRL0			MMIO32(SCIF_BASE + 0x0074)

/* Generic Clock Control1 GCCTRL1 Read/Write */
#define SCIF_GCCTRL1			MMIO32(SCIF_BASE + 0x0078)

/* Generic Clock Control2 GCCTRL2 Read/Write */
#define SCIF_GCCTRL2			MMIO32(SCIF_BASE + 0x007C)

/* Generic Clock Control3 GCCTRL3 Read/Write */
#define SCIF_GCCTRL3			MMIO32(SCIF_BASE + 0x0080)

/* Generic Clock Control4 GCCTRL4 Read/Write */
#define SCIF_GCCTRL4			MMIO32(SCIF_BASE + 0x0084)

/* Generic Clock Control5 GCCTRL5 Read/Write */
#define SCIF_GCCTRL5			MMIO32(SCIF_BASE + 0x0088)

/* Generic Clock Control6 GCCTRL6 Read/Write */
#define SCIF_GCCTRL6			MMIO32(SCIF_BASE + 0x008C)

/* Generic Clock Control7 GCCTRL7 Read/Write */
#define SCIF_GCCTRL7			MMIO32(SCIF_BASE + 0x0090)

/* Generic Clock Control8 GCCTRL8 Read/Write */
#define SCIF_GCCTRL8			MMIO32(SCIF_BASE + 0x0094)

/* Generic Clock Control9 GCCTRL9 Read/Write */
#define SCIF_GCCTRL9			MMIO32(SCIF_BASE + 0x0098)

/* Generic Clock Control10 GCCTRL10 Read/Write */
#define SCIF_GCCTRL10			MMIO32(SCIF_BASE + 0x009C)

/* Generic Clock Control11 GCCTRL11 Read/Write */
#define SCIF_GCCTRL11			MMIO32(SCIF_BASE + 0x00A0)

#define SCIF_GCTRL(N)			MMIO32(SCIF_BASE + 0x0074 + 0x0004 * (N))
#define SCIF_GCLK_MAX_NUM			11

/* 4/8/12MHz RC Oscillator Version Register RCFASTVERSION Read-only */
#define SCIF_RCFASTVERSION			MMIO32(SCIF_BASE + 0x03D8)

/* Generic Clock Prescaler Version Register GCLKPRESCVERSION Read-only */
#define SCIF_GCLKPRESCVERSION			MMIO32(SCIF_BASE + 0x03DC)

/* PLL Version Register PLLIFAVERSION Read-only */
#define SCIF_PLLIFAVERSION			MMIO32(SCIF_BASE + 0x03E0)

/* Oscillator0 Version Register OSCIFAVERSION Read-only */
#define SCIF_OSCIFAVERSION			MMIO32(SCIF_BASE + 0x03E4)

/* DFLL Version Register DFLLIFBVERSION Read-only */
#define SCIF_DFLLIFBVERSION			MMIO32(SCIF_BASE + 0x03E8)

/* System RC Oscillator Version Register RCOSCIFAVERSION Read-only */
#define SCIF_RCOSCIFAVERSION			MMIO32(SCIF_BASE + 0x03EC)

/* 80MHz RC Oscillator Version Register RC80MVERSION Read-only */
#define SCIF_RC80MVERSION			MMIO32(SCIF_BASE + 0x03F4)

/* Generic Clock Version Register GCLKVERSION Read-only */
#define SCIF_GCLKVERSION			MMIO32(SCIF_BASE + 0x03F8)

/* SCIF Version Register VERSION Read-Only */
#define SCIF_VERSION			MMIO32(SCIF_BASE + 0x03FC)


/* ---------------- SCIF Registers' Contents ------------------- */

/* Interrupt Enable/Disable/Mask/Status/Clear registers and PCLKSR
 * have the same bit configuration */
#define SCIF_OSC0RDY			(1 << 0)
#define SCIF_DFLL0LOCKC			(1 << 1)
#define SCIF_DFLL0LOCKF			(1 << 2)
#define SCIF_DFLL0RDY			(1 << 3)
#define SCIF_DFLL0RCS			(1 << 4)
#define SCIF_PLL0LOCK			(1 << 6)
#define SCIF_PLL0LOCKLOST			(1 << 7)
#define SCIF_RCFASTLOCK			(1 << 13)
#define SCIF_RCFASTLOCKLOST			(1 << 14)

#define SCIF_OSCCTRL_MODE			(1 << 0)
#define SCIF_OSCCTRL_GAIN_SHIFT			1
#define SCIF_OSCCTRL_GAIN_MASK		(3 << SCIF_OSCCTRL_GAIN_SHIFT)
#define SCIF_OSCCTRL_AGC			(1 << 3)
#define SCIF_OSCCTRL_STARTUP_SHIFT			8
#define SCIF_OSCCTRL_STARTUP_MASK	(0xf << SCIF_OSCCTRL_STARTUP_SHIFT)
#define SCIF_OSCCTRL_OSCEN			(1 << 16)

#define _MASKED_VALUE(V, S, M)			(((V) << (S)) & (M))

#define SCIF_PLL0_PLLEN			(1 << 0)
#define SCIF_PLL0_PLLOSC_SHIFT			1
#define SCIF_PLL0_PLLOSC_MASK			(3 << SCIF_PLL0_PLLOSC_SHIFT)
#define SCIF_PLL0_PLLOSC_MASKED(V)			_MASKED_VALUE((V), SCIF_PLL0_PLLOSC_SHIFT, SCIF_PLL0_PLLOSC_MASK)

#define SCIF_PLL0_PLLOPT_SHIFT			3
#define SCIF_PLL0_PLLOPT_MASK			(7 << SCIF_PLL0_PLLOPT_SHIFT)
#define SCIF_PLL0_PLLOPT_MASKED(V)			_MASKED_VALUE((V), SCIF_PLL0_PLLOPT_SHIFT, SCIF_PLL0_PLLOPT_MASK)

#define SCIF_PLL0_PLLDIV_SHIFT			8
#define SCIF_PLL0_PLLDIV_MASK			(0xf << SCIF_PLL0_PLLDIV_SHIFT)
#define SCIF_PLL0_PLLDIV_MASKED(V)			_MASKED_VALUE((V), SCIF_PLL0_PLLDIV_SHIFT, SCIF_PLL0_PLLDIV_MASK)

#define SCIF_PLL0_PLLMUL_SHIFT			16
#define SCIF_PLL0_PLLMUL_MASK			(0xf << SCIF_PLL0_PLLMUL_SHIFT)
#define SCIF_PLL0_PLLMUL_MASKED(V)			_MASKED_VALUE((V), SCIF_PLL0_PLLMUL_SHIFT, SCIF_PLL0_PLLMUL_MASK)

#define SCIF_PLL0_PLLCOUNT_SHIFT			24
#define SCIF_PLL0_PLLCOUNT_MASK			(0x3f << SCIF_PLL0_PLLCOUNT_SHIFT)
#define SCIF_PLL0_PLLCOUNT_MASKED(V)			_MASKED_VALUE((V), SCIF_PLL0_PLLCOUNT_SHIFT, SCIF_PLL0_PLLCOUNT_MASK)


#define SCIF_GCCTRL_CEN			(1 << 0)
#define SCIF_GCCTRL_DIVEN			(1 << 1)
#define SCIF_GCCTRL_OSCSEL_SHIFT			8
#define SCIF_GCCTRL_OSCSEL_MASK			(0x1f << SCIF_GCCTRL_OSCSEL_SHIFT)
#define SCIF_GCCTRL_OSCSEL_MASKED(V)			_MASKED_VALUE(V, SCIF_GCCTRL_OSCSEL_SHIFT, SCIF_GCCTRL_OSCSEL_MASK)
#define SCIF_GCCTRL_DIV_SHIFT			16
#define SCIF_GCCTRL_DIV_MASK			(0xffff << SCIF_GCCTRL_DIV_SHIFT)
#define SCIF_GCCTRL_DIV_MASKED(V)			_MASKED_VALUE(V, SCIF_GCCTRL_DIV_SHIFT, SCIF_GCCTRL_DIV_MASK)


enum osc_mode {
	OSC_MODE_XIN = 0,
	OSC_MODE_XIN_XOUT,
};

enum osc_startup {
	OSC_STARTUP_0 = 0,
	OSC_STARTUP_4 = 8,
	OSC_STARTUP_8 = 9,
	OSC_STARTUP_16 = 10,
	OSC_STARTUP_32 = 11,
	OSC_STARTUP_64 = 1,
	OSC_STARTUP_128 = 2,
	OSC_STARTUP_256 = 12,
	OSC_STARTUP_512 = 13,
	OSC_STARTUP_1K = 14,
	OSC_STARTUP_2K = 3,
	OSC_STARTUP_4K = 4,
	OSC_STARTUP_8K = 5,
	OSC_STARTUP_16K = 6,
	OSC_STARTUP_32K = 7,
};

enum pll_clk_src {
	PLL_CLK_SRC_OSC0 = 0,
	PLL_CLK_SRC_GCLK9,
};

/* Generic Clock Source
 * 0 RCSYS System RC oscillator clock
 * 1 OSC32K Output clock from OSC32K
 * 2 DFLL0 Output clock from DFLL0
 * 3 OSC0 Output clock from Oscillator0
 * 4 RC80M Output from 80MHz RCOSC
 * 5 RCFAST Output from 4,8,12MHz RCFAST
 * 6 RC1M Output from 1MHz RC1M
 * 7 CLK_CPU The clock the CPU runs on
 * 8 CLK_HSB High Speed Bus clock
 * 9 CLK_PBA Peripheral Bus A clock
 * 10 CLK_PBB Peripheral Bus B clock
 * 11 CLK_PBC Peripheral Bus C clock
 * 12 CLK_PBD Peripheral Bus D clock
 * 13 RC32K Output from 32kHz RCOSC
 * 14 Reserved
 * 15 CLK_1K 1kHz output clock from OSC32K
 * 16 PLL0 Output clock from PLL0
 * 17 HRP High Resolution Prescaler Output
 * 18 FP Fractionnal Prescaler Output
 * 19-20 GCLK_IN[0-1] GCLK_IN[0-1] pins, digital clock input
 * 21 GCLK11 Generic Clock 11. Can not be use as input to itself.
 */
enum gclk_src {
	GCLK_SRC_RCSYS,
	GCLK_SRC_OSC32K,
	GCLK_SRC_DFLL0,
	GCLK_SRC_OSC0,
	GCLK_SRC_RC80M,
	GCLK_SRC_RCFAST,
	GCLK_SRC_RC1M,
	GCLK_SRC_CLK_CPU,
	GCLK_SRC_CLK_HSB,
	GCLK_SRC_CLK_PBA,
	GCLK_SRC_CLK_PBB,
	GCLK_SRC_CLK_PBC,
	GCLK_SRC_CLK_PBD,
	GCLK_SRC_RC32K,
	GCLK_SRC_RESERVED_,
	GCLK_SRC_CLK_1K,
	GCLK_SRC_PLL0,
	GCLK_SRC_HRP,
	GCLK_SRC_FP,
	GCLK_SRC_GCLK_IN0,
	GCLK_SRC_GCLK_IN1,
	GCLK_SRC_GCLK11,
};

enum generic_clock {
	GENERIC_CLOCK0,
	GENERIC_CLOCK1,
	GENERIC_CLOCK2,
	GENERIC_CLOCK3,
	GENERIC_CLOCK4,
	GENERIC_CLOCK5,
	GENERIC_CLOCK6,
	GENERIC_CLOCK7,
	GENERIC_CLOCK8,
	GENERIC_CLOCK9,
	GENERIC_CLOCK10,
	GENERIC_CLOCK_ADCIFE = GENERIC_CLOCK10,
	GENERIC_CLOCK11,
};

BEGIN_DECLS

int scif_osc_enable(enum osc_mode mode, uint32_t freq, enum osc_startup startup);
int scif_enable_pll(uint8_t delay, uint8_t mul, uint8_t div, uint8_t pll_opt, enum pll_clk_src source_clock);
void scif_enable_gclk(enum generic_clock gclk, enum gclk_src source_clock, uint16_t div);

END_DECLS


#endif	/* LIBOPENCM3_SCIF_H */
