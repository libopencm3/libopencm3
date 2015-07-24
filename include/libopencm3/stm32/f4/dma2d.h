/** @addtogroup dma2d_defines

@author @htmlonly &copy; @endhtmlonly 2015
Moritz Nöltner-Augustin <>

*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DMA.H
The order of header inclusion is important. dma.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_DMA2D_H
/** @endcond */
#ifndef LIBOPENCM3_DMA2D_H
#define LIBOPENCM3_DMA2D_H

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/* DMA2D controller base address (for convenience) */
#define DMA2D				DMA2D_BASE


/* --- DMA2D controller registers -------------------------------------------- */

/* DMA2D control register (DMA2D_CR) */
#define DMA2D_CR			(DMA2D + 0x0000)

/* DMA2D interrupt status register (DMA2D_ISR) */
#define DMA2D_ISR			(DMA2D + 0x0004)

/* DMA2D interrupt flag clear register (DMA2D_IFCR) */
#define DMA2D_IFCR			(DMA2D + 0x0008)

/* DMA2D foreground memory address register (DMA2D_FGMAR) */
#define DMA2D_FGMAR			(DMA2D + 0x000C)

/* DMA2D foreground offset register (DMA2D_FGOR) */
#define DMA2D_FGOR			(DMA2D + 0x0010)

/* DMA2D background memory address register (DMA2D_BGMAR) */
#define DMA2D_BGMAR			(DMA2D + 0x0014)

/* DMA2D background offset register (DMA2D_BGOR) */
#define DMA2D_BGOR			(DMA2D + 0x0018)

/* DMA2D foreground PFC control register (DMA2D_FGPFCCR) */
#define DMA2D_FGPFCCR		(DMA2D + 0x001C)

/* DMA2D foreground color register (DMA2D_FGCOLR) */
#define DMA2D_FGCOLR		(DMA2D + 0x0020)

/* DMA2D background PFC control register (DMA2D_BGPFCCR) */
#define DMA2D_BGPFCCR		(DMA2D + 0x0024)

/* DMA2D background color register (DMA2D_BGCOLR) */
#define DMA2D_BGCOLR		(DMA2D + 0x0028)

/* DMA2D foreground CLUT memory address register (DMA2D_FGCMAR) */
#define DMA2D_FGCMAR		(DMA2D + 0x002C)

/* DMA2D background CLUT memory address register (DMA2D_BGCMAR) */
#define DMA2D_BGCMAR		(DMA2D + 0x0030)

/* DMA2D output PFC control register (DMA2D_OPFCCR) */
#define DMA2D_OPFCCR		(DMA2D + 0x0034)

/* DMA2D output color register (DMA2D_OCOLR) */
#define DMA2D_OCOLR			(DMA2D + 0x0038)

/* DMA2D output memory address register (DMA2D_OMAR) */
#define DMA2D_OMAR			(DMA2D + 0x003C)

/* DMA2D output offset register (DMA2D_OOR) */
#define DMA2D_OOR			(DMA2D + 0x0040)

/* DMA2D number of line register (DMA2D_NLR) */
#define DMA2D_NLR			(DMA2D + 0x0044)

/* DMA2D line watermark register (DMA2D_LWR) */
#define DMA2D_LWR			(DMA2D + 0x0048)

/* DMA2D AHB master timer configuration register (DMA2D_AMTCR) */
#define DMA2D_AMTCR			(DMA2D + 0x004C)

/* DMA2D AHB master timer configuration register (DMA2D_AMTCR) */
#define DMA2D_AMTCR			(DMA2D + 0x004C)



/* --- DMA2D_CR value ----------------------------------------------------- */

/* Bits 31:18 Reserved, must be kept at reset value */

/* MODE: DMA2D mode */
#define DMA2D_CR_MODE_SHIFT				16
#define DMA2D_CR_MODE_M2M				(0x0 << DMA2D_CR_MODE_SHIFT)
#define DMA2D_CR_MODE_M2M_PFC			(0x1 << DMA2D_CR_MODE_SHIFT)
#define DMA2D_CR_MODE_M2M_PFC_BLEND		(0x2 << DMA2D_CR_MODE_SHIFT)
#define DMA2D_CR_MODE_R2M				(0x3 << DMA2D_CR_MODE_SHIFT)

