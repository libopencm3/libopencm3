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
#include <libopencm3/stm32/otg_hs.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"
#include "usb_fx07_common.h"

/* The FS core and the HS core have the same register layout.
 * As the code can be used on both cores, the registers offset is modified
 * according to the selected cores base address. */
#define dev_base_address (usbd_dev->driver->base_address)
#define REBASE(x)        MMIO32((x) + (dev_base_address))
#define REBASE_FIFO(x)   (&MMIO32((dev_base_address) + (OTG_FIFO(x))))

void stm32fx07_set_address(usbd_device *usbd_dev, uint8_t addr)
{
	REBASE(OTG_DCFG) = (REBASE(OTG_DCFG) & ~OTG_FS_DCFG_DAD) | (addr << 4);
}

void stm32fx07_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
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
			REBASE(OTG_DIEPCTL0) = OTG_FS_DIEPCTL0_MPSIZ_64;
		} else if (max_size >= 32) {
			REBASE(OTG_DIEPCTL0) = OTG_FS_DIEPCTL0_MPSIZ_32;
		} else if (max_size >= 16) {
			REBASE(OTG_DIEPCTL0) = OTG_FS_DIEPCTL0_MPSIZ_16;
		} else {
			REBASE(OTG_DIEPCTL0) = OTG_FS_DIEPCTL0_MPSIZ_8;
		}

		REBASE(OTG_DIEPTSIZ0) =
			(max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DIEPCTL0) |=
			OTG_FS_DIEPCTL0_EPENA | OTG_FS_DIEPCTL0_SNAK;

		/* Configure OUT part. */
		usbd_dev->doeptsiz[0] = OTG_FS_DIEPSIZ0_STUPCNT_1 |
			OTG_FS_DIEPSIZ0_PKTCNT |
			(max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DOEPTSIZ(0)) = usbd_dev->doeptsiz[0];
		REBASE(OTG_DOEPCTL(0)) |=
		    OTG_FS_DOEPCTL0_EPENA | OTG_FS_DIEPCTL0_SNAK;

		REBASE(OTG_GNPTXFSIZ) = ((max_size / 4) << 16) |
					 usbd_dev->driver->rx_fifo_size;
		usbd_dev->fifo_mem_top += max_size / 4;
		usbd_dev->fifo_mem_top_ep0 = usbd_dev->fifo_mem_top;

		return;
	}

	if (dir) {
		REBASE(OTG_DIEPTXF(addr)) = ((max_size / 4) << 16) |
					     usbd_dev->fifo_mem_top;
		usbd_dev->fifo_mem_top += max_size / 4;

		REBASE(OTG_DIEPTSIZ(addr)) =
		    (max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DIEPCTL(addr)) |=
		    OTG_FS_DIEPCTL0_EPENA | OTG_FS_DIEPCTL0_SNAK | (type << 18)
		    | OTG_FS_DIEPCTL0_USBAEP | OTG_FS_DIEPCTLX_SD0PID
		    | (addr << 22) | max_size;

		if (callback) {
			usbd_dev->user_callback_ctr[addr][USB_TRANSACTION_IN] =
			    (void *)callback;
		}
	}

	if (!dir) {
		usbd_dev->doeptsiz[addr] = OTG_FS_DIEPSIZ0_PKTCNT |
				 (max_size & OTG_FS_DIEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DOEPTSIZ(addr)) = usbd_dev->doeptsiz[addr];
		REBASE(OTG_DOEPCTL(addr)) |= OTG_FS_DOEPCTL0_EPENA |
		    OTG_FS_DOEPCTL0_USBAEP | OTG_FS_DIEPCTL0_CNAK |
		    OTG_FS_DOEPCTLX_SD0PID | (type << 18) | max_size;

		if (callback) {
			usbd_dev->user_callback_ctr[addr][USB_TRANSACTION_OUT] =
			    (void *)callback;
		}
	}
}

