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

/**
 * Invalidate the device
 * @param dev USB Device
 */
void usbh_device_invalidate(usbh_device *dev)
{
	dev->host = NULL;
	dev->parent = NULL;
	dev->port = 0;
	dev->address = 0;
	dev->ep0_max_packet_size = 0;
	dev->speed = USBH_SPEED_UNKNOWN;
	dev->dtog = 0;
	dev->disconnected = NULL;
	dev->hub_ports = 0;
}

/**
 * A new root device has been attached.
 * @param host USB Host
 * @param parent USB Device parent
 * @param port USB Device parent port connected to
 * @param speed attached device speed
 */
void usbh_device_connected(usbh_host *host, usbh_device *parent,
		uint8_t port, usbh_speed speed)
{
	/* find a new device to store to */
	usbh_device *dev = NULL;

	for (unsigned i = 0; i < DEVICE_ARRAY_LENGTH; i++) {
		usbh_device *tmp = &host->devices[i];
		if (IS_DEVICE_INVALID(tmp)) {
			dev = tmp;
			break;
		}
	}

	if (dev == NULL) {
		LOG_LN("no empty device object left to store newly connected device");
		return;
	}

	/* prepare the object */
	dev->host = host;
	dev->parent = parent;
	dev->port = port;
	dev->address = 0;
	/* USB specs:
	 * "If the device is operating at high-speed,
	 *   the bMaxPacketSize0 field must be 64 indicating
	 *   a 64 byte maximum packet." */
	dev->ep0_max_packet_size = (speed >= USBH_SPEED_HIGH) ? 64 : 8;
	dev->speed = speed;
	dev->dtog = 0;
	dev->disconnected = NULL;

	usbh_device_enum_start(dev);
}

void usbh_device_disconnected(usbh_device *dev)
{
	usbh_host *host = dev->host;

	/* remove all URB */
	for (unsigned i = 0; i < URB_ARRAY_LENGTH; i++) {
		usbh_urb *urb = &host->urbs[i];
		if (urb->id != USBH_INVALID_URB_ID && urb->transfer.device == dev) {
			LOGF_LN("urb %"PRIu64" got removed because device disconnected.",
				urb->id);
			usbh_urb_free(urb, USBH_ERR_NO_DEVICE);
		}
	}

	/* remove all child devices */
	for (unsigned i = 0; i < DEVICE_ARRAY_LENGTH; i++) {
		usbh_device *child = &host->devices[i];
		if (child->parent == dev) {
			usbh_device_disconnected(child);
		}
	}

	if (dev->disconnected != NULL) {
		dev->disconnected(dev);
	}

	usbh_device_invalidate(dev);
}

/*
usbh_device *get_root_device(usbh_host *host)
{
	for (unsigned i = 0; i < DEVICE_ARRAY_LENGTH; i++) {
		usbh_device *dev = host->devices[i];
		if (IS_DEVICE_VALID(dev) && IS_ROOT_HUB(dev)) {
			return dev;
		}
	}

	return NULL;
}
*/

void usbh_root_device_connected(usbh_host *host, usbh_speed speed)
{
	usbh_device_connected(host, NULL, 0, speed);
}

void usbh_root_device_disconnected(usbh_host *host)
{
	usbh_device_disconnected(host->devices);
}

usbh_host *usbh_device_host(usbh_device *dev)
{
	return dev->host;
}

usbh_device *usbh_device_parent(usbh_device *dev)
{
	return dev->parent;
}

uint8_t usbh_device_port(usbh_device *dev)
{
	return dev->port;
}

uint8_t usbh_device_address(usbh_device *dev)
{
	return dev->address;
}

usbh_speed usbh_device_speed(usbh_device *dev)
{
	return dev->speed;
}

uint8_t usbh_device_ep0_size(usbh_device *dev)
{
	return dev->ep0_max_packet_size;
}

void usbh_device_register_disconnected_callback(usbh_device *dev,
		usbh_disconnected_callback disconnected)
{
	dev->disconnected = disconnected;
}

bool usbh_device_ep_dtog_get(usbh_device *dev, uint8_t ep)
{
	return !!(dev->dtog & ep_dtog_mask(ep));
}

void usbh_device_ep_dtog_set(usbh_device *dev, uint8_t ep, bool dtog)
{
	uint32_t mask = ep_dtog_mask(ep);
	dev->dtog = dtog ? (dev->dtog | mask) : (dev->dtog & ~mask);
}

void usbh_device_ep_dtog_reset_all(usbh_device *dev)
{
	dev->dtog = 0;
}

void usbh_device_reset(usbh_device *dev)
{
	usbh_host *host = dev->host;

	usbh_device_disconnected(dev); /* clear everything off */

	if (IS_ROOT_HUB(dev)) {
		host->backend->reset(host); /* reset the periph */
	} else {
		usbh_hub_reset_port(dev->parent, dev->port);
	}
}

void usbh_device_ep_dtog_toggle(usbh_device *dev, uint8_t ep)
{
	uint32_t mask = ep_dtog_mask(ep);
	dev->dtog ^= mask;
}

unsigned usbh_search_devices_by_parent(usbh_host *host, usbh_device *parent,
		usbh_device **list, unsigned list_size)
{
	unsigned len = 0;

	for (unsigned i = 0; i < DEVICE_ARRAY_LENGTH; i++) {
		usbh_device *dev = &host->devices[i];
		if (IS_DEVICE_VALID(dev) && dev->parent == parent) {
			list[len++] = dev;
			if (len >= list_size) {
				break;
			}
		}
	}

	return len;
}

usbh_device *usb_device_by_address(usbh_host *host, uint8_t address)
{
	for (unsigned i = 0; i < DEVICE_ARRAY_LENGTH; i++) {
		usbh_device *dev = &host->devices[i];
		if (IS_DEVICE_VALID(dev) && dev->address == address) {
			return dev;
		}
	}

	return NULL;
}
