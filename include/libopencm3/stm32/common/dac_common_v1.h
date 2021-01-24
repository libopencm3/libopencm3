/** @addtogroup dac_defines

@author @htmlonly &copy; @endhtmlonly 2020
Ben Brewer <ben.brewer@codethink.co.uk>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Ben Brewer <ben.brewer@codethink.co.uk>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DAC.H
The order of header inclusion is important. dac.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_DAC_H
/** @endcond */
#ifndef LIBOPENCM3_DAC_COMMON_V1_H
#define LIBOPENCM3_DAC_COMMON_V1_H

#include <libopencm3/stm32/common/dac_common_all.h>

/**@addtogroup dac_cr_values
 * @{
 */

/** TSEL2[2:0]: DAC channel2 trigger selection */
#define DAC_CR_TSEL2_SHIFT		19
/** @defgroup dac_trig2_sel DAC Channel 2 Trigger Source Selection
@ingroup dac_defines

@li T6: Timer 6 TRGO event
@li T3: Timer 3 TRGO event
@li T8: Timer 8 TRGO event
@li T7: Timer 7 TRGO event
@li T5: Timer 5 TRGO event
@li T15: Timer 15 TRGO event
@li T2: Timer 2 TRGO event
@li T4: Timer 4 TRGO event
@li E9: External line9
@li SW: Software trigger

@note: Refer to the timer documentation for details of the TRGO event.
@note: T3 replaced by T8 and T5 replaced by T15 in some devices.
@note: this is <b>not</b> valid for the STM32L1 family.
@note: only used if bit TEN2 is set (DAC channel 2 trigger enabled)
@{*/
#define DAC_CR_TSEL2_T6			(0x0 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T3			(0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T8			(0x1 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T7			(0x2 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T5			(0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T15		(0x3 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T2			(0x4 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_T4			(0x5 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_E9			(0x6 << DAC_CR_TSEL2_SHIFT)
#define DAC_CR_TSEL2_SW			(0x7 << DAC_CR_TSEL2_SHIFT)
/**@}*/

/* TEN2: DAC channel2 trigger enable */
#define DAC_CR_TEN2			(1 << 18)

/* BOFF2: DAC channel2 output buffer disable */
#define DAC_CR_BOFF2			(1 << 17)

/* TSEL1[2:0]: DAC channel1 trigger selection */
#define DAC_CR_TSEL1_SHIFT		3
/** @defgroup dac_trig1_sel DAC Channel 1 Trigger Source Selection
@ingroup dac_defines

@li T6: Timer 6 TRGO event
@li T3: Timer 3 TRGO event
@li T8: Timer 8 TRGO event
@li T7: Timer 7 TRGO event
@li T5: Timer 5 TRGO event
@li T15: Timer 15 TRGO event
@li T2: Timer 2 TRGO event
@li T4: Timer 4 TRGO event
@li E9: External line 9
@li SW: Software trigger

@note: Refer to the timer documentation for details of the TRGO event.
@note: T3 replaced by T8 and T5 replaced by T15 in some devices.
@note: this is <b>not</b> valid for the STM32L1 family.
@note: only used if bit TEN1 is set (DAC channel 1 trigger enabled).
@{*/
#define DAC_CR_TSEL1_T6			(0x0 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T3			(0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T8			(0x1 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T7			(0x2 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T5			(0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T15		(0x3 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T2			(0x4 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_T4			(0x5 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_E9			(0x6 << DAC_CR_TSEL1_SHIFT)
#define DAC_CR_TSEL1_SW			(0x7 << DAC_CR_TSEL1_SHIFT)
/**@}*/

/* TEN1: DAC channel1 trigger enable */
#define DAC_CR_TEN1			(1 << 2)

/* BOFF1: DAC channel1 output buffer disable */
#define DAC_CR_BOFF1			(1 << 1)

/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

END_DECLS

#endif
/** @cond */
#else
#warning "dac_common_v1.h should not be included explicitly, only via dac.h"
#endif
/** @endcond */

/**@}*/

