/** @defgroup ethernet_mac_stm32fxx7_defines MAC STM32Fxx7 Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet MAC for STM32Fxx7
 * chips</b>
 *
 * @ingroup ETH
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 1 September 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_ETHERNET_H
#define LIBOPENCM3_ETHERNET_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

/* Ethernet MAC registers */
#define ETH_MACCR			MMIO32(ETHERNET_BASE + 0x00)
#define ETH_MACFFR			MMIO32(ETHERNET_BASE + 0x04)
#define ETH_MACHTHR			MMIO32(ETHERNET_BASE + 0x08)
#define ETH_MACHTLR			MMIO32(ETHERNET_BASE + 0x0C)
#define ETH_MACMIIAR			MMIO32(ETHERNET_BASE + 0x10)
#define ETH_MACMIIDR			MMIO32(ETHERNET_BASE + 0x14)
#define ETH_MACFCR			MMIO32(ETHERNET_BASE + 0x18)
#define ETH_MACVLANTR			MMIO32(ETHERNET_BASE + 0x1C)
#define ETH_MACRWUFFR			MMIO32(ETHERNET_BASE + 0x28)
#define ETH_MACPMTCSR			MMIO32(ETHERNET_BASE + 0x2C)
/* not available on F1 ?*/
#define ETH_MACDBGR			MMIO32(ETHERNET_BASE + 0x34)
#define ETH_MACSR			MMIO32(ETHERNET_BASE + 0x38)
#define ETH_MACIMR			MMIO32(ETHERNET_BASE + 0x3C)

/* i=[0..3] */
#define ETH_MACAHR(i)			MMIO32(ETHERNET_BASE + 0x40+i*8)
/* i=[0..3] */
#define ETH_MACALR(i)			MMIO32(ETHERNET_BASE + 0x44+i*8)

/* Ethernet MMC registers */
#define ETH_MMCCR			MMIO32(ETHERNET_BASE + 0x100)
#define ETH_MMCRIR			MMIO32(ETHERNET_BASE + 0x104)
#define ETH_MMCTIR			MMIO32(ETHERNET_BASE + 0x108)
#define ETH_MMCRIMR			MMIO32(ETHERNET_BASE + 0x10C)
#define ETH_MMCTIMR			MMIO32(ETHERNET_BASE + 0x110)
#define ETH_MMCTGFSCCR			MMIO32(ETHERNET_BASE + 0x14C)
#define ETH_MMCTGFMSCCR			MMIO32(ETHERNET_BASE + 0x150)
#define ETH_MMCTGFCR			MMIO32(ETHERNET_BASE + 0x168)
#define ETH_MMCRFCECR			MMIO32(ETHERNET_BASE + 0x194)
#define ETH_MMCRFAECR			MMIO32(ETHERNET_BASE + 0x198)
#define ETH_MMCRGUFCR			MMIO32(ETHERNET_BASE + 0x1C4)

/* Ethrenet IEEE 1588 time stamp registers */
#define ETH_PTPTSCR			MMIO32(ETHERNET_BASE + 0x700)
#define ETH_PTPSSIR			MMIO32(ETHERNET_BASE + 0x704)
#define ETH_PTPTSHR			MMIO32(ETHERNET_BASE + 0x708)
#define ETH_PTPTSLR			MMIO32(ETHERNET_BASE + 0x70C)
#define ETH_PTPTSHUR			MMIO32(ETHERNET_BASE + 0x710)
#define ETH_PTPTSLUR			MMIO32(ETHERNET_BASE + 0x714)
#define ETH_PTPTSAR			MMIO32(ETHERNET_BASE + 0x718)
#define ETH_PTPTTHR			MMIO32(ETHERNET_BASE + 0x71C)
#define ETH_PTPTTLR			MMIO32(ETHERNET_BASE + 0x720)
/* not available on F1 ?*/
#define ETH_PTPTSSR			MMIO32(ETHERNET_BASE + 0x728)

/* Ethernet DMA registers */
#define ETH_DMABMR			MMIO32(ETHERNET_BASE + 0x1000)
#define ETH_DMATPDR			MMIO32(ETHERNET_BASE + 0x1004)
#define ETH_DMARPDR			MMIO32(ETHERNET_BASE + 0x1008)
#define ETH_DMARDLAR			MMIO32(ETHERNET_BASE + 0x100C)
#define ETH_DMATDLAR			MMIO32(ETHERNET_BASE + 0x1010)
#define ETH_DMASR			MMIO32(ETHERNET_BASE + 0x1014)
#define ETH_DMAOMR			MMIO32(ETHERNET_BASE + 0x1018)
#define ETH_DMAIER			MMIO32(ETHERNET_BASE + 0x101C)
#define ETH_DMAMFBOCR			MMIO32(ETHERNET_BASE + 0x1020)
#define ETH_DMACHTDR			MMIO32(ETHERNET_BASE + 0x1048)
#define ETH_DMACHRDR			MMIO32(ETHERNET_BASE + 0x104C)
#define ETH_DMACHTBAR			MMIO32(ETHERNET_BASE + 0x1050)
#define ETH_DMACHRBAR			MMIO32(ETHERNET_BASE + 0x1054)

