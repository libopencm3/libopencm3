/** @defgroup ltdc_defines LTDC Defines

@brief <b>Defined Constants and Types for the STM32F4xx LCD-TFT</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@date 4 Feb 2015

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_LTDC_H
#define LIBOPENCM3_LTDC_H

#include <libopencm3/stm32/f4/memorymap.h>


#include <stdint.h>
#include <libopencm3/stm32/rcc.h>

/**
 *  LTDC
 */


#define LTDC_SSCR                  (MMIO32(LTDC_BASE + 0x08))
#define LTDC_BPCR                  (MMIO32(LTDC_BASE + 0x0C))
#define LTDC_AWCR                  (MMIO32(LTDC_BASE + 0x10))
#define LTDC_TWCR                  (MMIO32(LTDC_BASE + 0x14))
#define LTDC_GCR                   (MMIO32(LTDC_BASE + 0x18))
#define LTDC_SRCR                  (MMIO32(LTDC_BASE + 0x24))
#define LTDC_BCCR                  (MMIO32(LTDC_BASE + 0x2C))
#define LTDC_IER                   (MMIO32(LTDC_BASE + 0x34))
#define LTDC_ISR                   (MMIO32(LTDC_BASE + 0x38))
#define LTDC_ICR                   (MMIO32(LTDC_BASE + 0x3C))
#define LTDC_LIPCR                 (MMIO32(LTDC_BASE + 0x40))
#define LTDC_CPSR                  (MMIO32(LTDC_BASE + 0x44))
#define LTDC_CDSR                  (MMIO32(LTDC_BASE + 0x48))

#define LTDC_LxCR(x)               (MMIO32(LTDC_BASE + 0x84 + 0x80 * ((x) - 1)))
#define LTDC_L1CR                  (LTDC_LxCR(1))
#define LTDC_L2CR                  (LTDC_LxCR(2))

#define LTDC_LxWHPCR(x)            (MMIO32(LTDC_BASE + 0x88 + 0x80 * ((x) - 1)))
#define LTDC_L1WHPCR               (LTDC_LxWHPCR(1))
#define LTDC_L2WHPCR               (LTDC_LxWHPCR(2))

#define LTDC_LxWVPCR(x)            (MMIO32(LTDC_BASE + 0x8C + 0x80 * ((x) - 1)))
#define LTDC_L1WVPCR               (LTDC_LxWVPCR(1))
#define LTDC_L2WVPCR               (LTDC_LxWVPCR(2))

#define LTDC_LxCKCR(x)             (MMIO32(LTDC_BASE + 0x90 + 0x80 * ((x) - 1)))
#define LTDC_L1CKCR                (LTDC_LxCKCR(1))
#define LTDC_L2CKCR                (LTDC_LxCKCR(2))

#define LTDC_LxPFCR(x)             (MMIO32(LTDC_BASE + 0x94 + 0x80 * ((x) - 1)))
#define LTDC_L1PFCR                (LTDC_LxPFCR(1))
#define LTDC_L2PFCR                (LTDC_LxPFCR(2))

#define LTDC_LxCACR(x)             (MMIO32(LTDC_BASE + 0x98 + 0x80 * ((x) - 1)))
#define LTDC_L1CACR                (LTDC_LxCACR(1))
#define LTDC_L2CACR                (LTDC_LxCACR(2))

#define LTDC_LxDCCR(x)             (MMIO32(LTDC_BASE + 0x9C + 0x80 * ((x) - 1)))
#define LTDC_L1DCCR                (LTDC_LxDCCR(1))
#define LTDC_L2DCCR                (LTDC_LxDCCR(2))

#define LTDC_LxBFCR(x)             (MMIO32(LTDC_BASE + 0xA0 + 0x80 * ((x) - 1)))
#define LTDC_L1BFCR                (LTDC_LxBFCR(1))
#define LTDC_L2BFCR                (LTDC_LxBFCR(2))

#define LTDC_LxCFBAR(x)            (MMIO32(LTDC_BASE + 0xAC + 0x80 * ((x) - 1)))
#define LTDC_L1CFBAR               (LTDC_LxCFBAR(1))
#define LTDC_L2CFBAR               (LTDC_LxCFBAR(2))

#define LTDC_LxCFBLR(x)            (MMIO32(LTDC_BASE + 0xB0 + 0x80 * ((x) - 1)))
#define LTDC_L1CFBLR               (LTDC_LxCFBLR(1))
#define LTDC_L2CFBLR               (LTDC_LxCFBLR(2))

