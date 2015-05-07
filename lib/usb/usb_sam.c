/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Owen Kirby <osk@exegin.com>
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

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/sam/pmc.h>
#include <libopencm3/sam/usb.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

static usbd_device *udp_init(void);
static void udp_set_address(usbd_device *usbd_dev, uint8_t addr);
static void udp_ep_setup(usbd_device *usbd_dev, uint8_t addr,
					uint8_t type, uint16_t max_size,
					void (*callback) (usbd_device *usbd_dev, uint8_t ep));
static void udp_endpoints_reset(usbd_device *usbd_dev);
static void udp_ep_stall_set(usbd_device *usbd_dev, uint8_t addr, uint8_t stall);
static uint8_t udp_ep_stall_get(usbd_device *usbd_dev, uint8_t addr);
static void udp_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak);
static uint16_t udp_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
					  const void *buf, uint16_t len);
static uint16_t udp_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
					 void *buf, uint16_t len);
static void udp_poll(usbd_device *usbd_dev);

static struct _usbd_device udp_dev;

const struct _usbd_driver sam_usb_driver = {
	.init = udp_init,
	.set_address = udp_set_address,
	.ep_setup = udp_ep_setup,
	.ep_reset = udp_endpoints_reset,
	.ep_stall_set = udp_ep_stall_set,
	.ep_stall_get = udp_ep_stall_get,
	.ep_nak_set = udp_ep_nak_set,
	.ep_write_packet = udp_ep_write_packet,
	.ep_read_packet = udp_ep_read_packet,
	.poll = udp_poll,
};

static void
udp_csr_set(uint8_t ep, uint32_t bits)
{
	volatile uint32_t csr = UDP_CSR(ep);
	UDP_CSR(ep) = csr | UDP_CSR_WRITE_NOP | bits;
	while ((UDP_CSR(ep) & bits) != bits);
} /* udp_csr_set */

static void
udp_csr_clear(uint8_t ep, uint32_t bits)
{
	uint32_t csr = (UDP_CSR(ep) | UDP_CSR_WRITE_NOP) & ~bits;
	UDP_CSR(ep) = csr;
	while ((UDP_CSR(ep) & bits) == bits);
} /* udp_csr_clear */

/** Initialize the USB device port hardware of the SAM. */
static usbd_device *udp_init(void)
{
	/* Reset the transceiver. */
	pmc_peripheral_clock_enable(NVIC_UDP_IRQ);
	UDP_TXVC &= ~UDP_TXVC_TXVDIS;
	UDP_TXVC |= UDP_TXVC_PUON;
	
	/* Enable interrupts. */
	UDP_IER = UDP_INT_WAKEUP | UDP_INT_SOFINT |
			UDP_INT_EXTRSM | UDP_INT_RXRSM | UDP_INT_RXSUSP;
	return &udp_dev;
}

static void udp_set_address(usbd_device *dev, uint8_t addr)
{
	(void)dev;
	UDP_FADDR = (addr & UDP_FADDR_MASK) | UDP_FADDR_FEN;
	UDP_GLB_STAT = (addr) ? UDP_GLB_STAT_FADDEN : 0;
} /* udp_set_address */

