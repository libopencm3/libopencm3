/** @defgroup dac_defines DAC Defines

@brief <b>Defined Constants and Types for the STM32G4xx DAC</b>

@ingroup STM32G4xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012
Felix Held <felix-libopencm3@felixheld.de>
@author @htmlonly &copy; @endhtmlonly 2020
Ben Brewer <ben.brewer@codethink.co.uk>

@date 3 August 2020

LGPL License Terms @ref lgpl_license
 */

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

#ifndef LIBOPENCM3_DAC_H
#define LIBOPENCM3_DAC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/**@{*/

/** @defgroup dac_reg_base DAC register base addresses
@ingroup STM32xx_dac_defines
@{*/
#define DAC1				DAC1_BASE
#define DAC2				DAC2_BASE
#define DAC3				DAC3_BASE
#define DAC4				DAC4_BASE
#define DAC5				DAC5_BASE
/**@}*/

/* --- DAC registers ------------------------------------------------------- */

/* DAC control register (DAC_CR) */
#define DAC_CR(dac)			MMIO32((dac) + 0x00)

/* DAC software trigger register (DAC_SWTRIGR) */
#define DAC_SWTRGR(dac)			MMIO32((dac) + 0x04)

/* DAC channel1 12-bit right-aligned data holding register (DAC_DHR12R1) */
#define DAC_DHR12R1(dac)		MMIO32((dac) + 0x08)

/* DAC channel1 12-bit left aligned data holding register (DAC_DHR12L1) */
#define DAC_DHR12L1(dac)		MMIO32((dac) + 0x0C)

/* DAC channel1 8-bit right aligned data holding register (DAC_DHR8R1) */
#define DAC_DHR8R1(dac)			MMIO32((dac) + 0x10)

/* DAC channel2 12-bit right aligned data holding register (DAC_DHR12R2) */
#define DAC_DHR12R2(dac)		MMIO32((dac) + 0x14)

/* DAC channel2 12-bit left aligned data holding register (DAC_DHR12L2) */
#define DAC_DHR12L2(dac)		MMIO32((dac) + 0x18)

/* DAC channel2 8-bit right-aligned data holding register (DAC_DHR8R2) */
#define DAC_DHR8R2(dac)			MMIO32((dac) + 0x1C)

/* Dual DAC 12-bit right-aligned data holding register (DAC_DHR12RD) */
#define DAC_DHR12RD(dac)		MMIO32((dac) + 0x20)

/* DUAL DAC 12-bit left aligned data holding register (DAC_DHR12LD) */
#define DAC_DHR12LD(dac)		MMIO32((dac) + 0x24)

/* DUAL DAC 8-bit right aligned data holding register (DAC_DHR8RD) */
#define DAC_DHR8RD(dac)			MMIO32((dac) + 0x28)

/* DAC channel1 data output register (DAC_DOR1) */
#define DAC_DOR1(dac)			MMIO32((dac) + 0x2C)

/* DAC channel2 data output register (DAC_DOR2) */
#define DAC_DOR2(dac)			MMIO32((dac) + 0x30)

/* DAC status register (DAC_SR) */
#define DAC_SR(dac)			MMIO32((dac) + 0x34)

/* DAC calibration control register (DAC_CCR) */
#define DAC_CCR(dac)			MMIO32((dac) + 0x38)

/* DAC mode control register (DAC_MCR) */
#define DAC_MCR(dac)			MMIO32((dac) + 0x3C)

/* DAC channel1 sample and hold sample time register (DAC_SHSR1) */
#define DAC_SHSR1(dac)			MMIO32((dac) + 0x40)

/* DAC channel2 sample and hold sample time register (DAC_SHSR2) */
#define DAC_SHSR2(dac)			MMIO32((dac) + 0x44)

/* DAC sample and hold time register (DAC_SHHR) */
#define DAC_SHHR(dac)			MMIO32((dac) + 0x48)

/* DAC sample and hold refresh time register (DAC_SHRR) */
#define DAC_SHRR(dac)			MMIO32((dac) + 0x4C)

