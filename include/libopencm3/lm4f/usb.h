/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/** @defgroup usb_defines USB Controller
 *
 * @brief <b>Defined Constants and Types for the LM4F USB Controller</b>
 *
 * @ingroup LM4Fxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 *
 * @date 15 May 2013
 *
 * LGPL License Terms @ref lgpl_license
 */


#ifndef LIBOPENCM3_LM4F_USB_H
#define LIBOPENCM3_LM4F_USB_H

/**@{*/

#include <libopencm3/lm4f/memorymap.h>
#include <libopencm3/cm3/common.h>

/* ============================================================================
 * USB registers
 * --------------------------------------------------------------------------*/

/* USB Device Functional Address */
#define USB_FADDR			MMIO8(USB_BASE + 0x00)

/* USB Power */
#define USB_POWER			MMIO8(USB_BASE + 0x01)

/* USB Transmit Interrupt Status */
#define USB_TXIS			MMIO16(USB_BASE + 0x02)

/* USB Receive Interrupt Status */
#define USB_RXIS			MMIO16(USB_BASE + 0x04)

/* USB Transmit Interrupt Enable */
#define USB_TXIE			MMIO16(USB_BASE + 0x06)

/* USB Receive Interrupt Enable */
#define USB_RXIE			MMIO16(USB_BASE + 0x08)

/* USB General Interrupt Status */
#define USB_IS				MMIO8(USB_BASE + 0x0A)

/* USB Interrupt Enable */
#define USB_IE				MMIO8(USB_BASE + 0x0B)

/* USB Frame Value */
#define USB_FRAME			MMIO16(USB_BASE + 0x0C)

/* USB Endpoint Index */
#define USB_EPIDX			MMIO8(USB_BASE + 0x0E)

/* USB Test Mode */
#define USB_TEST			MMIO8(USB_BASE + 0x0F)

/* USB FIFO Endpoint [0-7] */
#define USB_FIFO8(n)			MMIO8(USB_BASE + 0x20 + (n)*0x04)
#define USB_FIFO16(n)			MMIO16(USB_BASE + 0x20 + (n)*0x04)
#define USB_FIFO32(n)			MMIO32(USB_BASE + 0x20 + (n)*0x04)

/* USB Transmit Dynamic FIFO Sizing */
#define USB_TXFIFOSZ			MMIO8(USB_BASE + 0x62)

/* USB Receive Dynamic FIFO Sizing */
#define USB_RXFIFOSZ			MMIO8(USB_BASE + 0x63)

/* USB Transmit FIFO Start Address */
#define USB_TXFIFOADD			MMIO16(USB_BASE + 0x64)

/* USB Receive FIFO Start Address */
#define USB_RXFIFOADD			MMIO16(USB_BASE + 0x66)

/* USB Connect Timing */
#define USB_CONTIM			MMIO8(USB_BASE + 0x7A)

/* USB Full-Speed Last Transaction to End of Frame Timing */
#define USB_FSEOF			MMIO8(USB_BASE + 0x7D)

/* USB Low-Speed Last Transaction to End of Frame Timing */
#define USB_LSEOF			MMIO8(USB_BASE + 0x7E)

/* USB Control and Status Endpoint 0 Low */
#define USB_CSRL0			MMIO8(USB_BASE + 0x102)

/* USB Control and Status Endpoint 0 High */
#define USB_CSRH0			MMIO8(USB_BASE + 0x103)

/* USB Receive Byte Count Endpoint 0 */
#define USB_COUNT0			MMIO8(USB_BASE + 0x108)

/* USB Maximum Transmit Data Endpoint [1-7] */
#define USB_TXMAXP(n)			MMIO16(USB_BASE + 0x100 + (n)*0x10)

/* USB Transmit Control and Status Endpoint [1-7] Low */
#define USB_TXCSRL(n)			MMIO8(USB_BASE + 0x102 + (n)*0x10)

/* USB Transmit Control and Status Endpoint [1-7] High */
#define USB_TXCSRH(n)			MMIO8(USB_BASE + 0x103 + (n)*0x10)

