/** @defgroup gpdma_defines General Purpose DMA Defines
 *
 * @brief <b>Defined Constants and Types for the LPC43xx General Purpose DMA</b>
 *
 * @ingroup LPC43xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>
 *
 * @date 10 March 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
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

#ifndef LPC43XX_GPDMA_H
#define LPC43XX_GPDMA_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- GPDMA registers ----------------------------------------------------- */

/* General registers */

/* DMA Interrupt Status Register */
#define GPDMA_INTSTAT                   MMIO32(GPDMA_BASE + 0x000)

/* DMA Interrupt Terminal Count Request Status Register */
#define GPDMA_INTTCSTAT                 MMIO32(GPDMA_BASE + 0x004)

/* DMA Interrupt Terminal Count Request Clear Register */
#define GPDMA_INTTCCLEAR                MMIO32(GPDMA_BASE + 0x008)

/* DMA Interrupt Error Status Register */
#define GPDMA_INTERRSTAT                MMIO32(GPDMA_BASE + 0x00C)

/* DMA Interrupt Error Clear Register */
#define GPDMA_INTERRCLR                 MMIO32(GPDMA_BASE + 0x010)

/* DMA Raw Interrupt Terminal Count Status Register */
#define GPDMA_RAWINTTCSTAT              MMIO32(GPDMA_BASE + 0x014)

/* DMA Raw Error Interrupt Status Register */
#define GPDMA_RAWINTERRSTAT             MMIO32(GPDMA_BASE + 0x018)

/* DMA Enabled Channel Register */
#define GPDMA_ENBLDCHNS                 MMIO32(GPDMA_BASE + 0x01C)

/* DMA Software Burst Request Register */
#define GPDMA_SOFTBREQ                  MMIO32(GPDMA_BASE + 0x020)

/* DMA Software Single Request Register */
#define GPDMA_SOFTSREQ                  MMIO32(GPDMA_BASE + 0x024)

/* DMA Software Last Burst Request Register */
#define GPDMA_SOFTLBREQ                 MMIO32(GPDMA_BASE + 0x028)

/* DMA Software Last Single Request Register */
#define GPDMA_SOFTLSREQ                 MMIO32(GPDMA_BASE + 0x02C)

/* DMA Configuration Register */
#define GPDMA_CONFIG                    MMIO32(GPDMA_BASE + 0x030)

/* DMA Synchronization Register */
#define GPDMA_SYNC                      MMIO32(GPDMA_BASE + 0x034)


/* Channel registers */

/* Source Address Register */
#define GPDMA_CSRCADDR(channel)         MMIO32(GPDMA_BASE + 0x100 + \
							(channel * 0x20))
#define GPDMA_C0SRCADDR                 GPDMA_CSRCADDR(0)
#define GPDMA_C1SRCADDR                 GPDMA_CSRCADDR(1)
#define GPDMA_C2SRCADDR                 GPDMA_CSRCADDR(2)
#define GPDMA_C3SRCADDR                 GPDMA_CSRCADDR(3)
#define GPDMA_C4SRCADDR                 GPDMA_CSRCADDR(4)
#define GPDMA_C5SRCADDR                 GPDMA_CSRCADDR(5)
#define GPDMA_C6SRCADDR                 GPDMA_CSRCADDR(6)
#define GPDMA_C7SRCADDR                 GPDMA_CSRCADDR(7)

/* Destination Address Register */
#define GPDMA_CDESTADDR(channel)        MMIO32(GPDMA_BASE + 0x104 + \
							(channel * 0x20))
#define GPDMA_C0DESTADDR                GPDMA_CDESTADDR(0)
#define GPDMA_C1DESTADDR                GPDMA_CDESTADDR(1)
#define GPDMA_C2DESTADDR                GPDMA_CDESTADDR(2)
#define GPDMA_C3DESTADDR                GPDMA_CDESTADDR(3)
#define GPDMA_C4DESTADDR                GPDMA_CDESTADDR(4)
#define GPDMA_C5DESTADDR                GPDMA_CDESTADDR(5)
#define GPDMA_C6DESTADDR                GPDMA_CDESTADDR(6)
#define GPDMA_C7DESTADDR                GPDMA_CDESTADDR(7)

/* Linked List Item Register */
#define GPDMA_CLLI(channel)             MMIO32(GPDMA_BASE + 0x108 + \
							(channel * 0x20))
