/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/lpc17xx/exti.h>

void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig)
{
    EXTPOLAR &= ~(1<<extis);
    EXTPOLAR |= (trig == EXTI_TRIGGER_RISING  || trig == EXTI_TRIGGER_HIGH) ? (1 << extis) : 0;

    EXTMODE &= ~(1<<extis);
    EXTMODE |= (trig == EXTI_TRIGGER_RISING  || trig == EXTI_TRIGGER_FALLING) ? (1 << extis) : 0;
}

void exti_clear_flag(uint32_t extis)
{
    EXTINT = (1 << extis);
}