/* Ethernet Buffer Descriptors */
#define	ETH_DES(n, base)		MMIO32((base) + (n)*4)
#define	ETH_DES0(base)			ETH_DES(0, base)
#define	ETH_DES1(base)			ETH_DES(1, base)
#define	ETH_DES2(base)			ETH_DES(2, base)
#define	ETH_DES3(base)			ETH_DES(3, base)

/* Ethernet Extended buffer Descriptors */
#define	ETH_DES4(base)			ETH_DES(4, base)
#define	ETH_DES5(base)			ETH_DES(5, base)
#define	ETH_DES6(base)			ETH_DES(6, base)
#define	ETH_DES7(base)			ETH_DES(7, base)

/*---------------------------------------------------------------------------*/
/* MACCR --------------------------------------------------------------------*/

#define ETH_MACCR_RE			(1<<2)
#define ETH_MACCR_TE			(1<<3)
#define ETH_MACCR_DC			(1<<4)

#define ETH_MACCR_BL_SHIFT		5
#define ETH_MACCR_BL			(3 << ETH_MACCR_BL_SHIFT)
#define ETH_MACCR_BL_MIN10		(0 << ETH_MACCR_BL_SHIFT)
#define ETH_MACCR_BL_MIN8		(1 << ETH_MACCR_BL_SHIFT)
#define ETH_MACCR_BL_MIN4		(2 << ETH_MACCR_BL_SHIFT)
#define ETH_MACCR_BL_MIN1		(3 << ETH_MACCR_BL_SHIFT)

#define ETH_MACCR_APCS			(1<<7)
#define ETH_MACCR_RD			(1<<9)
#define ETH_MACCR_IPCO			(1<<10)
#define ETH_MACCR_DM			(1<<11)
#define ETH_MACCR_LM			(1<<12)
#define ETH_MACCR_ROD			(1<<13)
#define ETH_MACCR_FES			(1<<14)
#define ETH_MACCR_CSD			(1<<16)

#define ETH_MACCR_IFG_SHIFT		17
#define ETH_MACCR_IFG			(7<<ETH_MACCR_IFG_SHIFT)

#define ETH_MACCR_JD			(1<<22)
#define ETH_MACCR_WD			(1<<23)
#define ETH_MACCR_CSTF			(1<<25)

/*---------------------------------------------------------------------------*/
/* MACFFR -------------------------------------------------------------------*/
#define ETH_MACFFR_PM			(1<<0)
#define ETH_MACFFR_HU			(1<<1)
#define ETH_MACFFR_HM			(1<<2)
#define ETH_MACFFR_DAIF			(1<<3)
#define ETH_MACFFR_PAM			(1<<4)
#define ETH_MACFFR_BFD			(1<<5)

#define ETH_MACFFR_PCF_SHIFT		6
#define ETH_MACFFR_PCF			(3<<ETH_MACFFR_PCF_SHIFT)
#define ETH_MACFFR_PCF_DISABLE		(0<<ETH_MACFFR_PCF_SHIFT)
#define ETH_MACFFR_PCF_NOPAUSE		(1<<ETH_MACFFR_PCF_SHIFT)
#define ETH_MACFFR_PCF_ALL		(2<<ETH_MACFFR_PCF_SHIFT)
#define ETH_MACFFR_PCF_PASS		(3<<ETH_MACFFR_PCF_SHIFT)

#define ETH_MACFFR_SAIF			(1<<8)
#define ETH_MACFFR_SAF			(1<<9)
#define ETH_MACFFR_HPF			(1<<10)
#define ETH_MACFFR_RA			(1<<31)

/*---------------------------------------------------------------------------*/
/* MACMIIAR -----------------------------------------------------------------*/

#define ETH_MACMIIAR_MB			(1<<0)
#define ETH_MACMIIAR_MW			(1<<1)

#define ETH_MACMIIAR_CR_SHIFT		2
#define ETH_MACMIIAR_CR			(7<<ETH_MACMIIAR_CR_SHIFT)
/* For HCLK 60-100 MHz */
#define ETH_MACMIIAR_CR_HCLK_DIV_42	(0<<ETH_MACMIIAR_CR_SHIFT)
/* For HCLK 100-150 MHz */
#define ETH_MACMIIAR_CR_HCLK_DIV_62	(1<<ETH_MACMIIAR_CR_SHIFT)
/* For HCLK 20-35 MHz */
#define ETH_MACMIIAR_CR_HCLK_DIV_16	(2<<ETH_MACMIIAR_CR_SHIFT)
/* For HCLK 35-60 MHz */
#define ETH_MACMIIAR_CR_HCLK_DIV_26	(3<<ETH_MACMIIAR_CR_SHIFT)
/* For HCLK 150-168 MHz */
#define ETH_MACMIIAR_CR_HCLK_DIV_102	(4<<ETH_MACMIIAR_CR_SHIFT)

#define ETH_MACMIIAR_MR_SHIFT		6
#define ETH_MACMIIAR_MR			(0x1F << ETH_MACMIIAR_MR_SHIFT)