/* CEIE: Configuration errror interrupt enable */
#define DMA2D_CR_CEIE					(1 << 13)
/* CTCIE: CLUT transfer complete interrupt enable */
#define DMA2D_CR_CTCIE					(1 << 12)
/* CAEIE: CLUT acces error interrupt enable */
#define DMA2D_CR_CAEIE					(1 << 11)
/* TWIE: Transfer watermark interrupt enable */
#define DMA2D_CR_TWIE					(1 << 10)
/* TCIE: Transfer complete interrupt enable */
#define DMA2D_CR_TCIE					(1 << 9)
/* TCIE: Transfer complete interrupt enable */
#define DMA2D_CR_TEIE					(1 << 8)
/* Bits 7:3 Reserved, must be kept at reset value */
/* ABORT: Abort current transfer */
#define DMA2D_CR_ABORT					(1 << 2)
/* SUSP: Suspend the current transfer */
#define DMA2D_CR_SUSP					(1 << 1)
/* START: Start a transfer */
#define DMA2D_CR_START					(1 << 0)


/* --- DMA2D_ISR value ----------------------------------------------------- */

/* Bits 31:6 Reserved, must be kept at reset value */
/* CEIF: Configuration error interrupt flag */
#define DMA2D_ISR_CEIF					(1 << 5)
/* CTCIF: CLUT transfer complete interrupt flag */
#define DMA2D_ISR_CTCIF					(1 << 4)
/* CAEIF: CLUT access error interrupt flag */
#define DMA2D_ISR_CAEIF					(1 << 3)
/* TWIF: Transfer watermark interrupt flag */
#define DMA2D_ISR_TWIF					(1 << 2)
/* TCIF: Transfer complete interrupt flag */
#define DMA2D_ISR_TCIF					(1 << 1)
/* TEIF: Tansfer error interrupt flag */
#define DMA2D_ISR_TEIF					(1 << 0)


/* --- DMA2D_IFCR value ----------------------------------------------------- */

/* Bits 31:6 Reserved, must be kept at reset value */
/* CCEIF: Clear configuration error interrupt flag */
#define DMA2D_IFCR_CCEIF				(1 << 5)
/* CCTCIF: Clear CLUT transfer complete interrupt flag */
#define DMA2D_IFCR_CCTCIF				(1 << 4)
/* CCAEIF: Clear CLUT access error interrupt flag */
#define DMA2D_IFCR_CCAEIF				(1 << 3)
/* CTWIF: Clear transfer watermark interrupt flag */
#define DMA2D_IFCR_CTWIF				(1 << 2)
/* CTCIF: Clear transfer complete interrupt flag */
#define DMA2D_IFCR_CTCIF				(1 << 1)
/* CTEIF: Clear transfer error interrupt flag */
#define DMA2D_IFCR_CTEIF				(1 << 0)


/* --- DMA2D_FGMAR value ----------------------------------------------------- */
/* None */


/* --- DMA2D_FGOR value ----------------------------------------------------- */

/* Bits 31:14 Reserved, must be kept at reset value */
/* LO: Line offset */
#define DMA2D_FGOR_LO_MASK				(0x3FF << 0)


/* --- DMA2D_BGMAR value ----------------------------------------------------- */
/* None */


/* --- DMA2D_BGOR value ----------------------------------------------------- */

/* Bits 31:14 Reserved, must be kept at reset value */
/* LO: Line offset */
#define DMA2D_BGOR_LO_MASK				(0x3FF << 0)


/* --- DMA2D_FGPFCCR value ----------------------------------------------------- */

/* ALPHA: Fixed alpha value which can replace the original alpha value */
#define DMA2D_FGPFCCR_ALPHA_SHIFT		24
#define DMA2D_FGPFCCR_ALPHA_MASK		(0xFF << DMA2D_FGPFCCR_ALPHA_SHIFT)

/* Bits 23:18 Reserved, must be kept at reset value */

/* AM: Alpha channel mode: leave alone, replace or multiply with ALPHA */
#define DMA2D_FGPFCCR_AM_SHIFT			16
#define DMA2D_FGPFCCR_AM_NO_CHANGE		(0x0 << DMA2D_FGPFCCR_AM_SHIFT)
#define DMA2D_FGPFCCR_AM_REPLACE		(0x1 << DMA2D_FGPFCCR_AM_SHIFT)
#define DMA2D_FGPFCCR_AM_MULTIPLY		(0x2 << DMA2D_FGPFCCR_AM_SHIFT)

/* CS: CLUT size, CS+1 entries */
#define DMA2D_FGPFCCR_CS_SHIFT			8
#define DMA2D_FGPFCCR_CS_MASK			(0xFF << DMA2D_FGPFCCR_CS_SHIFT)

/* Bits 7:6 Reserved, must be kept at reset value */

/* START: Start automatic loading of the CLUT */
#define DMA2D_FGPFCCR_START				(1 << 5)

