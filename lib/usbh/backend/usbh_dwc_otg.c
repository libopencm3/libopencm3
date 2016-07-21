/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include "dwc_otg-private.h"
#include "../usbh-private.h"
#include <libopencm3/stm32/otg_common.h>
#include <libopencm3/cm3/common.h>
#include <string.h>

#define BACKEND_DATA     ((usbh_dwc_otg_priv *)(host->backend_data))
#define BASE_ADDRESS     (BACKEND_DATA->base_address)
#define RX_FIFO_SIZE     (BACKEND_DATA->fifo_size.rx)
#define TX_NP_FIFO_SIZE  (BACKEND_DATA->fifo_size.tx_np)
#define TX_P_FIFO_SIZE   (BACKEND_DATA->fifo_size.tx_p)
#define CHANNELS_COUNT   (BACKEND_DATA->channels_count)
#define CHANNELS_ITEM(i) (&BACKEND_DATA->channels[i])


#define REBASE(x)        MMIO32(BASE_ADDRESS + (x))
#define REBASE_FIFO(i)   (&REBASE(OTG_FIFO(i)))

/* as per specs, 10ms to 20ms */
#define RESET_HOLD_DURATION (MS2US(10))  /* unit: microseconds (us) */

#define PREFIX_FRAME_NUM LOGF("[FRAME %"PRIu16"]: ",					\
	(uint16_t)REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK);			\

/**
 * Calculate packet count from data length ( @a len) and endpoint size ( @a ep_size)
 * @param len Data length (packet length)
 * @param ep_size Endpoint size
 * @return packet count
 */
#define CALC_PKTCNT(transfer_len, ep_size) \
	(((transfer_len) > 0) ? DIV_AND_CEIL((transfer_len), (ep_size)) : 1)

/**
 * Return result based on @a value which is a multiple of 4.
 * This will return value greater than or equal @a value.
 * @param value Value (should be >= 0)
 * @return 0 if @a value is 0
 * @return multiple equal/heigher of 4
 *
 * @test NEXT_MULT_OF_4(1) == 4
 * @test NEXT_MULT_OF_4(3) == 4
 * @test NEXT_MULT_OF_4(4) == 4
 * @test NEXT_MULT_OF_4(6) == 8
 *
 * @note same as (value % 4) ? (value + 4 - (value % 4))
 */
#define NEXT_MULT_OF_4(v) \
	(((v) & 0x3) ? (((v) | 0x3) + 1) : (v))

/**
 * For IN endpoint,
 *   XFRSIZ should be equal to pktcnt * word-aligned-ep-size
 *
 * For OUT endpoint,
 *   XFRSIZ should be equal to number of bytes the application want to transmit
 *   XFRSIZ = transfer_len
 *
 * @param out true if OUT endpoint
 * @param pktcnt Packet count
 * @param transfer_len Number of bytes to transfer
 * @param ep_size Endpoint size
 */
/* #define CALC_XFRSIZ(out, pktcnt, transfer_len, ep_size)						\
	((out) ? (transfer_len) :												\
		(((transfer_len) > 0) ? ((pktcnt) * NEXT_MULT_OF_4((ep_size))) :  0)) */

/* for in endpoint, even if xfrsiz is not multiple of ep_size, it seems to work.
 *   > The application is expected to program this field as
 *   > an integer multiple of the maximum packet size for IN
 *   > transactions (periodic and non-periodic).
 *  do NOT seems to cause any problem!
 *
 * for out endpoint, xfrsiz = transfer_len
 */
#define CALC_XFRSIZ(out, pktcnt, transfer_len, ep_size)	(transfer_len)

static void handle_rxflvl_interrupt(usbh_host *host);
static void process_channel_interrupt(usbh_host *host, uint8_t i);
static int get_any_free_channel(usbh_host *host);

static void control_setup_stage(usbh_host *host, uint8_t i);
static void control_data_stage(usbh_host *host, uint8_t i);
static void control_status_stage(usbh_host *host, uint8_t i);

static void fifo_to_memory(volatile uint32_t *fifo, void *mem,
		unsigned bytes);
static void memory_to_fifo(const void *mem, volatile uint32_t *fifo,
		unsigned bytes);

#if defined(USBH_DEBUG)
const char *chan_state[] = {
	[USBH_DWC_OTG_CHAN_STATE_FREE] = "FREE",
	[USBH_DWC_OTG_CHAN_STATE_CANCELLED] = "CANCELLED",
	[USBH_DWC_OTG_CHAN_STATE_CTRL_SETUP] = "SETUP",
	[USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_IN] = "DATA_IN",
	[USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_OUT] = "DATA_OUT",
	[USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_IN] = "STATUS_IN",
	[USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_OUT] = "STATUS_OUT",
	[USBH_DWC_OTG_CHAN_STATE_CALLBACK] = "CALLBACK",
};
#endif

static void core_reset(usbh_host *host)
{
	/* Wait AHB idle condition.*/
	while (!(REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_AHBIDL));

	/* Core reset and delay of at least 3 PHY cycles.*/
	REBASE(OTG_GRSTCTL) = OTG_GRSTCTL_CSRST;
	while (REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_CSRST);

	/* Wait AHB idle condition.*/
	while (!(REBASE(OTG_GRSTCTL) & OTG_GRSTCTL_AHBIDL));
}

