/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 ARCOS-Lab UCR <arcoslab.org> 
 * Copyright (C) 2012 Fernando Cortes <fernando.corcam@gmail.com>
 * Copyright (C) 2013 Guillermo Rivera <memogrg@gmail.com>
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

#ifndef LIBOPENCM3_USB_FS_H
#define LIBOPENCM3_USB_FS_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* Universal serial bus full-speed device interface (USB) registers */
#define USB_FS_EP0R			MMIO32(USB_FS_BASE + 0x00)
#define USB_FS_EP1R			MMIO32(USB_FS_BASE + 0x04)
#define USB_FS_EP2R			MMIO32(USB_FS_BASE + 0x08)
#define USB_FS_EP3R			MMIO32(USB_FS_BASE + 0x0C)
#define USB_FS_EP4R			MMIO32(USB_FS_BASE + 0x10)
#define USB_FS_EP5R			MMIO32(USB_FS_BASE + 0x14)
#define USB_FS_EP6R			MMIO32(USB_FS_BASE + 0x18)
#define USB_FS_EP7R			MMIO32(USB_FS_BASE + 0x1C)
#define USB_FS_CNTR			MMIO32(USB_FS_BASE + 0x40)
#define USB_FS_ISTR			MMIO32(USB_FS_BASE + 0x44)
#define USB_FS_FNR			MMIO32(USB_FS_BASE + 0x48)
#define USB_FS_DADDR			MMIO32(USB_FS_BASE + 0x4C)
#define USB_FS_BTABLE			MMIO32(USB_FS_BASE + 0x50)

/*------ USB control register (USB_CNTR) values ------*/

/* CTRM: Correct transfer interrupt mask */
#define USB_FS_CNTR_CTRM		(1 << 15)

/* PMAOVRM: Packet memory area over / underrun interrupt mask */
#define USB_FS_CNTR_PMAOVRM		(1 << 14)

/* ERRM: Error interrupt mask */
#define USB_FS_CNTR_ERRM		(1 << 13)

/* WKUPM: Wakeup interrupt mask */
#define USB_FS_CNTR_WKUPM		(1 << 12)

/* SUSPM: Suspend mode interrupt mask */
#define USB_FS_CNTR_SUSPM		(1 << 11)

/* RESETM: USB reset interrupt mask */
#define USB_FS_CNTR_RESETM		(1 << 10)

/* SOFM: Start of frame interrupt mask */
#define USB_FS_CNTR_SOFM		(1 << 9)

/* ESOFM: Expected start of frame interrupt mask */
#define USB_FS_CNTR_ESOFM		(1 << 8)

/* RESUME: Resume request */
#define USB_FS_CNTR_RESUME		(1 << 4)

/* FSUSP: Force suspend */
#define USB_FS_CNTR_FSUSP		(1 << 3)

/* LP_MODE: Low-power mode */
#define USB_FS_CNTR_LP_MODE		(1 << 2)

/* PDWN: Power down */
#define USB_FS_CNTR_PDWN		(1 << 1)

/* FRES: Force USB Reset */
#define USB_FS_CNTR_FRES		(1 << 0)


/*------ USB interrupt status register (USB_ISTR) values ------*/

/* CTR: Correct transfer */
#define USB_FS_ISTR_CTR			(1 << 15)

/* PMAOVR: Packet memory area over / underrun */
#define USB_FS_ISTR_PMAOVR		(1 << 14)

/* ERR: Error */
#define USB_FS_ISTR_ERR			(1 << 13)

/* WKUP: Wakeup */
#define USB_FS_ISTR_WKUP		(1 << 12)

/* SUSP: Suspend mode request */
#define USB_FS_ISTR_SUSP		(1 << 11)

/* RESET: USB reset request */
#define USB_FS_ISTR_RESET		(1 << 10)

/* SOF: Start fo frame */
#define USB_FS_ISTR_SOF			(1 << 9)

/* ESOF: Expected start of frame */
#define USB_FS_ISTR_ESOF		(1 << 8)

/* DIR: Direction of transaction */
#define USB_FS_ISTR_DIR			(1 << 4)

/* EP_ID[3:0]: Endpoint Identifier */


/*------ USB frame number register (USB_FNR) values ------*/

/* RXDP: Receive data + line status */
#define USB_FS_FNR_RXDP			(1 << 15)

/* RXDM: Receive data - line status */
#define USB_FS_FNR_RXDM			(1 << 14)

