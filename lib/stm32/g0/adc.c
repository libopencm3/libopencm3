/** @addtogroup adc_file ADC peripheral API
 * @ingroup peripheral_apis
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @date 10 January 2019
 *
 * LGPL License Terms @ref lgpl_license
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

/**@{*/

#include <libopencm3/stm32/adc.h>
#include <libopencm3/cm3/assert.h>

/** @brief ADC Set Clock Source
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 * @param[in] source Source (@ref adc_cfgr2_ckmode)
 */
void adc_set_clk_source(uint32_t adc, uint32_t source)
{
	uint32_t reg32 = ADC_CFGR2(adc);

	reg32 &= ~(ADC_CFGR2_CKMODE_MASK << ADC_CFGR2_CKMODE_SHIFT);
	ADC_CFGR2(adc) = (reg32 | (source << ADC_CFGR2_CKMODE_SHIFT));
}

/** @brief ADC Set Clock Prescale
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 * @param[in] prescale Prescale value for ADC Async Clock (@ref adc_ccr_presc)
*/
void adc_set_clk_prescale(uint32_t adc, uint32_t prescale)
{
	uint32_t reg32 = ADC_CCR(adc);

	reg32  &= ~(ADC_CCR_PRESC_MASK << ADC_CCR_PRESC_SHIFT);
	ADC_CCR(adc) = (reg32 | (prescale << ADC_CCR_PRESC_SHIFT));
}

/** @brief ADC Set the Sample Time for All Channels
 *
 * Setup all ADC channels to use a single ADC sampling time.
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 * @param[in] time ADC Sampling Time (@ref adc_api_smptime)
 */
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
	uint32_t reg32;

	reg32 = ADC_SMPR1(adc);
	/* set all channels on ADC_SMPR_SMPSEL_SMP1 first @ref adc_smpr_smpsel sample time selection, and clear its value */
	reg32 &= ~((ADC_SMPR_SMPSEL_MASK << ADC_SMPR_SMP1_SHIFT) | (ADC_SMPR_SMP1_MASK << ADC_SMPR_SMP1_SHIFT));
	/* setup ADC_SMPR_SMPSEL_SMP1 sample time */
	reg32 |= (time << ADC_SMPR_SMP1_SHIFT);
	ADC_SMPR1(adc) = reg32;
}

/** @brief ADC Set the Sample Time Selection for a Single Channel
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 * @param[in] channel ADC Channel (0..18 or @ref adc_channel)
 * @param[in] selection Sampling time selection (@ref adc_smpr_smpsel)
*/
void adc_set_channel_sample_time_selection(uint32_t adc, uint8_t channel, uint8_t selection)
{
	uint32_t reg32;

	reg32 = ADC_SMPR1(adc);
	reg32 &= ~(ADC_SMPR_SMPSEL_CHANNEL_MASK << ADC_SMPR_SMPSEL_CHANNEL_SHIFT(channel));
	reg32 |= (selection << ADC_SMPR_SMPSEL_CHANNEL_SHIFT(channel));
	ADC_SMPR1(adc) = reg32;
}

/** @brief ADC Set the Sample Time for Given Selection.
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 * @param[in] selection Sampling Time Selection (@ref adc_smpr_smpsel)
 * @param[in] time Sampling Time (@ref adc_smpr_smp)
*/
void adc_set_selection_sample_time(uint32_t adc, uint8_t selection, uint8_t time)
{
	uint32_t reg32;

	reg32 = ADC_SMPR1(adc);
	switch (selection) {
		case ADC_SMPR_SMPSEL_SMP1:
			reg32 &= ~(ADC_SMPR_SMP1_MASK << ADC_SMPR_SMP1_SHIFT);
			reg32 |= (time << ADC_SMPR_SMP1_SHIFT);
			break;
		case ADC_SMPR_SMPSEL_SMP2:
			reg32 &= ~(ADC_SMPR_SMP2_MASK << ADC_SMPR_SMP2_SHIFT);
			reg32 |= (time << ADC_SMPR_SMP2_SHIFT);
			break;
	}
	ADC_SMPR1(adc) = reg32;
}

/** @brief ADC Set a Regular Channel Conversion Sequence
 *
 * Define a simple sequence of channels to be converted.
 * ADCSTART must be de-asserted before sequence setup.
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 * @param[in] length Number of channels in the group, range 0..18
 * @param[in] channel Set of channels in sequence (0..18 or @ref adc_channel)
 */
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
	uint32_t reg32 = 0;
	bool stepup = false, stepdn = false;

	if (length > ADC_CHSELR_MAX_CHANNELS) {
		return;
	}

	if (length == 0) {
		ADC_CHSELR(adc) = 0;
		return;
	}

	reg32 |= (1 << channel[0]);

	for (uint8_t i = 1; i < length; i++) {
		reg32 |= ADC_CHSELR_CHSEL(channel[i]);
		stepup |= channel[i-1] < channel[i];
		stepdn |= channel[i-1] > channel[i];
	}

	/* Check if the channel list is in order */
	if (stepup && stepdn) {
		cm3_assert_not_reached();
	}

	/* Each modification to ADC_CFGR1's SCANDIR or CHSELRMOD bits or
	   ADC_CHSELR register must be done after previous configuration change
	   being properly applied: We have to clear ccrdy bit before and poll for
	   it being assert back after, before going on. We also need to wait for
	   configuration applied before starting conversion, or start will be
	   ignored.  */

	/* Setup scandir, if needed, waiting for configuration be applied.. */
	if (stepdn && (!(ADC_CFGR1(adc) & ADC_CFGR1_SCANDIR))) {
		ADC_ISR(adc) &= ~ADC_ISR_CCRDY;
		ADC_CFGR1(adc) |= ADC_CFGR1_SCANDIR;
		while (!(ADC_ISR(adc) & ADC_ISR_CCRDY));
	} else if (stepup && ((ADC_CFGR1(adc) & ADC_CFGR1_SCANDIR))) {
		ADC_ISR(adc) &= ~ADC_ISR_CCRDY;
		ADC_CFGR1(adc) &= ~ADC_CFGR1_SCANDIR;
		while (!(ADC_ISR(adc) & ADC_ISR_CCRDY));
	}

	/* Setup ADC in simple, not configurable, mode, if needed. */
	if ((ADC_CFGR1(adc) & ADC_CFGR1_CHSELRMOD)) {
		ADC_ISR(adc) &= ~ADC_ISR_CCRDY;
		ADC_CFGR1(adc) &= ~ADC_CFGR1_CHSELRMOD;
		while (!(ADC_ISR(adc) & ADC_ISR_CCRDY));
	}

	if (ADC_CHSELR(adc) != reg32) {
		ADC_ISR(adc) &= ~ADC_ISR_CCRDY;
		ADC_CHSELR(adc) = reg32;
		while (!(ADC_ISR(adc) & ADC_ISR_CCRDY));
	}
}

/**
 * @brief Enable the ADC Voltage regulator
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 */
void adc_enable_regulator(uint32_t adc)
{
	ADC_CR(adc) |= ADC_CR_ADVREGEN;
}

/**
 * @brief Disable the ADC Voltage regulator
 *
 * @param[in] adc ADC base address (@ref adc_reg_base)
 */
void adc_disable_regulator(uint32_t adc)
{
	ADC_CR(adc) &= ~ADC_CR_ADVREGEN;
}

/**@}*/
