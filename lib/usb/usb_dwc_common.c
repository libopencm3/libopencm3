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
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/bos.h>
#include <libopencm3/usb/dwc/otg_common.h>
#include "usb_private.h"
#include "usb_dwc_common.h"

/* The FS core and the HS core have the same register layout.
 * As the code can be used on both cores, the registers offset is modified
 * according to the selected cores base address. */
#define dev_base_address (usbd_dev->driver->base_address)
#define REBASE(x)        MMIO32((x) + (dev_base_address))

void dwc_set_address(usbd_device *usbd_dev, uint8_t addr)
{
	REBASE(OTG_DCFG) = (REBASE(OTG_DCFG) & ~OTG_DCFG_DAD) | (addr << 4U);
}

void dwc_ep_setup(usbd_device *const usbd_dev, const uint8_t addr, const uint8_t type, const uint16_t max_size,
	void (*callback)(usbd_device *usbd_dev, uint8_t ep))
{
	/*
	 * Configure endpoint address and type. Allocate FIFO memory for
	 * endpoint. Install callback function.
	 */
	const uint8_t ep = addr & 0x7fU;

	if (ep == 0) { /* For the default control endpoint */
				   /* Configure IN part. */
#if defined(STM32H7)
		/* Do not initially arm the IN endpoint - we've got nothing to send the host at first */
		REBASE(OTG_DIEPTSIZ(0)) = 0;
		REBASE(OTG_DIEPCTL(0)) = (max_size & OTG_DIEPCTLX_MPSIZ_MASK) | OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP;
#else
		if (max_size >= 64) {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_64;
		} else if (max_size >= 32) {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_32;
		} else if (max_size >= 16) {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_16;
		} else {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_8;
		}

		REBASE(OTG_DIEPTSIZ0) = (max_size & OTG_DIEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DIEPCTL0) |= OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP;
#endif

		/* Configure OUT part. */
		usbd_dev->doeptsiz[0] = OTG_DOEPSIZ0_STUPCNT_1 | OTG_DOEPSIZ0_PKTCNT | (max_size & OTG_DOEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DOEPTSIZ(0)) = usbd_dev->doeptsiz[0];
#if defined(STM32H7)
		/* However, *do* arm the OUT endpoint so we can receive the first SETUP packet */
		if (max_size >= 64) {
			REBASE(OTG_DOEPCTL(0)) = OTG_DOEPCTL0_MPSIZ_64;
		} else if (max_size >= 32) {
			REBASE(OTG_DOEPCTL(0)) = OTG_DOEPCTL0_MPSIZ_32;
		} else if (max_size >= 16) {
			REBASE(OTG_DOEPCTL(0)) = OTG_DOEPCTL0_MPSIZ_16;
		} else {
			REBASE(OTG_DOEPCTL(0)) = OTG_DOEPCTL0_MPSIZ_8;
		}
		REBASE(OTG_DOEPCTL(0)) |= OTG_DOEPCTL0_EPENA | OTG_DOEPCTL0_CNAK | OTG_DOEPCTL0_USBAEP;
#else
		REBASE(OTG_DOEPCTL0) |= OTG_DOEPCTL0_EPENA | OTG_DIEPCTL0_SNAK;
#endif

		REBASE(OTG_GNPTXFSIZ) = ((max_size / 4) << 16) | usbd_dev->driver->rx_fifo_size;
		usbd_dev->fifo_mem_top += max_size / 4;
		usbd_dev->fifo_mem_top_ep0 = usbd_dev->fifo_mem_top;

		return;
	}

	if (addr & 0x80U) {
		/* Configure an IN endpoint */
		REBASE(OTG_DIEPTXF(ep)) = ((max_size / 4) << 16) | usbd_dev->fifo_mem_top;
		usbd_dev->fifo_mem_top += max_size / 4;

#if defined(STM32H7)
		/* Do not initially arm the IN endpoint - we've got nothing to send the host at first */
		REBASE(OTG_DIEPTSIZ(ep)) = 0U;
		REBASE(OTG_DIEPCTL(ep)) = (max_size & OTG_DIEPCTLX_MPSIZ_MASK) | OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP |
			(type << OTG_DIEPCTLX_EPTYP_SHIFT) | OTG_DIEPCTLX_SD0PID | (ep << OTG_DIEPCTLX_TXFNUM_SHIFT);
#else
		REBASE(OTG_DIEPTSIZ(ep)) = max_size & OTG_DIEPSIZ0_XFRSIZ_MASK;
		REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_SNAK | (type << OTG_DIEPCTLX_EPTYP_SHIFT) |
			OTG_DIEPCTL0_USBAEP | OTG_DIEPCTLX_SD0PID | (ep << OTG_DIEPCTLX_TXFNUM_SHIFT) |
			(max_size & OTG_DIEPCTLX_MPSIZ_MASK);
#endif

		if (callback) {
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN] = (void *)callback;
		}
	} else {
		/* Configure an OUT endpoint */
		usbd_dev->doeptsiz[ep] = OTG_DOEPSIZX_PKTCNT(1U) | (max_size & OTG_DOEPSIZX_XFRSIZ_MASK);
		REBASE(OTG_DOEPTSIZ(ep)) = usbd_dev->doeptsiz[ep];
		/* Make sure to arm the endpoint as part of enabling it so we can get the first data from it */
		REBASE(OTG_DOEPCTL(ep)) = OTG_DOEPCTL0_EPENA | OTG_DIEPCTL0_CNAK | OTG_DOEPCTL0_USBAEP | OTG_DOEPCTLX_SD0PID |
			(type << OTG_DIEPCTLX_EPTYP_SHIFT) | (max_size & OTG_DOEPCTLX_MPSIZ_MASK);

		if (callback) {
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_OUT] = (void *)callback;
		}
	}
}

