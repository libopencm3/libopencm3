/** @defgroup STM32L1xx_adc_file ADC

@ingroup STM32L1xx

@brief <b>libopencm3 STM32L1xx Analog to Digital Converters</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly 2013 Ben Gamari <bgamari.foss@gmail.com>
@author @htmlonly &copy; @endhtmlonly 2013 Chung-Yu Huang <ck911279@gmail.com>

@date 13 Dec 2013

This library supports the A/D Converter Control System in the STM32L1xx series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices have a single A/D converter driven by a clock prescaled from the APB2
by a minimum factor of 2 to a maximum of 8.

The A/D converter has up to 42 channels as well as the ability to
sample an internal temperature sensor and V<sub>REFINT</sub>.

The conversions can occur as a one-off conversion whereby the process stops once
conversion is complete. The conversions can also be continuous wherein a new
conversion starts immediately the previous conversion has ended.

Conversion can occur as a single channel conversion or a scan of a group of
channels in either continuous or one-off mode. If more than one channel is converted
in a scan group, DMA must be used to transfer the data as there is only one
result register available. An interrupt can be set to occur at the end of
conversion, which occurs after all channels have been scanned.

A discontinuous mode allows a subgroup of group of a channels to be converted in
bursts of a given length.

Injected conversions allow a second group of channels to be converted separately
from the regular group. An interrupt can be set to occur at the end of
conversion, which occurs after all channels have been scanned.

@section adc_api_ex Basic ADC Handling API.

Example 1: Simple single channel conversion polled.

@code
  uint8_t channels[28];
  uint16_t data;

  // Enable clock for ADC1 and ADC_IN10 (PC0)
  rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
  rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOCEN);

  // Set analog mode to PC0
  gpio_mode_setup(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO0);

  // Turn off ADC before configuration
  adc_power_off(ADC1);

  // Basic configuration
  adc_set_clk_prescale(ADC_CCR_ADCPRE_DIV1);
  adc_set_resolution(ADC1, ADC_CR1_RES_12BIT);
  adc_set_right_aligned(ADC1);
  adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR_SMP_4CYC);
  adc_disable_external_trigger_regular(ADC1);
  adc_enable_power_down_idle(ADC1);
  adc_enable_power_down_delay(ADC1);

  // Set one shot conversion
  adc_set_single_conversion_mode(ADC1);

  // Set channel 10 (ADC_IN10 / PC0) to be convert
  channels[0]=10;  
  adc_set_regular_sequence(ADC1, 1, channels);

  // Turn on ADC module
  adc_power_on(ADC1);

  // Software trigger one regular conversion
  adc_start_conversion_regular(ADC1);

  // Polling for conversion completion
  while (! adc_eoc(ADC1));

  // Read regular conversion data
  data = adc_read_regular(ADC1);
@endcode

Example 2: Sample multiple channel conversions with DMA interrupted. Use internel
temperature sensor and reference voltage channels as ADC inputs.

@code
  // Declare memory buffer for DMA
  uint16_t adb_buff[28];

  void dma_setup(void) {
      // Enable clock for DMA1
      rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_DMA1EN);

      // Enable DMA1 CHANNEL1 interrupt event
      nvic_enable_irq(NVIC_DMA1_CHANNEL1_IRQ);

      // Set DMA channel read data from ADC_DR (ADC data register)
      dma_set_peripheral_address(DMA1, DMA_CHANNEL1, (uint32_t)&ADC1_DR);

      // Set DMA channel write data to memory buffer
      dma_set_memory_address(DMA1, DMA_CHANNEL1, (uint32_t)adc_buff);

      // Indicate DMA move data from peripheral to memory
      dma_set_read_from_peripheral(DMA1, DMA_CHANNEL1);

      // Indicate DMA move 3 data as a cycle
      dma_set_number_of_data(DMA1, DMA_CHANNEL1, 3);

      // Increase memory pointer after every transfer
      dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL1);

      // Set 16-bit data size for both peripheral and memory
      dma_set_peripheral_size(DMA1, DMA_CHANNEL1, DMA_CCR_PSIZE_16BIT);
      dma_set_memory_size(DMA1, DMA_CHANNEL1, DMA_CCR_MSIZE_16BIT);

      // Set HIGH priority
      dma_set_priority(DMA1, DMA_CHANNEL1, DMA_CCR_PL_HIGH);

      // Enable interrupt to handel converted data
      dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL1);

      // Rewind memory pointer back to the head of memory buffer after 3 data transfered
      dma_enable_circular_mode(DMA1, DMA_CHANNEL1);

      // Enable DMA1 CHANNEL1
      dma_enable_channel(DMA1, DMA_CHANNEL1);
  }

  // DMA1 CHANNLE1 interrupt handler routine
  void dma1_channel1_isr(void)
  {
      uint16_t vts, vref, adc_10;
      // Check for data transfer complete event
      if (dma_get_interrupt_flag(DMA1, DMA_CHANNEL1, DMA_TCIF)) {
          // Clear event flag
          dma_clear_interrupt_flags(DMA1, DMA_CHANNEL1, DMA_TCIF);

          vts  = adc_buff[0];
          vref = adc_buff[1];
          adc_10 = adc_buff[2];
      }
  }

  void adc_setup(void) {
      uint8_t channels[28];

      // Enable clock for ADC1 and ADC_IN10 (PC0)
      rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
      rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOCEN);

      // Set analog mode to PC0
      gpio_mode_setup(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO0);

      // Turn off ADC before configuration
      adc_power_off(ADC1);

      // Basic configuration
      adc_set_clk_prescale(ADC_CCR_ADCPRE_DIV1);
      adc_set_resolution(ADC1, ADC_CR1_RES_12BIT);
      adc_set_right_aligned(ADC1);
      adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR_SMP_4CYC);
      adc_disable_external_trigger_regular(ADC1);
      adc_enable_power_down_idle(ADC1);
      adc_enable_power_down_delay(ADC1);

      // Enable SCAN mode to make multiple regular channel conversions
      adc_enable_scan_mode(ADC1);

      // Set EOC (End-Of-Conversion) event for each conversion sequence
      // Note: This is optional in this example
      adc_set_eoc_of_each_sequence(ADC1);

      // Set one shot conversion
      adc_set_single_conversion_mode(ADC1);

      // Enable DMA request of each channel conversion completion
      adc_enable_dma(ADC1);

      // Generate DMA request for every scan
      adc_set_continuous_dma(ADC1);

      channels[0]=16; // Vts (Internal temperature sensor)
      channels[1]=17; // Vref (Internal reference voltage)
      channels[2]=10; // ADC_IN10 (PC0)
      adc_set_regular_sequence(ADC1, 1, channels);

      // Turn on ADC module
      adc_power_on(ADC1);

  }

  void main(void)
  {
      dma_setup();
      adc_setup();

      while (1) {
          // Software trigger one regular conversion
          adc_start_conversion_regular(ADC1);

          // sleep a while
          sleep(5);
      }

      return 0;
  }
@endcode

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
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

#include <libopencm3/stm32/l1/adc.h>

/*-----------------------------------------------------------------------------*/
/** @brief ADC Power On

If the ADC is in power-down mode then it is powered up. The application needs
to wait a time of about 3 microseconds for stabilization before using the ADC.
If the ADC is already on this function call has no effect.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_power_on(uint32_t adc)
{
    if (!(ADC_CR2(adc) & ADC_CR2_ADON))
		ADC_CR2(adc) |= ADC_CR2_ADON;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Power Off

If the ADC is in power-up mode then it is powered down.
If the ADC is already off this function call has no effect.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_power_off(uint32_t adc)
{
    if (ADC_CR2(adc) & ADC_CR2_ADON)
    ADC_CR2(adc) &= ~ADC_CR2_ADON;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Clock Prescale

The ADC clock taken from the APB2 clock can be scaled down by 2, 4, 6 or 8.

@param[in] prescale Unsigned int32. Prescale value for ADC Clock @ref adc_ccr_adcpre
*/

