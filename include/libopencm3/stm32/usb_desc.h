/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Piotr Esden-Tempski <piotr@esden.net>
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

#ifndef LIBOPENCM3_USB_DESC
#define LIBOPENCM3_USB_DESC

/* Descriptor types */
#define USB_DT_DEVICE		0x01
#define USB_DT_CONF		0x02
#define USB_DT_STRING		0x03
#define USB_DT_INTERFACE	0x04
#define USB_DT_ENDPOINT		0x05

struct usb_desc_head {
	uint8_t length;		/* Descriptor size 0x012 */
	uint8_t type;		/* Descriptor type ID */
};

struct usb_device_desc {
	struct usb_desc_head h;	/* Size 0x12, ID 0x01 */
	uint16_t bcd_usb;	/* USB Version */
	uint8_t class;		/* Device class */
	uint8_t sub_class;	/* Subclass code */
	uint8_t protocol;	/* Protocol code */
	uint8_t max_psize;	/* Maximum packet size -> 64bytes */
	uint16_t vendor;	/* Vendor number */
	uint16_t product;	/* Device number */
	uint16_t bcd_dev;	/* Device version */
	uint8_t man_desc;	/* Index of manufacturer string desc */
	uint8_t prod_desc;	/* Index of product string desc */
	uint8_t sn_desc;	/* Index of serial number string desc */
	uint8_t num_conf;	/* Number of possible configurations */
};

struct usb_conf_desc_header {
	struct usb_desc_head h;	/* Size 0x09, Id 0x02 */
	uint16_t tot_leng;	/* Total length of data */
	uint8_t num_int;	/* Number of interfaces */
	uint8_t conf_val;	/* Configuration selector */
	uint8_t conf_desc;	/* Index of conf string desc */
	uint8_t attr;		/* Attribute bitmap:
				 * 7    : Bus powered
				 * 6    : Self powered
				 * 5    : Remote wakeup
				 * 4..0 : Reserved -> 0000
				 */
	uint8_t max_power;	/* Maximum power consumption in 2mA steps */
};

struct usb_int_desc_header {
	struct usb_desc_head h;	/* Size 0x09, Id 0x04 */
	uint8_t iface_num;	/* Interface id number */
	uint8_t alt_setting;	/* Alternative setting selector */
	uint8_t num_endp;	/* Endpoints used */
	uint8_t class;		/* Interface class */
	uint8_t sub_class;	/* Subclass code */
	uint8_t protocol;	/* Protocol code */
	uint8_t iface_desc;	/* Index of interface string desc */
};

struct usb_ep_desc {
	struct usb_desc_head h;	/* Size 0x07, Id 0x05 */
	uint8_t ep_addr;	/* Endpoint address:
				   0..3 : Endpoint Number
				   4..6 : Reserved        -> 0
				   7    : Direction 0=out 1=in */
	uint8_t ep_attr;	/* Endpoint attributes */
	uint16_t max_psize;	/* Maximum packet size -> 64bytes */
	uint8_t interval;	/* Interval for polling endpoint
				   data. Ignored for bulk & control
				   endpoints. */
};

struct usb_conf_desc {
	struct usb_conf_desc_header cdh;
	struct usb_int_desc_header idh;
	struct usb_ep_desc ep[];
};

struct usb_string_desc {
	struct usb_desc_head h;	/* Size > 0x02, Id 0x03 */
	uint16_t string[];	/* String UTF16 encoded */
};

#endif