#define ETH_MACMIIAR_PA_SHIFT		11
#define ETH_MACMIIAR_PA			(0x1F << ETH_MACMIIAR_MR_SHIFT)

/*---------------------------------------------------------------------------*/
/* MACMIIDR------------------------------------------------------------------*/

#define ETH_MACMIIDR_MD			0xFFFF

/*---------------------------------------------------------------------------*/
/* MACFCR -------------------------------------------------------------------*/
#define ETH_MACFCR_FCB			(1<<0)
#define ETH_MACFCR_BPA			(1<<0)
#define ETH_MACFCR_TFCE			(1<<1)
#define ETH_MACFCR_RFCE			(1<<2)
#define ETH_MACFCR_UPFD			(1<<3)

#define ETH_MACFCR_PLT_SHIFT		4
#define ETH_MACFCR_PLT			(0x03 << ETH_MACFCR_PLT_SHIFT)
#define ETH_MACFCR_PLT_4		(0 << ETH_MACFCR_PLT_SHIFT)
#define ETH_MACFCR_PLT_28		(1 << ETH_MACFCR_PLT_SHIFT)
#define ETH_MACFCR_PLT_144		(2 << ETH_MACFCR_PLT_SHIFT)
#define ETH_MACFCR_PLT_256		(3 << ETH_MACFCR_PLT_SHIFT)

#define ETH_MACFCR_ZQPD			(1<<7)

#define ETH_MACFCR_PT_SHIFT		16
#define ETH_MACFCR_PT			(0xFFFF << ETH_MACFCR_PT)

/*---------------------------------------------------------------------------*/
/* MACVLANTR ----------------------------------------------------------------*/
#define ETH_MACVLANTR_VLANTI_SHIFT	0
#define ETH_MACVLANTR_VLANTI		(0xFFFF << ETH_MACVLANTR_VLANTI_SHIFT)
#define ETH_MACVLANTR_VLANTC		(1<<16)

/*---------------------------------------------------------------------------*/
/* MACPMTCSR ----------------------------------------------------------------*/

#define ETH_MACPMTCSR_PD		(1<<0)
#define ETH_MACPMTCSR_MPE		(1<<1)
#define ETH_MACPMTCSR_WFE		(1<<2)
#define ETH_MACPMTCSR_MPR		(1<<5)
#define ETH_MACPMTCSR_WFR		(1<<6)
#define ETH_MACPMTCSR_GU		(1<<9)
#define ETH_MACPMTCSR_WFFRPR		(1<<31)

/*---------------------------------------------------------------------------*/
/* MACDBGR -------------------------------------------------------------------*/

#define ETH_MACDBGR_MMRPEA		(1<<0)
#define ETH_MACDBGR_MSFRWCS		(3<<1)
#define ETH_MACDBGR_RFWRA		(1<<4)

#define ETH_MACDBGR_RFRCS_SHIFT		5
#define ETH_MACDBGR_RFRCS		(3<<ETH_MACDBGR_RFRCS_SHIFT)
#define ETH_MACDBGR_RFRCS_IDLE		(0<<ETH_MACDBGR_RFRCS_SHIFT)
#define ETH_MACDBGR_RFRCS_RDATA		(1<<ETH_MACDBGR_RFRCS_SHIFT)
#define ETH_MACDBGR_RFRCS_RSTAT		(2<<ETH_MACDBGR_RFRCS_SHIFT)
#define ETH_MACDBGR_RFRCS_FLUSH		(3<<ETH_MACDBGR_RFRCS_SHIFT)

#define ETH_MACDBGR_RFFL_SHIFT		8
#define ETH_MACDBGR_RFFL		(3<<ETH_MACDBGR_RFFL_SHIFT)
#define ETH_MACDBGR_RFFL_EMPTY		(0<<ETH_MACDBGR_RFFL_SHIFT)
#define ETH_MACDBGR_RFFL_BELOW		(1<<ETH_MACDBGR_RFFL_SHIFT)
#define ETH_MACDBGR_RFFL_ABOVE		(2<<ETH_MACDBGR_RFFL_SHIFT)
#define ETH_MACDBGR_RFFL_FULL		(3<<ETH_MACDBGR_RFFL_SHIFT)

#define ETH_MACDBGR_MMTEA		(1<<16)

#define ETH_MACDBGR_MTFCS_SHIFT		17
#define ETH_MACDBGR_MTFCS		(3 << ETH_MACDBGR_MTFCS_SHIFT)
#define ETH_MACDBGR_MTFCS_IDLE		(0 << ETH_MACDBGR_MTFCS_SHIFT)
#define ETH_MACDBGR_MTFCS_WAIT		(1 << ETH_MACDBGR_MTFCS_SHIFT)
#define ETH_MACDBGR_MTFCS_PAUSE		(2 << ETH_MACDBGR_MTFCS_SHIFT)
#define ETH_MACDBGR_MTFCS_TRANSFER	(3 << ETH_MACDBGR_MTFCS_SHIFT)

#define ETH_MACDBGR_MTP			(1<<19)

