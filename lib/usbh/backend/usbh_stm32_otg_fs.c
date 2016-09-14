/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include "dwc_otg-private.h"
#include <libopencm3/stm32/memorymap.h>

static usbh_host host;

#define NUM_OF_CHANNELS 8

static usbh_dwc_otg_chan channels[NUM_OF_CHANNELS];

/* `host.backend_data` is usually used for information that is in RAM.
 *  but since all below data is constant, making it "const". */
static usbh_dwc_otg_priv private_data = {
	.base_address = USB_OTG_FS_BASE,

	.fifo_size = {
		.rx = 160,
		.tx_np = 76,
		.tx_p = 76
	},

	.channels_count = NUM_OF_CHANNELS,
	.channels = channels
};

static usbh_host *init(void)
{
	host.backend_data = &private_data;
	usbh_dwc_otg_init(&host);

	return &host;
}

usbh_backend usbh_stm32_otg_fs = {
	.init = init,
	.poll = usbh_dwc_otg_poll,
	.speed = usbh_dwc_otg_speed,
	.reset = usbh_dwc_otg_reset,
	.transfer_submit = usbh_dwc_otg_transfer_submit,
	.transfer_cancel = usbh_dwc_otg_transfer_cancel,
};