void usbh_dwc_otg_init(usbh_host *host)
{
	core_reset(host);
	REBASE(OTG_GUSBCFG) = OTG_GUSBCFG_FHMOD | OTG_GUSBCFG_PHYSEL;
	REBASE(OTG_PCGCCTL) = 0; /* Restart the PHY clock. */
	REBASE(OTG_GINTSTS) = 0xFFFFFFFF;
	REBASE(OTG_HPRT) |= OTG_HPRT_PPWR;
	REBASE(OTG_GCCFG) = OTG_GCCFG_PWRDWN | OTG_GCCFG_NOVBUSSENS |
						OTG_GCCFG_VBUSASEN | OTG_GCCFG_VBUSBSEN;

	LOG_LN("DWC_OTG init complete");
}

/**
 * Reset all channels
 * @param host USB Host
 */
static void reset_channels(usbh_host *host)
{
	LOG_LN("reseting all channels");

	for (unsigned i = 0; i < CHANNELS_COUNT; i++) {
		usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
		ch->state = USBH_DWC_OTG_CHAN_STATE_CANCELLED;

		if (ch->urb != NULL) {
			ch->urb->backend_tag = INVALID_BACKEND_TAG;
			ch->urb = NULL;
		}

		REBASE(OTG_HCINTMSK(i)) = OTG_HCINTMSK_CHHM;
		REBASE(OTG_HCINT(i)) = 0xFFF;
		REBASE(OTG_HCTSIZ(i)) = 0;
		REBASE(OTG_HCCHAR(i)) = OTG_HCCHAR_CHENA | OTG_HCCHAR_CHDIS;
	}
}

/**
 * Configure and flush the FIFO.
 * @param host USB Host
 */
static void prepare_fifo(usbh_host *host)
{
	LOG_LN("Preparing FIFO");

	/* Configure FIFO */
	REBASE(OTG_GRXFSIZ) = RX_FIFO_SIZE;
	REBASE(OTG_GNPTXFSIZ) = (TX_NP_FIFO_SIZE << 16) | RX_FIFO_SIZE;
	REBASE(OTG_HPTXFSIZ) = (TX_P_FIFO_SIZE << 16) | (RX_FIFO_SIZE + TX_NP_FIFO_SIZE);

	/* Flush RX, TX FIFO */
	REBASE(OTG_GRSTCTL) = OTG_GRSTCTL_RXFFLSH |
		(OTG_GRSTCTL_TXFFLSH | OTG_GRSTCTL_TXFNUM_ALL);
	while (REBASE(OTG_GRSTCTL) & (OTG_GRSTCTL_RXFFLSH | OTG_GRSTCTL_TXFFLSH));
}

/**
 * Perform channel scheduling.
 * All channel that are marked as "need_scheduling" are scheduled when they
 *  reach the appropriate frame.
 * On reaching the appropriate frame, just enable the channel.
 *  (it assumes that data is already there in FIFO)
 *
 * periodic transfer (interrup and isochronous) can be enabled in frame before
 *  "submit_frame" because ODD/EVEN bit will make sure that the transmission
 *   is done "submit_frame" frame.
 *
 * transfer (periodic and non-periodic) are always enabled in frame
 *  which are equal or greater than "submit_frame".
 *
 * On downside of this design is that, if interval (only used for isochronous
 *  and interrupt endpoint) is too large, it can increase the frame 14bit
 *  value make it think that the frame has not reached.
 *
 * for the design to work, interval should be less than 0x1FFF.
 *  (most of the time large interval are not a problem)
 *
 * interval >= 0x3E8 [0x3E8 = 1000, 1 second for FS] should never be required
 * interval >= 0x1F40 [0x1F40 = 1000, 1 second for HS] should never be required
 */
static void schedule_channels(usbh_host *host)
{
	for (unsigned i = 0; i < CHANNELS_COUNT; i++) {
		usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);

		if (!ch->need_scheduling) {
			continue;
		}

		/* we are using range because in case the poll is performed after the
		 *  the submit frame (example: proper polling not done),
		 *  it can gracefully handle and enable the channel.
		 *  0x1FFF is chosen because it is half of 0x3FFF.
		 *
		 * This method will fail if large interval value is used for
		 *  isochronous or interrupt endpoint. */
		uint16_t low = ch->submit_frame;
		uint16_t upper = (ch->submit_frame + 0x1FFF) & 0x3FFF;

		usbh_transfer *transfer = &ch->urb->transfer;
		if (transfer->ep_type == USBH_EP_INTERRUPT ||
			transfer->ep_type == USBH_EP_ISOCHRONOUS) {
			/* we can enable the endpoint even before the submit_frame
			 *  because ODD/EVEN bit will do trick of sending it in right frame
			 */
			low = low ? (low - 1) : 0x3FFF;
		}

		uint16_t current_frame = REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK;
		bool perform_enable = false;

		/* check if the current frame falls in the range of low and upper */

		if (low < upper) {
			/* upper has not overflow'd due to addition of 0x1FFF */
			if (current_frame >= low && current_frame <= upper) {
				perform_enable = true;
			}
		} else {
			/* upper has overflow'd due to addition of 0x1FFF */
			if (current_frame >= low || current_frame <= upper) {
				perform_enable = true;
			}
		}

		if (perform_enable) {
			PREFIX_FRAME_NUM
			LOGF_LN("re-enabling channel %"PRIu8 " in frame %"PRIu16, i,
				current_frame);
			ch->need_scheduling = false;
			REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_CHENA;
		}
	}
}

