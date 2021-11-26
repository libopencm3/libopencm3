/** @addtogroup ppi_file PPI peripheral API
 *
 * @brief <b>Access functions for the Programmable Peripheral Interconnect </b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#include <stdint.h>

#include <libopencm3/nrf/ppi.h>
/**@{*/

/** @brief Configure PPI Channel.
 *
 * @param[in] chan_num uint8_t Channel number (0-15).
 * @param[in] eep uint32_t Event endpoint. Memory address of the event endpoint.
 * @param[in] tep uint32_t Task endpoint. Memory address of the task endpoint.
 */
void ppi_configure_channel(uint8_t chan_num, uint32_t eep, uint32_t tep)
{
	PPI_CH_EEP(chan_num) = eep;
	PPI_CH_TEP(chan_num) = tep;
}

/** @brief Enable PPI channels, given the channels mask.
 *
 * @param[in] channels uint32_t mask of the channels to enable.
 */
void ppi_enable_channels(uint32_t channels)
{
	PPI_CHENSET = channels;
}

/** @brief Disable PPI channels, given the channels mask.
 *
 * @param[in] channels uint32_t mask of the channels to disable.
 */
void ppi_disable_channels(uint32_t channels)
{
	PPI_CHENCLR = channels;
}

/** @brief Set channels group, given channels mask.
 *
 * @param[in] group uint8_t group number (0-3)
 * @param[in] channels uint32_t mask of the channels to group together.
 */
void ppi_set_group(uint8_t group, uint32_t channels)
{
	PPI_CHG(group) = channels;
}

/** @brief Enable previously configured group of channels.
 *
 * @param[in] group uint8_t group number (0-3)
 */
void ppi_enable_group(uint8_t group)
{
	PPI_TASK_CHG_EN(group) = 1;
}

/** @brief Disable previously configured group of channels.
 *
 * @param[in] group uint8_t group number (0-3)
 */
void ppi_disable_group(uint8_t group)
{
	PPI_TASK_CHG_DIS(group) = 1;
}

/** @brief Configure new channel.
 *
 * This is the alternative API, which requires the caller to store the mask of used channels.
 *
 * @param chan_map uint32_t* The mask of channels that are already in use.
 *  For the first call initialize with zero and pass in.
 * @param[in] eep uint32_t Event endpoint.
 * @param[in] tep uint32_t Task endpoint.
 * @param enable bool If true, enable the channel immediately.
 * @return The number of the new channel. If there are no channels available, returns 0xff.
 */
uint8_t ppi_add_channel(uint32_t *chan_map, uint32_t eep, uint32_t tep, bool enable)
{
	/* Find a free channel */
	uint8_t i;
	uint32_t chan_bit;
	for (i = 0, chan_bit = 1; i <= PPI_MAX_PROG_CHANNEL; ++i, chan_bit <<= 1) {
		if (!(chan_bit & *chan_map)) {
			*chan_map |= chan_bit;
			break;
		}
	}

	/* If all channels are taken, return error. */
	if (i > PPI_MAX_PROG_CHANNEL) {
		return 0xff;
	}

	ppi_configure_channel(i, eep, tep);
	if (enable) {
		ppi_enable_channels(chan_bit);
	}

	return i;
}

/** @brief Disable channel and remove it from the map of used channels.
 *
 * This is the alternative API, which requires the caller to store the mask of used channels.
 *
 * @param chan_map uint32_t* The mask of channels that are already in use.
 *  For the first call initialize with zero and pass in.
 * @param[in] chan_num uint8_t the number of the channel to remove from the map.
 */
void ppi_remove_channel(uint32_t *chan_map, uint8_t chan_num)
{
	ppi_disable_channels(PPI_CH(chan_num));
	*chan_map &= ~(PPI_CH(chan_num));
}
/**@}*/