/* CCM: CLUT color mode */
#define DMA2D_FGPFCCR_CCM_SHIFT			4
#define DMA2D_FGPFCCR_CCM_ARGB			(0 << DMA2D_FGPFCCR_CCM_SHIFT)
#define DMA2D_FGPFCCR_CCM_RGB			(1 << DMA2D_FGPFCCR_CCM_SHIFT)

/* CM: Color mode for the foreground image */
#define DMA2D_FGPFCCR_CM_SHIFT			0
#define DMA2D_FGPFCCR_CM_ARGB8888		(0x0 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_RGB888			(0x1 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_RGB565			(0x2 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_ARGB1555		(0x3 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_ARGB4444		(0x4 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_L8				(0x5 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_AL44			(0x6 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_AL88			(0x7 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_L4				(0x8 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_A8				(0x9 << DMA2D_FGPFCCR_CM_SHIFT)
#define DMA2D_FGPFCCR_CM_A4				(0xA << DMA2D_FGPFCCR_CM_SHIFT)


/* --- DMA2D_FGCOLR value ----------------------------------------------------- */

/* Bits 31:24 Reserved, must be kept at reset value */
/* RED: Red value for the A4 or A8 mode of the foreground image */
#define DMA2D_FGCOLR_RED_SHIFT			16
#define DMA2D_FGCOLR_RED_MASK			(0xF << DMA2D_FGCOLR_RED_SHIFT)

/* GREEN: Green value for the A4 or A8 mode of the foreground image */
#define DMA2D_FGCOLR_GREEN_SHIFT		8
#define DMA2D_FGCOLR_GREEN_MASK			(0xF << DMA2D_FGCOLR_RED_SHIFT)

/* BLUE: Blue value for the A4 or A8 mode of the foreground image */
#define DMA2D_FGCOLR_BLUE_SHIFT			0
#define DMA2D_FGCOLR_BLUE_MASK			(0xF << DMA2D_FGCOLR_RED_SHIFT)


/* --- DMA2D_BGPFCCR value ----------------------------------------------------- */

/* ALPHA: Fixed alpha value which can replace the original alpha value */
#define DMA2D_BGPFCCR_ALPHA_SHIFT		24
#define DMA2D_BGPFCCR_ALPHA_MASK		(0xFF << DMA2D_BGPFCCR_ALPHA_SHIFT)

/* Bits 23:18 Reserved, must be kept at reset value */

/* AM: Alpha channel mode: leave alone, replace or multiply with ALPHA */
#define DMA2D_BGPFCCR_AM_SHIFT			16
#define DMA2D_BGPFCCR_AM_NO_MOD			(0x0 << DMA2D_BGPFCCR_AM_SHIFT)
#define DMA2D_BGPFCCR_AM_REPLACE		(0x1 << DMA2D_BGPFCCR_AM_SHIFT)
#define DMA2D_BGPFCCR_AM_MULTIPLY		(0x2 << DMA2D_BGPFCCR_AM_SHIFT)

/* CS: CLUT size, CS+1 entries */
#define DMA2D_BGPFCCR_CS_SHIFT			8
#define DMA2D_BGPFCCR_CS_MASK			(0xFF << DMA2D_BGPFCCR_CS_SHIFT)

/* Bits 7:6 Reserved, must be kept at reset value */

/* START: Start automatic loading of the CLUT */
#define DMA2D_BGPFCCR_START				(1 << 5)

/* CCM: CLUT color mode */
#define DMA2D_BGPFCCR_CCM_SHIFT			4
#define DMA2D_BGPFCCR_CCM_ARGB			(0 << DMA2D_BGPFCCR_CCM_SHIFT)
#define DMA2D_BGPFCCR_CCM_RGB			(1 << DMA2D_BGPFCCR_CCM_SHIFT)

/* CM: Color mode for the background image */
#define DMA2D_BGPFCCR_CM_SHIFT			0
#define DMA2D_BGPFCCR_CM_ARGB8888		(0x0 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_RGB888			(0x1 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_RGB565			(0x2 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_ARGB1555		(0x3 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_ARGB4444		(0x4 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_L8				(0x5 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_AL44			(0x6 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_AL88			(0x7 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_L4				(0x8 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_A8				(0x9 << DMA2D_BGPFCCR_CM_SHIFT)
#define DMA2D_BGPFCCR_CM_A4				(0xA << DMA2D_BGPFCCR_CM_SHIFT)


/* --- DMA2D_BGCOLR value ----------------------------------------------------- */

/* Bits 31:24 Reserved, must be kept at reset value */
/* RED: Red value for the A4 or A8 mode of the foreground image */
#define DMA2D_BGCOLR_RED_SHIFT			16
#define DMA2D_BGCOLR_RED_MASK			(0xF << DMA2D_BGCOLR_RED_SHIFT)

