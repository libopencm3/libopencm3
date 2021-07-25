/** @defgroup usb_standard_file Generic USB Standard Request Interface

@ingroup USB

@brief <b>Generic USB Standard Request Interface</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010
Gareth McMullin <gareth@blacksphere.co.nz>

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

int usbd_register_set_config_callback(usbd_device *usbd_dev,
				       usbd_set_config_callback callback)
{
	int i;

	for (i = 0; i < MAX_USER_SET_CONFIG_CALLBACK; i++) {
		if (usbd_dev->user_callback_set_config[i]) {
			if (usbd_dev->user_callback_set_config[i] == callback) {
				return 0;
			}
			continue;
		}

		usbd_dev->user_callback_set_config[i] = callback;
		return 0;
	}

	return -1;
}

void usbd_register_set_altsetting_callback(usbd_device *usbd_dev,
					usbd_set_altsetting_callback callback)
{
	usbd_dev->user_callback_set_altsetting = callback;
}

static uint16_t build_config_descriptor(usbd_device *usbd_dev,
				   uint8_t index, uint8_t *buf, uint16_t len)
{
	uint8_t *tmpbuf = buf;
	const struct usb_config_descriptor *cfg = &usbd_dev->config[index];
	uint16_t count, total = 0, totallen = 0;
	uint16_t i, j, k;

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
			if (iface->extra) {
				memcpy(buf, iface->extra,
				       count = MIN(len, iface->extralen));
				buf += count;
				len -= count;
				total += count;
				totallen += iface->extralen;
			}
			/* For each endpoint... */
			for (k = 0; k < iface->bNumEndpoints; k++) {
				const struct usb_endpoint_descriptor *ep =
				    &iface->endpoint[k];
				memcpy(buf, ep, count = MIN(len, ep->bLength));
				buf += count;
				len -= count;
				total += count;
				totallen += ep->bLength;
				/* Copy extra bytes (class specific). */
				if (ep->extra) {
					memcpy(buf, ep->extra,
					       count = MIN(len, ep->extralen));
					buf += count;
					len -= count;
					total += count;
					totallen += ep->extralen;
				}
			}
		}
	}

	/* Fill in wTotalLength.
	 * Note that tmpbuf is sometimes not halfword-aligned */
	memcpy((tmpbuf + 2), &totallen, sizeof(uint16_t));

	return total;
}

static int usb_descriptor_type(uint16_t wValue)
{
	return wValue >> 8;
}

static int usb_descriptor_index(uint16_t wValue)
{
	return wValue & 0xFF;
}

static enum usbd_request_return_codes
usb_standard_get_descriptor(usbd_device *usbd_dev,
			    struct usb_setup_data *req,
			    uint8_t **buf, uint16_t *len)
{
	int i, array_idx, descr_idx;
	struct usb_string_descriptor *sd;

	descr_idx = usb_descriptor_index(req->wValue);

	switch (usb_descriptor_type(req->wValue)) {
	case USB_DT_DEVICE:
		*buf = (uint8_t *) usbd_dev->desc;
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
			sd->bLength = sizeof(sd->bLength) +
				      sizeof(sd->bDescriptorType) +
				      sizeof(sd->wData[0]);

			*len = MIN(*len, sd->bLength);
		} else if (descr_idx == usbd_dev->extra_string_idx) {
			/* This string is returned as UTF16, hence the
			 * multiplication
			 */
			sd->bLength = strlen(usbd_dev->extra_string) * 2 +
				      sizeof(sd->bLength) +
				      sizeof(sd->bDescriptorType);

			*len = MIN(*len, sd->bLength);

			for (i = 0; i < (*len / 2) - 1; i++) {
				sd->wData[i] =
					usbd_dev->extra_string[i];
			}
        } else {
			array_idx = descr_idx - 1;

			if (!usbd_dev->strings) {
				/* Device doesn't support strings. */
				return USBD_REQ_NOTSUPP;
			}

			/* Check that string index is in range. */
			if (array_idx >= usbd_dev->num_strings) {
				return USBD_REQ_NOTSUPP;
			}

			/* Strings with Language ID differnet from
			 * USB_LANGID_ENGLISH_US are not supported */
			if (req->wIndex != USB_LANGID_ENGLISH_US) {
				return USBD_REQ_NOTSUPP;
			}

			/* This string is returned as UTF16, hence the
			 * multiplication
			 */
			sd->bLength = strlen(usbd_dev->strings[array_idx]) * 2 +
				      sizeof(sd->bLength) +
				      sizeof(sd->bDescriptorType);

			*len = MIN(*len, sd->bLength);

			for (i = 0; i < (*len / 2) - 1; i++) {
				sd->wData[i] =
					usbd_dev->strings[array_idx][i];
			}
		}

		sd->bDescriptorType = USB_DT_STRING;
		*buf = (uint8_t *)sd;

		return USBD_REQ_HANDLED;
	}
	return USBD_REQ_NOTSUPP;
}

