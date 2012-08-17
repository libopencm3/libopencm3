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

#ifndef __CDC_H
#define __CDC_H

/* Definitions of Communications Device Class from
 * "Universal Serial Bus Class Definitions for Communications Devices
 * Revision 1.2"
 */

/* Table 2: Communications Device Class Code */
#define USB_CLASS_CDC			0x02

/* Table 4: Class Subclass Code */
#define USB_CDC_SUBCLASS_DLCM		0x01
#define USB_CDC_SUBCLASS_ACM		0x02
/* ... */

/* Table 5 Communications Interface Class Control Protocol Codes */
#define USB_CDC_PROTOCOL_NONE		0x00
#define USB_CDC_PROTOCOL_AT		0x01
/* ... */

/* Table 6: Data Interface Class Code */
#define USB_CLASS_DATA			0x0A

/* Table 12: Type Values for the bDescriptorType Field */
#define CS_INTERFACE			0x24
#define CS_ENDPOINT			0x25

/* Table 13: bDescriptor SubType in Communications Class Functional
 * Descriptors */
#define USB_CDC_TYPE_HEADER		0x00
#define USB_CDC_TYPE_CALL_MANAGEMENT	0x01
#define USB_CDC_TYPE_ACM		0x02
/* ... */
#define USB_CDC_TYPE_UNION		0x06
/* ... */

/* Table 15: Class-Specific Descriptor Header Format */
struct usb_cdc_header_descriptor {
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubtype;
	u16 bcdCDC;
} __attribute__((packed));

/* Table 16: Union Interface Functional Descriptor */
struct usb_cdc_union_descriptor {
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubtype;
	u8 bControlInterface;
	u8 bSubordinateInterface0;
	/* ... */
} __attribute__((packed));


/* Definitions for Abstract Control Model devices from:
 * "Universal Serial Bus Communications Class Subclass Specification for
 * PSTN Devices"
 */

/* Table 3: Call Management Functional Descriptor */
struct usb_cdc_call_management_descriptor {
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubtype;
	u8 bmCapabilities;
	u8 bDataInterface;
} __attribute__((packed));

/* Table 4: Abstract Control Management Functional Descriptor */
struct usb_cdc_acm_descriptor {
	u8 bFunctionLength;
	u8 bDescriptorType;
	u8 bDescriptorSubtype;
	u8 bmCapabilities;
} __attribute__((packed));

/* Table 13: Class-Specific Request Codes for PSTN subclasses */
/* ... */
#define USB_CDC_REQ_SET_LINE_CODING		0x20
/* ... */
#define USB_CDC_REQ_SET_CONTROL_LINE_STATE	0x22
/* ... */

/* Table 17: Line Coding Structure */
struct usb_cdc_line_coding {
	u32 dwDTERate;
	u8 bCharFormat;
	u8 bParityType;
	u8 bDataBits;
} __attribute__((packed));

/* Table 30: Class-Specific Notification Codes for PSTN subclasses */
/* ... */
#define USB_CDC_NOTIFY_SERIAL_STATE		0x20
/* ... */

/* Notification Structure */
struct usb_cdc_notification {
	u8 bmRequestType;
	u8 bNotification;
	u16 wValue;
	u16 wIndex;
	u16 wLength;
} __attribute__((packed));

#endif
