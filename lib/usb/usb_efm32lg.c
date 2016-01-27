/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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
#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/efm32/cmu.h>
#include <libopencm3/efm32/usb.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 256

/* FIME: EFM32LG have 6 bidirectonal-endpoint
 *  problem is "uint32_t doeptsiz[4];" in usb_private.h
 *  doeptsiz is fixed size of length 4,
 *  if we it to be of length 6
 * possibly, same with "uint8_t force_nak[4];"
 *
 * solution: remove everything driver specific from usb_private.h
 *  and move that to there specific driver files.
 * maybe a pointer to driver specific data will do the task. */

#define ENDPOINT_COUNT 4

static struct _usbd_device _usbd_dev;

/** Initialize the USB_FS device controller hardware of the STM32. */
static usbd_device *efm32lg_usbd_init(void)
{
	/* Enable clock */
	CMU_HFCORECLKEN0 |= CMU_HFCORECLKEN0_USB | CMU_HFCORECLKEN0_USBC;
	CMU_CMD = CMU_CMD_USBCCLKSEL_HFCLKNODIV;

	/* wait till clock not selected */
	while (!(CMU_STATUS & CMU_STATUS_USBCHFCLKSEL));

	USB_GINTSTS = USB_GINTSTS_MMIS;

	USB_CTRL &= ~USB_CTRL_DMPUAP;
	USB_ROUTE = USB_ROUTE_DMPUPEN | USB_ROUTE_PHYPEN;

	/* Wait for AHB idle. */
	while (!(USB_GRSTCTL & USB_GRSTCTL_AHBIDL));
	/* Do core soft reset. */
	USB_GRSTCTL |= USB_GRSTCTL_CSRST;
	while (USB_GRSTCTL & USB_GRSTCTL_CSRST);

	/* Force peripheral only mode. */
	USB_GUSBCFG |= USB_GUSBCFG_FDMOD | USB_GUSBCFG_TRDT_16BIT;

	/* Full speed device. */
	USB_DCFG |= USB_DCFG_DSPD;

	/* Restart the PHY clock. */
	USB_PCGCCTL = 0;

	USB_GRXFSIZ = efm32lg_usb_driver.rx_fifo_size;
	_usbd_dev.fifo_mem_top = efm32lg_usb_driver.rx_fifo_size;

	/* Unmask interrupts for TX and RX. */
	USB_GAHBCFG |= USB_GAHBCFG_GLBLINTRMSK;
	USB_GINTMSK = USB_GINTMSK_ENUMDNEM |
			 USB_GINTMSK_RXFLVLM |
			 USB_GINTMSK_IEPINT |
			 USB_GINTMSK_USBSUSPM |
			 USB_GINTMSK_WUIM;
	USB_DAINTMSK = 0xF;
	USB_DIEPMSK = USB_DIEPMSK_XFRCM;

	return &_usbd_dev;
}

static void efm32lg_set_address(usbd_device *usbd_dev, uint8_t addr)
{
	(void)usbd_dev;

	USB_DCFG = (USB_DCFG & ~USB_DCFG_DAD) | (addr << 4);
}