/** @copydoc usbh_backend::poll() */
void usbh_dwc_otg_poll(usbh_host *host, uint64_t now)
{
	/* Check if a new device has been connected.
	 * If yes, then enable reset sequence for duration between 10ms to 20ms */
	if (REBASE(OTG_HPRT) & OTG_HPRT_PCDET) {
		/* Clear PCDET bit and turn reset on */
		BACKEND_DATA->wait_till = now + RESET_HOLD_DURATION;
		REBASE(OTG_HPRT) |= OTG_HPRT_PCDET | OTG_HPRT_PRST;
		LOG_LN("reset sequence enabled");
	}

	/* Check if reset in progress
	 * If yes, after the duration is over, disable the reset */
	if (REBASE(OTG_HPRT) & OTG_HPRT_PRST) {
		if (now >= BACKEND_DATA->wait_till) {
			/* Disable reset sequence */
			REBASE(OTG_HPRT) &= ~OTG_HPRT_PRST;
			LOG_LN("reset sequence disabled");
		} else {
			LOG_LN("reset sequence is in progress");
			return;
		}
	}

	/* Port enable for communication.
	 *  We are ready to communicate with the device! */
	if (REBASE(OTG_HPRT) & OTG_HPRT_PENCHNG) {
		LOG_LN("HPRT.PENCHING bit set");

		/* INCORRECT HARDWARE DOCUMENTATION (STM32F407)
		 * Writing PENA = 1 actually disable the port.
		 * Be cautious while working with HPRT register! */

		if (REBASE(OTG_HPRT) & OTG_HPRT_PENA) {
			/* clear any previous interrupts */
			REBASE(OTG_GINTSTS) = 0xFFFFFFFF;

			switch (REBASE(OTG_HPRT) & OTG_HPRT_PSPD_MASK) {
				uint32_t hcfg, fslspcs, hfir;
				usbh_speed speed;
			case OTG_HPRT_PSPD_FULL:
				LOG_LN("FULL SPEED device connected");
				speed = USBH_SPEED_FULL;
				fslspcs = OTG_HCFG_FSLSPCS_48MHz;
				hfir = 48000;
				goto next_step;
			break;
			case OTG_HPRT_PSPD_LOW:
				LOG_LN("LOW SPEED device connected");
				speed = USBH_SPEED_LOW;
				fslspcs = OTG_HCFG_FSLSPCS_6MHz;
				hfir = 6000;
				goto next_step;
			break;
			default:
				LOG_LN("unknown speed device connected");
			break;
			next_step:
				hcfg = REBASE(OTG_HCFG);
				if ((hcfg & OTG_HCFG_FSLSPCS_MASK) == fslspcs) {
					goto process_device;
				} else {
					goto change_speed;
				}
			break;
			process_device:
				REBASE(OTG_HPRT) &= ~OTG_HPRT_PENA; /* Clear PENCHNG */
				prepare_fifo(host);
				reset_channels(host);
				LOG_LN("Passing the root device to frontend");
				usbh_root_device_connected(host, speed);
			break;
			change_speed:
				LOGF_LN("Changing speed, going for HFIR = %"PRIu32, hfir);
				REBASE(OTG_HCFG) = (hcfg & ~OTG_HCFG_FSLSPCS_MASK) | fslspcs;
				REBASE(OTG_HFIR) = hfir;

				/* Perform reset **without** clearing PENCHNG or PENA bit.
				 *  So, that after reset we can process the same interrupt! */
				REBASE(OTG_HPRT) =
					(REBASE(OTG_HPRT) & ~(OTG_HPRT_PENA | OTG_HPRT_PENCHNG)) |
					OTG_HPRT_PRST;
				BACKEND_DATA->wait_till = now + RESET_HOLD_DURATION;
			break;
			}
		} else {
			/* Clear - port has been disabled due to disconnect
			 *   (or whatever reason) */
			REBASE(OTG_HPRT) &= ~OTG_HPRT_PENA; /* Clear PENCHNG */
		}
	}

	/* Check if device has disconnected */
	if (REBASE(OTG_GINTSTS) & OTG_GINTSTS_DISCINT) {
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_DISCINT;
		LOG_LN("GINTSTS.DISCINT bit set, device disconnected");

		reset_channels(host);
		usbh_root_device_disconnected(host);
	}

	/* re-enabled channels.
	 *  These channels are either disabled due to NAK or next interval.  */
	schedule_channels(host);

	/* process channel rx data */
	while (REBASE(OTG_GINTSTS) & OTG_GINTSTS_RXFLVL) {
		handle_rxflvl_interrupt(host);
	}

	/* process channel events */
	if (REBASE(OTG_GINTSTS) & OTG_GINTSTS_HCINT) {
		for (unsigned i = 0; i < CHANNELS_COUNT; i++) {
			if (REBASE(OTG_HAINT) & (1 << i)) {
				process_channel_interrupt(host, i);
			}
		}
	}

#if defined(USBH_DEBUG)
	if (REBASE(OTG_GINTSTS) & OTG_GINTSTS_IPXFR) {
		REBASE(OTG_GINTSTS) = OTG_GINTSTS_IPXFR;
		PREFIX_FRAME_NUM
		LOG_LN("WARNING: IPXFR (Incomplete Periodic transfer)");
	}
#endif
}

/** @copydoc usbh_dwc_host_speed() */
usbh_speed usbh_dwc_otg_speed(usbh_host *host)
{
	LOG_CALL

	switch (REBASE(OTG_HPRT) & OTG_HPRT_PSPD_MASK) {
	case OTG_HPRT_PSPD_LOW: return USBH_SPEED_LOW;
	case OTG_HPRT_PSPD_FULL: return USBH_SPEED_FULL;
	case OTG_HPRT_PSPD_HIGH: return USBH_SPEED_HIGH;
	default: return USBH_SPEED_UNKNOWN;
	}
}

