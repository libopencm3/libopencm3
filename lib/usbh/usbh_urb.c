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

#if defined(USBH_DEBUG)
static const char *stringify_transfer_status(usbh_transfer_status status) {
	switch (status) {
	case USBH_ONE_PACKET_DATA: return "USBH_ONE_PACKET_DATA";
	case USBH_SUCCESS: return "USBH_SUCCESS";
	case USBH_ERR_TIMEOUT: return "USBH_ERR_TIMEOUT";
	case USBH_ERR_IO: return "USBH_ERR_IO";
	case USBH_ERR_SIZE: return "USBH_ERR_SIZE";
	case USBH_ERR_STALL: return "USBH_ERR_STALL";
	case USBH_ERR_RES_UNAVAIL: return "USBH_ERR_RES_UNAVAIL";
	case USBH_ERR_NO_DEVICE: return "USBH_ERR_NO_DEVICE";
	case USBH_ERR_BABBLE: return "USBH_ERR_BABBLE";
	case USBH_ERR_DTOG: return "USBH_ERR_DTOG";
	case USBH_ERR_SHORT_PACKET: return "USBH_ERR_SHORT_PACKET";
	case USBH_ERR_INVALID: return "USBH_ERR_INVALID";
	case USBH_ERR_CANCEL: return "USBH_ERR_CANCEL";
	default: return "**UNKNOWN**";
	}
}
#endif

/**
 * Invalidate the URB.
 * It will mark this as free for other use
 * @param urb USB Request Block
 */
void usbh_urb_invalidate(usbh_urb *urb)
{
	urb->id = USBH_INVALID_URB_ID;
}

/**
 * Free the URB as it purpose has been served.
 * @param urb USB Request Block
 * @param status Transfer status to provide to callback
 */
void usbh_urb_free(usbh_urb *urb, usbh_transfer_status status)
{
	LOG_CALL

	usbh_urb_id cached_urb_id = urb->id;
	urb->id = USBH_INVALID_URB_ID;

	if (urb->backend_tag != INVALID_BACKEND_TAG) {
		usbh_host *host = urb->transfer.device->host;
		host->backend->transfer_cancel(host, urb);
	}

	LOGF_LN("URB %"PRIu64" transfer status = %s", cached_urb_id,
		stringify_transfer_status(status));

	if (urb->transfer.callback != NULL) {
		if (urb->transfer.flags & USBH_FLAG_NO_SUCCESS_CALLBACK) {
			if (status == USBH_SUCCESS) {
				return;
			}
		}

		const usbh_transfer transfer = urb->transfer; /* incase got overwritten */
		transfer.callback(&transfer, status, cached_urb_id);
	}
}

/**
 * Get the transfer direction
 * @param transfer USB Transfer
 * @return true if out, false on in
 */
static bool transfer_dir(const usbh_transfer *transfer)
{
	if (transfer->ep_type == USBH_EP_CONTROL) {
		return !(transfer->setup.bmRequestType & USB_REQ_TYPE_DIRECTION);
	} else {
		return IS_OUT_ENDPOINT(transfer->ep_addr);
	}
}

/**
 * Called by backend to get a pointer to receive/transmit 1 packet
 * @param urb USB Request Block
 * @param len The number of bytes it should be able to hold/provide
 * @return pointer to data
 */
void *usbh_urb_get_data_pointer(usbh_urb *urb, uint16_t len)
{
	usbh_transfer *transfer = &urb->transfer;
	bool out = transfer_dir(transfer);

#if defined(USBH_DEBUG)
	if ((transfer->transferred + len) > transfer->length) {
		LOGF_LN("URB %"PRIu64" buffer overflow detected! "
			"(backend want to %s %"PRIu16" bytes to buffer)", urb->id,
			out ? "read" : "write", len);
		LOGF_LN("transfer->length: %"PRIu16, transfer->length);
		LOGF_LN("transfer->transferred: %"PRIu16, transfer->transferred);
	}
#else
	(void) len;
#endif

	if (transfer->flags & USBH_FLAG_PER_PACKET_CALLBACK) {
		if (out) {
			/* OUT endpoint, get data from user */
			URB_CALLBACK(urb, USBH_ONE_PACKET_DATA);
		}
	}

	if (transfer->flags & USBH_FLAG_NO_MEMORY_INCREMENT) {
		/* User said to reuse same buffer location everytime. */
		return transfer->data;
	}

	return transfer->data + transfer->transferred;
}

/**
 * Called by backend when it get data
 * @param urb USB Request Block
 * @param len
 */
void usbh_urb_inc_data_pointer(usbh_urb *urb, uint16_t len)
{
	usbh_transfer *transfer = &urb->transfer;
	bool out = transfer_dir(transfer);


#if defined(USBH_DEBUG)
	if ((transfer->transferred + len) > transfer->length) {
		LOGF_LN("URB %"PRIu64" buffer overflow detected! "
			"(backend is reporting that it has %s %"PRIu16" bytes)", urb->id,
			out ? "readed" : "written", len);
		LOGF_LN("transfer->length: %"PRIu16, transfer->length);
		LOGF_LN("transfer->transferred: %"PRIu16, transfer->transferred);
	}
#endif

	transfer->transferred += len;

	if (transfer->flags & USBH_FLAG_PER_PACKET_CALLBACK) {
		if (!out) {
			/* IN endpoint, give data to user */
			URB_CALLBACK(urb, USBH_ONE_PACKET_DATA);
		}
	}
}
