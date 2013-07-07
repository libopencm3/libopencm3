/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/**
 * @defgroup usb_file USB
 *
 * @ingroup LM4Fxx
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Alexandru Gagniuc <mr.nuke.me@gmail.com>
 *
 * \brief <b>libopencm3 LM4F Universal Serial Bus controller </b>
 *
 * The LM4F USB driver is integrated with the libopencm3 USB stack. You should
 * use the generic stack.
 *
 * To use this driver, tell the linker to look for it:
 * @code{.c}
 *	extern usbd_driver lm4f_usb_driver;
 * @endcode
 *
 * And pass this driver as an argument when initializing the USB stack:
 * @code{.c}
 * usbd_device *usbd_dev;
 * usbd_dev = usbd_init(&lm4f_usb_driver, ...);
 * @endcode
 *
 * <b>Polling or interrupt-driven? </b>
 *
 * The LM4F USB driver will work fine regardless of whether it is called from an
 * interrupt service routine, or from the main program loop.
 *
 * Polling USB from the main loop requires calling @ref usbd_poll() from the
 * main program loop.
 * For example:
 * @code{.c}
 *	// Main program loop
 *	while(1) {
 *		usbd_poll(usb_dev);
 *		do_other_stuff();
 *		...
 * @endcode
 *
 * Running @ref usbd_poll() from an interrupt has the advantage that it is only
 * called when needed, saving CPU cycles for the main program.
 *
 * RESET, DISCON, RESUME, and SUSPEND interrupts must be enabled, along with the
 * interrupts for any endpoint that is used. The EP0_TX interrupt must be
 * enabled for the control endpoint to function correctly.
 * For example, if EP1IN and EP2OUT are used, then the EP0_TX, EP1_TX, and
 * EP2_RX interrupts should be enabled:
 * @code{.c}
 *	// Enable USB interrupts for EP0, EP1IN, and EP2OUT
 *	ints = USB_INT_RESET | USB_INT_DISCON | USB_INT_RESUME |
 *		 USB_INT_SUSPEND;
 *	usb_enable_interrupts(ints, USB_EP2_INT, USB_EP0_INT | USB_EP1_INT);
 *	// Route the interrupts through the NVIC
 *	nvic_enable_irq(NVIC_USB0_IRQ);
 * @endcode
 *
 * The USB ISR only has to call @ref usbd_poll().
 *
 * @code{.c}
 *	void usb0_isr(void)
 *	{
 *		usbd_poll(usb_dev);
 *	}
 * @endcode
 * @{
 */

/*
 * TODO list:
 *
 * 1) Driver works by reading and writing to the FIFOs one byte at a time. It
 * has no knowledge of DMA.
 * 2) Double-buffering is supported. How can we take advantage of it to speed
 * up endpoint transfers.
 * 3) No benchmarks as to the endpoint's performance has been done.
 */
/*
 * The following are resources referenced in comments:
 * [1] http://e2e.ti.com/support/microcontrollers/tiva_arm/f/908/t/238784.aspx
 */

#include <libopencm3/cm3/common.h>
#include <libopencm3/lm4f/usb.h>
#include <libopencm3/lm4f/rcc.h>
#include <libopencm3/usb/usbd.h>
#include "../../lib/usb/usb_private.h"

#include <stdbool.h>


#define MAX_FIFO_RAM	(4 * 1024)

const struct _usbd_driver lm4f_usb_driver;

/**
 * \brief Enable Specific USB Interrupts
 *
 * Enable any combination of interrupts. Interrupts may be OR'ed together to
 * enable them with one call. For example, to enable both the RESUME and RESET
 * interrupts, pass (USB_INT_RESUME | USB_INT_RESET)
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] ints Interrupts which to enable. Any combination of interrupts may
 *                 be specified by OR'ing then together
 * @param[in] rx_ints Endpoints for which to generate an interrupt when a packet
 *                    packet is received.
 * @param[in] tx_ints Endpoints for which to generate an interrupt when a packet
 *                    packet is finished transmitting.
 */
void usb_enable_interrupts(enum usb_interrupt ints,
			   enum usb_ep_interrupt rx_ints,
			   enum usb_ep_interrupt tx_ints)
{
	USB_IE |= ints;
	USB_RXIE |= rx_ints;
	USB_TXIE |= tx_ints;
}