/** @copydoc usbh_host_reset() */
void usbh_dwc_otg_reset(usbh_host *host)
{
	LOG_CALL

	REBASE(OTG_HPRT) |= OTG_HPRT_PRST;
	BACKEND_DATA->wait_till = host->last_poll + RESET_HOLD_DURATION;
}

/**
 * Get the first channel that is disabled.
 * @param host USB Host
 * @return index (>= 0) on success
 * @return -1 on failure
 */
static int get_any_free_channel(usbh_host *host)
{
	LOG_CALL

	for (unsigned i = 0; i < CHANNELS_COUNT; i++) {
		usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
		if (ch->state == USBH_DWC_OTG_CHAN_STATE_FREE) {
			LOGF_LN("channel %"PRIu8" is free for use", i);
			return i;
		}
	}

	LOG_LN("no free channel found");
	return -1;
}

/**
 * Write more data from URB to FIFO.
 * @param ch DWC OTG Channel data
 *
 * @warning This function should only be called for
 *  transfer that have data to send to device.
 */
static void push_packet_to_fifo(usbh_dwc_otg_chan *ch)
{
	usbh_urb *urb = ch->urb;
	usbh_transfer *transfer = &urb->transfer;
	usbh_host *host = transfer->device->host;

	uint16_t len = transfer->length - transfer->transferred;
	len = MIN(len, transfer->ep_size);

	if (!len) {
		LOGF_LN("Nothing more to transmit (intending ZLP?) for URB %"PRIu64, urb->id);
		return;
	}

	void *data = usbh_urb_get_data_pointer(urb, len);
	volatile uint32_t *fifo = REBASE_FIFO(urb->backend_tag) + RX_FIFO_SIZE;

	/* Periodic */
	if (transfer->ep_type == USBH_EP_INTERRUPT ||
			transfer->ep_type == USBH_EP_ISOCHRONOUS) {
		fifo += TX_NP_FIFO_SIZE;
	}

	memory_to_fifo(data, fifo, len);
	usbh_urb_inc_data_pointer(urb, len);
}

/**
 * Perform SETUP stage for Control transfer
 * After this, control transfer will either goto data or status stage
 * @param host USB Host
 * @param i DWC OTG channel number
 */
static void control_setup_stage(usbh_host *host, uint8_t i)
{
	LOG_CALL

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	usbh_transfer *transfer = &ch->urb->transfer;
	usbh_device *dev = transfer->device;
	struct usb_setup_data *setup = &transfer->setup;

	ch->state = USBH_DWC_OTG_CHAN_STATE_CTRL_SETUP;
	ch->need_scheduling = false;
	ch->submit_frame = REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK;

	REBASE(OTG_HCINT(i)) = 0xFFF;
	REBASE(OTG_HCINTMSK(i)) = 0xFFF;
	REBASE(OTG_HCTSIZ(i)) = OTG_HCTSIZ_DPID_MDATA | (1 << 19) | 8;
	REBASE(OTG_HCCHAR(i)) =
		OTG_HCCHAR_CHENA |
		(OTG_HCCHAR_DAD_MASK & (dev->address << 22)) |
		OTG_HCCHAR_MCNT_1 |
		OTG_HCCHAR_EPTYP_CONTROL |
		(dev->speed == USBH_SPEED_LOW ? OTG_HCCHAR_LSDEV : 0x00) |
		OTG_HCCHAR_EPDIR_OUT |
		(OTG_HCCHAR_EPNUM_MASK & (transfer->ep_addr << 11)) |
		(OTG_HCCHAR_MPSIZ_MASK & transfer->ep_size);

	volatile uint32_t *fifo = REBASE_FIFO(i) + RX_FIFO_SIZE;
	memory_to_fifo(setup, fifo, 8);
}

/**
 * Perform DATA_IN/DATA_OUT for control transfer.
 * After this, will proceed to control STATUS_OUT/STATUS_IN (respectively)
 * @param host USB Host
 * @param i DWC OTG channel number
 */
static void control_data_stage(usbh_host *host, uint8_t i)
{
	LOG_CALL

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	usbh_transfer *transfer = &ch->urb->transfer;
	usbh_device *dev = transfer->device;

	bool host2dev = !(transfer->setup.bmRequestType & USB_REQ_TYPE_DIRECTION);
	ch->state = host2dev ?
		USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_OUT :
		USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_IN;
	ch->need_scheduling = false;
	ch->submit_frame = REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK;

	uint16_t pktcnt = CALC_PKTCNT(transfer->length, transfer->ep_size);
	uint32_t xfrsiz = CALC_XFRSIZ(out, pktcnt, transfer->length, transfer->ep_size);

	REBASE(OTG_HCTSIZ(i)) =
		OTG_HCTSIZ_DPID_DATA1 |
		(OTG_HCTSIZ_PKTCNT_MASK & (pktcnt << 19)) |
		(OTG_HCTSIZ_XFRSIZ_MASK & xfrsiz);

	REBASE(OTG_HCCHAR(i)) =
		OTG_HCCHAR_CHENA |
		(OTG_HCCHAR_DAD_MASK & (dev->address << 22)) |
		OTG_HCCHAR_MCNT_1 |
		OTG_HCCHAR_EPTYP_CONTROL |
		(dev->speed == USBH_SPEED_LOW ? OTG_HCCHAR_LSDEV : 0x00) |
		(host2dev ? OTG_HCCHAR_EPDIR_OUT : OTG_HCCHAR_EPDIR_IN) |
		(OTG_HCCHAR_EPNUM_MASK & (transfer->ep_addr << 11)) |
		(OTG_HCCHAR_MPSIZ_MASK & transfer->ep_size);

	if (host2dev) {
		push_packet_to_fifo(ch);
	}
}

