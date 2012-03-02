/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <string.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

void usbd_register_set_config_callback(void (*callback)(u16 wValue))
{
	_usbd_device.user_callback_set_config = callback;
}

static u16 build_config_descriptor(u8 index, u8 *buf, u16 len)
{
	u8 *tmpbuf = buf;
	const struct usb_config_descriptor *cfg = &_usbd_device.config[index];
	u16 count, total = 0, totallen = 0;
	u16 i, j, k;

	memcpy(buf, cfg, count = MIN(len, cfg->bLength));
	buf += count;
	len -= count;
	total += count;
	totallen += cfg->bLength;

	/* For each interface... */
	for (i = 0; i < cfg->bNumInterfaces; i++) {
		/* Interface Association Descriptor, if any */
		if (cfg->interface[i].iface_assoc) {
			const struct usb_iface_assoc_descriptor *assoc = 
					cfg->interface[i].iface_assoc;
			memcpy(buf, assoc, count = MIN(len, assoc->bLength));
			buf += count;
			len -= count;
			total += count;
			totallen += assoc->bLength;
		}
		/* For each alternate setting... */
		for (j = 0; j < cfg->interface[i].num_altsetting; j++) {
			const struct usb_interface_descriptor *iface =
					&cfg->interface[i].altsetting[j];
			/* Copy interface descriptor. */
			memcpy(buf, iface, count = MIN(len, iface->bLength));
			buf += count;
			len -= count;
			total += count;
			totallen += iface->bLength;
			/* Copy extra bytes (function descriptors). */
			memcpy(buf, iface->extra,
			       count = MIN(len, iface->extralen));
			buf += count;
			len -= count;
			total += count;
			totallen += iface->extralen;
			/* For each endpoint... */
			for (k = 0; k < iface->bNumEndpoints; k++) {
				const struct usb_endpoint_descriptor *ep =
				    &iface->endpoint[k];
				memcpy(buf, ep, count = MIN(len, ep->bLength));
				buf += count;
				len -= count;
				total += count;
				totallen += ep->bLength;
			}
		}
	}

	/* Fill in wTotalLength. */
	*(u16 *)(tmpbuf + 2) = totallen;

	return total;
}

static int usb_standard_get_descriptor(struct usb_setup_data *req,
				       u8 **buf, u16 *len)
{
	int i;
	struct usb_string_descriptor *sd;

	switch (req->wValue >> 8) {
	case USB_DT_DEVICE:
		*buf = (u8 *) _usbd_device.desc;
		*len = MIN(*len, _usbd_device.desc->bLength);
		return 1;
	case USB_DT_CONFIGURATION:
		*buf = _usbd_device.ctrl_buf;
		*len = build_config_descriptor(req->wValue & 0xff, *buf, *len);
		return 1;
	case USB_DT_STRING:
		sd = (struct usb_string_descriptor *)_usbd_device.ctrl_buf;

		if (!_usbd_device.strings)
			return 0; /* Device doesn't support strings. */

		/* Check that string index is in range. */
		for (i = 0; i <= (req->wValue & 0xff); i++)
			if (_usbd_device.strings[i] == NULL)
				return 0;

		sd->bLength = strlen(_usbd_device.strings[req->wValue & 0xff])
				* 2 + 2;
		sd->bDescriptorType = USB_DT_STRING;

		*buf = (u8 *)sd;
		*len = MIN(*len, sd->bLength);

		for (i = 0; i < (*len / 2) - 1; i++)
			sd->wData[i] =
			    _usbd_device.strings[req->wValue & 0xff][i];

		/* Send sane Language ID descriptor... */
		if ((req->wValue & 0xff) == 0)
			sd->wData[0] = 0x409;

		return 1;
	}
	return 0;
}

static int usb_standard_set_address(struct usb_setup_data *req, u8 **buf,
				    u16 *len)
{
	(void)req;
	(void)buf;
	(void)len;

	/* The actual address is only latched at the STATUS IN stage. */
	if ((req->bmRequestType != 0) || (req->wValue >= 128))
		return 0;

	_usbd_device.current_address = req->wValue;

	/*
	 * Special workaround for STM32F10[57] that require the address
	 * to be set here. This is undocumented!
	 */
	if (_usbd_device.driver == &stm32f107_usb_driver)
		_usbd_device.driver->set_address(req->wValue);

	return 1;
}

static int usb_standard_set_configuration(struct usb_setup_data *req,
					  u8 **buf, u16 *len)
{
	int i;

	(void)req;
	(void)buf;
	(void)len;

	/* Is this correct, or should we reset alternate settings. */
	if (req->wValue == _usbd_device.current_config)
		return 1;

	_usbd_device.current_config = req->wValue;

	/* Reset all endpoints. */
	_usbd_hw_endpoints_reset();

	if (_usbd_device.user_callback_set_config) {
		/*
		 * Flush control callbacks. These will be reregistered
		 * by the user handler.
		 */
		for (i = 0; i < MAX_USER_CONTROL_CALLBACK; i++)
			_usbd_device.user_control_callback[i].cb = NULL;

		_usbd_device.user_callback_set_config(req->wValue);
	}

	return 1;
}

static int usb_standard_get_configuration(struct usb_setup_data *req,
					  u8 **buf, u16 *len)
{
	(void)req;

	if (*len > 1)
		*len = 1;
	(*buf)[0] = _usbd_device.current_config;

	return 1;
}

static int usb_standard_set_interface(struct usb_setup_data *req,
				      u8 **buf, u16 *len)
{
	(void)req;
	(void)buf;

	/* FIXME: Adapt if we have more than one interface. */
	if (req->wValue != 0)
		return 0;
	*len = 0;

	return 1;
}

