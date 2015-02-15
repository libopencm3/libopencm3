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
#define LTDC_LxCR(x)               (MMIO32(LTDC_BASE + 0x84 + 0x80 * (x - 1)))
#define LTDC_LxWHPCR(x)            (MMIO32(LTDC_BASE + 0x88 + 0x80 * (x - 1)))
#define LTDC_LxWVPCR(x)            (MMIO32(LTDC_BASE + 0x8C + 0x80 * (x - 1)))
#define LTDC_LxCKCR(x)             (MMIO32(LTDC_BASE + 0x90 + 0x80 * (x - 1)))
#define LTDC_LxPFCR(x)             (MMIO32(LTDC_BASE + 0x94 + 0x80 * (x - 1)))
#define LTDC_LxCACR(x)             (MMIO32(LTDC_BASE + 0x98 + 0x80 * (x - 1)))
#define LTDC_LxDCCR(x)             (MMIO32(LTDC_BASE + 0x9C + 0x80 * (x - 1)))
#define LTDC_LxBFCR(x)             (MMIO32(LTDC_BASE + 0xA0 + 0x80 * (x - 1)))
#define LTDC_LxCFBAR(x)            (MMIO32(LTDC_BASE + 0xAC + 0x80 * (x - 1)))
#define LTDC_LxCFBLR(x)            (MMIO32(LTDC_BASE + 0xB0 + 0x80 * (x - 1)))
#define LTDC_LxCFBLNR(x)           (MMIO32(LTDC_BASE + 0xB4 + 0x80 * (x - 1)))
#define LTDC_LxCLUTWR(x)           (MMIO32(LTDC_BASE + 0xC4 + 0x80 * (x - 1)))

#define LTDC_LAYER_1 1
#define LTDC_LAYER_2 2


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

/* LTDC_BCCR - reload control */
#define LTDC_SRCR_RELOAD_IMR       (1<<0)
#define LTDC_SRCR_RELOAD_VBR       (1<<1)

/* LTDC_CDSR - display status register */
#define LTDC_CDSR_VDES             (1<<0)
#define LTDC_CDSR_HDES             (1<<1)
#define LTDC_CDSR_VSYNCS           (1<<2)
#define LTDC_CDSR_HSYNCS           (1<<3)

/* LTDC_LxCR - layer control */
#define LTDC_LxCR_LAYER_ENABLE     (1<<0)
#define LTDC_LxCR_COLKEY_ENABLE    (1<<1)
#define LTDC_LxCR_COLTAB_ENABLE    (1<<4)

/* LTDC_LxPFCR - Pixel formats */
#define LTDC_LxPFCR_ARGB8888       (0b000)
#define LTDC_LxPFCR_RGB888         (0b001)
#define LTDC_LxPFCR_RGB565         (0b010)
#define LTDC_LxPFCR_ARGB1555       (0b011)
#define LTDC_LxPFCR_ARGB4444       (0b100)
#define LTDC_LxPFCR_L8             (0b101)
#define LTDC_LxPFCR_AL44           (0b110)
#define LTDC_LxPFCR_AL88           (0b111)

/* LTDC_LxBFCR - Blending factors - BF1 */
#define LTDC_LxBFCR_BF1_CONST_ALPHA               (0b100)
#define LTDC_LxBFCR_BF1_PIXEL_ALPHA_x_CONST_ALPHA (0b110)
/* LTDC_LxBFCR - Blending factors - BF2 */
#define LTDC_LxBFCR_BF2_CONST_ALPHA               (0b101)
#define LTDC_LxBFCR_BF2_PIXEL_ALPHA_x_CONST_ALPHA (0b111)

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
