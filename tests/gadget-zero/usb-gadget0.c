/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

/*
 * This file implements linux's "Gadget zero" functionality, both the
 * "source sink" functional interface, and the "loopback" interface.
 * It _only_ uses usb includes, do _not_ include any target specific code here!
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <libopencm3/usb/usbd.h>

#include "trace.h"
#include "usb-gadget0.h"

#define ER_DEBUG
#ifdef ER_DEBUG
#include <stdio.h>
#define ER_DPRINTF(fmt, ...) \
    do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
    do { } while (0)
#endif

/*
 * USB Vendor:Interface control requests.
 */
#define GZ_REQ_SET_PATTERN				1
#define GZ_REQ_PRODUCE					2
#define GZ_REQ_WRITE_LOOPBACK_BUFFER	3
#define GZ_REQ_READ_LOOPBACK_BUFFER		4

#define INTEL_COMPLIANCE_WRITE 0x5b
#define INTEL_COMPLIANCE_READ 0x5c

/* USB configurations */
#define GZ_CFG_SOURCESINK	2
#define GZ_CFG_LOOPBACK		3


static const struct usb_device_descriptor dev = {
	.bLength = USB_DT_DEVICE_SIZE,
	.bDescriptorType = USB_DT_DEVICE,
	.bcdUSB = 0x0200,
	.bDeviceClass = USB_CLASS_VENDOR,
	.bDeviceSubClass = 0,
	.bDeviceProtocol = 0,
	.bMaxPacketSize0 = 64,

	/* when we're compatible with gadget 0
	 * #define DRIVER_VENDOR_NUM       0x0525
	 * #define DRIVER_PRODUCT_NUM      0xa4a0
	 */
	.idVendor = 0xcafe,
	.idProduct = 0xcafe,
	.bcdDevice = 0x0001,
	.iManufacturer = 1,
	.iProduct = 2,
	.iSerialNumber = 3,
	.bNumConfigurations = 2,
};

static const struct usb_endpoint_descriptor endp_bulk[] = {
	{
		.bLength = USB_DT_ENDPOINT_SIZE,
		.bDescriptorType = USB_DT_ENDPOINT,
		.bEndpointAddress = 0x01,
		.bmAttributes = USB_ENDPOINT_ATTR_BULK,
		.wMaxPacketSize = 64,
		.bInterval = 1,
	},
	{
		.bLength = USB_DT_ENDPOINT_SIZE,
		.bDescriptorType = USB_DT_ENDPOINT,
		.bEndpointAddress = 0x82,
		.bmAttributes = USB_ENDPOINT_ATTR_BULK,
		.wMaxPacketSize = 64,
		.bInterval = 1,
	}
};

static const struct usb_interface_descriptor iface_sourcesink[] = {
	{
		.bLength = USB_DT_INTERFACE_SIZE,
		.bDescriptorType = USB_DT_INTERFACE,
		.bInterfaceNumber = 0,
		.bAlternateSetting = 0,
		.bNumEndpoints = 2,
		.bInterfaceClass = USB_CLASS_VENDOR,
		.iInterface = 0,
		.endpoint = endp_bulk,
	}
};

static const struct usb_interface_descriptor iface_loopback[] = {
	{
		.bLength = USB_DT_INTERFACE_SIZE,
		.bDescriptorType = USB_DT_INTERFACE,
		.bInterfaceNumber = 0, /* still 0, as it's a different config...? */
		.bAlternateSetting = 0,
		.bNumEndpoints = 2,
		.bInterfaceClass = USB_CLASS_VENDOR,
		.iInterface = 0,
		.endpoint = endp_bulk,
	}
};

static const struct usb_interface ifaces_sourcesink[] = {
	{
		.num_altsetting = 1,
		.altsetting = iface_sourcesink,
	}
};

static const struct usb_interface ifaces_loopback[] = {
	{
		.num_altsetting = 1,
		.altsetting = iface_loopback,
	}
};

