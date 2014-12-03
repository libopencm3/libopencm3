/** @defgroup usb_audio_defines USB Audio Type Definitions

@brief <b>Defined Constants and Types for the USB Audio Type Definitions</b>

@ingroup USB_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2014
Daniel Thompson <daniel@redfelineninja.org.uk>

@date 19 April 2014

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Daniel Thompson <daniel@redfelineninja.org.uk>
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

#ifndef LIBOPENCM3_USB_AUDIO_H
#define LIBOPENCM3_USB_AUDIO_H

/*
 * Definitions from the USB_AUDIO_ or usb_audio_ namespace come from:
 * "Universal Serial Bus Class Definitions for Audio Devices, Revision 1.0"
 */

/* Table A-1: Audio Interface Class Code */
#define USB_CLASS_AUDIO			0x01

/* Table A-2: Audio Interface Subclass Codes */
#define USB_AUDIO_SUBCLASS_UNDEFINED		0x00
#define USB_AUDIO_SUBCLASS_CONTROL		0x01
#define USB_AUDIO_SUBCLASS_AUDIOSTREAMING	0x02
#define USB_AUDIO_SUBCLASS_MIDISTREAMING	0x03

/* Table A-4: Audio Class-specific Descriptor Types */
#define USB_AUDIO_DT_CS_UNDEFINED		0x20
#define USB_AUDIO_DT_CS_DEVICE			0x21
#define USB_AUDIO_DT_CS_CONFIGURATION		0x22
#define USB_AUDIO_DT_CS_STRING			0x23
#define USB_AUDIO_DT_CS_INTERFACE		0x24
#define USB_AUDIO_DT_CS_ENDPOINT		0x25

/* Table A-5: Audio Class-Specific AC Interface Descriptor Subtypes */
#define USB_AUDIO_TYPE_AC_DESCRIPTOR_UNDEFINED	0x00
#define USB_AUDIO_TYPE_HEADER			0x01
#define USB_AUDIO_TYPE_INPUT_TERMINAL		0x02
#define USB_AUDIO_TYPE_OUTPUT_TERMINAL		0x03
#define USB_AUDIO_TYPE_MIXER_UNIT		0x04
#define USB_AUDIO_TYPE_SELECTOR_UNIT		0x05
#define USB_AUDIO_TYPE_FEATURE_UNIT		0x06
#define USB_AUDIO_TYPE_PROCESSING_UNIT		0x07
#define USB_AUDIO_TYPE_EXTENSION_UNIT		0x08

/* Table 4-2: Class-Specific AC Interface Header Descriptor (head) */
struct usb_audio_header_descriptor_head {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint16_t bcdADC;
	uint16_t wTotalLength;
	uint8_t binCollection;
	/* ... */
} __attribute__((packed));

/* Table 4-2: Class-Specific AC Interface Header Descriptor (body) */
struct usb_audio_header_descriptor_body {
	/* ... */
	uint8_t baInterfaceNr;
} __attribute__((packed));

#endif

/**@}*/