/* USB Maximum Receive Data Endpoint [1-7] */
#define USB_RXMAXP(n)			MMIO16(USB_BASE + 0x104 + (n)*0x10)

/* USB Receive Control and Status Endpoint [1-7] Low */
#define USB_RXCSRL(n)			MMIO8(USB_BASE + 0x106 + (n)*0x10)

/* USB Receive Control and Status Endpoint [1-7] High */
#define USB_RXCSRH(n)			MMIO8(USB_BASE + 0x107 + (n)*0x10)

/* USB Receive Byte Count Endpoint [1-7] */
#define USB_RXCOUNT(n)			MMIO16(USB_BASE + 0x108 + (n)*0x10)

/* USB Receive Double Packet Buffer Disable */
#define USB_RXDPKTBUFDIS		MMIO16(USB_BASE + 0x340)

/* USB Transmit Double Packet Buffer Disable */
#define USB_TXDPKTBUFDIS		MMIO16(USB_BASE + 0x342)

/* USB Device RESUME Raw Interrupt Status */
#define USB_DRRIS			MMIO32(USB_BASE + 0x410)

/* USB Device RESUME Interrupt Mask */
#define USB_DRIM			MMIO32(USB_BASE + 0x414)

/* USB Device RESUME Interrupt Status and Clear */
#define USB_DRISC			MMIO32(USB_BASE + 0x418)

/* USB DMA Select */
#define USB_DMASEL			MMIO32(USB_BASE + 0x450)

/* USB Peripheral Properties */
#define USB_PP				MMIO32(USB_BASE + 0xFC0)


/* =============================================================================
 * USB_FADDR values
 * ---------------------------------------------------------------------------*/
/** Function Address */
#define USB_FADDR_FUNCADDR_MASK		(0x3f << 0)

/* =============================================================================
 * USB_POWER values
 * ---------------------------------------------------------------------------*/
/** Isochronous Update */
#define USB_POWER_ISOUP			(1 << 7)
/** Soft Connect/Disconnect */
#define USB_POWER_SOFTCONN		(1 << 6)
/** RESET signaling */
#define USB_POWER_RESET			(1 << 3)
/** RESUME signaling */
#define USB_POWER_RESUME		(1 << 2)
/** SUSPEND mode */
#define USB_POWER_SUSPEND		(1 << 1)
/** Power down PHY */
#define USB_POWER_PWRDNPHY		(1 << 0)

/* =============================================================================
 * Endpoint bitmasks for interrupt status and control registers
 * Applies to USB_TXIS, USB_RXIS, USB_TXIE, USB_RXIE, USB_RXDPKTBUFDIS,
 * USB_TXDPKTBUFDIS
 * ---------------------------------------------------------------------------*/
#define USB_EP7				(1 << 7)
#define USB_EP6				(1 << 6)
#define USB_EP5				(1 << 5)
#define USB_EP4				(1 << 4)
#define USB_EP3				(1 << 3)
#define USB_EP2				(1 << 2)
#define USB_EP1				(1 << 1)
#define USB_EP0				(1 << 0)

/* =============================================================================
 * USB interrupt mask values
 *
 * These are interchangeable across USB_IS, and USB_IE registers.
 * ---------------------------------------------------------------------------*/
/** USB disconnect interrupt */
#define USB_IM_DISCON			(1 << 5)
/** Start of frame */
#define USB_IM_SOF			(1 << 3)
/** RESET signaling detected */
#define USB_IM_RESET			(1 << 2)
/** RESUME signaling detected */
#define USB_IM_RESUME			(1 << 1)
/** SUSPEND signaling detected */
#define USB_IM_SUSPEND			(1 << 0)

/* =============================================================================
 * USB_FRAME values
 * ---------------------------------------------------------------------------*/
/** Frame number */
#define USB_FRAME_MASK			(0x03FF)

/* =============================================================================
 * USB_IDX values
 * ---------------------------------------------------------------------------*/
/** Endpoint Index */
#define USB_EPIDX_MASK			(0x0F)

