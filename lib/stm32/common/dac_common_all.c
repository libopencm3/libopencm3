/** @addtogroup dac_file DAC peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies ksarkies@internode.on.net

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
	dac_disable(CHANNEL_1);
	dac_set_waveform_characteristics(DAC_CR_MAMP1_8);
	dac_set_waveform_generation(DAC_CR_WAVE1_NOISE);
	dac_enable(CHANNEL_1);
	dac_set_trigger_source(DAC_CR_TSEL1_SW);
	dac_load_data_buffer_single(0, RIGHT12, CHANNEL_1);
	....
	dac_software_trigger(CHANNEL_1);
	dac_load_data_buffer_single(value, RIGHT12, CHANNEL_1);
@endcode

@section dac_api_dma_ex Simultaneous Dual DAC with DMA.

This example in part sets up the DAC channel 1 DMA (DMA2 channel 3) to read
16 bit data from memory into the right-aligned 8 bit dual register DAC_DHR8RD.
Both DAC channels are enabled, and both triggers are set to the same timer
2 input as required for simultaneous operation. DMA is enabled for DAC channel
1 only to ensure that only one DMA request is generated.

@code
	dma_set_memory_size(DMA2,DMA_CHANNEL3,DMA_CCR_MSIZE_16BIT);
	dma_set_peripheral_size(DMA2,DMA_CHANNEL3,DMA_CCR_PSIZE_16BIT);
	dma_set_read_from_memory(DMA2,DMA_CHANNEL3);
	dma_set_peripheral_address(DMA2,DMA_CHANNEL3,(uint32_t) &DAC_DHR8RD);
	dma_enable_channel(DMA2,DMA_CHANNEL3);
	...
	dac_trigger_enable(CHANNEL_D);
	dac_set_trigger_source(DAC_CR_TSEL1_T2 | DAC_CR_TSEL2_T2);
	dac_dma_enable(CHANNEL_1);
	dac_enable(CHANNEL_D);
@endcode

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies
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

#define MASK8 0xFF
#define MASK12 0xFFF

/*---------------------------------------------------------------------------*/
/** @brief DAC Channel Enable.

Enable a digital to analog converter channel. After setting this enable, the
DAC requires a t<sub>wakeup</sub> time typically around 10 microseconds before
it actually wakes up.

@param[in] dac_channel enum ::data_channel.
*/

void dac_enable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR |= DAC_CR_EN1;
		break;
	case CHANNEL_2:
		DAC_CR |= DAC_CR_EN2;
		break;
	case CHANNEL_D:
		DAC_CR |= (DAC_CR_EN1 | DAC_CR_EN2);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DAC Channel Disable.

Disable a digital to analog converter channel.

@param[in] dac_channel enum ::data_channel.
*/

void dac_disable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR &= ~DAC_CR_EN1;
		break;
	case CHANNEL_2:
		DAC_CR &= ~DAC_CR_EN2;
		break;
	case CHANNEL_D:
		DAC_CR &= ~(DAC_CR_EN1 | DAC_CR_EN2);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DAC Channel Output Buffer Enable.

Enable a digital to analog converter channel output drive buffer. This is an
optional amplifying buffer that provides additional drive for the output
signal. The buffer is enabled by default after a reset and needs to be
explicitly disabled if required.

@param[in] dac_channel enum ::data_channel.
*/

void dac_buffer_enable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR &= ~DAC_CR_BOFF1;
		break;
	case CHANNEL_2:
		DAC_CR &= ~DAC_CR_BOFF2;
		break;
	case CHANNEL_D:
		DAC_CR &= ~(DAC_CR_BOFF1 | DAC_CR_BOFF2);
		break;
	}
}
/*---------------------------------------------------------------------------*/
/** @brief DAC Channel Output Buffer Disable.

Disable a digital to analog converter channel output drive buffer. Disabling
this will reduce power consumption slightly and will increase the output
impedance of the DAC.  The buffers are enabled by default after a reset.

@param[in] dac_channel enum ::data_channel.
*/