void dwc_endpoints_reset(usbd_device *usbd_dev)
{
	/* The core resets the endpoints automatically on reset. */
	usbd_dev->fifo_mem_top = usbd_dev->fifo_mem_top_ep0;

	/* Disable any currently active endpoints */
	for (size_t i = 1; i < ENDPOINT_COUNT; i++) {
		if (REBASE(OTG_DOEPCTL(i)) & OTG_DOEPCTL0_EPENA) {
			REBASE(OTG_DOEPCTL(i)) |= OTG_DOEPCTL0_EPDIS;
		}
		if (REBASE(OTG_DIEPCTL(i)) & OTG_DIEPCTL0_EPENA) {
			REBASE(OTG_DIEPCTL(i)) |= OTG_DIEPCTL0_EPDIS;
		}
	}

	/* Flush all tx/rx fifos */
	REBASE(OTG_GRSTCTL) = OTG_GRSTCTL_TXFFLSH | OTG_GRSTCTL_TXFNUM_ALL | OTG_GRSTCTL_RXFFLSH;
}

void dwc_ep_stall_set(usbd_device *const usbd_dev, const uint8_t addr, const uint8_t stall)
{
	const uint8_t ep = addr & 0x7FU;
	if (ep == 0) {
		if (stall) {
			REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_STALL;
		} else {
			REBASE(OTG_DIEPCTL(ep)) &= ~OTG_DIEPCTL0_STALL;
		}
	}

	if (addr & 0x80U) {
		if (stall) {
			REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_STALL;
		} else {
			REBASE(OTG_DIEPCTL(ep)) &= ~OTG_DIEPCTL0_STALL;
			REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTLX_SD0PID;
		}
	} else {
		if (stall) {
			REBASE(OTG_DOEPCTL(ep)) |= OTG_DOEPCTL0_STALL;
		} else {
			REBASE(OTG_DOEPCTL(ep)) &= ~OTG_DOEPCTL0_STALL;
			REBASE(OTG_DOEPCTL(ep)) |= OTG_DOEPCTLX_SD0PID;
		}
	}
}

uint8_t dwc_ep_stall_get(usbd_device *const usbd_dev, const uint8_t addr)
{
	const uint8_t ep = addr & 0x7FU;
	/* Return non-zero if STALL set. */
	if (addr & 0x80U) {
		return (REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_STALL) ? 1U : 0U;
	} else {
		return (REBASE(OTG_DOEPCTL(ep)) & OTG_DOEPCTL0_STALL) ? 1U : 0U;
	}
}

