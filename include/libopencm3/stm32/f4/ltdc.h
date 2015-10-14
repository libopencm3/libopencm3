/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Oliver Meier <h2obrain@gmail.com>
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


#ifndef LIBOPENCM3_STM32_F4_LTDC_H_
#define LIBOPENCM3_STM32_F4_LTDC_H_


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

/* x == LTDC_LAYER_x */
#define LTDC_LxCR(x)               (MMIO32(LTDC_BASE + 0x84 + 0x80 * ((x) - 1)))
#define LTDC_L1CR                  LTDC_LxCR(LTDC_LAYER_1)
#define LTDC_L2CR                  LTDC_LxCR(LTDC_LAYER_2)

#define LTDC_LxWHPCR(x)            (MMIO32(LTDC_BASE + 0x88 + 0x80 * ((x) - 1)))
#define LTDC_L1WHPCR               LTDC_LxWHPCR(LTDC_LAYER_1)
#define LTDC_L2WHPCR               LTDC_LxWHPCR(LTDC_LAYER_2)

#define LTDC_LxWVPCR(x)            (MMIO32(LTDC_BASE + 0x8C + 0x80 * ((x) - 1)))
#define LTDC_L1WVPCR               LTDC_LxWVPCR(LTDC_LAYER_1)
#define LTDC_L2WVPCR               LTDC_LxWVPCR(LTDC_LAYER_2)

#define LTDC_LxCKCR(x)             (MMIO32(LTDC_BASE + 0x90 + 0x80 * ((x) - 1)))
#define LTDC_L1CKCR                LTDC_LxCKCR(LTDC_LAYER_1)
#define LTDC_L2CKCR                LTDC_LxCKCR(LTDC_LAYER_2)

#define LTDC_LxPFCR(x)             (MMIO32(LTDC_BASE + 0x94 + 0x80 * ((x) - 1)))
#define LTDC_L1PFCR                LTDC_LxPFCR(LTDC_LAYER_1)
#define LTDC_L2PFCR                LTDC_LxPFCR(LTDC_LAYER_2)

#define LTDC_LxCACR(x)             (MMIO32(LTDC_BASE + 0x98 + 0x80 * ((x) - 1)))
#define LTDC_L1CACR                LTDC_LxCACR(LTDC_LAYER_1)
#define LTDC_L2CACR                LTDC_LxCACR(LTDC_LAYER_2)

#define LTDC_LxDCCR(x)             (MMIO32(LTDC_BASE + 0x9C + 0x80 * ((x) - 1)))
#define LTDC_L1DCCR                LTDC_LxDCCR(LTDC_LAYER_1)
#define LTDC_L2DCCR                LTDC_LxDCCR(LTDC_LAYER_2)

#define LTDC_LxBFCR(x)             (MMIO32(LTDC_BASE + 0xA0 + 0x80 * ((x) - 1)))
#define LTDC_L1BFCR                LTDC_LxBFCR(LTDC_LAYER_1)
#define LTDC_L2BFCR                LTDC_LxBFCR(LTDC_LAYER_2)

#define LTDC_LxCFBAR(x)            (MMIO32(LTDC_BASE + 0xAC + 0x80 * ((x) - 1)))
#define LTDC_L1CFBAR               LTDC_LxCFBAR(LTDC_LAYER_1)
#define LTDC_L2CFBAR               LTDC_LxCFBAR(LTDC_LAYER_2)

#define LTDC_LxCFBLR(x)            (MMIO32(LTDC_BASE + 0xB0 + 0x80 * ((x) - 1)))
#define LTDC_L1CFBLR               LTDC_LxCFBLR(LTDC_LAYER_1)
#define LTDC_L2CFBLR               LTDC_LxCFBLR(LTDC_LAYER_2)

#define LTDC_LxCFBLNR(x)           (MMIO32(LTDC_BASE + 0xB4 + 0x80 * ((x) - 1)))
#define LTDC_L1CFBLNR              LTDC_LxCFBLNR(LTDC_LAYER_1)
#define LTDC_L2CFBLNR              LTDC_LxCFBLNR(LTDC_LAYER_2)

