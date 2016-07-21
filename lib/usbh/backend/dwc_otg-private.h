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

#ifndef LIBOPENCM3_USBH_BACKEND_DWC_OTG_H
#define LIBOPENCM3_USBH_BACKEND_DWC_OTG_H

#include "../usbh-private.h"
#include <libopencm3/usb/usbstd.h>

/**
 * The channel will move around with different states.
 * Bulk/isochronous/interrupt have only one state.
 * where as control have multiple states
 */
enum usbh_dwc_otg_chan_state {
	/** Channel is free */
	USBH_DWC_OTG_CHAN_STATE_FREE,

	/** Channel is cancelled but not free.
	 *  When a CHH interrupt is received, we can assume the channel as free */
	USBH_DWC_OTG_CHAN_STATE_CANCELLED,

	/** path1: setup -> STATUS_IN
	 *  path2: setup -> DATA_IN -> STATUS_OUT
	 *  path3: setup -> DATA_OUT -> STATUS_IN */
	USBH_DWC_OTG_CHAN_STATE_CTRL_SETUP,

	/** data read -> STATUS_OUT */
	USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_IN,

	/** data write -> STATUS_IN */
	USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_OUT,

	/** read 0 byte */
	USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_IN,

	/** write 0 byte */
	USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_OUT,

	/** for bulk/isochronous/interrupt perform callback when done.
	 *  note: periph does not differentiate at the IO level */
	USBH_DWC_OTG_CHAN_STATE_CALLBACK,
};

typedef enum usbh_dwc_otg_chan_state usbh_dwc_otg_chan_state;

struct usbh_dwc_otg_chan {
	usbh_urb *urb; /* prevent lookup */
	usbh_dwc_otg_chan_state state;

	/* the channel is on hold.
	 *  the channel need to be enabled
	 *  so that IO can be performed in "submit_frame".
	 *  Only used for periodic endpoint (isochronous and interrupt) */
	bool need_scheduling;

	/* The frame in which the frame is submitted OR has to be submitted.
	 *  Only used for periodic endpoint (isochronous and interrupt) */
	uint16_t submit_frame;
};

typedef struct usbh_dwc_otg_chan usbh_dwc_otg_chan;

struct usbh_dwc_otg_priv {
	uint32_t base_address;

	/* Note: All sizes are in 32-bit words */
	struct {
		uint16_t rx; /* Receive size */
		uint16_t tx_np; /* Transmit non-periodic */
		uint16_t tx_p; /* Transmit periodic */
	} fifo_size;

	uint64_t wait_till;

	uint8_t channels_count;
	usbh_dwc_otg_chan *channels;
};

typedef struct usbh_dwc_otg_priv usbh_dwc_otg_priv;

void usbh_dwc_otg_init(usbh_host *host);
void usbh_dwc_otg_poll(usbh_host *host, uint64_t now);
usbh_speed usbh_dwc_otg_speed(usbh_host *host);
void usbh_dwc_otg_reset(usbh_host *host);

void usbh_dwc_otg_transfer_submit(usbh_host *host, usbh_urb *urb);
void usbh_dwc_otg_transfer_cancel(usbh_host *host, usbh_urb *urb);

#endif
