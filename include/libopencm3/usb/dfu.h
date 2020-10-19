/** @defgroup usb_dfu_defines USB DFU Type Definitions

@brief <b>Defined Constants and Types for the USB DFU Type Definitions</b>

@ingroup USB_defines

@version 1.0.0

@authors
@htmlonly &copy; @endhtmlonly 2010 Gareth McMullin <gareth@blacksphere.co.nz>
@authors
@htmlonly &copy; @endhtmlonly 2016 Dmitry Filimonchuk <dmitrystu@gmail.com>
@authors
@htmlonly &copy; @endhtmlonly 2020 Alexander Voronov <avv.0@ya.ru>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2016 Dmitry Filimonchuk <dmitrystu[at]gmail[dot]com>
 * Copyright (C) 2020 Alexander Voronov <avv.0@ya.ru>
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

#ifndef __DFU_H
#define __DFU_H

#include <stdint.h>

/**@name USB DFU class subclass and protocol definitions
 * @{*/
#define USB_CLASS_DFU		0xFE
#define USB_DFU_SUBCLASS_DFU	0x01
#define USB_DFU_PROTO_RUNTIME	0x01
#define USB_DFU_PROTO_DFU	0x02
/**@}*/

/**@anchor USB_DFU_DT
 * @name USB DFU descriptor types */
#define USB_DFU_DT_FUNCTIONAL	0x21

/**@name USB DFU class-specific requests
 * @{*/
/** Initiates a detach-attach sequence on the bus when it sees this request. */
#define USB_DFU_REQ_DETACH	0x00
/** Initiates firmware image downloading. */
#define USB_DFU_REQ_DNLOAD	0x01
/** This request is employed by the host to solicit firmware from the device.*/
#define USB_DFU_REQ_UPLOAD	0x02
/** The host employs this request to facilitate synchronization with the
 * device. */
#define USB_DFU_REQ_GETSTATUS	0x03
/** This request resets DFU machine state to DFU_IDLE. */
#define USB_DFU_REQ_CLRSTATUS	0x04
/** This request solicits a report about the state of the device. */
#define USB_DFU_REQ_GETSTATE	0x05
/** This request enables the host to exit from certain states and return
 * to the DFU_IDLE state. */
#define USB_DFU_REQ_ABORT	0x06
/**@}*/

/**@anchor USB_DFU_CAPAB
 * @name USB DFU capabilities
 * @{*/
/** Device will perform a bus detach-attach sequence when it receives a
 * DFU_DETACH request. */
#define USB_DFU_ATTR_WILL_DETACH	0x08
/** Device is able to communicate via USB after Manifestation phase. */
#define USB_DFU_ATTR_MANIF_TOL		0x04
#define USB_DFU_ATTR_CAN_UPLOAD		0x02
#define USB_DFU_ATTR_CAN_DNLOAD		0x01
/**@}*/

/**@anchor USB_DFU_STATUS
 * @name USB DFU status codes
 * @{*/
/** No error condition is present. */
#define USB_DFU_STATUS_OK		0x00
/** File is not targeted for use by this device. */
#define USB_DFU_STATUS_ERR_TARGET	0x01
/** File is for this device but fails some vendor specific verification test.*/
#define USB_DFU_STATUS_ERR_FILE		0x02
/** Device is unable to write memory. */
#define USB_DFU_STATUS_ERR_WRITE	0x03
/** Memory erase function failed. */
#define USB_DFU_STATUS_ERR_ERASE	0x04
/** Memory erase check failed. */
#define USB_DFU_STATUS_ERR_CHECK_ERASED	0x05
/** Program memory function failed. */
#define USB_DFU_STATUS_ERR_PROG		0x06
/** Programmed memory failed verification. */
#define USB_DFU_STATUS_ERR_VERIFY	0x07
/** Cannot program memory due to received address that is out of range. */
#define USB_DFU_STATUS_ERR_ADDRESS	0x08
/** Received DFU_DNLOAD with wLength = 0, but device does not think it
 * has all of the data yet. */
#define USB_DFU_STATUS_ERR_NOTDONE	0x09
/** Device's firmware is corrupt.  It cannot return to run-time (non-DFU)
 * operations. */
