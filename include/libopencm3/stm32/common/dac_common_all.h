/** @addtogroup dac_defines

@author @htmlonly &copy; @endhtmlonly 2012
Felix Held <felix-libopencm3@felixheld.de>
@author @htmlonly &copy; @endhtmlonly 2020
Ben Brewer <ben.brewer@codethink.co.uk>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Felix Held <felix-libopencm3@felixheld.de>
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
#ifndef LIBOPENCM3_DAC_COMMON_ALL_H
#define LIBOPENCM3_DAC_COMMON_ALL_H

/**@defgroup dac_registers DAC Registers
 @{*/

/** DAC control register (DAC_CR) */
#define DAC_CR(dac)			MMIO32((dac) + 0x00)

/** DAC software trigger register (DAC_SWTRIGR) */
#define DAC_SWTRIGR(dac)		MMIO32((dac) + 0x04)

/** DAC channel1 12-bit right-aligned data holding register (DAC_DHR12R1) */
#define DAC_DHR12R1(dac)		MMIO32((dac) + 0x08)

/** DAC channel1 12-bit left aligned data holding register (DAC_DHR12L1) */
#define DAC_DHR12L1(dac)		MMIO32((dac) + 0x0C)

/** DAC channel1 8-bit right aligned data holding register (DAC_DHR8R1) */
#define DAC_DHR8R1(dac)			MMIO32((dac) + 0x10)

/** DAC channel2 12-bit right aligned data holding register (DAC_DHR12R2) */
#define DAC_DHR12R2(dac)		MMIO32((dac) + 0x14)

/** DAC channel2 12-bit left aligned data holding register (DAC_DHR12L2) */
#define DAC_DHR12L2(dac)		MMIO32((dac) + 0x18)

/** DAC channel2 8-bit right-aligned data holding register (DAC_DHR8R2) */
#define DAC_DHR8R2(dac)			MMIO32((dac) + 0x1C)

/** Dual DAC 12-bit right-aligned data holding register (DAC_DHR12RD) */
#define DAC_DHR12RD(dac)		MMIO32((dac) + 0x20)

/** DUAL DAC 12-bit left aligned data holding register (DAC_DHR12LD) */
#define DAC_DHR12LD(dac)		MMIO32((dac) + 0x24)

/** DUAL DAC 8-bit right aligned data holding register (DAC_DHR8RD) */
#define DAC_DHR8RD(dac)			MMIO32((dac) + 0x28)

/** DAC channel1 data output register (DAC_DOR1) */
#define DAC_DOR1(dac)			MMIO32((dac) + 0x2C)

/** DAC channel2 data output register (DAC_DOR2) */
#define DAC_DOR2(dac)			MMIO32((dac) + 0x30)

/** DAC status register.
 * @note not available on F1
 */
#define DAC_SR(dac)			MMIO32((dac) + 0x34)

/**@}*/

/** @defgroup dac_cr_values DAC_CR values
 * @{
 */

/** DMAUDRIE2: DAC channel2 DMA underrun interrupt enable
 * @note doesn't exist in most members of the STM32F1 family
 */
#define DAC_CR_DMAUDRIE2		(1 << 29)

/** DMAEN2: DAC channel2 DMA enable */
#define DAC_CR_DMAEN2			(1 << 28)

/** MAMP2[3:0]: DAC channel2 mask/amplitude selector field position */
#define DAC_CR_MAMP2_SHIFT		24

/** Wave generation mode mask size */
#define DAC_CR_WAVEx_MASK		0x3

/** WAVE2[1:0]: DAC channel2 wave generation mode*/
#define DAC_CR_WAVE2_SHIFT		22

/** EN2: DAC channel2 enable */
#define DAC_CR_EN2			(1 << 16)

/** DMAUDRIE1: DAC channel1 DMA underrun interrupt enable
 * @note doesn't exist in most members of the STM32F1 family
 */
#define DAC_CR_DMAUDRIE1		(1 << 13)

/** DMAEN1: DAC channel1 DMA enable */
#define DAC_CR_DMAEN1			(1 << 12)

/** MAMP1[3:0]: DAC channel1 mask/amplitude selector field position */
#define DAC_CR_MAMP1_SHIFT		8
/** MAMP Mask/Amplitude selector field size */
#define DAC_CR_MAMPx_MASK		0xf

/** WAVE1[1:0]: DAC channel1 wave generation mode */
#define DAC_CR_WAVE1_SHIFT		6

/** EN1: DAC channel1 enable */
#define DAC_CR_EN1			(1 << 0)
/**@}*/

/**@defgroup dac_swtrigr_values DAC_SWTRIGR Values
 * @{
 */
/** SWTRIG2: DAC channel2 software trigger */
#define DAC_SWTRIGR_SWTRIG2		(1 << 1)

/** SWTRIG1: DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG1		(1 << 0)
/**@}*/


/**@defgroup dac_dhrxxx_values DAC_DHRxxx Values
 * @{
 */
/* --- DAC_DHR12R1 values -------------------------------------------------- */
#define DAC_DHR12R1_DACC1DHR_SHIFT	0
#define DAC_DHR12R1_DACC1DHR_MASK	0xFFF