void dwc_ep_nak_set(usbd_device *const usbd_dev, const uint8_t addr, const uint8_t nak)
{
	/* It does not make sense to force NAK on IN endpoints. */
	if (addr & 0x80U) {
		return;
	}

	usbd_dev->force_nak[addr] = nak;

	if (nak) {
		REBASE(OTG_DOEPCTL(addr)) |= OTG_DOEPCTL0_SNAK;
	} else {
		REBASE(OTG_DOEPCTL(addr)) |= OTG_DOEPCTL0_CNAK;
	}
}

uint16_t dwc_ep_write_packet(usbd_device *const usbd_dev, const uint8_t addr, const void *buf, const uint16_t len)
{
	const uint8_t ep = addr & 0x7FU;

	/* Return if endpoint is already enabled. */
#if defined(STM32H7)
	if (REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_EPENA) {
		return 0;
	}

	/* Enable endpoint for transmission. */
	if (ep == 0U) {
		REBASE(OTG_DIEPTSIZ(ep)) = OTG_DIEPSIZ0_PKTCNT | (len & OTG_DIEPSIZ0_XFRSIZ_MASK);
	} else {
		REBASE(OTG_DIEPTSIZ(ep)) = OTG_DIEPSIZX_PKTCNT(1) | (len & OTG_DIEPSIZX_XFRSIZ_MASK);
	}
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_EPENA | OTG_DIEPCTL0_CNAK;

	const uint8_t *const buf8 = buf;
	/* Figure out where to copy the data to */
	volatile uint32_t *const fifo = (volatile uint32_t *)(usbd_dev->driver->base_address + OTG_FIFO(ep));
	/* Copy the data into the FIFO for this endpoint */
	for (size_t offset = 0; offset < len; offset += 4) {
		uint32_t data = 0;
		const size_t amount = MIN(len - offset, 4U);
		memcpy(&data, buf8 + offset, amount);
		fifo[offset >> 2U] = data;
	}
#else
	if (REBASE(OTG_DIEPTSIZ(ep)) & OTG_DIEPSIZ0_PKTCNT) {
		return 0;
	}

	/* Enable endpoint for transmission. */
	REBASE(OTG_DIEPTSIZ(ep)) = OTG_DIEPSIZ0_PKTCNT | (len & OTG_DIEPSIZ0_XFRSIZ_MASK);
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_EPENA | OTG_DIEPCTL0_CNAK;

	const uint32_t *buf32 = buf;
	/* Copy buffer to endpoint FIFO, note - memcpy does not work.
	 * ARMv7M supports non-word-aligned accesses, ARMv6M does not. */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__)
	for (size_t i = 0; i < len; i += 4) {
		REBASE(OTG_FIFO(ep)) = *buf32++;
	}
#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

#if defined(__ARM_ARCH_6M__)
	const uint8_t *buf8 = buf;
	/* Take care of word-aligned and non-word-aligned buffers */
	if (((uintptr_t)buf8 & 0x3) == 0) {
		for (size_t i = 0; i < len; i += 4) {
			REBASE(OTG_FIFO(ep)) = *buf32++;
		}
	} else {
		for (size_t i = 0; i < len; i += 4) {
			uint32_t word32;
			memcpy(&word32, buf8 + i, 4);
			REBASE(OTG_FIFO(ep)) = word32;
		}
	}
#endif /* defined(__ARM_ARCH_6M__) */
#endif

	return len;
}

uint16_t dwc_ep_read_packet(usbd_device *usbd_dev, uint8_t addr, void *buf, uint16_t len)
{
	/* We do not need to know the endpoint address since there is only one
	 * receive FIFO for all endpoints.
	 */
	(void)addr;
#if defined(STM32H7)
	const size_t count = MIN(len, usbd_dev->rxbcnt);

	uint8_t *const buf8 = buf;
	/* Figure out where to copy the data from */
	const volatile uint32_t *const fifo = (const volatile uint32_t *)(usbd_dev->driver->base_address + OTG_FIFO(0));
	/* Copy the data out of the FIFO for this endpoint */
	for (size_t offset = 0; offset < count; offset += 4) {
		const uint32_t data = fifo[offset >> 2U];
		const size_t amount = MIN(count - offset, 4U);
		memcpy(buf8 + offset, &data, amount);
	}

	usbd_dev->rxbcnt -= count;
	return count;
#else
	len = MIN(len, usbd_dev->rxbcnt);

	int i = 0;
	uint32_t *buf32 = buf;
	/* ARMv7M supports non-word-aligned accesses, ARMv6M does not. */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__)
	for (i = len; i >= 4; i -= 4) {
		*buf32++ = REBASE(OTG_FIFO(0));
		usbd_dev->rxbcnt -= 4;
	}