static int usb_standard_get_interface(struct usb_setup_data *req,
				      u8 **buf, u16 *len)
{
	(void)req;
	(void)buf;

	/* FIXME: Adapt if we have more than one interface. */
	*len = 1;
	(*buf)[0] = 0;

	return 1;
}

static int usb_standard_device_get_status(struct usb_setup_data *req,
					  u8 **buf, u16 *len)
{
	(void)req;

	/* bit 0: self powered */
	/* bit 1: remote wakeup */
	if (*len > 2)
		*len = 2;
	(*buf)[0] = 0;
	(*buf)[1] = 0;

	return 1;
}

static int usb_standard_interface_get_status(struct usb_setup_data *req,
					     u8 **buf, u16 *len)
{
	(void)req;
	/* not defined */

	if (*len > 2)
		*len = 2;
	(*buf)[0] = 0;
	(*buf)[1] = 0;

	return 1;
}

static int usb_standard_endpoint_get_status(struct usb_setup_data *req,
					    u8 **buf, u16 *len)
{
	(void)req;

	if (*len > 2)
		*len = 2;
	(*buf)[0] = usbd_ep_stall_get(req->wIndex) ? 1 : 0;
	(*buf)[1] = 0;

	return 1;
}

static int usb_standard_endpoint_stall(struct usb_setup_data *req,
				       u8 **buf, u16 *len)
{
	(void)buf;
	(void)len;

	usbd_ep_stall_set(req->wIndex, 1);

	return 1;
}

static int usb_standard_endpoint_unstall(struct usb_setup_data *req,
					 u8 **buf, u16 *len)
{
	(void)buf;
	(void)len;

	usbd_ep_stall_set(req->wIndex, 0);

	return 1;
}

int _usbd_standard_request_device(struct usb_setup_data *req, u8 **buf,
				  u16 *len)
{
	int (*command)(struct usb_setup_data *req, u8 **buf, u16 *len) = NULL;

	switch (req->bRequest) {
	case USB_REQ_CLEAR_FEATURE:
	case USB_REQ_SET_FEATURE:
		if (req->wValue == USB_FEAT_DEVICE_REMOTE_WAKEUP) {
			/* Device wakeup code goes here. */
		}
		if (req->wValue == USB_FEAT_TEST_MODE) {
			/* Test mode code goes here. */
		}
		break;
	case USB_REQ_SET_ADDRESS:
		/*
		 * SET ADDRESS is an exception.
		 * It is only processed at STATUS stage.
		 */
		command = usb_standard_set_address;
		break;
	case USB_REQ_SET_CONFIGURATION:
		command = usb_standard_set_configuration;
		break;
	case USB_REQ_GET_CONFIGURATION:
		command = usb_standard_get_configuration;
		break;
	case USB_REQ_GET_DESCRIPTOR:
		command = usb_standard_get_descriptor;
		break;
	case USB_REQ_GET_STATUS:
		/*
		 * GET_STATUS always responds with zero reply.
		 * The application may override this behaviour.
		 */
		command = usb_standard_device_get_status;
		break;
	case USB_REQ_SET_DESCRIPTOR:
		/* SET_DESCRIPTOR is optional and not implemented. */
		break;
	}

	if (!command)
		return 0;

	return command(req, buf, len);
}

int _usbd_standard_request_interface(struct usb_setup_data *req, u8 **buf,
				     u16 *len)
{
	int (*command)(struct usb_setup_data *req, u8 **buf, u16 *len) = NULL;

	switch (req->bRequest) {
	case USB_REQ_CLEAR_FEATURE:
	case USB_REQ_SET_FEATURE:
		/* not defined */
		break;
	case USB_REQ_GET_INTERFACE:
		command = usb_standard_get_interface;
		break;
	case USB_REQ_SET_INTERFACE:
		command = usb_standard_set_interface;
		break;
	case USB_REQ_GET_STATUS:
		command = usb_standard_interface_get_status;
		break;
	}

	if (!command)
		return 0;

	return command(req, buf, len);
}

int _usbd_standard_request_endpoint(struct usb_setup_data *req, u8 **buf,
				    u16 *len)
{
	int (*command) (struct usb_setup_data *req, u8 **buf, u16 *len) = NULL;

	switch (req->bRequest) {
	case USB_REQ_CLEAR_FEATURE:
		if (req->wValue == USB_FEAT_ENDPOINT_HALT)
			command = usb_standard_endpoint_unstall;
		break;
	case USB_REQ_SET_FEATURE:
		if (req->wValue == USB_FEAT_ENDPOINT_HALT)
			command = usb_standard_endpoint_stall;
		break;
	case USB_REQ_GET_STATUS:
		command = usb_standard_endpoint_get_status;
		break;
	case USB_REQ_SET_SYNCH_FRAME:
		/* FIXME: SYNCH_FRAME is not implemented. */
		/*
		 * SYNCH_FRAME is used for synchronization of isochronous
		 * endpoints which are not yet implemented.
		 */
		break;
	}

	if (!command)
		return 0;

	return command(req, buf, len);
}

int _usbd_standard_request(struct usb_setup_data *req, u8 **buf, u16 *len)
{
	/* FIXME: Have class/vendor requests as well. */
	if ((req->bmRequestType & USB_REQ_TYPE_TYPE) != USB_REQ_TYPE_STANDARD)
		return 0;

	switch (req->bmRequestType & USB_REQ_TYPE_RECIPIENT) {
	case USB_REQ_TYPE_DEVICE:
		return _usbd_standard_request_device(req, buf, len);
	case USB_REQ_TYPE_INTERFACE:
		return _usbd_standard_request_interface(req, buf, len);
	case USB_REQ_TYPE_ENDPOINT:
		return _usbd_standard_request_endpoint(req, buf, len);
	default:
		return 0;
	}
}
