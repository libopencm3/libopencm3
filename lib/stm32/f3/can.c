/** @defgroup can_file CAN

@ingroup STM32F_files

@brief <b>libopencm3 STM32Fxxx CAN</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Piotr Esden-Tempski <piotr@esden.net>

@date 12 November 2012

Devices can have up to two CAN peripherals. The peripherals support up to 1MBit
transmission rate. The peripheral has several filters for incoming messages that
can be distributed between two FIFOs and three transmit mailboxes.

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

#include <libopencm3/stm32/can.h>

#if defined(STM32F3)
#   include <libopencm3/stm32/f3/rcc.h>
#else
#   error "stm32 family not defined."
#endif

/*---------------------------------------------------------------------------*/
/** @brief CAN Reset

The CAN peripheral and all its associated configuration registers are placed in
the reset condition. The reset is effective via the RCC peripheral reset
system.

@param[in] canport Unsigned int32. CAN block register address base @ref
can_reg_base.
 */
void can_reset(uint32_t canport)
{
    (void)canport;
    rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_CANRST);
    rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_CANRST);
}
