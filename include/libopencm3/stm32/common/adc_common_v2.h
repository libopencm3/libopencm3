/** @addtogroup adc_defines

@author @htmlonly &copy; @endhtmlonly 2015 Karl Palsson <karlp@tweak.net.au>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA ADC.H
The order of header inclusion is important. adc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_ADC_H
/** @endcond */
#ifndef LIBOPENCM3_ADC_COMMON_V2_H
#define LIBOPENCM3_ADC_COMMON_V2_H


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void adc_power_on_async(uint32_t adc);
void adc_power_on(uint32_t adc);
bool adc_is_power_on(uint32_t adc);
void adc_power_off_async(uint32_t adc);
void adc_power_off(uint32_t adc);
bool adc_is_power_off(uint32_t adc);

END_DECLS

#endif
#endif	/* LIBOPENCM3_ADC_H */
/**@}*/
