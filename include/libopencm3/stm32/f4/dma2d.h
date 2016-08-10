/*
 * STM32F4 DMA2D Register defines
 *
 * Copyright (C) 2016, Chuck McManis <cmcmanis@mcmanis.com>
 *
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
 *
 */

#include <libopencm3/stm32/memorymap.h>
#ifndef uint32_t
#include <stdint.h>
#endif


#ifndef DMA2D_H
#define DMA2D_H
/*
 * A couple of helper macros to avoid copy pasta code
 * For multi-bit fields we can use these macros to create
 * a unified SET_<reg>_<field> version and a GET_<reg_<field> version.
 */
#define DMA2D_GET(reg, field, x) \
    (((x) >> DMA2D_ ## reg ## _ ## field ##_SHIFT) & DMA2D_ ## reg ##_ ## field ##_MASK)

#define DMA2D_SET(reg, field, x) \
    (((x) & DMA2D_ ## reg ##_## field ##_MASK) << DMA2D_## reg ##_## field ##_SHIFT)

/* DMA2D Control Register */
#define DMA2D_CR			MMIO32(DMA2D_BASE + 0x0U)
#define DMA2D_CR_MODE_SHIFT		16
#define DMA2D_CR_MODE_MASK		0x3
#define DMA2D_CR_MODE_M2M		0	/* memory to memory */
#define DMA2D_CR_MODE_M2MWPFC		1	/* memory to memory with pix convert */
#define DMA2D_CR_MODE_M2MWB		2	/* memory to memory with blend */
#define DMA2D_CR_MODE_R2M		3	/* register to memory */
#define DMA2D_CR_CEIE			(1 << 13)
#define DMA2D_CR_CTCIE			(1 << 12)
#define DMA2D_CR_CAEIE			(1 << 11)
#define DMA2D_CR_TWIE			(1 << 10)
#define DMA2D_CR_TCIE			(1 << 9)
#define DMA2D_CR_TEIE			(1 << 8)
#define DMA2D_CR_ABORT			(1 << 2)
#define DMA2D_CR_SUSP			(1 << 1)
#define DMA2D_CR_START			(1 << 0)

/* DMA2D Interrupt Status Register */
#define DMA2D_ISR			MMIO32(DMA2D_BASE + 0x4U)
#define DMA2D_ISR_CEIF			(1 << 5)
#define DMA2D_ISR_CTCIF			(1 << 4)
#define DMA2D_ISR_CAEIF			(1 << 3)
#define DMA2D_ISR_TWIF			(1 << 2)
#define DMA2D_ISR_TCIF			(1 << 1)
#define DMA2D_ISR_TEIF			(1 << 0)

/* DMA2D Interrupt Flag Clear Register */
#define DMA2D_IFCR			MMIO32(DMA2D_BASE + 0x8U)
#define DMA2D_IFCR_CCEIF		(1 << 5)
#define DMA2D_IFCR_CCTCIF		(1 << 4)
/* this is what the reference manual specifies */
#define DMA2D_IFCR_CAECIF		(1 << 3)
/* this is what it "should be" */
#define DMA2D_IFCR_CCAEIF		(1 << 3)
#define DMA2D_IFCR_CTWIF		(1 << 2)
#define DMA2D_IFCR_CTCIF		(1 << 1)
#define DMA2D_IFCR_CTEIF		(1 << 0)

/* DMA2D Foreground Memory Address Register */
#define DMA2D_FGMAR			MMIO32(DMA2D_BASE + 0xCU)

/* DMA2D Foreground Offset Register */
#define DMA2D_FGOR			MMIO32(DMA2D_BASE + 0x10U)
#define DMA2D_FGOR_LO_SHIFT		0
#define DMA2D_FGOR_LO_MASK		0x3fff

/* DMA2D Background Memory Address Register */
#define DMA2D_BGMAR			MMIO32(DMA2D_BASE + 0x14U)

/* DMA2D Background Offset Register */
#define DMA2D_BGOR			MMIO32(DMA2D_BASE + 0x18U)
#define DMA2D_BGOR_LO_SHIFT		0
#define DMA2D_BGOR_LO_MASK		0x3fff

/* DMA2D Foreground PFC Control Register */
#define DMA2D_FGPFCCR			MMIO32(DMA2D_BASE + 0x1cU)
#define DMA2D_FGPFCCR_ALPHA_SHIFT	24
#define DMA2D_FGPFCCR_ALPHA_MASK	0xff
#define DMA2D_FGPFCCR_AM_SHIFT		16
#define DMA2D_FGPFCCR_AM_MASK		0x3
#define DMA2D_FGPFCCR_AM_NONE		0
#define DMA2D_FGPFCCR_AM_FORCE		1
#define DMA2D_FGPFCCR_AM_PRODUCT	2
#define DMA2D_FGPFCCR_CS_SHIFT		8
#define DMA2D_FGPFCCR_CS_MASK		0xff
#define DMA2D_FGPFCCR_START		(1 << 5)
#define DMA2D_FGPFCCR_CCM_ARGB8888	(0 << 4)
#define DMA2D_FGPFCCR_CCM_RGB888	(1 << 4)
#define DMA2D_FGPFCCR_CM_SHIFT		0
#define DMA2D_FGPFCCR_CM_MASK		0xf
#define DMA2D_FGPFCCR_CM_ARGB8888	0
#define DMA2D_FGPFCCR_CM_RGB888		1
#define DMA2D_FGPFCCR_CM_RGB565		2
#define DMA2D_FGPFCCR_CM_ARGB1555	3
#define DMA2D_FGPFCCR_CM_ARGB4444	4
#define DMA2D_FGPFCCR_CM_L8		5
#define DMA2D_FGPFCCR_CM_AL44		6
#define DMA2D_FGPFCCR_CM_AL88		7
#define DMA2D_FGPFCCR_CM_L4		8
#define DMA2D_FGPFCCR_CM_A8		9
#define DMA2D_FGPFCCR_CM_A4		10

/* DMA2D Foreground Color Register */
#define DMA2D_FGCOLR			MMIO32(DMA2D_BASE + 0x20U)
#define DMA2D_FGCOLR_RED_SHIFT		16
#define DMA2D_FGCOLR_RED_MASK		0xff
#define DMA2D_FGCOLR_GREEN_SHIFT	8
#define DMA2D_FGCOLR_GREEN_MASK		0xff
#define DMA2D_FGCOLR_BLUE_SHIFT		0
#define DMA2D_FGCOLR_BLUE_MASK		0xff

/* DMA2D Background PFC Control Register */
#define DMA2D_BGPFCCR			MMIO32(DMA2D_BASE + 0x24U)
#define DMA2D_BGPFCCR_ALPHA_SHIFT	24
#define DMA2D_BGPFCCR_ALPHA_MASK	0xff
#define DMA2D_BGPFCCR_AM_SHIFT		16
#define DMA2D_BGPFCCR_AM_MASK		0x3
#define DMA2D_BGPFCCR_AM_NONE		0
#define DMA2D_BGPFCCR_AM_FORCE		1
#define DMA2D_BGPFCCR_AM_PRODUCT	2
#define DMA2D_BGPFCCR_CS_SHIFT		8
#define DMA2D_BGPFCCR_CS_MASK		0xff
#define DMA2D_BGPFCCR_START		(1 << 5)
#define DMA2D_BGPFCCR_CCM_ARGB8888	(0 << 4)
#define DMA2D_BGPFCCR_CCM_RGB888	(1 << 4)
#define DMA2D_BGPFCCR_CM_SHIFT		0
#define DMA2D_BGPFCCR_CM_MASK		0xf
#define DMA2D_BGPFCCR_CM_ARGB8888	0
#define DMA2D_BGPFCCR_CM_RGB888		1
#define DMA2D_BGPFCCR_CM_RGB565		2
#define DMA2D_BGPFCCR_CM_ARGB1555	3
#define DMA2D_BGPFCCR_CM_ARGB4444	4
#define DMA2D_BGPFCCR_CM_L8		5
#define DMA2D_BGPFCCR_CM_AL44		6
#define DMA2D_BGPFCCR_CM_AL88		7
#define DMA2D_BGPFCCR_CM_L4		8
#define DMA2D_BGPFCCR_CM_A8		9
#define DMA2D_BGPFCCR_CM_A4		10

/* DMA2D Background Color Register */
#define DMA2D_BGCOLR			MMIO32(DMA2D_BASE + 0x28U)
#define DMA2D_BGCOLR_RED_SHIFT		16
#define DMA2D_BGCOLR_RED_MASK		0xff
#define DMA2D_BGCOLR_GREEN_SHIFT	8
#define DMA2D_BGCOLR_GREEN_MASK		0xff
#define DMA2D_BGCOLR_BLUE_SHIFT		0
#define DMA2D_BGCOLR_BLUE_MASK		0xff

/* DMA2D Foreground CLUT Memory Address Register */
#define DMA2D_FGCMAR			MMIO32(DMA2D_BASE + 0x2CU)

/* DMA2D Background CLUT Memory Address Register */
#define DMA2D_BGCMAR			MMIO32(DMA2D_BASE + 0x30U)

/* DMA2D Output PFC Control Register */
#define DMA2D_OPFCCR			MMIO32(DMA2D_BASE + 0x34U)
#define DMA2D_OPFCCR_CM_SHIFT		0
#define DMA2D_OPFCCR_CM_MASK		0x3
#define DMA2D_OPFCCR_CM_ARGB8888	0
#define DMA2D_OPFCCR_CM_RGB888		1
#define DMA2D_OPFCCR_CM_RGB565		2
#define DMA2D_OPFCCR_CM_ARGB4444	3

/* DMA2D Output Color Register */
/* The format of this register depends on PFC control above */
#define DMA2D_OCOLR			MMIO32(DMA2D_BASE + 0x38U)

/* DMA2D Output Memory Address Register */
#define DMA2D_OMAR			MMIO32(DMA2D_BASE + 0x3CU)

/* DMA2D Output offset Register */
#define DMA2D_OOR			MMIO32(DMA2D_BASE + 0x40U)
#define DMA2D_OOR_LO_SHIFT		0
#define DMA2D_OOR_LO_MASK		0x3fff

/* DMA2D Number of Lines Register */
#define DMA2D_NLR			MMIO32(DMA2D_BASE + 0x44U)
#define DMA2D_NLR_PL_SHIFT		16
#define DMA2D_NLR_PL_MASK		0x3fff
#define DMA2D_NLR_NL_SHIFT		0
#define DMA2D_NLR_NL_MASK		0xffff

/* DMA2D Line Watermark Register */
#define DMA2D_LWR			MMIO32(DMA2D_BASE + 0x48U)
#define DMA2D_LWR_LW_SHIFT		0
#define DMA2D_LWR_LW_MASK		0xffff

/* DMA2D AHB Master Timer Config Register */
#define DMA2D_AMTCR			MMIO32(DMA2D_BASE + 0x4CU)
#define DMA2D_AMTCR_DT_SHIFT		8
#define DMA2D_AMTCR_DT_MASK		0xff
#define DMA2D_AMTCR_EN			(1 << 0)

/* DMA2D Foreground Color Lookup table */
#define DMA2D_FG_CLUT			(uint32_t *)(DMA2D_BASE + 0x400U)

/* DMA2D Background Color Lookup table */
#define DMA2D_BG_CLUT			(uint32_t *)(DMA2D_BASE + 0x800U)

#endif