#define GPDMA_C0LLI                     GPDMA_CLLI(0)
#define GPDMA_C1LLI                     GPDMA_CLLI(1)
#define GPDMA_C2LLI                     GPDMA_CLLI(2)
#define GPDMA_C3LLI                     GPDMA_CLLI(3)
#define GPDMA_C4LLI                     GPDMA_CLLI(4)
#define GPDMA_C5LLI                     GPDMA_CLLI(5)
#define GPDMA_C6LLI                     GPDMA_CLLI(6)
#define GPDMA_C7LLI                     GPDMA_CLLI(7)

/* Control Register */
#define GPDMA_CCONTROL(channel)         MMIO32(GPDMA_BASE + 0x10C + \
							(channel * 0x20))
#define GPDMA_C0CONTROL                 GPDMA_CCONTROL(0)
#define GPDMA_C1CONTROL                 GPDMA_CCONTROL(1)
#define GPDMA_C2CONTROL                 GPDMA_CCONTROL(2)
#define GPDMA_C3CONTROL                 GPDMA_CCONTROL(3)
#define GPDMA_C4CONTROL                 GPDMA_CCONTROL(4)
#define GPDMA_C5CONTROL                 GPDMA_CCONTROL(5)
#define GPDMA_C6CONTROL                 GPDMA_CCONTROL(6)
#define GPDMA_C7CONTROL                 GPDMA_CCONTROL(7)

/* Configuration Register */
#define GPDMA_CCONFIG(channel)          MMIO32(GPDMA_BASE + 0x110 + \
							(channel * 0x20))
#define GPDMA_C0CONFIG                  GPDMA_CCONFIG(0)
#define GPDMA_C1CONFIG                  GPDMA_CCONFIG(1)
#define GPDMA_C2CONFIG                  GPDMA_CCONFIG(2)
#define GPDMA_C3CONFIG                  GPDMA_CCONFIG(3)
#define GPDMA_C4CONFIG                  GPDMA_CCONFIG(4)
#define GPDMA_C5CONFIG                  GPDMA_CCONFIG(5)
#define GPDMA_C6CONFIG                  GPDMA_CCONFIG(6)
#define GPDMA_C7CONFIG                  GPDMA_CCONFIG(7)

/* --- Common fields -------------------------------------------- */

#define GPDMA_CSRCADDR_SRCADDR_SHIFT (0)
#define GPDMA_CSRCADDR_SRCADDR_MASK (0xffffffff << GPDMA_CSRCADDR_SRCADDR_SHIFT)
#define GPDMA_CSRCADDR_SRCADDR(x) ((x) << GPDMA_CSRCADDR_SRCADDR_SHIFT)

#define GPDMA_CDESTADDR_DESTADDR_SHIFT (0)
#define GPDMA_CDESTADDR_DESTADDR_MASK \
			(0xffffffff << GPDMA_CDESTADDR_DESTADDR_SHIFT)
#define GPDMA_CDESTADDR_DESTADDR(x) ((x) << GPDMA_CDESTADDR_DESTADDR_SHIFT)

#define GPDMA_CLLI_LM_SHIFT (0)
#define GPDMA_CLLI_LM_MASK (0x1 << GPDMA_CLLI_LM_SHIFT)
#define GPDMA_CLLI_LM(x) ((x) << GPDMA_CLLI_LM_SHIFT)

#define GPDMA_CLLI_LLI_SHIFT (2)
#define GPDMA_CLLI_LLI_MASK (0x3fffffff << GPDMA_CLLI_LLI_SHIFT)
#define GPDMA_CLLI_LLI(x) ((x) << GPDMA_CLLI_LLI_SHIFT)

#define GPDMA_CCONTROL_TRANSFERSIZE_SHIFT (0)
#define GPDMA_CCONTROL_TRANSFERSIZE_MASK \
			(0xfff << GPDMA_CCONTROL_TRANSFERSIZE_SHIFT)
#define GPDMA_CCONTROL_TRANSFERSIZE(x) \
			((x) << GPDMA_CCONTROL_TRANSFERSIZE_SHIFT)

#define GPDMA_CCONTROL_SBSIZE_SHIFT (12)
#define GPDMA_CCONTROL_SBSIZE_MASK (0x7 << GPDMA_CCONTROL_SBSIZE_SHIFT)
#define GPDMA_CCONTROL_SBSIZE(x) ((x) << GPDMA_CCONTROL_SBSIZE_SHIFT)

