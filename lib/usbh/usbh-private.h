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

#ifndef LIBOPENCM3_USBH_PRIVATE_H
#define LIBOPENCM3_USBH_PRIVATE_H

/*
 * The design is inspired from libusb and Linux Kernel.
 * You can think of Linux kernel + libusb for microcontroller.
 *
 * Optimization
 * ===========
 * - We have no malloc/free/realloc (so compile time allocation only!)
 * - Flexibility over "low" memory wastage
 * - Use flash when ever possible to store Data structure that are readonly.
 * - Use RAM only when it is required (ie legimate reason), look for other ways.
 * - No Blocking calls, use callbacks
 *     libusb async transfer like interface implementation is only possible
 *      due to this requirement.
 * - If possible, try to make interface like libusb or Linux kernel.
 *     This is not a requirement, just a recommendation.
 *     Anything similar to a know information is easier to remember.
 *
 * Note
 * ====
 * To keep footprint smaller,
 * It is not possible to keep track of which interface use which endpoint.
 * That would require
 * - fetching whole configuration descriptor
 * - parse it and extract information
 * - then store the runtime information (memory required)
 *
 * So, application has to do it and pass appropriately to drivers,
 * - SET_INTERFACE, Clear DTOG of the endpoints inside it.
 * 	@a usbh_device_ep_clear() will be handy.
 * - SET_CONFIGURATION, Clear ALL DTOG of the endpoint.
 * 	@a usbh_device_ep_all_clear() will be handy.
 *
 * Note
 * ====
 * Also, the stack manage external device connect/disconnect (on hub).
 * so, you can see the code as (usb-stack + hub-driver)  [WIP, not implemented]
 *
 * Note
 * ====
 * Usually uC have one processor. so multithreaded is not an issue!
 */

/*
 * TODO
 * ====
 * - HUB code NOT written. current code only handles root device connect/disconnect.
 * - Write helper/ functions to convert UTF-16 to UTF-8 (and possibly for ASCII too)
 * - Add more Standard request in helper/stdreq.{c, h}  (backend independent!)
 * - Bulk (IN, OUT) transfer need testing
 * - Interrupt OUT transfer need testing
 * - Add Support for Isochronous (IN, OUT)
 * - Think of a generic "USB classes" driver API for application code.
 */

#include <libopencm3/usbh/usbh.h>

/**
 * USB Device
 * @param host USB Host (if NULL, marker of object as unused)
 * @param parent Parent USB Device
 * @param port Port at which connected to parent
 * @param address Address on bus (0 as address not assigned)
 * @param ep0_max_packet_size bMaxPacketSize0 of device descriptor
 *    (or a compatible value)
 * @param speed Speed of device
 * @param dtog Data Toggle bits
 * @param disconnected Called when the device get disconnected.
 * @param hub_ports Number of port of the hub.
 *    If the device is not an hub, should be 0.
 * @param buffer a static buffer to fetch some descriptor internally
 *     Used at
 */
struct usbh_device {
	usbh_host *host;
	usbh_device *parent;
	uint8_t port;
	uint8_t address;
	uint8_t ep0_max_packet_size;
	usbh_speed speed;
	/* BITx (x=0...15) = OUT EPx DTOG
	 * BITx (x=16...31) = IN EPy DTOG (y = x - 16).
	 *
	 * Inside the callback, DTOG bit is:
	 *  - the packet is going to be transmitted with
	 *  - the packet is received for */
	uint32_t dtog;
	usbh_disconnected_callback disconnected;
	uint8_t hub_ports;
};

/**
 * USB Request Block
 */
struct usbh_urb {
	/** URB (USB Request Block) ID (0 is invalid) */
	usbh_urb_id id;

	/** A copy of Transfer object provided by application */
	usbh_transfer transfer;

	/** Backend allocated channel to URB (all high as invalid) */
	uint8_t backend_tag;

	/**
	 * Timeout value (microseconds) at
	 *   which the URB will become invalid.
	 *   If the field is 0, that means the the timeout is not enabled.
	 */
	uint64_t timeout_on;
};

typedef struct usbh_urb usbh_urb;

struct usbh_backend {
	/**
	 * Initalize the backend
	 */
	usbh_host *(*init)(void);

	/** @copydoc usbh_host_speed() */
	usbh_speed (*speed)(usbh_host *host);

	/**
	 * Poll the peripherial.
	 * @param host USB Host
	 * @param now Current time = `last_poll + us`
	 */
	void (*poll)(usbh_host *host, uint64_t now);

	/** @copydoc usbh_reset() */
	void (*reset)(usbh_host *host);

	/**
	 * Submit the @a urb to @a host
	 * @param host USB Host
	 * @param urb USB Request Block
	 * @return Backend TAG
	 */
	void (*transfer_submit)(usbh_host *host, usbh_urb *urb);

	/**
	 * Cancel the URB
	 * @param host USB Host
	 * @param urb USB Request Block
	 */
	void (*transfer_cancel)(usbh_host *host, usbh_urb *urb);
};

#define URB_ARRAY_LENGTH 12

/** The maximum number of devices the host can hold. */
#define DEVICE_ARRAY_LENGTH 8