/**
 * Perform STATUS_OUT/STATUS_IN for control transfer.
 * After this, will proceed to control DONE
 * @param host USB Host
 * @param i DWC OTG channel number
 */
static void control_status_stage(usbh_host *host, uint8_t i)
{
	LOG_CALL

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	usbh_transfer *transfer = &ch->urb->transfer;
	usbh_device *dev = transfer->device;

	bool host2dev = !(transfer->setup.bmRequestType & USB_REQ_TYPE_DIRECTION);
	ch->state = host2dev ?
		USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_IN :
		USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_OUT;
	ch->submit_frame = REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK;
	ch->need_scheduling = false;

	REBASE(OTG_HCTSIZ(i)) = OTG_HCTSIZ_DPID_DATA1 | 1 << 19 | 0;

	REBASE(OTG_HCCHAR(i)) =
		OTG_HCCHAR_CHENA |
		(OTG_HCCHAR_DAD_MASK & (dev->address << 22)) |
		OTG_HCCHAR_MCNT_1 |
		OTG_HCCHAR_EPTYP_CONTROL |
		(dev->speed == USBH_SPEED_LOW ? OTG_HCCHAR_LSDEV : 0x00) |
		(!host2dev ? OTG_HCCHAR_EPDIR_OUT : OTG_HCCHAR_EPDIR_IN) |
		(OTG_HCCHAR_EPNUM_MASK & (transfer->ep_addr << 11)) |
		(OTG_HCCHAR_MPSIZ_MASK & transfer->ep_size);
}

/**
 * Perform bulk transfer on the @a i channel
 * @param host USB Host
 * @param i DWC OTG channel number
 */
static void bulk_transfer(usbh_host *host, uint8_t i)
{
	/* FIXME: function not tested! */
	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	usbh_transfer *transfer = &ch->urb->transfer;
	usbh_device *dev = transfer->device;

	bool out = IS_OUT_ENDPOINT(transfer->ep_addr);
	bool dtog = !!(dev->dtog & ep_dtog_mask(transfer->ep_addr));
	uint16_t pktcnt = CALC_PKTCNT(transfer->length, transfer->ep_size);
	uint32_t xfrsiz = CALC_XFRSIZ(out, pktcnt, transfer->length, transfer->ep_size);

	ch->state = USBH_DWC_OTG_CHAN_STATE_CALLBACK;
	ch->need_scheduling = false;
	ch->submit_frame = REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK;

	/* Check if we need to transmit a ZLP (Zero Length Packet) */
	if (out && transfer->length) {
		if ((transfer->flags & USBH_FLAG_ZERO_PACKET) &&
				(pktcnt * transfer->ep_size) == transfer->length) {
			/* There are absolutely N packets with transfer->ep_size.
			 * So, at the end of transfer, transmit a zero length packet. */
			pktcnt += 1;
		}
	}

	REBASE(OTG_HCINT(i)) = 0xFFF;
	REBASE(OTG_HCINTMSK(i)) = 0xFFF;
	REBASE(OTG_HCTSIZ(i)) =
		(dtog ? OTG_HCTSIZ_DPID_DATA1 : OTG_HCTSIZ_DPID_DATA0) |
		(OTG_HCTSIZ_PKTCNT_MASK & (pktcnt << 19)) |
		(OTG_HCTSIZ_XFRSIZ_MASK & xfrsiz);

	REBASE(OTG_HCCHAR(i)) =
		OTG_HCCHAR_CHENA |
		(OTG_HCCHAR_DAD_MASK & (dev->address << 22)) |
		OTG_HCCHAR_MCNT_1 |
		OTG_HCCHAR_EPTYP_BULK |
		(dev->speed == USBH_SPEED_LOW ? OTG_HCCHAR_LSDEV : 0x00) |
		(out ? OTG_HCCHAR_EPDIR_OUT : OTG_HCCHAR_EPDIR_IN) |
		(OTG_HCCHAR_EPNUM_MASK & (transfer->ep_addr << 11)) |
		(OTG_HCCHAR_MPSIZ_MASK & transfer->ep_size);

	if (out) {
		push_packet_to_fifo(ch);
	}
}

/**
 * Perform interrupt transfer on the @a i channel
 * @param host USB Host
 * @param i DWC OTG channel number
 */
