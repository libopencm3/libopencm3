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

#include "usbh-private.h"

usbh_urb_id usbh_transfer_submit(const usbh_transfer *transfer)
{
	usbh_host *host = transfer->device->host;

	if (transfer->ep_type == USBH_EP_CONTROL) {
		if (transfer->length != transfer->setup.wLength) {
			LOG_LN("for setup, transfer length and wLength should match");
			TRANSFER_INVALID(transfer);
			return USBH_INVALID_URB_ID;
		}

		if ((transfer->setup.bmRequestType & USB_REQ_TYPE_DIRECTION) &&
				!transfer->setup.wLength) {
			/* Control IN with no data do not make sense
			 *  and is not valid as per specs!
			 * usb_20.pdf p226 "Figure 8-37. Control Read and Write Sequences" */
			LOG_LN("Warning: device-to-host bit set for wLength = 0");
			TRANSFER_INVALID(transfer);
			return USBH_INVALID_URB_ID;
		}
	}

	if (transfer->ep_type == USBH_EP_INTERRUPT ||
		transfer->ep_type == USBH_EP_ISOCHRONOUS) {
		if (!transfer->interval) {
			/* Interval = 0 do not make any sense! */
			LOG_LN("Warning: interval should be greater than 0 "
				"for isochronous/interrupt endpoints");
			TRANSFER_INVALID(transfer);
			return USBH_INVALID_URB_ID;
		}
	}

	/* Low speed device capabilities check. */
	if (transfer->device->speed == USBH_SPEED_LOW) {
		usbh_ep_type et = transfer->ep_type;
		if (et != USBH_EP_CONTROL && et != USBH_EP_INTERRUPT) {
			LOG_LN("USB low-speed ONLY support control/interrupt endpoint");
			TRANSFER_INVALID(transfer);
			return USBH_INVALID_URB_ID;
		}
	}

	/* Search for a free URB */
	usbh_urb *urb = NULL;
	for (unsigned i = 0; i < URB_ARRAY_LENGTH; i++) {
		usbh_urb *tmp = &host->urbs[i];
		if (IS_URB_INVALID(tmp)) {
			LOGF_LN("urb at offset %"PRIu8" is currently unused", i);
			urb = tmp;
			break;
		}
	}

	/* check if got any URB free */
	if (urb == NULL) {
		LOG_LN("problem, all urb in use");
		TRANSFER_NO_RES(transfer);
		return USBH_INVALID_URB_ID;
	}

	/* store the information in URB */
	urb->id = host->next_urb_id++;
	urb->transfer = *transfer;
	urb->transfer.transferred = 0;
	urb->timeout_on = transfer->timeout ?
		(host->last_poll + MS2US(transfer->timeout)) : 0;
	urb->backend_tag = INVALID_BACKEND_TAG;

	LOGF_LN("Create URB with id = %"PRIu64, urb->id);

	host->backend->transfer_submit(host, urb);

	return urb->id;
}

void usbh_transfer_cancel(usbh_host *host, usbh_urb_id urb_id)
{
	if (IS_URB_ID_INVALID(urb_id)) {
		LOG_LN("invalid urb id passed to transfer_cancel");
		return;
	}

	for (unsigned i = 0; i < URB_ARRAY_LENGTH; i++) {
		usbh_urb *urb = &host->urbs[i];
		if (urb->id == urb_id) {
			LOGF_LN("urb %"PRIu64" cancelled", urb->id);
			usbh_urb_free(urb, USBH_ERR_CANCEL);
			return;
		}
	}

	LOGF_LN("WARNING: urb with id = %"PRIu64" not found", urb_id);
}
