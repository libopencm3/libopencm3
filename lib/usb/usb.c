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

struct _usbd_device _usbd_device;

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
int usbd_init(const usbd_driver *driver,
	      const struct usb_device_descriptor *dev,
	      const struct usb_config_descriptor *conf, const char **strings)
{
	_usbd_device.driver = driver;
	_usbd_device.desc = dev;
	_usbd_device.config = conf;
	_usbd_device.strings = strings;
	_usbd_device.ctrl_buf = usbd_control_buffer;
	_usbd_device.ctrl_buf_len = sizeof(usbd_control_buffer);

	_usbd_hw_init();

	_usbd_device.user_callback_ctr[0][USB_TRANSACTION_SETUP] =
	    _usbd_control_setup;
	_usbd_device.user_callback_ctr[0][USB_TRANSACTION_OUT] =
	    _usbd_control_out;
	_usbd_device.user_callback_ctr[0][USB_TRANSACTION_IN] =
	    _usbd_control_in;

	return 0;
}

void usbd_register_reset_callback(void (*callback)(void))
{
	_usbd_device.user_callback_reset = callback;
}

void usbd_register_suspend_callback(void (*callback)(void))
{
	_usbd_device.user_callback_suspend = callback;
}

void usbd_register_resume_callback(void (*callback)(void))
{
	_usbd_device.user_callback_resume = callback;
}

void usbd_register_sof_callback(void (*callback)(void))
{
	_usbd_device.user_callback_sof = callback;
}

void usbd_set_control_buffer_size(u16 size)
{
	_usbd_device.ctrl_buf_len = size;
}

void _usbd_reset(void)
{
	_usbd_device.current_address = 0;
	_usbd_device.current_config = 0;
	usbd_ep_setup(0, USB_ENDPOINT_ATTR_CONTROL, 64, NULL);
	_usbd_hw_set_address(0);

	if (_usbd_device.user_callback_reset)
		_usbd_device.user_callback_reset();
}

/* Functions to wrap the low-level driver */
void usbd_poll(void)
{
	_usbd_device.driver->poll();
}

void usbd_disconnect(bool disconnected)
{
	/* not all drivers support disconnection */
	if (_usbd_device.driver->disconnect)
		_usbd_device.driver->disconnect(disconnected);
}

void usbd_ep_setup(u8 addr, u8 type, u16 max_size, void (*callback)(u8 ep))
{
	_usbd_device.driver->ep_setup(addr, type, max_size, callback);
}

u16 usbd_ep_write_packet(u8 addr, const void *buf, u16 len)
{
	return _usbd_device.driver->ep_write_packet(addr, buf, len);
}

u16 usbd_ep_read_packet(u8 addr, void *buf, u16 len)
{
	return _usbd_device.driver->ep_read_packet(addr, buf, len);
}

void usbd_ep_stall_set(u8 addr, u8 stall)
{
	_usbd_device.driver->ep_stall_set(addr, stall);
}

u8 usbd_ep_stall_get(u8 addr)
{
	return _usbd_device.driver->ep_stall_get(addr);
}

void usbd_ep_nak_set(u8 addr, u8 nak)
{
	_usbd_device.driver->ep_nak_set(addr, nak);
}