/* DAC channel1 sawtooth register (DAC_STR1) */
#define DAC_STR1(dac)			MMIO32((dac) + 0x58)

/* DAC channel2 sawtooth register (DAC_STR2) */
#define DAC_STR2(dac)			MMIO32((dac) + 0x5C)

/* DAC sawtooth mode register (DAC_STMODR) */
#define DAC_STMODR(dac)			MMIO32((dac) + 0x60)

/* --- DAC_CR values ------------------------------------------------------- */

/* CEN2: DAC channel2 calibration enable */
#define DAC_CR_CEN2			(1 << 30)

/* DMAUDRIE2: DAC channel2 DMA underrun interrupt enable */
#define DAC_CR_DMAUDRIE2		(1 << 29)

/* DMAEN2: DAC channel2 DMA enable */
#define DAC_CR_DMAEN2			(1 << 28)

/* MAMP2[3:0]: DAC channel2 mask/amplitude selector */
/* DAC_CR_MAMP2_n:
 * Unmask bits [(n-1)..0] of LFSR/Triangle Amplitude equal to (2**n)-1
 */
#define DAC_CR_MAMP2_SHIFT		24
/** @defgroup dac_mamp2 DAC Channel 2 LFSR Mask and Triangle Wave Amplitude
values
@ingroup dac_defines

Unmask bits [(n-1)..0] of LFSR/Triangle Amplitude equal to (2**(n)-1
@{*/
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
/**@}*/

/* WAVE2[1:0]: DAC channel2 noise/triangle wave generation enable */
/* Legend:
 * NOISE: Noise wave generation enabled
 * TRI: Triangle wave generation enabled
 * SAW: Sawtooth wave generation enabled
 *
 * Note: only used if bit TEN2 = 1 (DAC channel2 trigger enabled)
 */
#define DAC_CR_WAVE2_SHIFT		22
#define DAC_CR_WAVE2_DIS		(0x3 << DAC_CR_WAVE2_SHIFT)
/** @defgroup dac_wave2_en DAC Channel 2 Waveform Generation Enable
@ingroup dac_defines

@li NOISE: Noise wave generation enabled
@li TRI: Triangle wave generation enabled
@li SAW: Sawtooth wave generation enabled

@note: only used if bit TEN2 is set (DAC channel2 trigger enabled)
@{*/
#define DAC_CR_WAVE2_NOISE		(0x1 << DAC_CR_WAVE2_SHIFT)
#define DAC_CR_WAVE2_TRI		(0x2 << DAC_CR_WAVE2_SHIFT)
#define DAC_CR_WAVE2_SAW		(0x3 << DAC_CR_WAVE2_SHIFT)
/**@}*/

/* TSEL2[3:0]: DAC channel2 trigger selection */
#define DAC_CR_TSEL2_SHIFT		18
/** @defgroup dac_trig2_sel DAC Channel 2 Trigger Source Selection
@ingroup dac_defines

@li SW: Software trigger
@li T8: Timer 8 TRGO event
@li T7: Timer 7 TRGO event
@li T15: Timer 15 TRGO event
@li T2: Timer 2 TRGO event
@li T4: Timer 4 TRGO event
@li E9: External line 9
@li T6: Timer 6 TRGO event
@li T3: Timer 3 TRGO event
@li HRR1: hrtim_dac_reset_trg1
@li HRR2: hrtim_dac_reset_trg2
@li HRR3: hrtim_dac_reset_trg3
@li HRR4: hrtim_dac_reset_trg4
@li HRR5: hrtim_dac_reset_trg5
@li HRR6: hrtim_dac_reset_trg6
@li HR2: hrtim_dac_trg2

@note: only used if bit TEN2 is set (DAC channel 2 trigger enabled)
@{*/
#define DAC_CR_TSEL2_SW			(0x0 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T8			(0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T7			(0x2 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T15		(0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T2			(0x4 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T4			(0x5 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_E9			(0x6 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T6			(0x7 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T3			(0x8 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HRR1		(0x9 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HRR2		(0xA << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HRR3		(0xB << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HRR4		(0xC << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HRR5		(0xD << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HRR6		(0xE << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_HR2		(0xF << DAC_CR_TSEL2_SHIFT)
/**@}*/