#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

#if defined(__ARM_ARCH_6M__)
	uint8_t *buf8 = buf;
	/* Take care of word-aligned and non-word-aligned buffers */
	if (((uint32_t)buf8 & 0x3) == 0) {
		for (i = len; i >= 4; i -= 4) {
			*buf32++ = REBASE(OTG_FIFO(0));
			usbd_dev->rxbcnt -= 4;
		}
	} else {
		for (i = len; i >= 4; i -= 4) {
			const uint32_t word32 = REBASE(OTG_FIFO(0));
			memcpy(buf8, &word32, 4);
			usbd_dev->rxbcnt -= 4;
			buf8 += 4;
		}
		/* buf32 needs to be updated as it is used for extra */
		buf32 = (uint32_t *)buf8;
	}
#endif /* defined(__ARM_ARCH_6M__) */

	if (i) {
		const uint32_t extra = REBASE(OTG_FIFO(0));
		/* we read 4 bytes from the fifo, so update rxbcnt */
		if (usbd_dev->rxbcnt < 4) {
			/* Be careful not to underflow (rxbcnt is unsigned) */
			usbd_dev->rxbcnt = 0;
		} else {
			usbd_dev->rxbcnt -= 4;
		}
		memcpy(buf32, &extra, i);
	}

	return len;
#endif
}

static void dwc_flush_txfifo(usbd_device *usbd_dev, int ep)
{
	uint32_t fifo;
	/* set IN endpoint NAK */
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_SNAK;
	/* wait for core to respond */
	while (!(REBASE(OTG_DIEPINT(ep)) & OTG_DIEPINTX_INEPNE)) {
		/* idle */
	}
	/* get fifo for this endpoint */
	fifo = (REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_TXFNUM_MASK) >> 22;
	/* wait for core to idle */
	while (!(REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_AHBIDL)) {
		/* idle */
	}
	/* flush tx fifo */
	REBASE(OTG_GRSTCTL) = (fifo << 6) | OTG_GRSTCTL_TXFFLSH;
	/* reset packet counter */
	REBASE(OTG_DIEPTSIZ(ep)) = 0;
	while ((REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_TXFFLSH)) {
		/* idle */
	}
}

