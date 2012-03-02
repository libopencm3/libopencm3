/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <string.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/tools.h>
#include <libopencm3/stm32/otg_fs.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 128
static uint16_t fifo_mem_top;
static uint16_t fifo_mem_top_ep0;

static u8 force_nak[4];

static void stm32f107_usbd_init(void);
static void stm32f107_set_address(u8 addr);
static void stm32f107_ep_setup(u8 addr, u8 type, u16 max_size,
			       void (*callback)(u8 ep));
static void stm32f107_endpoints_reset(void);
static void stm32f107_ep_stall_set(u8 addr, u8 stall);
static u8 stm32f107_ep_stall_get(u8 addr);
static void stm32f107_ep_nak_set(u8 addr, u8 nak);
static u16 stm32f107_ep_write_packet(u8 addr, const void *buf, u16 len);
static u16 stm32f107_ep_read_packet(u8 addr, void *buf, u16 len);
static void stm32f107_poll(void);
static void stm32f107_disconnect(bool disconnected);

/*
 * We keep a backup copy of the out endpoint size registers to restore them
 * after a transaction.
 */
static u32 doeptsiz[4];

const struct _usbd_driver stm32f107_usb_driver = {
	.init = stm32f107_usbd_init,
	.set_address = stm32f107_set_address,
	.ep_setup = stm32f107_ep_setup,
	.ep_reset = stm32f107_endpoints_reset,
	.ep_stall_set = stm32f107_ep_stall_set,
	.ep_stall_get = stm32f107_ep_stall_get,
	.ep_nak_set = stm32f107_ep_nak_set,
	.ep_write_packet = stm32f107_ep_write_packet,
	.ep_read_packet = stm32f107_ep_read_packet,
	.poll = stm32f107_poll,
	.disconnect = stm32f107_disconnect,
};

/** Initialize the USB device controller hardware of the STM32. */
static void stm32f107_usbd_init(void)
{
	OTG_FS_GINTSTS = OTG_FS_GINTSTS_MMIS;

	OTG_FS_GUSBCFG |= OTG_FS_GUSBCFG_PHYSEL;
	/* Enable VBUS sensing in device mode and power down the PHY. */
	OTG_FS_GCCFG |= OTG_FS_GCCFG_VBUSBSEN | OTG_FS_GCCFG_PWRDWN;

	/* Wait for AHB idle. */
	while (!(OTG_FS_GRSTCTL & OTG_FS_GRSTCTL_AHBIDL)) ;
	/* Do core soft reset. */
	OTG_FS_GRSTCTL |= OTG_FS_GRSTCTL_CSRST;
	while (OTG_FS_GRSTCTL & OTG_FS_GRSTCTL_CSRST) ;

	/* Force peripheral only mode. */
	OTG_FS_GUSBCFG |= OTG_FS_GUSBCFG_FDMOD | OTG_FS_GUSBCFG_TRDT_MASK;

	/* Full speed device. */
	OTG_FS_DCFG |= OTG_FS_DCFG_DSPD;

	/* Restart the PHY clock. */
	OTG_FS_PCGCCTL = 0;

	OTG_FS_GRXFSIZ = RX_FIFO_SIZE;
	fifo_mem_top = RX_FIFO_SIZE;

	/* Unmask interrupts for TX and RX. */
	OTG_FS_GAHBCFG |= OTG_FS_GAHBCFG_GINT;
	OTG_FS_GINTMSK = OTG_FS_GINTMSK_ENUMDNEM |
			 OTG_FS_GINTMSK_RXFLVLM |
			 OTG_FS_GINTMSK_IEPINT |
			 OTG_FS_GINTMSK_USBSUSPM |
			 OTG_FS_GINTMSK_WUIM |
			 OTG_FS_GINTMSK_SOFM;
	OTG_FS_DAINTMSK = 0xF;
	OTG_FS_DIEPMSK = OTG_FS_DIEPMSK_XFRCM;
}

static void stm32f107_set_address(u8 addr)
{
	OTG_FS_DCFG = (OTG_FS_DCFG & ~OTG_FS_DCFG_DAD) | (addr << 4);
}