#define ETH_MACDBGR_TFRS_SHIFT		20
#define ETH_MACDBGR_TFRS		(3<<ETH_MACDBGR_TFRS_SHIFT)
#define ETH_MACDBGR_TFRS_IDLE		(0<<ETH_MACDBGR_TFRS_SHIFT)
#define ETH_MACDBGR_TFRS_READ		(1<<ETH_MACDBGR_TFRS_SHIFT)
#define ETH_MACDBGR_TFRS_WAIT		(2<<ETH_MACDBGR_TFRS_SHIFT)
#define ETH_MACDBGR_TFRS_FLUSH		(3<<ETH_MACDBGR_TFRS_SHIFT)

#define ETH_MACDBGR_TFWA		(1<<22)
#define ETH_MACDBGR_TFNE		(1<<24)
#define ETH_MACDBGR_TFF			(1<<25)

/*---------------------------------------------------------------------------*/
/* MACSR --------------------------------------------------------------------*/

/* Ethernet MAC interrupt status register ETH_MACSR bits */
#define ETH_MACSR_PMTS			(1<<3)
#define ETH_MACSR_MMCS			(1<<4)
#define ETH_MACSR_MMCRS			(1<<5)
#define ETH_MACSR_MMCTS			(1<<6)
#define ETH_MACSR_TSTS			(1<<9)


/*---------------------------------------------------------------------------*/
/* MACIMR -------------------------------------------------------------------*/

#define ETH_MACIMR_PMTIM		(1<<3)
#define ETH_MACIMR_TSTIM		(1<<9)

/*---------------------------------------------------------------------------*/
/* MACA0HR ------------------------------------------------------------------*/

#define ETH_MACA0HR_MACA0H		(0xFFFF<<0)
#define ETH_MACA0HR_MO			(1<<31)

/*---------------------------------------------------------------------------*/
/* MACA1HR, MACA2HR, MACA3HR ------------------------------------------------*/

#define ETH_MACAHR_MACAH		(0xFFFF<<0)
#define ETH_MACAHR_MBC_ALL		(63<<24)
#define ETH_MACAHR_MBC_0		(1<<24)
#define ETH_MACAHR_MBC_1		(1<<25)
#define ETH_MACAHR_MBC_2		(1<<26)
#define ETH_MACAHR_MBC_3		(1<<27)
#define ETH_MACAHR_MBC_4		(1<<28)
#define ETH_MACAHR_MBC_5		(1<<29)
#define ETH_MACAHR_SA			(1<<30)
#define ETH_MACAHR_AE			(1<<31)

/*---------------------------------------------------------------------------*/
/* MMCCR --------------------------------------------------------------------*/

#define ETH_MMCCR_CR			(1<<0)
#define ETH_MMCCR_CSR			(1<<1)
#define ETH_MMCCR_ROR			(1<<2)
#define ETH_MMCCR_MCF			(1<<3)
#define ETH_MMCCR_MCP			(1<<4)
#define ETH_MMCCR_MCFHP			(1<<5)

/*---------------------------------------------------------------------------*/
/* MMCRIR -------------------------------------------------------------------*/

#define ETH_MMCRIR_RFCES		(1<<5)
#define ETH_MMCRIR_RFAES		(1<<6)
#define ETH_MMCRIR_RGUFS		(1<<17)

/*---------------------------------------------------------------------------*/
/* MMCTIR -------------------------------------------------------------------*/

#define ETH_MMCTIR_TGFSCS		(1<<14)
#define ETH_MMCTIR_TGFMSCS		(1<<15)
#define ETH_MMCTIR_TGFS			(1<<21)

/*---------------------------------------------------------------------------*/
/* MMCRIMR ------------------------------------------------------------------*/

#define ETH_MMCRIMR_RFCEM		(1<<5)
#define ETH_MMCRIMR_RFAEM		(1<<6)
#define ETH_MMCRIMR_RGUFM		(1<<17)

/*---------------------------------------------------------------------------*/
/* MMCTIMR ------------------------------------------------------------------*/

#define ETH_MMCTIMR_TGFSCS		(1<<14)
#define ETH_MMCTIMR_TGFMSCS		(1<<15)
#define ETH_MMCTIMR_TGFS		(1<<21)

/*---------------------------------------------------------------------------*/
/* PTPTSCR ------------------------------------------------------------------*/

#define ETH_PTPTSCR_TSE			(1<<0)
#define ETH_PTPTSCR_TSFCU		(1<<1)
#define ETH_PTPTSCR_TSSTI		(1<<2)
#define ETH_PTPTSCR_TSSTU		(1<<3)
#define ETH_PTPTSCR_TSITE		(1<<4)
#define ETH_PTPTSCR_TTSARU		(1<<5)
#define ETH_PTPTSCR_TSSARFE		(1<<8)
#define ETH_PTPTSCR_TSSSR		(1<<9)
#define ETH_PTPTSCR_TSPTPPSV2E		(1<<10)
#define ETH_PTPTSCR_TSSPTPOEFE		(1<<11)
#define ETH_PTPTSCR_TSSIPV6FE		(1<<12)
#define ETH_PTPTSCR_TSSIPV4FE		(1<<13)
#define ETH_PTPTSCR_TSSEME		(1<<14)
#define ETH_PTPTSCR_TSSMRME		(1<<15)

