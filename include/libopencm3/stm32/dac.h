/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Felix Held <felix-libopencm3@felixheld.de>
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

#ifndef LIBOPENCM3_DAC_H
#define LIBOPENCM3_DAC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>


/* --- DAC registers ------------------------------------------------------- */

/* DAC control register (DAC_CR) */
#define DAC_CR				MMIO32(DAC_BASE + 0x00)

/* DAC software trigger register (DAC_SWTRIGR) */
#define DAC_SWTRIGR			MMIO32(DAC_BASE + 0x04)

/* DAC channel1 12-bit right-aligned data holding register (DAC_DHR12R1) */
#define DAC_DHR12R1			MMIO32(DAC_BASE + 0x08)

/* DAC channel1 12-bit left aligned data holding register (DAC_DHR12L1) */
#define DAC_DHR12L1			MMIO32(DAC_BASE + 0x0C)

/* DAC channel1 8-bit right aligned data holding register (DAC_DHR8R1) */
#define DAC_DHR8R1			MMIO32(DAC_BASE + 0x10)

/* DAC channel2 12-bit right aligned data holding register (DAC_DHR12R2) */
#define DAC_DHR12R2			MMIO32(DAC_BASE + 0x14)

/* DAC channel2 12-bit left aligned data holding register (DAC_DHR12L2) */
#define DAC_DHR12L2			MMIO32(DAC_BASE + 0x18)

/* DAC channel2 8-bit right-aligned data holding register (DAC_DHR8R2) */
#define DAC_DHR8R2			MMIO32(DAC_BASE + 0x1C)

/* Dual DAC 12-bit right-aligned data holding register (DAC_DHR12RD) */
#define DAC_DHR12RD			MMIO32(DAC_BASE + 0x20)

/* DUAL DAC 12-bit left aligned data holding register (DAC_DHR12LD) */
#define DAC_DHR12LD			MMIO32(DAC_BASE + 0x24)

/* DUAL DAC 8-bit right aligned data holding register (DAC_DHR8RD) */
#define DAC_DHR8RD			MMIO32(DAC_BASE + 0x28)

/* DAC channel1 data output register (DAC_DOR1) */
#define DAC_DOR1			MMIO32(DAC_BASE + 0x2C)

/* DAC channel2 data output register (DAC_DOR2) */
#define DAC_DOR2			MMIO32(DAC_BASE + 0x30)


/* --- DAC_CR values ------------------------------------------------------- */

/* DMAUDRIE2: DAC channel2 DMA underrun interrupt enable */
/* doesn't exist in most members of the stm32f1 family */
#define DAC_CR_DMAUDRIE2		(1 << 29)

/* DMAEN2: DAC channel2 DMA enable */
#define DAC_CR_DMAEN2			(1 << 28)

/* MAMP2[3:0]: DAC channel2 mask/amplitude selector */
/* DAC_CR_MAMP2_n:
 * Unmask bits [(n-1)..0] of LFSR/Triangle Amplitude equal to (2**n)-1
 */
#define DAC_CR_MAMP2_SHIFT		24
#define DAC_CR_MAMP2_1			(0x0 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_2			(0x1 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_3			(0x2 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_4			(0x3 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_5			(0x4 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_6			(0x5 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_7			(0x6 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_8			(0x7 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_9			(0x8 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_10			(0x9 << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_11			(0xA << DAC_CR_MAMP2_SHIFT)
#define DAC_CR_MAMP2_12			(0xB << DAC_CR_MAMP2_SHIFT)

/* WAVE2[1:0]: DAC channel2 noise/triangle wave generation enable */
/* Legend:
 * DIS: wave generation disabled
 * NOISE: Noise wave generation enabled
 * TRI: Triangle wave generation enabled
 *
 * Note: only used if bit TEN2 = 1 (DAC channel2 trigger enabled)
 */
#define DAC_CR_WAVE2_SHIFT		22
#define DAC_CR_WAVE2_DIS		(0x0 << DAC_CR_WAVE2_SHIFT)
#define DAC_CR_WAVE2_NOISE		(0x1 << DAC_CR_WAVE2_SHIFT)
#define DAC_CR_WAVE2_TRI		(0x2 << DAC_CR_WAVE2_SHIFT)

