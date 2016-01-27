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
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/prs.h>

/**
 * Enable PRS output to GPIO.
 * @param[in] ch Channel (use PRS_CHx)
 * @see prs_set_output_loc()
 */
void prs_enable_gpio_output(enum prs_ch ch)
{
	PRS_ROUTE |= PRS_ROUTE_CHxPEN(ch);
}

/**
 * Disable PRS output to GPIO.
 * @param[in] ch Channel (use PRS_CHx)
 * @see prs_set_output_loc()
 */
void prs_disable_gpio_output(enum prs_ch ch)
{
	PRS_ROUTE &= ~PRS_ROUTE_CHxPEN(ch);
}

/**
 * Location of the PRS to be output on GPIO.
 * @param[in] loc location (use PRS_ROUTE_LOCATION_LOCx)
 * @see prs_set_output_loc()
 */
void prs_set_output_loc(uint32_t loc)
{
	PRS_ROUTE = (PRS_ROUTE & ~PRS_ROUTE_LOCATION_MASK) | loc;
}

/**
 * Generate software pulse.
 * @param[in] ch Channel (use PRS_CHx)
 * @note the final output is dependent on "software level" value of the channel
 * @see prs_software_level_high()
 * @see prs_software_level_low()
 */
void prs_software_pulse(enum prs_ch ch)
{
	PRS_SWPULSE = PRS_SWPULSE_CHxPULSE(ch);
}

/**
 * HIGH is XOR'ed with the corresponding bit in the software-pulse and
 *  the PRS input signal to generate.
 * @param[in] ch Channel (use PRS_CHx)
 * @see prs_software_level_low()
 * @see prs_software_pulse()
 */
void prs_software_level_high(enum prs_ch ch)
{
	PRS_SWLEVEL |= PRS_SWLEVEL_CHxLEVEL(ch);
}

/**
 * LOW is XOR'ed with the corresponding bit in the software-pulse and
 *  the PRS input signal to generate.
 * @param[in] ch Channel (use PRS_CHx)
 * @see prs_software_level_high()
 * @see prs_software_pulse()
 */
void prs_software_level_low(enum prs_ch ch)
{
	PRS_SWLEVEL &= ~PRS_SWLEVEL_CHxLEVEL(ch);
}

/**
 * disable synchronization of this channel reflex signal
 * @param[in] ch Channel (use PRS_CHx)
 * @see prs_disable_async()
 */
void prs_enable_async(enum prs_ch ch)
{
	PRS_CHx_CTRL(ch) |= PRS_CH_CTRL_ASYNC;
}

/**
 * enable synchronization of this channel reflex signal
 * @param[in] ch Channel (use PRS_CHx)
 * @see prs_disable_async()
 */
void prs_disable_async(enum prs_ch ch)
{
	PRS_CHx_CTRL(ch) &= ~PRS_CH_CTRL_ASYNC;
}

/**
 * Edge detection for the channel
 * @param[in] ch Channel (use PRS_CHx)
 * @param[in] edge Edge (use PRS_CH_CTRL_EDSEL_*)
 */
void prs_set_edge(enum prs_ch ch, uint32_t edge)
{
	PRS_CHx_CTRL(ch) = (PRS_CHx_CTRL(ch) & ~PRS_CH_CTRL_EDSEL_MASK) | edge;
}

/**
 * Source for the channel
 * @param[in] ch Channel (use PRS_CHx)
 * @param[in] source Source (use PRS_CH_CTRL_SOURCESEL_*)
 * @see prs_set_signal()
 */
void prs_set_source(enum prs_ch ch, uint32_t source)
{
	PRS_CHx_CTRL(ch) = (PRS_CHx_CTRL(ch) & ~PRS_CH_CTRL_SOURCESEL_MASK)
			   | source;
}

/**
 * Source for the channel
 * @param[in] ch Channel (use PRS_CHx)
 * @param[in] signal Signal (use PRS_CH_CTRL_SIGSEL_*)
 * @see prs_set_source()
 */
void prs_set_signal(enum prs_ch ch, uint32_t signal)
{
	PRS_CHx_CTRL(ch) = (PRS_CHx_CTRL(ch) & ~PRS_CH_CTRL_SIGSEL_MASK)
			   | signal;
}