static void udp_ep_setup(usbd_device *dev, uint8_t addr, uint8_t type,
				   uint16_t max_size,
				   void (*callback) (usbd_device *usbd_dev, uint8_t ep))
{
	uint8_t dir = (addr & 0x80) ? USB_TRANSACTION_IN : USB_TRANSACTION_OUT;
	uint32_t csr = UDP_CSR_WRITE_NOP | UDP_CSR_EPEDS;
	addr &= 0x7f;
	if (addr >= UDP_EP_COUNT) {
		return;
	}
	
	/* Set the endpoint configuration. */
	if (dir == USB_TRANSACTION_IN) csr |= UDP_CSR_EPTYPE_IN;
	UDP_RST |= UDP_RST_EP(addr);
	UDP_RST &= ~UDP_RST_EP(addr);
	switch (type) {
	case USB_ENDPOINT_ATTR_CONTROL:
		if (!UDP_EP_SUPPORT_CTRL(addr)) return; /* TODO: Handle errors? */
		/* TODO: What about the transfer direction setting? */
		UDP_CSR(addr) = csr | UDP_CSR_EPTYPE_CTRL;
		break;
	
	case USB_ENDPOINT_ATTR_ISOCHRONOUS:
		if (!UDP_EP_SUPPORT_ISO(addr)) return; /* TODO: Handle errors? */
		UDP_CSR(addr) = csr | UDP_CSR_EPTYPE_ISO;
		break;
	
	case USB_ENDPOINT_ATTR_BULK:
		UDP_CSR(addr) = csr | UDP_CSR_EPTYPE_BULK;
		break;
	
	case USB_ENDPOINT_ATTR_INTERRUPT:
		UDP_CSR(addr) = csr | UDP_CSR_EPTYPE_INT;
		break;
	}
	if (callback) {
		dev->user_callback_ctr[addr][dir] = (void *)callback;
	}
	
	/* TODO: What if the selected size is too big for the endpoint? */
	/* TODO: min(UDP_EP_MAX_SIZE(addr), max_size)? */
	dev->pm_top += max_size;
	
	/* Enable the endpoint interrupts. */
	UDP_IER = UDP_INT_EP(addr);
}

static void udp_endpoints_reset(usbd_device *dev)
{
	UDP_RST = UDP_RST_ALL;
	UDP_RST = 0;
	dev->pm_top = 0x40 + (2 * dev->desc->bMaxPacketSize0);
	
	/* If the current config is non-zero, we are entering the configured state,
	 * otherwise, fall back to the address state. */
	UDP_GLB_STAT = (dev->current_config) ? UDP_GLB_STAT_CONFG : UDP_GLB_STAT_FADDEN;
} /* udp_endpoints_reset */ 

static void udp_ep_stall_set(usbd_device *dev, uint8_t addr,
				   uint8_t stall)
{
	(void)dev;
	addr &= 0x7F;
	if (addr >= UDP_EP_COUNT) {
		return;
	}
	if (stall) {
		udp_csr_set(addr, UDP_CSR_FORCESTALL);
	} else {
		udp_csr_clear(addr, UDP_CSR_FORCESTALL | UDP_CSR_STALLSENT);
	}
}

static uint8_t udp_ep_stall_get(usbd_device *dev, uint8_t addr)
{
	(void)dev;
	addr &= 0x7F;
	if (addr >= UDP_EP_COUNT) {
		return 0;
	}
	return ((UDP_CSR(addr) & UDP_CSR_FORCESTALL) == UDP_CSR_FORCESTALL);
}

static void udp_ep_nak_set(usbd_device *dev, uint8_t addr, uint8_t nak)
{
	(void)dev;
	/* It does not make sence to force NAK on IN endpoints. */
	if (addr & 0x80) {
		return;
	}
	if (addr >= UDP_EP_COUNT) {
		return;
	}
	/* Disable the endpoint to force a NAK. */
	if (nak) {
		udp_csr_clear(addr, UDP_CSR_EPEDS);
	} else {
		udp_csr_set(addr, UDP_CSR_EPEDS);
	}
}

static uint16_t udp_ep_write_packet(usbd_device *dev, uint8_t addr,
					 const void *buf, uint16_t len)
{
	(void)dev;
	const uint8_t *p = buf;
	const uint8_t *end = p + len;
	addr &= 0x7F;
	if (addr >= UDP_EP_COUNT) {
		return 0;
	}
	
	/* TODO: This assumes a non ping-pong endpoint, we could improve throughput
	 * on ping-pong endpoints by skipping this check to fill the 2nd FIFO. */
	if ((UDP_CSR(addr) & UDP_CSR_TXPKTRDY) == UDP_CSR_TXPKTRDY) {
		return 0;
	}
	
	while (p < end) UDP_FDR(addr) = *p++;
	udp_csr_set(addr, UDP_CSR_TXPKTRDY);
	return len;
}

