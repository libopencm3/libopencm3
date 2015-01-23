/** @defgroup clock_defines Clock Defines

@brief <b>Defined Constants and Types for the LPC17xx Clock</b>

@ingroup LPC17xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013 Silvio Gissi <silvio.gissi@outlook.com>

@date 17 August 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Silvio Gissi <silvio.gissi@outlook.com>
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

#ifndef LPC17XX_CLOCK_H
#define LPC17XX_CLOCK_H

#include <libopencm3/lpc17xx/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Clock registers ----------------------------------------------------- */
/* System Control and Status */
#define CLK_SCS				MMIO32(SYSCON_BASE + 0x1a0)
/* Clock Source Selection */
#define CLK_CLKSRCSEL			MMIO32(SYSCON_BASE + 0x10c)
/* PLL0: Main */
#define CLK_PLL0CON			MMIO32(SYSCON_BASE + 0x080)
#define CLK_PLL0CFG			MMIO32(SYSCON_BASE + 0x084)
#define CLK_PLL0STAT			MMIO32(SYSCON_BASE + 0x088)
#define CLK_PLL0FEED			MMIO32(SYSCON_BASE + 0x08c)
/* PLL1: USB */
#define CLK_PLL1CON			MMIO32(SYSCON_BASE + 0x0a0)
#define CLK_PLL1CFG			MMIO32(SYSCON_BASE + 0x0a4)
#define CLK_PLL1STAT			MMIO32(SYSCON_BASE + 0x0a8)
#define CLK_PLL1FEED			MMIO32(SYSCON_BASE + 0x0ac)
/* Clock Dividers */
#define CLK_CCLKCFG			MMIO32(SYSCON_BASE + 0x104)
#define CLK_USBCLKCFG			MMIO32(SYSCON_BASE + 0x108)
#define CLK_PCLKSEL0			MMIO32(SYSCON_BASE + 0x1a8)
#define CLK_PCLKSEL1			MMIO32(SYSCON_BASE + 0x1ac)
/* Clock Output */
#define CLK_CLKOUTCFG			MMIO32(SYSCON_BASE + 0x1c8)

/* CLK_SCS Values*/
/* Reserved: [3:0] */
#define CLK_SCS_OSCRANGE_01_TO_20MHZ	(0)
#define CLK_SCS_OSCRANGE_15_TO_25MHZ	(1 << 4)
#define CLK_SCS_OSCEN			(1 << 5)
#define CLK_SCS_OSCSTAT			(1 << 6)
/* Reserved: [31:7] */

/* CLK_CLKSRCSEL Values*/
#define CLK_CLKSRCSEL_IRC		(0)
#define CLK_CLKSRCSEL_MAIN		(1 << 0)
#define CLK_CLKSRCSEL_RTC		(1 << 1)
/* Reserved: value 11b */
/* Reserved: [31:2] */

/* CLK_PLL0CON and CLK_PLL1CON Values */
#define CLK_PLLCON_ENABLE		(1 << 0)
#define CLK_PLLCON_CONNECT		(1 << 1)
/* Reserved: [31:2] */

/* CLK_PLL0CFG and CLK_PLL0STAT Values */
#define CLK_PLL0_MSEL_SHIFT		0
#define CLK_PLL0_MSEL_MASK		0x7fff
/* Reserved: [15] */
#define CLK_PLL0_NSEL_SHIFT		16
#define CLK_PLL0_NSEL_MASK		0xff
/* CFG Reserved: [31:24] */
#define CLK_PLL0STAT_ENABLE		(1 << 24)
#define CLK_PLL0STAT_CONNECT		(1 << 25)
#define CLK_PLL0STAT_PLOCK		(1 << 26)
/* STAT Reserved: [31:27] */

/* CLK_PLL1CFG and CLK_PLL1STAT Values */
#define CLK_PLL1_MSEL_SHIFT		0
#define CLK_PLL1_MSEL_MASK		0x1f
#define CLK_PLL1_PSEL_SHIFT		5
#define CLK_PLL1_PSEL_MASK		0x3
/* CFG Reserved: [31:7] */
#define CLK_PLL1STAT_ENABLE		(1 << 8)
#define CLK_PLL1STAT_CONNECT		(1 << 9)
#define CLK_PLL1STAT_PLOCK		(1 << 10)
/* STAT Reserved: [31:11] */

/* CLK_USBCLKCFG Values */
#define CLK_USBCLKCFG_DIV6		0x5
#define CLK_USBCLKCFG_DIV8		0x7
#define CLK_USBCLKCFG_DIV10		0x9

/* CLK_PCLKSEL0 and CLK_PCLKSEL1 Values */
#define CLK_PCLKSEL_DIV4		0x00
#define CLK_PCLKSEL_DIV1		0x01
#define CLK_PCLKSEL_DIV2		0x02
#define CLK_PCLKSEL_DIV8		0x03
#define CLK_PCLKSEL0_WDT_SHIFT		0
#define CLK_PCLKSEL0_TIMER0_SHIFT	2
#define CLK_PCLKSEL0_TIMER1_SHIFT	4
#define CLK_PCLKSEL0_UART0_SHIFT	6
#define CLK_PCLKSEL0_UART1_SHIFT	8
/* Reserved: [11:10]*/
#define CLK_PCLKSEL0_PWM1_SHIFT	12
#define CLK_PCLKSEL0_I2C0_SHIFT	14
#define CLK_PCLKSEL0_SPI_SHIFT		16
/* Reserved: [19:18]*/
#define CLK_PCLKSEL0_SSP1_SHIFT	20
#define CLK_PCLKSEL0_DAC_SHIFT		22
#define CLK_PCLKSEL0_ADC_SHIFT		24
#define CLK_PCLKSEL0_CAN1_SHIFT	26
#define CLK_PCLKSEL0_CAN2_SHIFT	28
#define CLK_PCLKSEL0_ACF_SHIFT		30
#define CLK_PCLKSEL1_QEI_SHIFT		0
#define CLK_PCLKSEL1_GPIOINT_SHIFT	2
#define CLK_PCLKSEL1_PCB_SHIFT		4
#define CLK_PCLKSEL1_I2C1_SHIFT	6
/* Reserved: [9:8]*/
#define CLK_PCLKSEL1_SSP0_SHIFT	10
#define CLK_PCLKSEL1_TIMER2_SHIFT	12
#define CLK_PCLKSEL1_TIMER3_SHIFT	14
#define CLK_PCLKSEL1_UART2_SHIFT	16
#define CLK_PCLKSEL1_UART3_SHIFT	18
#define CLK_PCLKSEL1_I2C2_SHIFT	20
#define CLK_PCLKSEL1_I2S_SHIFT		22
/* Reserved: [25:24]*/
#define CLK_PCLKSEL1_RIT_SHIFT		26
#define CLK_PCLKSEL1_SYSCON_SHIFT	28
#define CLK_PCLKSEL1_MCPWM_SHIFT	30

/* CLK_CLKOUTCFG Values */
#define CLK_CLKOUTCFG_SEL_CPU		0x00
#define CLK_CLKOUTCFG_SEL_MAIN		0x01
#define CLK_CLKOUTCFG_SEL_IRC		0x02
#define CLK_CLKOUTCFG_SEL_USB		0x03
#define CLK_CLKOUTCFG_SEL_RTC		0x04
#define CLK_CLKOUTCFG_DIV_SHIFT	4
#define CLK_CLKOUTCFG_ENABLE		(1 << 8)
#define CLK_CLKOUTCFG_ENABLE		(1 << 9)
/* Reserved: [31:10]*/

#endif
