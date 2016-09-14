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

#ifndef LIBOPENCM3_USBH_H
#define LIBOPENCM3_USBH_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <libopencm3/usb/usbstd.h>

/**
 * Type of endpoint
 */
enum usbh_ep_type {
	USBH_EP_CONTROL = 0, /**< Control endpoint */
	USBH_EP_ISOCHRONOUS = 1, /**< Isochronous endpoint */
	USBH_EP_BULK = 2, /**< Bulk endpoint */
	USBH_EP_INTERRUPT = 3 /**< Interrupt endpoint */
};

typedef enum usbh_ep_type usbh_ep_type;

typedef struct usbh_host usbh_host;
typedef struct usbh_device usbh_device;
typedef struct usbh_backend usbh_backend;
typedef struct usbh_transfer usbh_transfer;

typedef void (*usbh_connected_callback)(usbh_device *device);
typedef void (*usbh_disconnected_callback)(usbh_device *dev);

enum usbh_speed {
	USBH_SPEED_UNKNOWN = 0,
	USBH_SPEED_LOW = 1,
	USBH_SPEED_FULL = 2,
	USBH_SPEED_HIGH = 3,
	USBH_SPEED_SUPER = 4 /* cost nothing ;) */
};

typedef enum usbh_speed usbh_speed;

/**
 * USB Transfer flags
 */
enum usbh_transfer_flags {
	/** A readable value for special 0 */
	USBH_FLAG_NONE = 0,

	/**
	 * Transfer always end with a short packet,
	 *  even if it means adding an extra zero length packet.
	 * Currently only applies for bulk OUT
	 * Setting this flag on other transfer
	 */
	USBH_FLAG_ZERO_PACKET = (1 << 0),

	/**
	 * Transfer should never end with a short packet (less than endpoint size).
	 * If it does, treat it as error.
	 * This flag only applies to IN transfer (ie read).
	 */
	USBH_FLAG_NO_SHORT_PACKET = (1 << 1),

	/**
	 * Perform Per packet callback.
	 * When ever there is new data or library is going to transmit new data.
	 * Note: transfer will only proceed further when callback return.
	 * If callback want, it can make changes to the transfer data memory.
	 * transfer status = USBH_ONE_PACKET_DATA will be used.
	 *
	 * This feature is useful in case the transfer will require alot of memory.
	 *   (along with USBH_FLAG_NO_MEMORY_INCREMENT flag)
	 *  that is not fesible to allocate at runtime. but if the transfer is
	 *  done on packet to packet basis, it is possible to work in part.
	 *
	 * Also, when the callback will be done. "transferred" will contain:
	 *  for transmit, the number of bytes transmitted.
	 *  for received, the number of bytes already received
	 *
	 * Though this is an extension to the callback mechanism, but it allow
	 *  application to handle stuff on packet to packet basis.
	 *
	 * Do not assume that backend will call only when previous packet is required.
	 *  It could do call multiple time (in a row) to get multiple packets.
	 *
	 * If the transfer is setup, callback is performed for each data stage packet only.
	 */
	USBH_FLAG_PER_PACKET_CALLBACK = (1 << 2),

	/**
	 * Do not use incremented memory address [1] after packet receive or transmit.
	 * If this flag is set, it is assumed that the pointer provided can
	 *  atleast hold endpoint 1 max packet size data.
	 * Usually, if flag is used with flag USBH_FLAG_PER_PACKET_CALLBACK.
	 * so, that callback can update the data.
	 *
	 * [1] NOT talk of incrementing transfer::data.
	 *    transfer::data remain same as provided by user thoughout the transfer
	 *     life cycle.
	 *
	 * If flag effectively prevent `transfer->data + transfer->transferred`
	 *   and transfer everytime use `transfer->data`
	 *
	 * Setting this flag without USBH_FLAG_PER_PACKET_CALLBACK will
	 *  transmit all packet with same content.
	 *  receive the last packet content.
	 */
	USBH_FLAG_NO_MEMORY_INCREMENT = (1 << 3),