#define GPDMA_CCONTROL_DBSIZE_SHIFT (15)
#define GPDMA_CCONTROL_DBSIZE_MASK (0x7 << GPDMA_CCONTROL_DBSIZE_SHIFT)
#define GPDMA_CCONTROL_DBSIZE(x) ((x) << GPDMA_CCONTROL_DBSIZE_SHIFT)

#define GPDMA_CCONTROL_SWIDTH_SHIFT (18)
#define GPDMA_CCONTROL_SWIDTH_MASK (0x7 << GPDMA_CCONTROL_SWIDTH_SHIFT)
#define GPDMA_CCONTROL_SWIDTH(x) ((x) << GPDMA_CCONTROL_SWIDTH_SHIFT)

#define GPDMA_CCONTROL_DWIDTH_SHIFT (21)
#define GPDMA_CCONTROL_DWIDTH_MASK (0x7 << GPDMA_CCONTROL_DWIDTH_SHIFT)
#define GPDMA_CCONTROL_DWIDTH(x) ((x) << GPDMA_CCONTROL_DWIDTH_SHIFT)

#define GPDMA_CCONTROL_S_SHIFT (24)
#define GPDMA_CCONTROL_S_MASK (0x1 << GPDMA_CCONTROL_S_SHIFT)
#define GPDMA_CCONTROL_S(x) ((x) << GPDMA_CCONTROL_S_SHIFT)

#define GPDMA_CCONTROL_D_SHIFT (25)
#define GPDMA_CCONTROL_D_MASK (0x1 << GPDMA_CCONTROL_D_SHIFT)
#define GPDMA_CCONTROL_D(x) ((x) << GPDMA_CCONTROL_D_SHIFT)

#define GPDMA_CCONTROL_SI_SHIFT (26)
#define GPDMA_CCONTROL_SI_MASK (0x1 << GPDMA_CCONTROL_SI_SHIFT)
#define GPDMA_CCONTROL_SI(x) ((x) << GPDMA_CCONTROL_SI_SHIFT)

#define GPDMA_CCONTROL_DI_SHIFT (27)
#define GPDMA_CCONTROL_DI_MASK (0x1 << GPDMA_CCONTROL_DI_SHIFT)
#define GPDMA_CCONTROL_DI(x) ((x) << GPDMA_CCONTROL_DI_SHIFT)

#define GPDMA_CCONTROL_PROT1_SHIFT (28)
#define GPDMA_CCONTROL_PROT1_MASK (0x1 << GPDMA_CCONTROL_PROT1_SHIFT)
#define GPDMA_CCONTROL_PROT1(x) ((x) << GPDMA_CCONTROL_PROT1_SHIFT)

#define GPDMA_CCONTROL_PROT2_SHIFT (29)
#define GPDMA_CCONTROL_PROT2_MASK (0x1 << GPDMA_CCONTROL_PROT2_SHIFT)
#define GPDMA_CCONTROL_PROT2(x) ((x) << GPDMA_CCONTROL_PROT2_SHIFT)

#define GPDMA_CCONTROL_PROT3_SHIFT (30)
#define GPDMA_CCONTROL_PROT3_MASK (0x1 << GPDMA_CCONTROL_PROT3_SHIFT)
#define GPDMA_CCONTROL_PROT3(x) ((x) << GPDMA_CCONTROL_PROT3_SHIFT)

#define GPDMA_CCONTROL_I_SHIFT (31)
#define GPDMA_CCONTROL_I_MASK (0x1 << GPDMA_CCONTROL_I_SHIFT)
#define GPDMA_CCONTROL_I(x) ((x) << GPDMA_CCONTROL_I_SHIFT)

#define GPDMA_CCONFIG_E_SHIFT (0)
#define GPDMA_CCONFIG_E_MASK (0x1 << GPDMA_CCONFIG_E_SHIFT)
#define GPDMA_CCONFIG_E(x) ((x) << GPDMA_CCONFIG_E_SHIFT)

#define GPDMA_CCONFIG_SRCPERIPHERAL_SHIFT (1)
#define GPDMA_CCONFIG_SRCPERIPHERAL_MASK \
			(0x1f << GPDMA_CCONFIG_SRCPERIPHERAL_SHIFT)
#define GPDMA_CCONFIG_SRCPERIPHERAL(x) \
			((x) << GPDMA_CCONFIG_SRCPERIPHERAL_SHIFT)

#define GPDMA_CCONFIG_DESTPERIPHERAL_SHIFT (6)
#define GPDMA_CCONFIG_DESTPERIPHERAL_MASK \
			(0x1f << GPDMA_CCONFIG_DESTPERIPHERAL_SHIFT)
