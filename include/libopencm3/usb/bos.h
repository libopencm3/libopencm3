/** @defgroup usb_bos_defines USB BOS Type Definitions

@brief <b>Defined Constants and Types for the USB BOS Type Definitions</b>

@ingroup USB_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2022
Rachel Mant <git@dragonmux.network>

@date 11 August 2022

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Rachel Mant <git@dragonmux.network>
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

#ifndef __BOS_H
#define __BOS_H

#include <stdint.h>
#include <stddef.h>
#include <libopencm3/usb/usbd.h>

#define USB_DT_BOS               15
#define USB_DT_DEVICE_CAPABILITY 16

#define USB_DT_SUPERSPEED_USB_ENDPOINT_COMPANION             48
#define USB_DT_SUPERSPEEDPLUS_ISOCRHONOUS_ENDPOINT_COMPANION 49

#define USB_DCT_WIRELESS_USB                1
#define USB_DCT_USB_2_EXTENSION             2
#define USB_DCT_SUPERSPEED_USB              3
#define USB_DCT_CONTAINER_ID                4
#define USB_DCT_PLATFORM                    5
#define USB_DCT_POWER_DELIVERY_CAPABILITY   6
#define USB_DCT_BATTERY_INFO_CAPABILITY     7
#define USB_DCT_PD_CONSUMER_PORT_CAPABILITY 8
#define USB_DCT_PD_PROVIDER_PORT_CAPABILITY 9
#define USB_DCT_SUPERSPEED_PLUS             10
#define USB_DCT_PRECISION_TIME_MEASUREMENT  11
#define USB_DCT_WIRELESS_USB_EXTENSION      12
#define USB_DCT_BILLBOARD                   13
#define USB_DCT_AUTHENTICATION              14
#define USB_DCT_BILLBOARD_EXTENSION         15
#define USB_DCT_CONFIGURATION_SUMMARY       16

typedef struct __attribute__((packed)) usb_bos_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint16_t wTotalLength;
	uint8_t bNumDeviceCaps;

	/* Descriptor ends here.  The following are used internally: */
	/* This is a type-erased struct of the various capability descriptors */
	const void *device_capability_descriptors;
} usb_bos_descriptor;

#define USB_DT_BOS_SIZE 5U

/* This defines a UUID type with each of the discrete fields broken out to aid in specifying the value. */
typedef struct __attribute__((packed)) usb_bos_uuid {
	uint32_t a;
	uint16_t b;
	uint16_t c;
	uint16_t d;
	uint8_t e[6];
} usb_bos_uuid;

#define USB_BOS_UUID_SIZE sizeof(usb_bos_uuid)

typedef struct usb_device_capability_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDevCapabilityType;
} usb_device_capability_descriptor;

typedef struct __attribute__((packed)) usb_usb2_extension_descriptor {
	usb_device_capability_descriptor device_capability_descriptor;
	uint32_t bmAttributes;
} usb_usb2_extension_descriptor;

#define USB_DCT_USB_2_EXTENSION_SIZE sizeof(usb_usb2_extension_descriptor)

typedef struct __attribute__((packed)) usb_superspeeed_device_capability_descriptor {
	usb_device_capability_descriptor device_capability_descriptor;
	uint8_t bmAttributes;
	uint16_t wSpeedsSupported;
	uint8_t bFunctionalitySupport;
	uint8_t bU1DevExitLat;
	uint16_t wU2DevExitLat;
} usb_superspeeed_device_capability_descriptor;

#define USB_DCT_SUPERSPEED_USB_SIZE sizeof(usb_superspeeed_device_capability_descriptor)

typedef struct usb_superspeed_endpoint_companion_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bMaxBurst;
	uint8_t bmAttributes;
	uint16_t wBytesPerInterval;
} usb_superspeed_endpoint_companion_descriptor;

typedef struct __attribute__((packed)) usb_platform_device_capability_descriptor {
	usb_device_capability_descriptor device_capability_descriptor;
	uint8_t bReserved;
	usb_bos_uuid PlatformCapabilityUUID;

	/* Descriptor ends here.  The following are used internally: */
	/* This is a type-erased struct of the platform-specific capability data */
	const void *CapabilityData;
} usb_platform_device_capability_descriptor;

#define USB_DCT_PLATFORM_SIZE 20U

BEGIN_DECLS

void usbd_register_bos_descriptor(usbd_device *usbd_dev, const usb_bos_descriptor *bos);

END_DECLS

#endif

/**@}*/