void dwc_poll(usbd_device *usbd_dev)
{
	/* Read interrupt status register. */
	uint32_t intsts = REBASE(OTG_GINTSTS);

	if (intsts & OTG_GINTSTS_ENUMDNE) {
		/* Handle USB RESET condition. */
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_ENUMDNE;
		usbd_dev->fifo_mem_top = usbd_dev->driver->rx_fifo_size;
		_usbd_reset(usbd_dev);
		return;
	}
	if (intsts & OTG_GINTSTS_USBRST) {
		/* Handle the /other/ USB Reset condition */
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_USBRST | OTG_GINTSTS_RSTDET;
		dwc_endpoints_reset(usbd_dev);
		return;
	}

	/*
	 * There is not always a global interrupt flag for transmit complete.
	 * The XFRC bit must be checked in each OTG_DIEPINT(x).
	 *
	 * Iterate over the IN endpoints, triggering any post-transmit actions.
	 */
#if defined(STM32H7)
	if (intsts & OTG_GINTSTS_IEPINT) {
#endif
		for (size_t i = 0; i < ENDPOINT_COUNT; i++) {
			if (REBASE(OTG_DIEPINT(i)) & OTG_DIEPINTX_XFRC) {
				/* Transfer complete. */
				REBASE(OTG_DIEPINT(i)) = OTG_DIEPINTX_XFRC;

				if (usbd_dev->user_callback_ctr[i][USB_TRANSACTION_IN]) {
					usbd_dev->user_callback_ctr[i][USB_TRANSACTION_IN](usbd_dev, i);
				}
			}
		}
#if defined(STM32H7)
	}
#endif

	/* Note: RX and TX handled differently in this device. */
	if (intsts & OTG_GINTSTS_RXFLVL) {
		/* Receive FIFO non-empty. */
		const uint32_t rxstsp = REBASE(OTG_GRXSTSP);
		const uint32_t pktsts = rxstsp & OTG_GRXSTSP_PKTSTS_MASK;
		const uint8_t ep = rxstsp & OTG_GRXSTSP_EPNUM_MASK;

		if (pktsts == OTG_GRXSTSP_PKTSTS_SETUP_COMP) {
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_SETUP](usbd_dev, ep);
		}

		if (pktsts == OTG_GRXSTSP_PKTSTS_OUT_COMP || pktsts == OTG_GRXSTSP_PKTSTS_SETUP_COMP) {
#if defined(STM32H7) || defined(STM32U5)
			if (pktsts == OTG_GRXSTSP_PKTSTS_SETUP_COMP) {
				REBASE(OTG_DOEPINT(ep)) = OTG_DOEPINTX_STUP;
			}
#endif
			REBASE(OTG_DOEPTSIZ(ep)) = usbd_dev->doeptsiz[ep];
			REBASE(OTG_DOEPCTL(ep)) |=
				OTG_DOEPCTL0_EPENA | (usbd_dev->force_nak[ep] ? OTG_DOEPCTL0_SNAK : OTG_DOEPCTL0_CNAK);
			return;
		}

		if (pktsts != OTG_GRXSTSP_PKTSTS_OUT && pktsts != OTG_GRXSTSP_PKTSTS_SETUP) {
			return;
		}

		const uint8_t type = pktsts == OTG_GRXSTSP_PKTSTS_SETUP ? USB_TRANSACTION_SETUP : USB_TRANSACTION_OUT;

		if (type == USB_TRANSACTION_SETUP && (REBASE(OTG_DIEPTSIZ(ep)) & OTG_DIEPSIZ0_PKTCNT)) {
			/* SETUP received but there is still something stuck
			* in the transmit fifo.  Flush it.
			*/
			dwc_flush_txfifo(usbd_dev, ep);
		}

		/* Save packet size for dwc_ep_read_packet(). */
		usbd_dev->rxbcnt = (rxstsp & OTG_GRXSTSP_BCNT_MASK) >> 4U;

		if (type == USB_TRANSACTION_SETUP) {
			dwc_ep_read_packet(usbd_dev, ep, &usbd_dev->control_state.req, 8U);
		} else if (usbd_dev->user_callback_ctr[ep][type]) {
			usbd_dev->user_callback_ctr[ep][type](usbd_dev, ep);
		}

		/* Discard unread packet data. */
#if defined(STM32H7)
		const size_t total_length = (rxstsp & OTG_GRXSTSP_BCNT_MASK) >> 4U;
		const size_t consumed = total_length - usbd_dev->rxbcnt;
		const volatile uint32_t *const fifo = (const volatile uint32_t *)(usbd_dev->driver->base_address + OTG_FIFO(0));
		for (size_t offset = consumed; offset < total_length; offset += 4) {
			(void)fifo[offset >> 2U];
		}

		REBASE(OTG_DOEPINT(ep)) = OTG_DOEPINTX_XFRC;
#else
		for (size_t i = 0; i < usbd_dev->rxbcnt; i += 4) {
			/* There is only one receive FIFO, so use OTG_FIFO(0) */
			(void)REBASE(OTG_FIFO(0));
		}
#endif

		usbd_dev->rxbcnt = 0;
	}

	if (intsts & OTG_GINTSTS_USBSUSP) {
		if (usbd_dev->user_callback_suspend) {
			usbd_dev->user_callback_suspend();
		}
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_USBSUSP;
	}

	if (intsts & OTG_GINTSTS_WKUPINT) {
		if (usbd_dev->user_callback_resume) {
			usbd_dev->user_callback_resume();
		}
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_WKUPINT;
	}

	if (intsts & OTG_GINTSTS_SOF) {
		if (usbd_dev->user_callback_sof) {
			usbd_dev->user_callback_sof();
		}
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_SOF;
	}

#if !defined(STM32H7)
	if (usbd_dev->user_callback_sof) {
		REBASE(OTG_GINTMSK) |= OTG_GINTMSK_SOFM;
	} else {
		REBASE(OTG_GINTMSK) &= ~OTG_GINTMSK_SOFM;
	}
#endif
}

void dwc_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	if (disconnected) {
		REBASE(OTG_DCTL) |= OTG_DCTL_SDIS;
	} else {
		REBASE(OTG_DCTL) &= ~OTG_DCTL_SDIS;
	}
}