#define GPDMA_CCONFIG_DESTPERIPHERAL(x) \
			((x) << GPDMA_CCONFIG_DESTPERIPHERAL_SHIFT)

#define GPDMA_CCONFIG_FLOWCNTRL_SHIFT (11)
#define GPDMA_CCONFIG_FLOWCNTRL_MASK (0x7 << GPDMA_CCONFIG_FLOWCNTRL_SHIFT)
#define GPDMA_CCONFIG_FLOWCNTRL(x) ((x) << GPDMA_CCONFIG_FLOWCNTRL_SHIFT)

#define GPDMA_CCONFIG_IE_SHIFT (14)
#define GPDMA_CCONFIG_IE_MASK (0x1 << GPDMA_CCONFIG_IE_SHIFT)
#define GPDMA_CCONFIG_IE(x) ((x) << GPDMA_CCONFIG_IE_SHIFT)

#define GPDMA_CCONFIG_ITC_SHIFT (15)
#define GPDMA_CCONFIG_ITC_MASK (0x1 << GPDMA_CCONFIG_ITC_SHIFT)
#define GPDMA_CCONFIG_ITC(x) ((x) << GPDMA_CCONFIG_ITC_SHIFT)

#define GPDMA_CCONFIG_L_SHIFT (16)
#define GPDMA_CCONFIG_L_MASK (0x1 << GPDMA_CCONFIG_L_SHIFT)
#define GPDMA_CCONFIG_L(x) ((x) << GPDMA_CCONFIG_L_SHIFT)

#define GPDMA_CCONFIG_A_SHIFT (17)
#define GPDMA_CCONFIG_A_MASK (0x1 << GPDMA_CCONFIG_A_SHIFT)
#define GPDMA_CCONFIG_A(x) ((x) << GPDMA_CCONFIG_A_SHIFT)

#define GPDMA_CCONFIG_H_SHIFT (18)
#define GPDMA_CCONFIG_H_MASK (0x1 << GPDMA_CCONFIG_H_SHIFT)
#define GPDMA_CCONFIG_H(x) ((x) << GPDMA_CCONFIG_H_SHIFT)

/* --- AUTO-GENERATED STUFF FOLLOWS ----------------------------- */

/* --- GPDMA_NTSTAT values -------------------------------------- */

/* INTSTAT: Status of DMA channel interrupts after masking */
#define GPDMA_NTSTAT_INTSTAT_SHIFT (0)
#define GPDMA_NTSTAT_INTSTAT_MASK (0xff << GPDMA_NTSTAT_INTSTAT_SHIFT)
#define GPDMA_NTSTAT_INTSTAT(x) ((x) << GPDMA_NTSTAT_INTSTAT_SHIFT)

/* --- GPDMA_INTTCSTAT values ----------------------------------- */

/* INTTCSTAT: Terminal count interrupt request status for DMA channels */
#define GPDMA_INTTCSTAT_INTTCSTAT_SHIFT (0)
#define GPDMA_INTTCSTAT_INTTCSTAT_MASK (0xff << GPDMA_INTTCSTAT_INTTCSTAT_SHIFT)
#define GPDMA_INTTCSTAT_INTTCSTAT(x) ((x) << GPDMA_INTTCSTAT_INTTCSTAT_SHIFT)

/* --- GPDMA_INTTCCLEAR values ---------------------------------- */

/* INTTCCLEAR: Allows clearing the Terminal count interrupt request (IntTCStat)
   for DMA channels */
#define GPDMA_INTTCCLEAR_INTTCCLEAR_SHIFT (0)
#define GPDMA_INTTCCLEAR_INTTCCLEAR_MASK \
			(0xff << GPDMA_INTTCCLEAR_INTTCCLEAR_SHIFT)
#define GPDMA_INTTCCLEAR_INTTCCLEAR(x) \
			((x) << GPDMA_INTTCCLEAR_INTTCCLEAR_SHIFT)

/* --- GPDMA_INTERRSTAT values ---------------------------------- */

/* INTERRSTAT: Interrupt error status for DMA channels */
#define GPDMA_INTERRSTAT_INTERRSTAT_SHIFT (0)
#define GPDMA_INTERRSTAT_INTERRSTAT_MASK \
			(0xff << GPDMA_INTERRSTAT_INTERRSTAT_SHIFT)