/* TEN2: DAC channel2 trigger enable */
#define DAC_CR_TEN2			(1 << 17)

/* EN2: DAC channel2 enable */
#define DAC_CR_EN2			(1 << 16)

/* CEN2: DAC channel1 calibration enable */
#define DAC_CR_CEN1			(1 << 14)

/* DMAUDRIE1: DAC channel1 DMA underrun interrupt enable */
/* doesn't exist in most members of the STM32F1 family */
#define DAC_CR_DMAUDRIE1		(1 << 13)

/* DMAEN1: DAC channel1 DMA enable */
#define DAC_CR_DMAEN1			(1 << 12)

/* MAMP1[3:0]: DAC channel1 mask/amplitude selector */
/* DAC_CR_MAMP1_n:
 * Unmask bits [(n-1)..0] of LFSR/Triangle Amplitude equal to (2**n)-1
 */
#define DAC_CR_MAMP1_SHIFT		8
/** @defgroup dac_mamp1 DAC Channel 1 LFSR Mask and Triangle Wave Amplitude
values
@ingroup dac_defines

Unmask bits [(n-1)..0] of LFSR/Triangle Amplitude equal to (2**(n+1)-1
@{*/
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
/**@}*/

/* WAVE1[1:0]: DAC channel1 noise/triangle wave generation enable */
/* Legend:
 * NOISE: Noise wave generation enabled
 * TRI: Triangle wave generation enabled
 * SAW: Sawtooth wave generation enabled
 *
 * Note: only used if bit TEN1 = 1 (DAC channel1 trigger enabled)
 */
#define DAC_CR_WAVE1_SHIFT		6
#define DAC_CR_WAVE1_DIS		(0x3 << DAC_CR_WAVE1_SHIFT)
/** @defgroup dac_wave1_en DAC Channel 1 Waveform Generation Enable
@ingroup dac_defines

@li NOISE: Noise wave generation enabled
@li TRI: Triangle wave generation enabled
@li SAW: Sawtooth wave generation enabled

@note: only used if bit TEN2 = 1 (DAC channel2 trigger enabled)
@{*/
#define DAC_CR_WAVE1_NOISE		(0x1 << DAC_CR_WAVE1_SHIFT)
#define DAC_CR_WAVE1_TRI		(0x2 << DAC_CR_WAVE1_SHIFT)
#define DAC_CR_WAVE1_SAW		(0x3 << DAC_CR_WAVE1_SHIFT)
/**@}*/

/* TSEL1[3:0]: DAC channel1 trigger selection */
#define DAC_CR_TSEL1_SHIFT		2
/** @defgroup dac_trig1_sel DAC Channel 1 Trigger Source Selection
@ingroup dac_defines

@li CK: ck_lsi or ck_lse (selected in the RCC)
@li T8: Timer 8 TRGO event
@li T7: Timer 7 TRGO event in connectivity line devices
@li T15: Timer 15 TRGO event in high-density and XL-density devices
@li T2: Timer 2 TRGO event
@li T4: Timer 4 TRGO event
@li E9: External line9
@li T6: Timer 6 TRGO event
@li T3: Timer 3 TRGO event
@li HRR1: hrtim_dac_reset_trg1
@li HRR2: hrtim_dac_reset_trg2
@li HRR3: hrtim_dac_reset_trg3
@li HRR4: hrtim_dac_reset_trg4
@li HRR5: hrtim_dac_reset_trg5
@li HRR6: hrtim_dac_reset_trg6
@li HR2: hrtim_dac_trg2

@note: only used if bit TEN2 is set (DAC channel 1 trigger enabled).
@{*/
#define DAC_CR_TSEL1_CK			(0x0 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T8			(0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T7			(0x2 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T15		(0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T2			(0x4 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T4			(0x5 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_E9			(0x6 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T6			(0x7 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T3			(0x8 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HRR1		(0x9 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HRR2		(0xA << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HRR3		(0xB << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HRR4		(0xC << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HRR5		(0xD << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HRR6		(0xE << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_HR3		(0xF << DAC_CR_TSEL1_SHIFT)
/**@}*/

