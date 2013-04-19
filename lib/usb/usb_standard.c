/** @defgroup usb_standard_file Generic USB Standard Request Interface

@ingroup USB

@brief <b>Generic USB Standard Request Interface</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Gareth McMullin <gareth@blacksphere.co.nz>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
*/

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

/**@{*/

#include <string.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

void usbd_register_set_config_callback(usbd_device *usbd_dev,
				       void (*callback)(usbd_device *usbd_dev,
					       		u16 wValue))
{
	usbd_dev->user_callback_set_config = callback;
}

static u16 build_config_descriptor(usbd_device *usbd_dev,
				   u8 index, u8 *buf, u16 len)
{
	u8 *tmpbuf = buf;
	const struct usb_config_descriptor *cfg = &usbd_dev->config[index];
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

static int usb_descriptor_type(u16 wValue)
{
	return wValue >> 8;
}

static int usb_descriptor_index(u16 wValue)
{
	return wValue & 0xFF;
}

static int usb_standard_get_descriptor(usbd_device *usbd_dev,
				       struct usb_setup_data *req,
				       u8 **buf, u16 *len)
{
	int i, array_idx, descr_idx;
	struct usb_string_descriptor *sd;

	descr_idx = usb_descriptor_index(req->wValue);

	switch (usb_descriptor_type(req->wValue)) {
	case USB_DT_DEVICE:
		*buf = (u8 *) usbd_dev->desc;
		*len = MIN(*len, usbd_dev->desc->bLength);
		return USBD_REQ_HANDLED;
	case USB_DT_CONFIGURATION:
		*buf = usbd_dev->ctrl_buf;
		*len = build_config_descriptor(usbd_dev, descr_idx, *buf, *len);
		return USBD_REQ_HANDLED;
	case USB_DT_STRING:
		sd = (struct usb_string_descriptor *)usbd_dev->ctrl_buf;

		if (descr_idx == 0) {
			/* Send sane Language ID descriptor... */
			sd->wData[0] = USB_LANGID_ENGLISH_US;
			sd->bLength = sizeof(sd->bLength) + sizeof(sd->bDescriptorType) 
				+ sizeof(sd->wData[0]);

			*len = MIN(*len, sd->bLength);
		} else {
			array_idx = descr_idx - 1;

			if (!usbd_dev->strings)
				return USBD_REQ_NOTSUPP; /* Device doesn't support strings. */
			/* Check that string index is in range. */
			if (array_idx >= usbd_dev->num_strings)
				return USBD_REQ_NOTSUPP;

			/* Strings with Language ID differnet from
			 * USB_LANGID_ENGLISH_US are not supported */
			if (req->wIndex != USB_LANGID_ENGLISH_US)
				return USBD_REQ_NOTSUPP;

			/* Ths string is returned as UTF16, hence the multiplication */
			sd->bLength = strlen(usbd_dev->strings[array_idx]) * 2 +
				sizeof(sd->bLength) + sizeof(sd->bDescriptorType);

			*len = MIN(*len, sd->bLength);

			for (i = 0; i < (*len / 2) - 1; i++)
				sd->wData[i] =
					usbd_dev->strings[array_idx][i];
		}

		sd->bDescriptorType = USB_DT_STRING;
		*buf = (u8 *)sd;

		return USBD_REQ_HANDLED;
	}
	return USBD_REQ_NOTSUPP;
}

static int usb_standard_set_address(usbd_device *usbd_dev,
				    struct usb_setup_data *req, u8 **buf,
				    u16 *len)
{
	(void)req;
	(void)buf;
	(void)len;

	/* The actual address is only latched at the STATUS IN stage. */
	if ((req->bmRequestType != 0) || (req->wValue >= 128))
		return 0;

	usbd_dev->current_address = req->wValue;

	/*
	 * Special workaround for STM32F10[57] that require the address
	 * to be set here. This is undocumented!
	 */
	if ( usbd_dev->driver->set_address_before_status)
		usbd_dev->driver->set_address(usbd_dev, req->wValue);

	return 1;
}

static int usb_standard_set_configuration(usbd_device *usbd_dev,
					  struct usb_setup_data *req,
					  u8 **buf, u16 *len)
{
	int i;

	(void)req;
	(void)buf;
	(void)len;

	/* Is this correct, or should we reset alternate settings. */
	if (req->wValue == usbd_dev->current_config)
		return 1;

	usbd_dev->current_config = req->wValue;

	/* Reset all endpoints. */
	usbd_dev->driver->ep_reset(usbd_dev);

	if (usbd_dev->user_callback_set_config) {
		/*
		 * Flush control callbacks. These will be reregistered
		 * by the user handler.
		 */
		for (i = 0; i < MAX_USER_CONTROL_CALLBACK; i++)
			usbd_dev->user_control_callback[i].cb = NULL;

		usbd_dev->user_callback_set_config(usbd_dev, req->wValue);
	}

	return 1;
}

static int usb_standard_get_configuration(usbd_device *usbd_dev,
					  struct usb_setup_data *req,
					  u8 **buf, u16 *len)
{
	(void)req;

	if (*len > 1)
		*len = 1;
	(*buf)[0] = usbd_dev->current_config;

	return 1;
}

static int usb_standard_set_interface(usbd_device *usbd_dev,
				      struct usb_setup_data *req,
				      u8 **buf, u16 *len)
{
	(void)usbd_dev;
	(void)req;
	(void)buf;

	/* FIXME: Adapt if we have more than one interface. */
	if (req->wValue != 0)
		return 0;
	*len = 0;

	return 1;
}

static int usb_standard_get_interface(usbd_device *usbd_dev,
				      struct usb_setup_data *req,
				      u8 **buf, u16 *len)
{
	(void)usbd_dev;
	(void)req;
	(void)buf;

	/* FIXME: Adapt if we have more than one interface. */
	*len = 1;
	(*buf)[0] = 0;

	return 1;
}

static int usb_standard_device_get_status(usbd_device *usbd_dev,
					  struct usb_setup_data *req,
					  u8 **buf, u16 *len)
{
	(void)usbd_dev;
	(void)req;

	/* bit 0: self powered */
	/* bit 1: remote wakeup */
	if (*len > 2)
		*len = 2;
	(*buf)[0] = 0;
	(*buf)[1] = 0;

	return 1;
}

static int usb_standard_interface_get_status(usbd_device *usbd_dev,
					     struct usb_setup_data *req,
					     u8 **buf, u16 *len)
{
	(void)usbd_dev;
	(void)req;
	/* not defined */

	if (*len > 2)
		*len = 2;
	(*buf)[0] = 0;
	(*buf)[1] = 0;

	return 1;
}

static int usb_standard_endpoint_get_status(usbd_device *usbd_dev,
					    struct usb_setup_data *req,
					    u8 **buf, u16 *len)
{
	(void)req;

	if (*len > 2)
		*len = 2;
	(*buf)[0] = usbd_ep_stall_get(usbd_dev, req->wIndex) ? 1 : 0;
	(*buf)[1] = 0;

	return 1;
}

static int usb_standard_endpoint_stall(usbd_device *usbd_dev,
				       struct usb_setup_data *req,
				       u8 **buf, u16 *len)
{
	(void)buf;
	(void)len;

	usbd_ep_stall_set(usbd_dev, req->wIndex, 1);

	return 1;
}

static int usb_standard_endpoint_unstall(usbd_device *usbd_dev,
					 struct usb_setup_data *req,
					 u8 **buf, u16 *len)
{
	(void)buf;
	(void)len;

	usbd_ep_stall_set(usbd_dev, req->wIndex, 0);

	return 1;
}

/* Do not appear to belong to the API, so are omitted from docs */
/**@}*/

int _usbd_standard_request_device(usbd_device *usbd_dev,
				  struct usb_setup_data *req, u8 **buf,
				  u16 *len)
{
	int (*command)(usbd_device *usbd_dev, struct usb_setup_data *req, u8
		       **buf, u16 *len) = NULL;

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

	return command(usbd_dev, req, buf, len);
}

int _usbd_standard_request_interface(usbd_device *usbd_dev,
				     struct usb_setup_data *req, u8 **buf,
				     u16 *len)
{
	int (*command)(usbd_device *usbd_dev, struct usb_setup_data *req,
		       u8 **buf, u16 *len) = NULL;

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

	return command(usbd_dev, req, buf, len);
}

int _usbd_standard_request_endpoint(usbd_device *usbd_dev,
				    struct usb_setup_data *req, u8 **buf,
				    u16 *len)
{
	int (*command) (usbd_device *usbd_dev, struct usb_setup_data *req,
			u8 **buf, u16 *len) = NULL;

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

	return command(usbd_dev, req, buf, len);
}

int _usbd_standard_request(usbd_device *usbd_dev,
			   struct usb_setup_data *req, u8 **buf, u16 *len)
{
	/* FIXME: Have class/vendor requests as well. */
	if ((req->bmRequestType & USB_REQ_TYPE_TYPE) != USB_REQ_TYPE_STANDARD)
		return 0;

	switch (req->bmRequestType & USB_REQ_TYPE_RECIPIENT) {
	case USB_REQ_TYPE_DEVICE:
		return _usbd_standard_request_device(usbd_dev, req, buf, len);
	case USB_REQ_TYPE_INTERFACE:
		return _usbd_standard_request_interface(usbd_dev, req,
							buf, len);
	case USB_REQ_TYPE_ENDPOINT:
		return _usbd_standard_request_endpoint(usbd_dev, req, buf, len);
	default:
		return 0;
	}
}

