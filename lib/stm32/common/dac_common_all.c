/** @addtogroup dac_file DAC peripheral API
 * @ingroup peripheral_apis
 * @brief Digital to Analog Converter

@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly 2020 Ben Brewer <ben.brewer@codethink.co.uk>

This library supports the Digital to Analog Conversion System in the
STM32 series of ARM Cortex Microcontrollers by ST Microelectronics.

The DAC peripheral found on many of the devices in the STM32 lineup,
sometimes with only one channel, but normally with two channels.

Two DAC channels are available, however unlike the ADC channels these
are separate DAC devices controlled by the same register block.

The DAC is on APB1. Its clock must be enabled in RCC and depending on
specific family, the GPIO
ports set to alternate function output before it can be used.
On most families, the GPIO pins should be configured to Analog IN to
avoid parasitic consumption.
The digital output driver is disabled so the output driver mode
(push-pull/open drain) is arbitrary.

The DAC has a holding (buffer) register and an output register from
which the analog output is derived. The holding register must be
loaded first. If triggering is enabled the output register is loaded
from the holding register after a trigger occurs. If triggering is
not enabled the holding register contents are transferred directly
to the output register.

@note To avoid nonlinearities, do not allow outputs to range close
to zero or V_analog.

@section dac_api_dual Dual Channel Conversion

There are dual modes in which both DACs are used to output data
simultaneously or independently on both channels. The data must be
presented according to the formats described in the datasheets. A
convenience function @ref dac_load_data_buffer_dual is provided
for software controlled use.

A variety of modes are available depending on whether independent
or simultaneous output is desired, and whether waveforms are to be
superimposed. Refer to the datasheets.

If DMA is used, only enable it for one of the channels. The DMA
requests will then serve data in dual format to the data register
dedicated to dual mode. The data will then be split and loaded to the
appropriate DAC following the next trigger. There are three registers
available, one for each of the formats: 12 bit right-aligned, 12 bit
left-aligned and 8 bit right-aligned. The desired format is determined
by specifying the appropriate register to the DMA controller.

@section dac_api_basic_ex Basic DAC handling API.

Set the DAC's GPIO port to Analog IN. Enable the
DAC clock. Enable the DAC, set a trigger source and load the buffer
with the first value. After the DAC is triggered, load the buffer with
the next value. This example uses software triggering and added noise.
The trigger and further buffer load calls are made when data is to be
sent out.

@code
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO4);
	rcc_periph_clock_enable(RCC_DAC);
	dac_disable(DAC1, DAC_CHANNEL1);
	dac_set_waveform_characteristics(DAC1, DAC_CR_MAMP1_8);
	dac_set_waveform_generation(DAC1, DAC_CR_WAVE1_NOISE);
	dac_enable(DAC1, DAC_CHANNEL1);
	dac_set_trigger_source(DAC1, DAC_CR_TSEL1_SW);
	dac_load_data_buffer_single(DAC1, 0, DAC_ALIGN_RIGHT12, DAC_CHANNEL1);
	....
	dac_software_trigger(DAC1, DAC_CHANNEL1);
	dac_load_data_buffer_single(DAC1, value,
	                            DAC_ALIGN_RIGHT12, DAC_CHANNEL1);
@endcode

@section dac_api_dma_ex Simultaneous Dual DAC with DMA.

This example in part sets up the DAC channel 1 DMA (DMA2 channel 3) to read
16 bit data from memory into the right-aligned 8 bit dual register DAC_DHR8RD.
Both DAC channels are enabled, and both triggers are set to the same timer
2 input as required for simultaneous operation. DMA is enabled for DAC channel
1 only to ensure that only one DMA request is generated.

@code
	dma_set_memory_size(DMA2, DMA_CHANNEL3, DMA_CCR_MSIZE_16BIT);
	dma_set_peripheral_size(DMA2, DMA_CHANNEL3, DMA_CCR_PSIZE_16BIT);
	dma_set_read_from_memory(DMA2, DMA_CHANNEL3);
	dma_set_peripheral_address(DMA2, DMA_CHANNEL3,(uint32_t) &DAC_DHR8RD);
	dma_enable_channel(DMA2, DMA_CHANNEL3);
	...
	dac_trigger_enable(DAC1, DAC_CHANNEL_BOTH);
	dac_set_trigger_source(DAC1, DAC_CR_TSEL1_T2 | DAC_CR_TSEL2_T2);
	dac_dma_enable(DAC1, DAC_CHANNEL1);
	dac_enable(DAC1, DAC_CHANNEL_BOTH);
@endcode

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies
 * Copyright (C) 2020 Ben Brewer
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

#include <libopencm3/stm32/dac.h>

/** @brief DAC Channel Enable.

Enable a digital to analog converter channel. After setting this enable, the
DAC requires a t<sub>wakeup</sub> time typically around 10 microseconds before
it actually wakes up.

@param[in] dac the base address of the DAC @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_enable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) |= DAC_CR_EN1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) |= DAC_CR_EN2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) |= (DAC_CR_EN1 | DAC_CR_EN2);
		break;
	}
}

/** @brief DAC Channel Disable.

Disable a digital to analog converter channel.

@param[in] dac the base address of the DAC @ref dac_reg_base
@param[in] channel with DAC mask @ref dac_channel_id
*/
void dac_disable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) &= ~DAC_CR_EN1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) &= ~DAC_CR_EN2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) &= ~(DAC_CR_EN1 | DAC_CR_EN2);
		break;
	default:
		break;
	}
}