/* --- DAC_DHR12L1 values -------------------------------------------------- */
#define DAC_DHR12L1_DACC1DHR_SHIFT	4
#define DAC_DHR12L1_DACC1DHR_MASK	0xFFF


/* --- DAC_DHR8R1 values --------------------------------------------------- */
#define DAC_DHR8R1_DACC1DHR_SHIFT	0
#define DAC_DHR8R1_DACC1DHR_MASK	0xFF


/* --- DAC_DHR12R2 values -------------------------------------------------- */
#define DAC_DHR12R2_DACC2DHR_SHIFT	0
#define DAC_DHR12R2_DACC2DHR_MASK	0xFFF


/* --- DAC_DHR12L2 values -------------------------------------------------- */
#define DAC_DHR12L2_DACC2DHR_SHIFT	4
#define DAC_DHR12L2_DACC2DHR_MASK	0xFFF


/* --- DAC_DHR8R2 values --------------------------------------------------- */
#define DAC_DHR8R2_DACC2DHR_SHIFT	0
#define DAC_DHR8R2_DACC2DHR_MASK	0xFF


/* --- DAC_DHR12RD values -------------------------------------------------- */
#define DAC_DHR12RD_DACC2DHR_SHIFT	16
#define DAC_DHR12RD_DACC2DHR_MASK	0xFFF
#define DAC_DHR12RD_DACC1DHR_SHIFT	0
#define DAC_DHR12RD_DACC1DHR_MSK	0xFFF


/* --- DAC_DHR12LD values -------------------------------------------------- */
#define DAC_DHR12LD_DACC2DHR_SHIFT	16
#define DAC_DHR12LD_DACC2DHR_MSK	0xFFF
#define DAC_DHR12LD_DACC1DHR_SHIFT	0
#define DAC_DHR12LD_DACC1DHR_MSK	0xFFF


/* --- DAC_DHR8RD values --------------------------------------------------- */
#define DAC_DHR8RD_DACC2DHR_SHIFT	8
#define DAC_DHR8RD_DACC2DHR_MSK		0xFF
#define DAC_DHR8RD_DACC1DHR_SHIFT	0
#define DAC_DHR8RD_DACC1DHR_MSK		0xFF
/**@}*/


/**@defgroup dac_dorx_values DAC_DORx Values
 * @{
 */
/* --- DAC_DOR1 values ----------------------------------------------------- */
#define DAC_DOR1_DACC1DOR_SHIFT		0
#define DAC_DOR1_DACC1DOR_MSK		0xFFF


/* --- DAC_DOR2 values ----------------------------------------------------- */
#define DAC_DOR2_DACC2DOR_SHIFT		0
#define DAC_DOR2_DACC2DOR_MSK		0xFFF

/**@}*/

/**@defgroup dac_sr_values DAC_SR Values
 * @{
 */
/** DAC channel 1 DMA underrun flag */
#define DAC_SR_DMAUDR1			(1 << 13)

/** DAC channel 2 DMA underrun flag */
#define DAC_SR_DMAUDR2			(1 << 29)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

/** @defgroup dac_channel_id DAC Channel Identifier
 * @note Not all parts have two channels, notably, some of the smaller F0's
 * @{
 */
#define DAC_CHANNEL1		(1 << 0)
#define DAC_CHANNEL2		(1 << 1)
#define DAC_CHANNEL_BOTH	(DAC_CHANNEL1 | DAC_CHANNEL2)
/**@}*/

/** DAC data size (8/12 bits), alignment (right/left) */
enum dac_align {
	DAC_ALIGN_RIGHT8,
	DAC_ALIGN_RIGHT12,
	DAC_ALIGN_LEFT12,
};

/** DAC waveform generation options.
 * Not all wave shapes are available on all parts.
 */
enum dac_wave {
	DAC_WAVE_DISABLE  = 0,
	DAC_WAVE_NOISE    = 1,
	DAC_WAVE_TRIANGLE = 2,
	DAC_WAVE_SAWTOOTH = 3,
};

BEGIN_DECLS

void dac_enable(uint32_t dac, int channel);
void dac_disable(uint32_t dac, int channel);
void dac_buffer_enable(uint32_t dac, int channel);
void dac_buffer_disable(uint32_t dac, int channel);
void dac_dma_enable(uint32_t dac, int channel);
void dac_dma_disable(uint32_t dac, int channel);
void dac_trigger_enable(uint32_t dac, int channel);
void dac_trigger_disable(uint32_t dac, int channel);
void dac_set_trigger_source(uint32_t dac, uint32_t source);
void dac_set_waveform_generation(uint32_t dac, int channel, enum dac_wave wave);
void dac_disable_waveform_generation(uint32_t dac, int channel);
void dac_set_waveform_characteristics(uint32_t dac, int channel, int mamp);
void dac_load_data_buffer_single(uint32_t dac, uint16_t data,
                                 enum dac_align align, int channel);
void dac_load_data_buffer_dual(uint32_t dac, uint16_t data1, uint16_t data2,
			       enum dac_align align);
void dac_software_trigger(uint32_t dac, int channel);

END_DECLS

#endif
/** @cond */
#else
#warning "dac_common_all.h should not be included explicitly, only via dac.h"
#endif
/** @endcond */

/**@}*/