static void interrupt_transfer(usbh_host *host, uint8_t i)
{
	/* FIXME: function not tested! */
	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	usbh_transfer *transfer = &ch->urb->transfer;
	usbh_device *dev = transfer->device;

	bool out = IS_OUT_ENDPOINT(transfer->ep_addr);
	bool dtog = !!(dev->dtog & ep_dtog_mask(transfer->ep_addr));
	uint16_t pktcnt = CALC_PKTCNT(transfer->length, transfer->ep_size);
	uint32_t xfrsiz = CALC_XFRSIZ(out, pktcnt, transfer->length, transfer->ep_size);

	ch->state = USBH_DWC_OTG_CHAN_STATE_CALLBACK;
	ch->need_scheduling = false;
	ch->submit_frame = REBASE(OTG_HFNUM) & OTG_HFNUM_FRNUM_MASK;
	ch->submit_frame += 1; /* transferred in next frame for first time */
	ch->submit_frame &= 0x3FFF;

	REBASE(OTG_HCINT(i)) = 0xFFF;
	REBASE(OTG_HCINTMSK(i)) = 0xFFF;
	REBASE(OTG_HCTSIZ(i)) =
		(dtog ? OTG_HCTSIZ_DPID_DATA1 : OTG_HCTSIZ_DPID_DATA0) |
		(OTG_HCTSIZ_PKTCNT_MASK & (pktcnt << 19)) |
		(OTG_HCTSIZ_XFRSIZ_MASK & xfrsiz);

	REBASE(OTG_HCCHAR(i)) =
		OTG_HCCHAR_CHENA |
		(OTG_HCCHAR_DAD_MASK & (dev->address << 22)) |
		OTG_HCCHAR_MCNT_1 |
		((ch->submit_frame & 0x1) ? OTG_HCCHAR_ODDFRM : 0x00) |
		OTG_HCCHAR_EPTYP_INTERRUPT |
		(dev->speed == USBH_SPEED_LOW ? OTG_HCCHAR_LSDEV : 0x00) |
		(out ? OTG_HCCHAR_EPDIR_OUT : OTG_HCCHAR_EPDIR_IN) |
		(OTG_HCCHAR_EPNUM_MASK & (transfer->ep_addr << 11)) |
		(OTG_HCCHAR_MPSIZ_MASK & transfer->ep_size);

	if (out) {
		push_packet_to_fifo(ch);
	}
}

/**
 * Process the URB and prepare some channel for transfer
 * If no channel are currently free, ignore the call.
 * @param host USB Host
 * @param urb USB Request Block
 */
void usbh_dwc_otg_transfer_submit(usbh_host *host, usbh_urb *urb)
{
	LOG_CALL

	int i = get_any_free_channel(host);
	if (i == -1) {
		return;
	}

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	urb->backend_tag = i;
	ch->urb = urb;

	LOGF_LN("Channel %"PRIu8" assigned to URB %"PRIu64, i, urb->id);

	switch (urb->transfer.ep_type) {
	case USBH_EP_CONTROL:
		control_setup_stage(host, i);
	break;
	case USBH_EP_BULK:
		bulk_transfer(host, i);
	break;
	case USBH_EP_INTERRUPT:
		interrupt_transfer(host, i);
	break;
	case USBH_EP_ISOCHRONOUS:
		/* TODO */
	break;
	}
}

/**
 * The URB has been cancelled. Remove any backend allocated resource to @a urb
 * @param host USB Host
 * @param urb USB Request Block
 */
void usbh_dwc_otg_transfer_cancel(usbh_host *host, usbh_urb *urb)
{
	LOG_CALL

	if (urb->backend_tag == INVALID_BACKEND_TAG) {
		LOG_LN("requesting to cancel a URB with invalid channel assigned");
		return;
	}

	uint8_t i = urb->backend_tag;
	urb->backend_tag = INVALID_BACKEND_TAG;

	LOGF_LN("channel %"PRIu8" cancelled with state = %s", i,
		chan_state[CHANNELS_ITEM(i)->state]);

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	ch->urb = NULL;
	ch->state = USBH_DWC_OTG_CHAN_STATE_CANCELLED;
	ch->need_scheduling = false;

	REBASE(OTG_HCINTMSK(i)) = OTG_HCINTMSK_CHHM;
	REBASE(OTG_HCINT(i)) = 0xFFF;
	REBASE(OTG_HCTSIZ(i)) = 0;
	REBASE(OTG_HCCHAR(i)) = OTG_HCCHAR_CHENA | OTG_HCCHAR_CHDIS;
}

/**
 * A channel will revolve around this function
 * For Control, it will go setup->data->status->callback
 * For bulk/isochronous/interrupt will go data->callback
 * @param host USB Host
 * @param i DWC OTG channel number
 */