/**
 * USB Host
 * @param backend Host backend
 * @param last_poll Last time the has was polled via usbh_poll()
 * @param connected called when new device is connected on bus
 * @param next_device_address Bus address for next device
 * @param devices Static array of devices to store information
 *    If the list become full, new devices will be dropped if item on available.
 *    The list will also INCLUDE ROOT HUB.
 * @param next_urb_id Next URB ID (start from 1)
 * @param buffer Buffer to fetch device descriptor for device at enumeration.
 *    Used for one device at a time.
 */
struct usbh_host {
	const usbh_backend *backend;
	void *backend_data;
	uint64_t last_poll;
	usbh_connected_callback connected;
	uint8_t next_device_address;
	usbh_device devices[DEVICE_ARRAY_LENGTH];
	usbh_urb_id next_urb_id;
	usbh_urb urbs[URB_ARRAY_LENGTH];
	uint8_t buffer[8];
};

void usbh_device_ep_dtog_toggle(usbh_device *host, uint8_t ep);

/**
 * Divide @a a by @a b and return the ceiling of quotient
 * @param a Dividend
 * @param b Divisor
 * @return ceiling of quotient
 */
#define DIV_AND_CEIL(a, b) (((a) + (b) - 1) / (b))

/** Convert milliseconds to microseconds */
#define MS2US(ms) ((ms) * 1000)

/**
 * Perform a callback for transfer
 * @param t Transfer
 * @param status Status of transfer
 * @param transferred Length of data transferred
 */
#define TRANSFER_CALLBACK(transfer, status, urb_id)					\
	if ((transfer)->callback != NULL) {								\
		(transfer)->callback((transfer), (status), (urb_id));		\
	}

/**
 * Perform callback when no channel (aka pipe) is available for transfer
 * @param t Transfer
 */
#define TRANSFER_NO_RES(t)		\
	TRANSFER_CALLBACK((t), USBH_ERR_RES_UNAVAIL, USBH_INVALID_URB_ID)

/**
 * Perform callback when transfer is invalid
 * @param t Transfer
 */
#define TRANSFER_INVALID(t)		\
	TRANSFER_CALLBACK((t), USBH_ERR_INVALID, USBH_INVALID_URB_ID)

#define URB_CALLBACK(urb, status)		\
	TRANSFER_CALLBACK(&(urb)->transfer, status, (urb)->id)

#if defined(USBH_DEBUG)
extern void usbh_log_puts(const char *arg);
extern void usbh_log_printf(const char *fmt, ...)
	__attribute__((format(printf, 1, 2)));
#include <inttypes.h>
#define NEW_LINE "\n"
#define LOG(str) usbh_log_puts(str)
#define LOG_LN(str) LOG(str); LOG(NEW_LINE)
#define LOG_CALL LOG("inside "); LOG(__func__); LOG(NEW_LINE);
#define LOGF(fmt,...) usbh_log_printf(fmt, ##__VA_ARGS__)
#define LOGF_LN(fmt,...) LOGF(fmt, __VA_ARGS__); LOG(NEW_LINE)
#else
#define NEW_LINE
#define LOG(str)
#define LOG_LN(str)
#define LOG_CALL
#define LOGF(fmt,...)
#define LOGF_LN(fmt,...)
#endif

#define INVALID_BACKEND_TAG 0xFF

#define IS_OUT_ENDPOINT(ep_addr) (!((ep_addr) & 0x80))
#define IS_IN_ENDPOINT(ep_addr) ((ep_addr) & 0x80)

#define IS_ROOT_HUB(dev) ((dev)->parent == NULL)

#define MIN(a, b) (((a) > (b)) ? (b) : (a))

#define IS_URB_ID_INVALID(urb_id) ((urb_id) == USBH_INVALID_URB_ID)
#define IS_URB_INVALID(urb) IS_URB_ID_INVALID((urb)->id)

#define IS_DEVICE_INVALID(dev) ((dev)->host == NULL)
#define IS_DEVICE_VALID(dev) (!IS_DEVICE_INVALID(dev))

/**
 * Generate a mask for uint32_t so that Data Toggle can be extracted
 *  from the device->dtog value
 * @param ep_addr Endpoint address
 * @return mask
 */
static inline uint32_t ep_dtog_mask(uint8_t ep_addr)
{
	bool ep_in = IS_IN_ENDPOINT(ep_addr);
	uint8_t ep_num = ep_addr & 0x7F;
	return 1 << (ep_num + (ep_in ? 16 : 0));
}

void usbh_device_enum_start(usbh_device *dev);
void usbh_device_invalidate(usbh_device *dev);
void usbh_device_disconnected(usbh_device *dev);
void usbh_device_connected(usbh_host *host, usbh_device *parent,
		uint8_t port, usbh_speed speed);

void usbh_root_device_disconnected(usbh_host *host);
void usbh_root_device_connected(usbh_host *host, usbh_speed speed);

void *usbh_urb_get_data_pointer(usbh_urb *urb, uint16_t len);
void usbh_urb_inc_data_pointer(usbh_urb *urb, uint16_t len);
void usbh_urb_free(usbh_urb *urb, usbh_transfer_status status);
void usbh_urb_invalidate(usbh_urb *urb);

void usbh_hub_reset_port(usbh_device *dev, uint8_t port);

#endif
