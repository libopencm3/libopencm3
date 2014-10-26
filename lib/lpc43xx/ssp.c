/** @defgroup ssp_file SSP

@ingroup LPC43xx

@brief <b>libopencm3 LPC43xx SSP</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Benjamin Vernoux <titanmkd@gmail.com>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#include <libopencm3/lpc43xx/ssp.h>
#include <libopencm3/lpc43xx/cgu.h>

/* Disable SSP */
void ssp_disable(ssp_num_t ssp_num)
{
	uint32_t ssp_port;

	if (ssp_num == SSP0_NUM) {
		ssp_port = SSP0;
	} else {
		ssp_port = SSP1;
	}
	/* Disable SSP */
	SSP_CR1(ssp_port) = 0x0;
}

/*
* SSP Init function
*/
void ssp_init(ssp_num_t ssp_num,
			ssp_datasize_t data_size,
			ssp_frame_format_t frame_format,
			ssp_cpol_cpha_t cpol_cpha_format,
			uint8_t serial_clock_rate,
			uint8_t clk_prescale,
			ssp_mode_t mode,
			ssp_master_slave_t master_slave,
			ssp_slave_option_t slave_option)
{
	uint32_t ssp_port;
	uint32_t clock;

	if (ssp_num == SSP0_NUM) {
		ssp_port = SSP0;
	} else {
		ssp_port = SSP1;
	}

	/* use PLL1 as clock source for SSP1 */
	CGU_BASE_SSP1_CLK =
		  CGU_BASE_SSP1_CLK_CLK_SEL(CGU_SRC_PLL1)
		| CGU_BASE_SSP1_CLK_AUTOBLOCK;

	/* Disable SSP before to configure it */
	SSP_CR1(ssp_port) = 0x0;

	/* Configure SSP */
	clock = serial_clock_rate;
	SSP_CPSR(ssp_port) = clk_prescale;
	SSP_CR0(ssp_port) =
		(data_size | frame_format | cpol_cpha_format | (clock<<8));

	/* Enable SSP */
	SSP_CR1(ssp_port) = (SSP_ENABLE | mode | master_slave | slave_option);
}

static void ssp_wait_until_not_busy(ssp_num_t ssp_num)
{
	uint32_t ssp_port;

	if (ssp_num == SSP0_NUM) {
		ssp_port = SSP0;
	} else {
		ssp_port = SSP1;
	}

	while ((SSP_SR(ssp_port) & SSP_SR_BSY));
}

/* This Function Wait Data TX Ready, and Write Data to SSP */
uint16_t ssp_transfer(ssp_num_t ssp_num, uint16_t data)
{
	uint32_t ssp_port;

	if (ssp_num == SSP0_NUM) {
		ssp_port = SSP0;
	} else {
		ssp_port = SSP1;
	}

	/* Wait Until FIFO not full  */
	while ((SSP_SR(ssp_port) & SSP_SR_TNF) == 0);

	SSP_DR(ssp_port) = data;

	/* Wait for not busy, since we're controlling CS# of
	 * devices manually and need to wait for the data to
	 * be sent. It may also be important to wait here
	 * in case we're configuring devices via SPI and also
	 * with GPIO control -- we need to know when SPI
	 * commands are effective before altering a device's
	 * state with GPIO. I'm thinking the MAX2837, for
	 * example...
	 */
	ssp_wait_until_not_busy(ssp_num);

	/* Wait Until Data Received (Rx FIFO not Empty) */
	while ((SSP_SR(ssp_port) & SSP_SR_RNE) == 0);

	return SSP_DR(ssp_port);
}


/**@}*/