/**
 * \brief Disable Specific USB Interrupts
 *
 * Disable any combination of interrupts. Interrupts may be OR'ed together to
 * enable them with one call. For example, to disable both the RESUME and RESET
 * interrupts, pass (USB_INT_RESUME | USB_INT_RESET)
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] ints Interrupts which to disable. Any combination of interrupts
 *                 may be specified by OR'ing then together
 * @param[in] rx_ints Endpoints for which to stop generating an interrupt when a
 *                    packet packet is received.
 * @param[in] tx_ints Endpoints for which to stop generating an interrupt when a
 *                    packet packet is finished transmitting.
 */
void usb_disable_interrupts(enum usb_interrupt ints,
			    enum usb_ep_interrupt rx_ints,
			    enum usb_ep_interrupt tx_ints)
{
	USB_IE &= ~ints;
	USB_RXIE &= ~rx_ints;
	USB_TXIE &= ~tx_ints;
}

/**
 * @cond private
 */
static inline void lm4f_usb_soft_disconnect(void)
{
	USB_POWER &= ~USB_POWER_SOFTCONN;
}

static inline void lm4f_usb_soft_connect(void)
{
	USB_POWER |= USB_POWER_SOFTCONN;
}

static void lm4f_set_address(usbd_device *usbd_dev, uint8_t addr)
{
	(void)usbd_dev;

	USB_FADDR = addr & USB_FADDR_FUNCADDR_MASK;
}

static void lm4f_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
			  uint16_t max_size,
			  void (*callback) (usbd_device *usbd_dev, uint8_t ep))
{
	(void)usbd_dev;
	(void)type;

	uint8_t reg8;
	uint16_t fifo_size;

	const bool dir_tx = addr & 0x80;
	const uint8_t ep = addr & 0x0f;

	/*
	 * We do not mess with the maximum packet size, but we can only allocate
	 * the FIFO in power-of-two increments.
	 */
	if (max_size > 1024) {
		fifo_size = 2048;
		reg8 = USB_FIFOSZ_SIZE_2048;
	} else if (max_size > 512) {
		fifo_size = 1024;
		reg8 = USB_FIFOSZ_SIZE_1024;
	} else if (max_size > 256) {
		fifo_size = 512;
		reg8 = USB_FIFOSZ_SIZE_512;
	} else if (max_size > 128) {
		fifo_size = 256;
		reg8 = USB_FIFOSZ_SIZE_256;
	} else if (max_size > 64) {
		fifo_size = 128;
		reg8 = USB_FIFOSZ_SIZE_128;
	} else if (max_size > 32) {
		fifo_size = 64;
		reg8 = USB_FIFOSZ_SIZE_64;
	} else if (max_size > 16) {
		fifo_size = 32;
		reg8 = USB_FIFOSZ_SIZE_32;
	} else if (max_size > 8) {
		fifo_size = 16;
		reg8 = USB_FIFOSZ_SIZE_16;
	} else {
		fifo_size = 8;
		reg8 = USB_FIFOSZ_SIZE_8;
	}

	/* Endpoint 0 is more special */
	if (addr == 0) {
		USB_EPIDX = 0;

		if (reg8 > USB_FIFOSZ_SIZE_64) {
			reg8 = USB_FIFOSZ_SIZE_64;
		}

		/* The RX and TX FIFOs are shared for EP0 */
		USB_RXFIFOSZ = reg8;
		USB_TXFIFOSZ = reg8;

		/*
		 * Regardless of how much we allocate, the first 64 bytes
		 * are always reserved for EP0.
		 */
		usbd_dev->fifo_mem_top_ep0 = 64;
		return;
	}

	/* Are we out of FIFO space? */
	if (usbd_dev->fifo_mem_top + fifo_size > MAX_FIFO_RAM) {
		return;
	}

	USB_EPIDX = addr & USB_EPIDX_MASK;

	/* FIXME: What about double buffering? */
	if (dir_tx) {
		USB_TXMAXP(ep) = max_size;
		USB_TXFIFOSZ = reg8;
		USB_TXFIFOADD = ((usbd_dev->fifo_mem_top) >> 3);
		if (callback) {
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN] =
			(void *)callback;
		}
		if (type == USB_ENDPOINT_ATTR_ISOCHRONOUS) {
			USB_TXCSRH(ep) |= USB_TXCSRH_ISO;
		} else {
			USB_TXCSRH(ep) &= ~USB_TXCSRH_ISO;
		}
	} else {
		USB_RXMAXP(ep) = max_size;
		USB_RXFIFOSZ = reg8;
		USB_RXFIFOADD = ((usbd_dev->fifo_mem_top) >> 3);
		if (callback) {
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_OUT] =
			(void *)callback;
		}
		if (type == USB_ENDPOINT_ATTR_ISOCHRONOUS) {
			USB_RXCSRH(ep) |= USB_RXCSRH_ISO;
		} else {
			USB_RXCSRH(ep) &= ~USB_RXCSRH_ISO;
		}
	}

	usbd_dev->fifo_mem_top += fifo_size;
}

