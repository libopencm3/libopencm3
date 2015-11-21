/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the LM3S Reset and Clock
 * Control</b>
 *
 * @ingroup LM3S_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Daniele Lacamera \<root at danielinux dot net\>
 *
 * @date 21 November 2015
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2015 Daniele Lacamera <root@danielinux.net>
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

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H
#include <libopencm3/cm3/common.h>

/* Interface required types */

enum rcc_periph_clken { CLK_ENA_E };
enum rcc_periph_rst { CLK_RST_E };

#include <libopencm3/stm32/common/rcc_common_all.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_RIS             MMIO32(0x400FE050)
#define RCC_CR			    MMIO32(0x400FE060)
#define RCC2_CR				MMIO32(0x400FE070)

#define RCC_DEFAULT_VALUE   (0x078E3AD1)
#define RCC2_DEFAULT_VALUE  (0x07802810)

/* RCC1 bits */
#define RCC_SYSDIV    (1 << 23)
#define RCC_SYSDIV_BITPOS  (23)

#define RCC_USESYSDIV (1 << 22)
#define RCC_USEPWMDIV (1 << 20)

#define RCC_PWMDIV    (1 << 17)
#define RCC_PWMDIV_BITPOS  (17)

#define RCC_OFF       (1 << 13)
#define RCC_BYPASS    (1 << 11)

#define RCC_XTAL      (1 << 6)
#define RCC_XTAL_BITPOS    (6)

#define RCC_IOSCDIS   (1 << 1)

/* RCC2 bits */
#define RCC2_USERRCC2  (1 << 31)
#define RCC2_SYSDIV    (1 << 23)
#define RCC2_SYSDIV_BITPOS ( 23)
#define RCC2_OFF       (1 << 13)
#define RCC2_BYPASS    (1 << 11)

/* RIS bit */
#define RIS_PLLLRIS    (1 << 6)


BEGIN_DECLS

int rcc_lm3s_init(uint32_t sys_div, uint32_t pwm_div, uint32_t xtal);
int rcc_qemu_init(void);

END_DECLS

#endif