static void stm32f107_ep_setup(u8 addr, u8 type, u16 max_size,
			       void (*callback) (u8 ep))
{
	/*
	 * Configure endpoint address and type. Allocate FIFO memory for
	 * endpoint. Install callback funciton.
	 */
	u8 dir = addr & 0x80;
	addr &= 0x7f;

	if (addr == 0) { /* For the default control endpoint */
		/* Configure IN part. */
		if (max_size >= 64) {
			OTG_FS_DIEPCTL0 = OTG_FS_DIEPCTL0_MPSIZ_64;
		} else if (max_size >= 32) {
			OTG_FS_DIEPCTL0 = OTG_FS_DIEPCTL0_MPSIZ_32;
		} else if (max_size >= 16) {
			OTG_FS_DIEPCTL0 = OTG_FS_DIEPCTL0_MPSIZ_16;
		} else {
			OTG_FS_DIEPCTL0 = OTG_FS_DIEPCTL0_MPSIZ_8;
		}
		OTG_FS_DIEPTSIZ0 = (max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		OTG_FS_DIEPCTL0 |= OTG_FS_DIEPCTL0_EPENA | OTG_FS_DIEPCTL0_SNAK;

		/* Configure OUT part. */
		doeptsiz[0] = OTG_FS_DIEPSIZ0_STUPCNT_1 | (1 << 19) |
			(max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		OTG_FS_DOEPTSIZ(0) = doeptsiz[0];
		OTG_FS_DOEPCTL(0) |=
		    OTG_FS_DOEPCTL0_EPENA | OTG_FS_DIEPCTL0_SNAK;

		OTG_FS_GNPTXFSIZ = ((max_size / 4) << 16) | RX_FIFO_SIZE;
		fifo_mem_top += max_size / 4;
		fifo_mem_top_ep0 = fifo_mem_top;

		return;
	}

	if (dir) {
		OTG_FS_DIEPTXF(addr) = ((max_size / 4) << 16) | fifo_mem_top;
		fifo_mem_top += max_size / 4;

		OTG_FS_DIEPTSIZ(addr) =
		    (max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		OTG_FS_DIEPCTL(addr) |=
		    OTG_FS_DIEPCTL0_EPENA | OTG_FS_DIEPCTL0_SNAK | (type << 18)
		    | OTG_FS_DIEPCTL0_USBAEP | OTG_FS_DIEPCTLX_SD0PID
		    | (addr << 22) | max_size;

		if (callback) {
			_usbd_device.
			    user_callback_ctr[addr][USB_TRANSACTION_IN] =
			    (void *)callback;
		}
	}

	if (!dir) {
		doeptsiz[addr] = (1 << 19) |
				 (max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		OTG_FS_DOEPTSIZ(addr) = doeptsiz[addr];
		OTG_FS_DOEPCTL(addr) |= OTG_FS_DOEPCTL0_EPENA |
		    OTG_FS_DOEPCTL0_USBAEP | OTG_FS_DIEPCTL0_CNAK |
		    OTG_FS_DOEPCTLX_SD0PID | (type << 18) | max_size;

		if (callback) {
			_usbd_device.
			    user_callback_ctr[addr][USB_TRANSACTION_OUT] =
			    (void *)callback;
		}
	}
}

static void stm32f107_endpoints_reset(void)
{
	/* The core resets the endpoints automatically on reset. */
	fifo_mem_top = fifo_mem_top_ep0;
}

static void stm32f107_ep_stall_set(u8 addr, u8 stall)
{
	if (addr == 0) {
		if (stall)
			OTG_FS_DIEPCTL(addr) |= OTG_FS_DIEPCTL0_STALL;
		else
			OTG_FS_DIEPCTL(addr) &= ~OTG_FS_DIEPCTL0_STALL;
	}

	if (addr & 0x80) {
		addr &= 0x7F;

		if (stall) {
			OTG_FS_DIEPCTL(addr) |= OTG_FS_DIEPCTL0_STALL;
		} else {
			OTG_FS_DIEPCTL(addr) &= ~OTG_FS_DIEPCTL0_STALL;
			OTG_FS_DIEPCTL(addr) |= OTG_FS_DIEPCTLX_SD0PID;
		}
	} else {
		if (stall) {
			OTG_FS_DOEPCTL(addr) |= OTG_FS_DOEPCTL0_STALL;
		} else {
			OTG_FS_DOEPCTL(addr) &= ~OTG_FS_DOEPCTL0_STALL;
			OTG_FS_DOEPCTL(addr) |= OTG_FS_DOEPCTLX_SD0PID;
		}
	}
}

static u8 stm32f107_ep_stall_get(u8 addr)
{
	/* Return non-zero if STALL set. */
	if (addr & 0x80)
		return
		 (OTG_FS_DIEPCTL(addr & 0x7f) & OTG_FS_DIEPCTL0_STALL) ? 1 : 0;
	else
		return (OTG_FS_DOEPCTL(addr) & OTG_FS_DOEPCTL0_STALL) ? 1 : 0;
}

static void stm32f107_ep_nak_set(u8 addr, u8 nak)
{
	/* It does not make sence to force NAK on IN endpoints. */
	if (addr & 0x80)
		return;

	force_nak[addr] = nak;

	if (nak)
		OTG_FS_DOEPCTL(addr) |= OTG_FS_DOEPCTL0_SNAK;
	else
		OTG_FS_DOEPCTL(addr) |= OTG_FS_DOEPCTL0_CNAK;
}

static u16 stm32f107_ep_write_packet(u8 addr, const void *buf, u16 len)
{
	const u32 *buf32 = buf;
	int i;

	addr &= 0x7F;

	/* Return if endpoint is already enabled. */
	if (OTG_FS_DIEPTSIZ(addr) & OTG_FS_DIEPSIZ0_PKTCNT)
		return 0;

	/* Enable endpoint for transmission. */
	OTG_FS_DIEPTSIZ(addr) = (1 << 19) | len;
	OTG_FS_DIEPCTL(addr) |= OTG_FS_DIEPCTL0_EPENA | OTG_FS_DIEPCTL0_CNAK;

	/* Copy buffer to endpoint FIFO. */
	volatile u32 *fifo = OTG_FS_FIFO(addr);
	for (i = len; i > 0; i -= 4)
		*fifo++ = *buf32++;

	return len;
}

/*
 * Received packet size for each endpoint. This is assigned in
 * stm32f107_poll() which reads the packet status push register GRXSTSP
 * for use in stm32f107_ep_read_packet().
 */
static uint16_t rxbcnt;

static u16 stm32f107_ep_read_packet(u8 addr, void *buf, u16 len)
{
	int i;
	u32 *buf32 = buf;
	u32 extra;

	len = MIN(len, rxbcnt);
	rxbcnt -= len;

	volatile u32 *fifo = OTG_FS_FIFO(addr);
	for (i = len; i >= 4; i -= 4)
		*buf32++ = *fifo++;

	if (i) {
		extra = *fifo++;
		memcpy(buf32, &extra, i);
	}

	OTG_FS_DOEPTSIZ(addr) = doeptsiz[addr];
	OTG_FS_DOEPCTL(addr) |= OTG_FS_DOEPCTL0_EPENA |
	    (force_nak[addr] ? OTG_FS_DOEPCTL0_SNAK : OTG_FS_DOEPCTL0_CNAK);

	return len;
}

static void stm32f107_poll(void)
{
	/* Read interrupt status register. */
	u32 intsts = OTG_FS_GINTSTS;
	int i;

	if (intsts & OTG_FS_GINTSTS_ENUMDNE) {
		/* Handle USB RESET condition. */
		OTG_FS_GINTSTS = OTG_FS_GINTSTS_ENUMDNE;
		fifo_mem_top = RX_FIFO_SIZE;
		_usbd_reset();
		return;
	}

	/* Note: RX and TX handled differently in this device. */
	if (intsts & OTG_FS_GINTSTS_RXFLVL) {
		/* Receive FIFO non-empty. */
		u32 rxstsp = OTG_FS_GRXSTSP;
		u32 pktsts = rxstsp & OTG_FS_GRXSTSP_PKTSTS_MASK;
		if ((pktsts != OTG_FS_GRXSTSP_PKTSTS_OUT) &&
		    (pktsts != OTG_FS_GRXSTSP_PKTSTS_SETUP))
			return;

		u8 ep = rxstsp & OTG_FS_GRXSTSP_EPNUM_MASK;
		u8 type;
		if (pktsts == OTG_FS_GRXSTSP_PKTSTS_SETUP)
			type = USB_TRANSACTION_SETUP;
		else
			type = USB_TRANSACTION_OUT;

		/* Save packet size for stm32f107_ep_read_packet(). */
		rxbcnt = (rxstsp & OTG_FS_GRXSTSP_BCNT_MASK) >> 4;

		/*
		 * FIXME: Why is a delay needed here?
		 * This appears to fix a problem where the first 4 bytes
		 * of the DATA OUT stage of a control transaction are lost.
		 */
		for (i = 0; i < 1000; i++)
			__asm__("nop");

		if (_usbd_device.user_callback_ctr[ep][type])
			_usbd_device.user_callback_ctr[ep][type] (ep);

		/* Discard unread packet data. */
		for (i = 0; i < rxbcnt; i += 4)
			(void)*OTG_FS_FIFO(ep);

		rxbcnt = 0;
	}

	/*
	 * There is no global interrupt flag for transmit complete.
	 * The XFRC bit must be checked in each OTG_FS_DIEPINT(x).
	 */
	for (i = 0; i < 4; i++) { /* Iterate over endpoints. */
		if (OTG_FS_DIEPINT(i) & OTG_FS_DIEPINTX_XFRC) {
			/* Transfer complete. */
			if (_usbd_device.
			    user_callback_ctr[i][USB_TRANSACTION_IN]) {
				_usbd_device.
				   user_callback_ctr[i][USB_TRANSACTION_IN](i);
			}
			OTG_FS_DIEPINT(i) = OTG_FS_DIEPINTX_XFRC;
		}
	}

	if (intsts & OTG_FS_GINTSTS_USBSUSP) {
		if (_usbd_device.user_callback_suspend)
			_usbd_device.user_callback_suspend();
		OTG_FS_GINTSTS = OTG_FS_GINTSTS_USBSUSP;
	}

	if (intsts & OTG_FS_GINTSTS_WKUPINT) {
		if (_usbd_device.user_callback_resume)
			_usbd_device.user_callback_resume();
		OTG_FS_GINTSTS = OTG_FS_GINTSTS_WKUPINT;
	}

	if (intsts & OTG_FS_GINTSTS_SOF) {
		if (_usbd_device.user_callback_sof)
			_usbd_device.user_callback_sof();
		OTG_FS_GINTSTS = OTG_FS_GINTSTS_SOF;
	}
}

static void stm32f107_disconnect(bool disconnected)
{
	if (disconnected) {
		OTG_FS_DCTL |= OTG_FS_DCTL_SDIS;
	} else {
		OTG_FS_DCTL &= ~OTG_FS_DCTL_SDIS;
	}
}
