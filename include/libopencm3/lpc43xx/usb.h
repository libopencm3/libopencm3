/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_USB_H
#define LPC43XX_USB_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

#define BIT_MASK(base_name) \
	(((1 << base_name##_WIDTH) - 1) << base_name##_SHIFT)
#define BIT_ARG(base_name, x) ((x) << base_name##_SHIFT)

/* USB device data structures */

/* "The software must ensure that no interface data structure reachable
 *  by the Device controller crosses a 4kB-page boundary."
 */

/* --- Endpoint Transfer Descriptor (dTD) ---------------------------------- */

typedef struct usb_transfer_descriptor_t usb_transfer_descriptor_t;
struct usb_transfer_descriptor_t {
	volatile usb_transfer_descriptor_t *next_dtd_pointer;
	volatile uint32_t total_bytes;
	volatile uint32_t buffer_pointer_page[5];
	volatile uint32_t _reserved;
};

#define USB_TD_NEXT_DTD_POINTER_TERMINATE_SHIFT (0)
#define USB_TD_NEXT_DTD_POINTER_TERMINATE \
	((volatile usb_transfer_descriptor_t *) \
	(1 << USB_TD_NEXT_DTD_POINTER_TERMINATE_SHIFT))

#define USB_TD_DTD_TOKEN_TOTAL_BYTES_SHIFT (16)
#define USB_TD_DTD_TOKEN_TOTAL_BYTES_WIDTH (15)
#define USB_TD_DTD_TOKEN_TOTAL_BYTES_MASK BIT_MASK(USB_TD_DTD_TOKEN_TOTAL_BYTES)
#define USB_TD_DTD_TOKEN_TOTAL_BYTES(x) BIT_ARG(USB_TD_DTD_TOKEN_TOTAL_BYTES, (x))

#define USB_TD_DTD_TOKEN_IOC_SHIFT (15)
#define USB_TD_DTD_TOKEN_IOC (1 << USB_TD_DTD_TOKEN_IOC_SHIFT)

#define USB_TD_DTD_TOKEN_MULTO_SHIFT (10)
#define USB_TD_DTD_TOKEN_MULTO_WIDTH (2)
#define USB_TD_DTD_TOKEN_MULTO_MASK BIT_MASK(USB_TD_DTD_TOKEN_MULTO)
#define USB_TD_DTD_TOKEN_MULTO(x) BIT_ARG(USB_TD_DTD_TOKEN_MULTO, (x))

#define USB_TD_DTD_TOKEN_STATUS_ACTIVE_SHIFT (7)
#define USB_TD_DTD_TOKEN_STATUS_ACTIVE \
			(1 << USB_TD_DTD_TOKEN_STATUS_ACTIVE_SHIFT)

#define USB_TD_DTD_TOKEN_STATUS_HALTED_SHIFT (6)
#define USB_TD_DTD_TOKEN_STATUS_HALTED \
			(1 << USB_TD_DTD_TOKEN_STATUS_HALTED_SHIFT)

#define USB_TD_DTD_TOKEN_STATUS_BUFFER_ERROR_SHIFT (5)
#define USB_TD_DTD_TOKEN_STATUS_BUFFER_ERROR \
			(1 << USB_TD_DTD_TOKEN_STATUS_BUFFER_ERROR_SHIFT)

#define USB_TD_DTD_TOKEN_STATUS_TRANSACTION_ERROR_SHIFT (3)
#define USB_TD_DTD_TOKEN_STATUS_TRANSACTION_ERROR \
			(1 << USB_TD_DTD_TOKEN_STATUS_TRANSACTION_ERROR_SHIFT)

/* --- Endpoint Queue Head (dQH) ------------------------------------------- */

/* - must be aligned on 64-byte boundaries. */
typedef struct {
	volatile uint32_t capabilities;
	volatile usb_transfer_descriptor_t *current_dtd_pointer;
	volatile usb_transfer_descriptor_t *next_dtd_pointer;
	volatile uint32_t total_bytes;
	volatile uint32_t buffer_pointer_page[5];
	volatile uint32_t _reserved_0;
	volatile uint8_t setup[8];
	volatile uint32_t _reserved_1[4];
} usb_queue_head_t;

#define USB_QH_CAPABILITIES_IOS_SHIFT (15)
#define USB_QH_CAPABILITIES_IOS (1 << USB_QH_CAPABILITIES_IOS_SHIFT)

#define USB_QH_CAPABILITIES_MPL_SHIFT (16)
#define USB_QH_CAPABILITIES_MPL_WIDTH (11)
#define USB_QH_CAPABILITIES_MPL_MASK BIT_MASK(USB_QH_CAPABILITIES_MPL)
#define USB_QH_CAPABILITIES_MPL(x) BIT_ARG(USB_QH_CAPABILITIES_MPL, (x))

#define USB_QH_CAPABILITIES_ZLT_SHIFT (29)
#define USB_QH_CAPABILITIES_ZLT (1 << USB_QH_CAPABILITIES_ZLT_SHIFT)

#define USB_QH_CAPABILITIES_MULT_SHIFT (30)
#define USB_QH_CAPABILITIES_MULT_WIDTH (2)
#define USB_QH_CAPABILITIES_MULT_MASK BIT_MASK(USB_QH_CAPABILITIES_MULT)
#define USB_QH_CAPABILITIES_MULT(x) BIT_ARG(USB_QH_CAPABILITIES_MULT, (x))

/* --- USB0 registers ------------------------------------------------------ */

/* Device/host capability registers */

/* Capability register length */
#define USB0_CAPLENGTH                  MMIO32(USB0_BASE + 0x100)

/* Host controller structural parameters */
#define USB0_HCSPARAMS                  MMIO32(USB0_BASE + 0x104)

/* Host controller capability parameters */
#define USB0_HCCPARAMS                  MMIO32(USB0_BASE + 0x108)

/* Device interface version number */
#define USB0_DCIVERSION                 MMIO32(USB0_BASE + 0x120)

/* Device controller capability parameters */
#define USB0_DCCPARAMS                  MMIO32(USB0_BASE + 0x124)


/* Device/host operational registers */

/* USB command (device mode) */
#define USB0_USBCMD_D                   MMIO32(USB0_BASE + 0x140)

/* USB command (host mode) */
#define USB0_USBCMD_H                   MMIO32(USB0_BASE + 0x140)

/* USB status (device mode) */
#define USB0_USBSTS_D                   MMIO32(USB0_BASE + 0x144)

/* USB status (host mode) */
#define USB0_USBSTS_H                   MMIO32(USB0_BASE + 0x144)

/* USB interrupt enable (device mode) */
#define USB0_USBINTR_D                  MMIO32(USB0_BASE + 0x148)

/* USB interrupt enable (host mode) */
#define USB0_USBINTR_H                  MMIO32(USB0_BASE + 0x148)

/* USB frame index (device mode) */
#define USB0_FRINDEX_D                  MMIO32(USB0_BASE + 0x14C)

/* USB frame index (host mode) */
#define USB0_FRINDEX_H                  MMIO32(USB0_BASE + 0x14C)

/* USB device address (device mode) */
#define USB0_DEVICEADDR                 MMIO32(USB0_BASE + 0x154)

/* Frame list base address (host mode) */
#define USB0_PERIODICLISTBASE           MMIO32(USB0_BASE + 0x154)

/* Address of endpoint list in memory */
#define USB0_ENDPOINTLISTADDR           MMIO32(USB0_BASE + 0x158)

/* Asynchronous list address */
#define USB0_ASYNCLISTADDR              MMIO32(USB0_BASE + 0x158)

/* Asynchronous buffer status for embedded TT (host mode) */
#define USB0_TTCTRL                     MMIO32(USB0_BASE + 0x15C)

/* Programmable burst size */
#define USB0_BURSTSIZE                  MMIO32(USB0_BASE + 0x160)

/* Host transmit pre-buffer packet tuning (host mode) */
#define USB0_TXFILLTUNING               MMIO32(USB0_BASE + 0x164)

/* Length of virtual frame */
#define USB0_BINTERVAL                  MMIO32(USB0_BASE + 0x174)

/* Endpoint NAK (device mode) */
#define USB0_ENDPTNAK                   MMIO32(USB0_BASE + 0x178)

/* Endpoint NAK Enable (device mode) */
#define USB0_ENDPTNAKEN                 MMIO32(USB0_BASE + 0x17C)

/* Port 1 status/control (device mode) */
#define USB0_PORTSC1_D                  MMIO32(USB0_BASE + 0x184)

/* Port 1 status/control (host mode) */
#define USB0_PORTSC1_H                  MMIO32(USB0_BASE + 0x184)

/* OTG status and control */
#define USB0_OTGSC                      MMIO32(USB0_BASE + 0x1A4)

/* USB device mode (device mode) */
#define USB0_USBMODE_D                  MMIO32(USB0_BASE + 0x1A8)

/* USB device mode (host mode) */
#define USB0_USBMODE_H                  MMIO32(USB0_BASE + 0x1A8)


/* Device endpoint registers */

/* Endpoint setup status */
#define USB0_ENDPTSETUPSTAT             MMIO32(USB0_BASE + 0x1AC)

/* Endpoint initialization */
#define USB0_ENDPTPRIME                 MMIO32(USB0_BASE + 0x1B0)

/* Endpoint de-initialization */
#define USB0_ENDPTFLUSH                 MMIO32(USB0_BASE + 0x1B4)

/* Endpoint status */
#define USB0_ENDPTSTAT                  MMIO32(USB0_BASE + 0x1B8)

/* Endpoint complete */
#define USB0_ENDPTCOMPLETE              MMIO32(USB0_BASE + 0x1BC)

/* Endpoint control */
#define USB0_ENDPTCTRL(logical_ep)      MMIO32(USB0_BASE + 0x1C0 + \
							((logical_ep) * 4))

/* Endpoint control 0 */
#define USB0_ENDPTCTRL0                 USB0_ENDPTCTRL(0)

/* Endpoint control 1 */
#define USB0_ENDPTCTRL1                 USB0_ENDPTCTRL(1)

/* Endpoint control 2 */
#define USB0_ENDPTCTRL2                 USB0_ENDPTCTRL(2)

/* Endpoint control 3 */
#define USB0_ENDPTCTRL3                 USB0_ENDPTCTRL(3)

/* Endpoint control 4 */
#define USB0_ENDPTCTRL4                 USB0_ENDPTCTRL(4)

/* Endpoint control 5 */
#define USB0_ENDPTCTRL5                 USB0_ENDPTCTRL(5)

/* --- USB0_CAPLENGTH values ------------------------------------ */

/* CAPLENGTH: Indicates offset to add to the register base address at the
 beginning of the Operational Register */
#define USB0_CAPLENGTH_CAPLENGTH_SHIFT (0)
#define USB0_CAPLENGTH_CAPLENGTH_MASK (0xff << USB0_CAPLENGTH_CAPLENGTH_SHIFT)
#define USB0_CAPLENGTH_CAPLENGTH(x) ((x) << USB0_CAPLENGTH_CAPLENGTH_SHIFT)

/* HCIVERSION: BCD encoding of the EHCI revision number supported by this host
 controller */
#define USB0_CAPLENGTH_HCIVERSION_SHIFT (8)
#define USB0_CAPLENGTH_HCIVERSION_MASK \
			(0xffff << USB0_CAPLENGTH_HCIVERSION_SHIFT)
#define USB0_CAPLENGTH_HCIVERSION(x) ((x) << USB0_CAPLENGTH_HCIVERSION_SHIFT)

/* --- USB0_HCSPARAMS values ------------------------------------ */

/* N_PORTS: Number of downstream ports */
#define USB0_HCSPARAMS_N_PORTS_SHIFT (0)
#define USB0_HCSPARAMS_N_PORTS_MASK (0xf << USB0_HCSPARAMS_N_PORTS_SHIFT)
#define USB0_HCSPARAMS_N_PORTS(x) ((x) << USB0_HCSPARAMS_N_PORTS_SHIFT)

/* PPC: Port Power Control */
#define USB0_HCSPARAMS_PPC_SHIFT (4)
#define USB0_HCSPARAMS_PPC (1 << USB0_HCSPARAMS_PPC_SHIFT)

/* N_PCC: Number of Ports per Companion Controller */
#define USB0_HCSPARAMS_N_PCC_SHIFT (8)
#define USB0_HCSPARAMS_N_PCC_MASK (0xf << USB0_HCSPARAMS_N_PCC_SHIFT)
#define USB0_HCSPARAMS_N_PCC(x) ((x) << USB0_HCSPARAMS_N_PCC_SHIFT)

/* N_CC: Number of Companion Controller */
#define USB0_HCSPARAMS_N_CC_SHIFT (12)
#define USB0_HCSPARAMS_N_CC_MASK (0xf << USB0_HCSPARAMS_N_CC_SHIFT)
#define USB0_HCSPARAMS_N_CC(x) ((x) << USB0_HCSPARAMS_N_CC_SHIFT)

/* PI: Port indicators */
#define USB0_HCSPARAMS_PI_SHIFT (16)
#define USB0_HCSPARAMS_PI (1 << USB0_HCSPARAMS_PI_SHIFT)

/* N_PTT: Number of Ports per Transaction Translator */
#define USB0_HCSPARAMS_N_PTT_SHIFT (20)
#define USB0_HCSPARAMS_N_PTT_MASK (0xf << USB0_HCSPARAMS_N_PTT_SHIFT)
#define USB0_HCSPARAMS_N_PTT(x) ((x) << USB0_HCSPARAMS_N_PTT_SHIFT)

/* N_TT: Number of Transaction Translators */
#define USB0_HCSPARAMS_N_TT_SHIFT (24)
#define USB0_HCSPARAMS_N_TT_MASK (0xf << USB0_HCSPARAMS_N_TT_SHIFT)
#define USB0_HCSPARAMS_N_TT(x) ((x) << USB0_HCSPARAMS_N_TT_SHIFT)

/* --- USB0_HCCPARAMS values ------------------------------------ */

/* ADC: 64-bit Addressing Capability */
#define USB0_HCCPARAMS_ADC_SHIFT (0)
#define USB0_HCCPARAMS_ADC (1 << USB0_HCCPARAMS_ADC_SHIFT)

/* PFL: Programmable Frame List Flag */
#define USB0_HCCPARAMS_PFL_SHIFT (1)
#define USB0_HCCPARAMS_PFL (1 << USB0_HCCPARAMS_PFL_SHIFT)

/* ASP: Asynchronous Schedule Park Capability */
#define USB0_HCCPARAMS_ASP_SHIFT (2)
#define USB0_HCCPARAMS_ASP (1 << USB0_HCCPARAMS_ASP_SHIFT)

/* IST: Isochronous Scheduling Threshold */
#define USB0_HCCPARAMS_IST_SHIFT (4)
#define USB0_HCCPARAMS_IST_MASK (0xf << USB0_HCCPARAMS_IST_SHIFT)
#define USB0_HCCPARAMS_IST(x) ((x) << USB0_HCCPARAMS_IST_SHIFT)

/* EECP: EHCI Extended Capabilities Pointer */
#define USB0_HCCPARAMS_EECP_SHIFT (8)
#define USB0_HCCPARAMS_EECP_MASK (0xf << USB0_HCCPARAMS_EECP_SHIFT)
#define USB0_HCCPARAMS_EECP(x) ((x) << USB0_HCCPARAMS_EECP_SHIFT)

/* --- USB0_DCCPARAMS values ------------------------------------ */

/* DEN: Device Endpoint Number */
#define USB0_DCCPARAMS_DEN_SHIFT (0)
#define USB0_DCCPARAMS_DEN_MASK (0x1f << USB0_DCCPARAMS_DEN_SHIFT)
#define USB0_DCCPARAMS_DEN(x) ((x) << USB0_DCCPARAMS_DEN_SHIFT)

/* DC: Device Capable */
#define USB0_DCCPARAMS_DC_SHIFT (7)
#define USB0_DCCPARAMS_DC (1 << USB0_DCCPARAMS_DC_SHIFT)

/* HC: Host Capable */
#define USB0_DCCPARAMS_HC_SHIFT (8)
#define USB0_DCCPARAMS_HC (1 << USB0_DCCPARAMS_HC_SHIFT)

/* --- USB0_USBCMD_D values ------------------------------------- */

/* RS: Run/Stop */
#define USB0_USBCMD_D_RS_SHIFT (0)
#define USB0_USBCMD_D_RS (1 << USB0_USBCMD_D_RS_SHIFT)

/* RST: Controller reset */
#define USB0_USBCMD_D_RST_SHIFT (1)
#define USB0_USBCMD_D_RST (1 << USB0_USBCMD_D_RST_SHIFT)

/* SUTW: Setup trip wire */
#define USB0_USBCMD_D_SUTW_SHIFT (13)
#define USB0_USBCMD_D_SUTW (1 << USB0_USBCMD_D_SUTW_SHIFT)

/* ATDTW: Add dTD trip wire */
#define USB0_USBCMD_D_ATDTW_SHIFT (14)
#define USB0_USBCMD_D_ATDTW (1 << USB0_USBCMD_D_ATDTW_SHIFT)

/* ITC: Interrupt threshold control */
#define USB0_USBCMD_D_ITC_SHIFT (16)
#define USB0_USBCMD_D_ITC_MASK (0xff << USB0_USBCMD_D_ITC_SHIFT)
#define USB0_USBCMD_D_ITC(x) ((x) << USB0_USBCMD_D_ITC_SHIFT)

/* --- USB0_USBCMD_H values ------------------------------------- */

/* RS: Run/Stop */
#define USB0_USBCMD_H_RS_SHIFT (0)
#define USB0_USBCMD_H_RS (1 << USB0_USBCMD_H_RS_SHIFT)

/* RST: Controller reset */
#define USB0_USBCMD_H_RST_SHIFT (1)
#define USB0_USBCMD_H_RST (1 << USB0_USBCMD_H_RST_SHIFT)

/* FS0: Bit 0 of the Frame List Size bits */
#define USB0_USBCMD_H_FS0_SHIFT (2)
#define USB0_USBCMD_H_FS0 (1 << USB0_USBCMD_H_FS0_SHIFT)

/* FS1: Bit 1 of the Frame List Size bits */
#define USB0_USBCMD_H_FS1_SHIFT (3)
#define USB0_USBCMD_H_FS1 (1 << USB0_USBCMD_H_FS1_SHIFT)

/* PSE: This bit controls whether the host controller skips processing the
periodic schedule */
#define USB0_USBCMD_H_PSE_SHIFT (4)
#define USB0_USBCMD_H_PSE (1 << USB0_USBCMD_H_PSE_SHIFT)

/* ASE: This bit controls whether the host controller skips processing the
asynchronous schedule */
#define USB0_USBCMD_H_ASE_SHIFT (5)
#define USB0_USBCMD_H_ASE (1 << USB0_USBCMD_H_ASE_SHIFT)

/* IAA: This bit is used as a doorbell by software to tell the host controller
to issue an interrupt the next time it advances asynchronous schedule */
#define USB0_USBCMD_H_IAA_SHIFT (6)
#define USB0_USBCMD_H_IAA (1 << USB0_USBCMD_H_IAA_SHIFT)

/* ASP1_0: Asynchronous schedule park mode */
#define USB0_USBCMD_H_ASP1_0_SHIFT (8)
#define USB0_USBCMD_H_ASP1_0_MASK (0x3 << USB0_USBCMD_H_ASP1_0_SHIFT)
#define USB0_USBCMD_H_ASP1_0(x) ((x) << USB0_USBCMD_H_ASP1_0_SHIFT)

/* ASPE: Asynchronous Schedule Park Mode Enable */
#define USB0_USBCMD_H_ASPE_SHIFT (11)
#define USB0_USBCMD_H_ASPE (1 << USB0_USBCMD_H_ASPE_SHIFT)

/* FS2: Bit 2 of the Frame List Size bits */
#define USB0_USBCMD_H_FS2_SHIFT (15)
#define USB0_USBCMD_H_FS2 (1 << USB0_USBCMD_H_FS2_SHIFT)

/* ITC: Interrupt threshold control */
#define USB0_USBCMD_H_ITC_SHIFT (16)
#define USB0_USBCMD_H_ITC_MASK (0xff << USB0_USBCMD_H_ITC_SHIFT)
#define USB0_USBCMD_H_ITC(x) ((x) << USB0_USBCMD_H_ITC_SHIFT)

/* --- USB0_USBSTS_D values ------------------------------------- */

/* UI: USB interrupt */
#define USB0_USBSTS_D_UI_SHIFT (0)
#define USB0_USBSTS_D_UI (1 << USB0_USBSTS_D_UI_SHIFT)

/* UEI: USB error interrupt */
#define USB0_USBSTS_D_UEI_SHIFT (1)
#define USB0_USBSTS_D_UEI (1 << USB0_USBSTS_D_UEI_SHIFT)

/* PCI: Port change detect */
#define USB0_USBSTS_D_PCI_SHIFT (2)
#define USB0_USBSTS_D_PCI (1 << USB0_USBSTS_D_PCI_SHIFT)

/* URI: USB reset received */
#define USB0_USBSTS_D_URI_SHIFT (6)
#define USB0_USBSTS_D_URI (1 << USB0_USBSTS_D_URI_SHIFT)

/* SRI: SOF received */
#define USB0_USBSTS_D_SRI_SHIFT (7)
#define USB0_USBSTS_D_SRI (1 << USB0_USBSTS_D_SRI_SHIFT)

/* SLI: DCSuspend */
#define USB0_USBSTS_D_SLI_SHIFT (8)
#define USB0_USBSTS_D_SLI (1 << USB0_USBSTS_D_SLI_SHIFT)

/* NAKI: NAK interrupt bit */
#define USB0_USBSTS_D_NAKI_SHIFT (16)
#define USB0_USBSTS_D_NAKI (1 << USB0_USBSTS_D_NAKI_SHIFT)

/* --- USB0_USBSTS_H values ------------------------------------- */

/* UI: USB interrupt */
#define USB0_USBSTS_H_UI_SHIFT (0)
#define USB0_USBSTS_H_UI (1 << USB0_USBSTS_H_UI_SHIFT)

/* UEI: USB error interrupt */
#define USB0_USBSTS_H_UEI_SHIFT (1)
#define USB0_USBSTS_H_UEI (1 << USB0_USBSTS_H_UEI_SHIFT)

/* PCI: Port change detect */
#define USB0_USBSTS_H_PCI_SHIFT (2)
#define USB0_USBSTS_H_PCI (1 << USB0_USBSTS_H_PCI_SHIFT)

/* FRI: Frame list roll-over */
#define USB0_USBSTS_H_FRI_SHIFT (3)
#define USB0_USBSTS_H_FRI (1 << USB0_USBSTS_H_FRI_SHIFT)

/* AAI: Interrupt on async advance */
#define USB0_USBSTS_H_AAI_SHIFT (5)
#define USB0_USBSTS_H_AAI (1 << USB0_USBSTS_H_AAI_SHIFT)

/* SRI: SOF received */
#define USB0_USBSTS_H_SRI_SHIFT (7)
#define USB0_USBSTS_H_SRI (1 << USB0_USBSTS_H_SRI_SHIFT)

/* HCH: HCHalted */
#define USB0_USBSTS_H_HCH_SHIFT (12)
#define USB0_USBSTS_H_HCH (1 << USB0_USBSTS_H_HCH_SHIFT)

/* RCL: Reclamation */
#define USB0_USBSTS_H_RCL_SHIFT (13)
#define USB0_USBSTS_H_RCL (1 << USB0_USBSTS_H_RCL_SHIFT)

/* PS: Periodic schedule status */
#define USB0_USBSTS_H_PS_SHIFT (14)
#define USB0_USBSTS_H_PS (1 << USB0_USBSTS_H_PS_SHIFT)

/* AS: Asynchronous schedule status */
#define USB0_USBSTS_H_AS_SHIFT (15)
#define USB0_USBSTS_H_AS (1 << USB0_USBSTS_H_AS_SHIFT)

/* UAI: USB host asynchronous interrupt (USBHSTASYNCINT) */
#define USB0_USBSTS_H_UAI_SHIFT (18)
#define USB0_USBSTS_H_UAI (1 << USB0_USBSTS_H_UAI_SHIFT)

/* UPI: USB host periodic interrupt (USBHSTPERINT) */
#define USB0_USBSTS_H_UPI_SHIFT (19)
#define USB0_USBSTS_H_UPI (1 << USB0_USBSTS_H_UPI_SHIFT)

/* --- USB0_USBINTR_D values ------------------------------------ */

/* UE: USB interrupt enable */
#define USB0_USBINTR_D_UE_SHIFT (0)
#define USB0_USBINTR_D_UE (1 << USB0_USBINTR_D_UE_SHIFT)

/* UEE: USB error interrupt enable */
#define USB0_USBINTR_D_UEE_SHIFT (1)
#define USB0_USBINTR_D_UEE (1 << USB0_USBINTR_D_UEE_SHIFT)

/* PCE: Port change detect enable */
#define USB0_USBINTR_D_PCE_SHIFT (2)
#define USB0_USBINTR_D_PCE (1 << USB0_USBINTR_D_PCE_SHIFT)

/* URE: USB reset enable */
#define USB0_USBINTR_D_URE_SHIFT (6)
#define USB0_USBINTR_D_URE (1 << USB0_USBINTR_D_URE_SHIFT)

/* SRE: SOF received enable */
#define USB0_USBINTR_D_SRE_SHIFT (7)
#define USB0_USBINTR_D_SRE (1 << USB0_USBINTR_D_SRE_SHIFT)

/* SLE: Sleep enable */
#define USB0_USBINTR_D_SLE_SHIFT (8)
#define USB0_USBINTR_D_SLE (1 << USB0_USBINTR_D_SLE_SHIFT)

/* NAKE: NAK interrupt enable */
#define USB0_USBINTR_D_NAKE_SHIFT (16)
#define USB0_USBINTR_D_NAKE (1 << USB0_USBINTR_D_NAKE_SHIFT)

/* --- USB0_USBINTR_H values ------------------------------------ */

/* UE: USB interrupt enable */
#define USB0_USBINTR_H_UE_SHIFT (0)
#define USB0_USBINTR_H_UE (1 << USB0_USBINTR_H_UE_SHIFT)

/* UEE: USB error interrupt enable */
#define USB0_USBINTR_H_UEE_SHIFT (1)
#define USB0_USBINTR_H_UEE (1 << USB0_USBINTR_H_UEE_SHIFT)

/* PCE: Port change detect enable */
#define USB0_USBINTR_H_PCE_SHIFT (2)
#define USB0_USBINTR_H_PCE (1 << USB0_USBINTR_H_PCE_SHIFT)

/* FRE: Frame list rollover enable */
#define USB0_USBINTR_H_FRE_SHIFT (3)
#define USB0_USBINTR_H_FRE (1 << USB0_USBINTR_H_FRE_SHIFT)

/* AAE: Interrupt on asynchronous advance enable */
#define USB0_USBINTR_H_AAE_SHIFT (5)
#define USB0_USBINTR_H_AAE (1 << USB0_USBINTR_H_AAE_SHIFT)

/* SRE: SOF received enable */
#define USB0_USBINTR_H_SRE_SHIFT (7)
#define USB0_USBINTR_H_SRE (1 << USB0_USBINTR_H_SRE_SHIFT)

/* UAIE: USB host asynchronous interrupt enable */
#define USB0_USBINTR_H_UAIE_SHIFT (18)
#define USB0_USBINTR_H_UAIE (1 << USB0_USBINTR_H_UAIE_SHIFT)

/* UPIA: USB host periodic interrupt enable */
#define USB0_USBINTR_H_UPIA_SHIFT (19)
#define USB0_USBINTR_H_UPIA (1 << USB0_USBINTR_H_UPIA_SHIFT)

/* --- USB0_FRINDEX_D values ------------------------------------ */

/* FRINDEX2_0: Current micro frame number */
#define USB0_FRINDEX_D_FRINDEX2_0_SHIFT (0)
#define USB0_FRINDEX_D_FRINDEX2_0_MASK (0x7 << USB0_FRINDEX_D_FRINDEX2_0_SHIFT)
#define USB0_FRINDEX_D_FRINDEX2_0(x) ((x) << USB0_FRINDEX_D_FRINDEX2_0_SHIFT)

/* FRINDEX13_3: Current frame number of the last frame transmitted */
#define USB0_FRINDEX_D_FRINDEX13_3_SHIFT (3)
#define USB0_FRINDEX_D_FRINDEX13_3_MASK \
			(0x7ff << USB0_FRINDEX_D_FRINDEX13_3_SHIFT)
#define USB0_FRINDEX_D_FRINDEX13_3(x) ((x) << USB0_FRINDEX_D_FRINDEX13_3_SHIFT)

/* --- USB0_FRINDEX_H values ------------------------------------ */

/* FRINDEX2_0: Current micro frame number */
#define USB0_FRINDEX_H_FRINDEX2_0_SHIFT (0)
#define USB0_FRINDEX_H_FRINDEX2_0_MASK (0x7 << USB0_FRINDEX_H_FRINDEX2_0_SHIFT)
#define USB0_FRINDEX_H_FRINDEX2_0(x) ((x) << USB0_FRINDEX_H_FRINDEX2_0_SHIFT)

/* FRINDEX12_3: Frame list current index */
#define USB0_FRINDEX_H_FRINDEX12_3_SHIFT (3)
#define USB0_FRINDEX_H_FRINDEX12_3_MASK \
			(0x3ff << USB0_FRINDEX_H_FRINDEX12_3_SHIFT)
#define USB0_FRINDEX_H_FRINDEX12_3(x) ((x) << USB0_FRINDEX_H_FRINDEX12_3_SHIFT)

/* --- USB0_DEVICEADDR values ----------------------------------- */

/* USBADRA: Device address advance */
#define USB0_DEVICEADDR_USBADRA_SHIFT (24)
#define USB0_DEVICEADDR_USBADRA (1 << USB0_DEVICEADDR_USBADRA_SHIFT)

/* USBADR: USB device address */
#define USB0_DEVICEADDR_USBADR_SHIFT (25)
#define USB0_DEVICEADDR_USBADR_MASK (0x7f << USB0_DEVICEADDR_USBADR_SHIFT)
#define USB0_DEVICEADDR_USBADR(x) ((x) << USB0_DEVICEADDR_USBADR_SHIFT)

/* --- USB0_PERIODICLISTBASE values ----------------------------- */

/* PERBASE31_12: Base Address (Low) */
#define USB0_PERIODICLISTBASE_PERBASE31_12_SHIFT (12)
#define USB0_PERIODICLISTBASE_PERBASE31_12_MASK \
			(0xfffff << USB0_PERIODICLISTBASE_PERBASE31_12_SHIFT)
#define USB0_PERIODICLISTBASE_PERBASE31_12(x) \
			((x) << USB0_PERIODICLISTBASE_PERBASE31_12_SHIFT)

/* --- USB0_ENDPOINTLISTADDR values ----------------------------- */

/* EPBASE31_11: Endpoint list pointer (low) */
#define USB0_ENDPOINTLISTADDR_EPBASE31_11_SHIFT (11)
#define USB0_ENDPOINTLISTADDR_EPBASE31_11_MASK \
			(0x1fffff << USB0_ENDPOINTLISTADDR_EPBASE31_11_SHIFT)
#define USB0_ENDPOINTLISTADDR_EPBASE31_11(x) \
			((x) << USB0_ENDPOINTLISTADDR_EPBASE31_11_SHIFT)

/* --- USB0_ASYNCLISTADDR values -------------------------------- */

/* ASYBASE31_5: Link pointer (Low) LPL */
#define USB0_ASYNCLISTADDR_ASYBASE31_5_SHIFT (5)
#define USB0_ASYNCLISTADDR_ASYBASE31_5_MASK \
			(0x7ffffff << USB0_ASYNCLISTADDR_ASYBASE31_5_SHIFT)
#define USB0_ASYNCLISTADDR_ASYBASE31_5(x) \
			((x) << USB0_ASYNCLISTADDR_ASYBASE31_5_SHIFT)

/* --- USB0_TTCTRL values --------------------------------------- */

/* TTHA: Hub address when FS or LS device are connected directly */
#define USB0_TTCTRL_TTHA_SHIFT (24)
#define USB0_TTCTRL_TTHA_MASK (0x7f << USB0_TTCTRL_TTHA_SHIFT)
#define USB0_TTCTRL_TTHA(x) ((x) << USB0_TTCTRL_TTHA_SHIFT)

/* --- USB0_BURSTSIZE values ------------------------------------ */

/* RXPBURST: Programmable RX burst length */
#define USB0_BURSTSIZE_RXPBURST_SHIFT (0)
#define USB0_BURSTSIZE_RXPBURST_MASK (0xff << USB0_BURSTSIZE_RXPBURST_SHIFT)
#define USB0_BURSTSIZE_RXPBURST(x) ((x) << USB0_BURSTSIZE_RXPBURST_SHIFT)

/* TXPBURST: Programmable TX burst length */
#define USB0_BURSTSIZE_TXPBURST_SHIFT (8)
#define USB0_BURSTSIZE_TXPBURST_MASK (0xff << USB0_BURSTSIZE_TXPBURST_SHIFT)
#define USB0_BURSTSIZE_TXPBURST(x) ((x) << USB0_BURSTSIZE_TXPBURST_SHIFT)

/* --- USB0_TXFILLTUNING values --------------------------------- */

/* TXSCHOH: FIFO burst threshold */
#define USB0_TXFILLTUNING_TXSCHOH_SHIFT (0)
#define USB0_TXFILLTUNING_TXSCHOH_MASK (0xff << USB0_TXFILLTUNING_TXSCHOH_SHIFT)
#define USB0_TXFILLTUNING_TXSCHOH(x) ((x) << USB0_TXFILLTUNING_TXSCHOH_SHIFT)

/* TXSCHEATLTH: Scheduler health counter */
#define USB0_TXFILLTUNING_TXSCHEATLTH_SHIFT (8)
#define USB0_TXFILLTUNING_TXSCHEATLTH_MASK \
			(0x1f << USB0_TXFILLTUNING_TXSCHEATLTH_SHIFT)
#define USB0_TXFILLTUNING_TXSCHEATLTH(x) \
			((x) << USB0_TXFILLTUNING_TXSCHEATLTH_SHIFT)

/* TXFIFOTHRES: Scheduler overhead */
#define USB0_TXFILLTUNING_TXFIFOTHRES_SHIFT (16)
#define USB0_TXFILLTUNING_TXFIFOTHRES_MASK \
			(0x3f << USB0_TXFILLTUNING_TXFIFOTHRES_SHIFT)
#define USB0_TXFILLTUNING_TXFIFOTHRES(x) \
			((x) << USB0_TXFILLTUNING_TXFIFOTHRES_SHIFT)

/* --- USB0_BINTERVAL values ------------------------------------ */

/* BINT: bInterval value */
#define USB0_BINTERVAL_BINT_SHIFT (0)
#define USB0_BINTERVAL_BINT_MASK (0xf << USB0_BINTERVAL_BINT_SHIFT)
#define USB0_BINTERVAL_BINT(x) ((x) << USB0_BINTERVAL_BINT_SHIFT)

/* --- USB0_ENDPTNAK values ------------------------------------- */

/* EPRN: Rx endpoint NAK */
#define USB0_ENDPTNAK_EPRN_SHIFT (0)
#define USB0_ENDPTNAK_EPRN_MASK (0x3f << USB0_ENDPTNAK_EPRN_SHIFT)
#define USB0_ENDPTNAK_EPRN(x) ((x) << USB0_ENDPTNAK_EPRN_SHIFT)

/* EPTN: Tx endpoint NAK */
#define USB0_ENDPTNAK_EPTN_SHIFT (16)
#define USB0_ENDPTNAK_EPTN_MASK (0x3f << USB0_ENDPTNAK_EPTN_SHIFT)
#define USB0_ENDPTNAK_EPTN(x) ((x) << USB0_ENDPTNAK_EPTN_SHIFT)

/* --- USB0_ENDPTNAKEN values ----------------------------------- */

/* EPRNE: Rx endpoint NAK enable */
#define USB0_ENDPTNAKEN_EPRNE_SHIFT (0)
#define USB0_ENDPTNAKEN_EPRNE_MASK (0x3f << USB0_ENDPTNAKEN_EPRNE_SHIFT)
#define USB0_ENDPTNAKEN_EPRNE(x) ((x) << USB0_ENDPTNAKEN_EPRNE_SHIFT)

/* EPTNE: Tx endpoint NAK */
#define USB0_ENDPTNAKEN_EPTNE_SHIFT (16)
#define USB0_ENDPTNAKEN_EPTNE_MASK (0x3f << USB0_ENDPTNAKEN_EPTNE_SHIFT)
#define USB0_ENDPTNAKEN_EPTNE(x) ((x) << USB0_ENDPTNAKEN_EPTNE_SHIFT)

/* --- USB0_PORTSC1_D values ------------------------------------ */

/* CCS: Current connect status */
#define USB0_PORTSC1_D_CCS_SHIFT (0)
#define USB0_PORTSC1_D_CCS (1 << USB0_PORTSC1_D_CCS_SHIFT)

/* PE: Port enable */
#define USB0_PORTSC1_D_PE_SHIFT (2)
#define USB0_PORTSC1_D_PE (1 << USB0_PORTSC1_D_PE_SHIFT)

/* PEC: Port enable/disable change */
#define USB0_PORTSC1_D_PEC_SHIFT (3)
#define USB0_PORTSC1_D_PEC (1 << USB0_PORTSC1_D_PEC_SHIFT)

/* FPR: Force port resume */
#define USB0_PORTSC1_D_FPR_SHIFT (6)
#define USB0_PORTSC1_D_FPR (1 << USB0_PORTSC1_D_FPR_SHIFT)

/* SUSP: Suspend */
#define USB0_PORTSC1_D_SUSP_SHIFT (7)
#define USB0_PORTSC1_D_SUSP (1 << USB0_PORTSC1_D_SUSP_SHIFT)

/* PR: Port reset */
#define USB0_PORTSC1_D_PR_SHIFT (8)
#define USB0_PORTSC1_D_PR (1 << USB0_PORTSC1_D_PR_SHIFT)

/* HSP: High-speed status */
#define USB0_PORTSC1_D_HSP_SHIFT (9)
#define USB0_PORTSC1_D_HSP (1 << USB0_PORTSC1_D_HSP_SHIFT)

/* PIC1_0: Port indicator control */
#define USB0_PORTSC1_D_PIC1_0_SHIFT (14)
#define USB0_PORTSC1_D_PIC1_0_MASK (0x3 << USB0_PORTSC1_D_PIC1_0_SHIFT)
#define USB0_PORTSC1_D_PIC1_0(x) ((x) << USB0_PORTSC1_D_PIC1_0_SHIFT)

/* PTC3_0: Port test control */
#define USB0_PORTSC1_D_PTC3_0_SHIFT (16)
#define USB0_PORTSC1_D_PTC3_0_MASK (0xf << USB0_PORTSC1_D_PTC3_0_SHIFT)
#define USB0_PORTSC1_D_PTC3_0(x) ((x) << USB0_PORTSC1_D_PTC3_0_SHIFT)

/* PHCD: PHY low power suspend - clock disable (PLPSCD) */
#define USB0_PORTSC1_D_PHCD_SHIFT (23)
#define USB0_PORTSC1_D_PHCD (1 << USB0_PORTSC1_D_PHCD_SHIFT)

/* PFSC: Port force full speed connect */
#define USB0_PORTSC1_D_PFSC_SHIFT (24)
#define USB0_PORTSC1_D_PFSC (1 << USB0_PORTSC1_D_PFSC_SHIFT)

/* PSPD: Port speed */
#define USB0_PORTSC1_D_PSPD_SHIFT (26)
#define USB0_PORTSC1_D_PSPD_MASK (0x3 << USB0_PORTSC1_D_PSPD_SHIFT)
#define USB0_PORTSC1_D_PSPD(x) ((x) << USB0_PORTSC1_D_PSPD_SHIFT)

/* --- USB0_PORTSC1_H values ------------------------------------ */

/* CCS: Current connect status */
#define USB0_PORTSC1_H_CCS_SHIFT (0)
#define USB0_PORTSC1_H_CCS (1 << USB0_PORTSC1_H_CCS_SHIFT)

/* CSC: Connect status change */
#define USB0_PORTSC1_H_CSC_SHIFT (1)
#define USB0_PORTSC1_H_CSC (1 << USB0_PORTSC1_H_CSC_SHIFT)

/* PE: Port enable */
#define USB0_PORTSC1_H_PE_SHIFT (2)
#define USB0_PORTSC1_H_PE (1 << USB0_PORTSC1_H_PE_SHIFT)

/* PEC: Port disable/enable change */
#define USB0_PORTSC1_H_PEC_SHIFT (3)
#define USB0_PORTSC1_H_PEC (1 << USB0_PORTSC1_H_PEC_SHIFT)

/* OCA: Over-current active */
#define USB0_PORTSC1_H_OCA_SHIFT (4)
#define USB0_PORTSC1_H_OCA (1 << USB0_PORTSC1_H_OCA_SHIFT)

/* OCC: Over-current change */
#define USB0_PORTSC1_H_OCC_SHIFT (5)
#define USB0_PORTSC1_H_OCC (1 << USB0_PORTSC1_H_OCC_SHIFT)

/* FPR: Force port resume */
#define USB0_PORTSC1_H_FPR_SHIFT (6)
#define USB0_PORTSC1_H_FPR (1 << USB0_PORTSC1_H_FPR_SHIFT)

/* SUSP: Suspend */
#define USB0_PORTSC1_H_SUSP_SHIFT (7)
#define USB0_PORTSC1_H_SUSP (1 << USB0_PORTSC1_H_SUSP_SHIFT)

/* PR: Port reset */
#define USB0_PORTSC1_H_PR_SHIFT (8)
#define USB0_PORTSC1_H_PR (1 << USB0_PORTSC1_H_PR_SHIFT)

/* HSP: High-speed status */
#define USB0_PORTSC1_H_HSP_SHIFT (9)
#define USB0_PORTSC1_H_HSP (1 << USB0_PORTSC1_H_HSP_SHIFT)

/* LS: Line status */
#define USB0_PORTSC1_H_LS_SHIFT (10)
#define USB0_PORTSC1_H_LS_MASK (0x3 << USB0_PORTSC1_H_LS_SHIFT)
#define USB0_PORTSC1_H_LS(x) ((x) << USB0_PORTSC1_H_LS_SHIFT)

/* PP: Port power control */
#define USB0_PORTSC1_H_PP_SHIFT (12)
#define USB0_PORTSC1_H_PP (1 << USB0_PORTSC1_H_PP_SHIFT)

/* PIC1_0: Port indicator control */
#define USB0_PORTSC1_H_PIC1_0_SHIFT (14)
#define USB0_PORTSC1_H_PIC1_0_MASK (0x3 << USB0_PORTSC1_H_PIC1_0_SHIFT)
#define USB0_PORTSC1_H_PIC1_0(x) ((x) << USB0_PORTSC1_H_PIC1_0_SHIFT)

/* PTC3_0: Port test control */
#define USB0_PORTSC1_H_PTC3_0_SHIFT (16)
#define USB0_PORTSC1_H_PTC3_0_MASK (0xf << USB0_PORTSC1_H_PTC3_0_SHIFT)
#define USB0_PORTSC1_H_PTC3_0(x) ((x) << USB0_PORTSC1_H_PTC3_0_SHIFT)

/* WKCN: Wake on connect enable (WKCNNT_E) */
#define USB0_PORTSC1_H_WKCN_SHIFT (20)
#define USB0_PORTSC1_H_WKCN (1 << USB0_PORTSC1_H_WKCN_SHIFT)

/* WKDC: Wake on disconnect enable (WKDSCNNT_E) */
#define USB0_PORTSC1_H_WKDC_SHIFT (21)
#define USB0_PORTSC1_H_WKDC (1 << USB0_PORTSC1_H_WKDC_SHIFT)

/* WKOC: Wake on over-current enable (WKOC_E) */
#define USB0_PORTSC1_H_WKOC_SHIFT (22)
#define USB0_PORTSC1_H_WKOC (1 << USB0_PORTSC1_H_WKOC_SHIFT)

/* PHCD: PHY low power suspend - clock disable (PLPSCD) */
#define USB0_PORTSC1_H_PHCD_SHIFT (23)
#define USB0_PORTSC1_H_PHCD (1 << USB0_PORTSC1_H_PHCD_SHIFT)

/* PFSC: Port force full speed connect */
#define USB0_PORTSC1_H_PFSC_SHIFT (24)
#define USB0_PORTSC1_H_PFSC (1 << USB0_PORTSC1_H_PFSC_SHIFT)

/* PSPD: Port speed */
#define USB0_PORTSC1_H_PSPD_SHIFT (26)
#define USB0_PORTSC1_H_PSPD_MASK (0x3 << USB0_PORTSC1_H_PSPD_SHIFT)
#define USB0_PORTSC1_H_PSPD(x) ((x) << USB0_PORTSC1_H_PSPD_SHIFT)

/* --- USB0_OTGSC values ---------------------------------------- */

/* VD: VBUS_Discharge */
#define USB0_OTGSC_VD_SHIFT (0)
#define USB0_OTGSC_VD (1 << USB0_OTGSC_VD_SHIFT)

/* VC: VBUS_Charge */
#define USB0_OTGSC_VC_SHIFT (1)
#define USB0_OTGSC_VC (1 << USB0_OTGSC_VC_SHIFT)

/* HAAR: Hardware assist auto_reset */
#define USB0_OTGSC_HAAR_SHIFT (2)
#define USB0_OTGSC_HAAR (1 << USB0_OTGSC_HAAR_SHIFT)

/* OT: OTG termination */
#define USB0_OTGSC_OT_SHIFT (3)
#define USB0_OTGSC_OT (1 << USB0_OTGSC_OT_SHIFT)

/* DP: Data pulsing */
#define USB0_OTGSC_DP_SHIFT (4)
#define USB0_OTGSC_DP (1 << USB0_OTGSC_DP_SHIFT)

/* IDPU: ID pull-up */
#define USB0_OTGSC_IDPU_SHIFT (5)
#define USB0_OTGSC_IDPU (1 << USB0_OTGSC_IDPU_SHIFT)

/* HADP: Hardware assist data pulse */
#define USB0_OTGSC_HADP_SHIFT (6)
#define USB0_OTGSC_HADP (1 << USB0_OTGSC_HADP_SHIFT)

/* HABA: Hardware assist B-disconnect to A-connect */
#define USB0_OTGSC_HABA_SHIFT (7)
#define USB0_OTGSC_HABA (1 << USB0_OTGSC_HABA_SHIFT)

/* ID: USB ID */
#define USB0_OTGSC_ID_SHIFT (8)
#define USB0_OTGSC_ID (1 << USB0_OTGSC_ID_SHIFT)

/* AVV: A-VBUS valid */
#define USB0_OTGSC_AVV_SHIFT (9)
#define USB0_OTGSC_AVV (1 << USB0_OTGSC_AVV_SHIFT)

/* ASV: A-session valid */
#define USB0_OTGSC_ASV_SHIFT (10)
#define USB0_OTGSC_ASV (1 << USB0_OTGSC_ASV_SHIFT)

/* BSV: B-session valid */
#define USB0_OTGSC_BSV_SHIFT (11)
#define USB0_OTGSC_BSV (1 << USB0_OTGSC_BSV_SHIFT)

/* BSE: B-session end */
#define USB0_OTGSC_BSE_SHIFT (12)
#define USB0_OTGSC_BSE (1 << USB0_OTGSC_BSE_SHIFT)

/* MS1T: 1 millisecond timer toggle */
#define USB0_OTGSC_MS1T_SHIFT (13)
#define USB0_OTGSC_MS1T (1 << USB0_OTGSC_MS1T_SHIFT)

/* DPS: Data bus pulsing status */
#define USB0_OTGSC_DPS_SHIFT (14)
#define USB0_OTGSC_DPS (1 << USB0_OTGSC_DPS_SHIFT)

/* IDIS: USB ID interrupt status */
#define USB0_OTGSC_IDIS_SHIFT (16)
#define USB0_OTGSC_IDIS (1 << USB0_OTGSC_IDIS_SHIFT)

/* AVVIS: A-VBUS valid interrupt status */
#define USB0_OTGSC_AVVIS_SHIFT (17)
#define USB0_OTGSC_AVVIS (1 << USB0_OTGSC_AVVIS_SHIFT)

/* ASVIS: A-Session valid interrupt status */
#define USB0_OTGSC_ASVIS_SHIFT (18)
#define USB0_OTGSC_ASVIS (1 << USB0_OTGSC_ASVIS_SHIFT)

/* BSVIS: B-Session valid interrupt status */
#define USB0_OTGSC_BSVIS_SHIFT (19)
#define USB0_OTGSC_BSVIS (1 << USB0_OTGSC_BSVIS_SHIFT)

/* BSEIS: B-Session end interrupt status */
#define USB0_OTGSC_BSEIS_SHIFT (20)
#define USB0_OTGSC_BSEIS (1 << USB0_OTGSC_BSEIS_SHIFT)

/* MS1S: 1 millisecond timer interrupt status */
#define USB0_OTGSC_MS1S_SHIFT (21)
#define USB0_OTGSC_MS1S (1 << USB0_OTGSC_MS1S_SHIFT)

/* DPIS: Data pulse interrupt status */
#define USB0_OTGSC_DPIS_SHIFT (22)
#define USB0_OTGSC_DPIS (1 << USB0_OTGSC_DPIS_SHIFT)

/* IDIE: USB ID interrupt enable */
#define USB0_OTGSC_IDIE_SHIFT (24)
#define USB0_OTGSC_IDIE (1 << USB0_OTGSC_IDIE_SHIFT)

/* AVVIE: A-VBUS valid interrupt enable */
#define USB0_OTGSC_AVVIE_SHIFT (25)
#define USB0_OTGSC_AVVIE (1 << USB0_OTGSC_AVVIE_SHIFT)

/* ASVIE: A-session valid interrupt enable */
#define USB0_OTGSC_ASVIE_SHIFT (26)
#define USB0_OTGSC_ASVIE (1 << USB0_OTGSC_ASVIE_SHIFT)

/* BSVIE: B-session valid interrupt enable */
#define USB0_OTGSC_BSVIE_SHIFT (27)
#define USB0_OTGSC_BSVIE (1 << USB0_OTGSC_BSVIE_SHIFT)

/* BSEIE: B-session end interrupt enable */
#define USB0_OTGSC_BSEIE_SHIFT (28)
#define USB0_OTGSC_BSEIE (1 << USB0_OTGSC_BSEIE_SHIFT)

/* MS1E: 1 millisecond timer interrupt enable */
#define USB0_OTGSC_MS1E_SHIFT (29)
#define USB0_OTGSC_MS1E (1 << USB0_OTGSC_MS1E_SHIFT)

/* DPIE: Data pulse interrupt enable */
#define USB0_OTGSC_DPIE_SHIFT (30)
#define USB0_OTGSC_DPIE (1 << USB0_OTGSC_DPIE_SHIFT)

/* --- USB0_USBMODE_D values ------------------------------------ */

/* CM1_0: Controller mode */
#define USB0_USBMODE_D_CM1_0_SHIFT (0)
#define USB0_USBMODE_D_CM1_0_MASK (0x3 << USB0_USBMODE_D_CM1_0_SHIFT)
#define USB0_USBMODE_D_CM1_0(x) ((x) << USB0_USBMODE_D_CM1_0_SHIFT)

/* ES: Endian select */
#define USB0_USBMODE_D_ES_SHIFT (2)
#define USB0_USBMODE_D_ES (1 << USB0_USBMODE_D_ES_SHIFT)

/* SLOM: Setup Lockout mode */
#define USB0_USBMODE_D_SLOM_SHIFT (3)
#define USB0_USBMODE_D_SLOM (1 << USB0_USBMODE_D_SLOM_SHIFT)

/* SDIS: Setup Lockout mode */
#define USB0_USBMODE_D_SDIS_SHIFT (4)
#define USB0_USBMODE_D_SDIS (1 << USB0_USBMODE_D_SDIS_SHIFT)

/* --- USB0_USBMODE_H values ------------------------------------ */

/* CM: Controller mode */
#define USB0_USBMODE_H_CM_SHIFT (0)
#define USB0_USBMODE_H_CM_MASK (0x3 << USB0_USBMODE_H_CM_SHIFT)
#define USB0_USBMODE_H_CM(x) ((x) << USB0_USBMODE_H_CM_SHIFT)

/* ES: Endian select */
#define USB0_USBMODE_H_ES_SHIFT (2)
#define USB0_USBMODE_H_ES (1 << USB0_USBMODE_H_ES_SHIFT)

/* SDIS: Stream disable mode */
#define USB0_USBMODE_H_SDIS_SHIFT (4)
#define USB0_USBMODE_H_SDIS (1 << USB0_USBMODE_H_SDIS_SHIFT)

/* VBPS: VBUS power select */
#define USB0_USBMODE_H_VBPS_SHIFT (5)
#define USB0_USBMODE_H_VBPS (1 << USB0_USBMODE_H_VBPS_SHIFT)

/* --- USB0_ENDPTSETUPSTAT values ------------------------------- */

/* ENDPSETUPSTAT: Setup endpoint status for logical endpoints 0 to 5 */
#define USB0_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT (0)
#define USB0_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK \
			(0x3f << USB0_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT)
#define USB0_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x) \
			((x) << USB0_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT)

/* --- USB0_ENDPTPRIME values ----------------------------------- */

/* PERB: Prime endpoint receive buffer for physical OUT endpoints 5 to 0 */
#define USB0_ENDPTPRIME_PERB_SHIFT (0)
#define USB0_ENDPTPRIME_PERB_MASK (0x3f << USB0_ENDPTPRIME_PERB_SHIFT)
#define USB0_ENDPTPRIME_PERB(x) ((x) << USB0_ENDPTPRIME_PERB_SHIFT)

/* PETB: Prime endpoint transmit buffer for physical IN endpoints 5 to 0 */
#define USB0_ENDPTPRIME_PETB_SHIFT (16)
#define USB0_ENDPTPRIME_PETB_MASK (0x3f << USB0_ENDPTPRIME_PETB_SHIFT)
#define USB0_ENDPTPRIME_PETB(x) ((x) << USB0_ENDPTPRIME_PETB_SHIFT)

/* --- USB0_ENDPTFLUSH values ----------------------------------- */

/* FERB: Flush endpoint receive buffer for physical OUT endpoints 5 to 0 */
#define USB0_ENDPTFLUSH_FERB_SHIFT (0)
#define USB0_ENDPTFLUSH_FERB_MASK (0x3f << USB0_ENDPTFLUSH_FERB_SHIFT)
#define USB0_ENDPTFLUSH_FERB(x) ((x) << USB0_ENDPTFLUSH_FERB_SHIFT)

/* FETB: Flush endpoint transmit buffer for physical IN endpoints 5 to 0 */
#define USB0_ENDPTFLUSH_FETB_SHIFT (16)
#define USB0_ENDPTFLUSH_FETB_MASK (0x3f << USB0_ENDPTFLUSH_FETB_SHIFT)
#define USB0_ENDPTFLUSH_FETB(x) ((x) << USB0_ENDPTFLUSH_FETB_SHIFT)

/* --- USB0_ENDPTSTAT values ------------------------------------ */

/* ERBR: Endpoint receive buffer ready for physical OUT endpoints 5 to 0 */
#define USB0_ENDPTSTAT_ERBR_SHIFT (0)
#define USB0_ENDPTSTAT_ERBR_MASK (0x3f << USB0_ENDPTSTAT_ERBR_SHIFT)
#define USB0_ENDPTSTAT_ERBR(x) ((x) << USB0_ENDPTSTAT_ERBR_SHIFT)

/* ETBR: Endpoint transmit buffer ready for physical IN endpoints 3 to 0 */
#define USB0_ENDPTSTAT_ETBR_SHIFT (16)
#define USB0_ENDPTSTAT_ETBR_MASK (0x3f << USB0_ENDPTSTAT_ETBR_SHIFT)
#define USB0_ENDPTSTAT_ETBR(x) ((x) << USB0_ENDPTSTAT_ETBR_SHIFT)

/* --- USB0_ENDPTCOMPLETE values -------------------------------- */

/* ERCE: Endpoint receive complete event for physical OUT endpoints 5 to 0 */
#define USB0_ENDPTCOMPLETE_ERCE_SHIFT (0)
#define USB0_ENDPTCOMPLETE_ERCE_MASK (0x3f << USB0_ENDPTCOMPLETE_ERCE_SHIFT)
#define USB0_ENDPTCOMPLETE_ERCE(x) ((x) << USB0_ENDPTCOMPLETE_ERCE_SHIFT)

/* ETCE: Endpoint transmit complete event for physical IN endpoints 5 to 0 */
#define USB0_ENDPTCOMPLETE_ETCE_SHIFT (16)
#define USB0_ENDPTCOMPLETE_ETCE_MASK (0x3f << USB0_ENDPTCOMPLETE_ETCE_SHIFT)
#define USB0_ENDPTCOMPLETE_ETCE(x) ((x) << USB0_ENDPTCOMPLETE_ETCE_SHIFT)

/* --- USB0_ENDPTCTRL0 values ----------------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL0_RXS_SHIFT (0)
#define USB0_ENDPTCTRL0_RXS (1 << USB0_ENDPTCTRL0_RXS_SHIFT)

/* RXT1_0: Endpoint type */
#define USB0_ENDPTCTRL0_RXT1_0_SHIFT (2)
#define USB0_ENDPTCTRL0_RXT1_0_MASK (0x3 << USB0_ENDPTCTRL0_RXT1_0_SHIFT)
#define USB0_ENDPTCTRL0_RXT1_0(x) ((x) << USB0_ENDPTCTRL0_RXT1_0_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL0_RXE_SHIFT (7)
#define USB0_ENDPTCTRL0_RXE (1 << USB0_ENDPTCTRL0_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL0_TXS_SHIFT (16)
#define USB0_ENDPTCTRL0_TXS (1 << USB0_ENDPTCTRL0_TXS_SHIFT)

/* TXT1_0: Endpoint type */
#define USB0_ENDPTCTRL0_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL0_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL0_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL0_TXT1_0(x) ((x) << USB0_ENDPTCTRL0_TXT1_0_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL0_TXE_SHIFT (23)
#define USB0_ENDPTCTRL0_TXE (1 << USB0_ENDPTCTRL0_TXE_SHIFT)

/* --- USB0_ENDPTCTRL1 values ----------------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL1_RXS_SHIFT (0)
#define USB0_ENDPTCTRL1_RXS (1 << USB0_ENDPTCTRL1_RXS_SHIFT)

/* RXT: Endpoint type */
#define USB0_ENDPTCTRL1_RXT_SHIFT (2)
#define USB0_ENDPTCTRL1_RXT_MASK (0x3 << USB0_ENDPTCTRL1_RXT_SHIFT)
#define USB0_ENDPTCTRL1_RXT(x) ((x) << USB0_ENDPTCTRL1_RXT_SHIFT)

/* RXI: Rx data toggle inhibit */
#define USB0_ENDPTCTRL1_RXI_SHIFT (5)
#define USB0_ENDPTCTRL1_RXI (1 << USB0_ENDPTCTRL1_RXI_SHIFT)

/* RXR: Rx data toggle reset */
#define USB0_ENDPTCTRL1_RXR_SHIFT (6)
#define USB0_ENDPTCTRL1_RXR (1 << USB0_ENDPTCTRL1_RXR_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL1_RXE_SHIFT (7)
#define USB0_ENDPTCTRL1_RXE (1 << USB0_ENDPTCTRL1_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL1_TXS_SHIFT (16)
#define USB0_ENDPTCTRL1_TXS (1 << USB0_ENDPTCTRL1_TXS_SHIFT)

/* TXT1_0: Tx Endpoint type */
#define USB0_ENDPTCTRL1_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL1_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL1_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL1_TXT1_0(x) ((x) << USB0_ENDPTCTRL1_TXT1_0_SHIFT)

/* TXI: Tx data toggle inhibit */
#define USB0_ENDPTCTRL1_TXI_SHIFT (21)
#define USB0_ENDPTCTRL1_TXI (1 << USB0_ENDPTCTRL1_TXI_SHIFT)

/* TXR: Tx data toggle reset */
#define USB0_ENDPTCTRL1_TXR_SHIFT (22)
#define USB0_ENDPTCTRL1_TXR (1 << USB0_ENDPTCTRL1_TXR_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL1_TXE_SHIFT (23)
#define USB0_ENDPTCTRL1_TXE (1 << USB0_ENDPTCTRL1_TXE_SHIFT)

/* --- USB0_ENDPTCTRL2 values ----------------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL2_RXS_SHIFT (0)
#define USB0_ENDPTCTRL2_RXS (1 << USB0_ENDPTCTRL2_RXS_SHIFT)

/* RXT: Endpoint type */
#define USB0_ENDPTCTRL2_RXT_SHIFT (2)
#define USB0_ENDPTCTRL2_RXT_MASK (0x3 << USB0_ENDPTCTRL2_RXT_SHIFT)
#define USB0_ENDPTCTRL2_RXT(x) ((x) << USB0_ENDPTCTRL2_RXT_SHIFT)

/* RXI: Rx data toggle inhibit */
#define USB0_ENDPTCTRL2_RXI_SHIFT (5)
#define USB0_ENDPTCTRL2_RXI (1 << USB0_ENDPTCTRL2_RXI_SHIFT)

/* RXR: Rx data toggle reset */
#define USB0_ENDPTCTRL2_RXR_SHIFT (6)
#define USB0_ENDPTCTRL2_RXR (1 << USB0_ENDPTCTRL2_RXR_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL2_RXE_SHIFT (7)
#define USB0_ENDPTCTRL2_RXE (1 << USB0_ENDPTCTRL2_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL2_TXS_SHIFT (16)
#define USB0_ENDPTCTRL2_TXS (1 << USB0_ENDPTCTRL2_TXS_SHIFT)

/* TXT1_0: Tx Endpoint type */
#define USB0_ENDPTCTRL2_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL2_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL2_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL2_TXT1_0(x) ((x) << USB0_ENDPTCTRL2_TXT1_0_SHIFT)

/* TXI: Tx data toggle inhibit */
#define USB0_ENDPTCTRL2_TXI_SHIFT (21)
#define USB0_ENDPTCTRL2_TXI (1 << USB0_ENDPTCTRL2_TXI_SHIFT)

/* TXR: Tx data toggle reset */
#define USB0_ENDPTCTRL2_TXR_SHIFT (22)
#define USB0_ENDPTCTRL2_TXR (1 << USB0_ENDPTCTRL2_TXR_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL2_TXE_SHIFT (23)
#define USB0_ENDPTCTRL2_TXE (1 << USB0_ENDPTCTRL2_TXE_SHIFT)

/* --- USB0_ENDPTCTRL3 values ----------------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL3_RXS_SHIFT (0)
#define USB0_ENDPTCTRL3_RXS (1 << USB0_ENDPTCTRL3_RXS_SHIFT)

/* RXT: Endpoint type */
#define USB0_ENDPTCTRL3_RXT_SHIFT (2)
#define USB0_ENDPTCTRL3_RXT_MASK (0x3 << USB0_ENDPTCTRL3_RXT_SHIFT)
#define USB0_ENDPTCTRL3_RXT(x) ((x) << USB0_ENDPTCTRL3_RXT_SHIFT)

/* RXI: Rx data toggle inhibit */
#define USB0_ENDPTCTRL3_RXI_SHIFT (5)
#define USB0_ENDPTCTRL3_RXI (1 << USB0_ENDPTCTRL3_RXI_SHIFT)

/* RXR: Rx data toggle reset */
#define USB0_ENDPTCTRL3_RXR_SHIFT (6)
#define USB0_ENDPTCTRL3_RXR (1 << USB0_ENDPTCTRL3_RXR_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL3_RXE_SHIFT (7)
#define USB0_ENDPTCTRL3_RXE (1 << USB0_ENDPTCTRL3_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL3_TXS_SHIFT (16)
#define USB0_ENDPTCTRL3_TXS (1 << USB0_ENDPTCTRL3_TXS_SHIFT)

/* TXT1_0: Tx Endpoint type */
#define USB0_ENDPTCTRL3_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL3_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL3_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL3_TXT1_0(x) ((x) << USB0_ENDPTCTRL3_TXT1_0_SHIFT)

/* TXI: Tx data toggle inhibit */
#define USB0_ENDPTCTRL3_TXI_SHIFT (21)
#define USB0_ENDPTCTRL3_TXI (1 << USB0_ENDPTCTRL3_TXI_SHIFT)

/* TXR: Tx data toggle reset */
#define USB0_ENDPTCTRL3_TXR_SHIFT (22)
#define USB0_ENDPTCTRL3_TXR (1 << USB0_ENDPTCTRL3_TXR_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL3_TXE_SHIFT (23)
#define USB0_ENDPTCTRL3_TXE (1 << USB0_ENDPTCTRL3_TXE_SHIFT)

/* --- USB0_ENDPTCTRL4 values ----------------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL4_RXS_SHIFT (0)
#define USB0_ENDPTCTRL4_RXS (1 << USB0_ENDPTCTRL4_RXS_SHIFT)

/* RXT: Endpoint type */
#define USB0_ENDPTCTRL4_RXT_SHIFT (2)
#define USB0_ENDPTCTRL4_RXT_MASK (0x3 << USB0_ENDPTCTRL4_RXT_SHIFT)
#define USB0_ENDPTCTRL4_RXT(x) ((x) << USB0_ENDPTCTRL4_RXT_SHIFT)

/* RXI: Rx data toggle inhibit */
#define USB0_ENDPTCTRL4_RXI_SHIFT (5)
#define USB0_ENDPTCTRL4_RXI (1 << USB0_ENDPTCTRL4_RXI_SHIFT)

/* RXR: Rx data toggle reset */
#define USB0_ENDPTCTRL4_RXR_SHIFT (6)
#define USB0_ENDPTCTRL4_RXR (1 << USB0_ENDPTCTRL4_RXR_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL4_RXE_SHIFT (7)
#define USB0_ENDPTCTRL4_RXE (1 << USB0_ENDPTCTRL4_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL4_TXS_SHIFT (16)
#define USB0_ENDPTCTRL4_TXS (1 << USB0_ENDPTCTRL4_TXS_SHIFT)

/* TXT1_0: Tx Endpoint type */
#define USB0_ENDPTCTRL4_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL4_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL4_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL4_TXT1_0(x) ((x) << USB0_ENDPTCTRL4_TXT1_0_SHIFT)

/* TXI: Tx data toggle inhibit */
#define USB0_ENDPTCTRL4_TXI_SHIFT (21)
#define USB0_ENDPTCTRL4_TXI (1 << USB0_ENDPTCTRL4_TXI_SHIFT)

/* TXR: Tx data toggle reset */
#define USB0_ENDPTCTRL4_TXR_SHIFT (22)
#define USB0_ENDPTCTRL4_TXR (1 << USB0_ENDPTCTRL4_TXR_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL4_TXE_SHIFT (23)
#define USB0_ENDPTCTRL4_TXE (1 << USB0_ENDPTCTRL4_TXE_SHIFT)

/* --- USB0_ENDPTCTRL5 values ----------------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL5_RXS_SHIFT (0)
#define USB0_ENDPTCTRL5_RXS (1 << USB0_ENDPTCTRL5_RXS_SHIFT)

/* RXT: Endpoint type */
#define USB0_ENDPTCTRL5_RXT_SHIFT (2)
#define USB0_ENDPTCTRL5_RXT_MASK (0x3 << USB0_ENDPTCTRL5_RXT_SHIFT)
#define USB0_ENDPTCTRL5_RXT(x) ((x) << USB0_ENDPTCTRL5_RXT_SHIFT)

/* RXI: Rx data toggle inhibit */
#define USB0_ENDPTCTRL5_RXI_SHIFT (5)
#define USB0_ENDPTCTRL5_RXI (1 << USB0_ENDPTCTRL5_RXI_SHIFT)

/* RXR: Rx data toggle reset */
#define USB0_ENDPTCTRL5_RXR_SHIFT (6)
#define USB0_ENDPTCTRL5_RXR (1 << USB0_ENDPTCTRL5_RXR_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL5_RXE_SHIFT (7)
#define USB0_ENDPTCTRL5_RXE (1 << USB0_ENDPTCTRL5_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL5_TXS_SHIFT (16)
#define USB0_ENDPTCTRL5_TXS (1 << USB0_ENDPTCTRL5_TXS_SHIFT)

/* TXT1_0: Tx Endpoint type */
#define USB0_ENDPTCTRL5_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL5_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL5_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL5_TXT1_0(x) ((x) << USB0_ENDPTCTRL5_TXT1_0_SHIFT)

/* TXI: Tx data toggle inhibit */
#define USB0_ENDPTCTRL5_TXI_SHIFT (21)
#define USB0_ENDPTCTRL5_TXI (1 << USB0_ENDPTCTRL5_TXI_SHIFT)

/* TXR: Tx data toggle reset */
#define USB0_ENDPTCTRL5_TXR_SHIFT (22)
#define USB0_ENDPTCTRL5_TXR (1 << USB0_ENDPTCTRL5_TXR_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL5_TXE_SHIFT (23)
#define USB0_ENDPTCTRL5_TXE (1 << USB0_ENDPTCTRL5_TXE_SHIFT)

/* -------------------------------------------------------------- */


/* --- USB0_ENDPTCTRL common values ----------------------------- */

/* RXS: Rx endpoint stall */
#define USB0_ENDPTCTRL_RXS_SHIFT (0)
#define USB0_ENDPTCTRL_RXS (1 << USB0_ENDPTCTRL_RXS_SHIFT)

/* RXT: Endpoint type */
#define USB0_ENDPTCTRL_RXT_SHIFT (2)
#define USB0_ENDPTCTRL_RXT_MASK (0x3 << USB0_ENDPTCTRL_RXT_SHIFT)
#define USB0_ENDPTCTRL_RXT(x) ((x) << USB0_ENDPTCTRL_RXT_SHIFT)

/* RXI: Rx data toggle inhibit */
#define USB0_ENDPTCTRL_RXI_SHIFT (5)
#define USB0_ENDPTCTRL_RXI (1 << USB0_ENDPTCTRL_RXI_SHIFT)

/* RXR: Rx data toggle reset */
#define USB0_ENDPTCTRL_RXR_SHIFT (6)
#define USB0_ENDPTCTRL_RXR (1 << USB0_ENDPTCTRL_RXR_SHIFT)

/* RXE: Rx endpoint enable */
#define USB0_ENDPTCTRL_RXE_SHIFT (7)
#define USB0_ENDPTCTRL_RXE (1 << USB0_ENDPTCTRL_RXE_SHIFT)

/* TXS: Tx endpoint stall */
#define USB0_ENDPTCTRL_TXS_SHIFT (16)
#define USB0_ENDPTCTRL_TXS (1 << USB0_ENDPTCTRL_TXS_SHIFT)

/* TXT1_0: Tx Endpoint type */
#define USB0_ENDPTCTRL_TXT1_0_SHIFT (18)
#define USB0_ENDPTCTRL_TXT1_0_MASK (0x3 << USB0_ENDPTCTRL_TXT1_0_SHIFT)
#define USB0_ENDPTCTRL_TXT1_0(x) ((x) << USB0_ENDPTCTRL_TXT1_0_SHIFT)

/* TXI: Tx data toggle inhibit */
#define USB0_ENDPTCTRL_TXI_SHIFT (21)
#define USB0_ENDPTCTRL_TXI (1 << USB0_ENDPTCTRL_TXI_SHIFT)

/* TXR: Tx data toggle reset */
#define USB0_ENDPTCTRL_TXR_SHIFT (22)
#define USB0_ENDPTCTRL_TXR (1 << USB0_ENDPTCTRL_TXR_SHIFT)

/* TXE: Tx endpoint enable */
#define USB0_ENDPTCTRL_TXE_SHIFT (23)
#define USB0_ENDPTCTRL_TXE (1 << USB0_ENDPTCTRL_TXE_SHIFT)





/* --- USB1 registers ------------------------------------------------------ */
/* TODO */

#endif
