/** @defgroup ethernet_mac_defines MAC Generic Defines
 *
 * @brief <b>Defined Constants and Types for the Ethernet MAC</b>
 *
 * @ingroup ETH
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 1 September 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#if defined(STM32F1)
#       include <libopencm3/ethernet/mac_stm32fxx7.h>
#elif defined(STM32F4)
#       include <libopencm3/ethernet/mac_stm32fxx7.h>
#else
#       error "stm32 family not defined."
#endif

/**@}*/