#define LTDC_LxCLUTWR(x)           (MMIO32(LTDC_BASE + 0xC4 + 0x80 * ((x) - 1)))
#define LTDC_L1CLUTWR              LTDC_LxCLUTWR(LTDC_LAYER_1)
#define LTDC_L2CLUTWR              LTDC_LxCLUTWR(LTDC_LAYER_2)


#define LTDC_LAYER_1 1
#define LTDC_LAYER_2 2

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

/* GCR - control register */
#define LTDC_GCR_LTDC_ENABLE       (1<<0)
#define LTDC_GCR_DITHER_ENABLE     (1<<16)

#define LTDC_GCR_PCPOL_ACTIVE_LOW  (0<<28)
#define LTDC_GCR_PCPOL_ACTIVE_HIGH (1<<28)

#define LTDC_GCR_DEPOL_ACTIVE_LOW  (0<<29)
#define LTDC_GCR_DEPOL_ACTIVE_HIGH (1<<29)

#define LTDC_GCR_VSPOL_ACTIVE_LOW  (0<<30)
#define LTDC_GCR_VSPOL_ACTIVE_HIGH (1<<30)

#define LTDC_GCR_HSPOL_ACTIVE_LOW  (0<<31)
#define LTDC_GCR_HSPOL_ACTIVE_HIGH (1<<31)

/* --- LTDC_SRCR values ---------------------------------------------------- */

/* Vertical Blanking Reload */
#define LTDC_SRCR_VBR                   (1 << 1)

/* Immediate Reload */
#define LTDC_SRCR_IMR                   (1 << 0)

/* LTDC_BCCR - reload control */
#define LTDC_SRCR_RELOAD_IMR       (1<<0)
#define LTDC_SRCR_RELOAD_VBR       (1<<1)

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

/* LTDC_CDSR - display status register */
#define LTDC_CDSR_VDES             (1<<0)
#define LTDC_CDSR_HDES             (1<<1)
#define LTDC_CDSR_VSYNCS           (1<<2)
#define LTDC_CDSR_HSYNCS           (1<<3)

/* LTDC_LxCR - layer control */
#define LTDC_LxCR_LAYER_ENABLE     (1<<0)
#define LTDC_LxCR_COLKEY_ENABLE    (1<<1)
#define LTDC_LxCR_COLTAB_ENABLE    (1<<4)

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

/* LTDC_LxPFCR - Pixel formats */
#define LTDC_LxPFCR_ARGB8888       (0b000)
#define LTDC_LxPFCR_RGB888         (0b001)
#define LTDC_LxPFCR_RGB565         (0b010)
#define LTDC_LxPFCR_ARGB1555       (0b011)
#define LTDC_LxPFCR_ARGB4444       (0b100)
#define LTDC_LxPFCR_L8             (0b101)
#define LTDC_LxPFCR_AL44           (0b110)
#define LTDC_LxPFCR_AL88           (0b111)

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

/* LTDC_LxBFCR - Blending factors - BF1 */
#define LTDC_LxBFCR_BF1_CONST_ALPHA               (0b100)
#define LTDC_LxBFCR_BF1_PIXEL_ALPHA_x_CONST_ALPHA (0b110)
/* LTDC_LxBFCR - Blending factors - BF2 */
#define LTDC_LxBFCR_BF2_CONST_ALPHA               (0b101)
#define LTDC_LxBFCR_BF2_PIXEL_ALPHA_x_CONST_ALPHA (0b111)

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

/**
 * simple helper macros
 */

/* global */
static inline void ltdc_ctrl_enable(uint32_t ctrl_flags)
{
	LTDC_GCR            |= ctrl_flags;
}

static inline void ltdc_ctrl_disable(uint32_t ctrl_flags)
{
	LTDC_GCR            &= ~(ctrl_flags);
}

static inline void ltdc_reload(uint32_t reload_flags)
{
	LTDC_SRCR            = reload_flags;
}

static inline void ltdc_set_background_color(uint8_t r, uint8_t g, uint8_t b)
{
	LTDC_BCCR            = (((r)&255)<<16) |
			       (((g)&255)<<8) |
			       (((b)&255)<<0);
}

