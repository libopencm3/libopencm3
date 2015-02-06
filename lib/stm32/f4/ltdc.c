/** @defgroup ltdc_file LTDC
 *
 * @ingroup STM32F4xx
 *
 * @brief <b>libopencm3 STM32F4xx LTDC</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Oliver Meier <h2obrain@gmail.com>
 *
 * @date 5 December 2014
 *
 * This library supports the LCD controller (LTDC) in the STM32F4
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * For the STM32F4xx, LTDC is described in LCD-TFT Controller (LTDC)
 * section 16 of the STM32F4xx Reference Manual (RM0090,Rev8).
 *
 *
 * LGPL License Terms @ref lgpl_license
 */

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

#include <libopencm3/stm32/f4/ltdc.h>

void ltdc_set_tft_sync_timings(uint16_t sync_width,    uint16_t sync_height,
			       uint16_t h_back_porch,  uint16_t v_back_porch,
			       uint16_t active_width,  uint16_t active_height,
			       uint16_t h_front_porch, uint16_t v_front_porch)
{
	/*assert((active_width <= 0x400) && (active_height <= 0x300));*/

	uint16_t w, h;
	w = sync_width   - 1;
	h = sync_height  - 1;
	/*assert((w&0xfff == w) && (h&0x7ff == h));*/
	LTDC_SSCR = (w << 16) | (h << 0);

	w += h_back_porch;
	h += v_back_porch;
	/*assert((w&0xfff == w) && (h&0x7ff == h));*/
	LTDC_BPCR = (w << 16) | (h << 0);

	w += active_width;
	h += active_height;
	/*assert((w&0xfff == w) && (h&0x7ff == h));*/
	LTDC_AWCR = (w << 16) | (h << 0);

	w += h_front_porch;
	h += v_front_porch;
	/*assert((w&0xfff == w) && (h&0x7ff == h));*/
	LTDC_TWCR = (w << 16) | (h << 0);
}

void ltdc_setup_windowing(uint8_t  layer_number,
			  uint16_t h_back_porch, uint16_t v_back_porch,
			  uint16_t active_width, uint16_t active_height)
{
	active_width  += h_back_porch - 1;
	active_height += v_back_porch - 1;
	/*assert((h_back_porch & 0xfff == h_back_porch) &&
		 (v_back_porch  & 0xfff == v_back_porch) &&
		 (active_width & 0xfff == active_width) &&
		 (active_height & 0xfff == active_height));*/
	LTDC_LxWHPCR(layer_number) = (active_width  << 16) |
				     (h_back_porch << 0);
	LTDC_LxWVPCR(layer_number) = (active_height << 16) |
				     (v_back_porch << 0);
}