	/**
	 * Do not perform success callback.
	 * No callback with transfer status = USBH_SUCCESS will be performed.
	 */
	USBH_FLAG_NO_SUCCESS_CALLBACK = (1 << 4)
};

typedef enum usbh_transfer_flags usbh_transfer_flags;

/**
 * USB Transfer status
 */
enum usbh_transfer_status {
	/** Transfer status used for USBH_FLAG_PER_PACKET_CALLBACK flag */
	USBH_ONE_PACKET_DATA = 1,

	/** Success */
	USBH_SUCCESS = 0,

	/** Transfer has time'd out */
	USBH_ERR_TIMEOUT = -1,

	/** Input/Output Error */
	USBH_ERR_IO = -2,

	/** Transfer too large */
	USBH_ERR_SIZE = -3,

	/** Stall was receivied on endpoint.
	 *  For control transfer, this signify a failed control transfer
	 */
	USBH_ERR_STALL = -4,

	/** Resource unavailable, try again later. */
	USBH_ERR_RES_UNAVAIL = -5,

	/** There is no device (device disconnected?) */
	USBH_ERR_NO_DEVICE = -6,

	/** More data received than endpoint size in one packet */
	USBH_ERR_BABBLE = -7,

	/** Data toggle mismatch */
	USBH_ERR_DTOG = -8,

	/** Packet smaller than endpoint size received */
	USBH_ERR_SHORT_PACKET = -9,

	/** Invalid transfer requested.
	 * @warning if this status is passed to callback,
	 *   Callback SHOULD NOT consider library generated values
	 *    (usbh_transfer::id and usbh_transfer::transferred) as valid!
	 *  This is because library will try to return the original invalid transfer.
	 */
	USBH_ERR_INVALID = -10,

	/** Transfer cancelled by application */
	USBH_ERR_CANCEL = -11
};

typedef enum usbh_transfer_status usbh_transfer_status;

/* Though this is ugly but could be useful in future. */
typedef uint64_t usbh_urb_id;

typedef void (*usbh_transfer_callback)(const usbh_transfer *transfer,
	usbh_transfer_status status, usbh_urb_id urb_id);

/**
 * USB Transfer
 */
struct usbh_transfer {
	/** USB Device */
	usbh_device *device;

	/** Endpoint type */
	usbh_ep_type ep_type;

	/** Endpoint Address.
	 *   bit 0-3: Endpoint number
	 *   bit 7: HIGH = in-endpoint, LOW = out-endpoint
	 */
	uint8_t ep_addr;

	/** Endpoint size */
	uint16_t ep_size;

	/** Data to read/write */
	void *data;

	/** Number of bytes to transfer */
	uint16_t length;

	/** Number of bytes transferred to/from @a data
	 *  @warning Manipulated by library internally. not accepted from user
	 */
	uint16_t transferred;

	/** Transfer related flags */
	usbh_transfer_flags flags;

	/**
	 * Specifies the polling interval for interrupt or isochronous transfers.
	 * The units are frames (milliseconds) for full and low speed devices,
	 * and microframes (1/8 millisecond) for highspeed and SuperSpeed devices.
	 */
	uint16_t interval;

	/** Timeout, in milliseconds (0 for never timeout) */
	uint32_t timeout;

	/** Callback to perform when complete or error occur */
	usbh_transfer_callback callback;

	/** Setup data (control endpoint only) */
	struct usb_setup_data setup;

	/** User can keep any pointer that it may require later */
	void *user_data;
};

/* A readable value for special 0 */
#define USBH_TIMEOUT_NEVER 0

/* Marker ID of URB as invalid */
#define USBH_INVALID_URB_ID 0

extern usbh_backend usbh_stm32_otg_fs;

#define USBH_STM32_OTG_FS (&usbh_stm32_otg_fs)

/**
 * Init the host.
 * @param backend Host backend
 */
usbh_host *usbh_init(const usbh_backend *backend);

