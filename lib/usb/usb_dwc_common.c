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

static void dwc_flush_txfifo(usbd_device *const usbd_dev, const uint8_t ep);

void dwc_set_address(usbd_device *const usbd_dev, const uint8_t address)
{
	REBASE(OTG_DCFG) = (REBASE(OTG_DCFG) & ~OTG_DCFG_DAD) | ((address << 4U) & OTG_DCFG_DAD);
}

void dwc_ep_setup(usbd_device *const usbd_dev, const uint8_t endpoint_address, const uint8_t type,
	const uint16_t max_packet_length, void (*const callback)(usbd_device *usbd_dev, uint8_t ep))
{
	const uint8_t ep = endpoint_address & 0x7fU;
	const uint8_t dir = endpoint_address & 0x80U;
	/* Convert the max packet length to a length in u32's */
	const uint16_t packet_length = max_packet_length / 4U;

	/* Process if we're being asked to set up EP0, */
	if (ep == 0U) {
		/* Start by setting up the TX and RX FIFOs */
		REBASE(OTG_GRXFSIZ) = usbd_dev->driver->rx_fifo_size;
		REBASE(OTG_GNPTXFSIZ) = (packet_length << 16U) | usbd_dev->driver->rx_fifo_size;
		/* Update our internal state for how the FIFOs are presently allocated */
		usbd_dev->fifo_mem_top_ep0 = usbd_dev->driver->rx_fifo_size + packet_length;
		usbd_dev->fifo_mem_top = usbd_dev->fifo_mem_top_ep0;
		/* Configure EP0 IN to allow us to send packets appropriately */
#if defined(STM32H7)
		REBASE(OTG_DIEPCTL0) = (max_packet_length & OTG_DIEPCTLX_MPSIZ_MASK);
#else
		if (max_packet_length >= 64U)
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_64;
		else if (max_packet_length >= 32U)
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_32;
		else if (max_packet_length >= 16U)
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_16;
		else
			REBASE(OTG_DIEPCTL0) = OTG_DIEPCTL0_MPSIZ_8;
#endif
		/* Do not initially arm the IN endpoint - we've got nothing to send the host at first */
		REBASE(OTG_DIEPCTL0) |= OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP;

		/* Now configure EP0 OUT to allow us to receive SETUP packets */
		usbd_dev->doeptsiz[0U] =
			OTG_DOEPSIZ0_STUPCNT_1 | OTG_DOEPSIZ0_PKTCNT | (max_packet_length & OTG_DOEPSIZ0_XFRSIZ_MASK);
		REBASE(OTG_DOEPTSIZ0) = usbd_dev->doeptsiz[0U];
		/* However, *do* arm the OUT endpoint so we can receive the first SETUP packet */
#if defined(STM32H7)
		if (max_packet_length >= 64) {
			REBASE(OTG_DOEPCTL0) = OTG_DOEPCTL0_MPSIZ_64;
		} else if (max_packet_length >= 32) {
			REBASE(OTG_DOEPCTL0) = OTG_DOEPCTL0_MPSIZ_32;
		} else if (max_packet_length >= 16) {
			REBASE(OTG_DOEPCTL0) = OTG_DOEPCTL0_MPSIZ_16;
		} else {
			REBASE(OTG_DOEPCTL0) = OTG_DOEPCTL0_MPSIZ_8;
		}
		REBASE(OTG_DOEPCTL0) |= OTG_DOEPCTL0_EPENA | OTG_DOEPCTL0_CNAK | OTG_DOEPCTL0_USBAEP;
#else
		REBASE(OTG_DOEPCTL0) = OTG_DOEPCTL0_EPENA | OTG_DIEPCTL0_SNAK | OTG_DOEPCTL0_USBAEP;
#endif
	} else {
		/* Otherwise process if this is for IN vs OUT */
		if (dir == 0U) {
			/* Set up this OUT endpoint, arming it so we can get data from it */
			usbd_dev->doeptsiz[ep] = OTG_DOEPSIZX_PKTCNT(1U) | (max_packet_length & OTG_DOEPSIZX_XFRSIZ_MASK);
			REBASE(OTG_DOEPTSIZ(ep)) = usbd_dev->doeptsiz[ep];
			REBASE(OTG_DOEPCTL(ep)) = OTG_DOEPCTL0_EPENA | OTG_DOEPCTL0_CNAK | OTG_DOEPCTL0_USBAEP |
				OTG_DOEPCTLX_SD0PID | (type << OTG_DOEPCTLX_EPTYP_SHIFT) |
				(max_packet_length & OTG_DOEPCTLX_MPSIZ_MASK);

			/* Install the user's callback provided */
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_OUT] = callback;
		} else {
			/* Set up this IN endpoint, allocating space for it in the FIFO memory */
			REBASE(OTG_DIEPTXF(ep)) = (packet_length << 16U) | usbd_dev->fifo_mem_top;
			usbd_dev->fifo_mem_top += packet_length;
			REBASE(OTG_DIEPTSIZ(ep)) = 0U;
			/* Enable the endpoint but do not yet arm it as we've not yet got anything to send */
			REBASE(OTG_DIEPCTL(ep)) = OTG_DIEPCTL0_SNAK | OTG_DIEPCTL0_USBAEP | OTG_DIEPCTLX_SD0PID |
				(ep << OTG_DIEPCTLX_TXFNUM_SHIFT) | (type << OTG_DIEPCTLX_EPTYP_SHIFT) |
				(max_packet_length & OTG_DIEPCTLX_MPSIZ_MASK);

			/* Install the user's callback provided */
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN] = callback;
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

uint16_t dwc_ep_write_packet(
	usbd_device *const usbd_dev, const uint8_t endpoint_address, const void *const buffer, const uint16_t length)
{
	const uint8_t ep = endpoint_address & 0x7fU;
	/* Return if endpoint is already enabled */
	if ((REBASE(OTG_DIEPCTL(ep)) & (OTG_DIEPCTL0_EPENA | OTG_DIEPCTL0_NAKSTS)) == OTG_DIEPCTL0_EPENA) {
		return 0U;
	}
	/* If it's still enabled but being NAK'd, flush FIFO and reset */
	if ((REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_EPENA) != 0U) {
		dwc_flush_txfifo(usbd_dev, ep);
		/* Disable the endpoint and wait for it to become actually disabled */
		REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_EPDIS;
		while ((REBASE(OTG_DIEPINT(ep)) & OTG_DIEPINTX_EPDISD) == 0U)
			continue;
		REBASE(OTG_DIEPINT(ep)) = OTG_DIEPINTX_EPDISD;
	}

	/* Configure the endpoint to accept the new packet */
	if (ep == 0U)
		REBASE(OTG_DIEPTSIZ0) = OTG_DIEPSIZ0_PKTCNT | (length & OTG_DIEPSIZ0_XFRSIZ_MASK);
	else
		REBASE(OTG_DIEPTSIZ(ep)) = OTG_DIEPSIZX_MCNT_1 | OTG_DIEPSIZX_PKTCNT(1) | (length & OTG_DIEPSIZX_XFRSIZ_MASK);
	/* Arm the endpoint for send */
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_EPENA | OTG_DIEPCTL0_CNAK;

	/* Figure out how many bytes can be written as u32 chunks */
	const size_t aligned_length = length & ~3U;
#if defined(__ARM_ARCH_6M__)
	if (((uintptr_t)buffer & 0x3U) == 0U) {
#endif
		/* Copy what we can into the FIFO for this endpoint in u32 blocks */
		for (size_t offset = 0U; offset < aligned_length; offset += 4U)
			REBASE(OTG_FIFO(ep)) = ((const uint32_t *)buffer)[offset >> 2U];
#if defined(__ARM_ARCH_6M__)
	} else {
		const uint8_t *const buffer8 = buffer;
		/* Copy the data into the FIFO for this endpoint in u32 blocks using memcpy to work around alignment issues */
		for (size_t offset = 0U; offset < aligned_length; offset += 4U) {
			uint32_t data;
			memcpy(&data, buffer8 + offset, 4U);
			REBASE(OTG_FIFO(0U)) = data;
		}
	}
#endif
	/* If there's some data left over at the end, do the final copy */
	if (length - aligned_length) {
		/* Prepare the data block for the FIFO */
		uint32_t data = 0U;
		memcpy(&data, (const uint8_t *)buffer + aligned_length, length - aligned_length);
		/* Push the prepared data into the FIFO to complete transfer setup */
		REBASE(OTG_FIFO(ep)) = data;
	}

	/* Return that we wrote the whole packet out */
	return length;
}

uint16_t dwc_ep_read_packet(
	usbd_device *const usbd_dev, const uint8_t endpoint_address, void *const buffer, const uint16_t length)
{
	/* We do not need to know the endpoint address since there is only one receive FIFO for all endpoints. */
	(void)endpoint_address;
	/* Figure out how many bytes to read, and how many can be read as u32 chunks */
	const size_t count = MIN(length, usbd_dev->rxbcnt);
	const size_t aligned_count = count & ~3U;

	/* ARMv7-M and newer supports non-word-aligned accesses, ARMv6-M does not. */
#if defined(__ARM_ARCH_6M__)
	if (((uintptr_t)buffer & 0x3U) == 0U) {
#endif
		/* Copy the data out of the FIFO for this endpoint in u32 blocks */
		for (size_t offset = 0U; offset < aligned_count; offset += 4U)
			((uint32_t *)buffer)[offset >> 2U] = REBASE(OTG_FIFO(0U));
#if defined(__ARM_ARCH_6M__)
	} else {
		uint8_t *const buffer8 = buffer;
		/* Copy the data out of the FIFO for this endpoint in u32 blocks using memcpy to work around alignment issues */
		for (size_t offset = 0U; offset < aligned_count; offset += 4U) {
			const uint32_t data = REBASE(OTG_FIFO(0U));
			memcpy(buffer8 + offset, &data, 4U);
		}
	}
#endif

	/* If theres some data left over at the end, do the final copy */
	if (count - aligned_count) {
		/* Extract the last data block from the FIFO */
		const uint32_t data = REBASE(OTG_FIFO(0U));
		/* Copy the data for this final transfer into the target location in the buffer */
		memcpy((uint8_t *)buffer + aligned_count, &data, count - aligned_count);
		/* Because of how unloading works, we unload a bit more than this would ideally want */
		if (usbd_dev->rxbcnt <= aligned_count + 4U)
			usbd_dev->rxbcnt = 0U; /* If we exhausted the data, set to 0 */
		else
			usbd_dev->rxbcnt -= count + 4U;
	} else
		/* All's said and done, so drop the read count by the amount read and return */
		usbd_dev->rxbcnt -= count;
	return count;
}

static void dwc_flush_txfifo(usbd_device *const usbd_dev, const uint8_t ep)
{
	/* Mark the endpoint to NAK and wait for it to become active */
	REBASE(OTG_DIEPCTL(ep)) |= OTG_DIEPCTL0_SNAK;
	while ((REBASE(OTG_DIEPINT(ep)) & OTG_DIEPINTX_INEPNE) == 0U) {
	}
	/* Figure out which FIFO is in use for this endpoint */
	const uint32_t fifo = (REBASE(OTG_DIEPCTL(ep)) & OTG_DIEPCTL0_TXFNUM_MASK) >> 22;
	/* Wait for core to idle */
	while ((REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_AHBIDL) == 0U) {
	}
	/* Flush the FIFO in quest */
	REBASE(OTG_GRSTCTL) = (fifo << 6U) | OTG_GRSTCTL_TXFFLSH;
	while ((REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_TXFFLSH) != 0U) {
		/* idle */
	}
	/* Reset packet queing size information */
	REBASE(OTG_DIEPTSIZ(ep)) = 0U;
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