static const struct usb_config_descriptor config[] = {
	{
		.bLength = USB_DT_CONFIGURATION_SIZE,
		.bDescriptorType = USB_DT_CONFIGURATION,
		.wTotalLength = 0,
		.bNumInterfaces = 1,
		.bConfigurationValue = GZ_CFG_SOURCESINK,
		.iConfiguration = 4, /* string index */
		.bmAttributes = 0x80,
		.bMaxPower = 0x32,
		.interface = ifaces_sourcesink,
	},
	{
		.bLength = USB_DT_CONFIGURATION_SIZE,
		.bDescriptorType = USB_DT_CONFIGURATION,
		.wTotalLength = 0,
		.bNumInterfaces = 1,
		.bConfigurationValue = GZ_CFG_LOOPBACK,
		.iConfiguration = 5, /* string index */
		.bmAttributes = 0x80,
		.bMaxPower = 0x32,
		.interface = ifaces_loopback,
	}
};

static char serial[] = "0123456789.0123456789.0123456789";
static const char *usb_strings[] = {
	"libopencm3",
	"Gadget-Zero",
	serial,
	"source and sink data",
	"loop input to output"
};

/* Buffer to be used for control requests. */
static uint8_t usbd_control_buffer[5*64];
static usbd_device *our_dev;

/* Private global for state */
static struct {
	uint8_t pattern;
	int pattern_counter;
} state = {
	.pattern = 0,
	.pattern_counter = 0,
};

static void gadget0_ss_out_cb(usbd_device *usbd_dev, uint8_t ep)
{
	(void) ep;
	/* TODO - if you're really keen, perf test this. tiva implies it matters */
	/* char buf[64] __attribute__ ((aligned(4))); */
	char buf[64];
	trace_send_blocking8(0, 'O');
	uint16_t x = usbd_ep_read_packet(usbd_dev, ep, buf, sizeof(buf));
	trace_send_blocking8(1, x);
}

static void gadget0_ss_in_cb(usbd_device *usbd_dev, uint8_t ep)
{
	(void) usbd_dev;
	trace_send_blocking8(0, 'I');
	uint8_t buf[64];
	switch (state.pattern) {
	case 0:
		memset(buf, 0, sizeof(buf));
		break;
	case 1:
		for (unsigned i = 0; i < sizeof(buf); i++) {
			buf[i] = state.pattern_counter++ % 63;
		}
		break;
	}

	uint16_t x = usbd_ep_write_packet(usbd_dev, ep, buf, sizeof(buf));
	/* As we are calling write in the callback, this should never fail */
	trace_send_blocking8(2, x);
	if (x != sizeof(buf)) {
		ER_DPRINTF("failed to write?: %d\n", x);
	}
	/*assert(x == sizeof(buf));*/
}

static void gadget0_rx_cb_loopback(usbd_device *usbd_dev, uint8_t ep)
{
	(void) usbd_dev;
	(void) ep;
	ER_DPRINTF("loop rx %x\n", ep);
	/* TODO - unimplemented - consult linux source on proper behaviour */
}

static void gadget0_tx_cb_loopback(usbd_device *usbd_dev, uint8_t ep)
{
	(void) usbd_dev;
	(void) ep;
	ER_DPRINTF("loop tx %x\n", ep);
	/* TODO - unimplemented - consult linux source on proper behaviour */
}