/* GREEN: Green value for the A4 or A8 mode of the foreground image */
#define DMA2D_BGCOLR_GREEN_SHIFT		8
#define DMA2D_BGCOLR_GREEN_MASK			(0xF << DMA2D_BGCOLR_RED_SHIFT)

/* BLUE: Blue value for the A4 or A8 mode of the foreground image */
#define DMA2D_BGCOLR_BLUE_SHIFT			0
#define DMA2D_BGCOLR_BLUE_MASK			(0xF << DMA2D_BGCOLR_RED_SHIFT)


/* --- DMA2D_FGCMAR value ----------------------------------------------------- */
/* None */

/* --- DMA2D_BGCMAR value ----------------------------------------------------- */
/* None */


/* --- DMA2D_OPFCCR value ----------------------------------------------------- */

/* Bits 31:3 Reserved, must be kept at reset value */
/* CM: Color mode for the output image */
#define DMA2D_OPFCCR_CM_SHIFT			0
#define DMA2D_OPFCCR_CM_ARGB8888		(0x0 << DMA2D_OPFCCR_CM_SHIFT)
#define DMA2D_OPFCCR_CM_RGB888			(0x1 << DMA2D_OPFCCR_CM_SHIFT)
#define DMA2D_OPFCCR_CM_RGB565			(0x2 << DMA2D_OPFCCR_CM_SHIFT)
#define DMA2D_OPFCCR_CM_ARGB1555		(0x3 << DMA2D_OPFCCR_CM_SHIFT)
#define DMA2D_OPFCCR_CM_ARGB4444		(0x4 << DMA2D_OPFCCR_CM_SHIFT)


/* --- DMA2D_OCOLR value ----------------------------------------------------- */

/* ALPHA: Alpha channel value of the output color */
#define DMA2D_OCOLR_ALPHA_SHIFT			24
#define DMA2D_OCOLR_ALPHA_MASK			(0xF << DMA2D_OCOLR_ALPHA_SHIFT)

/* RED: Red channel value of the output color */
#define DMA2D_OCOLR_RED_SHIFT			16
#define DMA2D_OCOLR_RED_MASK			(0xF << DMA2D_OCOLR_RED_SHIFT)

/* GREEN: Green channel value of the output color */
#define DMA2D_OCOLR_GREEN_SHIFT			8
#define DMA2D_OCOLR_GREEN_MASK			(0xF << DMA2D_OCOLR_GREEN_SHIFT)

/* BLUE: Blue channel value of the output color */
#define DMA2D_OCOLR_BLUE_SHIFT			0
#define DMA2D_OCOLR_BLUE_MASK			(0xF << DMA2D_OCOLR_BLUE_SHIFT)


/* --- DMA2D_OMAR value ----------------------------------------------------- */
/* None */


/* --- DMA2D_OOR value ----------------------------------------------------- */

/* Bits 31:14 Reserved, must be kept at reset value */
/* LO: Line offset */
#define DMA2D_OOR_LO_MASK				(0x3FF << 0)


/* --- DMA2D_NLR value ----------------------------------------------------- */

/* Bits 31:30 Reserved, must be kept at reset value */
/* PL: Number of pixel per line of the area to be transferred */
#define DMA2D_NLR_PL_SHIFT				16
#define DMA2D_NLR_PL_MASK				(0x3FF << DMA2D_NLR_PL_SHIFT)

/* NL: Number of lines of the area to be transferred */
#define DMA2D_NLR_NL_SHIFT				0
#define DMA2D_NLR_NL_MASK				(0xFFFF << DMA2D_NLR_NL_SHIFT)


/* --- DMA2D_LWR value ----------------------------------------------------- */

/* Bits 31:16 Reserved, must be kept at reset value */
/* LW: Line number for watermarking, generates an interrupt when that line is transferred */
#define DMA2D_LWR_LW_SHIFT				0
#define DMA2D_LWR_LW_MASK				(0xFFFF << DMA2D_LWR_LW_SHIFT)


/* --- DMA2D_AMTCR value ----------------------------------------------------- */

/* Bits 31:16 Reserved */
/* DT: Dead time between to consecutive on the AHB master port in AHB cycles */
#define DMA2D_AMTCR_DT_SHIFT			8
#define DMA2D_AMTCR_DT_MASK				(0xFF << DMA2D_AMTCR_DT_SHIFT)
/* Bits 7:16 Reserved */
/* EN: Enables the dead time functionality */
#define DMA2D_AMTCR_EN					1






















/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

//void dma_stream_reset(uint32_t dma, uint8_t stream);

END_DECLS
/**@}*/
#endif
/** @cond */
#else
#warning "dma2d.h should not be included explicitly, only via dma2d.h"
#endif
/** @endcond */

