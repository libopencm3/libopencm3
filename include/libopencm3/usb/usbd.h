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

BEGIN_DECLS


enum usbd_request_return_codes {
	USBD_REQ_NOTSUPP	= 0,
	USBD_REQ_HANDLED	= 1,
	USBD_REQ_NEXT_CALLBACK	= 2,
};

typedef struct _usbd_driver usbd_driver;
typedef struct _usbd_device usbd_device;

extern const usbd_driver st_usbfs_v1_usb_driver;
extern const usbd_driver stm32f107_usb_driver;
extern const usbd_driver stm32f207_usb_driver;
extern const usbd_driver st_usbfs_v2_usb_driver;
#define otgfs_usb_driver stm32f107_usb_driver
#define otghs_usb_driver stm32f207_usb_driver
extern const usbd_driver efm32lg_usb_driver;
extern const usbd_driver efm32hg_usb_driver;
extern const usbd_driver lm4f_usb_driver;

/* <usb.c> */
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
 * @param strings Pointer to an array of strings for USB string descriptors.
 *                Referenced in @e iSomething fields, e.g. @a iManufacturer.
 *                Since a zero index means "no string", an iSomething value of
 *                1 refers strings[0].
 * @param num_strings Number of items in @a strings array.
 * @param control_buffer Pointer to array that would hold the data
 *                       received during control requests with DATA
 *                       stage
 * @param control_buffer_size Size of control_buffer
 * @return the usb device initialized for use. (currently cannot fail).
 *
 * To place @a strings entirely into Flash/read-only memory, use
 * @code static const * const strings[] = { ... }; @endcode
 * (note the double @e const.)  The first @e const refers to the strings
 * while the second @e const refers to the array.
 */
extern usbd_device * usbd_init(const usbd_driver *driver,
			       const struct usb_device_descriptor *dev,
			       const struct usb_config_descriptor *conf,
			       const char * const *strings, int num_strings,
			       uint8_t *control_buffer,
			       uint16_t control_buffer_size);

/** Registers a reset callback */
extern void usbd_register_reset_callback(usbd_device *usbd_dev,
					 void (*callback)(void));
/** Registers a suspend callback */
extern void usbd_register_suspend_callback(usbd_device *usbd_dev,
					   void (*callback)(void));
/** Registers a resume callback */
extern void usbd_register_resume_callback(usbd_device *usbd_dev,
					  void (*callback)(void));
/** Registers a SOF callback */
extern void usbd_register_sof_callback(usbd_device *usbd_dev,
				       void (*callback)(void));

typedef void (*usbd_control_complete_callback)(usbd_device *usbd_dev,
		struct usb_setup_data *req);

typedef enum usbd_request_return_codes (*usbd_control_callback)(
		usbd_device *usbd_dev,
		struct usb_setup_data *req, uint8_t **buf, uint16_t *len,
		usbd_control_complete_callback *complete);

typedef void (*usbd_set_config_callback)(usbd_device *usbd_dev,
					 uint16_t wValue);

typedef void (*usbd_set_altsetting_callback)(usbd_device *usbd_dev,
					     uint16_t wIndex, uint16_t wValue);

typedef void (*usbd_endpoint_callback)(usbd_device *usbd_dev, uint8_t ep);

/* <usb_control.c> */
/** Registers a control callback.
 *
 * Since the list of user control callbacks is cleared every time
 * device configuration is set (inside usb_standard_set_configuration()),
 * control callback registration must happen inside (or after) the
 * config callback. The specified callback will be called if
 * (type == (bmRequestType & type_mask)).
 * @sa usbd_register_set_config_callback
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param type Handled request type
 * @param type_mask Mask to apply before matching request type
 * @param callback your desired callback function
 * @return 0 if successful
 */
extern int usbd_register_control_callback(usbd_device *usbd_dev, uint8_t type,
					  uint8_t type_mask,
					  usbd_control_callback callback);

/* <usb_standard.c> */
/** Registers a "Set Config" callback
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param callback your desired callback function
 * @return 0 if successful or already existed.
 * @return -1 if no more space was available for callbacks.
 */
extern int usbd_register_set_config_callback(usbd_device *usbd_dev,
					  usbd_set_config_callback callback);
/** Registers a "Set Interface" (alternate setting) callback
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param callback your desired callback function
 */
extern void usbd_register_set_altsetting_callback(usbd_device *usbd_dev,
					usbd_set_altsetting_callback callback);

/* Functions to be provided by the hardware abstraction layer */
extern void usbd_poll(usbd_device *usbd_dev);

/** Disconnect, if supported by the driver
 *
 * This function is implemented as weak function and can be replaced by an
 * application specific version to handle chips that don't have built-in
 * handling for this (e.g. STM32F1.)
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param disconnected true to request a disconnect
 */
extern void usbd_disconnect(usbd_device *usbd_dev, bool disconnected);

/** Setup an endpoint
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param addr Full EP address including direction (e.g. 0x01 or 0x81)
 * @param type Value for bmAttributes (USB_ENDPOINT_ATTR_*)
 * @param max_size Endpoint max size
 * @param callback your desired callback function
 * @note The stack only supports 8 endpoints, 0..7, so don't try
 * and use arbitrary addresses here, even though USB itself would allow this.
 * Not all backends support arbitrary addressing anyway.
 */
extern void usbd_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
		uint16_t max_size, usbd_endpoint_callback callback);

/** Write a packet
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param addr EP address (direction is ignored)
 * @param buf pointer to user data to write
 * @param len # of bytes
 * @return 0 if failed, len if successful
 */
extern uint16_t usbd_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
				const void *buf, uint16_t len);

/** Read a packet
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param addr EP address
 * @param buf user buffer that will receive data
 * @param len # of bytes
 * @return Actual # of bytes read
 */
extern uint16_t usbd_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
			       void *buf, uint16_t len);
/** Set/clear STALL condition on an endpoint
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param addr Full EP address (with direction bit)
 * @param stall if 0, clear STALL, else set stall.
 */
extern void usbd_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
			      uint8_t stall);

/** Get STALL status of an endpoint
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param addr Full EP address (with direction bit)
 * @return nonzero if endpoint is stalled
 */
extern uint8_t usbd_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);

/** Set an Out endpoint to NAK
 * @param usbd_dev the usb device handle returned from @ref usbd_init
 * @param addr EP address
 * @param nak if nonzero, set NAK
 */
extern void usbd_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);

END_DECLS

#endif

/**@}*/