/* TEN1: DAC channel1 trigger enable */
#define DAC_CR_TEN1			(1 << 1)

/* EN1: DAC channel1 enable */
#define DAC_CR_EN1			(1 << 0)


/* --- DAC_SWTRGR values -------------------------------------------------- */

/* SWTRIG2: DAC channel2 software trigger B */
#define DAC_SWTRGR_SWTRIGB2		(1 << 17)

/* SWTRIG1: DAC channel1 software trigger B*/
#define DAC_SWTRGR_SWTRIGB1		(1 << 16)

/* SWTRIG2: DAC channel2 software trigger */
#define DAC_SWTRGR_SWTRIG2		(1 << 1)

/* SWTRIG1: DAC channel1 software trigger */
#define DAC_SWTRGR_SWTRIG1		(1 << 0)


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
#define DAC_DOR1_DACC1DORB_LSB		(1 << 16)
#define DAC_DOR1_DACC1DORB_MSK		(0x0FFF << 16)

#define DAC_DOR1_DACC1DOR_LSB		(1 << 0)
#define DAC_DOR1_DACC1DOR_MSK		(0x0FFF << 0)


/* --- DAC_DOR2 values ----------------------------------------------------- */
#define DAC_DOR2_DACC2DORB_LSB		(1 << 16)
#define DAC_DOR2_DACC2DORB_MSK		(0x0FFF << 16)

#define DAC_DOR2_DACC2DOR_LSB		(1 << 0)
#define DAC_DOR2_DACC2DOR_MSK		(0x0FFF << 0)

/** @defgroup dac_sr_values DAC_SR Values
@{*/
/* DAC channel2 busy writing sample time flag */
#define DAC_SR_BWST2			(1 << 31)

/* DAC channel2 calibration offset status */
#define DAC_SR_CAL_FLAG2		(1 << 30)

/** DAC channel2 DMA underrun flag */
#define DAC_SR_DMAUDR2			(1 << 29)

/* DAC channel2 output register status bit */
#define DAC_SR_DORSTAT2			(1 << 28)

/* DAC channel2 ready status bit */
#define DAC_SR_DAC2RDY			(1 << 27)

/* DAC channel1 busy writing sample time flag */
#define DAC_SR_BWST1			(1 << 15)

/* DAC channel1 calibration offset status */
#define DAC_SR_CAL_FLAG1		(1 << 14)

/** DAC channel1 DMA underrun flag */
#define DAC_SR_DMAUDR1			(1 << 13)

/* DAC channel1 output register status bit */
#define DAC_SR_DORSTAT1			(1 << 12)

/* DAC channel1 ready status bit */
#define DAC_SR_DAC1RDY			(1 << 11)
/*@}*/

/* --- DAC_CCR values ----------------------------------------------------- */

/* DAC channel2 offset trimming value */
#define DAC_CCR_OTRIM2_LSB		(1 << 16)
#define DAC_CCR_OTRIM2_MSK		(0x1F << 16)

/* DAC channel1 offset trimming value */
#define DAC_CCR_OTRIM1_LSB		(1 << 0)
#define DAC_CCR_OTRIM1_MSK		(0x1F << 0)

/* --- DAC_MCR values ----------------------------------------------------- */

/* Enable signed format for DAC channel2 */
#define DAC_MCR_SINFORMAT2		(1 << 25)

/* DAC channel2 DMA double data mode */
#define DAC_MCR_DMADOUBLE2		(1 << 24)