#define GPDMA_INTERRSTAT_INTERRSTAT(x) \
			((x) << GPDMA_INTERRSTAT_INTERRSTAT_SHIFT)

/* --- GPDMA_INTERRCLR values ----------------------------------- */

/* INTERRCLR: Writing a 1 clears the error interrupt request (IntErrStat)
   for DMA channels */
#define GPDMA_INTERRCLR_INTERRCLR_SHIFT (0)
#define GPDMA_INTERRCLR_INTERRCLR_MASK \
			(0xff << GPDMA_INTERRCLR_INTERRCLR_SHIFT)
#define GPDMA_INTERRCLR_INTERRCLR(x) \
			((x) << GPDMA_INTERRCLR_INTERRCLR_SHIFT)

/* --- GPDMA_RAWINTTCSTAT values -------------------------------- */

/* RAWINTTCSTAT: Status of the terminal count interrupt for DMA channels
   prior to masking */
#define GPDMA_RAWINTTCSTAT_RAWINTTCSTAT_SHIFT (0)
#define GPDMA_RAWINTTCSTAT_RAWINTTCSTAT_MASK \
			(0xff << GPDMA_RAWINTTCSTAT_RAWINTTCSTAT_SHIFT)
#define GPDMA_RAWINTTCSTAT_RAWINTTCSTAT(x) \
			((x) << GPDMA_RAWINTTCSTAT_RAWINTTCSTAT_SHIFT)

/* --- GPDMA_RAWINTERRSTAT values ------------------------------- */

/* RAWINTERRSTAT: Status of the error interrupt for DMA channels prior to
   masking */
#define GPDMA_RAWINTERRSTAT_RAWINTERRSTAT_SHIFT (0)
#define GPDMA_RAWINTERRSTAT_RAWINTERRSTAT_MASK \
			(0xff << GPDMA_RAWINTERRSTAT_RAWINTERRSTAT_SHIFT)
#define GPDMA_RAWINTERRSTAT_RAWINTERRSTAT(x) \
			((x) << GPDMA_RAWINTERRSTAT_RAWINTERRSTAT_SHIFT)

/* --- GPDMA_ENBLDCHNS values ----------------------------------- */

/* ENABLEDCHANNELS: Enable status for DMA channels */
#define GPDMA_ENBLDCHNS_ENABLEDCHANNELS_SHIFT (0)
#define GPDMA_ENBLDCHNS_ENABLEDCHANNELS_MASK \
			(0xff << GPDMA_ENBLDCHNS_ENABLEDCHANNELS_SHIFT)
#define GPDMA_ENBLDCHNS_ENABLEDCHANNELS(x) \
			((x) << GPDMA_ENBLDCHNS_ENABLEDCHANNELS_SHIFT)

/* --- GPDMA_SOFTBREQ values ------------------------------------ */

/* SOFTBREQ: Software burst request flags for each of 16 possible sources */
#define GPDMA_SOFTBREQ_SOFTBREQ_SHIFT (0)
#define GPDMA_SOFTBREQ_SOFTBREQ_MASK (0xffff << GPDMA_SOFTBREQ_SOFTBREQ_SHIFT)
#define GPDMA_SOFTBREQ_SOFTBREQ(x) ((x) << GPDMA_SOFTBREQ_SOFTBREQ_SHIFT)

/* --- GPDMA_SOFTSREQ values ------------------------------------ */

/* SOFTSREQ: Software single transfer request flags for each of 16 possible
  sources */
#define GPDMA_SOFTSREQ_SOFTSREQ_SHIFT (0)
#define GPDMA_SOFTSREQ_SOFTSREQ_MASK (0xffff << GPDMA_SOFTSREQ_SOFTSREQ_SHIFT)
#define GPDMA_SOFTSREQ_SOFTSREQ(x) ((x) << GPDMA_SOFTSREQ_SOFTSREQ_SHIFT)

/* --- GPDMA_SOFTLBREQ values ----------------------------------- */

/* SOFTLBREQ: Software last burst request flags for each of 16 possible
 sources */
#define GPDMA_SOFTLBREQ_SOFTLBREQ_SHIFT (0)
#define GPDMA_SOFTLBREQ_SOFTLBREQ_MASK \
			(0xffff << GPDMA_SOFTLBREQ_SOFTLBREQ_SHIFT)
#define GPDMA_SOFTLBREQ_SOFTLBREQ(x) \
			((x) << GPDMA_SOFTLBREQ_SOFTLBREQ_SHIFT)