void dac_buffer_disable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR |= DAC_CR_BOFF1;
		break;
	case CHANNEL_2:
		DAC_CR |= DAC_CR_BOFF2;
		break;
	case CHANNEL_D:
		DAC_CR |= (DAC_CR_BOFF1 | DAC_CR_BOFF2);
		break;
	}
}
/*---------------------------------------------------------------------------*/
/** @brief DAC Channel DMA Enable.

Enable a digital to analog converter channel DMA mode (connected to DMA2 channel
3 for DAC channel 1 and DMA2 channel 4 for DAC channel 2). A DMA request is
generated following an external trigger.

@param[in] dac_channel enum ::data_channel.
*/

void dac_dma_enable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR |= DAC_CR_DMAEN1;
		break;
	case CHANNEL_2:
		DAC_CR |= DAC_CR_DMAEN2;
		break;
	case CHANNEL_D:
		DAC_CR |= (DAC_CR_DMAEN1 | DAC_CR_DMAEN2);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DAC Channel DMA Disable.

Disable a digital to analog converter channel DMA mode.

@param[in] dac_channel enum ::data_channel.
*/

void dac_dma_disable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR &= ~DAC_CR_DMAEN1;
		break;
	case CHANNEL_2:
		DAC_CR &= ~DAC_CR_DMAEN2;
		break;
	case CHANNEL_D:
		DAC_CR &= ~(DAC_CR_DMAEN1 | DAC_CR_DMAEN2);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DAC Channel Trigger Enable.

Enable a digital to analog converter channel external trigger mode. This allows
an external trigger to initiate register transfers from the buffer register to
the DAC output register, followed by a DMA transfer to the buffer register if
DMA is enabled.  The trigger source must also be selected.

@param[in] dac_channel enum ::data_channel.
*/

void dac_trigger_enable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR |= DAC_CR_TEN1;
		break;
	case CHANNEL_2:
		DAC_CR |= DAC_CR_TEN2;
		break;
	case CHANNEL_D:
		DAC_CR |= (DAC_CR_TEN1 | DAC_CR_TEN2);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief DAC Channel Trigger Disable.

Disable a digital to analog converter channel external trigger.

@param[in] dac_channel enum ::data_channel.
*/

