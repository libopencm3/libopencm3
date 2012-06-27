/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_USB_H
#define LPC43XX_USB_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- USB0 registers ------------------------------------------------------ */

/* Device/host capability registers */

/* Capability register length */
#define USB0_CAPLENGTH                  MMIO32(USB0_BASE + 0x100)

/* Host controller structural parameters */
#define USB0_HCSPARAMS                  MMIO32(USB0_BASE + 0x104)

/* Host controller capability parameters */
#define USB0_HCCPARAMS                  MMIO32(USB0_BASE + 0x108)

/* Device interface version number */
#define USB0_DCIVERSION                 MMIO32(USB0_BASE + 0x120)

/* Device controller capability parameters */
#define USB0_DCCPARAMS                  MMIO32(USB0_BASE + 0x124)


/* Device/host operational registers */

/* USB command (device mode) */
#define USB0_USBCMD_D                   MMIO32(USB0_BASE + 0x140)

/* USB command (host mode) */
#define USB0_USBCMD_H                   MMIO32(USB0_BASE + 0x140)

/* USB status (device mode) */
#define USB0_USBSTS_D                   MMIO32(USB0_BASE + 0x144)

/* USB status (host mode) */
#define USB0_USBSTS_H                   MMIO32(USB0_BASE + 0x144)

/* USB interrupt enable (device mode) */
#define USB0_USBINTR_D                  MMIO32(USB0_BASE + 0x148)

/* USB interrupt enable (host mode) */
#define USB0_USBINTR_H                  MMIO32(USB0_BASE + 0x148)

/* USB frame index (device mode) */
#define USB0_FRINDEX_D                  MMIO32(USB0_BASE + 0x14C)

/* USB frame index (host mode) */
#define USB0_FRINDEX_H                  MMIO32(USB0_BASE + 0x14C)

/* USB device address (device mode) */
#define USB0_DEVICEADDR                 MMIO32(USB0_BASE + 0x154)

/* Frame list base address (host mode) */
#define USB0_PERIODICLISTBASE           MMIO32(USB0_BASE + 0x154)

/* Address of endpoint list in memory */
#define USB0_ENDPOINTLISTADDR           MMIO32(USB0_BASE + 0x158)

/* Asynchronous list address */
#define USB0_ASYNCLISTADDR              MMIO32(USB0_BASE + 0x158)

/* Asynchronous buffer status for embedded TT (host mode) */
#define USB0_TTCTRL                     MMIO32(USB0_BASE + 0x15C)

/* Programmable burst size */
#define USB0_BURSTSIZE                  MMIO32(USB0_BASE + 0x160)

/* Host transmit pre-buffer packet tuning (host mode) */
#define USB0_TXFILLTUNING               MMIO32(USB0_BASE + 0x164)

/* Length of virtual frame */
#define USB0_BINTERVAL                  MMIO32(USB0_BASE + 0x174)

/* Endpoint NAK (device mode) */
#define USB0_ENDPTNAK                   MMIO32(USB0_BASE + 0x178)

/* Endpoint NAK Enable (device mode) */
#define USB0_ENDPTNAKEN                 MMIO32(USB0_BASE + 0x17C)

/* Port 1 status/control (device mode) */
#define USB0_PORTSC1_D                  MMIO32(USB0_BASE + 0x184)

/* Port 1 status/control (host mode) */
#define USB0_PORTSC1_H                  MMIO32(USB0_BASE + 0x184)

/* OTG status and control */
#define USB0_OTGSC                      MMIO32(USB0_BASE + 0x1A4)

/* USB device mode (device mode) */
#define USB0_USBMODE_D                  MMIO32(USB0_BASE + 0x1A8)

/* USB device mode (host mode) */
#define USB0_USBMODE_H                  MMIO32(USB0_BASE + 0x1A8)


/* Device endpoint registers */

/* Endpoint setup status */
#define USB0_ENDPTSETUPSTAT             MMIO32(USB0_BASE + 0x1AC)

/* Endpoint initialization */
#define USB0_ENDPTPRIME                 MMIO32(USB0_BASE + 0x1B0)

/* Endpoint de-initialization */
#define USB0_ENDPTFLUSH                 MMIO32(USB0_BASE + 0x1B4)

/* Endpoint status */
#define USB0_ENDPTSTAT                  MMIO32(USB0_BASE + 0x1B8)

/* Endpoint complete */
#define USB0_ENDPTCOMPLETE              MMIO32(USB0_BASE + 0x1BC)

/* Endpoint control 0 */
#define USB0_ENDPTCTRL0                 MMIO32(USB0_BASE + 0x1C0)

/* Endpoint control 1 */
#define USB0_ENDPTCTRL1                 MMIO32(USB0_BASE + 0x1C4)

/* Endpoint control 2 */
#define USB0_ENDPTCTRL2                 MMIO32(USB0_BASE + 0x1C8)

/* Endpoint control 3 */
#define USB0_ENDPTCTRL3                 MMIO32(USB0_BASE + 0x1CC)

/* Endpoint control 4 */
#define USB0_ENDPTCTRL4                 MMIO32(USB0_BASE + 0x1D0)

/* Endpoint control 5 */
#define USB0_ENDPTCTRL5                 MMIO32(USB0_BASE + 0x1D4)


/* --- USB1 registers ------------------------------------------------------ */
//TODO

#endif
