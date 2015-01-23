/** @defgroup usb_msc_defines USB MSC Type Definitions

@brief <b>Defined Constants and Types for the USB MSC Type Definitions</b>

@ingroup USB_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013
Weston Schmidt <weston_schmidt@alumni.purdue.edu>
Pavol Rusnak <stick@gk2.sk>

@date 27 June 2013

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Weston Schmidt <weston_schmidt@alumni.purdue.edu>
 * Copyright (C) 2013 Pavol Rusnak <stick@gk2.sk>
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

#ifndef __MSC_H
#define __MSC_H

typedef struct _usbd_mass_storage usbd_mass_storage;

/* Definitions of Mass Storage Class from:
 *
 * (A) "Universal Serial Bus Mass Storage Class Bulk-Only Transport
 *      Revision 1.0"
 *
 * (B) "Universal Serial Bus Mass Storage Class Specification Overview
 *      Revision 1.0"
 */

/* (A) Table 4.5: Mass Storage Device Class Code */
#define USB_CLASS_MSC			0x08

/* (B) Table 2.1: Class Subclass Code */
#define USB_MSC_SUBCLASS_RBC		0x01
#define USB_MSC_SUBCLASS_ATAPI		0x02
#define USB_MSC_SUBCLASS_UFI		0x04
#define USB_MSC_SUBCLASS_SCSI		0x06
#define USB_MSC_SUBCLASS_LOCKABLE	0x07
#define USB_MSC_SUBCLASS_IEEE1667	0x08

/* (B) Table 3.1 Mass Storage Interface Class Control Protocol Codes */
#define USB_MSC_PROTOCOL_CBI		0x00
#define USB_MSC_PROTOCOL_CBI_ALT	0x01
#define USB_MSC_PROTOCOL_BBB		0x50

/* (B) Table 4.1 Mass Storage Request Codes */
#define USB_MSC_REQ_CODES_ADSC		0x00
#define USB_MSC_REQ_CODES_GET		0xFC
#define USB_MSC_REQ_CODES_PUT		0xFD
#define USB_MSC_REQ_CODES_GML		0xFE
#define USB_MSC_REQ_CODES_BOMSR		0xFF

/* (A) Table 3.1/3.2 Class-Specific Request Codes */
#define USB_MSC_REQ_BULK_ONLY_RESET	0xFF
#define USB_MSC_REQ_GET_MAX_LUN		0xFE

usbd_mass_storage *usb_msc_init(usbd_device *usbd_dev,
				 uint8_t ep_in, uint8_t ep_in_size,
				 uint8_t ep_out, uint8_t ep_out_size,
				 const char *vendor_id,
				 const char *product_id,
				 const char *product_revision_level,
				 const uint32_t block_count,
				 int (*read_block)(uint32_t lba, uint8_t *copy_to),
				 int (*write_block)(uint32_t lba, const uint8_t *copy_from));

#endif

/**@}*/
