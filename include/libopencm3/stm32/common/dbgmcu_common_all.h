/** @addtogroup dbgmcu_defines

@author @htmlonly &copy; @endhtmlonly
2011 Gareth McMullin <gareth@blacksphere.co.nz>

@author @htmlonly &copy; @endhtmlonly 2021 Alexey Ryabov <6006l1k@gmail.com>
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2021 Alexey Ryabov <6006l1k@gmail.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DBGMCU.H
The order of header inclusion is important. dbgmcu.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_DBGMCU_H
/** @endcond */

#ifndef LIBOPENCM3_DBGMCU_COMMON_ALL_H
#define LIBOPENCM3_DBGMCU_COMMON_ALL_H

/* --- DBGMCU registers ---------------------------------------------------- */

/**@defgroup dbgmcu_registers Debug MCU Registers
 @{*/

/** Debug MCU IDCODE register */
#define DBGMCU_IDCODE			MMIO32(DBGMCU_BASE + 0x00)

/** Debug MCU configuration register
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_CR			MMIO32(DBGMCU_BASE + 0x04)
/**@}*/

/* --- DBGMCU_IDCODE values ------------------------------------------------ */

/** @defgroup dbgmcu_idcode_values MCU device ID code (DBGMCU_IDCODE) values
 * @{*/
#define DBGMCU_IDCODE_DEV_ID_MASK	0x00000fff
#define DBGMCU_IDCODE_REV_ID_MASK	0xffff0000
/**@}*/

/* --- DBGMCU_CR values ----------------------------------------------------- */

/** @defgroup dbgmcu_cr_values Debug MCU configuration register (DBGMCU_CR) values
 * @{
 * @}*/

#endif

/** @cond */
#endif
/** @endcond */

/**@}*/