static void lm4f_endpoints_reset(usbd_device *usbd_dev)
{
	/*
	 * The core resets the endpoints automatically on reset.
	 * The first 64 bytes are always reserved for EP0
	 */
	usbd_dev->fifo_mem_top = 64;
}

static void lm4f_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
			      uint8_t stall)
{
	(void)usbd_dev;

	const uint8_t ep = addr & 0x0f;
	const bool dir_tx = addr & 0x80;

	if (ep == 0) {
		if (stall) {
			USB_CSRL0 |= USB_CSRL0_STALL;
		} else {
			USB_CSRL0 &= ~USB_CSRL0_STALL;
		}
		return;
	}

	if (dir_tx) {
		if (stall) {
			(USB_TXCSRL(ep)) |= USB_TXCSRL_STALL;
		} else {
			(USB_TXCSRL(ep)) &= ~USB_TXCSRL_STALL;
		}
	} else {
		if (stall) {
			(USB_RXCSRL(ep)) |= USB_RXCSRL_STALL;
		} else {
			(USB_RXCSRL(ep)) &= ~USB_RXCSRL_STALL;
		}
	}
}

static uint8_t lm4f_ep_stall_get(usbd_device *usbd_dev, uint8_t addr)
{
	(void)usbd_dev;

	const uint8_t ep = addr & 0x0f;
	const bool dir_tx = addr & 0x80;

	if (ep == 0) {
		return USB_CSRL0 & USB_CSRL0_STALLED;
	}

	if (dir_tx) {
		return USB_TXCSRL(ep) & USB_TXCSRL_STALLED;
	} else {
		return USB_RXCSRL(ep) & USB_RXCSRL_STALLED;
	}
}

static void lm4f_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak)
{
	(void)usbd_dev;
	(void)addr;
	(void)nak;

	/* NAK's are handled automatically by hardware. Move along. */
}

static uint16_t lm4f_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
			      const void *buf, uint16_t len)
{
	const uint8_t ep = addr & 0xf;
	uint16_t i;

	(void)usbd_dev;

	/* Don't touch the FIFO if there is still a packet being transmitted */
	if (ep == 0 && (USB_CSRL0 & USB_CSRL0_TXRDY)) {
		return 0;
	} else if (USB_TXCSRL(ep) & USB_TXCSRL_TXRDY) {
		return 0;
	}

	/*
	 * We don't need to worry about buf not being aligned. If it's not,
	 * the reads are downgraded to 8-bit in hardware. We lose a bit of
	 * performance, but we don't crash.
	 */
	for (i = 0; i < (len & ~0x3); i += 4) {
		USB_FIFO32(ep) = *((uint32_t *)(buf + i));
	}
	if (len & 0x2) {
		USB_FIFO16(ep) = *((uint16_t *)(buf + i));
		i += 2;
	}
	if (len & 0x1) {
		USB_FIFO8(ep)  = *((uint8_t *)(buf + i));
		i += 1;
	}

	if (ep == 0) {
		/*
		 * EP0 is very special. We should only set DATAEND when we
		 * transmit the last packet in the transaction. A transaction
		 * that is a multiple of 64 bytes will end with a zero-length
		 * packet, so our check is sane.
		 */
		if (len != 64) {
			USB_CSRL0 |= USB_CSRL0_TXRDY | USB_CSRL0_DATAEND;
		} else {
			USB_CSRL0 |= USB_CSRL0_TXRDY;
		}
	} else {
		USB_TXCSRL(ep) |= USB_TXCSRL_TXRDY;
	}

	return i;
}

