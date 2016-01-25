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

/* Audio Streaming Interface Descriptor Subtypes */
#define USB_AUDIO_STREAMING_DT_UNDEFINED               0x00
#define USB_AUDIO_STREAMING_DT_GENERAL                 0x01
#define USB_AUDIO_STREAMING_DT_FORMAT_TYPE             0x02
#define USB_AUDIO_STREAMING_DT_FORMAT_SPECIFIC         0x03

/* Data format tags - wFormatTag */
#define USB_AUDIO_FORMAT_TYPE_I_UNDEFINED	0x0000
#define USB_AUDIO_FORMAT_PCM 			0x0001
#define USB_AUDIO_FORMAT_PCM8 			0x0002
#define USB_AUDIO_FORMAT_IEEE_FLOAT		0x0003
#define USB_AUDIO_FORMAT_ALAW			0x0004
#define USB_AUDIO_FORMAT_MULAW			0x0005

 /* Audio Format Types */
#define USB_AUDIO_FORMAT_TYPE_UNDEFINED 	0x00
#define USB_AUDIO_FORMAT_TYPE_I 		0x01
#define USB_AUDIO_FORMAT_TYPE_II 		0x02
#define USB_AUDIO_FORMAT_TYPE_III 		0x03
 
/* USB sink/source terminal types */
#define USB_IO_TERMINAL_TYPE_UNDEFINED 		0x100
#define USB_IO_TERMINAL_TYPE_STREAMING 		0x101 
#define USB_IO_TERMINAL_TYPE_VENDOR 		0x1ff

/* Physical terminals */
/* Input terminal types */
#define USB_AUDIO_INPUT_TERMINAL_TYPE_UNDEFINED 		0x200
#define USB_AUDIO_INPUT_TERMINAL_TYPE_MICROPHONE 		0x201
#define USB_AUDIO_INPUT_TERMINAL_TYPE_DESKTOP_MICROPHONE 	0x202
#define USB_AUDIO_INPUT_TERMINAL_TYPE_PERSONAL_MICROPHONE 	0x203
#define USB_AUDIO_INPUT_TERMINAL_TYPE_OMNI_MICROPHONE 		0x204
#define USB_AUDIO_INPUT_TERMINAL_TYPE_MICROPHONE_ARRAY 		0x205
#define USB_AUDIO_INPUT_TERMINAL_TYPE_PROCESSING_MICROPHONE_ARRAY	0x206

/* Output terminal types */
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_UNDEFINED 	0x300
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_SPEAKER 		0x301
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_HEADPHONES 	0x302
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_HMD_AUDIO 	0x303
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_DESKTOP_SPEAKER 	0x304
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_ROOM_SPEAKER 	0x305
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_COMMS_SPEAKER 	0x306
#define USB_AUDIO_OUTPUT_TERMINAL_TYPE_SUBWOOFER	0x307

/* Audio Channel config (see audio_input_terminal_descriptor.wChannelConfig */
#define USB_AUDIO_CHAN_MONO		(0)
#define USB_AUDIO_CHAN_LEFTFRONT	(1 << 0)
#define USB_AUDIO_CHAN_RIGHTFRONT	(1 << 1)
#define USB_AUDIO_CHAN_CENTERFRONT	(1 << 2)
#define USB_AUDIO_CHAN_LFE 		(1 << 3)
#define USB_AUDIO_CHAN_LEFTSURROUND 	(1 << 4)
#define USB_AUDIO_CHAN_RIGHTSURROUND 	(1 << 5)
#define USB_AUDIO_CHAN_LEFTOFCENTER 	(1 << 6)
#define USB_AUDIO_CHAN_RIGHTOFCENTER 	(1 << 7)
#define USB_AUDIO_CHAN_SURROUND 	(1 << 8)
#define USB_AUDIO_CHAN_SIDELEFT 	(1 << 9)
#define USB_AUDIO_CHAN_SIDERIGHT 	(1 << 10)
#define USB_AUDIO_CHAN_TOP		(1 << 11)
/* 12..15 reserved */

