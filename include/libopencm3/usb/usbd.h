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

#ifndef __USBD_H
#define __USBD_H

#include <libopencm3/usb/usbstd.h>

typedef struct _usbd_driver usbd_driver;
extern const usbd_driver stm32f103_usb_driver;
extern const usbd_driver stm32f107_usb_driver;
#define otgfs_usb_driver stm32f107_usb_driver

/* Static buffer for control transactions:
 * This is defined as weak in the library, applicaiton
 * may provide if a larger buffer is requred. */
extern u8 usbd_control_buffer[];

/* <usb.c> */
extern int usbd_init(const usbd_driver *driver,
		     const struct usb_device_descriptor *dev,
                     const struct usb_config_descriptor *conf,
		     const char **strings);
extern void usbd_set_control_buffer_size(u16 size);

extern void usbd_register_reset_callback(void (*callback)(void));
extern void usbd_register_suspend_callback(void (*callback)(void));
extern void usbd_register_resume_callback(void (*callback)(void));
extern void usbd_register_sof_callback(void (*callback)(void));

typedef int (*usbd_control_callback)(struct usb_setup_data *req, u8 **buf,
	    u16 *len, void (**complete)(struct usb_setup_data *req));

/* <usb_control.c> */
extern int usbd_register_control_callback(u8 type, u8 type_mask,
			usbd_control_callback callback);

/* <usb_standard.c> */
extern void usbd_register_set_config_callback(void (*callback)(u16 wValue));

/* Functions to be provided by the hardware abstraction layer */
extern void usbd_poll(void);
extern void usbd_disconnect(bool disconnected);

extern void usbd_ep_setup(u8 addr, u8 type, u16 max_size,
	      void (*callback)(u8 ep));

extern u16 usbd_ep_write_packet(u8 addr, const void *buf, u16 len);

extern u16 usbd_ep_read_packet(u8 addr, void *buf, u16 len);

extern void usbd_ep_stall_set(u8 addr, u8 stall);
extern u8 usbd_ep_stall_get(u8 addr);

extern void usbd_ep_nak_set(u8 addr, u8 nak);

/* Optional */
extern void usbd_cable_connect(u8 on);

#endif