static enum usbd_request_return_codes
usb_standard_set_address(usbd_device *usbd_dev,
			 struct usb_setup_data *req, uint8_t **buf,
			 uint16_t *len)
{
	(void)req;
	(void)buf;
	(void)len;

	/* The actual address is only latched at the STATUS IN stage. */
	if ((req->bmRequestType != 0) || (req->wValue >= 128)) {
		return USBD_REQ_NOTSUPP;
	}

	usbd_dev->current_address = req->wValue;

	/*
	 * Special workaround for STM32F10[57] that require the address
	 * to be set here. This is undocumented!
	 */
	if (usbd_dev->driver->set_address_before_status) {
		usbd_dev->driver->set_address(usbd_dev, req->wValue);
	}

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_set_configuration(usbd_device *usbd_dev,
			       struct usb_setup_data *req,
			       uint8_t **buf, uint16_t *len)
{
	unsigned i;
	int found_index = -1;
	const struct usb_config_descriptor *cfg;

	(void)req;
	(void)buf;
	(void)len;

	if (req->wValue > 0) {
		for (i = 0; i < usbd_dev->desc->bNumConfigurations; i++) {
			if (req->wValue
			    == usbd_dev->config[i].bConfigurationValue) {
				found_index = i;
				break;
			}
		}
		if (found_index < 0) {
			return USBD_REQ_NOTSUPP;
		}
	}

	usbd_dev->current_config = found_index + 1;

	if (usbd_dev->current_config > 0) {
		cfg = &usbd_dev->config[usbd_dev->current_config - 1];

		/* reset all alternate settings configuration */
		for (i = 0; i < cfg->bNumInterfaces; i++) {
			if (cfg->interface[i].cur_altsetting) {
				*cfg->interface[i].cur_altsetting = 0;
			}
		}
	}

	/* Reset all endpoints. */
	usbd_dev->driver->ep_reset(usbd_dev);

	if (usbd_dev->user_callback_set_config[0]) {
		/*
		 * Flush control callbacks. These will be reregistered
		 * by the user handler.
		 */
		for (i = 0; i < MAX_USER_CONTROL_CALLBACK; i++) {
			usbd_dev->user_control_callback[i].cb = NULL;
		}

		for (i = 0; i < MAX_USER_SET_CONFIG_CALLBACK; i++) {
			if (usbd_dev->user_callback_set_config[i]) {
				usbd_dev->user_callback_set_config[i](usbd_dev,
								req->wValue);
			}
		}
	}

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_get_configuration(usbd_device *usbd_dev,
			       struct usb_setup_data *req,
			       uint8_t **buf, uint16_t *len)
{
	(void)req;

	if (*len > 1) {
		*len = 1;
	}
	if (usbd_dev->current_config > 0) {
		const struct usb_config_descriptor *cfg =
			&usbd_dev->config[usbd_dev->current_config - 1];
		(*buf)[0] = cfg->bConfigurationValue;
	} else {
		(*buf)[0] = 0;
	}

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_set_interface(usbd_device *usbd_dev,
			   struct usb_setup_data *req,
			   uint8_t **buf, uint16_t *len)
{
	const struct usb_config_descriptor *cfx =
		&usbd_dev->config[usbd_dev->current_config - 1];
	const struct usb_interface *iface;

	(void)buf;

	if (req->wIndex >= cfx->bNumInterfaces) {
		return USBD_REQ_NOTSUPP;
	}

	iface = &cfx->interface[req->wIndex];

	if (req->wValue >= iface->num_altsetting) {
		return USBD_REQ_NOTSUPP;
	}

	if (iface->cur_altsetting) {
		*iface->cur_altsetting = req->wValue;
	} else if (req->wValue > 0) {
		return USBD_REQ_NOTSUPP;
	}

	if (usbd_dev->user_callback_set_altsetting) {
			usbd_dev->user_callback_set_altsetting(usbd_dev,
							       req->wIndex,
							       req->wValue);
	}

	*len = 0;

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_get_interface(usbd_device *usbd_dev,
			   struct usb_setup_data *req,
			   uint8_t **buf, uint16_t *len)
{
	uint8_t *cur_altsetting;
	const struct usb_config_descriptor *cfx =
		&usbd_dev->config[usbd_dev->current_config - 1];

	if (req->wIndex >= cfx->bNumInterfaces) {
		return USBD_REQ_NOTSUPP;
	}

	*len = 1;
	cur_altsetting = cfx->interface[req->wIndex].cur_altsetting;
	(*buf)[0] = (cur_altsetting) ? *cur_altsetting : 0;

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_device_get_status(usbd_device *usbd_dev,
			       struct usb_setup_data *req,
			       uint8_t **buf, uint16_t *len)
{
	(void)usbd_dev;
	(void)req;

	/* bit 0: self powered */
	/* bit 1: remote wakeup */
	if (*len > 2) {
		*len = 2;
	}
	(*buf)[0] = 0;
	(*buf)[1] = 0;

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_interface_get_status(usbd_device *usbd_dev,
				  struct usb_setup_data *req,
				  uint8_t **buf, uint16_t *len)
{
	(void)usbd_dev;
	(void)req;
	/* not defined */

	if (*len > 2) {
		*len = 2;
	}
	(*buf)[0] = 0;
	(*buf)[1] = 0;

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_endpoint_get_status(usbd_device *usbd_dev,
				 struct usb_setup_data *req,
				 uint8_t **buf, uint16_t *len)
{
	(void)req;

	if (*len > 2) {
		*len = 2;
	}
	(*buf)[0] = usbd_ep_stall_get(usbd_dev, req->wIndex) ? 1 : 0;
	(*buf)[1] = 0;

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_endpoint_stall(usbd_device *usbd_dev,
			    struct usb_setup_data *req,
			    uint8_t **buf, uint16_t *len)
{
	(void)buf;
	(void)len;

	usbd_ep_stall_set(usbd_dev, req->wIndex, 1);

	return USBD_REQ_HANDLED;
}

static enum usbd_request_return_codes
usb_standard_endpoint_unstall(usbd_device *usbd_dev,
			      struct usb_setup_data *req,
			      uint8_t **buf, uint16_t *len)
{
	(void)buf;
	(void)len;

	usbd_ep_stall_set(usbd_dev, req->wIndex, 0);

	return USBD_REQ_HANDLED;
}

/* Do not appear to belong to the API, so are omitted from docs */
/**@}*/

enum usbd_request_return_codes
_usbd_standard_request_device(usbd_device *usbd_dev,
			      struct usb_setup_data *req, uint8_t **buf,
			      uint16_t *len)
{
	enum usbd_request_return_codes (*command)(usbd_device *usbd_dev,
		struct usb_setup_data *req,
		uint8_t **buf, uint16_t *len) = NULL;

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

	if (!command) {
		return USBD_REQ_NOTSUPP;
	}

	return command(usbd_dev, req, buf, len);
}

enum usbd_request_return_codes
_usbd_standard_request_interface(usbd_device *usbd_dev,
				 struct usb_setup_data *req, uint8_t **buf,
				 uint16_t *len)
{
	enum usbd_request_return_codes (*command)(usbd_device *usbd_dev,
		struct usb_setup_data *req,
		uint8_t **buf, uint16_t *len) = NULL;

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

	if (!command) {
		return USBD_REQ_NOTSUPP;
	}

	return command(usbd_dev, req, buf, len);
}

enum usbd_request_return_codes
_usbd_standard_request_endpoint(usbd_device *usbd_dev,
				struct usb_setup_data *req, uint8_t **buf,
				uint16_t *len)
{
	enum usbd_request_return_codes (*command) (usbd_device *usbd_dev,
		struct usb_setup_data *req,
		uint8_t **buf, uint16_t *len) = NULL;

	switch (req->bRequest) {
	case USB_REQ_CLEAR_FEATURE:
		if (req->wValue == USB_FEAT_ENDPOINT_HALT) {
			command = usb_standard_endpoint_unstall;
		}
		break;
	case USB_REQ_SET_FEATURE:
		if (req->wValue == USB_FEAT_ENDPOINT_HALT) {
			command = usb_standard_endpoint_stall;
		}
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

	if (!command) {
		return USBD_REQ_NOTSUPP;
	}

	return command(usbd_dev, req, buf, len);
}

enum usbd_request_return_codes
_usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
		       uint8_t **buf, uint16_t *len)
{
	/* FIXME: Have class/vendor requests as well. */
	if ((req->bmRequestType & USB_REQ_TYPE_TYPE) != USB_REQ_TYPE_STANDARD) {
		return USBD_REQ_NOTSUPP;
	}

	switch (req->bmRequestType & USB_REQ_TYPE_RECIPIENT) {
	case USB_REQ_TYPE_DEVICE:
		return _usbd_standard_request_device(usbd_dev, req, buf, len);
	case USB_REQ_TYPE_INTERFACE:
		return _usbd_standard_request_interface(usbd_dev, req,
							buf, len);
	case USB_REQ_TYPE_ENDPOINT:
		return _usbd_standard_request_endpoint(usbd_dev, req, buf, len);
	default:
		return USBD_REQ_NOTSUPP;
	}
}

