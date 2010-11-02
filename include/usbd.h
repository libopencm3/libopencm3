/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010  Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __USBD_H
#define __USBD_H

#include <usbstd.h>

/* Static buffer for control transactions:
 * This is defined as weak in the library, applicaiton
 * may provide if a larger buffer is requred. */
extern uint8_t usbd_control_buffer[];

/* <usb.c> */
extern int usbd_init(const struct usb_device_descriptor *dev,
                     const struct usb_config_descriptor *conf,
		     const char **strings);
extern void usbd_set_control_buffer_size(uint16_t size);

extern void usbd_register_reset_callback(void (*callback)(void));
extern void usbd_register_suspend_callback(void (*callback)(void));
extern void usbd_register_resume_callback(void (*callback)(void));

/* <usb_control.c> */
extern void usbd_register_control_command_callback(
	int (*callback)(struct usb_setup_data *req,
		void (**complete)(struct usb_setup_data *req)));
extern void usbd_register_control_read_callback(
	int (*callback)(struct usb_setup_data *req, uint8_t **buf, 
		uint16_t *len, void (**complete)(struct usb_setup_data *req)));
extern void usbd_register_control_write_callback(
	int (*callback)(struct usb_setup_data *req, uint8_t *buf, 
		uint16_t len, void (**complete)(struct usb_setup_data *req)));

/* <usb_standard.c> */
extern void 
usbd_register_set_config_callback(void (*callback)(uint16_t wValue));


/* Functions to be provided by the hardware abstraction layer */
extern void usbd_poll(void);

extern void usbd_ep_setup(uint8_t addr, uint8_t type, uint16_t max_size, 
	      void (*callback)(uint8_t ep));

extern uint16_t
usbd_ep_write_packet(uint8_t addr, const void *buf, uint16_t len);

extern uint16_t 
usbd_ep_read_packet(uint8_t addr, void *buf, uint16_t len);

extern void usbd_ep_stall(uint8_t addr);

/* Optional */
extern void usbd_cable_connect(uint8_t on);

#endif