static uint16_t udp_ep_read_packet(usbd_device *dev, uint8_t addr,
					 void *buf, uint16_t len)
{
	(void)dev;
	uint32_t csr, rxbit;
	uint8_t *p = buf;
	uint8_t *end;
	if (addr >= UDP_EP_COUNT) {
		return 0;
	}
	
	/* TODO: What happens when both FIFOs of a ping-pong endpoint are filled? */
	csr = UDP_CSR(addr);
	rxbit = csr & (UDP_CSR_RX_DATA_BK0 | UDP_CSR_RX_DATA_BK1 | UDP_CSR_RXSETUP);
	if (rxbit == 0) {
		return 0;
	}

	len = MIN(UDP_CSR_GET_RXBYTECNT(csr), len);
	end = p + len;
	while (p < end) *p++ = UDP_FDR(addr);
	if ((csr & UDP_CSR_RXSETUP) && (*(uint8_t*)buf & 0x80)) {
		udp_csr_set(addr, UDP_CSR_DIR);
	}
	udp_csr_clear(addr, rxbit);
	return len;
}

static void udp_poll_ep(usbd_device *dev, uint8_t ep)
{
	uint32_t csr = UDP_CSR(ep);
	
	if (csr & UDP_CSR_RXSETUP) {
		if (dev->user_callback_ctr[ep][USB_TRANSACTION_SETUP]) {
			dev->user_callback_ctr[ep][USB_TRANSACTION_SETUP](dev, ep);
		} else {
			udp_csr_clear(ep, UDP_CSR_RXSETUP);
		}
	}
	if (csr & (UDP_CSR_RX_DATA_BK0 | UDP_CSR_RX_DATA_BK1)) {
		if (dev->user_callback_ctr[ep][USB_TRANSACTION_OUT]) {
			dev->user_callback_ctr[ep][USB_TRANSACTION_OUT](dev, ep);
		} else {
			udp_csr_clear(ep, UDP_CSR_RX_DATA_BK0 | UDP_CSR_RX_DATA_BK1);
		}
	}
	if (csr & UDP_CSR_TXCOMP) {
		if (dev->user_callback_ctr[ep][USB_TRANSACTION_IN]) {
			dev->user_callback_ctr[ep][USB_TRANSACTION_IN](dev, ep);
		}
		udp_csr_clear(ep, UDP_CSR_TXCOMP);
	}
	if (csr & UDP_CSR_STALLSENT) {
		UDP_CSR(ep) = (csr | UDP_CSR_WRITE_NOP) & ~UDP_CSR_STALLSENT;
	}
}

static void udp_poll(usbd_device *dev)
{
	int i;

	if (UDP_ISR & UDP_INT_ENDBUSRES) {
		dev->pm_top = 0x40; /* ??? */
		_usbd_reset(dev);
		UDP_ICR = UDP_INT_ENDBUSRES;
		return;
	}

	/* Endpoint interrupts. */
	for (i = 0; i < UDP_EP_COUNT; i++) {
		if (UDP_ISR & UDP_INT_EP(i)) udp_poll_ep(dev, i);
	}

	if (UDP_ISR & UDP_INT_RXSUSP) {
		UDP_ICR = UDP_INT_RXSUSP;
		if (dev->user_callback_suspend) {
			dev->user_callback_suspend();
		}
	}

	if (UDP_ISR & (UDP_INT_WAKEUP | UDP_INT_RXRSM)) {
		UDP_ICR = UDP_INT_WAKEUP | UDP_INT_RXRSM;
		if (dev->user_callback_resume) {
			dev->user_callback_resume();
		}
	}

	if (UDP_ISR & UDP_INT_SOFINT) {
		if (dev->user_callback_sof) {
			dev->user_callback_sof();
		}
		UDP_ICR = UDP_INT_SOFINT;
	}
}
