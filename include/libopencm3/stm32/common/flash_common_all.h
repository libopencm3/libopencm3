/** @addtogroup flash_defines
 *
 */
/*
 * This file is part of the libopencm3 project.
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

#pragma once

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

/**
 * This buffer is used for instruction fetches and is enabled by default after
 * reset.
 * 
 * Note carefully the clock restrictions under which the prefetch buffer may be
 * enabled or disabled. Changes are normally made while the clock is running in
 * the power-on low frequency mode before being set to a higher speed mode.
 *
 * See the reference manual for details.
 */
void flash_prefetch_enable(void);

/**
 * Note carefully the clock restrictions under which the prefetch buffer may be
 * set to disabled. See the reference manual for details.
 */
void flash_prefetch_disable(void);


void flash_set_ws(uint32_t ws);

END_DECLS