static uint16_t lm4f_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
				    void *buf, uint16_t len)
{
	(void)usbd_dev;

	uint16_t rlen;
	uint8_t ep = addr & 0xf;

	uint16_t fifoin = USB_RXCOUNT(ep);

	rlen = (fifoin > len) ? len : fifoin;

	/*
	 * We don't need to worry about buf not being aligned. If it's not,
	 * the writes are downgraded to 8-bit in hardware. We lose a bit of
	 * performance, but we don't crash.
	 */
	for (len = 0; len < (rlen & ~0x3); len += 4) {
		*((uint32_t *)(buf + len)) = USB_FIFO32(ep);
	}
	if (rlen & 0x2) {
		*((uint16_t *)(buf + len)) = USB_FIFO16(ep);
		len += 2;
	}
	if (rlen & 0x1) {
		*((uint8_t *)(buf + len)) = USB_FIFO8(ep);
	}

	if (ep == 0) {
		/*
		 * Clear RXRDY
		 * Datasheet says that DATAEND must also be set when clearing
		 * RXRDY. We don't do that. If did this when transmitting a
		 * packet larger than 64 bytes, only the first 64 bytes would
		 * be transmitted, followed by a handshake. The host would only
		 * get 64 bytes, seeing it as a malformed packet. Usually, we
		 * would not get past enumeration.
		 */
		USB_CSRL0 |= USB_CSRL0_RXRDYC;

	} else {
		USB_RXCSRL(ep) &= ~USB_RXCSRL_RXRDY;
	}

	return rlen;
}

static void lm4f_poll(usbd_device *usbd_dev)
{
	void (*tx_cb)(usbd_device *usbd_dev, uint8_t ea);
	void (*rx_cb)(usbd_device *usbd_dev, uint8_t ea);
	int i;

	/*
	 * The initial state of these registers might change, as we process the
	 * interrupt, but we need the initial state in order to decide how to
	 * handle events.
	 */
	const uint8_t usb_is = USB_IS;
	const uint8_t usb_rxis = USB_RXIS;
	const uint8_t usb_txis = USB_TXIS;
	const uint8_t usb_csrl0 = USB_CSRL0;

	if ((usb_is & USB_IM_SUSPEND) && (usbd_dev->user_callback_suspend)) {
		usbd_dev->user_callback_suspend();
	}

	if ((usb_is & USB_IM_RESUME) && (usbd_dev->user_callback_resume)) {
		usbd_dev->user_callback_resume();
	}

	if (usb_is & USB_IM_RESET) {
		_usbd_reset(usbd_dev);
	}

	if ((usb_is & USB_IM_SOF) && (usbd_dev->user_callback_sof)) {
		usbd_dev->user_callback_sof();
	}

	if (usb_txis & USB_EP0) {
		/*
		 * The EP0 bit in USB_TXIS is special. It tells us that
		 * something happened on EP0, but does not tell us what. This
		 * bit does not necessarily tell us that a packet was
		 * transmitted, so we have to go through all the possibilities
		 * to figure out exactly what did. Only after we've exhausted
		 * all other possibilities, can we assume this is a EPO
		 * "transmit complete" interrupt.
		 */
		if (usb_csrl0 & USB_CSRL0_RXRDY) {
			enum _usbd_transaction type;
			type = (usbd_dev->control_state.state != DATA_OUT &&
				usbd_dev->control_state.state != LAST_DATA_OUT)
				? USB_TRANSACTION_SETUP :
				  USB_TRANSACTION_OUT;

			if (usbd_dev->user_callback_ctr[0][type]) {
				usbd_dev->
					user_callback_ctr[0][type](usbd_dev, 0);
			}


		} else {
			tx_cb = usbd_dev->user_callback_ctr[0]
							   [USB_TRANSACTION_IN];

			/*
			 * EP0 bit in TXIS is set not only when a packet is
			 * finished transmitting, but also when RXRDY is set, or
			 * when we set TXRDY to transmit a packet. If any of
			 * those are the case, then we do not want to call our
			 * IN callback, since the state machine will be in the
			 * wrong state, and we'll just stall our control
			 * endpoint.
			 * In fact, the only way to know if it's time to call
			 * our TX callback is to know what to expect. The
			 * hardware does not tell us what sort of transaction
			 * this is. We need to work with the state machine to
			 * figure it all out. See [1] for details.
			 */
			if ((usbd_dev->control_state.state != DATA_IN) &&
			    (usbd_dev->control_state.state != LAST_DATA_IN) &&
			    (usbd_dev->control_state.state != STATUS_IN)) {
				return;
			}

			if (tx_cb) {
				tx_cb(usbd_dev, 0);
			}
		}
	}

	/* See which interrupt occurred */
	for (i = 1; i < 8; i++) {
		tx_cb = usbd_dev->user_callback_ctr[i][USB_TRANSACTION_IN];
		rx_cb = usbd_dev->user_callback_ctr[i][USB_TRANSACTION_OUT];

		if ((usb_txis & (1 << i)) && tx_cb) {
			tx_cb(usbd_dev, i);
		}

		if ((usb_rxis & (1 << i)) && rx_cb) {
			rx_cb(usbd_dev, i);
		}
	}


}

