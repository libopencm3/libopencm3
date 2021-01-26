/** @addtogroup dac_defines

@author @htmlonly &copy; @endhtmlonly 2020
Ben Brewer <ben.brewer@codethink.co.uk>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Ben Brewer <ben.brewer@codethink.co.uk>
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

/**@{*/

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DAC.H
The order of header inclusion is important. dac.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_DAC_H
/** @endcond */
#ifndef LIBOPENCM3_DAC_COMMON_V2_H
#define LIBOPENCM3_DAC_COMMON_V2_H

#include <libopencm3/stm32/common/dac_common_all.h>

/**@addtogroup dac_registers
 @{*/

/** DAC calibration control register (DAC_CCR) */
#define DAC_CCR(dac)			MMIO32((dac) + 0x38)

/** DAC mode control register (DAC_MCR) */
#define DAC_MCR(dac)			MMIO32((dac) + 0x3C)

/** DAC channel1 sample and hold sample time register (DAC_SHSR1) */
#define DAC_SHSR1(dac)			MMIO32((dac) + 0x40)

/** DAC channel2 sample and hold sample time register (DAC_SHSR2) */
#define DAC_SHSR2(dac)			MMIO32((dac) + 0x44)

/** DAC sample and hold time register (DAC_SHHR) */
#define DAC_SHHR(dac)			MMIO32((dac) + 0x48)

/** DAC sample and hold refresh time register (DAC_SHRR) */
#define DAC_SHRR(dac)			MMIO32((dac) + 0x4C)

/** DAC channel1 sawtooth register (DAC_STR1) */
#define DAC_STR1(dac)			MMIO32((dac) + 0x58)

/** DAC channel2 sawtooth register (DAC_STR2) */
#define DAC_STR2(dac)			MMIO32((dac) + 0x5C)

/** DAC sawtooth mode register (DAC_STMODR) */
#define DAC_STMODR(dac)			MMIO32((dac) + 0x60)
/**@}*/

/**@addtogroup dac_cr_values
 * @{
 */

/** CEN2: DAC channel2 calibration enable */
#define DAC_CR_CEN2			(1 << 30)

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

/* CEN1: DAC channel1 calibration enable */
#define DAC_CR_CEN1			(1 << 14)

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

@note: only used if bit TEN1 is set (DAC channel 1 trigger enabled).
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

/** TEN1: DAC channel1 trigger enable */
#define DAC_CR_TEN1			(1 << 1)
/**@}*/


/** @addtogroup dac_swtrigr_values
 * @{
 */
/** SWTRIG2: DAC channel2 software trigger B */
#define DAC_SWTRIGR_SWTRIGB2		(1 << 17)

/** SWTRIG1: DAC channel1 software trigger B */
#define DAC_SWTRIGR_SWTRIGB1		(1 << 16)
/**@}*/

/** @addtogroup dac_dorx_values
 * @{
 */
/* --- DAC_DOR1 values ----------------------------------------------------- */
#define DAC_DOR1_DACC1DORB_SHIFT	16
#define DAC_DOR1_DACC1DORB_MASK		0xFFF


/* --- DAC_DOR2 values ----------------------------------------------------- */
#define DAC_DOR2_DACC2DORB_SHIFT	16
#define DAC_DOR2_DACC2DORB_MASK		0xFFF
/**@}*/

/** @addtogroup dac_sr_values
 * @{
 */
/** DAC channel2 busy writing sample time flag */
#define DAC_SR_BWST2			(1 << 31)

/** DAC channel2 calibration offset status */
#define DAC_SR_CAL_FLAG2		(1 << 30)

/** DAC channel2 DMA underrun flag */
#define DAC_SR_DMAUDR2			(1 << 29)

/** DAC channel2 output register status bit */
#define DAC_SR_DORSTAT2			(1 << 28)

/** DAC channel2 ready status bit */
#define DAC_SR_DAC2RDY			(1 << 27)

/** DAC channel1 busy writing sample time flag */
#define DAC_SR_BWST1			(1 << 15)

/** DAC channel1 calibration offset status */
#define DAC_SR_CAL_FLAG1		(1 << 14)