/* --- GPDMA_SOFTLSREQ values ----------------------------------- */

/* SOFTLSREQ: Software last single transfer request flags for each of 16
 possible sources */
#define GPDMA_SOFTLSREQ_SOFTLSREQ_SHIFT (0)
#define GPDMA_SOFTLSREQ_SOFTLSREQ_MASK \
			(0xffff << GPDMA_SOFTLSREQ_SOFTLSREQ_SHIFT)
#define GPDMA_SOFTLSREQ_SOFTLSREQ(x) \
			((x) << GPDMA_SOFTLSREQ_SOFTLSREQ_SHIFT)

/* --- GPDMA_CONFIG values -------------------------------------- */

/* E: DMA Controller enable */
#define GPDMA_CONFIG_E_SHIFT (0)
#define GPDMA_CONFIG_E_MASK (0x1 << GPDMA_CONFIG_E_SHIFT)
#define GPDMA_CONFIG_E(x) ((x) << GPDMA_CONFIG_E_SHIFT)

/* M0: AHB Master 0 endianness configuration */
#define GPDMA_CONFIG_M0_SHIFT (1)
#define GPDMA_CONFIG_M0_MASK (0x1 << GPDMA_CONFIG_M0_SHIFT)
#define GPDMA_CONFIG_M0(x) ((x) << GPDMA_CONFIG_M0_SHIFT)

/* M1: AHB Master 1 endianness configuration */
#define GPDMA_CONFIG_M1_SHIFT (2)
#define GPDMA_CONFIG_M1_MASK (0x1 << GPDMA_CONFIG_M1_SHIFT)
#define GPDMA_CONFIG_M1(x) ((x) << GPDMA_CONFIG_M1_SHIFT)

/* --- GPDMA_SYNC values ---------------------------------------- */

/* DMACSYNC: Controls the synchronization logic for DMA request signals */
#define GPDMA_SYNC_DMACSYNC_SHIFT (0)
#define GPDMA_SYNC_DMACSYNC_MASK (0xffff << GPDMA_SYNC_DMACSYNC_SHIFT)
#define GPDMA_SYNC_DMACSYNC(x) ((x) << GPDMA_SYNC_DMACSYNC_SHIFT)

/* --- GPDMA_C[0..7]SRCADDR values ----------------------------------- */

/* SRCADDR: DMA source address */
#define GPDMA_CxSRCADDR_SRCADDR_SHIFT (0)
#define GPDMA_CxSRCADDR_SRCADDR_MASK \
			(0xffffffff << GPDMA_CxSRCADDR_SRCADDR_SHIFT)
#define GPDMA_CxSRCADDR_SRCADDR(x) ((x) << GPDMA_CxSRCADDR_SRCADDR_SHIFT)

/* --- GPDMA_C[0..7]DESTADDR values ---------------------------------- */

/* DESTADDR: DMA source address */
#define GPDMA_CxDESTADDR_DESTADDR_SHIFT (0)
#define GPDMA_CxDESTADDR_DESTADDR_MASK \
			(0xffffffff << GPDMA_CxDESTADDR_DESTADDR_SHIFT)
#define GPDMA_CxDESTADDR_DESTADDR(x) ((x) << GPDMA_CxDESTADDR_DESTADDR_SHIFT)

/* --- GPDMA_C[0..7]LLI values --------------------------------------- */

/* LM: AHB master select for loading the next LLI */
#define GPDMA_CxLLI_LM_SHIFT (0)
#define GPDMA_CxLLI_LM_MASK (0x1 << GPDMA_CxLLI_LM_SHIFT)
#define GPDMA_CxLLI_LM(x) ((x) << GPDMA_CxLLI_LM_SHIFT)

/* LLI: Linked list item */
#define GPDMA_CxLLI_LLI_SHIFT (2)
#define GPDMA_CxLLI_LLI_MASK (0x3fffffff << GPDMA_CxLLI_LLI_SHIFT)
#define GPDMA_CxLLI_LLI(x) ((x) << GPDMA_CxLLI_LLI_SHIFT)

/* --- GPDMA_C[0..7]CONTROL values ----------------------------------- */

/* TRANSFERSIZE: Transfer size in number of transfers */
#define GPDMA_CxCONTROL_TRANSFERSIZE_SHIFT (0)
#define GPDMA_CxCONTROL_TRANSFERSIZE_MASK \
			(0xfff << GPDMA_CxCONTROL_TRANSFERSIZE_SHIFT)