/* =============================================================================
 * USB_TEST values
 * ---------------------------------------------------------------------------*/
/** FIFO access */
#define USB_TEST_FIFOACC		(1 << 6)
/** Force full-speed mode */
#define USB_TEST_FORCEFS		(1 << 5)

/* =============================================================================
 * USB_TXFIFOSZ and USB_RXFIFOSZ values
 * ---------------------------------------------------------------------------*/
/** Double packet buffer support */
#define USB_FIFOSZ_DPB			(1 << 4)
/* USB Transmit Dynamic FIFO Sizing */
#define USB_FIFOSZ_SIZE_MASK		(0x0F << 0)
#define USB_FIFOSZ_SIZE_8		(0x00 << 0)
#define USB_FIFOSZ_SIZE_16		(0x01 << 0)
#define USB_FIFOSZ_SIZE_32		(0x02 << 0)
#define USB_FIFOSZ_SIZE_64		(0x03 << 0)
#define USB_FIFOSZ_SIZE_128		(0x04 << 0)
#define USB_FIFOSZ_SIZE_256		(0x05 << 0)
#define USB_FIFOSZ_SIZE_512		(0x06 << 0)
#define USB_FIFOSZ_SIZE_1024		(0x07 << 0)
#define USB_FIFOSZ_SIZE_2048		(0x08 << 0)


/* =============================================================================
 * USB_CONTIM values
 * ---------------------------------------------------------------------------*/
/** Connect wait */
#define USB_CONTIM_WTCON_MASK		(0x0F << 4)
/** Wait ID */
#define USB_CONTIM_WTID_MASK		(0x0F << 0)

/* =============================================================================
 * USB_CSRL0 values
 * ---------------------------------------------------------------------------*/
/** Setup End Clear */
#define USB_CSRL0_SETENDC		(1 << 7)
/** RXRDY Clear */
#define USB_CSRL0_RXRDYC		(1 << 6)
/** Send Stall */
#define USB_CSRL0_STALL			(1 << 5)
/** Setup End */
#define USB_CSRL0_SETEND		(1 << 4)
/** Data End */
#define USB_CSRL0_DATAEND		(1 << 3)
/** Endpoint Stalled */
#define USB_CSRL0_STALLED		(1 << 2)
/** Transmit Packet Ready */
#define USB_CSRL0_TXRDY			(1 << 1)
/** Receive Packet Ready */
#define USB_CSRL0_RXRDY			(1 << 0)

/* =============================================================================
 * USB_CSRH0 values
 * ---------------------------------------------------------------------------*/
/** Flush FIFO */
#define USB_CSRH0_FLUSH			(1 << 0)

/* =============================================================================
 * USB_TXCSRLx values
 * ---------------------------------------------------------------------------*/
/** Clear data toggle */
#define USB_TXCSRL_CLRDT		(1 << 6)
/** Endpoint Stalled */
#define USB_TXCSRL_STALLED		(1 << 5)
/** Send Stall */
#define USB_TXCSRL_STALL		(1 << 4)
/** Flush FIFO */
#define USB_TXCSRL_FLUSH		(1 << 3)
/** Underrun */
#define USB_TXCSRL_UNDRN		(1 << 2)
/** FIFO not empty */
#define USB_TXCSRL_FIFONE		(1 << 1)
/** Transmit Packet Ready */
#define USB_TXCSRL_TXRDY		(1 << 0)

/* =============================================================================
 * USB_TXCSRHx values
 * ---------------------------------------------------------------------------*/
/** Auto set */
#define USB_TXCSRH_AUTOSET		(1 << 7)
/** Isochronous transfers */
#define USB_TXCSRH_ISO			(1 << 6)
/** Mode */
#define USB_TXCSRH_MODE			(1 << 5)
/** DMA request enable */
#define USB_TXCSRH_DMAEN		(1 << 4)
/** Force data toggle */
#define USB_TXCSRH_FDT			(1 << 3)
/** DMA request mode */
#define USB_TXCSRH_DMAMOD		(1 << 2)