#define LTDC_LxCFBLNR(x)           (MMIO32(LTDC_BASE + 0xB4 + 0x80 * ((x) - 1)))
#define LTDC_L1CFBLNR              (LTDC_LxCFBLNR(1))
#define LTDC_L2CFBLNR              (LTDC_LxCFBLNR(2))

#define LTDC_LxCLUTWR(x)           (MMIO32(LTDC_BASE + 0xC4 + 0x80 * ((x) - 1)))
#define LTDC_L1CLUTWR              (LTDC_LxCLUTWR(1))
#define LTDC_L2CLUTWR              (LTDC_LxCLUTWR(2))

/* --- LTDC_SSCR values ---------------------------------------------------- */

/* Horizontal Synchronization Width */
#define LTDC_SSCR_HSW_SHIFT             16
#define LTDC_SSCR_HSW_MASK              0xfff

/* Vertical Synchronization Height */
#define LTDC_SSCR_VSH_SHIFT             0
#define LTDC_SSCR_VSH_MASK              0x7ff

/* --- LTDC_BPCR values ---------------------------------------------------- */

/* Accumulated Horizontal Back Porch */
#define LTDC_BPCR_AHBP_SHIFT            16
#define LTDC_BPCR_AHBP_MASK             0xfff

/* Accumulated Vertical Back Porch */
#define LTDC_BPCR_AVBP_SHIFT            0
#define LTDC_BPCR_AVBP_MASK             0x7FF

/* --- LTDC_AWCR values ---------------------------------------------------- */

/* Accumulated Active Width */
#define LTDC_AWCR_AAW_SHIFT             16
#define LTDC_AWCR_AAW_MASK              0xfff

/* Accumulated Active Height */
#define LTDC_AWCR_AAH_SHIFT             0
#define LTDC_AWCR_AAH_MASK              0x7ff

/* --- LTDC_TWCR values ---------------------------------------------------- */

/* Total Width */
#define LTDC_TWCR_TOTALW_SHIFT          16
#define LTDC_TWCR_TOTALW_MASK           0xfff

/* Total Height */
#define LTDC_TWCR_TOTALH_SHIFT          0
#define LTDC_TWCR_TOTALH_MASK           0x7ff

/* --- LTDC_GCR values ----------------------------------------------------- */

/* Horizontal Synchronization Polarity */
#define LTDC_GCR_HSPOL                  (1 << 31)

/* Vertical Synchronization Polarity */
#define LTDC_GCR_VSPOL                  (1 << 30)

/* Data Enable Polarity */
#define LTDC_GCR_DEPOL                  (1 << 29)

/* Pixel Clock Polarity */
#define LTDC_GCR_PCPOL                  (1 << 28)

/* Dither Enable */
#define LTDC_GCR_DEN                    (1 << 16)

/* Dither Red Width */
#define LTDC_GCR_DRW_SHIFT              12
#define LTDC_GCR_DRW_MASK               0x7

/* Dither Green Width */
#define LTDC_GCR_DGW_SHIFT              8
#define LTDC_GCR_DGW_MASK               0x7

/* Dither Blue Width */
#define LTDC_GCR_DBW_SHIFT              4
#define LTDC_GCR_DBW_MASK               0x7

/* LCD-TFT Controller Enable */
#define LTDC_GCR_LTDCEN                 (1 << 0)

/* --- LTDC_SRCR values ---------------------------------------------------- */

/* Vertical Blanking Reload */
#define LTDC_SRCR_VBR                   (1 << 1)

/* Immediate Reload */
#define LTDC_SRCR_IMR                   (1 << 0)

/* --- LTDC_BCCR values ---------------------------------------------------- */

/* Background Color Red */
#define LTDC_BCCR_BCRED_SHIFT           16
#define LTDC_BCCR_BCRED_MASK            0xff

/* Background Color Green */
#define LTDC_BCCR_BCGREEN_SHIFT         8
#define LTDC_BCCR_BCGREEN_MASK          0xff

/* Background Color Blue */
#define LTDC_BCCR_BCBLUE_SHIFT          0
#define LTDC_BCCR_BCBLUE_MASK           0xff

/* --- LTDC_IER values ----------------------------------------------------- */

/* Register Reload Interrupt Enable */
#define LTDC_IER_RRIE                   (1 << 3)