#define GPDMA_CxCONTROL_TRANSFERSIZE(x) \
			((x) << GPDMA_CxCONTROL_TRANSFERSIZE_SHIFT)

/* SBSIZE: Source burst size */
#define GPDMA_CxCONTROL_SBSIZE_SHIFT	(12)
#define GPDMA_CxCONTROL_SBSIZE_MASK	(0x7 << GPDMA_CxCONTROL_SBSIZE_SHIFT)
#define GPDMA_CxCONTROL_SBSIZE(x)	((x) << GPDMA_CxCONTROL_SBSIZE_SHIFT)

/* DBSIZE: Destination burst size */
#define GPDMA_CxCONTROL_DBSIZE_SHIFT	(15)
#define GPDMA_CxCONTROL_DBSIZE_MASK	(0x7 << GPDMA_CxCONTROL_DBSIZE_SHIFT)
#define GPDMA_CxCONTROL_DBSIZE(x)	((x) << GPDMA_CxCONTROL_DBSIZE_SHIFT)

/* SWIDTH: Source transfer width */
#define GPDMA_CxCONTROL_SWIDTH_SHIFT	(18)
#define GPDMA_CxCONTROL_SWIDTH_MASK	(0x7 << GPDMA_CxCONTROL_SWIDTH_SHIFT)
#define GPDMA_CxCONTROL_SWIDTH(x)	((x) << GPDMA_CxCONTROL_SWIDTH_SHIFT)

/* DWIDTH: Destination transfer width */
#define GPDMA_CxCONTROL_DWIDTH_SHIFT	(21)
#define GPDMA_CxCONTROL_DWIDTH_MASK	(0x7 << GPDMA_CxCONTROL_DWIDTH_SHIFT)
#define GPDMA_CxCONTROL_DWIDTH(x)	((x) << GPDMA_CxCONTROL_DWIDTH_SHIFT)

/* S: Source AHB master select */
#define GPDMA_CxCONTROL_S_SHIFT		(24)
#define GPDMA_CxCONTROL_S_MASK		(0x1 << GPDMA_CxCONTROL_S_SHIFT)
#define GPDMA_CxCONTROL_S(x)		((x) << GPDMA_CxCONTROL_S_SHIFT)

/* D: Destination AHB master select */
#define GPDMA_CxCONTROL_D_SHIFT		(25)
#define GPDMA_CxCONTROL_D_MASK		(0x1 << GPDMA_CxCONTROL_D_SHIFT)
#define GPDMA_CxCONTROL_D(x)		((x) << GPDMA_CxCONTROL_D_SHIFT)

/* SI: Source increment */
#define GPDMA_CxCONTROL_SI_SHIFT	(26)
#define GPDMA_CxCONTROL_SI_MASK		(0x1 << GPDMA_CxCONTROL_SI_SHIFT)
#define GPDMA_Cx0CONTROL_SI(x)		((x) << GPDMA_CxCONTROL_SI_SHIFT)

/* DI: Destination increment */
#define GPDMA_CxCONTROL_DI_SHIFT	(27)
#define GPDMA_CxCONTROL_DI_MASK		(0x1 << GPDMA_CxCONTROL_DI_SHIFT)
#define GPDMA_CxCONTROL_DI(x)		((x) << GPDMA_CxCONTROL_DI_SHIFT)

/* PROT1: This information is provided to the peripheral during a DMA bus
  access and indicates that the access is in user mode or privileged mode */
#define GPDMA_CxCONTROL_PROT1_SHIFT	(28)
#define GPDMA_CxCONTROL_PROT1_MASK	(0x1 << GPDMA_CxCONTROL_PROT1_SHIFT)
#define GPDMA_CxCONTROL_PROT1(x)	((x) << GPDMA_CxCONTROL_PROT1_SHIFT)

/* PROT2: This information is provided to the peripheral during a DMA bus
  access and indicates to the peripheral that the access is bufferable or not
  bufferable */
#define GPDMA_CxCONTROL_PROT2_SHIFT	(29)
#define GPDMA_CxCONTROL_PROT2_MASK	(0x1 << GPDMA_CxCONTROL_PROT2_SHIFT)
#define GPDMA_CxCONTROL_PROT2(x)	((x) << GPDMA_CxCONTROL_PROT2_SHIFT)

/* PROT3: This information is provided to the peripheral during a DMA bus
 access and indicates to the peripheral that the access is cacheable or not
 cacheable */
