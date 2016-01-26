  /*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#ifndef LIBOPENCM3_EZR32WG_MEMORYMAP_H
#define LIBOPENCM3_EZR32WG_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

#define PERIPH_BASE			(0x40000000U)

/* Device information */
#define DI_BASE				(0x0FE08000U)

/* all names are "DI_" + <reg> */
#define DI_CMU_LFRCOCTRL		MMIO32(DI_BASE + 0x020)
#define DI_CMU_HFRCOCTRL		MMIO32(DI_BASE + 0x028)
#define DI_CMU_AUXHFRCOCTRL		MMIO32(DI_BASE + 0x030)
#define DI_ADC0_CAL			MMIO32(DI_BASE + 0x040)
#define DI_ADC0_BIASPROG		MMIO32(DI_BASE + 0x048)
#define DI_DAC0_CAL			MMIO32(DI_BASE + 0x050)
#define DI_DAC0_BIASPROG		MMIO32(DI_BASE + 0x058)
#define DI_ACMP0_CTRL			MMIO32(DI_BASE + 0x060)
#define DI_ACMP1_CTRL			MMIO32(DI_BASE + 0x068)
#define DI_CMU_LCDCTRL			MMIO32(DI_BASE + 0x078)
#define DI_DAC0_OPACTRL			MMIO32(DI_BASE + 0x0A0)
#define DI_DAC0_OPAOFFSET		MMIO32(DI_BASE + 0x0A8)
#define DI_EMU_BUINACT			MMIO32(DI_BASE + 0x0B0)
#define DI_EMU_BUACT			MMIO32(DI_BASE + 0x0B8)
#define DI_EMU_BUBODBUVINCAL		MMIO32(DI_BASE + 0x0C0)
#define DI_EMU_BUBODUNREGCAL		MMIO32(DI_BASE + 0x0C8)
#define DI_MCM_REV_MIN			MMIO8(DI_BASE + 0x1AA)
#define DI_MCM_REV_MAJ			MMIO8(DI_BASE + 0x1AB)
#define DI_RADIO_REV_MIN		MMIO8(DI_BASE + 0x1AC)
#define DI_RADIO_REV_MAJ		MMIO8(DI_BASE + 0x1AD)
#define DI_RADIO_OPN			MMIO8(DI_BASE + 0x1AE)
#define DI_DI_CRC			MMIO16(DI_BASE + 0x1B0)
#define DI_CAL_TEMP_0			MMIO8(DI_BASE + 0x1B2)
#define DI_ADC0_CAL_1V25		MMIO16(DI_BASE + 0x1B4)
#define DI_ADC0_CAL_2V5			MMIO16(DI_BASE + 0x1B6)
#define DI_ADC0_CAL_VDD			MMIO16(DI_BASE + 0x1B8)
#define DI_ADC0_CAL_5VDIFF		MMIO16(DI_BASE + 0x1BA)
#define DI_ADC0_CAL_2XVDD		MMIO16(DI_BASE + 0x1BC)
#define DI_ADC0_TEMP_0_READ_1V25	MMIO16(DI_BASE + 0x1BE)
#define DI_DAC0_CAL_1V25		MMIO32(DI_BASE + 0x1C8)
#define DI_DAC0_CAL_2V5			MMIO32(DI_BASE + 0x1CC)
#define DI_DAC0_CAL_VDD			MMIO32(DI_BASE + 0x1D0)
#define DI_AUXHFRCO_CALIB_BAND_1	MMIO8(DI_BASE + 0x1D4)
#define DI_AUXHFRCO_CALIB_BAND_7	MMIO8(DI_BASE + 0x1D5)
#define DI_AUXHFRCO_CALIB_BAND_11	MMIO8(DI_BASE + 0x1D6)
#define DI_AUXHFRCO_CALIB_BAND_14	MMIO8(DI_BASE + 0x1D7)
#define DI_AUXHFRCO_CALIB_BAND_21	MMIO8(DI_BASE + 0x1D8)
#define DI_AUXHFRCO_CALIB_BAND_28	MMIO8(DI_BASE + 0x1D9)
#define DI_HFRCO_CALIB_BAND_1		MMIO8(DI_BASE + 0x1DC)
#define DI_HFRCO_CALIB_BAND_7		MMIO8(DI_BASE + 0x1DD)
#define DI_HFRCO_CALIB_BAND_11		MMIO8(DI_BASE + 0x1DE)
#define DI_HFRCO_CALIB_BAND_14		MMIO8(DI_BASE + 0x1DF)
#define DI_HFRCO_CALIB_BAND_21		MMIO8(DI_BASE + 0x1E0)
#define DI_HFRCO_CALIB_BAND_28		MMIO8(DI_BASE + 0x1E1)
#define DI_MEM_INFO_PAGE_SIZE		MMIO8(DI_BASE + 0x1E7)
#define DI_RADIO_ID                     MMIO16(DI_BASE + 0x1EE)
#define DI_UNIQUE_0			MMIO32(DI_BASE + 0x1F0)
#define DI_UNIQUE_1			MMIO32(DI_BASE + 0x1F4)
#define DI_MEM_INFO_FLASH		MMIO16(DI_BASE + 0x1F8)
#define DI_MEM_INFO_RAM			MMIO16(DI_BASE + 0x1FA)
#define DI_PART_NUMBER			MMIO16(DI_BASE + 0x1FC)
#define DI_PART_FAMILY			MMIO8(DI_BASE + 0x1FE)
#define DI_PROD_REV			MMIO8(DI_BASE + 0x1FF)