static void efm32lg_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
			uint16_t max_size,
			void (*callback) (usbd_device *usbd_dev, uint8_t ep))
{
	/*
	 * Configure endpoint address and type. Allocate FIFO memory for
	 * endpoint. Install callback funciton.
	 */
	uint8_t dir = addr & 0x80;
	addr &= 0x7f;

	if (addr == 0) { /* For the default control endpoint */
		/* Configure IN part. */
		if (max_size >= 64) {
			USB_DIEP0CTL = USB_DIEP0CTL_MPSIZ_64;
		} else if (max_size >= 32) {
			USB_DIEP0CTL = USB_DIEP0CTL_MPSIZ_32;
		} else if (max_size >= 16) {
			USB_DIEP0CTL = USB_DIEP0CTL_MPSIZ_16;
		} else {
			USB_DIEP0CTL = USB_DIEP0CTL_MPSIZ_8;
		}

		USB_DIEP0TSIZ =
			(max_size & USB_DIEP0TSIZ_XFRSIZ_MASK);
		USB_DIEP0CTL |=
			USB_DIEP0CTL_EPENA | USB_DIEP0CTL_SNAK;

		/* Configure OUT part. */
		usbd_dev->doeptsiz[0] = USB_DIEP0TSIZ_STUPCNT_1 |
			USB_DIEP0TSIZ_PKTCNT |
			(max_size & USB_DIEP0TSIZ_XFRSIZ_MASK);
		USB_DOEPx_TSIZ(0) = usbd_dev->doeptsiz[0];
		USB_DOEPx_CTL(0) |=
		    USB_DOEP0CTL_EPENA | USB_DIEP0CTL_SNAK;

		USB_GNPTXFSIZ = ((max_size / 4) << 16) |
					 usbd_dev->driver->rx_fifo_size;
		usbd_dev->fifo_mem_top += max_size / 4;
		usbd_dev->fifo_mem_top_ep0 = usbd_dev->fifo_mem_top;

		return;
	}

	if (dir) {
		USB_DIEPTXF(addr) = ((max_size / 4) << 16) |
					     usbd_dev->fifo_mem_top;
		usbd_dev->fifo_mem_top += max_size / 4;

		USB_DIEPx_TSIZ(addr) =
		    (max_size & USB_DIEP0TSIZ_XFRSIZ_MASK);
		USB_DIEPx_CTL(addr) |=
		    USB_DIEP0CTL_EPENA | USB_DIEP0CTL_SNAK | (type << 18)
		    | USB_DIEP0CTL_USBAEP | USB_DIEP0CTL_SD0PID
		    | (addr << 22) | max_size;

		if (callback) {
			usbd_dev->user_callback_ctr[addr][USB_TRANSACTION_IN] =
			    (void *)callback;
		}
	}

	if (!dir) {
		usbd_dev->doeptsiz[addr] = USB_DIEP0TSIZ_PKTCNT |
				 (max_size & USB_DIEP0TSIZ_XFRSIZ_MASK);
		USB_DOEPx_TSIZ(addr) = usbd_dev->doeptsiz[addr];
		USB_DOEPx_CTL(addr) |= USB_DOEP0CTL_EPENA |
		    USB_DOEP0CTL_USBAEP | USB_DIEP0CTL_CNAK |
		    USB_DOEP0CTL_SD0PID | (type << 18) | max_size;

		if (callback) {
			usbd_dev->user_callback_ctr[addr][USB_TRANSACTION_OUT] =
			    (void *)callback;
		}
	}
}

static void efm32lg_endpoints_reset(usbd_device *usbd_dev)
{
	/* The core resets the endpoints automatically on reset. */
	usbd_dev->fifo_mem_top = usbd_dev->fifo_mem_top_ep0;
}

static void efm32lg_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
				 uint8_t stall)
{
	(void)usbd_dev;
	if (addr == 0) {
		if (stall) {
			USB_DIEPx_CTL(addr) |= USB_DIEP0CTL_STALL;
		} else {
			USB_DIEPx_CTL(addr) &= ~USB_DIEP0CTL_STALL;
		}
	}

	if (addr & 0x80) {
		addr &= 0x7F;

		if (stall) {
			USB_DIEPx_CTL(addr) |= USB_DIEP0CTL_STALL;
		} else {
			USB_DIEPx_CTL(addr) &= ~USB_DIEP0CTL_STALL;
			USB_DIEPx_CTL(addr) |= USB_DIEP0CTL_SD0PID;
		}
	} else {
		if (stall) {
			USB_DOEPx_CTL(addr) |= USB_DOEP0CTL_STALL;
		} else {
			USB_DOEPx_CTL(addr) &= ~USB_DOEP0CTL_STALL;
			USB_DOEPx_CTL(addr) |= USB_DOEP0CTL_SD0PID;
		}
	}
}