/* bmaControls bit map */
#define USB_AUDIO_CONTROL_MUTE 		(1 << 0)
#define USB_AUDIO_CONTROL_VOLUME 	(1 << 1)
#define USB_AUDIO_CONTROL_BASS 		(1 << 2)
#define USB_AUDIO_CONTROL_MID 		(1 << 3)
#define USB_AUDIO_CONTROL_TREBLE 	(1 << 4)
#define USB_AUDIO_CONTROL_EQ 		(1 << 5)
#define USB_AUDIO_CONTROL_AGC 		(1 << 6)
#define USB_AUDIO_CONTROL_DELAY 	(1 << 7)
#define USB_AUDIO_CONTROL_BBOOST 	(1 << 8)
#define USB_AUDIO_CONTROL_LOUDNESS 	(1 << 9)

/* Table 2-1: Type I Format Descriptor, bSamFreqType */
#define USB_AUDIO_SAMPLING_FREQ_CONTINUOUS	0 
#define USB_AUDIO_SAMPLING_FREQ_FIXED  		1

/* Integer sample rate as 3-byte array for format descriptor */
#define USB_AUDIO_SAMPFREQ(X) {(X)&0xff,((X)>>8)&0xff,((X)>>16)&0xff}
#define USB_AUDIO_PACKET_SIZE(freq,nch,res) ((freq)*(nch)*((res)/8)/1000)
/* Audio specific Endpoint subtypes */
#define USB_AUDIO_EP_UNDEFINED      0
#define USB_AUDIO_EP_GENERAL        1

/* Endpoint attributes: bits 3..2 combined with
   bits 1..0 = USB_ENDPOINT_ATTR_ISOCHRONOUS */
#define USB_ENDPOINT_ATTR_ISO_ASYNC     5   // 0101
#define USB_ENDPOINT_ATTR_ISO_ADAPTIVE  9   // 1001
#define USB_ENDPOINT_ATTR_ISO_SYNC      13  // 1101

/* USB 2.0 Section 4.10.1.1 / Table 4-33 */
#define USB_ENDPOINT_USAGE_DATA 		0
#define USB_ENDPOINT_USAGE_IMPLICIT_FEEDBACK	(2 << 4)

/* Table A-9: Audio specific request codes */
#define USB_AUDIO_REQ_UNDEFINED 0x00
#define USB_AUDIO_REQ_SET_CUR 0x01
#define USB_AUDIO_REQ_GET_CUR 0x81
#define USB_AUDIO_REQ_SET_MIN 0x02
#define USB_AUDIO_REQ_GET_MIN 0x82
#define USB_AUDIO_REQ_SET_MAX 0x03
#define USB_AUDIO_REQ_GET_MAX 0x83
#define USB_AUDIO_REQ_SET_RES 0x04
#define USB_AUDIO_REQ_GET_RES 0x84
#define USB_AUDIO_REQ_SET_MEM 0x05
#define USB_AUDIO_REQ_GET_MEM 0x85
#define USB_AUDIO_REQ_GET_STAT 0xFF   

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

/* The bNrChannels, wChannelConfig and iChannelNames fields together constitute the cluster
   descriptor. They characterize the cluster that leaves the Input Terminal over the single Output Pin
   (‘downstream’ connection).  */

struct usb_audio_cluster_descriptor {
	uint8_t bNrChannels;
	/* A bit field that indicates which spatial locations are present in the cluster. 
	   See USB_AUDIO_CHAN for bit definitions */
	uint16_t wChannelConfig;
	uint8_t iChannelNames;
} __attribute__((packed));

struct usb_audio_input_terminal_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bTerminalID;
	uint16_t wTerminalType;
	uint8_t bAssocTerminal;

	struct usb_audio_cluster_descriptor cluster_descriptor;

	uint8_t iTerminal;
} __attribute__((packed));

#define USB_AUDIO_INPUT_TERMINAL_DESCRIPTOR_SIZE sizeof(struct usb_audio_input_terminal_descriptor)

struct usb_audio_output_terminal_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bTerminalID;
	uint16_t wTerminalType;
	uint8_t bAssocTerminal;
	uint8_t bSourceId;
	uint8_t iTerminal;
} __attribute__((packed));
#define USB_AUDIO_OUTPUT_TERMINAL_DESCRIPTOR_SIZE sizeof(struct usb_audio_output_terminal_descriptor)