/* MODE2[2:0]: DAC channel2 mode */
#define DAC_MCR_MODE2_SHIFT		16
/** @defgroup dac_mode2_sel DAC Channel 2 Mode Selection
@ingroup dac_defines

@li E_BUFF: External pin with buffer enabled
@li EP_BUFF: External pin and on-chip peripherals with buffer
@li E: External pin without buffer
@li EP: External pin and on-chip peripherals without buffer
@li SH_E_BUFF: Sample & Hold, External pin with buffer enabled
@li SH_EP_BUFF: Sample & Hold, External pin and on-chip peripherals with buffer
@li SH_E: Sample & Hold, External pin without buffer
@li SH_EP: Sample & Hold , External pin and on-chip peripherals without buffer
@{*/
#define DAC_MCR_MODE2_E_BUFF		(0x0 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_EP_BUFF		(0x1 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_E			(0x2 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_EP		(0x3 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_SH_E_BUFF		(0x4 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_SH_EP_BUFF	(0x5 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_SH_E		(0x6 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_SH_EP		(0x7 << DAC_MCR_MODE2_SHIFT)
/**@}*/

#define DAC_MCR_MODE2_PERIPHERAL	(0x1 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_UNBUFFERED	(0x2 << DAC_MCR_MODE2_SHIFT)
#define DAC_MCR_MODE2_SAMPLEHOLD	(0x4 << DAC_MCR_MODE2_SHIFT)

/* HFSEL[1:0]: High frequency interface mode selection */
#define DAC_MCR_HFSEL_SHIFT		14
#define DAC_MCR_HFSEL_MASK		0x3
/** @defgroup dac_hfsel High frequency interface mode selection
@ingroup dac_defines

@li DIS: High frequency mode disabled
@li AHB80: High frequency interface mode compatible to AHB>80MHz enabled
@li AHB160: High frequency interface mode compatible to AHB>160MHz enabled
@{*/
#define DAC_MCR_HFSEL_DIS		(0x0 << DAC_MCR_HFSEL_SHIFT)
#define DAC_MCR_HFSEL_AHB80		(0x1 << DAC_MCR_HFSEL_SHIFT)
#define DAC_MCR_HFSEL_AHB160		(0x2 << DAC_MCR_HFSEL_SHIFT)
/**@}*/

/* Enable signed format for DAC channel1 */
#define DAC_MCR_SINFORMAT1		(1 << 9)

/* DAC channel1 DMA double data mode */
#define DAC_MCR_DMADOUBLE1		(1 << 8)

/* MODE1[2:0]: DAC channel1 mode */
#define DAC_MCR_MODE1_SHIFT		0
/** @defgroup dac_mode1_sel DAC Channel 1 Mode Selection
@ingroup dac_defines

@li E_BUFF: External pin with buffer enabled
@li EP_BUFF: External pin and on-chip peripherals with buffer
@li E: External pin without buffer
@li EP: External pin and on-chip peripherals without buffer
@li SH_E_BUFF: Sample & Hold, External pin with buffer enabled
@li SH_EP_BUFF: Sample & Hold, External pin and on-chip peripherals with buffer
@li SH_E: Sample & Hold, External pin without buffer
@li SH_EP: Sample & Hold , External pin and on-chip peripherals without buffer
@{*/
#define DAC_MCR_MODE1_E_BUFF		(0x0 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_EP_BUFF		(0x1 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_E			(0x2 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_EP		(0x3 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_SH_E_BUFF		(0x4 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_SH_EP_BUFF	(0x5 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_SH_E		(0x6 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_SH_EP		(0x7 << DAC_MCR_MODE1_SHIFT)
/**@}*/

#define DAC_MCR_MODE1_PERIPHERAL	(0x1 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_UNBUFFERED	(0x2 << DAC_MCR_MODE1_SHIFT)
#define DAC_MCR_MODE1_SAMPLEHOLD	(0x4 << DAC_MCR_MODE1_SHIFT)

/* --- DAC_SHSR1 values ----------------------------------------------------- */