static int gadget0_control_request(usbd_device *usbd_dev,
	struct usb_setup_data *req,
	uint8_t **buf,
	uint16_t *len,
	usbd_control_complete_callback *complete)
{
	(void) usbd_dev;
	(void) complete;
	static uint8_t loopback_buffer[sizeof(usbd_control_buffer)];
	ER_DPRINTF("ctrl breq: %x, bmRT: %x, windex :%x, wlen: %x, wval :%x\n",
		req->bRequest, req->bmRequestType, req->wIndex, req->wLength,
		req->wValue);

	/* TODO - what do the return values mean again? */
	switch (req->bRequest) {
	case GZ_REQ_SET_PATTERN:
		state.pattern_counter = 0;
		state.pattern = req->wValue;
		return USBD_REQ_HANDLED;
	case INTEL_COMPLIANCE_WRITE:
	case INTEL_COMPLIANCE_READ:
		ER_DPRINTF("unimplemented!");
		return USBD_REQ_NOTSUPP;
	case GZ_REQ_PRODUCE:
		ER_DPRINTF("fake loopback of %d\n", req->wValue);
		if (req->wValue > sizeof(usbd_control_buffer)) {
			ER_DPRINTF("Can't write more than out control buffer! %d > %d\n",
				req->wValue, sizeof(usbd_control_buffer));
			return USBD_REQ_NOTSUPP;
		}
		/* Don't produce more than asked for! */
		if (req->wValue > req->wLength) {
			ER_DPRINTF("Truncating reply to match wLen\n");
			*len = req->wLength;
		} else {
			*len = req->wValue;
		}
		return USBD_REQ_HANDLED;
	case GZ_REQ_WRITE_LOOPBACK_BUFFER:
		if (req->wValue > sizeof(usbd_control_buffer)) {
			ER_DPRINTF("Can't store more than out control buffer! %d > %d\n",
				req->wValue, sizeof(usbd_control_buffer));
			return USBD_REQ_NOTSUPP;
		}
		/* Don't store more than asked for! */
		if (req->wValue > req->wLength) {
			memcpy(loopback_buffer, *buf, req->wLength);
			ER_DPRINTF("Truncated stored loopback data to match wLen\n");
		} else {
			memcpy(loopback_buffer, *buf, req->wValue);
		}
		ER_DPRINTF("Stored loopback data of %d\n", req->wValue);
		return USBD_REQ_HANDLED;
	case GZ_REQ_READ_LOOPBACK_BUFFER:
		ER_DPRINTF("loopback of %d\n", req->wValue);
		if (req->wValue > sizeof(usbd_control_buffer)) {
			ER_DPRINTF("Can't write more than out control buffer! %d > %d\n",
				req->wValue, sizeof(usbd_control_buffer));
			return USBD_REQ_NOTSUPP;
		}
		/* Don't produce more than asked for! */
		if (req->wValue > req->wLength) {
			ER_DPRINTF("Truncating reply to match wLen\n");
			*len = req->wLength;
		} else {
			*len = req->wValue;
		}
		memcpy(*buf,loopback_buffer,*len);
		return USBD_REQ_HANDLED;
	}
	return USBD_REQ_NEXT_CALLBACK;
}

static void gadget0_set_config(usbd_device *usbd_dev, uint16_t wValue)
{
	ER_DPRINTF("set cfg %d\n", wValue);
	switch (wValue) {
	case GZ_CFG_SOURCESINK:
		usbd_ep_setup(usbd_dev, 0x01, USB_ENDPOINT_ATTR_BULK, 64,
			gadget0_ss_out_cb);
		usbd_ep_setup(usbd_dev, 0x82, USB_ENDPOINT_ATTR_BULK, 64,
			gadget0_ss_in_cb);
		usbd_register_control_callback(
			usbd_dev,
			USB_REQ_TYPE_VENDOR | USB_REQ_TYPE_INTERFACE,
			USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT,
			gadget0_control_request);
		/* Prime source for IN data. */
		gadget0_ss_in_cb(usbd_dev, 0x82);
		break;
	case GZ_CFG_LOOPBACK:
		usbd_ep_setup(usbd_dev, 0x01, USB_ENDPOINT_ATTR_BULK, 64,
			gadget0_rx_cb_loopback);
		usbd_ep_setup(usbd_dev, 0x82, USB_ENDPOINT_ATTR_BULK, 64,
			gadget0_tx_cb_loopback);
		break;
	default:
		ER_DPRINTF("set configuration unknown: %d\n", wValue);
	}
}

usbd_device *gadget0_init(const usbd_driver *driver, const char *userserial)
{
#ifdef ER_DEBUG
	setbuf(stdout, NULL);
#endif
	if (userserial) {
		usb_strings[2] = userserial;
	}
	our_dev = usbd_init(driver, &dev, config,
		usb_strings, 5,
		usbd_control_buffer, sizeof(usbd_control_buffer));

	usbd_register_set_config_callback(our_dev, gadget0_set_config);

	return our_dev;
}