struct usb_audio_feature_unit_descriptor_head {
	uint8_t bLength;                // 7 + (ch+1)*bControlSize
	uint8_t bDescriptorType;        // USB_AUDIO_DT_CS_INTERFACE
	uint8_t bDescriptorSubtype;     // USB_AUDIO_TYPE_FEATURE_UNIT
	uint8_t bUnitID; 
	uint8_t bSourceID;
	uint8_t bControlSize; 	
	/* ... bmaControls[] ... */
	/* usb_audio_feature_unit_descriptor_tail */
} __attribute__((packed));

struct usb_audio_feature_unit_descriptor_tail {
	uint8_t iFeature;
} __attribute__((packed));
#define USB_AUDIO_FEATURE_UNIT_DESCRIPTOR_SIZE_BASE 7

/* Table 4-18: Standard AS Interface Descriptor */
struct usb_audio_interface_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;        // USB_DT_INTERFACE
	uint8_t bInterfaceNumber; 
	uint8_t bAlternateSetting;
	uint8_t bNumEndpoints;          // Number of endpoints excluding EP 0
	uint8_t bInterfaceClass;        // USB_CLASS_AUDIO
	uint8_t bInterfaceSubClass;     // USB_AUDIO_SUBCLASS_AUDIOSTREAMING
	uint8_t bInterfaceProtocol;     // Not used. Must be set to 0.
	uint8_t iInterface;
} __attribute__((packed));
#define USB_AUDIO_INTERFACE_DESCRIPTOR_SIZE \
	sizeof(struct usb_audio_interface_descriptor)

/* Table 4-19: Class-specific AS Interface Descriptor */
struct usb_audio_streaming_interface_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;        // USB_AUDIO_DT_CS_INTERFACE
	uint8_t bDescriptorSubtype;     // USB_AUDIO_STREAMING_DT_GENERAL, etc
	uint8_t bTerminalLink;          
	uint8_t bDelay;
	uint16_t wFormatTag;            // USB_AUDIO_FORMAT_PCM, etc
} __attribute__((packed));
#define USB_AUDIO_STREAMING_INTERFACE_DESCRIPTOR_SIZE \
	sizeof(struct usb_audio_streaming_interface_descriptor)

struct usb_audio_type_i_iii_format_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;        // USB_AUDIO_DT_CS_INTERFACE
	uint8_t bDescriptorSubtype;     // USB_AUDIO_STREAMING_DT_FORMAT_TYPE
	uint8_t bFormatType;            // USB_AUDIO_FORMAT_TYPE_I, etc
	uint8_t bNrChannels; 
	uint8_t bSubframeSize;          // bytes per frame (e.g. 2 for 16-bit)
	uint8_t bBitResolution;         // e.g. 16
	uint8_t bSamFreqType;
	uint8_t tSampFreq[3];           // see USB_AUDIO_SAMPFREQ(X)
} __attribute__((packed));
#define USB_AUDIO_TYPE_I_III_FORMAT_DESCRIPTOR_SIZE \
	sizeof(struct usb_audio_type_i_iii_format_descriptor)

struct usb_audio_standard_endpoint_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bEndpointAddress;
	/*  D3..2: Synchronization type
	    01 = Asynchronous
	    10 = Adaptive
	    11 = Synchronous
	D1..0: Transfer type
	    01 = Isochronous */
	uint8_t bmAttributes;     
	uint16_t wMaxPacketSize; 
	uint8_t bInterval;              // 10ms or more recommended
	uint8_t bRefresh;               // reset to 0
	uint8_t bSynchAddress;
} __attribute__((packed));
#define USB_AUDIO_STANDARD_ENDPOINT_DESCRIPTOR_SIZE \
	sizeof(struct usb_audio_standard_endpoint_descriptor)

struct usb_audio_streaming_endpoint_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bmAttributes;
	uint8_t bLockDelayUnits;
	uint16_t wLockDelay;
} __attribute__((packed));
#define USB_AUDIO_STREAMING_ENDPOINT_DESCRIPTOR_SIZE \
	sizeof(struct usb_audio_streaming_endpoint_descriptor)

#endif

/**@}*/

