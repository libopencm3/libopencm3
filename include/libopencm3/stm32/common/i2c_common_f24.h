/** @addtogroup i2c_defines

@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA I2C.H
The order of header inclusion is important. i2c.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_I2C_H
/** @endcond */
#ifndef LIBOPENCM3_I2C_COMMON_F24_H
#define LIBOPENCM3_I2C_COMMON_F24_H

#include <libopencm3/stm32/common/i2c_common_all.h>

/**@{*/

#define I2C3				I2C3_BASE

/**@}*/

#endif
/** @cond */
#else
#warning "i2c_common_f24.h should not be included explicitly, only via i2c.h"
#endif
/** @endcond */

