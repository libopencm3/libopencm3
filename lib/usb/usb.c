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

#include <string.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

u8 usbd_control_buffer[128] __attribute__((weak));

/**
 * Main initialization entry point.
 *
 * Initialize the USB firmware library to implement the USB device described
 * by the descriptors provided.
 *
 * It is required that the 48MHz USB clock is already available.
 *
 * @param driver TODO
 * @param dev Pointer to USB device descriptor. This must not be changed while
 *            the device is in use.
 * @param conf Pointer to array of USB configuration descriptors. These must
 *             not be changed while the device is in use. The length of this
 *             array is determined by the bNumConfigurations field in the
 *             device descriptor.
 * @param strings TODO
 * @return Zero on success (currently cannot fail).
 */
usbd_device *usbd_init(const usbd_driver *driver,
	      	       const struct usb_device_descriptor *dev,
	      	       const struct usb_config_descriptor *conf,
		       const char **strings)
{
	usbd_device *usbd_dev;

	usbd_dev = driver->init();

	usbd_dev->driver = driver;
	usbd_dev->desc = dev;
	usbd_dev->config = conf;
	usbd_dev->strings = strings;
	usbd_dev->ctrl_buf = usbd_control_buffer;
	usbd_dev->ctrl_buf_len = sizeof(usbd_control_buffer);

	usbd_dev->user_callback_ctr[0][USB_TRANSACTION_SETUP] =
	    _usbd_control_setup;
	usbd_dev->user_callback_ctr[0][USB_TRANSACTION_OUT] =
	    _usbd_control_out;
	usbd_dev->user_callback_ctr[0][USB_TRANSACTION_IN] =
	    _usbd_control_in;

	return usbd_dev;
}

void usbd_register_reset_callback(usbd_device *usbd_dev, void (*callback)(void))
{
	usbd_dev->user_callback_reset = callback;
}

void usbd_register_suspend_callback(usbd_device *usbd_dev,
				    void (*callback)(void))
{
	usbd_dev->user_callback_suspend = callback;
}

void usbd_register_resume_callback(usbd_device *usbd_dev,
				   void (*callback)(void))
{
	usbd_dev->user_callback_resume = callback;
}

void usbd_register_sof_callback(usbd_device *usbd_dev, void (*callback)(void))
{
	usbd_dev->user_callback_sof = callback;
}

void usbd_set_control_buffer_size(usbd_device *usbd_dev, u16 size)
{
	usbd_dev->ctrl_buf_len = size;
}

void _usbd_reset(usbd_device *usbd_dev)
{
	usbd_dev->current_address = 0;
	usbd_dev->current_config = 0;
	usbd_ep_setup(usbd_dev, 0, USB_ENDPOINT_ATTR_CONTROL, 64, NULL);
	usbd_dev->driver->set_address(usbd_dev, 0);

	if (usbd_dev->user_callback_reset)
		usbd_dev->user_callback_reset();
}

/* Functions to wrap the low-level driver */
void usbd_poll(usbd_device *usbd_dev)
{
	usbd_dev->driver->poll(usbd_dev);
}

void usbd_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	/* not all drivers support disconnection */
	if (usbd_dev->driver->disconnect)
		usbd_dev->driver->disconnect(usbd_dev, disconnected);
}

void usbd_ep_setup(usbd_device *usbd_dev, u8 addr, u8 type, u16 max_size,
		   void (*callback)(usbd_device *usbd_dev, u8 ep))
{
	usbd_dev->driver->ep_setup(usbd_dev, addr, type, max_size, callback);
}

u16 usbd_ep_write_packet(usbd_device *usbd_dev, u8 addr,
			 const void *buf, u16 len)
{
	return usbd_dev->driver->ep_write_packet(usbd_dev, addr, buf, len);
}

u16 usbd_ep_read_packet(usbd_device *usbd_dev, u8 addr, void *buf, u16 len)
{
	return usbd_dev->driver->ep_read_packet(usbd_dev, addr, buf, len);
}

void usbd_ep_stall_set(usbd_device *usbd_dev, u8 addr, u8 stall)
{
	usbd_dev->driver->ep_stall_set(usbd_dev, addr, stall);
}

u8 usbd_ep_stall_get(usbd_device *usbd_dev, u8 addr)
{
	return usbd_dev->driver->ep_stall_get(usbd_dev, addr);
}

void usbd_ep_nak_set(usbd_device *usbd_dev, u8 addr, u8 nak)
{
	usbd_dev->driver->ep_nak_set(usbd_dev, addr, nak);
}