/**
 * Search for devices by @a parent
 * @param host USB Host
 * @param parent Parent device (NULL to get root hub)
 * @param[out] list List of devices found
 * @param list_size Maximum number of devices that can be placed in @a list
 * @return actual number of devices found
 * @return 0 if none found
 */
unsigned usbh_search_devices_by_parent(usbh_host *host, usbh_device *parent,
		usbh_device **list, unsigned list_size);

/**
 * Search for device by @a address
 * @param host USB Host
 * @param address Device bus address
 * @return reference to device object on success
 * @return NULL on failure
 */
usbh_device *usb_device_by_address(usbh_host *host, uint8_t address);

/**
 * Poll the host
 * @param host USB Host
 * @param us Number of microseconds passed since the last poll or init
 * @note it is recommended to poll every millisecond
 * @note it is recommended to provide atleast 0.1ms resolution in @a us
 */
void usbh_poll(usbh_host *host, uint32_t us);

/**
 * Register a callback for connected device
 * @param host USB Host
 * @param connected Callback
 */
void usbh_register_connected_callback(usbh_host *host,
		usbh_connected_callback connected);

/**
 * Get the parent device the device is connected to
 * @param dev USB Device
 * @return USB Device
 */
usbh_device *usbh_device_parent(usbh_device *dev);

/**
 * Get the device host it is attached to
 * @param dev USB Device
 * @return USB host
 */
usbh_host *usbh_device_host(usbh_device *dev);

/**
 * Get the device address
 * @param dev Device
 * @return device bus address
 */
uint8_t usbh_device_address(usbh_device *dev);

/**
 * Get the device port that it is connected to
 * @param dev Device
 * @return device port number on hub
 */
uint8_t usbh_device_port(usbh_device *dev);

/**
 * Get the device speed
 * @param dev Device
 * @return speed
 */
usbh_speed usbh_device_speed(usbh_device *dev);

/**
 * Register a callback for disconnected device
 * @param dev Device
 * @param disconnected Callback
 */
void usbh_device_register_disconnected_callback(usbh_device *dev,
		usbh_disconnected_callback disconnected);

/**
 * Get the device endpoint DTOG bit for @a ep
 * @param host USB Host
 * @param dev_addr Device address
 * @param ep Endpoint
 */
bool usbh_device_ep_dtog_get(usbh_device *dev, uint8_t ep);

/**
 * Set the device endpoint DTOG bit for @a ep
 * @param dev Device
 * @param ep Endpoint
 * @param dtog Data toggle
 */
void usbh_device_ep_dtog_set(usbh_device *dev, uint8_t ep, bool dtog);

/**
 * Set all DTOG bit to 0 for all endpoint.
 * @param dev USB Device
 * @param dtog Data toggle
 * @note useful for set configuration when all endpoint DTOG need to be reset
 */
void usbh_device_ep_dtog_reset_all(usbh_device *dev);

/**
 * Reset the USB device
 * @param dev Device
 * @note after this, @a dev is invalid
 */
void usbh_device_reset(usbh_device *dev);

/**
 * Read the device EP0 size.
 * If you are read from EP0 then you need to place EP0 value
 * The stack has to internally cache the value.
 * @param dev USB Device
 * @return USB Device bMaxEndpointSize0
 * @note as per USB specification, this value can only be one of {8, 16, 32, 64}
 */
uint8_t usbh_device_ep0_size(usbh_device *dev);

/**
 * Perform a control transfer
 * @param transfer Transfer
 * @return Valid URB ID on sucecss
 * @return Invalid URB ID on failure
 * @note @a transfer pointer need to be only valid till callee return.
 *    (go allocate @a transfer on stack!)
 * @note @a transfer::data need to be valid till callback is performed.
 * @warning if control ep, transfer->setup.wLength and transfer->length should match
 */
usbh_urb_id usbh_transfer_submit(const usbh_transfer *transfer);

/**
 * Cancel the transfer
 * @param host USB Host
 * @param urb_id URB ID
 */
void usbh_transfer_cancel(usbh_host *host, usbh_urb_id urb_id);

#endif