static void process_channel_interrupt(usbh_host *host, uint8_t i)
{
	LOG_CALL

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);

	if (REBASE(OTG_HCINT(i)) & OTG_HCINT_CHH) {
		LOGF_LN("got CHH for channel %"PRIu8, i);

		REBASE(OTG_HCINT(i)) = OTG_HCINT_CHH;

		if (ch->state != USBH_DWC_OTG_CHAN_STATE_CANCELLED) {
			PREFIX_FRAME_NUM
			LOGF_LN("cleared CHH for channel %"PRIu8
				" (without freeing channel)"
				" since channel is not in cancelled state", i);
			return;
		}

		LOGF_LN("channel %"PRIu8" marked as free", i);
		ch->state = USBH_DWC_OTG_CHAN_STATE_FREE;
		REBASE(OTG_HCINTMSK(i)) = 0;
		return;
	}

	switch (ch->state) {
	case USBH_DWC_OTG_CHAN_STATE_FREE:
		LOGF_LN("got callback for free channel %"PRIu8, i);
	return;
	case USBH_DWC_OTG_CHAN_STATE_CANCELLED:
		LOGF_LN("got callback for cancelled channel %"PRIu8, i);
	return;
	default:
	break;
	}

	if (REBASE(OTG_HCINT(i)) & OTG_HCINT_NAK) {
		/* retry, we only got NAK */

		usbh_transfer *transfer = &ch->urb->transfer;
		switch (transfer->ep_type) {
		case USBH_EP_BULK:
		case USBH_EP_CONTROL:
			/* enable the channel for retry */
			REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_CHENA;
		break;
		case USBH_EP_INTERRUPT:
		case USBH_EP_ISOCHRONOUS:
			ch->submit_frame += transfer->interval;
			ch->submit_frame &= 0x3FFF;

			if (ch->submit_frame & 0x1) {
				REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_ODDFRM;
			} else {
				REBASE(OTG_HCCHAR(i)) &= ~OTG_HCCHAR_ODDFRM;
			}

			if (transfer->interval > 1) {
				/* Channel will be enabled on next applicable frame.
				 *  till then the channel is not enabled.
				 *  and is marked for scheduling */
				PREFIX_FRAME_NUM
				LOGF_LN("channel %"PRIu8" got NAK, retry after "
					"interval = %"PRIu16" and at frame = %"PRIu16, i,
					transfer->interval, ch->submit_frame);
				ch->need_scheduling = true;
			} else {
				/* Enabling the channel right here because packet will
				 *  be transferred on next frame.
				 * ODD/EVEN frame bit will make sure that the transfer is done
				 *  in next frame. */
				REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_CHENA;
			}
		break;
		}

		REBASE(OTG_HCINT(i)) = OTG_HCINT_NAK;
		LOGF_LN("got NAK for channel %"PRIu8, i);
		return;
	}

	if (REBASE(OTG_HCINT(i)) & OTG_HCINT_ACK) {
		usbh_transfer *transfer = &ch->urb->transfer;

		/* toggle the dtog */
		if (IS_OUT_ENDPOINT(transfer->ep_addr)) {
			/* Toggle the DTOG.
			 *  for IN endpoint, handle_rxflvl_interrupt update the DTOG */
			transfer->device->dtog ^= ep_dtog_mask(transfer->ep_addr);
		}

		switch (transfer->ep_type) {
		case USBH_EP_CONTROL:
			if (ch->state == USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_OUT) {
				goto send_more;
			}
		break;
		case USBH_EP_BULK:
			if (IS_OUT_ENDPOINT(transfer->ep_addr)) {
				goto send_more;
			}
		break;
		case USBH_EP_INTERRUPT:
		case USBH_EP_ISOCHRONOUS:
			/* next packet will be transmitted in next applicable frame. */
			/* ch->need_scheduling = true; */
			ch->submit_frame += transfer->interval;
			ch->submit_frame &= 0x3FFF;
			if (ch->submit_frame & 0x1) {
				REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_ODDFRM;
			} else {
				REBASE(OTG_HCCHAR(i)) &= ~OTG_HCCHAR_ODDFRM;
			}

			if (transfer->interval > 1 &&
					/* we have more packets to send? */
					REBASE(OTG_HCTSIZ(i)) & OTG_HCTSIZ_PKTCNT_MASK) {
				/* we need to wait for the appropriate frame to come.
				 *  till then, the channel is disabled and is marked for
				 *  scheduling. */
				ch->need_scheduling = true;
				PREFIX_FRAME_NUM
				LOGF_LN("channel %"PRIu8" got ACK, resume transfer after "
					"interval = %"PRIu16" and at frame = %"PRIu16, i,
					transfer->interval, ch->submit_frame);
				REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_CHENA | OTG_HCCHAR_CHDIS;
			}

			/* We are submitting data here so that on the next applicable frame
			 *   channel can just directly enable to transmit data. */
			if (IS_OUT_ENDPOINT(transfer->ep_addr)) {
				goto send_more;
			}
		break;
		send_more:
			push_packet_to_fifo(ch);
		break;
		}

		REBASE(OTG_HCINT(i)) = OTG_HCINT_ACK;
		LOGF_LN("got ACK for channel %"PRIu8, i);
		return;
	}

	static const struct {
		uint32_t bit_mask;
		usbh_transfer_status status;
		const char *name;
	} error_cond[] = {
		{OTG_HCINT_STALL, USBH_ERR_STALL, "STALL"},
		{OTG_HCINT_DTERR, USBH_ERR_DTOG, "DTERR"},
		{OTG_HCINT_BBERR, USBH_ERR_BABBLE, "BBERR"},
		{OTG_HCINT_FRMOR, USBH_ERR_IO, "FRMOR"},
		{OTG_HCINT_TXERR, USBH_ERR_IO, "TXERR"},
		{0}
	};

	/* handle multiple error bits with same code */
	for (unsigned j = 0; error_cond[j].bit_mask; j++) {
		if (REBASE(OTG_HCINT(i)) & error_cond[j].bit_mask) {
			LOGF_LN("got %s for channel %"PRIu8, error_cond[j].name, i);
			REBASE(OTG_HCINT(i)) = error_cond[j].bit_mask;
			usbh_urb_free(ch->urb, error_cond[j].status);
			return;
		}
	}

	/* TODO: NYET not handled */

	LOGF_LN("success, channel %"PRIu8" in %s state. "
		"now we will move to next state", i, chan_state[ch->state]);
	REBASE(OTG_HCINT(i)) = OTG_HCINT_XFRC;

	/* lets move the channel to next state! */
	switch (ch->state) {
	case USBH_DWC_OTG_CHAN_STATE_CTRL_SETUP:
		if (ch->urb->transfer.setup.wLength) {
			/* place request for data */
			LOGF_LN("moving channel %"PRIu8" from setup to data stage", i);
			control_data_stage(host, i);
			break;
		}
	case USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_IN:
	case USBH_DWC_OTG_CHAN_STATE_CTRL_DATA_OUT:
		/* place request to read 0 byte packet */
		LOGF_LN("moving channel %"PRIu8" from state %s to status stage",
			i, (ch->state == USBH_DWC_OTG_CHAN_STATE_CTRL_SETUP) ?
				"setup" : "data");
		control_status_stage(host, i);
	break;
	case USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_IN:
	case USBH_DWC_OTG_CHAN_STATE_CTRL_STATUS_OUT:
	case USBH_DWC_OTG_CHAN_STATE_CALLBACK: {
		LOGF_LN("backend marked urb %"PRIu64" as success (channel %"PRIu8")",
			ch->urb->id, i);
		usbh_urb_free(ch->urb, USBH_SUCCESS);
	} break;
	case USBH_DWC_OTG_CHAN_STATE_FREE:
		LOG_LN("WARN: channel is in free state");
	break;
	case USBH_DWC_OTG_CHAN_STATE_CANCELLED:
		LOG_LN("WARN: channel is in cancelled state");
	break;
	}
}

