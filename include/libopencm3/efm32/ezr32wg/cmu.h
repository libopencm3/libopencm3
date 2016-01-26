/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Bob Miller <kbob@jogger-egg.com>
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

#ifndef LIBOPENCM3_EFM32_EZR32WG_CMU_H
#define LIBOPENCM3_EFM32_EZR32WG_CMU_H

#include <libopencm3/efm32/common/cmu_common.h>

/* EZR32WG refers to USART0 as USART0RF
 * because it is connected to the radio MCU.
 */

#define CMU_HFPERCLKEN0_USARTRF0 CMU_HFPERCLKEN0_USART0
#define CMU_USARTRF0             CMU_USART0

#endif