#define USB_DFU_STATUS_ERR_FIRMWARE	0x0A
/** iString indicates a vendor-specific error. */
#define USB_DFU_STATUS_ERR_VENDOR	0x0B
/** Device detected unexpected USB reset signaling. */
#define USB_DFU_STATUS_ERR_USBR		0x0C
/** Device detected unexpected power on reset. */
#define USB_DFU_STATUS_ERR_POR		0x0D
/** Something went wrong, but the device does not know what it was. */
#define USB_DFU_STATUS_ERR_UNKNOWN	0x0E
/** Device stalled an unexpected request. */
#define USB_DFU_STATUS_ERR_STALLEDPKT	0x0F
/**@}*/

/**@anchor USB_DFU_STATE
 * @name USB DFU state codes
 * @{*/
/** Device is running its normal application. */
#define USB_DFU_STATE_APP_IDLE		0x00
/** Device is running its normal application, has received the DFU_DETACH
 * request, and is waiting for a USB reset. */
#define USB_DFU_STATE_APP_DETACH	0x01
/** Device is operating in the DFU mode and is waiting for requests. */
#define USB_DFU_STATE_DFU_IDLE		0x02
/** Device has received a block and is waiting for the host to solicit
 * the status via DFU_GETSTATUS. */
#define USB_DFU_STATE_DFU_DNLOADSYNC	0x03
/** Device is programming a control-write block into its nonvolatile
 * memories. */
#define USB_DFU_STATE_DFU_DNBUSY	0x04
/** Device is processing a download operation. Expecting DFU_DNLOAD
 * requests. */
#define USB_DFU_STATE_DFU_DNLOADIDLE	0x05
/** Device has received the final block of firmware from the host and is
 * waiting for receipt of DFU_GETSTATUS to begin the Manifestation phase; or
 * device has completed the Manifestation phase and is waiting for receipt of
 * DFU_GETSTATUS.
 * @note Devices that can enter this state after the Manifestation phase set
 * bmAttributes bit bitManifestationTolerant to 1. */
#define USB_DFU_STATE_DFU_MANIFESTSYNC	0x06
/** Device is in the Manifestation phase.
 * @note Not all devices will be able to respond to DFU_GETSTATUS when in this
 * state. */
#define USB_DFU_STATE_DFU_MANIFEST	0x07
/** Device has programmed its memories and is waiting for a USB reset or
 * a power on reset.
 * @note Devices that must enter this state clear bitManifestationTolerant to
 * 0. */
#define USB_DFU_STATE_DFU_MANIFESTWR	0x08
/** The device is processing an upload operation. */
#define USB_DFU_STATE_DFU_UPLOADIDLE	0x09
/** An error has occurred. */
#define USB_DFU_STATE_DFU_ERROR		0x0A
/**@}*/

/** USB DFU functional descriptor */
struct usb_dfu_descriptor {
	/** Descriptor length in bytes. */
	uint8_t bLength;
	/** DFU functional \ref USB_DFU_DT "descriptor type". */
	uint8_t bDescriptorType;
	/** USB DFU \ref USB_DFU_CAPAB "capabilities"*/
	uint8_t bmAttributes;
	/** USB DFU detach timeout in ms. */
	uint16_t wDetachTimeout;
	/** USB DFU maximum transfer block size in bytes. */
	uint16_t wTransferSize;
	/** USB DFU version. */
	uint16_t bcdDFUVersion;
}__attribute__((packed));

/** Payload packet to response in DFU_GETSTATUS request */
struct usb_dfu_status {
	/** An indication of the \ref USB_DFU_STATUS "status" resulting from
	 * the execution of the most recent request. */
	uint8_t bStatus;
	/** Minimum time (LSB) in ms, that the host should wait before sending
	 * a subsequent DFU_GETSTATUS request. */
	uint8_t bPollTimeout;
	/** Minimum time (MSB) in ms, that the host should wait before sending
	 * a subsequent DFU_GETSTATUS request. */
	uint16_t wPollTimeout;
	/** An indication of the \ref USB_DFU_STATE "state" that the device is
	 * going to enter immediately following transmission of this
	 * response. */
	uint8_t bState;
	/** Index of the status string descriptor. */
	uint8_t iString;
};

#endif /* __DFU_H */

/**@}*/