/**
 * Handle the RXFLVL interrupt.
 * This interrupt is called when their is data in FIFO.
 * In order to know target channel, we need to pop GRXSTS
 *  and get the data length and channel number to proceed to data copying.
 * @param host USB Host
 */
static void handle_rxflvl_interrupt(usbh_host *host)
{
	LOG_CALL

	uint32_t rxstsp = REBASE(OTG_GRXSTSP);
	uint8_t i = rxstsp & OTG_GRXSTSP_EPNUM_MASK;
	uint16_t len = (rxstsp & OTG_GRXSTSP_BCNT_MASK) >> 4;

#if defined(USBH_DEBUG)
	const char *map_pktsts[] = {
		[0] = "RESERVED_0",
		[1] = "GOUTNAK",
		[2] = "IN",
		[3] = "IN_COMP",
		[4] = "SETUP_COMP",
		[5] = "DTERR",
		[6] = "SETUP",
		[7] = "CHH",
		[8] = "RESERVED_8",
		[9] = "RESERVED_9",
		[10] = "RESERVED_10",
		[11] = "RESERVED_11",
		[12] = "RESERVED_12",
		[13] = "RESERVED_13",
		[14] = "RESERVED_14",
		[15] = "RESERVED_15"
	};
	PREFIX_FRAME_NUM
	LOGF_LN("GRXSTSP: rxstsp = %s, epnum = %"PRIu8", bcnt = %"PRIu16,
		map_pktsts[(rxstsp & OTG_GRXSTSP_PKTSTS_MASK) >> 17], i, len);
#endif

	if ((rxstsp & OTG_GRXSTSP_PKTSTS_MASK) != OTG_GRXSTSP_PKTSTS_IN || !len) {
		return;
	}

	usbh_dwc_otg_chan *ch = CHANNELS_ITEM(i);
	usbh_urb *urb = ch->urb;
	usbh_transfer *transfer = &urb->transfer;

	if ((transfer->flags & USBH_FLAG_NO_SHORT_PACKET) &&
			(len < transfer->ep_size)) {
		/* We got a short packet but "NO_SHORT_PACKET" flag
		 *  told says that if we get any, report it as error */

		LOGF_LN("got a short packet on channel %"PRIu8
			" and NO_SHORT_PACKET flag is set", i);

		/* TODO: We need to manually flush these? */
		volatile uint32_t *fifo = REBASE_FIFO(i);
		for (unsigned j = 0; j < len; i += 4) {
			*fifo;
		}

		usbh_urb_free(urb, USBH_ERR_SHORT_PACKET);
		return;
	}

	/* If transfer not complete, Enable channel to continue. */
	if (REBASE(OTG_HCTSIZ(i)) & OTG_HCTSIZ_PKTCNT_MASK) {
		REBASE(OTG_HCCHAR(i)) |= OTG_HCCHAR_CHENA;
	}

	/* read from FIFO and copy to data */
	void *data = usbh_urb_get_data_pointer(urb, len);
	volatile uint32_t *fifo = REBASE_FIFO(i);
	fifo_to_memory(fifo, data, len);
	usbh_urb_inc_data_pointer(urb, len);

	/* Toggle in DTOG (IN only, OUT is done in process_channel_interrupt()) */
	transfer->device->dtog ^= ep_dtog_mask(transfer->ep_addr);
}

/**
 * Copy @a bytes count from FIFO ( @a fifo) to memory @a mem
 * @param fifo FIFO pointer
 * @param mem Memory pointer
 * @param bytes Number of bytes to copy
 * @note @a fifo will only be accessed in 32bit
 * @note @a mem should be 8bit, 16bit and 32bit accessible
 */
static void fifo_to_memory(volatile uint32_t *fifo, void *mem,
			unsigned bytes)
{
	LOG_CALL

	uint32_t *mem32 = mem;
	while (bytes >= 4) {
		bytes -= 4;
		*mem32++ = *fifo;
	}

	if (bytes) {
		/* remaining data (less than 4bytes) */
		uint32_t extra = *fifo;
		uint8_t *extra8 = (uint8_t *) &extra;
		uint8_t *mem8 = (uint8_t *) mem32;
		while (bytes > 0) {
			bytes -= 1;
			*mem8++ = *extra8++;
		}
	}
}

/**
 * Copy @a bytes count from memory ( @a mem) to FIFO ( @a fifo)
 * @param mem Memory pointer
 * @param fifo FIFO pointer
 * @param bytes Number of bytes to copy
 * @note @a fifo and @a mem will only be accessed in 32bit
 */
static void memory_to_fifo(const void *mem, volatile uint32_t *fifo,
			unsigned bytes)
{
	LOG_CALL

	const uint32_t *mem32 = mem;
	for (unsigned j = 0; j < bytes; j += 4) {
		*fifo = *mem32++;
	}
}
