/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Ben Gamari <bgamari@gmail.com>
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

#ifndef LIBOPENCM3_CORTEX_H
#define LIBOPENCM3_CORTEX_H

static inline void cm_enable_interrupts(void)
{
        __asm__("CPSIE I\n");
}

static inline void cm_disable_interrupts(void)
{
        __asm__("CPSID I\n");
}

#endif