#define ETH_PTPTSCR_TSCNT_SHIFT		16
#define ETH_PTPTSCR_TSCNT		(3 << ETH_PTPTSCR_TSCNT_SHIFT)
#define ETH_PTPTSCR_TSCNT_ORD		(0 << ETH_PTPTSCR_TSCNT_SHIFT)
#define ETH_PTPTSCR_TSCNT_BOUND		(1 << ETH_PTPTSCR_TSCNT_SHIFT)
#define ETH_PTPTSCR_TSCNT_ETETC		(2 << ETH_PTPTSCR_TSCNT_SHIFT)
#define ETH_PTPTSCR_TSCNT_PTPTC		(3 << ETH_PTPTSCR_TSCNT_SHIFT)

#define ETH_PTPTSCR_TSPFFMAE		(1<<18)


/*---------------------------------------------------------------------------*/
/* PTPSSIR ------------------------------------------------------------------*/

#define ETH_PTPSSIR_STSSI		0xFF

/*---------------------------------------------------------------------------*/
/* PTPTSLR ------------------------------------------------------------------*/

#define ETH_PTPTSLR_STSS		0x7FFFFFFF
#define ETH_PTPTSLR_STPNS		(1<<31)

/*---------------------------------------------------------------------------*/
/* PTPTSLUR -----------------------------------------------------------------*/

#define ETH_PTPTSLUR_TSUSS		0x7FFFFFFF
#define ETH_PTPTSLUR_TSUPNS		(1<<31)

/*---------------------------------------------------------------------------*/
/* PTPTSSR ------------------------------------------------------------------*/

#define ETH_PTPTSSR_TSSO		(1<<0)
#define ETH_PTPTSSR_TSTTR		(1<<1)

/*---------------------------------------------------------------------------*/
/* PTPTSCR ------------------------------------------------------------------*/

#define ETH_PTPTSCR_PPSFREQ		(0x0F<<0)
#define ETH_PTPTSCR_PPSFREQ_1HZ		(0x00<<0)
#define ETH_PTPTSCR_PPSFREQ_2HZ		(0x01<<0)
#define ETH_PTPTSCR_PPSFREQ_4HZ		(0x02<<0)
#define ETH_PTPTSCR_PPSFREQ_8HZ		(0x03<<0)
#define ETH_PTPTSCR_PPSFREQ_16HZ	(0x04<<0)
#define ETH_PTPTSCR_PPSFREQ_32HZ	(0x05<<0)
#define ETH_PTPTSCR_PPSFREQ_64HZ	(0x06<<0)
#define ETH_PTPTSCR_PPSFREQ_128HZ	(0x07<<0)
#define ETH_PTPTSCR_PPSFREQ_256HZ	(0x08<<0)
#define ETH_PTPTSCR_PPSFREQ_512HZ	(0x09<<0)
#define ETH_PTPTSCR_PPSFREQ_1024HZ	(0x0A<<0)
#define ETH_PTPTSCR_PPSFREQ_2048HZ	(0x0B<<0)
#define ETH_PTPTSCR_PPSFREQ_4096HZ	(0x0C<<0)
#define ETH_PTPTSCR_PPSFREQ_8192HZ	(0x0D<<0)
#define ETH_PTPTSCR_PPSFREQ_16384HZ	(0x0E<<0)
#define ETH_PTPTSCR_PPSFREQ_32768HZ	(0x0F<<0)

/*---------------------------------------------------------------------------*/
/* DMABMR -------------------------------------------------------------------*/

#define ETH_DMABMR_SR			(1<<0)
#define ETH_DMABMR_DA			(1<<1)

#define ETH_DMABMR_DSL_SHIFT		2
#define ETH_DMABMR_DSL			(0x1F << ETH_DMABR_DSL_SHIFT)

#define ETH_DMABMR_EDFE			(1<<7)

#define ETH_DMABMR_PBL_SHIFT		8
#define ETH_DMABMR_PBL			(0x3F << ETH_DMABR_PBL_SHIFT)

#define ETH_DMABMR_PM_SHIFT		14
#define ETH_DMABMR_PM			(0x03 << ETH_DMABMR_PM_SHIFT)
#define ETH_DMABMR_PM_1_1		(0 << ETH_DMABMR_PM_SHIFT)
#define ETH_DMABMR_PM_2_1		(1 << ETH_DMABMR_PM_SHIFT)
#define ETH_DMABMR_PM_3_1		(2 << ETH_DMABMR_PM_SHIFT)
#define ETH_DMABMR_PM_4_1		(3 << ETH_DMABMR_PM_SHIFT)

#define ETH_DMABMR_FB			(1<<16)

#define ETH_DMABMR_RDP_SHIFT		17
#define ETH_DMABMR_RDP			(0x3F << ETH_DMABMR_RDP_SHIFT)

#define ETH_DMABMR_USP			(1<<23)
#define ETH_DMABMR_FPM			(1<<24)
#define ETH_DMABMR_AAB			(1<<25)
#define ETH_DMABMR_MB			(1<<26)