#define AES_BASE			(PERIPH_BASE + 0xE0000)
#define RMU_BASE			(PERIPH_BASE + 0xCA000)
#define CMU_BASE			(PERIPH_BASE + 0xC8000)
#define EMU_BASE			(PERIPH_BASE + 0xC6000)
#define USB_BASE			(PERIPH_BASE + 0xC4000)
#define DMA_BASE			(PERIPH_BASE + 0xC2000)
#define MSC_BASE			(PERIPH_BASE + 0xC0000)
#define LESENSE_BASE			(PERIPH_BASE + 0x8C000)
#define WDOG_BASE			(PERIPH_BASE + 0x88000)
#define PCNT2_BASE			(PERIPH_BASE + 0x86800)
#define PCNT1_BASE			(PERIPH_BASE + 0x86400)
#define PCNT0_BASE			(PERIPH_BASE + 0x86000)
#define LEUART1_BASE			(PERIPH_BASE + 0x84400)
#define LEUART0_BASE			(PERIPH_BASE + 0x84000)
#define LETIMER0_BASE			(PERIPH_BASE + 0x82000)
#define BURTC_BASE			(PERIPH_BASE + 0x81000)
#define RTC_BASE			(PERIPH_BASE + 0x80000)
#define PRS_BASE			(PERIPH_BASE + 0xCC000)
#define TIMER3_BASE			(PERIPH_BASE + 0x10C00)
#define TIMER2_BASE			(PERIPH_BASE + 0x10800)
#define TIMER1_BASE			(PERIPH_BASE + 0x10400)
#define TIMER0_BASE			(PERIPH_BASE + 0x10000)
#define UART1_BASE			(PERIPH_BASE + 0x0E400)
#define UART0_BASE			(PERIPH_BASE + 0x0E000)
#define USART2_BASE			(PERIPH_BASE + 0x0C800)
#define USART1_BASE			(PERIPH_BASE + 0x0C400)
#define USARTRF0_BASE			(PERIPH_BASE + 0x0C000)
#define I2C1_BASE			(PERIPH_BASE + 0x0A400)
#define I2C0_BASE			(PERIPH_BASE + 0x0A000)
#define GPIO_BASE			(PERIPH_BASE + 0x06000)
#define DAC0_BASE			(PERIPH_BASE + 0x04000)
#define ADC0_BASE			(PERIPH_BASE + 0x02000)
#define ACMP1_BASE			(PERIPH_BASE + 0x01400)
#define ACMP0_BASE			(PERIPH_BASE + 0x01000)
#define VCMP_BASE			(PERIPH_BASE + 0x00000)

#endif
