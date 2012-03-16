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

#ifndef __DFU_H
#define __DFU_H

enum dfu_req {
	DFU_DETACH,
	DFU_DNLOAD,
	DFU_UPLOAD,
	DFU_GETSTATUS,
	DFU_CLRSTATUS,
	DFU_GETSTATE,
	DFU_ABORT,
};

enum dfu_status {
	DFU_STATUS_OK,
	DFU_STATUS_ERR_TARGET,
	DFU_STATUS_ERR_FILE,
	DFU_STATUS_ERR_WRITE,
	DFU_STATUS_ERR_ERASE,
	DFU_STATUS_ERR_CHECK_ERASED,
	DFU_STATUS_ERR_PROG,
	DFU_STATUS_ERR_VERIFY,
	DFU_STATUS_ERR_ADDRESS,
	DFU_STATUS_ERR_NOTDONE,
	DFU_STATUS_ERR_FIRMWARE,
	DFU_STATUS_ERR_VENDOR,
	DFU_STATUS_ERR_USBR,
	DFU_STATUS_ERR_POR,
	DFU_STATUS_ERR_UNKNOWN,
	DFU_STATUS_ERR_STALLEDPKT,
};

enum dfu_state {
	STATE_APP_IDLE,
	STATE_APP_DETACH,
	STATE_DFU_IDLE,
	STATE_DFU_DNLOAD_SYNC,
	STATE_DFU_DNBUSY,
	STATE_DFU_DNLOAD_IDLE,
	STATE_DFU_MANIFEST_SYNC,
	STATE_DFU_MANIFEST,
	STATE_DFU_MANIFEST_WAIT_RESET,
	STATE_DFU_UPLOAD_IDLE,
	STATE_DFU_ERROR,
};

#define DFU_FUNCTIONAL			0x21
struct usb_dfu_descriptor {
	u8 bLength;
	u8 bDescriptorType;
	u8 bmAttributes;
#define USB_DFU_CAN_DOWNLOAD		0x01
#define USB_DFU_CAN_UPLOAD		0x02
#define USB_DFU_MANIFEST_TOLERANT	0x04
#define USB_DFU_WILL_DETACH		0x08

	u16 wDetachTimeout;
	u16 wTransferSize;
	u16 bcdDFUVersion;
} __attribute__((packed));

#endif