/* TSEL2[2:0]: DAC channel2 trigger selection */
/* Legend:
 *
 * T6: Timer 6 TRGO event
 * T3: Timer 3 TRGO event
 * T8: Timer 8 TRGO event
 * T7: Timer 7 TRGO event
 * T5: Timer 5 TRGO event
 * T15: Timer 15 TRGO event
 * T2: Timer 2 TRGO event
 * T4: Timer 4 TRGO event
 * E9: External line9
 * SW: Software trigger
 *
 * Note: only used if bit TEN2 = 1 (DAC channel2 trigger enabled)
 * Note: T3 == T8; T5 == T15; not both present on one device
 * Note: this is *not* valid for the STM32L1 family
 */
#define DAC_CR_TSEL2_SHIFT		19
#define DAC_CR_TSEL2_T6			(0x0 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T3			(0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T8			(0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T7			(0x2 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T5			(0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T15		(0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T2			(0x4 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T4			(0x5 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_E9			(0x6 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_SW			(0x7 << DAC_CR_TSEL2_SHIFT)

/* TEN2: DAC channel2 trigger enable */
#define DAC_CR_TEN2			(1 << 18)

/* BOFF2: DAC channel2 output buffer disable */
#define DAC_CR_BOFF2			(1 << 17)

/* EN2: DAC channel2 enable */
#define DAC_CR_EN2			(1 << 16)

/* DMAUDRIE1: DAC channel1 DMA underrun interrupt enable */
/* doesn't exist in most members of the stm32f1 family */
#define DAC_CR_DMAUDRIE1	(1 << 13)

/* DMAEN1: DAC channel1 DMA enable */
#define DAC_CR_DMAEN1			(1 << 12)

/* MAMP1[3:0]: DAC channel1 mask/amplitude selector */
/* DAC_CR_MAMP1_n:
 * Unmask bits [(n-1)..0] of LFSR/Triangle Amplitude equal to (2**n)-1
 */
#define DAC_CR_MAMP1_SHIFT		8
#define DAC_CR_MAMP1_1			(0x0 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_2			(0x1 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_3			(0x2 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_4			(0x3 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_5			(0x4 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_6			(0x5 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_7			(0x6 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_8			(0x7 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_9			(0x8 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_10			(0x9 << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_11			(0xA << DAC_CR_MAMP1_SHIFT)
#define DAC_CR_MAMP1_12			(0xB << DAC_CR_MAMP1_SHIFT)

/* WAVE1[1:0]: DAC channel1 noise/triangle wave generation enable */
/* Legend:
 * DIS: wave generation disabled
 * NOISE: Noise wave generation enabled
 * TRI: Triangle wave generation enabled
 *
 * Note: only used if bit TEN1 = 1 (DAC channel1 trigger enabled)
 */
#define DAC_CR_WAVE1_SHIFT		6
#define DAC_CR_WAVE1_DIS		(0x0 << DAC_CR_WAVE1_SHIFT)
#define DAC_CR_WAVE1_NOISE		(0x1 << DAC_CR_WAVE1_SHIFT)
#define DAC_CR_WAVE1_TRI		(0x2 << DAC_CR_WAVE1_SHIFT)

/* TSEL1[2:0]: DAC channel1 trigger selection */
/* Legend:
 *
 * T6: Timer 6 TRGO event
 * T3: Timer 3 TRGO event in connectivity line devices
 * T8: Timer 8 TRGO event in high-density and XL-density devices
 * T7: Timer 7 TRGO event
 * T5: Timer 5 TRGO event
 * T15: Timer 15 TRGO event
 * T2: Timer 2 TRGO event
 * T4: Timer 4 TRGO event
 * E9: External line9
 * SW: Software trigger
 *
 * Note: only used if bit TEN1 = 1 (DAC channel1 trigger enabled)
 * Note: T3 == T8; T5 == T15; not both present on one device
 * Note: this is *not* valid for the STM32L1 family
 */
