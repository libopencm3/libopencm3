/** @defgroup usb_driver_defines USB Drivers

@brief <b>Defined Constants and Types for the USB Drivers</b>

@ingroup USB_defines

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

#ifndef __USBD_H
#define __USBD_H

#include <libopencm3/usb/usbstd.h>

#define OUT		0
#define IN		1

#define EP00_OUT	((OUT << 7) | 0x00)
#define EP00_IN		((IN  << 7) | 0x00)
#define EP01_OUT	((OUT << 7) | 0x01)
#define EP01_IN		((IN  << 7) | 0x01)
#define EP02_OUT	((OUT << 7) | 0x02)
#define EP02_IN		((IN  << 7) | 0x02)
#define EP03_OUT	((OUT << 7) | 0x03)
#define EP03_IN		((IN  << 7) | 0x03)
#define EP04_OUT	((OUT << 7) | 0x04)
#define EP04_IN		((IN  << 7) | 0x04)
#define EP05_OUT	((OUT << 7) | 0x05)
#define EP05_IN		((IN  << 7) | 0x05)
#define EP06_OUT	((OUT << 7) | 0x06)
#define EP06_IN		((IN  << 7) | 0x06)
#define EP07_OUT	((OUT << 7) | 0x07)
#define EP07_IN		((IN  << 7) | 0x07)
#define EP08_OUT	((OUT << 7) | 0x08)
#define EP08_IN		((IN  << 7) | 0x08)
#define EP09_OUT	((OUT << 7) | 0x09)
#define EP09_IN		((IN  << 7) | 0x09)
#define EP10_OUT	((OUT << 7) | 0x0A)
#define EP10_IN		((IN  << 7) | 0x0A)
#define EP11_OUT	((OUT << 7) | 0x0B)
#define EP11_IN		((IN  << 7) | 0x0B)
#define EP12_OUT	((OUT << 7) | 0x0C)
#define EP12_IN		((IN  << 7) | 0x0C)
#define EP13_OUT	((OUT << 7) | 0x0D)
#define EP13_IN		((IN  << 7) | 0x0D)
#define EP14_OUT	((OUT << 7) | 0x0E)
#define EP14_IN		((IN  << 7) | 0x0E)
#define EP15_OUT	((OUT << 7) | 0x0F)
#define EP15_IN 	((IN  << 7) | 0x0F)

BEGIN_DECLS


enum usbd_request_return_codes {
	USBD_REQ_NOTSUPP	= 0,
	USBD_REQ_HANDLED	= 1,
	USBD_REQ_NEXT_CALLBACK	= 2,
};

typedef struct _usbd_driver usbd_driver;
typedef struct _usbd_device usbd_device;

extern const usbd_driver stm32f103_usb_driver;
extern const usbd_driver stm32f107_usb_driver;
extern const usbd_driver stm32f207_usb_driver;
#define otgfs_usb_driver stm32f107_usb_driver
#define otghs_usb_driver stm32f207_usb_driver

/* <usb.c> */
extern usbd_device * usbd_init(const usbd_driver *driver,
			       const struct usb_device_descriptor *dev,
			       const struct usb_config_descriptor *conf,
			       const char **strings, int num_strings,
			       uint8_t *control_buffer,
			       uint16_t control_buffer_size);

extern void usbd_register_reset_callback(usbd_device *usbd_dev,
					 void (*callback)(void));
extern void usbd_register_suspend_callback(usbd_device *usbd_dev,
					   void (*callback)(void));
extern void usbd_register_resume_callback(usbd_device *usbd_dev,
					  void (*callback)(void));
extern void usbd_register_sof_callback(usbd_device *usbd_dev,
				       void (*callback)(void));

typedef int (*usbd_control_callback)(usbd_device *usbd_dev,
		struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
		void (**complete)(usbd_device *usbd_dev,
				  struct usb_setup_data *req));

/* <usb_control.c> */
extern int usbd_register_control_callback(usbd_device *usbd_dev, uint8_t type,
					  uint8_t type_mask,
					  usbd_control_callback callback);

/* <usb_standard.c> */
extern int usbd_register_set_config_callback(usbd_device *usbd_dev,
	void (*callback)(usbd_device *usbd_dev, uint16_t wValue));

/* Functions to be provided by the hardware abstraction layer */
extern void usbd_poll(usbd_device *usbd_dev);
extern void usbd_disconnect(usbd_device *usbd_dev, bool disconnected);

extern void usbd_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
		uint16_t max_size,
		void (*callback)(usbd_device *usbd_dev, uint8_t ep));

extern uint16_t usbd_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
				const void *buf, uint16_t len);

extern uint16_t usbd_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
			       void *buf, uint16_t len);

extern void usbd_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
			      uint8_t stall);
extern uint8_t usbd_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);

extern void usbd_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);

/* Optional */
extern void usbd_cable_connect(usbd_device *usbd_dev, uint8_t on);

END_DECLS

#endif

/**@}*/