/** @brief DAC Channel DMA Enable.

Enable a digital to analog converter channel DMA mode (connected to DMA2 channel
3 for DAC channel 1 and DMA2 channel 4 for DAC channel 2). A DMA request is
generated following an external trigger.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_dma_enable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) |= DAC_CR_DMAEN1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) |= DAC_CR_DMAEN2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) |= (DAC_CR_DMAEN1 | DAC_CR_DMAEN2);
		break;
	default:
		break;
	}
}

/** @brief DAC Channel DMA Disable.

Disable a digital to analog converter channel DMA mode.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_dma_disable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) &= ~DAC_CR_DMAEN1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) &= ~DAC_CR_DMAEN2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) &= ~(DAC_CR_DMAEN1 | DAC_CR_DMAEN2);
		break;
	default:
		break;
	}
}

/** @brief DAC Channel Trigger Enable.

Enable a digital to analog converter channel external trigger mode. This allows
an external trigger to initiate register transfers from the buffer register to
the DAC output register, followed by a DMA transfer to the buffer register if
DMA is enabled.  The trigger source must also be selected.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_trigger_enable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) |= DAC_CR_TEN1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) |= DAC_CR_TEN2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) |= (DAC_CR_TEN1 | DAC_CR_TEN2);
		break;
	default:
		break;
	}
}

/** @brief DAC Channel Trigger Disable.

Disable a digital to analog converter channel external trigger.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_trigger_disable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) &= ~DAC_CR_TEN1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) &= ~DAC_CR_TEN2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) &= ~(DAC_CR_TEN1 | DAC_CR_TEN2);
		break;
	default:
		break;
	}
}

/** @brief Set DAC Channel Trigger Source.

Sets the digital to analog converter trigger source, which can be taken from
various timers, an external trigger or a software trigger.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] source Taken from @ref dac_trig2_sel or @ref
dac_trig1_sel or a logical OR of one of each of these to set both channels
simultaneously.
*/
void dac_set_trigger_source(uint32_t dac, uint32_t source)
{
	DAC_CR(dac) |= source;
}

/** @brief Enable and Set DAC Channel Waveform Generation.

Enable the digital to analog converter waveform generation as either
pseudo-random noise or triangular wave. These signals are superimposed on
existing output values in the DAC output registers.

@note The DAC trigger must be enabled for this to work.
@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] wave enum ::dac_wave. Taken from @ref dac_wave1_en or @ref
dac_wave2_en or a logical OR of one of each of these to set both channels
simultaneously.
*/
void dac_set_waveform_generation(uint32_t dac, enum dac_wave wave)
{
	DAC_CR(dac) |= wave;
}

