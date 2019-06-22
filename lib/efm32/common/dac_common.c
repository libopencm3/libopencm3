/** @addtogroup dac_file DAC peripheral API
 * @ingroup peripheral_apis
 */
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
 * but WITHOUT ANY WARRANTY
{

} without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/dac.h>

/**@{*/

/**
 * Set DAC refresh cycle
 * @param[in] dac DAC (use DACx)
 * @param[in] refrsel (use DAC_CTRL_REFRSEL_*CYCLES)
 * @see dac_disable_auto_refresh()
 * @see dac_enable_auto_refresh()
 */
void dac_set_refresh_cycle(uint32_t dac, uint32_t refrsel)
{
	DAC_CTRL(dac) = (DAC_CTRL(dac) & ~DAC_CTRL_REFRSEL_MASK) | refrsel;
}

/**
 * Set DAC clock prescaler
 * @param[in] dac DAC (use DACx)
 * @param[in] presc Prescaler (use DAC_CTRL_PRESC_*)
 */
void dac_set_clock_prescaler(uint32_t dac, uint32_t presc)
{
	DAC_CTRL(dac) = (DAC_CTRL(dac) & ~DAC_CTRL_PRESC_MASK) | presc;
}

/**
 * Set DAC reference
 * @param[in] dac DAC (use DACx)
 * @param[in] refsel Reference (DAC_CTRL_REFSEL_*)
 */
void dac_set_reference(uint32_t dac, uint32_t refsel)
{
	DAC_CTRL(dac) = (DAC_CTRL(dac) & ~DAC_CTRL_REFSEL_MASK) | refsel;
}

/**
 * Set DAC output mode
 * @param[in] dac DAC (use DACx)
 * @param[in] outmode Output mode (DAC_CTRL_OUTMODE_*)
 */
void dac_set_out_mode(uint32_t dac, uint32_t outmode)
{
	DAC_CTRL(dac) = (DAC_CTRL(dac) & ~DAC_CTRL_OUTMODE_MASK) | outmode;
}

/**
 * Set conversion mode
 * @param[in] dac DAC (use DACx)
 * @param[in] convmode Conversion mode (use DAC_CTRL_CONVMODE_*)
 */
void dac_set_conversion_mode(uint32_t dac, uint32_t convmode)
{
	DAC_CTRL(dac) = (DAC_CTRL(dac) & ~DAC_CTRL_CONVMODE_MASK) | convmode;
}

/**
 * Enable Sine wave on output
 * @param[in] dac DAC (use DACx)
 */
void dac_enable_sine(uint32_t dac)
{
	DAC_CTRL(dac) |= DAC_CTRL_SINMODE;
}

/**
 * Disable Sine wave on output
 * @param[in] dac DAC (use DACx)
 */
void dac_disable_sine(uint32_t dac)
{
	DAC_CTRL(dac) &= ~DAC_CTRL_SINMODE;
}

/**
 * Set PRS trigger source on DAC channel
 * @param[in] dac DAC (use DACx)
 * @param[in] dac_chan DAC Channel (use DAC_CHx)
 * @param[in] prs_chan PRS Channel (use PRS_CHx)
 */
void dac_set_prs_trigger(uint32_t dac, enum dac_ch dac_chan,
			 enum prs_ch prs_chan)
{
	uint32_t ch_ctrl = DAC_CHx_CTRL(dac, dac_chan);
	ch_ctrl &= DAC_CH_CTRL_PRSSEL_MASK;
	ch_ctrl |= DAC_CH_CTRL_PRSSEL(prs_chan);
	DAC_CHx_CTRL(dac, dac_chan) = ch_ctrl;
}

/**
 * Enable PRS triggerring
 * @param[in] dac DAC (use DACx)
 * @param[in] ch DAC Channel (use DAC_CHx)
 */
void dac_enable_prs_trigger(uint32_t dac, enum dac_ch ch)
{
	DAC_CHx_CTRL(dac, ch) |= DAC_CH_CTRL_PRSEN;
}

/**
 * Disable PRS triggerring
 * @param[in] dac DAC (use DACx)
 * @param[in] ch DAC Channel (use DAC_CHx)
 */
void dac_disable_prs_trigger(uint32_t dac, enum dac_ch ch)
{
	DAC_CHx_CTRL(dac, ch) &= ~DAC_CH_CTRL_PRSEN;
}

/**
 * Enable auto refresh
 * @param[in] dac DAC (use DACx)
 * @param[in] ch DAC Channel (use DAC_CHx)
 */
void dac_enable_auto_refresh(uint32_t dac, enum dac_ch ch)
{
	DAC_CHx_CTRL(dac, ch) |= DAC_CH_CTRL_REFREN;
}

/**
 * Disable auto refresh
 * @param[in] dac DAC (use DACx)
 * @param[in] ch DAC Channel (use DAC_CHx)
 */
void dac_disable_auto_refresh(uint32_t dac, enum dac_ch ch)
{
	DAC_CHx_CTRL(dac, ch) &= ~DAC_CH_CTRL_REFREN;
}

/**
 * Enable channel
 * @param[in] dac DAC (use DACx)
 * @param[in] ch DAC Channel (use DAC_CHx)
 */
void dac_enable_channel(uint32_t dac, enum dac_ch ch)
{
	DAC_CHx_CTRL(dac, ch) |= DAC_CH_CTRL_EN;
}

/**
 * Disable channel
 * @param[in] dac DAC (use DACx)
 * @param[in] ch DAC Channel (use DAC_CHx)
 */
void dac_disable_channel(uint32_t dac, enum dac_ch ch)
{
	DAC_CHx_CTRL(dac, ch) &= ~DAC_CH_CTRL_REFREN;
}

/**@}*/