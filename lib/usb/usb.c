/** @defgroup usb_drivers_file Generic USB Drivers

@ingroup USB

@brief <b>Generic USB Drivers</b>

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

#include <string.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

usbd_device *usbd_init(const usbd_driver *driver,
		       const struct usb_device_descriptor *dev,
		       const struct usb_config_descriptor *conf,
		       const char * const *strings, int num_strings,
		       uint8_t *control_buffer, uint16_t control_buffer_size)
{
	usbd_device *usbd_dev;

	usbd_dev = driver->init();

	usbd_dev->driver = driver;
	usbd_dev->desc = dev;
	usbd_dev->config = conf;
	usbd_dev->strings = strings;
	usbd_dev->num_strings = num_strings;
	usbd_dev->ctrl_buf = control_buffer;
	usbd_dev->ctrl_buf_len = control_buffer_size;

	usbd_dev->user_callback_ctr[0][USB_TRANSACTION_SETUP] =
	    _usbd_control_setup;
	usbd_dev->user_callback_ctr[0][USB_TRANSACTION_OUT] =
	    _usbd_control_out;
	usbd_dev->user_callback_ctr[0][USB_TRANSACTION_IN] =
	    _usbd_control_in;

	int i;
	for (i = 0; i < MAX_USER_SET_CONFIG_CALLBACK; i++) {
		usbd_dev->user_callback_set_config[i] = NULL;
	}

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

void _usbd_reset(usbd_device *usbd_dev)
{
	usbd_dev->current_address = 0;
	usbd_dev->current_config = 0;
	usbd_ep_setup(usbd_dev, 0, USB_ENDPOINT_ATTR_CONTROL, usbd_dev->desc->bMaxPacketSize0, NULL);
	usbd_dev->driver->set_address(usbd_dev, 0);

	if (usbd_dev->user_callback_reset) {
		usbd_dev->user_callback_reset();
	}
}

/* Functions to wrap the low-level driver */
void usbd_poll(usbd_device *usbd_dev)
{
	usbd_dev->driver->poll(usbd_dev);
}

__attribute__((weak)) void usbd_disconnect(usbd_device *usbd_dev,
					   bool disconnected)
{
	/* not all drivers support disconnection */
	if (usbd_dev->driver->disconnect) {
		usbd_dev->driver->disconnect(usbd_dev, disconnected);
	}
}

void usbd_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
		   uint16_t max_size, usbd_endpoint_callback callback)
{
	usbd_dev->driver->ep_setup(usbd_dev, addr, type, max_size, callback);
}

uint16_t usbd_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
			 const void *buf, uint16_t len)
{
	return usbd_dev->driver->ep_write_packet(usbd_dev, addr, buf, len);
}

uint16_t usbd_ep_read_packet(usbd_device *usbd_dev, uint8_t addr, void *buf,
			     uint16_t len)
{
	return usbd_dev->driver->ep_read_packet(usbd_dev, addr, buf, len);
}

void usbd_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall)
{
	usbd_dev->driver->ep_stall_set(usbd_dev, addr, stall);
}

uint8_t usbd_ep_stall_get(usbd_device *usbd_dev, uint8_t addr)
{
	return usbd_dev->driver->ep_stall_get(usbd_dev, addr);
}

void usbd_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak)
{
	usbd_dev->driver->ep_nak_set(usbd_dev, addr, nak);
}

/**@}*/