void stm32fx07_endpoints_reset(usbd_device *usbd_dev)
{
	/* The core resets the endpoints automatically on reset. */
	usbd_dev->fifo_mem_top = usbd_dev->fifo_mem_top_ep0;
}

void stm32fx07_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall)
{
	if (addr == 0) {
		if (stall) {
			REBASE(OTG_DIEPCTL(addr)) |= OTG_FS_DIEPCTL0_STALL;
		} else {
			REBASE(OTG_DIEPCTL(addr)) &= ~OTG_FS_DIEPCTL0_STALL;
		}
	}

	if (addr & 0x80) {
		addr &= 0x7F;

		if (stall) {
			REBASE(OTG_DIEPCTL(addr)) |= OTG_FS_DIEPCTL0_STALL;
		} else {
			REBASE(OTG_DIEPCTL(addr)) &= ~OTG_FS_DIEPCTL0_STALL;
			REBASE(OTG_DIEPCTL(addr)) |= OTG_FS_DIEPCTLX_SD0PID;
		}
	} else {
		if (stall) {
			REBASE(OTG_DOEPCTL(addr)) |= OTG_FS_DOEPCTL0_STALL;
		} else {
			REBASE(OTG_DOEPCTL(addr)) &= ~OTG_FS_DOEPCTL0_STALL;
			REBASE(OTG_DOEPCTL(addr)) |= OTG_FS_DOEPCTLX_SD0PID;
		}
	}
}

uint8_t stm32fx07_ep_stall_get(usbd_device *usbd_dev, uint8_t addr)
{
	/* Return non-zero if STALL set. */
	if (addr & 0x80) {
		return (REBASE(OTG_DIEPCTL(addr & 0x7f)) &
				OTG_FS_DIEPCTL0_STALL) ? 1 : 0;
	} else {
		return (REBASE(OTG_DOEPCTL(addr)) &
				OTG_FS_DOEPCTL0_STALL) ? 1 : 0;
	}
}

void stm32fx07_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak)
{
	/* It does not make sence to force NAK on IN endpoints. */
	if (addr & 0x80) {
		return;
	}

	usbd_dev->force_nak[addr] = nak;

	if (nak) {
		REBASE(OTG_DOEPCTL(addr)) |= OTG_FS_DOEPCTL0_SNAK;
	} else {
		REBASE(OTG_DOEPCTL(addr)) |= OTG_FS_DOEPCTL0_CNAK;
	}
}

uint16_t stm32fx07_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
			      const void *buf, uint16_t len)
{
	const uint32_t *buf32 = buf;
	int i;

	addr &= 0x7F;

	/* Return if endpoint is already enabled. */
	if (REBASE(OTG_DIEPTSIZ(addr)) & OTG_FS_DIEPSIZ0_PKTCNT) {
		return 0;
	}

	/* Enable endpoint for transmission. */
	REBASE(OTG_DIEPTSIZ(addr)) = OTG_FS_DIEPSIZ0_PKTCNT | len;
	REBASE(OTG_DIEPCTL(addr)) |= OTG_FS_DIEPCTL0_EPENA |
				     OTG_FS_DIEPCTL0_CNAK;
	volatile uint32_t *fifo = REBASE_FIFO(addr);

	/* Copy buffer to endpoint FIFO, note - memcpy does not work */
	for (i = len; i > 0; i -= 4) {
		*fifo++ = *buf32++;
	}

	return len;
}

uint16_t stm32fx07_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
				  void *buf, uint16_t len)
{
	int i;
	uint32_t *buf32 = buf;
	uint32_t extra;

	len = MIN(len, usbd_dev->rxbcnt);
	usbd_dev->rxbcnt -= len;

	volatile uint32_t *fifo = REBASE_FIFO(addr);
	for (i = len; i >= 4; i -= 4) {
		*buf32++ = *fifo++;
	}

	if (i) {
		extra = *fifo++;
		memcpy(buf32, &extra, i);
	}

	REBASE(OTG_DOEPTSIZ(addr)) = usbd_dev->doeptsiz[addr];
	REBASE(OTG_DOEPCTL(addr)) |= OTG_FS_DOEPCTL0_EPENA |
	    (usbd_dev->force_nak[addr] ?
	     OTG_FS_DOEPCTL0_SNAK : OTG_FS_DOEPCTL0_CNAK);

	return len;
}