/*---------------------------------------------------------------------------*/
/* DMASR --------------------------------------------------------------------*/

#define ETH_DMASR_TS			(1<<0)
#define ETH_DMASR_TPSS			(1<<1)
#define ETH_DMASR_TBUS			(1<<2)
#define ETH_DMASR_TJTS			(1<<3)
#define ETH_DMASR_ROS			(1<<4)
#define ETH_DMASR_TUS			(1<<5)
#define ETH_DMASR_RS			(1<<6)
#define ETH_DMASR_RBUS			(1<<7)
#define ETH_DMASR_RPSS			(1<<8)
#define ETH_DMASR_RWTS			(1<<9)
#define ETH_DMASR_ETS			(1<<10)
#define ETH_DMASR_FBES			(1<<13)
#define ETH_DMASR_ERS			(1<<14)
#define ETH_DMASR_AIS			(1<<15)
#define ETH_DMASR_NIS			(1<<16)

#define ETH_DMASR_RPS_SHIFT		17
#define ETH_DMASR_RPS			(7<<ETH_DMASR_RPS_SHIFT)
#define ETH_DMASR_RPS_STOP		(0<<ETH_DMASR_RPS_SHIFT)
#define ETH_DMASR_RPS_FETCH		(1<<ETH_DMASR_RPS_SHIFT)
#define ETH_DMASR_RPS_WAIT		(3<<ETH_DMASR_RPS_SHIFT)
#define ETH_DMASR_RPS_SUSPEND		(4<<ETH_DMASR_RPS_SHIFT)
#define ETH_DMASR_RPS_CLOSE		(5<<ETH_DMASR_RPS_SHIFT)
#define ETH_DMASR_RPS_TRANSFER		(7<<ETH_DMASR_RPS_SHIFT)

#define ETH_DMASR_TPS_SHIFT		20
#define ETH_DMASR_TPS			(7<<ETH_DMASR_TPS_SHIFT)
#define ETH_DMASR_TPS_STOP		(0<<ETH_DMASR_TPS_SHIFT)
#define ETH_DMASR_TPS_FETCH		(1<<ETH_DMASR_TPS_SHIFT)
#define ETH_DMASR_TPS_WAIT		(2<<ETH_DMASR_TPS_SHIFT)
#define ETH_DMASR_TPS_TRANSFER		(3<<ETH_DMASR_TPS_SHIFT)
#define ETH_DMASR_TPS_SUSPEND		(6<<ETH_DMASR_TPS_SHIFT)
#define ETH_DMASR_TPS_CLOSE		(7<<ETH_DMASR_TPS_SHIFT)

#define ETH_DMASR_EBS_SHIFT		23
#define ETH_DMASR_EBS			(7<<ETH_DMASR_EBS_SHIFT)

#define ETH_DMASR_MMCS			(1<<27)
#define ETH_DMASR_PMTS			(1<<28)
#define ETH_DMASR_TSTS			(1<<29)

/*---------------------------------------------------------------------------*/
/* DMAOMR -------------------------------------------------------------------*/

#define ETH_DMAOMR_SR			(1<<1)
#define ETH_DMAOMR_OSF			(1<<2)

#define ETH_DMAOMR_RTC_SHIFT		3
#define ETH_DMAOMR_RTC			(3 << ETH_DMAOMR_RTC_SHIFT)
#define ETH_DMAOMR_RTC_64		(0 << ETH_DMAOMR_RTC_SHIFT)
#define ETH_DMAOMR_RTC_32		(1 << ETH_DMAOMR_RTC_SHIFT)
#define ETH_DMAOMR_RTC_96		(2 << ETH_DMAOMR_RTC_SHIFT)
#define ETH_DMAOMR_RTC_128		(3 << ETH_DMAOMR_RTC_SHIFT)

#define ETH_DMAOMR_FUGF			(1<<6)
#define ETH_DMAOMR_FEF			(1<<7)
#define ETH_DMAOMR_ST			(1<<13)

#define ETH_DMAOMR_TTC_SHIFT		14
#define ETH_DMAOMR_TTC			(0x07 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_64		(0 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_128		(1 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_192		(2 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_256		(3 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_40		(4 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_32		(5 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_24		(6 << ETH_DMAOMR_TTC_SHIFT)
#define ETH_DMAOMR_TTC_16		(7 << ETH_DMAOMR_TTC_SHIFT)

#define ETH_DMAOMR_FTF			(1<<20)
#define ETH_DMAOMR_TSF			(1<<21)
#define ETH_DMAOMR_DFRF			(1<<24)
#define ETH_DMAOMR_RSF			(1<<25)
#define ETH_DMAOMR_DTCEFD		(1<<26)

/*----------------------------------------------------------------------------*/
/* DMAIER --------------------------------------------------------------------*/

