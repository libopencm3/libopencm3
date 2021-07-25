/** @defgroup usb_private_defines USB Private Structures

@brief <b>Defined Constants and Types for the USB Private Structures</b>

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

#ifndef __USB_PRIVATE_H
#define __USB_PRIVATE_H

#define MAX_USER_CONTROL_CALLBACK	4
#define MAX_USER_SET_CONFIG_CALLBACK	4

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/** Internal collection of device information. */
struct _usbd_device {
	const struct usb_device_descriptor *desc;
	const struct usb_config_descriptor *config;
	const char * const *strings;
	int num_strings;

	uint8_t *ctrl_buf;  /**< Internal buffer used for control transfers */
	uint16_t ctrl_buf_len;

	uint8_t current_address;
	uint8_t current_config;

	uint16_t pm_top;    /**< Top of allocated endpoint buffer memory */

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
		uint8_t *ctrl_buf;
		uint16_t ctrl_len;
		usbd_control_complete_callback complete;
		bool needs_zlp;
	} control_state;

	struct user_control_callback {
		usbd_control_callback cb;
		uint8_t type;
		uint8_t type_mask;
	} user_control_callback[MAX_USER_CONTROL_CALLBACK];

	usbd_endpoint_callback user_callback_ctr[8][3];

	/* User callback function for some standard USB function hooks */
	usbd_set_config_callback user_callback_set_config[MAX_USER_SET_CONFIG_CALLBACK];

	usbd_set_altsetting_callback user_callback_set_altsetting;

	const struct _usbd_driver *driver;

	/* Extra, non-contiguous user string descriptor index and value */
	int extra_string_idx;
	const char* extra_string;

	/* private driver data */

	uint16_t fifo_mem_top;
	uint16_t fifo_mem_top_ep0;
	uint8_t force_nak[4];
	/*
	 * We keep a backup copy of the out endpoint size registers to restore
	 * them after a transaction.
	 */
	uint32_t doeptsiz[4];
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

/* Do not appear to belong to the API, so are omitted from docs */
/**@}*/

void _usbd_control_in(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_out(usbd_device *usbd_dev, uint8_t ea);
void _usbd_control_setup(usbd_device *usbd_dev, uint8_t ea);

enum usbd_request_return_codes _usbd_standard_request_device(usbd_device *usbd_dev,
				  struct usb_setup_data *req, uint8_t **buf,
				  uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_interface(usbd_device *usbd_dev,
				     struct usb_setup_data *req, uint8_t **buf,
				     uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request_endpoint(usbd_device *usbd_dev,
				    struct usb_setup_data *req, uint8_t **buf,
				    uint16_t *len);
enum usbd_request_return_codes _usbd_standard_request(usbd_device *usbd_dev, struct usb_setup_data *req,
			   uint8_t **buf, uint16_t *len);

void _usbd_reset(usbd_device *usbd_dev);

/* Functions provided by the hardware abstraction. */
struct _usbd_driver {
	usbd_device *(*init)(void);
	void (*set_address)(usbd_device *usbd_dev, uint8_t addr);
	void (*ep_setup)(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
			 uint16_t max_size, usbd_endpoint_callback cb);
	void (*ep_reset)(usbd_device *usbd_dev);
	void (*ep_stall_set)(usbd_device *usbd_dev, uint8_t addr,
			     uint8_t stall);
	void (*ep_nak_set)(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
	uint8_t (*ep_stall_get)(usbd_device *usbd_dev, uint8_t addr);
	uint16_t (*ep_write_packet)(usbd_device *usbd_dev, uint8_t addr,
				    const void *buf, uint16_t len);
	uint16_t (*ep_read_packet)(usbd_device *usbd_dev, uint8_t addr,
				   void *buf, uint16_t len);
	void (*poll)(usbd_device *usbd_dev);
	void (*disconnect)(usbd_device *usbd_dev, bool disconnected);
	uint32_t base_address;
	bool set_address_before_status;
	uint16_t rx_fifo_size;
};

#endif

