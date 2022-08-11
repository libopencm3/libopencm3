/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Rachel Mant <git@dragonmux.network>
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

#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/microsoft.h>
#include "usb_private.h"

static enum usbd_request_return_codes microsoft_os_get_descriptor_set(usbd_device *const usbd_dev,
	struct usb_setup_data *const req, uint8_t **const buf, uint16_t *const len)
{
	const microsoft_os_descriptor_set_header *sets = usbd_dev->microsoft_os_descriptor_sets;
	for (size_t i = 0; i < usbd_dev->num_microsoft_os_descriptor_sets; ++i) {
		//
	}
	return USBD_REQ_NOTSUPP;
}

static enum usbd_request_return_codes microsoft_os_control_request(usbd_device *const usbd_dev,
	struct usb_setup_data *const req, uint8_t **const buf, uint16_t *const len)
{
	switch (req->wIndex) {
	case MICROSOFT_GET_DESCRIPTOR_SET:
		return microsoft_os_get_descriptor_set(usbd_dev, req, buf, len);
	case MICROSOFT_SET_ALTERNATE_ENUM:
		return USBD_REQ_NOTSUPP;
	}
	return USBD_REQ_NEXT_CALLBACK;
}

void microsoft_os_register_descriptor_sets(usbd_device *const dev,
	const microsoft_os_descriptor_set_header *const sets, const uint8_t num_sets)
{
	dev->microsoft_os_req_callback = microsoft_os_control_request;
	dev->microsoft_os_descriptor_sets = sets;
	dev->num_microsoft_os_descriptor_sets = num_sets;
}