/* LCK: Locked */
#define USB_FS_FNR_LCK			(1 << 13)

/* LSOF[1:0]: Lost SOF  (12,11) */

/* FN[10:0]: Frame number (10,0) */


/*------ USB device address (USB_DADDR) values ------*/

/* EF: Enable function */
#define USB_FS_DADDR_EF			(1 << 7)

/* ADD[6:0]: Device address (6,0) */


/*------ Buffer table address (USB_BTABLE) values ------*/

/* BTABLE[15:3]: Buffer table (15,3) */


/*------ USB endpoint n register (USB_EP0R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP0R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP0R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP0R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP0R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP0R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP0R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP0R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP0R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP0R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP0R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP0R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP0R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP0R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP0R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP0R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP0R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP0R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP0R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*------ USB endpoint n register (USB_EP1R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP1R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP1R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP1R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP1R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP1R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP1R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP1R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP1R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP1R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP1R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP1R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP1R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP1R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP1R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP1R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP1R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP1R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP1R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*------ USB endpoint n register (USB_EP2R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP2R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP2R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP2R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP2R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP2R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP2R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP2R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP2R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP2R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP2R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP2R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP2R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP2R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP2R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP2R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP2R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP2R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP2R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*------ USB endpoint n register (USB_EP3R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP3R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP3R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP3R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP3R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP3R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP3R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP3R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP3R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP3R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP3R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP3R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP3R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP3R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP3R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP3R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP3R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP3R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP3R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*...... USB endpoint n register (USB_EP4R) values ......*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP4R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP4R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP4R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP4R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP4R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP4R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP4R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP4R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP4R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP4R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP4R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP4R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP4R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP4R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP4R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP4R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP4R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP4R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*------ USB endpoint n register (USB_EP5R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP5R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP5R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP5R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP5R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP5R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP5R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP5R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP5R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP5R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP5R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP5R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP5R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP5R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP5R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP5R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP5R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP5R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP5R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*------ USB endpoint n register (USB_EP6R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP6R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP6R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP6R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP6R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP6R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP6R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP6R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP6R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP6R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP6R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP6R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP6R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP6R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP6R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP6R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP6R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP6R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP6R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */


/*------ USB endpoint n register (USB_EP7R) values ------*/

/* CTR_RX: Correct Transfer for reception */
#define USB_FS_EP7R_CTR_RX		(1 << 15)

/* DTOG_RX: Data Toggle, for reception transfers */
#define USB_FS_EP7R_DTOG_RX		(1 << 14)

/* STAT_RX [1:0]: Status bits, for reception transfers (13,12) */
#define USB_FS_EP7R_STAT_RX_DISABLED	(0x0 << 12)
#define USB_FS_EP7R_STAT_RX_STALL	(0x1 << 12)
#define USB_FS_EP7R_STAT_RX_NAK		(0x2 << 12)
#define USB_FS_EP7R_STAT_RX_VALID	(0x3 << 12)

/* SETUP: Setup transaction completed */
#define USB_FS_EP7R_SETUP		(1 << 11)

/* EP_TYPE[1:0]: Endpoint type (10,9) */
#define USB_FS_EP7R_EP_TYPE_BULK	(0x0 << 12)
#define USB_FS_EP7R_EP_TYPE_CONTROL	(0x1 << 12)
#define USB_FS_EP7R_EP_TYPE_ISO		(0x2 << 12)
#define USB_FS_EP7R_EP_TYPE_INTERRUPT	(0x3 << 12)

/* EP_KIND: Endpoint kind */
#define USB_FS_EP7R_EP_KIND		(1 << 8)

/* CTR_TX: Correct Transfer for transmission */
#define USB_FS_EP7R_CTR_TX		(1 << 7)

/* DTOG_TX: Data Toggle, for transmission transfers */
#define USB_FS_EP7R_DTOG_TX		(1 << 6)

/* STAT_TX [1:0]: Status bits, for transmission transfers (5,4) */
#define USB_FS_EP7R_STAT_TX_DISABLED	(0x0 << 12)
#define USB_FS_EP7R_STAT_TX_STALL	(0x1 << 12)
#define USB_FS_EP7R_STAT_TX_NAK		(0x2 << 12)
#define USB_FS_EP7R_STAT_TX_VALID	(0x3 << 12)


/* EA[3:0]: Endpoint address (3,0) */




#endif
