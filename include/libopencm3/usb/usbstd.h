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

#ifndef __USBSTD_H
#define __USBSTD_H

#include <stdint.h>
#include <libopencm3/cm3/common.h>

/*
 * This file contains structure definitions for the USB control structures
 * defined in chapter 9 of the "Univeral Serial Bus Specification Revision 2.0"
 * Available from the USB Implementers Forum - http://www.usb.org/
 */

/* USB Setup Data structure - Table 9-2 */
struct usb_setup_data {
	u8 bmRequestType;
	u8 bRequest;
	u16 wValue;
	u16 wIndex;
	u16 wLength;
} __attribute__((packed));

/* Class Definition */
#define USB_CLASS_VENDOR            		0xFF

/* bmRequestType bit definitions */
#define USB_REQ_TYPE_IN				0x80
#define USB_REQ_TYPE_STANDARD			0x00
#define USB_REQ_TYPE_CLASS			0x20
#define USB_REQ_TYPE_VENDOR			0x40
#define USB_REQ_TYPE_DEVICE			0x00
#define USB_REQ_TYPE_INTERFACE			0x01
#define USB_REQ_TYPE_ENDPOINT			0x02

#define USB_REQ_TYPE_DIRECTION			0x80
#define USB_REQ_TYPE_TYPE			0x60
#define USB_REQ_TYPE_RECIPIENT			0x1F

/* USB Standard Request Codes - Table 9-4 */
#define USB_REQ_GET_STATUS			0
#define USB_REQ_CLEAR_FEATURE			1
/* Reserved for future use: 2 */
#define USB_REQ_SET_FEATURE			3
/* Reserved for future use: 3 */
#define USB_REQ_SET_ADDRESS			5
#define USB_REQ_GET_DESCRIPTOR			6
#define USB_REQ_SET_DESCRIPTOR			7
#define USB_REQ_GET_CONFIGURATION		8
#define USB_REQ_SET_CONFIGURATION		9
#define USB_REQ_GET_INTERFACE			10
#define USB_REQ_SET_INTERFACE			11
#define USB_REQ_SET_SYNCH_FRAME			12

/* USB Descriptor Types - Table 9-5 */
#define USB_DT_DEVICE				1
#define USB_DT_CONFIGURATION			2
#define USB_DT_STRING				3
#define USB_DT_INTERFACE			4
#define USB_DT_ENDPOINT				5
#define USB_DT_DEVICE_QUALIFIER			6
#define USB_DT_OTHER_SPEED_CONFIGURATION	7
#define USB_DT_INTERFACE_POWER			8
/* From ECNs */
#define USB_DT_OTG				9
#define USB_DT_DEBUG				10
#define USB_DT_INTERFACE_ASSOCIATION		11

/* USB Standard Feature Selectors - Table 9-6 */
#define USB_FEAT_ENDPOINT_HALT			0
#define USB_FEAT_DEVICE_REMOTE_WAKEUP		1
#define USB_FEAT_TEST_MODE			2

/* Information Returned by a GetStatus() Request to a Device - Figure 9-4 */
#define USB_DEV_STATUS_SELF_POWERED		0x01
#define USB_DEV_STATUS_REMOTE_WAKEUP		0x02

/* USB Standard Device Descriptor - Table 9-8 */
struct usb_device_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u16 bcdUSB;
	u8 bDeviceClass;
	u8 bDeviceSubClass;
	u8 bDeviceProtocol;
	u8 bMaxPacketSize0;
	u16 idVendor;
	u16 idProduct;
	u16 bcdDevice;
	u8 iManufacturer;
	u8 iProduct;
	u8 iSerialNumber;
	u8 bNumConfigurations;
} __attribute__((packed));

#define USB_DT_DEVICE_SIZE sizeof(struct usb_device_descriptor)

/* USB Device_Qualifier Descriptor - Table 9-9
 * Not used in this implementation.
 */
struct usb_device_qualifier_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u16 bcdUSB;
	u8 bDeviceClass;
	u8 bDeviceSubClass;
	u8 bDeviceProtocol;
	u8 bMaxPacketSize0;
	u8 bNumConfigurations;
	u8 bReserved;
} __attribute__((packed));

/* USB Standard Configuration Descriptor - Table 9-10 */
struct usb_config_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u16 wTotalLength;
	u8 bNumInterfaces;
	u8 bConfigurationValue;
	u8 iConfiguration;
	u8 bmAttributes;
	u8 bMaxPower;

	/* Descriptor ends here.  The following are used internally: */
	const struct usb_interface {
		int num_altsetting;
		const struct usb_iface_assoc_descriptor *iface_assoc;
		const struct usb_interface_descriptor *altsetting;
	} *interface;
} __attribute__((packed));
#define USB_DT_CONFIGURATION_SIZE		9

/* USB Configuration Descriptor bmAttributes bit definitions */
#define USB_CONFIG_ATTR_SELF_POWERED		0x40
#define USB_CONFIG_ATTR_REMOTE_WAKEUP		0x20

/* Other Speed Configuration is the same as Configuration Descriptor.
 *  - Table 9-11
 */

/* USB Standard Interface Descriptor - Table 9-12 */
struct usb_interface_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u8 bInterfaceNumber;
	u8 bAlternateSetting;
	u8 bNumEndpoints;
	u8 bInterfaceClass;
	u8 bInterfaceSubClass;
	u8 bInterfaceProtocol;
	u8 iInterface;

	/* Descriptor ends here.  The following are used internally: */
	const struct usb_endpoint_descriptor *endpoint;
	const void *extra;
	int extralen;
} __attribute__((packed));
#define USB_DT_INTERFACE_SIZE			9

/* USB Standard Endpoint Descriptor - Table 9-13 */
struct usb_endpoint_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u8 bEndpointAddress;
	u8 bmAttributes;
	u16 wMaxPacketSize;
	u8 bInterval;
} __attribute__((packed));
#define USB_DT_ENDPOINT_SIZE		sizeof(struct usb_endpoint_descriptor)

/* USB Endpoint Descriptor bmAttributes bit definitions */
#define USB_ENDPOINT_ATTR_CONTROL		0x00
#define USB_ENDPOINT_ATTR_ISOCHRONOUS		0x01
#define USB_ENDPOINT_ATTR_BULK			0x02
#define USB_ENDPOINT_ATTR_INTERRUPT		0x03

#define USB_ENDPOINT_ATTR_NOSYNC		0x00
#define USB_ENDPOINT_ATTR_ASYNC			0x04
#define USB_ENDPOINT_ATTR_ADAPTIVE		0x08
#define USB_ENDPOINT_ATTR_SYNC			0x0C

#define USB_ENDPOINT_ATTR_DATA			0x00
#define USB_ENDPOINT_ATTR_FEEDBACK		0x10
#define USB_ENDPOINT_ATTR_IMPLICIT_FEEDBACK_DATA 0x20

/* Table 9-15 specifies String Descriptor Zero.
 * Table 9-16 specified UNICODE String Descriptor.
 */
struct usb_string_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u16 wData[];
} __attribute__((packed));

/* From ECN: Interface Association Descriptors, Table 9-Z */
struct usb_iface_assoc_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u8 bFirstInterface;
	u8 bInterfaceCount;
	u8 bFunctionClass;
	u8 bFunctionSubClass;
	u8 bFunctionProtocol;
	u8 iFunction;
} __attribute__((packed));
#define USB_DT_INTERFACE_ASSOCIATION_SIZE \
				sizeof(struct usb_iface_assoc_descriptor)

#endif
