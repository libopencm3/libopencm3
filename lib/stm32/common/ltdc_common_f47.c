/** @defgroup ltdc_file LTDC peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Oliver Meier <h2obrain@gmail.com>
 *
 * @date 5 December 2014
 *
 * This library supports the LCD controller (LTDC) in the STM32F4xx and
 * STM32F7xx series of ARM Cortex Microcontrollers by ST Microelectronics.
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

/**@{*/

#include <libopencm3/stm32/common/ltdc_common_f47.h>

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

/*---------------------------------------------------------------------------*/
/** @brief LTDC Windowing Setup
@param[in] layer_number unsigned int8. @ref ltdc_layer_num
@param[in] h_back_porch unsigned int16. Horizontal Back Porch
@param[in] v_back_porch unsigned int16. Vertical Back Porch
@param[in] h_sync unsigned int16. Horizontal Sync
@param[in] v_sync unsigned int16. Vertical Sync
@param[in] width unsigned int16. Width of the screen (e.g. LCD is 320x240, width
would be 320)
@param[in] height unsigned int16. Height of the screen (e.g. LCD is 320x240,
height would be 240)
*/
void ltdc_setup_windowing(uint8_t layer_number, uint16_t h_back_porch,
			uint16_t v_back_porch, uint16_t h_sync,
			uint16_t v_sync, uint16_t width, uint16_t height) {
	LTDC_LxWHPCR(layer_number) = (h_back_porch + width + h_sync - 1) << LTDC_LxWHPCR_WHSPPOS_SHIFT |
		(h_sync + h_back_porch) << LTDC_LxWHPCR_WHSTPOS_SHIFT;
	LTDC_LxWVPCR(layer_number) = (v_back_porch + height + v_sync - 1) << LTDC_LxWVPCR_WVSPPOS_SHIFT |
		(v_back_porch + v_sync) << LTDC_LxWVPCR_WVSTPOS_SHIFT;
}

/**@}*/