static uint8_t efm32lg_ep_stall_get(usbd_device *usbd_dev, uint8_t addr)
{
	(void)usbd_dev;

	/* Return non-zero if STALL set. */
	if (addr & 0x80) {
		return (USB_DIEPx_CTL(addr & 0x7f) &
				USB_DIEP0CTL_STALL) ? 1 : 0;
	} else {
		return (USB_DOEPx_CTL(addr) &
				USB_DOEP0CTL_STALL) ? 1 : 0;
	}
}

static void efm32lg_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak)
{
	/* It does not make sence to force NAK on IN endpoints. */
	if (addr & 0x80) {
		return;
	}

	usbd_dev->force_nak[addr] = nak;

	if (nak) {
		USB_DOEPx_CTL(addr) |= USB_DOEP0CTL_SNAK;
	} else {
		USB_DOEPx_CTL(addr) |= USB_DOEP0CTL_CNAK;
	}
}

static uint16_t efm32lg_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
			      const void *buf, uint16_t len)
{
	(void)usbd_dev;
	const uint32_t *buf32 = buf;
	int i;

	addr &= 0x7F;

	/* Return if endpoint is already enabled. */
	if (USB_DIEPx_TSIZ(addr) & USB_DIEP0TSIZ_PKTCNT) {
		return 0;
	}

	/* Enable endpoint for transmission. */
	USB_DIEPx_TSIZ(addr) = USB_DIEP0TSIZ_PKTCNT | len;
	USB_DIEPx_CTL(addr) |= USB_DIEP0CTL_EPENA |
				     USB_DIEP0CTL_CNAK;
	volatile uint32_t *fifo = USB_FIFOxD(addr);

	/* Copy buffer to endpoint FIFO, note - memcpy does not work */
	for (i = len; i > 0; i -= 4) {
		*fifo++ = *buf32++;
	}

	return len;
}

static uint16_t efm32lg_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
				  void *buf, uint16_t len)
{
	int i;
	uint32_t *buf32 = buf;
	uint32_t extra;

	len = MIN(len, usbd_dev->rxbcnt);
	usbd_dev->rxbcnt -= len;

	volatile uint32_t *fifo = USB_FIFOxD(addr);
	for (i = len; i >= 4; i -= 4) {
		*buf32++ = *fifo++;
	}

	if (i) {
		extra = *fifo++;
		memcpy(buf32, &extra, i);
	}

	USB_DOEPx_TSIZ(addr) = usbd_dev->doeptsiz[addr];
	USB_DOEPx_CTL(addr) |= USB_DOEP0CTL_EPENA |
	    (usbd_dev->force_nak[addr] ?
	     USB_DOEP0CTL_SNAK : USB_DOEP0CTL_CNAK);

	return len;
}