/* DAC channel1 sample time (only valid in Sample and hold mode) */
#define DAC_SHSR1_TSAMPLE1_LSB		(1 << 0)
#define DAC_SHSR1_TSAMPLE1_MSK		(0x1FF << 16)

/* --- DAC_SHSR2 values ----------------------------------------------------- */

/* DAC channel2 sample time (only valid in Sample and hold mode) */
#define DAC_SHSR2_TSAMPLE2_LSB		(1 << 0)
#define DAC_SHSR2_TSAMPLE2_MSK		(0x1FF << 0)

/* --- DAC_SHHR values ----------------------------------------------------- */

/* DAC channel2 hold time (only valid in Sample and hold mode) */
#define DAC_SHHSR_THOLD2_LSB		(1 << 16)
#define DAC_SHHSR_THOLD2_MSK		(0x1FF << 16)

/* DAC channel1 hold time (only valid in Sample and hold mode) */
#define DAC_SHHSR_THOLD1_LSB		(1 << 0)
#define DAC_SHHSR_THOLD1_MSK		(0x1FF << 0)

/* --- DAC_STR1 values ----------------------------------------------------- */

/* DAC channel1 sawtooth increment value (12.4 bit format) */
#define DAC_STR1_STINCDATA1_LSB		(1 << 16)
#define DAC_STR1_STINCDATA1_MSK		(0xFFFF << 16)

/* STDIR1: DAC channel1 sawtooth direction setting */
#define DAC_STR1_STDIR1_SHIFT		12
/** @defgroup dac_stdir1 DAC Channel 1 Sawtooth Direction Setting
@ingroup dac_defines

@li DEC: Decrement
@li INC: Increment
@{*/
#define DAC_STR1_STDIR1_DEC		(0x0 << DAC_STR_STDIR1_SHIFT)
#define DAC_STR1_STDIR1_INC		(0x1 << DAC_STR_STDIR1_SHIFT)
/**@}*/

/* DAC channel1 sawtooth reset value */
#define DAC_STR1_STRSTDATA1_LSB		(1 << 0)
#define DAC_STR1_STRSTDATA1_MSK		(0xFFF << 0)

/* --- DAC_STR2 values ----------------------------------------------------- */

/* DAC channel2 sawtooth increment value (12.4 bit format) */
#define DAC_STR2_STINCDATA2_LSB		(1 << 16)
#define DAC_STR2_STINCDATA2_MSK		(0xFFFF << 16)

/* STDIR1: DAC channel2 sawtooth direction setting */
#define DAC_STR2_STDIR2_SHIFT		12
/** @defgroup dac_stdir2 DAC Channel 2 Sawtooth Direction Setting
@ingroup dac_defines

@li DEC: Decrement
@li INC: Increment
@{*/
#define DAC_STR2_STDIR2_DEC		(0x0 << DAC_STR_STDIR2_SHIFT)
#define DAC_STR2_STDIR2_INC		(0x1 << DAC_STR_STDIR2_SHIFT)
/**@}*/

/* DAC channel1 sawtooth reset value */
#define DAC_STR2_STRSTDATA2_LSB		(1 << 0)
#define DAC_STR2_STRSTDATA2_MSK		(0xFFF << 0)

/* --- DAC_STMODR values ----------------------------------------------------- */

