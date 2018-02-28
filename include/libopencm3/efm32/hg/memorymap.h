/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 * Copyright (C) 2018 Seb Holzapfel <schnommus@gmail.com>
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

#ifndef LIBOPENCM3_EFM32_MEMORYMAP_H
#define LIBOPENCM3_EFM32_MEMORYMAP_H

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
#define DI_ACMP0_CTRL			MMIO32(DI_BASE + 0x050)
#define DI_CMU_LCDCTRL			MMIO32(DI_BASE + 0x058)
#define DI_IDAC0_CAL			MMIO32(DI_BASE + 0x078)
#define DI_USHFRCOCTRL			MMIO32(DI_BASE + 0x098)
#define DI_DI_CRC			MMIO16(DI_BASE + 0x1B0)
#define DI_CAL_TEMP_0			MMIO8(DI_BASE + 0x1B2)
#define DI_ADC0_CAL_1V25		MMIO16(DI_BASE + 0x1B4)
#define DI_ADC0_CAL_2V5			MMIO16(DI_BASE + 0x1B6)
#define DI_ADC0_CAL_VDD			MMIO16(DI_BASE + 0x1B8)
#define DI_ADC0_CAL_5VDIFF		MMIO16(DI_BASE + 0x1BA)
#define DI_ADC0_CAL_2XVDD		MMIO16(DI_BASE + 0x1BC)
#define DI_ADC0_TEMP_0_READ_1V25	MMIO16(DI_BASE + 0x1BE)
#define DI_IDAC0_CAL_RANGE0		MMIO32(DI_BASE + 0x1C8)
#define DI_IDAC0_CAL_RANGE1		MMIO32(DI_BASE + 0x1C9)
#define DI_IDAC0_CAL_RANGE2		MMIO32(DI_BASE + 0x1CA)
#define DI_IDAC0_CAL_RANGE3		MMIO32(DI_BASE + 0x1CB)
#define DI_USHFRCO_COARSECAL_BAND_25	MMIO32(DI_BASE + 0x1CC)
#define DI_USHFRCO_FINECAL_BAND_25	MMIO32(DI_BASE + 0x1CD)
#define DI_USHFRCO_COARSECAL_BAND_48	MMIO32(DI_BASE + 0x1CE)
#define DI_USHFRCO_FINECAL_BAND_48	MMIO32(DI_BASE + 0x1CF)
#define DI_AUXHFRCO_CALIB_BAND_1	MMIO8(DI_BASE + 0x1D4)
#define DI_AUXHFRCO_CALIB_BAND_7	MMIO8(DI_BASE + 0x1D5)
#define DI_AUXHFRCO_CALIB_BAND_11	MMIO8(DI_BASE + 0x1D6)
#define DI_AUXHFRCO_CALIB_BAND_14	MMIO8(DI_BASE + 0x1D7)
#define DI_AUXHFRCO_CALIB_BAND_21	MMIO8(DI_BASE + 0x1D8)
#define DI_HFRCO_CALIB_BAND_1		MMIO8(DI_BASE + 0x1DC)
#define DI_HFRCO_CALIB_BAND_7		MMIO8(DI_BASE + 0x1DD)
#define DI_HFRCO_CALIB_BAND_11		MMIO8(DI_BASE + 0x1DE)
#define DI_HFRCO_CALIB_BAND_14		MMIO8(DI_BASE + 0x1DF)
#define DI_HFRCO_CALIB_BAND_21		MMIO8(DI_BASE + 0x1E0)
#define DI_UNIQUE_0			MMIO32(DI_BASE + 0x1F0)
#define DI_UNIQUE_1			MMIO32(DI_BASE + 0x1F4)
#define DI_MEM_INFO_FLASH		MMIO16(DI_BASE + 0x1F8)
#define DI_MEM_INFO_RAM			MMIO16(DI_BASE + 0x1FA)
#define DI_PART_NUMBER			MMIO16(DI_BASE + 0x1FC)
#define DI_PART_FAMILY			MMIO8(DI_BASE + 0x1FE)
#define DI_PROD_REV			MMIO8(DI_BASE + 0x1FF)

#define AES_BASE			(PERIPH_BASE + 0xE0000)
#define PRS_BASE			(PERIPH_BASE + 0xCC000)
#define RMU_BASE			(PERIPH_BASE + 0xCA000)
#define CMU_BASE			(PERIPH_BASE + 0xC8000)
#define EMU_BASE			(PERIPH_BASE + 0xC6000)
#define USB_BASE			(PERIPH_BASE + 0xC4000)
#define DMA_BASE			(PERIPH_BASE + 0xC2000)
#define MSC_BASE			(PERIPH_BASE + 0xC0000)
#define WDOG_BASE			(PERIPH_BASE + 0x88000)
#define PCNT0_BASE			(PERIPH_BASE + 0x86000)
#define LEUART0_BASE			(PERIPH_BASE + 0x84000)
#define RTC_BASE			(PERIPH_BASE + 0x80000)
#define TIMER2_BASE			(PERIPH_BASE + 0x10800)
#define TIMER1_BASE			(PERIPH_BASE + 0x10400)
#define TIMER0_BASE			(PERIPH_BASE + 0x10000)
#define USART1_BASE			(PERIPH_BASE + 0x0C400)
#define USART0_BASE			(PERIPH_BASE + 0x0C000)
#define I2C0_BASE			(PERIPH_BASE + 0x0A000)
#define GPIO_BASE			(PERIPH_BASE + 0x06000)
#define IDAC0_BASE			(PERIPH_BASE + 0x04000)
#define ADC0_BASE			(PERIPH_BASE + 0x02000)
#define ACMP0_BASE			(PERIPH_BASE + 0x01000)
#define VCMP_BASE			(PERIPH_BASE + 0x00000)

#define USB_OTG_FS_BASE			(USB_BASE    + 0x3C000)

#endif