static void efm32lg_poll(usbd_device *usbd_dev)
{
	/* Read interrupt status register. */
	uint32_t intsts = USB_GINTSTS;
	int i;

	if (intsts & USB_GINTSTS_ENUMDNE) {
		/* Handle USB RESET condition. */
		USB_GINTSTS = USB_GINTSTS_ENUMDNE;
		usbd_dev->fifo_mem_top = usbd_dev->driver->rx_fifo_size;
		_usbd_reset(usbd_dev);
		return;
	}

	/* Note: RX and TX handled differently in this device. */
	if (intsts & USB_GINTSTS_RXFLVL) {
		/* Receive FIFO non-empty. */
		uint32_t rxstsp = USB_GRXSTSP;
		uint32_t pktsts = rxstsp & USB_GRXSTSP_PKTSTS_MASK;
		if ((pktsts != USB_GRXSTSP_PKTSTS_OUT) &&
		    (pktsts != USB_GRXSTSP_PKTSTS_SETUP)) {
			return;
		}

		uint8_t ep = rxstsp & USB_GRXSTSP_EPNUM_MASK;
		uint8_t type;
		if (pktsts == USB_GRXSTSP_PKTSTS_SETUP) {
			type = USB_TRANSACTION_SETUP;
		} else {
			type = USB_TRANSACTION_OUT;
		}

		/* Save packet size for stm32f107_ep_read_packet(). */
		usbd_dev->rxbcnt = (rxstsp & USB_GRXSTSP_BCNT_MASK) >> 4;

		/*
		 * FIXME: Why is a delay needed here?
		 * This appears to fix a problem where the first 4 bytes
		 * of the DATA OUT stage of a control transaction are lost.
		 */
		for (i = 0; i < 1000; i++) {
			__asm__("nop");
		}

		if (usbd_dev->user_callback_ctr[ep][type]) {
			usbd_dev->user_callback_ctr[ep][type] (usbd_dev, ep);
		}

		/* Discard unread packet data. */
		for (i = 0; i < usbd_dev->rxbcnt; i += 4) {
			(void)*USB_FIFOxD(ep);
		}

		usbd_dev->rxbcnt = 0;
	}

	/*
	 * There is no global interrupt flag for transmit complete.
	 * The XFRC bit must be checked in each USB_DIEPx_INT(x).
	 */
	for (i = 0; i < ENDPOINT_COUNT; i++) { /* Iterate over endpoints. */
		if (USB_DIEPx_INT(i) & USB_DIEP_INT_XFRC) {
			/* Transfer complete. */
			if (usbd_dev->user_callback_ctr[i]
						       [USB_TRANSACTION_IN]) {
				usbd_dev->user_callback_ctr[i]
					[USB_TRANSACTION_IN](usbd_dev, i);
			}

			USB_DIEPx_INT(i) = USB_DIEP_INT_XFRC;
		}
	}

	if (intsts & USB_GINTSTS_USBSUSP) {
		if (usbd_dev->user_callback_suspend) {
			usbd_dev->user_callback_suspend();
		}
		USB_GINTSTS = USB_GINTSTS_USBSUSP;
	}

	if (intsts & USB_GINTSTS_WKUPINT) {
		if (usbd_dev->user_callback_resume) {
			usbd_dev->user_callback_resume();
		}
		USB_GINTSTS = USB_GINTSTS_WKUPINT;
	}

	if (intsts & USB_GINTSTS_SOF) {
		if (usbd_dev->user_callback_sof) {
			usbd_dev->user_callback_sof();
		}
		USB_GINTSTS = USB_GINTSTS_SOF;
	}

	if (usbd_dev->user_callback_sof) {
		USB_GINTMSK |= USB_GINTMSK_SOFM;
	} else {
		USB_GINTMSK &= ~USB_GINTMSK_SOFM;
	}
}

static void efm32lg_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	(void)usbd_dev;

	if (disconnected) {
		USB_DCTL |= USB_DCTL_SDIS;
	} else {
		USB_DCTL &= ~USB_DCTL_SDIS;
	}
}

const struct _usbd_driver efm32lg_usb_driver = {
	.init = efm32lg_usbd_init,
	.set_address = efm32lg_set_address,
	.ep_setup = efm32lg_ep_setup,
	.ep_reset = efm32lg_endpoints_reset,
	.ep_stall_set = efm32lg_ep_stall_set,
	.ep_stall_get = efm32lg_ep_stall_get,
	.ep_nak_set = efm32lg_ep_nak_set,
	.ep_write_packet = efm32lg_ep_write_packet,
	.ep_read_packet = efm32lg_ep_read_packet,
	.poll = efm32lg_poll,
	.disconnect = efm32lg_disconnect,
	.base_address = USB_BASE,
	.set_address_before_status = 1,
	.rx_fifo_size = RX_FIFO_SIZE,
};