/** DAC channel1 DMA underrun flag */
#define DAC_SR_DMAUDR1			(1 << 13)

/** DAC channel1 output register status bit */
#define DAC_SR_DORSTAT1			(1 << 12)

/** DAC channel1 ready status bit */
#define DAC_SR_DAC1RDY			(1 << 11)
/**@}*/


/**@defgroup dac_ccr_values DAC_CCR values
 * @{
 */
/* DAC channel2 offset trimming value */
#define DAC_CCR_OTRIM2_SHIFT		16
#define DAC_CCR_OTRIM2_MASK		0x1F

/* DAC channel1 offset trimming value */
#define DAC_CCR_OTRIM1_SHIFT		0
#define DAC_CCR_OTRIM1_MASK		0x1F
/**@}*/

/* --- DAC_MCR values ----------------------------------------------------- */

/**@defgroup dac_mcr_values DAC_MCR values
 * @{
 */
/** Enable signed format for DAC channel2 */
#define DAC_MCR_SINFORMAT2		(1 << 25)

/** DAC channel2 DMA double data mode */
#define DAC_MCR_DMADOUBLE2		(1 << 24)

/** MODE2[2:0]: DAC channel2 mode */
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
@li SH_EP: Sample & Hold, External pin and on-chip peripherals without buffer
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

/** Enable signed format for DAC channel1 */
#define DAC_MCR_SINFORMAT1		(1 << 9)

/** DAC channel1 DMA double data mode */
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
/**@}*/

/* --- DAC_SHSR1 values ----------------------------------------------------- */

/* DAC channel1 sample time (only valid in Sample and hold mode) */
#define DAC_SHSR1_TSAMPLE1_SHIFT	0
#define DAC_SHSR1_TSAMPLE1_MASK		0x1FF

/* --- DAC_SHSR2 values ----------------------------------------------------- */

/* DAC channel2 sample time (only valid in Sample and hold mode) */
#define DAC_SHSR2_TSAMPLE2_SHIFT	0
#define DAC_SHSR2_TSAMPLE2_MASK		0x1FF

/* --- DAC_SHHR values ----------------------------------------------------- */

/* DAC channel2 hold time (only valid in Sample and hold mode) */
#define DAC_SHHSR_THOLD2_SHIFT		16
#define DAC_SHHSR_THOLD2_MASK		0x1FF

/* DAC channel1 hold time (only valid in Sample and hold mode) */
#define DAC_SHHSR_THOLD1_SHIFT		0
#define DAC_SHHSR_THOLD1_MASK		0x1FF

/* --- DAC_STR1 values ----------------------------------------------------- */

/* DAC channel1 sawtooth increment value (12.4 bit format) */
#define DAC_STR1_STINCDATA1_SHIFT	16
#define DAC_STR1_STINCDATA1_MASK	0xFFFF

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
#define DAC_STR1_STRSTDATA1_SHIFT	0
#define DAC_STR1_STRSTDATA1_MASK	0xFFF

/* --- DAC_STR2 values ----------------------------------------------------- */

/* DAC channel2 sawtooth increment value (12.4 bit format) */
#define DAC_STR2_STINCDATA2_SHIFT	16
#define DAC_STR2_STINCDATA2_MASK	0xFFFF

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
#define DAC_STR2_STRSTDATA2_SHIFT	0
#define DAC_STR2_STRSTDATA2_MASK	0xFFF

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
/** @defgroup dac_sawtooth1_inc DAC Channel 1 Sawtooth Increment Trigger
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
/** @defgroup dac_sawtooth1_rst DAC Channel 1 Sawtooth Reset Trigger
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

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dac_set_mode(uint32_t dac, uint32_t mode);
bool dac_is_ready(uint32_t dac, int channel);
void dac_wait_on_ready(uint32_t dac, int channel);
void dac_set_high_frequency_mode(uint32_t dac, uint32_t hfsel);

END_DECLS

#endif
/** @cond */
#else
#warning "dac_common_v2.h should not be included explicitly, only via dac.h"
#endif
/** @endcond */

/**@}*/

