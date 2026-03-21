/** @addtogroup exti_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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

/** @cond */
#if defined(LIBOPENCM3_EXTI_H)
/** @endcond */
#ifndef LIBOPENCM3_EXTI_COMMON_ALL_H
#define LIBOPENCM3_EXTI_COMMON_ALL_H
/**@{*/

/* EXTI number definitions */
#define EXTI0				(1U << 0U)
#define EXTI1				(1U << 1U)
#define EXTI2				(1U << 2U)
#define EXTI3				(1U << 3U)
#define EXTI4				(1U << 4U)
#define EXTI5				(1U << 5U)
#define EXTI6				(1U << 6U)
#define EXTI7				(1U << 7U)
#define EXTI8				(1U << 8U)
#define EXTI9				(1U << 9U)
#define EXTI10				(1U << 10U)
#define EXTI11				(1U << 11U)
#define EXTI12				(1U << 12U)
#define EXTI13				(1U << 13U)
#define EXTI14				(1U << 14U)
#define EXTI15				(1U << 15U)
#define EXTI16				(1U << 16U)
#define EXTI17				(1U << 17U)
#define EXTI18				(1U << 18U)
#define EXTI19				(1U << 19U)
#define EXTI20				(1U << 20U)
#define EXTI21				(1U << 21U)
#define EXTI22				(1U << 22U)
#define EXTI23				(1U << 23U)
#define EXTI24				(1U << 24U)
#define EXTI25				(1U << 25U)
#define EXTI26				(1U << 26U)
#define EXTI27				(1U << 27U)
#define EXTI28				(1U << 28U)
#define EXTI29				(1U << 29U)
#define EXTI30				(1U << 30U)
#define EXTI31				(1U << 31U)

#define EXTI32				(1U << 0U)
#define EXTI33				(1U << 1U)
#define EXTI34				(1U << 2U)
#define EXTI35				(1U << 3U)
#define EXTI36				(1U << 4U)
#define EXTI37				(1U << 5U)

/* Trigger types */
enum exti_trigger_type {
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH,
	EXTI_TRIGGER_NONE,
};

BEGIN_DECLS

void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig);
void exti_enable_request(uint32_t extis);
void exti_disable_request(uint32_t extis);
void exti_reset_request(uint32_t extis);
void exti_select_source(uint32_t exti, uint32_t gpioport);
uint32_t exti_get_flag_status(uint32_t exti);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "exti_common_all.h should not be included directly, only via exti.h"
#endif
/** @endcond */