void dac_trigger_disable(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR &= ~DAC_CR_TEN1;
		break;
	case CHANNEL_2:
		DAC_CR &= ~DAC_CR_TEN2;
		break;
	case CHANNEL_D:
		DAC_CR &= ~(DAC_CR_TEN1 | DAC_CR_TEN2);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Set DAC Channel Trigger Source.

Sets the digital to analog converter trigger source, which can be taken from
various timers, an external trigger or a software trigger.

@param[in] dac_trig_src uint32_t. Taken from @ref dac_trig2_sel or @ref
dac_trig1_sel or a logical OR of one of each of these to set both channels
simultaneously.
*/

void dac_set_trigger_source(uint32_t dac_trig_src)
{
	DAC_CR |= dac_trig_src;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable and Set DAC Channel Waveform Generation.

Enable the digital to analog converter waveform generation as either
pseudo-random noise or triangular wave. These signals are superimposed on
existing output values in the DAC output registers.

@note The DAC trigger must be enabled for this to work.

@param[in] dac_wave_ens uint32_t. Taken from @ref dac_wave1_en or @ref
dac_wave2_en or a logical OR of one of each of these to set both channels
simultaneously.
*/

void dac_set_waveform_generation(uint32_t dac_wave_ens)
{
	DAC_CR |= dac_wave_ens;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable DAC Channel Waveform Generation.

Disable a digital to analog converter channel superimposed waveform generation.

@param[in] dac_channel enum ::data_channel.
*/

void dac_disable_waveform_generation(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_CR &= ~DAC_CR_WAVE1_DIS;
		break;
	case CHANNEL_2:
		DAC_CR &= ~DAC_CR_WAVE2_DIS;
		break;
	case CHANNEL_D:
		DAC_CR &= ~(DAC_CR_WAVE1_DIS | DAC_CR_WAVE2_DIS);
		break;
	}
}

/*---------------------------------------------------------------------------*/
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

@param[in] dac_mamp uint32_t. Taken from @ref dac_mamp2 or @ref dac_mamp1 or a
logical OR of one of each of these to set both channels simultaneously.
*/

void dac_set_waveform_characteristics(uint32_t dac_mamp)
{
	DAC_CR |= dac_mamp;
}

/*---------------------------------------------------------------------------*/
/** @brief Load DAC Data Register.

Loads the appropriate digital to analog converter data register with 12 or 8 bit
data to be converted on a channel. The data can be aligned as follows:
@li right-aligned 8 bit data in bits 0-7
@li right-aligned 12 bit data in bits 0-11
@li left aligned 12 bit data in bits 4-15

@param[in] dac_data uint16_t with appropriate alignment.
@param[in] dac_data_format enum ::data_align. Alignment and size.
@param[in] dac_channel enum ::data_channel.
*/

void dac_load_data_buffer_single(uint16_t dac_data, data_align dac_data_format,
		data_channel dac_channel)
{
	if (dac_channel == CHANNEL_1) {
		switch (dac_data_format) {
		case RIGHT8:
			DAC_DHR8R1 = dac_data;
			break;
		case RIGHT12:
			DAC_DHR12R1 = dac_data;
			break;
		case LEFT12:
			DAC_DHR12L1 = dac_data;
			break;
		}
	} else if (dac_channel == CHANNEL_2) {
		switch (dac_data_format) {
		case RIGHT8:
			DAC_DHR8R2 = dac_data;
			break;
		case RIGHT12:
			DAC_DHR12R2 = dac_data;
			break;
		case LEFT12:
			DAC_DHR12L2 = dac_data;
			break;
		}
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Load DAC Dual Data Register.

Loads the appropriate digital to analog converter dual data register with 12 or
8 bit data to be converted for both channels. This allows high bandwidth
simultaneous or independent analog output. The data in both channels are aligned
identically.

@param[in] dac_data1 uint16_t for channel 1 with appropriate alignment.
@param[in] dac_data2 uint16_t for channel 2 with appropriate alignment.
@param[in] dac_data_format enum ::data_align. Right or left aligned, and 8 or
12 bit.
*/

void dac_load_data_buffer_dual(uint16_t dac_data1, uint16_t dac_data2,
		data_align dac_data_format)
{
	switch (dac_data_format) {
	case RIGHT8:
		DAC_DHR8RD = ((dac_data1 & MASK8) | ((dac_data2 & MASK8) << 8));
		break;
	case RIGHT12:
		DAC_DHR12RD = ((dac_data1 & MASK12) |
				((dac_data2 & MASK12) << 16));
		break;
	case LEFT12:
		DAC_DHR12LD = ((dac_data1 & MASK12) |
				((dac_data2 & MASK12) << 16));
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Trigger the DAC by a Software Trigger.

If the trigger source is set to be a software trigger, cause a trigger to occur.
The trigger is cleared by hardware after conversion.

@param[in] dac_channel enum ::data_channel.
*/

void dac_software_trigger(data_channel dac_channel)
{
	switch (dac_channel) {
	case CHANNEL_1:
		DAC_SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
		break;
	case CHANNEL_2:
		DAC_SWTRIGR |= DAC_SWTRIGR_SWTRIG2;
		break;
	case CHANNEL_D:
		DAC_SWTRIGR |= (DAC_SWTRIGR_SWTRIG1 | DAC_SWTRIGR_SWTRIG2);
		break;
	}
}
/**@}*/