void stm32fx07_poll(usbd_device *usbd_dev)
{
	/* Read interrupt status register. */
	uint32_t intsts = REBASE(OTG_GINTSTS);
	int i;

	if (intsts & OTG_FS_GINTSTS_ENUMDNE) {
		/* Handle USB RESET condition. */
		REBASE(OTG_GINTSTS) = OTG_FS_GINTSTS_ENUMDNE;
		usbd_dev->fifo_mem_top = usbd_dev->driver->rx_fifo_size;
		_usbd_reset(usbd_dev);
		return;
	}

	/* Note: RX and TX handled differently in this device. */
	if (intsts & OTG_FS_GINTSTS_RXFLVL) {
		/* Receive FIFO non-empty. */
		uint32_t rxstsp = REBASE(OTG_GRXSTSP);
		uint32_t pktsts = rxstsp & OTG_FS_GRXSTSP_PKTSTS_MASK;
		if ((pktsts != OTG_FS_GRXSTSP_PKTSTS_OUT) &&
		    (pktsts != OTG_FS_GRXSTSP_PKTSTS_SETUP)) {
			return;
		}

		uint8_t ep = rxstsp & OTG_FS_GRXSTSP_EPNUM_MASK;
		uint8_t type;
		if (pktsts == OTG_FS_GRXSTSP_PKTSTS_SETUP) {
			type = USB_TRANSACTION_SETUP;
		} else {
			type = USB_TRANSACTION_OUT;
		}

		/* Save packet size for stm32f107_ep_read_packet(). */
		usbd_dev->rxbcnt = (rxstsp & OTG_FS_GRXSTSP_BCNT_MASK) >> 4;

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
			(void)*REBASE_FIFO(ep);
		}

		usbd_dev->rxbcnt = 0;
	}

	/*
	 * There is no global interrupt flag for transmit complete.
	 * The XFRC bit must be checked in each OTG_FS_DIEPINT(x).
	 */
	for (i = 0; i < 4; i++) { /* Iterate over endpoints. */
		if (REBASE(OTG_DIEPINT(i)) & OTG_FS_DIEPINTX_XFRC) {
			/* Transfer complete. */
			if (usbd_dev->user_callback_ctr[i]
						       [USB_TRANSACTION_IN]) {
				usbd_dev->user_callback_ctr[i]
					[USB_TRANSACTION_IN](usbd_dev, i);
			}

			REBASE(OTG_DIEPINT(i)) = OTG_FS_DIEPINTX_XFRC;
		}
	}

	if (intsts & OTG_FS_GINTSTS_USBSUSP) {
		if (usbd_dev->user_callback_suspend) {
			usbd_dev->user_callback_suspend();
		}
		REBASE(OTG_GINTSTS) = OTG_FS_GINTSTS_USBSUSP;
	}

	if (intsts & OTG_FS_GINTSTS_WKUPINT) {
		if (usbd_dev->user_callback_resume) {
			usbd_dev->user_callback_resume();
		}
		REBASE(OTG_GINTSTS) = OTG_FS_GINTSTS_WKUPINT;
	}

	if (intsts & OTG_FS_GINTSTS_SOF) {
		if (usbd_dev->user_callback_sof) {
			usbd_dev->user_callback_sof();
		}
		REBASE(OTG_GINTSTS) = OTG_FS_GINTSTS_SOF;
	}
}

void stm32fx07_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	if (disconnected) {
		REBASE(OTG_DCTL) |= OTG_FS_DCTL_SDIS;
	} else {
		REBASE(OTG_DCTL) &= ~OTG_FS_DCTL_SDIS;
	}
}
