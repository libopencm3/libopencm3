/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@ŧweak.net.au>
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

#include <libopencm3/stm32/desig.h>

u16 desig_get_flash_size(void)
{
    return DESIG_FLASH_SIZE;
}

void desig_get_unique_id(u32 result[])
{
    // Could also just return a pointer to the start? read it as they wish?
    u16 bits15_0 = DESIG_UID_15_0;
    u32 bits31_16 = DESIG_UID_31_16;
    u32 bits63_32 = DESIG_UID_63_32;
    u32 bits95_64 = DESIG_UID_95_64;
    result[0] = bits95_64;
    result[1] = bits63_32;
    result[2] = bits31_16 << 16 | bits15_0;
}