void adc_set_clk_prescale(uint32_t prescale)
{
	uint32_t reg32 = ((ADC_CCR & ~ADC_CCR_ADCPRE_MASK) | prescale);
	ADC_CCR = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag

  This flag is set after all channels of a regular or injected group have been
  converted.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @returns bool. End of conversion flag.
 */

bool adc_eoc(uint32_t adc)
{
	return ((ADC_SR(adc) & ADC_SR_EOC) != 0);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC clear the End-of-Conversion Flag

  This flag should be cleared after all channel data of an regular group have
  been read.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_clear_eoc(uint32_t adc)
{
    ADC_SR(adc) &= ~ADC_SR_EOC;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag for Injected Conversion

  This flag is set after all channels of an injected group have been converted.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @returns bool. End of conversion flag.
 */

bool adc_eoc_injected(uint32_t adc)
{
	return ((ADC_SR(adc) & ADC_SR_JEOC) != 0);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC clear the End-of-Conversion Flag for Injected Conversion

  This flag should be cleared after all channel data of an injected group have
  been read.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_clear_eoc_injected(uint32_t adc)
{
    ADC_SR(adc) &= ~ADC_SR_JEOC;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read from the Regular Conversion Result Register

  The result read back is 12 bits, right or left aligned within the first 16 bits.
  For ADC1 only, the higher 16 bits will hold the result from ADC2 if
  an appropriate dual mode has been set @see adc_set_dual_mode.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @returns Unsigned int32 conversion result.
 */

uint32_t adc_read_regular(uint32_t adc)
{
	return ADC_DR(adc);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read from an Injected Conversion Result Register

  The result read back from the selected injected result register (one of four) is
  12 bits, right or left aligned within the first 16 bits. The result can have a
  negative value if the injected channel offset has been set @see adc_set_injected_offset.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] reg Unsigned int8. Register number (1 ... 4).
  @returns Unsigned int32 conversion result.
 */

uint32_t adc_read_injected(uint32_t adc, uint8_t reg)
{
	switch (reg) {
		case 1:
			return ADC_JDR1(adc);
		case 2:
			return ADC_JDR2(adc);
		case 3:
			return ADC_JDR3(adc);
		case 4:
			return ADC_JDR4(adc);
	}
	return 0;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Injected Channel Data Offset

  This value is subtracted from the injected channel results after conversion
  is complete, and can result in negative results. A separate value can be specified
  for each injected data register.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] reg Unsigned int8. Register number (1 ... 4).
  @param[in] offset Unsigned int32.
 */

void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset)
{
	switch (reg) {
		case 1:
			ADC_JOFR1(adc) = offset & ADC_JOFFSET_MSK;
			break;
		case 2:
			ADC_JOFR2(adc) = offset & ADC_JOFFSET_MSK;
			break;
		case 3:
			ADC_JOFR3(adc) = offset & ADC_JOFFSET_MSK;
			break;
		case 4:
			ADC_JOFR4(adc) = offset & ADC_JOFFSET_MSK;
			break;
	}
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Regular Conversions

  The analog watchdog allows the monitoring of an analog signal between two threshold
  levels. The thresholds must be preset. Comparison is done before data alignment
  takes place, so the thresholds are left-aligned.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_analog_watchdog_regular(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Regular Conversions

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_analog_watchdog_regular(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Injected Conversions

  The analog watchdog allows the monitoring of an analog signal between two threshold
  levels. The thresholds must be preset. Comparison is done before data alignment
  takes place, so the thresholds are left-aligned.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Injected Conversions

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Regular Conversions

  In this mode the ADC converts, on each trigger, a subgroup of up to 8 of the
  defined regular channel group. The subgroup is defined by the number of
  consecutive channels to be converted. After a subgroup has been converted
  the next trigger will start conversion of the immediately following subgroup
  of the same length or until the whole group has all been converted. When the
  the whole group has been converted, the next trigger will restart conversion
  of the subgroup at the beginning of the whole group.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] length Unsigned int8. Number of channels in the group @ref adc_cr1_discnum.
 */

void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length)
{
	if ( (length-1) > 7 ) return;
	ADC_CR1(adc) |= ADC_CR1_DISCEN;	
	ADC_CR1(adc) |= ((length-1) << ADC_CR1_DISCNUM_SHIFT);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_discontinuous_mode_regular(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_DISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Injected Conversions

  In this mode the ADC converts sequentially one channel of the defined group of
  injected channels, cycling back to the first channel in the group once the
  entire group has been converted.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_JDISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Injected Conversions

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JDISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Automatic Injected Conversions

  The ADC converts a defined injected group of channels immediately after the
  regular channels have been converted. The external trigger on the injected
  channels is disabled as required.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
 */

void adc_enable_automatic_injected_group_conversion(uint32_t adc)
{
	adc_disable_external_trigger_injected(adc);
	ADC_CR1(adc) |= ADC_CR1_JAUTO;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Automatic Injected Conversions

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_automatic_injected_group_conversion(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAUTO;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for All Regular and/or Injected Channels

  The analog watchdog allows the monitoring of an analog signal between two threshold
  levels. The thresholds must be preset. Comparison is done before data alignment
  takes place, so the thresholds are left-aligned.

  @note The analog watchdog must be enabled for either or both of the regular or
  injected channels. If neither are enabled, the analog watchdog feature will be
  disabled.
  @ref adc_enable_analog_watchdog_injected, @ref adc_enable_analog_watchdog_regular.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_analog_watchdog_on_all_channels(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDSGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Resolution
 *
 * ADC Resolution can be reduced from 12 bits to 10, 8 or 6 bits for a
 * corresponding reduction in conversion time.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] resolution Unsigned int16. Resolution value (@ref adc_api_res)
 */

void adc_set_resolution(uint32_t adc, uint16_t resolution)
{
	ADC_CR1(adc) = (ADC_CR1(adc) & ~ADC_CR1_RES_MASK) | resolution;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for a Selected Channel

  The analog watchdog allows the monitoring of an analog signal between two threshold
  levels. The thresholds must be preset. Comparison is done before data alignment
  takes place, so the thresholds are left-aligned.

  @note The analog watchdog must be enabled for either or both of the regular or
  injected channels. If neither are enabled, the analog watchdog feature will be
  disabled. If both are enabled, the same channel number is monitored.
  @ref adc_enable_analog_watchdog_injected, @ref adc_enable_analog_watchdog_regular.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] channel Unsigned int8. ADC channel number @ref adc_watchdog_channel.
 */

void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc, uint8_t channel)
{
	uint32_t reg32;

	reg32 = (ADC_CR1(adc) & ~ADC_CR1_AWDCH_MASK); /* Clear channel select bits. */
	if (channel < 27)
		reg32 |= channel << ADC_CR1_AWDCH_SHIFT;
	ADC_CR1(adc) = reg32;
	ADC_CR1(adc) |= ADC_CR1_AWDSGL;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Scan Mode

  In this mode a conversion consists of a scan of the predefined set of channels,
  regular and injected, each channel conversion immediately following the
  previous one. It can use single, continuous or discontinuous mode.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_scan_mode(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_SCAN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Scan Mode

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
 */

void adc_disable_scan_mode(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_SCAN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Conversion Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_eoc_interrupt(uint32_t adc)
{
    ADC_CR1(adc) |= ADC_CR1_EOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_eoc_interrupt(uint32_t adc)
{
    ADC_CR1(adc) &= ~ADC_CR1_EOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Injected End-Of-Conversion Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_eoc_interrupt_injected(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_JEOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Injected End-Of-Conversion Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_eoc_interrupt_injected(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JEOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_awd_interrupt(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_awd_interrupt(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Overrun Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_ovr_interrupt(uint32_t adc)
{
    ADC_CR1(adc) |= ADC_CR1_OVRIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Overrun Interrupt

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_ovr_interrupt(uint32_t adc)
{
    ADC_CR1(adc) &= ~ADC_CR1_OVRIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable The Temperature Sensor

  This enables both the sensor and the reference voltage measurements on channels
  16 and 17.
 */

void adc_enable_temperature_sensor(void)
{
	ADC_CCR |= ADC_CCR_TSVREFE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable The Temperature Sensor

  Disabling this will reduce power consumption from the sensor and the reference
  voltage measurements.
 */

void adc_disable_temperature_sensor(void)
{
	ADC_CCR &= ~ADC_CCR_TSVREFE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Regular Channels

  This starts conversion on a set of defined regular channels if the ADC trigger
  is set to be a software trigger. It is cleared by hardware once conversion
  starts.

  Note this is a software trigger and requires triggering to be enabled and the
  trigger source to be set appropriately otherwise conversion will not start.
  This is not the same as the ADC start conversion operation.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_start_conversion_regular(uint32_t adc)
{
	/* Wait until the regular channel ready and ADC ON */
    while (ADC_SR(adc) & ADC_SR_RCNR);
    while (!(ADC_SR(adc) & ADC_SR_ADONS));

	/* Start conversion on regular channels. */
	ADC_CR2(adc) |= ADC_CR2_SWSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR2(adc) & ADC_CR2_SWSTART);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Injected Channels

  This starts conversion on a set of defined injected channels if the ADC trigger
  is set to be a software trigger. It is cleared by hardware once conversion
  starts.

  Note this is a software trigger and requires triggering to be enabled and the
  trigger source to be set appropriately otherwise conversion will not start.
  This is not the same as the ADC start conversion operation.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_start_conversion_injected(uint32_t adc)
{
	/* Wait until the injected channel ready and ADC ON */
	while (ADC_SR(adc) & ADC_SR_JCNR);
    while (!(ADC_SR(adc) & ADC_SR_ADONS));

	/* Start conversion on injected channels. */
	ADC_CR2(adc) |= ADC_CR2_JSWSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR2(adc) & ADC_CR2_JSWSTART);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Regular Channels

  This enables an external trigger for set of defined regular channels.

  @li Timer 9 CC2 event
  @li Timer 9 TRGO event
  @li Timer 2 CC3 event
  @li Timer 2 CC2 event
  @li Timer 3 TRGO event
  @li Timer 4 CC4 event
  @li Timer 2 TRGO event
  @li Timer 3 CC1 event
  @li Timer 3 CC3 event
  @li Timer 4 TRGO event
  @li Timer 6 TRGO event
  @li EXTI line 11

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] mode Unsigned int32. External trigger mode @ref adc_trigger_mode_regular
  @param[in] trigger Unsigned int8. Trigger identifier @ref adc_trigger_regular
 */

void adc_enable_external_trigger_regular(uint32_t adc, uint32_t mode, uint32_t trigger)
{
	uint32_t reg32;

	reg32 = ADC_CR2(adc) & ~(ADC_CR2_EXTEN_MASK | ADC_CR2_EXTSEL_MASK);
	reg32 |= trigger;
	ADC_CR2(adc) = reg32;
	ADC_CR2(adc) |= mode;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_external_trigger_regular(uint32_t adc)
{
	ADC_CR2(adc) = (ADC_CR2(adc) & ~(ADC_CR2_EXTEN_MASK)) | ADC_CR2_EXTEN_DISABLED;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Injected Channels

  This enables an external trigger for set of defined injected channels.

  @li Timer 9 CC1 event
  @li Timer 9 TRGO event
  @li Timer 2 TRGO event
  @li Timer 2 CC1 event
  @li Timer 3 CC4 event
  @li Timer 4 TRGO event
  @li Timer 4 CC1 event
  @li Timer 4 CC2 event
  @li Timer 4 CC3 event
  @li Timer 10 CC1 event
  @li Timer 7 TRGO event
  @li EXTI line 15

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] mode Unsigned int32. External trigger mode @ref adc_trigger_mode_injected
  @param[in] trigger Unsigned int8. Trigger identifier @ref adc_trigger_injected
 */
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t mode, uint32_t trigger)
{
	uint32_t reg32;

	reg32 = ADC_CR2(adc) & ~(ADC_CR2_JEXTEN_MASK | ADC_CR2_JEXTSEL_MASK);
	reg32 |= trigger;
	ADC_CR2(adc) = reg32;
	ADC_CR2(adc) |= mode;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Injected Channels

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_external_trigger_injected(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_JEXTEN_MASK;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Left Aligned

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_left_aligned(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_ALIGN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Right Aligned

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_right_aligned(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ALIGN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable DMA Transfers

  Only available for ADC1 through DMA1 channel1, and ADC3 through DMA2 channel5.
  ADC2 will use DMA if it is set as slave in dual mode with ADC1 in DMA transfer
  mode.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_dma(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_DMA;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable DMA Transfers

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_dma(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_DMA;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC No DMA Request After Last Transfers

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_single_dma(uint32_t adc)
{
    ADC_CR2(adc) &= ~ADC_CR2_DDS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable DMA Request As Long As Data Converted

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_continuous_dma(uint32_t adc)
{
    ADC_CR2(adc) |= ADC_CR2_DDS;
}


/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Power Down during Idle

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_power_down_idle(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_PDI;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Power Down during Idle

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_power_down_idle(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_PDI;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Power Down during Delay

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_enable_power_down_delay(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_PDD;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Power Down during Delay

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_disable_power_down_delay(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_PDD;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Continuous Conversion Mode

  In this mode the ADC starts a new conversion of a single channel or a channel
  group immediately following completion of the previous channel group conversion.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_continuous_conversion_mode(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_CONT;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Single Conversion Mode

  In this mode the ADC performs a conversion of one channel or a channel group
  and stops.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_single_conversion_mode(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_CONT;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for a Single Channel

  The sampling time can be selected in ADC clock cycles from 1.5 to 239.5.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] channel Unsigned int8. ADC Channel integer 0..31 or from @ref adc_channel.
  @param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg.
 */

void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time)
{
	uint32_t reg32;

#define SET_SAMPLE_TIME(_SMPR_, _CH_) \
do {\
	reg32 = _SMPR_(adc) & ~(0x7 << ((_CH_) * 3)); \
	reg32 |= ((time & 0x7) << ((_CH_) * 3)); \
	_SMPR_(adc) = reg32; \
} while (0)

	if (channel < 10)
		SET_SAMPLE_TIME(ADC_SMPR3, channel);
	else if (channel < 20)
		SET_SAMPLE_TIME(ADC_SMPR2, channel - 10);
	else if (channel < 30)
		SET_SAMPLE_TIME(ADC_SMPR1, channel - 20);
	else if (channel < 32)
		SET_SAMPLE_TIME(ADC_SMPR0, channel - 30);

#undef SET_SMAPLE_TIME
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for All Channels

  The sampling time can be selected in ADC clock cycles from 1.5 to 239.5, same for
  all channels.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg.
 */

void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
	uint8_t channel;
	uint32_t reg32 = 0;

	for (channel = 0; channel <= 9; channel++)
		reg32 |= ((time & 0xf) << (channel * 3));
	ADC_SMPR3(adc) = reg32;
	ADC_SMPR2(adc) = reg32;
	ADC_SMPR1(adc) = reg32;
	ADC_SMPR0(adc) = ((time & 0xf) << 3) | (time & 0xf);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Upper Threshold

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] threshold Unsigned int8. Upper threshold value.
 */

void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold)
{
	ADC_HTR(adc) = (uint32_t)threshold & ADC_HT_MSK;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Lower Threshold

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] threshold Unsigned int8. Lower threshold value.
 */

void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold)
{
	ADC_LTR(adc) = (uint32_t)threshold & ADC_LT_MSK;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the Over-Run Flag

  This flag is set when regular conversion data are lost.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @returns bool. Overrun flag.
 */

bool adc_get_overrun_flag(uint32_t adc)
{
    return ((ADC_SR(adc) & ADC_SR_OVR) != 0);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Clear the Over-Run Flag

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_clear_overrun_flag(uint32_t adc)
{
    ADC_SR(adc) &= ~ADC_SR_OVR;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the Watch-Dog Flag

  This flag is set when the converted voltage crosses the values programmed by function
  @ref adc_set_watchdog_high_threshold and @ref adc_set_watchdog_low_threshold.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @returns bool. Watchdog flag.
 */

bool adc_get_watchdog_flag(uint32_t adc)
{
    return ((ADC_SR(adc) & ADC_SR_AWD) != 0);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Clear the Watch-Dog Flag

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_clear_watchdog_flag(uint32_t adc)
{
    ADC_SR(adc) &= ~ADC_SR_AWD;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set End of Conversion of each Conversion

  Make hardware to generate End of conversion event for each regular convertion.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_eoc_of_each_conversion(uint32_t adc)
{
    ADC_CR2(adc) |= ADC_CR2_EOCS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set End of Conversion of each Sequence of Conversion

  Make hardware to generate End of conversion event for each sequence of
  regular convertion.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
 */

void adc_set_eoc_of_each_sequence(uint32_t adc)
{
    ADC_CR2(adc) &= ~ADC_CR2_EOCS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set a Regular Channel Conversion Sequence

  Define a sequence of channels to be converted as a regular group with a length
  from 1 to 28 channels. If this is called during conversion, the current conversion
  is reset and conversion begins again with the newly defined group.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] length Unsigned int8. Number of channels in the group.
  @param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0..31.
 */

void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
    uint32_t reg32[5] = {0,0,0,0,0};
    uint8_t i = 0;

    /* Maximum sequence length is 28 channels. */
    if (length > 28)
        return;

    for (i = 0; i < length; i++)
        reg32[4 - i/6] |= (channel[i] << ((i%6)*5));

    reg32[0] |= ((length -1) << ADC_SQR1_L_LSB);

    ADC_SQR1(adc) = reg32[0];
    ADC_SQR2(adc) = reg32[1];
    ADC_SQR3(adc) = reg32[2];
    ADC_SQR4(adc) = reg32[3];
    ADC_SQR5(adc) = reg32[4];
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set an Injected Channel Conversion Sequence

  Defines a sequence of channels to be converted as an injected group with a length
  from 1 to 4 channels. If this is called during conversion, the current conversion
  is reset and conversion begins again with the newly defined group.

  @param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base.
  @param[in] length Unsigned int8. Number of channels in the group.
  @param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0..31.
 */

void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
	uint32_t reg32 = 0;
	uint8_t i = 0;

	/* Maximum sequence length is 4 channels. */
	if (length > 4)
		return;

	for (i = 0; i < length; i++)
		reg32 |= (channel[i] << (i * 5));

	reg32 |= ((length - 1) << ADC_JSQR_JL_LSB);

	ADC_JSQR(adc) = reg32;
}

/**@}*/