/* STINCTRIGSEL2[3:0]: DAC channel2 sawtooth increment trigger selection */
#define DAC_STMODR_STINCTRIGSEL2_SHIFT	24
/** @defgroup dac_sawtooth2_inc DAC Channel 2 Sawtooth Increment Trigger
@ingroup dac_defines

@li SW: SWTRIGB2
@li T1: dac_inc_ch2_trg1
@li T2: dac_inc_ch2_trg2
@li T3: dac_inc_ch2_trg3
@li T4: dac_inc_ch2_trg4
@li T5: dac_inc_ch2_trg5
@li T6: dac_inc_ch2_trg6
@li T7: dac_inc_ch2_trg7
@li T8: dac_inc_ch2_trg8
@li T9: dac_inc_ch2_trg9
@li T10: dac_inc_ch2_trg10
@li T11: dac_inc_ch2_trg11
@li T12: dac_inc_ch2_trg12
@li T13: dac_inc_ch2_trg13
@li T14: dac_inc_ch2_trg14
@li T15: dac_inc_ch2_trg15

@note: These bits are only available only on dual-channel DACs.
@{*/
#define DAC_STMODR_STINCTRIGSEL2_SW	(0x0 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T1	(0x1 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T2	(0x2 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T3	(0x3 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T4	(0x4 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T5	(0x5 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T6	(0x6 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T7	(0x7 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T8	(0x8 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T9	(0x9 << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T10	(0xA << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T11	(0xB << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T12	(0xC << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T13	(0xD << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T14	(0xE << DAC_STMODR_STINCTRIGSEL2_SHIFT)
#define DAC_STMODR_STINCTRIGSEL2_T15	(0xF << DAC_STMODR_STINCTRIGSEL2_SHIFT)
/**@}*/

/* STRSTTRIGSEL2[3:0]: DAC channel2 sawtooth reset trigger selection */
#define DAC_STMODR_STRSTTRIGSEL2_SHIFT	16
/** @defgroup dac_sawtooth2_rst DAC Channel 2 Sawtooth Reset Trigger
@ingroup dac_defines

@li SW: SWTRIGB2
@li T1: dac_ch2_trg1
@li T2: dac_ch2_trg2
@li T3: dac_ch2_trg3
@li T4: dac_ch2_trg4
@li T5: dac_ch2_trg5
@li T6: dac_ch2_trg6
@li T7: dac_ch2_trg7
@li T8: dac_ch2_trg8
@li T9: dac_ch2_trg9
@li T10: dac_ch2_trg10
@li T11: dac_ch2_trg11
@li T12: dac_ch2_trg12
@li T13: dac_ch2_trg13
@li T14: dac_ch2_trg14
@li T15: dac_ch2_trg15

@note: These bits are only available only on dual-channel DACs.
@{*/
#define DAC_STMODR_STRSTTRIGSEL2_SW	(0x0 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T1	(0x1 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T2	(0x2 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T3	(0x3 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T4	(0x4 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T5	(0x5 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T6	(0x6 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T7	(0x7 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T8	(0x8 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T9	(0x9 << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T10	(0xA << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T11	(0xB << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T12	(0xC << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T13	(0xD << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T14	(0xE << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL2_T15	(0xF << DAC_STMODR_STRSTTRIGSEL2_SHIFT)
/**@}*/


/* STINCTRIGSEL1[3:0]: DAC channel1 sawtooth increment trigger selection */
#define DAC_STMODR_STINCTRIGSEL1_SHIFT	8
/** @defgroup dac_sawtooth2_inc DAC Channel 1 Sawtooth Increment Trigger
@ingroup dac_defines

@li SW: SWTRIGB2
@li T1: dac_inc_ch1_trg1
@li T2: dac_inc_ch1_trg2
@li T3: dac_inc_ch1_trg3
@li T4: dac_inc_ch1_trg4
@li T5: dac_inc_ch1_trg5
@li T6: dac_inc_ch1_trg6
@li T7: dac_inc_ch1_trg7
@li T8: dac_inc_ch1_trg8
@li T9: dac_inc_ch1_trg9
@li T10: dac_inc_ch1_trg10
@li T11: dac_inc_ch1_trg11
@li T12: dac_inc_ch1_trg12
@li T13: dac_inc_ch1_trg13
@li T14: dac_inc_ch1_trg14
@li T15: dac_inc_ch1_trg15

@note: These bits are only available only on dual-channel DACs.
@{*/
#define DAC_STMODR_STINCTRIGSEL1_SW	(0x0 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T1	(0x1 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T2	(0x2 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T3	(0x3 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T4	(0x4 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T5	(0x5 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T6	(0x6 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T7	(0x7 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T8	(0x8 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T9	(0x9 << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T10	(0xA << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T11	(0xB << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T12	(0xC << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T13	(0xD << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T14	(0xE << DAC_STMODR_STINCTRIGSEL1_SHIFT)
#define DAC_STMODR_STINCTRIGSEL1_T15	(0xF << DAC_STMODR_STINCTRIGSEL1_SHIFT)
/**@}*/

