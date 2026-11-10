/** @addtogroup exti_file EXTI peripheral API
 * @ingroup peripheral_apis
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
 * Copyright (C) 2026 Rachel Mant <git@dragonmux.network>
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
 * This provides the code for the "next gen" EXTI block provided in F2/F4/F7/L1
 * devices.  (differences only in the source selection)
 */
/**@{*/

#include <stddef.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>

#if defined(EXTI_EXTICR)
	#define EXTICR_SELECTION_FIELDSIZE	EXTI_EXTICR_FIELDSIZE
	#define EXTICR_SELECTION_REG(x)	EXTI_EXTICR(x)
#elif defined(AFIO_EXTICR)
	#define EXTICR_SELECTION_FIELDSIZE	AFIO_EXTICR_FIELDSIZE
	#define EXTICR_SELECTION_REG(x)	AFIO_EXTICR(x)
#else
	#include <libopencm3/stm32/syscfg.h>
	#define EXTICR_SELECTION_FIELDSIZE	SYSCFG_EXTICR_FIELDSIZE
	#define EXTICR_SELECTION_REG(x)	SYSCFG_EXTICR(x)
#endif

void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig)
{
	switch (trig) {
	case EXTI_TRIGGER_RISING:
		EXTI_RTSR |= extis;
		EXTI_FTSR &= ~extis;
		break;
	case EXTI_TRIGGER_FALLING:
		EXTI_RTSR &= ~extis;
		EXTI_FTSR |= extis;
		break;
	case EXTI_TRIGGER_BOTH:
		EXTI_RTSR |= extis;
		EXTI_FTSR |= extis;
		break;
	}
}

void exti_enable_request(uint32_t extis)
{
	/* Enable interrupts. */
	EXTI_IMR |= extis;

	/* Enable events. */
	EXTI_EMR |= extis;
}

void exti_disable_request(uint32_t extis)
{
	/* Disable interrupts. */
	EXTI_IMR &= ~extis;

	/* Disable events. */
	EXTI_EMR &= ~extis;
}

/*
 * Reset the interrupt request by writing a 1 to the corresponding
 * pending bit register.
 */
void exti_reset_request(uint32_t extis)
{
#if defined(EXTI_RPR1) && defined(EXTI_FPR1)
	EXTI_RPR1 = extis;
	EXTI_FPR1 = extis;
#else
	EXTI_PR = extis;
#endif
}

/*
 * Check the flag of a given EXTI interrupt.
 * */
uint32_t exti_get_flag_status(uint32_t exti)
{
#if defined(EXTI_RPR1) && defined(EXTI_FPR1)
	return (EXTI_RPR1 & exti) | (EXTI_FPR1 & exti);
#else
	return EXTI_PR & exti;
#endif
}

/*
 * Remap an external interrupt line to the corresponding pin on the
 * specified GPIO port.
 *
 */
void exti_select_source(uint32_t exti, enum exti_gpioport_source gpioport)
{
    uint8_t line, shift = 0;
    uint32_t mask = 0, reg = 0;
    for(line = 0; line < 16; ++line){
        if (!((1 << line) & exti)){
            continue;
        }
        shift = (EXTICR_SELECTION_FIELDSIZE * (line & 3));
        mask = ((1 << EXTICR_SELECTION_FIELDSIZE) - 1) << shift;
        reg = line >> 2;
        EXTICR_SELECTION_REG(reg) = (EXTICR_SELECTION_REG(reg) & ~mask) | (gpioport << shift);
    };

}
/**@}*/