#define ETH_DMAIER_TIE			(1<<0)
#define ETH_DMAIER_TPSIE		(1<<1)
#define ETH_DMAIER_TBUIE		(1<<2)
#define ETH_DMAIER_TJTIE		(1<<3)
#define ETH_DMAIER_ROIE			(1<<4)
#define ETH_DMAIER_TUIE			(1<<5)
#define ETH_DMAIER_RIE			(1<<6)
#define ETH_DMAIER_RBUIE		(1<<7)
#define ETH_DMAIER_RPSIE		(1<<8)
#define ETH_DMAIER_RWTIE		(1<<9)
#define ETH_DMAIER_ETIE			(1<<10)
#define ETH_DMAIER_FBEIE		(1<<13)
#define ETH_DMAIER_ERIE			(1<<14)
#define ETH_DMAIER_AISE			(1<<15)
#define ETH_DMAIER_NISE			(1<<16)

/*---------------------------------------------------------------------------*/
/* DMAMFBOCR ----------------------------------------------------------------*/

#define ETH_DMAMFBOCR_MFC_SHIFT		0
#define ETH_DMAMFBOCR_MFC		(0xFFFF << ETH_DMAMFBOCR_MFC_SHIFT)
#define ETH_DMAMFBOCR_OMFC		(1<<16)
#define ETH_DMAMFBOCR_MFA		(0x7FF << ETH_DMAMFBOCR_MFA_SHIFT)
#define ETH_DMAMFBOCR_OFOC		(1<<28)

/*---------------------------------------------------------------------------*/
/* DMARSWTR -----------------------------------------------------------------*/

#define ETH_DMARSWTR_RSWTC		0xFF

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* DMA Tx Descriptor */

#define ETH_DES_STD_SIZE		16
#define ETH_DES_EXT_SIZE		32
/*---------------------------------------------------------------------------*/
/* TDES0 --------------------------------------------------------------------*/

#define ETH_TDES0_DB			(1<<0)
#define ETH_TDES0_UF			(1<<1)
#define ETH_TDES0_ED			(1<<2)

#define ETH_TDES0_CC_SHIFT		3
#define ETH_TDES0_CC			(0x0F << ETH_TDES0_CC_SHIFT)

#define ETH_TDES0_VF			(1<<7)
#define ETH_TDES0_EC			(1<<8)
#define ETH_TDES0_LCO			(1<<9)
#define ETH_TDES0_NC			(1<<10)
#define ETH_TDES0_LCA			(1<<11)
#define ETH_TDES0_IPE			(1<<12)
#define ETH_TDES0_FF			(1<<13)
#define ETH_TDES0_JT			(1<<14)
#define ETH_TDES0_ES			(1<<15)
#define ETH_TDES0_IHE			(1<<16)
#define ETH_TDES0_TTSS			(1<<17)
#define ETH_TDES0_TCH			(1<<20)
#define ETH_TDES0_TER			(1<<21)

#define ETH_TDES0_CIC_SHIFT		22
#define ETH_TDES0_CIC			(3<<ETH_TDES0_CIC_SHIFT)
#define ETH_TDES0_CIC_DISABLED		(0<<ETH_TDES0_CIC_SHIFT)
#define ETH_TDES0_CIC_IP		(1<<ETH_TDES0_CIC_SHIFT)
#define ETH_TDES0_CIC_IPPL		(2<<ETH_TDES0_CIC_SHIFT)
#define ETH_TDES0_CIC_IPPLPH		(3<<ETH_TDES0_CIC_SHIFT)

#define ETH_TDES0_TTSE			(1<<25)
#define ETH_TDES0_DP			(1<<26)
#define ETH_TDES0_DC			(1<<27)
#define ETH_TDES0_FS			(1<<28)
#define ETH_TDES0_LS			(1<<29)
#define ETH_TDES0_IC			(1<<30)
#define ETH_TDES0_OWN			(1<<31)

/*---------------------------------------------------------------------------*/
/* TDES1 --------------------------------------------------------------------*/

#define ETH_TDES1_TBS1_SHIFT		0
#define ETH_TDES1_TBS1			(0x1FFF<<ETH_TDES1_TBS1_SHIFT)

#define ETH_TDES1_TBS2_SHIFT		16
#define ETH_TDES1_TBS2			(0x1FFF<<ETH_TDES1_TBS1_SHIFT)

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* DMA Rx Descriptor */

/*---------------------------------------------------------------------------*/
/* RDES0 --------------------------------------------------------------------*/

#define ETH_RDES0_PCE			(1<<0)
#define ETH_RDES0_ESA			(1<<0)
#define ETH_RDES0_CE			(1<<1)
#define ETH_RDES0_DE			(1<<2)
#define ETH_RDES0_RE			(1<<3)
#define ETH_RDES0_RWT			(1<<4)
#define ETH_RDES0_FT			(1<<5)
#define ETH_RDES0_LCO			(1<<6)
#define ETH_RDES0_IPHCE			(1<<7)
#define ETH_RDES0_TSV			(1<<7)
#define ETH_RDES0_LS			(1<<8)
#define ETH_RDES0_FS			(1<<9)
#define ETH_RDES0_VLAN			(1<<10)
#define ETH_RDES0_OE			(1<<11)
#define ETH_RDES0_LE			(1<<12)
#define ETH_RDES0_SAF			(1<<13)
#define ETH_RDES0_DCE			(1<<14)
#define ETH_RDES0_ES			(1<<15)