#define DAC_CR_TSEL1_SHIFT		3
#define DAC_CR_TSEL1_T6			(0x0 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T3			(0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T8			(0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T7			(0x2 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T5			(0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T15		(0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T2			(0x4 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T4			(0x5 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_E9			(0x6 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_SW			(0x7 << DAC_CR_TSEL1_SHIFT)

/* TEN1: DAC channel1 trigger enable */
#define DAC_CR_TEN1			(1 << 2)

/* BOFF1: DAC channel1 output buffer disable */
#define DAC_CR_BOFF1			(1 << 1)

/* EN1: DAC channel1 enable */
#define DAC_CR_EN1			(1 << 0)


/* --- DAC_SWTRIGR values -------------------------------------------------- */

/* SWTRIG2: DAC channel2 software trigger */
#define DAC_SWTRIGR_SWTRIG2		(1 << 1)

/* SWTRIG1: DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG1		(1 << 0)


/* --- DAC_DHR12R1 values -------------------------------------------------- */
#define DAC_DHR12R1_DACC1DHR_LSB	(1 << 0)
#define DAC_DHR12R1_DACC1DHR_MSK	(0x0FFF << 0)


/* --- DAC_DHR12L1 values -------------------------------------------------- */
#define DAC_DHR12L1_DACC1DHR_LSB	(1 << 4)
#define DAC_DHR12L1_DACC1DHR_MSK	(0x0FFF << 4)


/* --- DAC_DHR8R1 values --------------------------------------------------- */
#define DAC_DHR8R1_DACC1DHR_LSB		(1 << 0)
#define DAC_DHR8R1_DACC1DHR_MSK		(0x00FF << 0)


/* --- DAC_DHR12R2 values -------------------------------------------------- */
#define DAC_DHR12R2_DACC2DHR_LSB	(1 << 0)
#define DAC_DHR12R2_DACC2DHR_MSK	(0x00FFF << 0)


/* --- DAC_DHR12L2 values -------------------------------------------------- */
#define DAC_DHR12L2_DACC2DHR_LSB	(1 << 4)
#define DAC_DHR12L2_DACC2DHR_MSK	(0x0FFF << 4)


/* --- DAC_DHR8R2 values --------------------------------------------------- */
#define DAC_DHR8R2_DACC2DHR_LSB		(1 << 0)
#define DAC_DHR8R2_DACC2DHR_MSK		(0x00FF << 0)


/* --- DAC_DHR12RD values -------------------------------------------------- */
#define DAC_DHR12RD_DACC2DHR_LSB	(1 << 16)
#define DAC_DHR12RD_DACC2DHR_MSK	(0x0FFF << 16)
#define DAC_DHR12RD_DACC1DHR_LSB	(1 << 0)
#define DAC_DHR12RD_DACC1DHR_MSK	(0x0FFF << 0)


/* --- DAC_DHR12LD values -------------------------------------------------- */
#define DAC_DHR12LD_DACC2DHR_LSB	(1 << 16)
#define DAC_DHR12LD_DACC2DHR_MSK	(0x0FFF << 20)
#define DAC_DHR12LD_DACC1DHR_LSB	(1 << 0)
#define DAC_DHR12LD_DACC1DHR_MSK	(0x0FFF << 4)


/* --- DAC_DHR8RD values --------------------------------------------------- */
#define DAC_DHR8RD_DACC2DHR_LSB		(1 << 8)
#define DAC_DHR8RD_DACC2DHR_MSK		(0x00FF << 8)
#define DAC_DHR8RD_DACC1DHR_LSB		(1 << 0)
#define DAC_DHR8RD_DACC1DHR_MSK		(0x00FF << 0)


/* --- DAC_DOR1 values ----------------------------------------------------- */
#define DAC_DOR1_DACC1DOR_LSB		(1 << 0)
#define DAC_DOR1_DACC1DOR_MSK		(0x0FFF << 0)


/* --- DAC_DOR2 values ----------------------------------------------------- */
#define DAC_DOR2_DACC2DOR_LSB		(1 << 0)
#define DAC_DOR2_DACC2DOR_MSK		(0x0FFF << 0)


/* --- Function prototypes ------------------------------------------------- */


/* TODO */


#endif