static inline void ltdc_get_current_position(uint16_t *x, uint16_t *y)
{
	uint32_t tmp = LTDC_CPSR;
	*x = tmp >> 16;
	*y = tmp &= 0xFFFF;
}

static inline uint16_t ltdc_get_current_position_x(void)
{
	return LTDC_CPSR >> 16;
}

static inline uint16_t ltdc_get_current_position_y(void)
{
	return LTDC_CPSR & 0xffff;
}

static inline uint32_t ltdc_get_display_status(uint32_t status_flags)
{
	return LTDC_CDSR & status_flags;
}

/* layers */
static inline void ltdc_layer_ctrl_enable(uint32_t layer, uint32_t ctrl_flags)
{
	LTDC_LxCR(layer)    |= ctrl_flags;
}

static inline void ltdc_layer_ctrl_disable(uint32_t layer, uint32_t ctrl_flags)
{
	LTDC_LxCR(layer)    &= ~(ctrl_flags);
}

static inline void ltdc_set_color_key(uint32_t layer,
				      uint8_t r, uint8_t g, uint8_t b)
{
	LTDC_LxCKCR(layer)   = ((((r)&255)<<16) |
				(((g)&255)<<8) |
				(((b)&255)<<0));
}

static inline void ltdc_set_pixel_format(uint32_t layer, uint32_t format)
{
	LTDC_LxPFCR(layer)   = format;
}

static inline void ltdc_set_constant_alpha(uint32_t layer, uint8_t alpha)
{
	LTDC_LxCACR(layer)   = ((alpha)&255);
}

static inline void ltdc_set_default_colors(uint32_t layer,
					   uint8_t a,
					   uint8_t r, uint8_t g, uint8_t b)
{
	LTDC_LxDCCR(layer)   = ((((a)&255)<<24) |
				(((r)&255)<<16) |
				(((g)&255)<<8) |
				(((b)&255)<<0));
}

static inline void ltdc_set_blending_factors(uint32_t layer,
					     uint8_t bf1, uint8_t bf2)
{
	LTDC_LxBFCR(layer)   = ((bf1)<<8) | ((bf2)<<0);
}

static inline void ltdc_set_fbuffer_address(uint32_t layer, uint32_t address)
{
	LTDC_LxCFBAR(layer)  = (uint32_t)address;
}

static inline void ltdc_set_fb_line_length(uint32_t layer,
					   uint16_t len, uint16_t pitch)
{
	LTDC_LxCFBLR(layer)  = ((((pitch)&0x1FFF)<<16) | (((len)&0x1FFF)<<0));
}

static inline void ltdc_set_fb_line_count(uint32_t layer, uint16_t linecount)
{
	LTDC_LxCFBLNR(layer) = (((linecount)&0x3FF)<<0);
}

/**
 * more complicated helper functions
 */
void ltdc_set_tft_sync_timings(
		uint16_t sync_width,    uint16_t sync_height,
		uint16_t h_back_porch,  uint16_t v_back_porch,
		uint16_t active_width,  uint16_t active_height,
		uint16_t h_front_porch, uint16_t v_front_porch
);
void ltdc_setup_windowing(
		uint8_t  layer_number,
		uint16_t h_back_porch,  uint16_t v_back_porch,
		uint16_t active_width,  uint16_t active_height
);



/**
 * Helper function to wait for SRCR reload to complete or so
 */

static inline bool LTDC_SRCR_IS_RELOADING(void)
{
	return (LTDC_SRCR & (LTDC_SRCR_RELOAD_VBR |
			     LTDC_SRCR_RELOAD_IMR)) != 0;
}

/**
 * color conversion helper function
 * (simulate the ltdc color conversion)
 */

static inline uint16_t ltdc_get_rgb888_from_rgb565(uint16_t rgb888)
{
	return ((((rgb888) & 0xF800)   >> (11-8))/31)<<16
	       | ((((rgb888) & 0x07E0) <<  (8-5))/63)<<8
	       | ((((rgb888) & 0x001F) <<  (8-0))/31)<<0;
}


#endif /* LIBOPENCM3_STM32_F4_LTDC_H_ */