static void lm4f_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	(void)usbd_dev;

	/*
	 * This is all it takes:
	 * usbd_disconnect(dev, 1) followed by usbd_disconnect(dev, 0)
	 * causes the device to re-enumerate and re-configure properly.
	 */
	if (disconnected) {
		lm4f_usb_soft_disconnect();
	} else {
		lm4f_usb_soft_connect();
	}
}

/*
 * A static struct works as long as we have only one USB peripheral. If we
 * meet LM4Fs with more than one USB, then we need to rework this approach.
 */
static struct _usbd_device usbd_dev;

/** Initialize the USB device controller hardware of the LM4F. */
static usbd_device *lm4f_usbd_init(void)
{
	int i;

	/* Start the USB clock */
	periph_clock_enable(RCC_USB0);
	/* Enable the USB PLL interrupts - used to assert PLL lock */
	SYSCTL_IMC |= (SYSCTL_IMC_USBPLLLIM | SYSCTL_IMC_PLLLIM);
	rcc_usb_pll_on();

	/* Make sure we're disconnected. We'll reconnect later */
	lm4f_usb_soft_disconnect();

	/* Software reset USB */
	SYSCTL_SRUSB = 1;
	for (i = 0; i < 1000; i++) {
		__asm__("nop");
	}
	SYSCTL_SRUSB = 0;

	/*
	 * Wait for the PLL to lock before soft connecting
	 * This will result in a deadlock if the system clock is not setup
	 * correctly (clock from main oscillator).
	 */
	/* Wait for it */
	i = 0;
	while ((SYSCTL_RIS & SYSCTL_RIS_USBPLLLRIS) == 0) {
		i++;
		if (i > 0xffff) {
			return 0;
		}
	}

	/* Now connect to USB */
	lm4f_usb_soft_connect();

	/* No FIFO allocated yet, but the first 64 bytes are still reserved */
	usbd_dev.fifo_mem_top = 64;

	return &usbd_dev;
}

/* What is this thing even good for */
#define RX_FIFO_SIZE 512

const struct _usbd_driver lm4f_usb_driver = {
	.init = lm4f_usbd_init,
	.set_address = lm4f_set_address,
	.ep_setup = lm4f_ep_setup,
	.ep_reset = lm4f_endpoints_reset,
	.ep_stall_set = lm4f_ep_stall_set,
	.ep_stall_get = lm4f_ep_stall_get,
	.ep_nak_set = lm4f_ep_nak_set,
	.ep_write_packet = lm4f_ep_write_packet,
	.ep_read_packet = lm4f_ep_read_packet,
	.poll = lm4f_poll,
	.disconnect = lm4f_disconnect,
	.base_address = USB_BASE,
	.set_address_before_status = false,
	.rx_fifo_size = RX_FIFO_SIZE,
};
/**
 * @endcond
 */

/**
 * @}
 */
