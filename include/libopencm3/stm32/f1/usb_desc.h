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
	u8 length;		/* Descriptor size 0x012 */
	u8 type;		/* Descriptor type ID */
};

struct usb_device_desc {
	struct usb_desc_head h;	/* Size 0x12, ID 0x01 */
	u16 bcd_usb;		/* USB Version */
	u8 class;		/* Device class */
	u8 sub_class;		/* Subclass code */
	u8 protocol;		/* Protocol code */
	u8 max_psize;		/* Maximum packet size -> 64bytes */
	u16 vendor;		/* Vendor number */
	u16 product;		/* Device number */
	u16 bcd_dev;		/* Device version */
	u8 man_desc;		/* Index of manufacturer string desc */
	u8 prod_desc;		/* Index of product string desc */
	u8 sn_desc;		/* Index of serial number string desc */
	u8 num_conf;		/* Number of possible configurations */
};

struct usb_conf_desc_header {
	struct usb_desc_head h;	/* Size 0x09, Id 0x02 */
	u16 tot_leng;		/* Total length of data */
	u8 num_int;		/* Number of interfaces */
	u8 conf_val;		/* Configuration selector */
	u8 conf_desc;		/* Index of conf string desc */
	u8 attr;		/* Attribute bitmap:
				 * 7    : Bus powered
				 * 6    : Self powered
				 * 5    : Remote wakeup
				 * 4..0 : Reserved -> 0000
				 */
	u8 max_power;		/* Maximum power consumption in 2mA steps */
};

struct usb_int_desc_header {
	struct usb_desc_head h;	/* Size 0x09, Id 0x04 */
	u8 iface_num;		/* Interface id number */
	u8 alt_setting;		/* Alternative setting selector */
	u8 num_endp;		/* Endpoints used */
	u8 class;		/* Interface class */
	u8 sub_class;		/* Subclass code */
	u8 protocol;		/* Protocol code */
	u8 iface_desc;		/* Index of interface string desc */
};

struct usb_ep_desc {
	struct usb_desc_head h;	/* Size 0x07, Id 0x05 */
	u8 ep_addr;		/* Endpoint address:
				   0..3 : Endpoint Number
				   4..6 : Reserved        -> 0
				   7    : Direction 0=out 1=in */
	u8 ep_attr;		/* Endpoint attributes */
	u16 max_psize;		/* Maximum packet size -> 64bytes */
	u8 interval;		/* Interval for polling endpoint
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
	u16 string[];		/* String UTF16 encoded */
};

#endif