/** @brief Disable DAC Channel Waveform Generation.

Disable a digital to analog converter channel superimposed waveform generation.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_disable_waveform_generation(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) &= ~(DAC_CR_WAVE1_MASK << DAC_CR_WAVE1_SHIFT);
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) &= ~(DAC_CR_WAVE2_MASK << DAC_CR_WAVE2_SHIFT);
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) &= ~(DAC_CR_WAVE1_MASK << DAC_CR_WAVE1_SHIFT)
				| ~(DAC_CR_WAVE2_MASK << DAC_CR_WAVE2_SHIFT);
		break;
	default:
		break;
	}
}

/** @brief Set DAC Channel LFSR Mask or Triangle Wave Amplitude.

Sets the digital to analog converter superimposed waveform generation
characteristics.  @li If the noise generation mode is set, this sets the length
of the PRBS sequence and hence the amplitude of the output noise signal.
Default setting is length 1.  @li If the triangle wave generation mode is set,
this sets the amplitude of the output signal as 2^(n)-1 where n is the
parameter value. Default setting is 1.

@note High amplitude levels of these waveforms can overload the DAC and distort
the signal output.
@note This must be called before enabling the DAC as the settings will then
become read-only.
@note The DAC trigger must be enabled for this to work.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] mamp uint8_t. Taken from @ref dac_mamp2 or @ref dac_mamp1 or a
logical OR of one of each of these to set both channels simultaneously.
*/
void dac_set_waveform_characteristics(uint32_t dac, uint8_t mamp)
{
	DAC_CR(dac) |= mamp;
}

/** @brief Load DAC Data Register.

Loads the appropriate digital to analog converter data register with 12 or 8 bit
data to be converted on a channel. The data can be aligned as follows:
@li right-aligned 8 bit data in bits 0-7
@li right-aligned 12 bit data in bits 0-11
@li left aligned 12 bit data in bits 4-15

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] data uint16_t with appropriate alignment.
@param[in] align enum ::dac_align. Alignment and size.
@param[in] channel uint8_t with DAC mask.
*/
void dac_load_data_buffer_single(uint32_t dac, uint16_t data,
		enum dac_align align,
		int channel)
{
	if (channel == DAC_CHANNEL1) {
		switch (align) {
		case DAC_ALIGN_RIGHT8:
			DAC_DHR8R1(dac) = data;
			break;
		case DAC_ALIGN_RIGHT12:
			DAC_DHR12R1(dac) = data;
			break;
		case DAC_ALIGN_LEFT12:
			DAC_DHR12L1(dac) = data;
			break;
		default:
			break;
		}
	} else if (channel == DAC_CHANNEL2) {
		switch (align) {
		case DAC_ALIGN_RIGHT8:
			DAC_DHR8R2(dac) = data;
			break;
		case DAC_ALIGN_RIGHT12:
			DAC_DHR12R2(dac) = data;
			break;
		case DAC_ALIGN_LEFT12:
			DAC_DHR12L2(dac) = data;
			break;
		default:
			break;
		}
	}
}

/** @brief Load DAC Dual Data Register.

Loads the appropriate digital to analog converter dual data register with 12 or
8 bit data to be converted for both channels. This allows high bandwidth
simultaneous or independent analog output. The data in both channels are aligned
identically.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] data1 uint16_t for channel 1 with appropriate alignment.
@param[in] data2 uint16_t for channel 2 with appropriate alignment.
@param[in] align enum ::dac_align. Right or left aligned, and 8 or
12 bit.
*/
void dac_load_data_buffer_dual(uint32_t dac,
		uint16_t data1, uint16_t data2,
		enum dac_align align)
{
	switch (align) {
	case DAC_ALIGN_RIGHT8:
		DAC_DHR8RD(dac) = ((data1 & 0xFF) | ((data2 & 0xFF) << 8));
		break;
	case DAC_ALIGN_RIGHT12:
		DAC_DHR12RD(dac) = ((data1 & 0xFFF) |
				((data2 & 0xFFF) << 16));
		break;
	case DAC_ALIGN_LEFT12:
		DAC_DHR12LD(dac) = ((data1 & 0xFFF) |
				((data2 & 0xFFF) << 16));
		break;
	default:
		break;
	}
}

/** @brief Trigger the DAC by a Software Trigger.

If the trigger source is set to be a software trigger, cause a trigger to occur.
The trigger is cleared by hardware after conversion.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_software_trigger(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_SWTRIGR(dac) |= DAC_SWTRIGR_SWTRIG1;
		break;
	case DAC_CHANNEL2:
		DAC_SWTRIGR(dac) |= DAC_SWTRIGR_SWTRIG2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_SWTRIGR(dac) |= (DAC_SWTRIGR_SWTRIG1 | DAC_SWTRIGR_SWTRIG2);
		break;
	default:
		break;
	}
}
/**@}*/