/* STRSTTRIGSEL1[3:0]: DAC channel1 sawtooth reset trigger selection */
#define DAC_STMODR_STRSTTRIGSEL1_SHIFT	0
/** @defgroup dac_sawtooth2_rst DAC Channel 1 Sawtooth Reset Trigger
@ingroup dac_defines

@li SW: SWTRIGB2
@li T1: dac_ch1_trg1
@li T2: dac_ch1_trg2
@li T3: dac_ch1_trg3
@li T4: dac_ch1_trg4
@li T5: dac_ch1_trg5
@li T6: dac_ch1_trg6
@li T7: dac_ch1_trg7
@li T8: dac_ch1_trg8
@li T9: dac_ch1_trg9
@li T10: dac_ch1_trg10
@li T11: dac_ch1_trg11
@li T12: dac_ch1_trg12
@li T13: dac_ch1_trg13
@li T14: dac_ch1_trg14
@li T15: dac_ch1_trg15

@note: These bits are only available only on dual-channel DACs.
@{*/
#define DAC_STMODR_STRSTTRIGSEL1_SW	(0x0 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T1	(0x1 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T2	(0x2 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T3	(0x3 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T4	(0x4 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T5	(0x5 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T6	(0x6 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T7	(0x7 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T8	(0x8 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T9	(0x9 << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T10	(0xA << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T11	(0xB << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T12	(0xC << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T13	(0xD << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T14	(0xE << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
#define DAC_STMODR_STRSTTRIGSEL1_T15	(0xF << DAC_STMODR_STRSTTRIGSEL1_SHIFT)
/**@}*/

/** DAC channel identifier */
#define DAC_CHANNEL1			1
#define DAC_CHANNEL2			2
#define DAC_CHANNEL_COUNT		2
#define DAC_CHANNEL_BOTH		(DAC_CHANNEL1 | DAC_CHANNEL2)

/** DAC data size (8/12 bits), alignment (right/left) */
typedef enum {
	DAC_RIGHT8, DAC_RIGHT12, DAC_LEFT12
} dac_data_align_t;

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dac_enable(uint32_t dac, uint8_t channel);
void dac_disable(uint32_t dac, uint8_t channel);
void dac_buffer_enable(uint32_t dac, uint8_t channel);
void dac_buffer_disable(uint32_t dac, uint8_t channel);
void dac_set_mode(uint32_t dac, uint32_t mode);
void dac_dma_enable(uint32_t dac, uint8_t channel);
void dac_dma_disable(uint32_t dac, uint8_t channel);
void dac_trigger_enable(uint32_t dac, uint8_t channel);
void dac_trigger_disable(uint32_t dac, uint8_t channel);
void dac_set_trigger_source(uint32_t dac, uint32_t dac_trig_src);
void dac_set_waveform_generation(uint32_t dac, uint32_t dac_wave_ens);
void dac_disable_waveform_generation(uint32_t dac, uint8_t channel);
void dac_set_waveform_characteristics(uint32_t dac, uint32_t dac_mamp);
bool dac_is_ready(uint32_t dac, uint8_t channel);
void dac_wait_on_ready(uint32_t dac, uint8_t channel);
void dac_load_data_buffer_single(uint32_t dac, uint16_t dac_data,
                                 dac_data_align_t data_format,
				 uint8_t channel);
void dac_load_data_buffer_dual(uint32_t dac,
                               uint16_t dac_data1, uint16_t dac_data2,
			       dac_data_align_t data_format);
void dac_software_trigger(uint32_t dac, uint8_t channel);
void dac_set_high_frequency_mode(uint32_t dac, uint32_t hfsel);

END_DECLS

#endif

/**@}*/