/* =============================================================================
 * USB_RXCSRLx values
 * ---------------------------------------------------------------------------*/
/** Clear data toggle */
#define USB_RXCSRL_CLRDT		(1 << 7)
/** Endpoint Stalled */
#define USB_RXCSRL_STALLED		(1 << 6)
/** Send Stall */
#define USB_RXCSRL_STALL		(1 << 5)
/** Flush FIFO */
#define USB_RXCSRL_FLUSH		(1 << 4)
/** Data error */
#define USB_RXCSRL_DATAERR		(1 << 2)
/** Overrun */
#define USB_RXCSRL_OVER			(1 << 2)
/** FIFO full */
#define USB_RXCSRL_FULL			(1 << 1)
/** Receive Packet Ready */
#define USB_RXCSRL_RXRDY		(1 << 0)

/* =============================================================================
 * USB_RXCSRHx values
 * ---------------------------------------------------------------------------*/
/** Auto clear */
#define USB_RXCSRH_AUTOCL		(1 << 7)
/** Isochronous transfers */
#define USB_RXCSRH_ISO			(1 << 6)
/** DMA request enable */
#define USB_RXCSRH_DMAEN		(1 << 5)
/** Disable NYET / PID error */
#define USB_RXCSRH_PIDERR		(1 << 4)
/** DMA request mode */
#define USB_RXCSRH_DMAMOD		(1 << 3)

/* =============================================================================
 * USB_DRRIS values
 * ---------------------------------------------------------------------------*/
/** RESUME interrupt status */
#define USB_DRRIS_RESUME		(1 << 0)

/* =============================================================================
 * USB_DRIM values
 * ---------------------------------------------------------------------------*/
/** RESUME interrupt mask */
#define USB_DRIM_RESUME			(1 << 0)

/* =============================================================================
 * USB_DRISC values
 * ---------------------------------------------------------------------------*/
/** RESUME interrupt status and clear */
#define USB_DRISC_RESUME		(1 << 0)

/* =============================================================================
 * USB_PP values
 * ---------------------------------------------------------------------------*/
/** Endpoint count */
#define USB_PP_ECNT_MASK		(0xFF << 8)
/** USB capability */
#define USB_PP_USB_MASK			(0x03 << 6)
#define USB_PP_USB_NA			(0x00 << 6)
#define USB_PP_USB_DEVICE		(0x01 << 6)
#define USB_PP_USB_HOST			(0x02 << 6)
#define USB_PP_USB_OTG			(0x03 << 6)
/** PHY present */
#define USB_PP_PHY			(1 << 4)
/** Controller type */
#define USB_PP_TYPE_MASK		(0x0F << 0)

/* =============================================================================
 * Convenience enums
 * ---------------------------------------------------------------------------*/
enum usb_interrupt {
	USB_INT_DISCON			= USB_IM_DISCON,
	USB_INT_SOF			= USB_IM_SOF,
	USB_INT_RESET			= USB_IM_RESET,
	USB_INT_RESUME			= USB_IM_RESUME,
	USB_INT_SUSPEND			= USB_IM_SUSPEND,
};

enum usb_ep_interrupt {
	USB_EP0_INT			= USB_EP0,
	USB_EP1_INT			= USB_EP1,
	USB_EP2_INT			= USB_EP2,
	USB_EP3_INT			= USB_EP3,
	USB_EP4_INT			= USB_EP4,
	USB_EP5_INT			= USB_EP5,
	USB_EP6_INT			= USB_EP6,
	USB_EP7_INT			= USB_EP7,
};
/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void usb_enable_interrupts(enum usb_interrupt ints,
			   enum usb_ep_interrupt rx_ints,
			   enum usb_ep_interrupt tx_ints);
void usb_disable_interrupts(enum usb_interrupt ints,
			    enum usb_ep_interrupt rx_ints,
			    enum usb_ep_interrupt tx_ints);

END_DECLS

/**@}*/

#endif /* LIBOPENCM3_LM4F_USB_H */
