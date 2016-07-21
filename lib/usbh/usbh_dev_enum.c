/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include "usbh-private.h"
#include <libopencm3/usbh/helper/ctrlreq.h>

/**
 * procedure to enumerate a device
 *  - prepare the device object
 *  - set address
 *  - get device descriptor (get ep0 max size)
 */

#define CONTROL_TIMEOUT 500

static void enum_failed(usbh_device *dev)
{
	LOG_LN("failed to enumerate device");
	usbh_device_invalidate(dev);
}

static void enum_success(usbh_device *dev)
{
	usbh_host *host = dev->host;

	LOG_LN("successfully enumerated device");

	if (host->connected != NULL) {
		host->connected(dev);
	}
}

/**
 * Callback when the partial descriptor is readed from the device.
 * @param dev USB Device
 * @param status Transfer status
 * @param urb_id URB ID (ignored)
 * @warning @a desc has only first 8bytes valid
 */
static void got_partial_dev_desc(const usbh_transfer *transfer,
		usbh_transfer_status status, usbh_urb_id urb_id)
{
	(void) urb_id;

	usbh_device *dev = transfer->device;
	if (status != USBH_SUCCESS) {
		LOG_LN("failed to read partial device descriptor from device");
		enum_failed(dev);
		return;
	}

	LOG_LN("success in reading partial device descriptor from device");

	struct usb_device_descriptor *desc = transfer->data;
	LOGF_LN("bLength: %"PRIu8, desc->bLength);
	LOGF_LN("bDescriptorType: 0x%"PRIx8, desc->bDescriptorType);
	LOGF_LN("bcdUSB: 0x%"PRIx16, desc->bcdUSB);
	LOGF_LN("bDeviceClass: 0x%"PRIx8, desc->bDeviceClass);
	LOGF_LN("bDeviceSubClass: 0x%"PRIx8, desc->bDeviceSubClass);
	LOGF_LN("bDeviceProtocol: 0x%"PRIx8, desc->bDeviceProtocol);
	LOGF_LN("bMaxPacketSize0: %"PRIu8, desc->bMaxPacketSize0);

	dev->ep0_max_packet_size = desc->bMaxPacketSize0;
	enum_success(dev);
}

/**
 * Callback when an address is assigned to the device.
 * @param dev USB Device
 * @param status Transfer status
 * @param urb_id URB ID (ignored)
 */
static void address_assigned(const usbh_transfer *transfer,
		usbh_transfer_status status, usbh_urb_id urb_id)
{
	(void) urb_id;

	usbh_device *dev = transfer->device;
	if (status != USBH_SUCCESS) {
		LOG_LN("failed to set address to device");
		enum_failed(dev);
		return;
	}

	LOG_LN("succeeded in set address to device");
	dev->address = transfer->setup.wValue;

	LOG_LN("trying to read partial device descriptor from device");
	usbh_ctrlreq_read_dev_desc(dev, dev->host->buffer, 8, got_partial_dev_desc);
}

/**
 * Allocate the next device address from the host
 * @param host USB Host
 * @return valid non-zero 7bit address
 * @return zero on failure
 */
static uint8_t alloc_device_address(usbh_host *host)
{
	for (unsigned i = 0; i < 127; i++) {
		/* fail after 127 attempts! (address space is full) */

		uint8_t addr = host->next_device_address & 0x7F;
		addr = (!addr) ? 1 : addr;
		host->next_device_address = (addr == 0x7F) ? 1 : (addr + 1);

		for (unsigned j = 0; j < DEVICE_ARRAY_LENGTH; j++) {
			usbh_device *dev = &host->devices[j];
			if (IS_DEVICE_VALID(dev) && dev->address == addr) {
				/* address is being used! */
				addr = 0;
				break;
			}
		}

		if (addr) {
			/* tada! we found a unused address */
			LOGF_LN("address 0x%"PRIx8" is free for use", addr);
			return addr;
		}
	}

	LOG_LN("tried all possibilities, no valid address found");
	return 0;
}

/**
 * Place a SET_ADDRESS request for @a dev
 * @param dev USB Device
 */
static void set_address(usbh_device *dev)
{
	uint8_t addr = alloc_device_address(dev->host);
	if (!addr) {
		LOG_LN("no device address to assign for SET_ADDRESS");
		enum_failed(dev);
		return;
	}

	LOGF_LN("trying to set address (0x%"PRIx8") to device", addr);
	usbh_ctrlreq_set_address(dev, addr, address_assigned);
}

/**
 * Start the device enumeration.
 * @param dev USB Device
 */
void usbh_device_enum_start(usbh_device *dev)
{
	LOG_CALL

	set_address(dev);
}
