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

#ifndef __USB_PRIVATE_H
#define __USB_PRIVATE_H

#define MAX_USER_CONTROL_CALLBACK	4

#define MIN(a, b) ((a)<(b) ? (a) : (b))

/** Internal collection of device information. */
struct _usbd_device {
	const struct usb_device_descriptor *desc;
	const struct usb_config_descriptor *config;
	const char **strings;

	u8 *ctrl_buf;  /**< Internal buffer used for control transfers */
	u16 ctrl_buf_len;

	u8 current_address;
	u8 current_config;

	u16 pm_top;    /**< Top of allocated endpoint buffer memory */

	/* User callback functions for various USB events */
	void (*user_callback_reset)(void);
	void (*user_callback_suspend)(void);
	void (*user_callback_resume)(void);
	void (*user_callback_sof)(void);

	struct usb_control_state {
		enum {
			IDLE, STALLED,
			DATA_IN, LAST_DATA_IN, STATUS_IN,
			DATA_OUT, LAST_DATA_OUT, STATUS_OUT,
		} state;
		struct usb_setup_data req __attribute__((aligned(4)));
		u8 *ctrl_buf;
		u16 ctrl_len;
		void (*complete)(usbd_device *usbd_dev,
				 struct usb_setup_data *req);
	} control_state;

	struct user_control_callback {
		usbd_control_callback cb;
		u8 type;
		u8 type_mask;
	} user_control_callback[MAX_USER_CONTROL_CALLBACK];

	void (*user_callback_ctr[8][3])(usbd_device *usbd_dev, u8 ea);

	/* User callback function for some standard USB function hooks */
	void (*user_callback_set_config)(usbd_device *usbd_dev, u16 wValue);

	const struct _usbd_driver *driver;

	/* private driver data */

	uint16_t fifo_mem_top;
	uint16_t fifo_mem_top_ep0;
    u8 force_nak[4];
    /*
     * We keep a backup copy of the out endpoint size registers to restore them
     * after a transaction.
     */
    u32 doeptsiz[4];
    /*
     * Received packet size for each endpoint. This is assigned in
     * stm32f107_poll() which reads the packet status push register GRXSTSP
     * for use in stm32f107_ep_read_packet().
     */
    uint16_t rxbcnt;
};

enum _usbd_transaction {
	USB_TRANSACTION_IN,
	USB_TRANSACTION_OUT,
	USB_TRANSACTION_SETUP,
};

void _usbd_control_in(usbd_device *usbd_dev, u8 ea);
void _usbd_control_out(usbd_device *usbd_dev, u8 ea);
void _usbd_control_setup(usbd_device *usbd_dev, u8 ea);

int _usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
			   u8 **buf, u16 *len);

void _usbd_reset(usbd_device *usbd_dev);

/* Functions provided by the hardware abstraction. */
struct _usbd_driver {
	usbd_device *(*init)(void);
	void (*set_address)(usbd_device *usbd_dev, u8 addr);
	void (*ep_setup)(usbd_device *usbd_dev, u8 addr, u8 type, u16 max_size,
			 void (*cb)(usbd_device *usbd_dev, u8 ep));
	void (*ep_reset)(usbd_device *usbd_dev);
	void (*ep_stall_set)(usbd_device *usbd_dev, u8 addr, u8 stall);
	void (*ep_nak_set)(usbd_device *usbd_dev, u8 addr, u8 nak);
	u8 (*ep_stall_get)(usbd_device *usbd_dev, u8 addr);
	u16 (*ep_write_packet)(usbd_device *usbd_dev, u8 addr, const void *buf,
			       u16 len);
	u16 (*ep_read_packet)(usbd_device *usbd_dev, u8 addr, void *buf,
			      u16 len);
	void (*poll)(usbd_device *usbd_dev);
	void (*disconnect)(usbd_device *usbd_dev, bool disconnected);
	u32 base_address;
	bool set_address_before_status;
	u16 rx_fifo_size;
};

#endif