#define GPDMA_CxCONTROL_PROT3_SHIFT	(30)
#define GPDMA_CxCONTROL_PROT3_MASK	(0x1 << GPDMA_CxCONTROL_PROT3_SHIFT)
#define GPDMA_CxCONTROL_PROT3(x)	((x) << GPDMA_CxCONTROL_PROT3_SHIFT)

/* I: Terminal count interrupt enable bit */
#define GPDMA_CxCONTROL_I_SHIFT		(31)
#define GPDMA_CxCONTROL_I_MASK		(0x1 << GPDMA_CxCONTROL_I_SHIFT)
#define GPDMA_CxCONTROL_I(x)		((x) << GPDMA_CxCONTROL_I_SHIFT)

/* --- GPDMA_C[0..7]CONFIG values ------------------------------------ */

/* E: Channel enable */
#define GPDMA_CxCONFIG_E_SHIFT		(0)
#define GPDMA_CxCONFIG_E_MASK		(0x1 << GPDMA_CxCONFIG_E_SHIFT)
#define GPDMA_CxCONFIG_E(x)		((x) << GPDMA_CxCONFIG_E_SHIFT)

/* SRCPERIPHERAL: Source peripheral */
#define GPDMA_CxCONFIG_SRCPERIPHERAL_SHIFT (1)
#define GPDMA_CxCONFIG_SRCPERIPHERAL_MASK \
			(0x1f << GPDMA_CxCONFIG_SRCPERIPHERAL_SHIFT)
#define GPDMA_CxCONFIG_SRCPERIPHERAL(x) \
			((x) << GPDMA_CxCONFIG_SRCPERIPHERAL_SHIFT)

/* DESTPERIPHERAL: Destination peripheral */
#define GPDMA_CxCONFIG_DESTPERIPHERAL_SHIFT (6)
#define GPDMA_CxCONFIG_DESTPERIPHERAL_MASK \
			(0x1f << GPDMA_CxCONFIG_DESTPERIPHERAL_SHIFT)
#define GPDMA_CxCONFIG_DESTPERIPHERAL(x) \
			((x) << GPDMA_CxCONFIG_DESTPERIPHERAL_SHIFT)

/* FLOWCNTRL: Flow control and transfer type */
#define GPDMA_CxCONFIG_FLOWCNTRL_SHIFT	(11)
#define GPDMA_CxCONFIG_FLOWCNTRL_MASK	(0x7 << GPDMA_CxCONFIG_FLOWCNTRL_SHIFT)
#define GPDMA_CxCONFIG_FLOWCNTRL(x)	((x) << GPDMA_CxCONFIG_FLOWCNTRL_SHIFT)

/* IE: Interrupt error mask */
#define GPDMA_CxCONFIG_IE_SHIFT		(14)
#define GPDMA_CxCONFIG_IE_MASK		(0x1 << GPDMA_CxCONFIG_IE_SHIFT)
#define GPDMA_CxCONFIG_IE(x)		((x) << GPDMA_CxCONFIG_IE_SHIFT)

/* ITC: Terminal count interrupt mask */
#define GPDMA_CxCONFIG_ITC_SHIFT	(15)
#define GPDMA_CxCONFIG_ITC_MASK		(0x1 << GPDMA_CxCONFIG_ITC_SHIFT)
#define GPDMA_CxCONFIG_ITC(x)		((x) << GPDMA_CxCONFIG_ITC_SHIFT)

/* L: Lock */
#define GPDMA_CxCONFIG_L_SHIFT		(16)
#define GPDMA_CxCONFIG_L_MASK		(0x1 << GPDMA_CxCONFIG_L_SHIFT)
#define GPDMA_CxCONFIG_L(x)		((x) << GPDMA_CxCONFIG_L_SHIFT)

/* A: Active */
#define GPDMA_CxCONFIG_A_SHIFT		(17)
#define GPDMA_CxCONFIG_A_MASK		(0x1 << GPDMA_CxCONFIG_A_SHIFT)
#define GPDMA_CxCONFIG_A(x)		((x) << GPDMA_CxCONFIG_A_SHIFT)

/* H: Halt */
#define GPDMA_CxCONFIG_H_SHIFT		(18)
#define GPDMA_CxCONFIG_H_MASK		(0x1 << GPDMA_CxCONFIG_H_SHIFT)
#define GPDMA_CxCONFIG_H(x)		((x) << GPDMA_CxCONFIG_H_SHIFT)

/**@}*/

#endif
