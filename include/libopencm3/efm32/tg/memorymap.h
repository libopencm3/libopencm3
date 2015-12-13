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
 *
 * Layout of the system address space of Tiny Gecko devices.
 *
 * This reflects d0034_efm32tg_reference_manual.pdf figure 5.2.
 */

/* The common cortex-m3 definitions were verified from
 * d0034_efm32tg_reference_manual.pdf figure 5.2. The CM3 ROM Table seems to be
 * missing there. The details (everything based on SCS_BASE) was verified from
 * d0002_efm32_cortex-m3_reference_manual.pdf table 4.1, and seems to fit, but
 * there are discrepancies. */
#include <libopencm3/cm3/memorymap.h>

#define CODE_BASE		(0x00000000U)

#define SRAM_BASE		(0x20000000U)
#define SRAM_BASE_BITBAND	(0x22000000U)

#define PERIPH_BASE		(0x40000000U)
#define PERIPH_BASE_BITBAND	(0x42000000U)

/* Details of the "Code" section */

#define FLASH_BASE		(CODE_BASE + 0x00000000)
#define USERDATA_BASE		(CODE_BASE + 0x0fe00000)
#define LOCKBITS_BASE		(CODE_BASE + 0x0fe04000)
#define CHIPCONFIG_BASE		(CODE_BASE + 0x0fe08000)
#define CODESPACESRAM_BASE	(CODE_BASE + 0x10000000)

/* Tiny Gecko peripherial definitions */

#define	VCMP_BASE		(PERIPH_BASE + 0x00000000)
#define	ACMP0_BASE		(PERIPH_BASE + 0x00001000)
#define	ACMP1_BASE		(PERIPH_BASE + 0x00001400)
#define	ADC_BASE		(PERIPH_BASE + 0x00002000)
#define	DAC0_BASE		(PERIPH_BASE + 0x00004000)
#define	GPIO_BASE		(PERIPH_BASE + 0x00006000) /**< @see gpio.h */
#define	I2C0_BASE		(PERIPH_BASE + 0x0000a000)
#define	USART0_BASE		(PERIPH_BASE + 0x0000c000)
#define	USART1_BASE		(PERIPH_BASE + 0x0000c400)
#define	TIMER0_BASE		(PERIPH_BASE + 0x00010000)
#define	TIMER1_BASE		(PERIPH_BASE + 0x00010400)
#define	RTC_BASE		(PERIPH_BASE + 0x00080000)
#define	LETIMER0_BASE		(PERIPH_BASE + 0x00082000)
#define	LEUART0_BASE		(PERIPH_BASE + 0x00084000)
#define	PCNT0_BASE		(PERIPH_BASE + 0x00086000)
#define	WDOG_BASE		(PERIPH_BASE + 0x00088000)
#define	LCD_BASE		(PERIPH_BASE + 0x0008a000)
#define	LESENSE_BASE		(PERIPH_BASE + 0x0008c000)
#define	MSC_BASE		(PERIPH_BASE + 0x000c0000)
#define	DMA_BASE		(PERIPH_BASE + 0x000c2000)
#define	EMU_BASE		(PERIPH_BASE + 0x000c6000)
#define	CMU_BASE		(PERIPH_BASE + 0x000c8000) /**< @see cmu.h */
#define	RMU_BASE		(PERIPH_BASE + 0x000ca000)
#define	PRS_BASE		(PERIPH_BASE + 0x000cc000)
#define	AES_BASE		(PERIPH_BASE + 0x000e0000)
