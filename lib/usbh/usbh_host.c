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

usbh_host *usbh_init(const usbh_backend *backend)
{
	usbh_host *host = backend->init();

	host->backend = backend;
	host->connected = NULL;
	host->last_poll = 0;
	host->next_device_address = 1;
	host->next_urb_id = 1;

	for (unsigned i = 0; i < DEVICE_ARRAY_LENGTH; i++) {
		usbh_device_invalidate(&host->devices[i]);
	}

	for (unsigned i = 0; i < URB_ARRAY_LENGTH; i++) {
		usbh_urb_invalidate(&host->urbs[i]);
	}

	return host;
}

static void poll_urb(usbh_host *host, uint64_t now)
{
	for (unsigned i = 0; i < URB_ARRAY_LENGTH; i++) {
		usbh_urb *urb = &host->urbs[i];

		/* check if the URB is even valid */
		if (IS_URB_INVALID(urb)) {
			continue;
		}

		/* check if the transfer has time'd out */
		if (urb->timeout_on && now >= urb->timeout_on) {
			LOGF_LN("urb %"PRIu64" time'd out", urb->id);
			usbh_urb_free(urb, USBH_ERR_TIMEOUT);
			continue;
		}

		/* get a channel from the backend for the URB */
		if (urb->backend_tag == INVALID_BACKEND_TAG) {
			LOGF_LN("try to submit urb %"PRIu64" to backend", urb->id);
			host->backend->transfer_submit(host, urb);
			continue;
		}
	}
}

void usbh_poll(usbh_host *host, uint32_t us)
{
	uint64_t now = host->last_poll + us;
	host->backend->poll(host, now);
	poll_urb(host, now);
	host->last_poll = now;
}

void usbh_register_connected_callback(usbh_host *host,
		usbh_connected_callback connected)
{
	host->connected = connected;
}