/* Transfer Error Interrupt Enable */
#define LTDC_IER_TERRIE                 (1 << 2)

/* FIFO Underrun Interrupt Enable */
#define LTDC_IER_FUIE                   (1 << 1)

/* Line Interrupt Enable */
#define LTDC_IER_LIE                    (1 << 0)

/* --- LTDC_ISR values ----------------------------------------------------- */

/* Register Reload Interrupt Flag */
#define LTDC_ISR_RRIF                   (1 << 3)

/* Transfer Error Interrupt Flag */
#define LTDC_ISR_TERRIF                 (1 << 2)

/* FIFO Underrun Interrupt Flag */
#define LTDC_ISR_FUIF                   (1 << 1)

/* Line Interrupt Flag */
#define LTDC_ISR_LIF                    (1 << 0)

/* --- LTDC_ICR values ----------------------------------------------------- */

/* Clears Register Reload Interrupt Flag */
#define LTDC_ICR_CRRIF                  (1 << 3)

/* Clears Transfer Error Interrupt Flag */
#define LTDC_ICR_CTERRIF                (1 << 2)

/* Clears FIFO Underrun Interrupt Flag */
#define LTDC_ICR_CFUIF                  (1 << 1)

/* Clears Line Interrupt Flag */
#define LTDC_ICR_CLIF                   (1 << 0)

/* --- LTDC_LIPCR values --------------------------------------------------- */

/* Line Interrupt Position */
#define LTDC_LIPCR_LIPOS_SHIFT          0
#define LTDC_LIPCR_LIPOS_MASK           0x7ff

/* --- LTDC_CPSR values ---------------------------------------------------- */

/* Current X Position */
#define LTDC_CPSR_CXPOS_SHIFT           16
#define LTDC_CPSR_CXPOS_MASK            0xffff

/* Current Y Position */
#define LTDC_CPSR_CYPOS_SHIFT           0
#define LTDC_CPSR_CYPOS_MASK            0xffff

/* --- LTDC_CDSR values ---------------------------------------------------- */

/* Horizontal Synchronization Display Status */
#define LTDC_CDSR_HSYNCS                (1 << 3)

/* Vertical Synchronization Display Status */
#define LTDC_CDSR_VSYNCS                (1 << 2)

/* Horizontal Data Enable Display Status */
#define LTDC_CDSR_HDES                  (1 << 1)

/* Vertical Data Enable Display Status */
#define LTDC_CDSR_VDES                  (1 << 0)

/* --- LTDC_LxCR values ---------------------------------------------------- */

/* Color Look-Up Table Enable */
#define LTDC_LxCR_CLUTEN                (1 << 4)

/* Color Keying Enable */
#define LTDC_LxCR_COLKEN                (1 << 1)

/* Layer Enable */
#define LTDC_LxCR_LEN                   (1 << 0)

/* --- LTDC_LxWHPCR values ------------------------------------------------- */

/* Window Horizontal Stop Position */
#define LTDC_LxWHPCR_WHSPPOS_SHIFT      16
#define LTDC_LxWHPCR_WHSPPOS_MASK       0xfff

/* Window Horizontal Start Position */
#define LTDC_LxWHPCR_WHSTPOS_SHIFT      0
#define LTDC_LxWHPCR_WHSTPOS_MASK       0xfff

/* --- LTDC_LxWVPCR values ------------------------------------------------- */

/* Window Vertical Stop Position */
#define LTDC_LxWVPCR_WVSPPOS_SHIFT      16
#define LTDC_LxWVPCR_WVSPPOS_MASK       0x7ff

/* Window Vertical Start Position */
#define LTDC_LxWVPCR_WVSTPOS_SHIFT      0
#define LTDC_LxWVPCR_WVSTPOS_MASK       0x7ff

/* --- LTDC_LxCKCR values -------------------------------------------------- */

/* Color Key Red */
#define LTDC_LxCKCR_CKRED_SHIFT         16
#define LTDC_LxCKCR_CKRED_MASK          0xff

/* Color Key Green */
#define LTDC_LxCKCR_CKGREEN_SHIFT       16
#define LTDC_LxCKCR_CKGREEN_MASK        0xff

/* Color Key Blue */
#define LTDC_LxCKCR_CKBLUE_SHIFT        16
#define LTDC_LxCKCR_CKBLUE_MASK         0xff

/* --- LTDC_LxPFCR values -------------------------------------------------- */

