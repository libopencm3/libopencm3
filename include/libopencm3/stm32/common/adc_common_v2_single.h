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

/*
 * The adc v2 peripheral optionally supports per channel sampling, injected
 * sequences, watchdogs, offsets and other "advanced" features, and is
 * found on the (so far) F3 and L4,
 * or only a much "simpler" version as found on (so far) f0 and l0.
 */

/** @cond */
#ifdef LIBOPENCM3_ADC_H
/** @endcond */
#ifndef LIBOPENCM3_ADC_COMMON_V2_SINGLE_H
#define LIBOPENCM3_ADC_COMMON_V2_SINGLE_H

/* ----- ADC registers  -----------------------------------------------------*/
/* Channel Select Register */
#define ADC_CHSELR(adc)		MMIO32((adc) + 0x28)

/* ----- ADC registers values -----------------------------------------------*/
/* ADC_CFGR1 values */
#define ADC_CFGR1_WAIT		(1<<14)
/* EXTSEL[2:0]: External trigger selection for regular group */
#define ADC_CFGR1_EXTSEL_SHIFT		6
#define ADC_CFGR1_EXTSEL		(0x7 << ADC_CFGR1_EXTSEL_SHIFT)
#define ADC_CFGR1_EXTSEL_VAL(x)		((x) << ADC_CFGR1_EXTSEL_SHIFT)

#define ADC_CFGR1_SCANDIR		(1 << 2)

/* ADC_CHSELR Values --------------------------------------------------------*/

#define ADC_CHSELR_CHSEL(x)		(1 << (x))


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

END_DECLS

#endif
/** @cond */
#endif
/** @endcond */
/**@}*/
