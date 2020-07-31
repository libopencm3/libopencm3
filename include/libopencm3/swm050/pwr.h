/** @defgroup pwr_defines Power/Sleep Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 Power/Sleep API</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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
#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H
#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

BEGIN_DECLS

void pwr_sleep(void);

END_DECLS

#endif
/**@}*/