#define ETH_RDES0_FL_SHIFT		16
#define ETH_RDES0_FL			(0x3FFF<<ETH_RDES0_FL_SHIFT)

#define ETH_RDES0_AFM			(1<<30)
#define ETH_RDES0_OWN			(1<<31)

/*---------------------------------------------------------------------------*/
/* RDES1 --------------------------------------------------------------------*/

#define ETH_RDES1_RBS1_SHIFT		0
#define ETH_RDES1_RBS1			(0x1FFF<<ETH_RDES1_RBS1_SHIFT)

#define ETH_RDES1_RCH			(1<<14)
#define ETH_RDES1_RER			(1<<15)

#define ETH_RDES1_RBS2_SHIFT		16
#define ETH_RDES1_RBS2			(0x1FFF<<ETH_RDES1_RBS2_SHIFT)

#define ETH_RDES1_DIC			(1<<31)

/*---------------------------------------------------------------------------*/
/* RDES4 --------------------------------------------------------------------*/

#define ETH_RDES4_IPPT_SHIFT		0
#define ETH_RDES4_IPPT			(7<<ETH_RDES4_IPPT_SHIFT)
#define ETH_RDES4_IPPT_UNKNOWN		(0<<ETH_RDES4_IPPT_SHIFT)
#define ETH_RDES4_IPPT_UDP		(1<<ETH_RDES4_IPPT_SHIFT)
#define ETH_RDES4_IPPT_TCP		(2<<ETH_RDES4_IPPT_SHIFT)
#define ETH_RDES4_IPPT_ICMP		(3<<ETH_RDES4_IPPT_SHIFT)

#define ETH_RDES4_IPHE			(1<<3)
#define ETH_RDES4_IPPE			(1<<4)
#define ETH_RDES4_IPCB			(1<<5)
#define ETH_RDES4_IPV4PR		(1<<6)
#define ETH_RDES4_IPV6PR		(1<<7)

#define ETH_RDES4_PMT_SHIFT		8
#define ETH_RDES4_PMT			(0x0F<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_NO		(0x00<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_SYNC		(0x01<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_FOLLOW		(0x02<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_DLYRQ		(0x03<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_DLYRSP		(0x04<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_PDLYRQ		(0x05<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_PDLYRSP		(0x06<<ETH_RDES4_PMT_SHIFT)
#define ETH_RDES4_PMT_PDLYRSPFUP	(0x07<<ETH_RDES4_PMT_SHIFT)

#define ETH_RDES4_PFT			(1<<12)
#define ETH_RDES4_PV			(1<<13)

enum eth_clk {
	ETH_CLK_025_035MHZ = ETH_MACMIIAR_CR_HCLK_DIV_16,
	ETH_CLK_035_060MHZ = ETH_MACMIIAR_CR_HCLK_DIV_26,
	ETH_CLK_060_100MHZ = ETH_MACMIIAR_CR_HCLK_DIV_42,
	ETH_CLK_100_150MHZ = ETH_MACMIIAR_CR_HCLK_DIV_62,
	ETH_CLK_150_168MHZ = ETH_MACMIIAR_CR_HCLK_DIV_102,
};

BEGIN_DECLS

void eth_smi_write(uint8_t phy, uint8_t reg, uint16_t data);
uint16_t eth_smi_read(uint8_t phy, uint8_t reg);
void eth_smi_bit_op(uint8_t phy, uint8_t reg, uint16_t bits, uint16_t mask);
void eth_smi_bit_clear(uint8_t phy, uint8_t reg, uint16_t clearbits);
void eth_smi_bit_set(uint8_t phy, uint8_t reg, uint16_t setbits);

void eth_set_mac(uint8_t *mac);
void eth_desc_init(uint8_t *buf, uint32_t nTx, uint32_t nRx, uint32_t cTx,
		    uint32_t cRx, bool isext);
bool eth_tx(uint8_t *ppkt, uint32_t n);
bool eth_rx(uint8_t *ppkt, uint32_t *len, uint32_t maxlen);

void eth_init(uint8_t phy, enum eth_clk clock);
void eth_start(void);

void eth_enable_checksum_offload(void);

void eth_irq_enable(uint32_t reason);
void eth_irq_disable(uint32_t reason);
bool eth_irq_is_pending(uint32_t reason);
bool eth_irq_ack_pending(uint32_t reason);


END_DECLS

/*
 * Usage:
 *  rcc_periph_reset_pulse(RCC_ETHMAC);
 *  [ init gpio pins ]
 *  rcc_periph_reset_pulse(RCC_ETHMAC);
 *  phy_init(0);
 *  eth_init(0, ETH_CLK_025_035MHZ);
 *  eth_set_mac(mac);
 *  eth_desc_init(buffer, &eth_buffer[0], ETH_TXBUFNB, ETH_RXBUFNB,
 *                  ETH_TX_BUF_SIZE, ETH_RX_BUF_SIZE, false);
 *  eth_start();
 *  for (;;)
 *    eth_tx(frame,sizeof(frame));
 */

/**@}*/

#endif
