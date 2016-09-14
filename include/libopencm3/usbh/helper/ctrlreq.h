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

#include <libopencm3/usbh/usbh.h>
#include <libopencm3/usb/usbstd.h>

/**
 * Perform a Control request on EP0
 * Use to perform callback, instead of manually configuring transfer.
 * @param dev USB Device
 * @param bmRequestType bmRequestType
 * @param bRequest bRequest
 * @param wValue wValue
 * @param wIndex wIndex
 * @param data data
 * @param wLength wLength
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_ctrlreq_ep0(usbh_device *dev, uint8_t bmRequestType,
	uint8_t bRequest, uint16_t wValue, uint16_t wIndex,
	void *data, uint16_t wLength, usbh_transfer_callback callback);

/**
 * Read a descriptor from device
 * @param dev USB Device
 * @param type Descriptor type
 * @param index Descriptor index (non zero for configuration and string)
 * @param buf Buffer to store to
 * @param len Maximum number of bytes can be readed
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_ctrlreq_read_desc(usbh_device *dev, uint8_t type,
	uint8_t index, void *buf, uint16_t len, usbh_transfer_callback callback);

/**
 * Read the device descriptor from device
 * @param dev USB Device
 * @param desc Descriptor to store
 * @param len Total number of bytes that can be written to @a desc
 * @param callback Callback when done
 * @note use @a len = USB_DT_DEVICE_SIZE for full length
 * @return URB ID
 */
usbh_urb_id usbh_ctrlreq_read_dev_desc(usbh_device *dev, void *desc,
	uint16_t len, usbh_transfer_callback callback);

/**
 * Read a configuration descriptor from device
 * @param dev USB Device
 * @param index Configuration descriptor index
 * @param desc Descriptor to store
 * @param len Total number of bytes that can be written to @a desc
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_ctrlreq_read_config_desc(usbh_device *dev, uint8_t index,
	void *desc, uint16_t len, usbh_transfer_callback callback);

/**
 * Read a string descriptor from device
 * @param dev USB Device
 * @param index String descriptor index
 * @param desc Descriptor to store
 * @param len Total number of bytes that can be written to @a desc
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_ctrlreq_read_string_desc(usbh_device *dev, uint8_t index,
	void *desc, uint16_t len, usbh_transfer_callback callback);

/**
 * Set an address to device
 * @param dev USB Device
 * @param addr Address to assign
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_ctrlreq_set_address(usbh_device *dev, uint8_t addr,
	usbh_transfer_callback callback);

/**
 * Set the configuration value to the device
 * @param dev USB Device
 * @param bConfigurationValue Configuration value
 * @param callback Callback when done
 * @return URB ID
 * @note the stack do not set all dtog bits,
 *   application code need to manually set dtog to  0.
 *   application code can use usbh_ctrlreq_set_config() for the purpose.
 */
usbh_urb_id usbh_ctrlreq_set_config(usbh_device *dev,
	uint8_t bConfigurationValue, usbh_transfer_callback callback);

/**
 * Set the interface on device
 * @param dev USB Device
 * @param bInterface Interface to set
 * @param bAlternateSetting Alternate setting for Interface
 * @param callback Callback when done
 * @return URB ID
 * @note the stack internally do not keep track of endpoint for the interface.
 *    so, in after set interface, application have to manually set dtog to 0.
 */
usbh_urb_id usbh_ctrlreq_set_interface(usbh_device *dev, uint8_t bInterface,
	uint8_t bAlternateSetting, usbh_transfer_callback callback);
