/** @defgroup usb_hid_defines USB HID Type Definitions

@brief <b>Defined Constants and Types for the USB HID Type Definitions</b>

@ingroup USB_defines

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

#ifndef __HID_H
#define __HID_H

#include <stdint.h>

#define USB_CLASS_HID	3

/* USB HID 4.2 */
#define USB_HID_SUBCLASS_NO 0
#define USB_HID_SUBCLASS_BOOT_INTERFACE 1

/* USB HID 4.3 */
#define USB_HID_INTERFACE_PROTOCOL_NONE 0
#define USB_HID_INTERFACE_PROTOCOL_KEYBOARD 1
#define USB_HID_INTERFACE_PROTOCOL_MOUSE 2

/* USB HID 7.1 */
#define USB_HID_DT_HID 0x21
#define USB_HID_DT_REPORT 0x22
#define USB_HID_DT_PHYSICAL 0x23
/** @deprecated Use @ref USB_HID_DT_HID */
#define USB_DT_HID USB_HID_DT_HID
/** @deprecated Use @ref USB_HID_DT_REPORT */
#define USB_DT_REPORT USB_HID_DT_REPORT

/* USB HID 7.2 */
#define USB_HID_REQ_TYPE_GET_REPORT 0x01
#define USB_HID_REQ_TYPE_GET_IDLE 0x02
#define USB_HID_REQ_TYPE_GET_PROTOCOL 0x03
#define USB_HID_REQ_TYPE_SET_REPORT 0x09
#define USB_HID_REQ_TYPE_SET_IDLE 0x0A
#define USB_HID_REQ_TYPE_SET_PROTOCOL 0x0B

/* USB HID 7.2.1 */
#define USB_HID_REPORT_TYPE_INPUT 1
#define USB_HID_REPORT_TYPE_OUTPUT 2
#define USB_HID_REPORT_TYPE_FEATURE 3

/* USB HID 7.2.5 */
#define USB_HID_PROTOCOL_BOOT 0
#define USB_HID_PROTOCOL_REPORT 1

struct usb_hid_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint16_t bcdHID;
	uint8_t bCountryCode;
	uint8_t bNumDescriptors;
} __attribute__((packed));

#endif

/**@}*/