/* Pixel Format */
#define LTDC_LxPFCR_PF_SHIFT            0
#define LTDC_LxPFCR_PF_MASK             0x7

#define LTDC_LxPFCR_PF_ARGB8888         (0b000 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_RGB888           (0b001 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_RGB565           (0b010 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_ARGB1555         (0b011 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_ARGB4444         (0b100 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_L8               (0b101 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_AL44             (0b110 << LTDC_LxPFCR_PF_SHIFT)
#define LTDC_LxPFCR_PF_AL88             (0b111 << LTDC_LxPFCR_PF_SHIFT)

/* --- LTDC_LxCACR values -------------------------------------------------- */

/* Constant Alpha */
#define LTDC_LxCACR_CONSTA_SHIFT        0
#define LTDC_LxCACR_CONSTA_MASK         0xff

/* --- LTDC_LxDCCR values -------------------------------------------------- */

/* Default Color Alpha */
#define LTDC_LxDCCR_DCALPHA_SHIFT       24
#define LTDC_LxDCCR_DCALPHA_MASK        1

/* Default Color Red */
#define LTDC_LxDCCR_DCRED_SHIFT         16
#define LTDC_LxDCCR_DCRED_MASK          1

/* Default Color Green */
#define LTDC_LxDCCR_DCGREEN_SHIFT       8
#define LTDC_LxDCCR_DCGREEN_MASK        1

/* Default Color Blue */
#define LTDC_LxDCCR_DCBLUE_SHIFT        0
#define LTDC_LxDCCR_DCBLUE_MASK         1

/* --- LTDC_LxBFCR values -------------------------------------------------- */

/* Blending Factor 1 */
#define LTDC_LxBFCR_BF1_SHIFT           8
#define LTDC_LxBFCR_BF1_MASK            0x7

#define LTDC_LxBFCR_BF1_CONSTANT_ALPHA  (0b100 << LTDC_LxBFCR_BF1_SHIFT)
#define LTDC_LxBFCR_BF1_PIXEL_ALPHA_x_CONSTANT_ALPHA \
                                        (0b110 << LTDC_LxBFCR_BF1_SHIFT)

/* Blending Factor 2 */
#define LTDC_LxBFCR_BF2_SHIFT           0
#define LTDC_LxBFCR_BF2_MASK            0x7

#define LTDC_LxBFCR_BF2_CONSTANT_ALPHA  (0b101 << LTDC_LxBFCR_BF2_SHIFT)
#define LTDC_LxBFCR_BF2_PIXEL_ALPHA_x_CONSTANT_ALPHA \
                                        (0b111 << LTDC_LxBFCR_BF2_SHIFT)

/* --- LTDC_LxCFBAR values ------------------------------------------------- */

/* Color Frame Buffer Start Address */
#define LTDC_LxCFBAR_CFBAR_SHIFT        0
#define LTDC_LxCFBAR_CFBAR_MASK         0xffffffff

/* --- LTDC_LxCFBLR values ------------------------------------------------- */

/* Color Frame Buffer Pitch */
#define LTDC_LxCFBLR_CFBP_SHIFT         16
#define LTDC_LxCFBLR_CFBP_MASK          0x1fff

/* Color Frame Buffer Line Length */
#define LTDC_LxCFBLR_CFBLL_SHIFT        0
#define LTDC_LxCFBLR_CFBLL_MASK         0x1fff

/* --- LTDC_LxCFBLNR values ------------------------------------------------ */

/* Frame Buffer Line Number */
#define LTDC_LxCFBLNR_CFBLNBR_SHIFT     0
#define LTDC_LxCFBLNR_CFBLNBR_MASK      0x3ff

/* --- LTDC_LxCLUTWR values ------------------------------------------------ */

/* CLUT Address */
#define LTDC_LxCLUTWR_CLUTADD_SHIFT     24
#define LTDC_LxCLUTWR_CLUTADD_MASK      0xff

/* Red */
#define LTDC_LxCLUTWR_RED_SHIFT         16
#define LTDC_LxCLUTWR_RED_MASK          0xff

/* Green */
#define LTDC_LxCLUTWR_GREEN_SHIFT       8
#define LTDC_LxCLUTWR_GREEN_MASK        0xff

/* Blue */
#define LTDC_LxCLUTWR_BLUE_SHIFT        0
#define LTDC_LxCLUTWR_BLUE_MASK         0xff

#endif /* !LIBOPENCM3_LTDC_H */
