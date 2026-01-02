/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2024-2025 Rachel Mant <git@dragonmux.network>
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

void dwc_set_address(usbd_device *const usbd_dev, const uint8_t address)
{
	REBASE(OTG_DCFG) = (REBASE(OTG_DCFG) & ~OTG_DCFG_DAD) | ((address << 4U) & OTG_DCFG_DAD);
}

void dwc_ep_setup(usbd_device *const usbd_dev, const uint8_t addr, const uint8_t type, const uint16_t max_size,
	void (*callback)(usbd_device *usbd_dev, uint8_t ep))
{
	/*
	 * Configure endpoint address and type. Allocate FIFO memory for
	 * endpoint. Install callback function.
	 */
	const uint8_t ep = addr & 0x7fU;

	if (ep == 0U) { /* For the default control endpoint */
					/* Configure IN part. */
#if defined(STM32H7)
		/* Do not initially arm the IN endpoint - we've got nothing to send the host at first */
		REBASE(OTG_DIEPTSIZ(0)) = 0U;
		REBASE(OTG_DIEPCTL(0)) = (max_size & OTG_DIEPCTLX_MPSIZ_MASK) | OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP;
#else
		if (max_size >= 64U) {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_64;
		} else if (max_size >= 32U) {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_32;
		} else if (max_size >= 16U) {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_16;
		} else {
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_8;
		}

#if defined(STM32U5)
		REBASE(OTG_DIEPTSIZ(0)) = 0U;
#else
		REBASE(OTG_DIEPTSIZ0) = (max_size & OTG_DIEPSIZ0_XFRSIZ_MASK);
#endif
		REBASE(OTG_DIEPCTL0) |= OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP;
		if (REBASE(OTG_DIEPCTL0) & OTG_DIEPCTL0_EPENA)
			REBASE(OTG_DIEPCTL0) |= OTG_DIEPCTL0_EPDIS;
#endif

		/* Configure OUT part. */
		usbd_dev->doeptsiz[0U] = OTG_DOEPSIZ0_STUPCNT_1 | OTG_DOEPSIZ0_PKTCNT | (max_size & OTG_DOEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DOEPTSIZ(0U)) = usbd_dev->doeptsiz[0U];
#if defined(STM32H7)
		/* However, *do* arm the OUT endpoint so we can receive the first SETUP packet */
		if (max_size >= 64) {
			REBASE(OTG_DOEPCTL(0U)) = OTG_DOEPCTL0_MPSIZ_64;
		} else if (max_size >= 32) {
			REBASE(OTG_DOEPCTL(0U)) = OTG_DOEPCTL0_MPSIZ_32;
		} else if (max_size >= 16) {
			REBASE(OTG_DOEPCTL(0U)) = OTG_DOEPCTL0_MPSIZ_16;
		} else {
			REBASE(OTG_DOEPCTL(0U)) = OTG_DOEPCTL0_MPSIZ_8;
		}
		REBASE(OTG_DOEPCTL(0U)) |= OTG_DOEPCTL0_EPENA | OTG_DOEPCTL0_CNAK | OTG_DOEPCTL0_USBAEP;
#elif defined(STM32U5)
		REBASE(OTG_DOEPCTL(0U)) = OTG_DOEPCTL0_EPENA | OTG_DOEPCTL0_CNAK;
#else
		REBASE(OTG_DOEPCTL0) |= OTG_DOEPCTL0_EPENA | OTG_DIEPCTL0_SNAK;
#endif

		REBASE(OTG_GNPTXFSIZ) = ((max_size / 4U) << 16U) | usbd_dev->driver->rx_fifo_size;
		usbd_dev->fifo_mem_top += max_size / 4U;
		usbd_dev->fifo_mem_top_ep0 = usbd_dev->fifo_mem_top;

		return;
	}

	if (addr & 0x80U) {
		/* Configure an IN endpoint */
		REBASE(OTG_DIEPTXF(ep)) = ((max_size / 4) << 16) | usbd_dev->fifo_mem_top;
		usbd_dev->fifo_mem_top += max_size / 4;

#if defined(STM32H7) || defined(STM32U5)
		/* Do not initially arm the IN endpoint - we've got nothing to send the host at first */
		REBASE(OTG_DIEPTSIZ(ep)) = 0U;
		REBASE(OTG_DIEPCTL(ep)) = (max_size & OTG_DIEPCTLX_MPSIZ_MASK) | OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP |
			(type << OTG_DIEPCTLX_EPTYP_SHIFT) | OTG_DIEPCTLX_SD0PID | (ep << OTG_DIEPCTLX_TXFNUM_SHIFT);
#else
		REBASE(OTG_DIEPTSIZ(ep)) = max_size & OTG_DIEPSIZ0_XFRSIZ_MASK;
		REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_SNAK | (type << OTG_DIEPCTLX_EPTYP_SHIFT) | OTG_DIEPCTL0_USBAEP |
			OTG_DIEPCTLX_SD0PID | (ep << OTG_DIEPCTLX_TXFNUM_SHIFT) | (max_size & OTG_DIEPCTLX_MPSIZ_MASK);
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

void dwc_endpoints_reset(usbd_device *const usbd_dev)
{
	/* Start by resetting our FIFO setup state */
	usbd_dev->fifo_mem_top = usbd_dev->fifo_mem_top_ep0;

	/*
	 * Now loop through all endpoints and make sure we're NAK'ing and they're properly disabled
	 *
	 * NB: We ignore EP0 here because that's handled by the EP setup call _usbd_reset() performs.
	 */
	for (size_t i = 1U; i < ENDPOINT_COUNT; i++) {
		if (REBASE(OTG_DOEPCTL(i)) & OTG_DOEPCTL0_EPENA) {
			REBASE(OTG_DOEPCTL(i)) |= OTG_DOEPCTL0_SNAK | OTG_DOEPCTL0_EPDIS;
		}
		if (REBASE(OTG_DIEPCTL(i)) & OTG_DIEPCTL0_EPENA) {
			REBASE(OTG_DIEPCTL(i)) |= OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_EPDIS;
		}
	}

	/* Make sure all FIFOs are fully flushed */
	REBASE(OTG_GRSTCTL) = OTG_GRSTCTL_TXFNUM_ALL | OTG_GRSTCTL_TXFFLSH | OTG_GRSTCTL_RXFFLSH;
	/* Wait for that to complete */
	while ((REBASE(OTG_GRSTCTL) & (OTG_GRSTCTL_TXFFLSH | OTG_GRSTCTL_RXFFLSH)) != 0U) {
	}
	/* Reset the GRSTCTL register state */
	REBASE(OTG_GRSTCTL) &= ~OTG_GRSTCTL_TXFNUM_MASK;

	/* Reset the endpoint disabled interrupt state for all endpoints */
	for (size_t i = 1U; i < ENDPOINT_COUNT; i++) {
		REBASE(OTG_DOEPINT(i)) = OTG_DOEPINTX_EPDISD;
		REBASE(OTG_DIEPINT(i)) = OTG_DIEPINTX_EPDISD;
	}
}

void dwc_ep_stall_set(usbd_device *const usbd_dev, const uint8_t endpoint_address, const uint8_t stall)
{
	/* Decode which endpoint this request is for exactly */
	const uint8_t ep = endpoint_address & 0x7fU;
	const uint8_t dir = endpoint_address & 0x80U;
	/* If the stall is for EP0, special-case to handle this correctly */
	if (ep == 0U) {
		/* Set/clear STALL on the IN side to properly communicate the condition back to the host */
		if (stall) {
			REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_STALL;
		} else {
			REBASE(OTG_DIEPCTL(ep)) &= ~OTG_DIEPCTL0_STALL;
		}
	} else {
		/* Figure out which direction to set STALL for */
		if (dir == 0U) {
			/* Set/clear STALL on OUT endpoint */
			if (stall) {
				REBASE(OTG_DOEPCTL(ep)) |= OTG_DOEPCTL0_STALL;
			} else {
				REBASE(OTG_DOEPCTL(ep)) &= ~OTG_DOEPCTL0_STALL;
			}
			/* Reset DATA PID to use */
			REBASE(OTG_DOEPCTL(ep)) |= OTG_DOEPCTLX_SD0PID;
		} else {
			/* Set/clear STALL on IN endpoint */
			if (stall) {
				REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_STALL;
			} else {
				REBASE(OTG_DIEPCTL(ep)) &= ~OTG_DIEPCTL0_STALL;
			}
			/* Reset DATA PID to use */
			REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTLX_SD0PID;
		}
	}
}

uint8_t dwc_ep_stall_get(usbd_device *const usbd_dev, const uint8_t endpoint_address)
{
	/* Decode which endpoint this request is for exactly */
	const uint8_t ep = endpoint_address & 0x7fU;
	const uint8_t dir = endpoint_address & 0x80U;
	/* Handle OUT endpoints */
	if (dir == 0U) {
		return (REBASE(OTG_DOEPCTL(ep)) & OTG_DOEPCTL0_STALL) ? true : false;
	}
	/* Handle IN endpoints */
	return (REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_STALL) ? true : false;
}

void dwc_ep_nak_set(usbd_device *const usbd_dev, const uint8_t endpoint_address, const uint8_t nak)
{
	/* Decode which endpoint this request is for exactly */
	const uint8_t ep = endpoint_address & 0x7fU;
	const uint8_t dir = endpoint_address & 0x80U;
	/* Handle NAK's only on OUT endpoints */
	if (dir != 0U) {
		return;
	}
	/*
	 * Copy the required NAK state into the device state storage and then set
	 * the NAK bit for this endpoint accordingly via SNAK/CNAK
	 */
	usbd_dev->force_nak[ep] = nak;
	if (nak) {
		REBASE(OTG_DOEPCTL(ep)) |= OTG_DOEPCTL0_SNAK;
	} else {
		REBASE(OTG_DOEPCTL(ep)) |= OTG_DOEPCTL0_CNAK;
	}
}

uint16_t dwc_ep_write_packet(usbd_device *const usbd_dev, const uint8_t addr, const void *buf, const uint16_t len)
{
	const uint8_t ep = addr & 0x7FU;

#if defined(STM32H7) || defined(STM32U5)
	/* Return if endpoint is already enabled. */
	if (REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_EPENA) {
		return 0U;
	}

	/* Enable endpoint for transmission. */
	if (ep == 0U) {
		REBASE(OTG_DIEPTSIZ0) = OTG_DIEPSIZ0_PKTCNT | (len & OTG_DIEPSIZ0_XFRSIZ_MASK);
	} else {
		REBASE(OTG_DIEPTSIZ(ep)) = OTG_DIEPSIZX_MCNT_1 | OTG_DIEPSIZX_PKTCNT(1) | (len & OTG_DIEPSIZX_XFRSIZ_MASK);
	}
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_EPENA | OTG_DIEPCTL0_CNAK;

	const uint32_t *const buf32 = buf;
#if defined(STM32H7)
	/* Figure out where to copy the data to */
	volatile uint32_t *const fifo = (volatile uint32_t *)(usbd_dev->driver->base_address + OTG_FIFO(ep));
#endif
	const uint16_t aligned_len = len & ~3U;
	/* Copy the data into the FIFO for this endpoint 32 bits at a time */
	for (size_t offset = 0U; offset < aligned_len; offset += 4U) {
#if defined(STM32H7)
		fifo[offset >> 2U] = buf32[offset >> 2U];
#else
		REBASE(OTG_FIFO(ep)) = buf32[offset >> 2U];
#endif
	}
	/* If there's some data left over at the end, do the final copy */
	if (len - aligned_len) {
		uint32_t data = 0U;
		const size_t amount = len - aligned_len;
		memcpy(&data, buf32 + (aligned_len >> 2U), amount);
#if defined(STM32H7)
		fifo[aligned_len >> 2U] = data;
#else
		REBASE(OTG_FIFO(ep)) = data;
#endif
	}
#else
	if (REBASE(OTG_DIEPTSIZ(ep)) & OTG_DIEPSIZ0_PKTCNT) {
		return 0U;
	}

	/* Enable endpoint for transmission. */
	REBASE(OTG_DIEPTSIZ(ep)) = OTG_DIEPSIZ0_PKTCNT | (len & OTG_DIEPSIZ0_XFRSIZ_MASK);
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_EPENA | OTG_DIEPCTL0_CNAK;

	const uint32_t *buf32 = buf;
	/* Copy buffer to endpoint FIFO, note - memcpy does not work.
	 * ARMv7M supports non-word-aligned accesses, ARMv6M does not. */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__)
	for (size_t i = 0U; i < len; i += 4U) {
		REBASE(OTG_FIFO(ep)) = buf32[i >> 2U];
	}
#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) */

#if defined(__ARM_ARCH_6M__)
	const uint8_t *buf8 = buf;
	/* Take care of word-aligned and non-word-aligned buffers */
	if (((uintptr_t)buf8 & 0x3U) == 0U) {
		for (size_t i = 0U; i < len; i += 4U) {
			REBASE(OTG_FIFO(ep)) = *buf32++;
		}
	} else {
		for (size_t i = 0U; i < len; i += 4U) {
			uint32_t word32;
			memcpy(&word32, buf8 + i, 4U);
			REBASE(OTG_FIFO(ep)) = word32;
		}
	}
#endif /* defined(__ARM_ARCH_6M__) */
#endif

	return len;
}

uint16_t dwc_ep_read_packet(usbd_device *usbd_dev, uint8_t addr, void *buf, uint16_t len)
{
	/* We do not need to know the endpoint address since there is only one receive FIFO for all endpoints. */
	(void)addr;
#if defined(STM32H7)
	const size_t count = MIN(len, usbd_dev->rxbcnt);

	uint8_t *const buf8 = buf;
	/* Figure out where to copy the data from */
	const volatile uint32_t *const fifo = (const volatile uint32_t *)(usbd_dev->driver->base_address + OTG_FIFO(0));
	/* Copy the data out of the FIFO for this endpoint */
	for (size_t offset = 0U; offset < count; offset += 4U) {
		const uint32_t data = fifo[offset >> 2U];
		const size_t amount = MIN(count - offset, 4U);
		memcpy(buf8 + offset, &data, amount);
	}

	usbd_dev->rxbcnt -= count;
	return count;
#else
	const size_t count = MIN(len, usbd_dev->rxbcnt);

	/* Calculate how many bytes will be left over from doing 32-bit transfers of the main bulk of data */
	const size_t remainder = count & 0x3U;
	/* Adjust the end point to cover only whole u32s */
	const size_t adjusted_count = count - remainder;
	uint32_t *const buf32 = buf;
	/* ARMv7-M and newer supports non-word-aligned accesses, ARMv6-M does not. */
#if defined(__ARM_ARCH_6M__)
	uint8_t *buf8 = buf;
	/* Take care of word-aligned and non-word-aligned buffers */
	if (((uintptr_t)buf8 & 0x3U) == 0U) {
		for (size_t offset = 0U; offset < adjusted_count; offset += 4U) {
			buf32[offset >> 2U] = REBASE(OTG_FIFO(0U));
			usbd_dev->rxbcnt -= 4U;
		}
	} else {
		for (size_t offset = 0U; offset < adjusted_count; offset += 4U) {
			const uint32_t word32 = REBASE(OTG_FIFO(0U));
			memcpy(buf8 + offset, &word32, 4U);
			usbd_dev->rxbcnt -= 4U;
		}
	}
#else
	for (size_t offset = 0U; offset < adjusted_count; offset += 4U) {
		buf32[offset >> 2U] = REBASE(OTG_FIFO(0U));
		usbd_dev->rxbcnt -= 4U;
	}
#endif /* defined(__ARM_ARCH_6M__) */

	if (remainder) {
		const uint32_t extra = REBASE(OTG_FIFO(0U));
		/* we read 4 bytes from the FIFO, so update rxbcnt */
		if (usbd_dev->rxbcnt < 4U) {
			/* Be careful not to underflow (rxbcnt is unsigned) */
			usbd_dev->rxbcnt = 0U;
		} else {
			usbd_dev->rxbcnt -= 4U;
		}
		memcpy(buf32 + (adjusted_count >> 2U), &extra, remainder);
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
#if defined(STM32H7) || defined(STM32U5)
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
#if defined(STM32H7) || defined(STM32U5)
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
#if defined(STM32H7) || defined(STM32U5)
			REBASE(OTG_DOEPINT(ep)) = OTG_DOEPINTX_STUP;
#endif
		}

		if (pktsts == OTG_GRXSTSP_PKTSTS_OUT_COMP || pktsts == OTG_GRXSTSP_PKTSTS_SETUP_COMP) {
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
			/* SETUP received but there is still something stuck in the transmit fifo. Flush it. */
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
		for (size_t offset = consumed; offset < total_length; offset += 4U) {
			(void)fifo[offset >> 2U];
		}

		REBASE(OTG_DOEPINT(ep)) = OTG_DOEPINTX_XFRC;
#else
		for (size_t offset = 0; offset < usbd_dev->rxbcnt; offset += 4U) {
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

#if !defined(STM32H7) && !defined(STM32U5)
	if (usbd_dev->user_callback_sof) {
		REBASE(OTG_GINTMSK) |= OTG_GINTMSK_SOFM;
	} else {
		REBASE(OTG_GINTMSK) &= ~OTG_GINTMSK_SOFM;
	}
#endif
}

void dwc_disconnect(usbd_device *const usbd_dev, const bool disconnected)
{
	if (disconnected) {
		REBASE(OTG_DCTL) |= OTG_DCTL_SDIS;
	} else {
		REBASE(OTG_DCTL) &= ~OTG_DCTL_SDIS;
	}
}
