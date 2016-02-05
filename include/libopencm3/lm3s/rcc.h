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

/* --- RCC registers ------------------------------------------------------- */

#define RCC_RIS             MMIO32(0x400FE050)
#define RCC_CR              MMIO32(0x400FE060)
#define RCC2_CR             MMIO32(0x400FE070)

/* RCC1 bits */
#define RCC_SYSDIV_MASK      (0x0F << 23)
#define RCC_SYSDIV_12_5MHZ   (0x0F << 23)
#define RCC_SYSDIV_50MHZ     (0x03 << 23)

#define RCC_USESYSDIV (1 << 22)
#define RCC_USEPWMDIV (1 << 20)

#define RCC_PWMDIV_MASK (0x07 << 17)
#define RCC_PWMDIV_64   (0x07 << 17)

#define RCC_OFF       (1 << 13)
#define RCC_BYPASS    (1 << 11)

#define RCC_XTAL_MASK (0x0F << 6)    
/* For other values, see datasheet section 23.2.2 - table 23-9  */
#define RCC_XTAL_6MHZ_RESET     (0x0B << 6)
#define RCC_XTAL_8MHZ_400MHZ    (0x0D << 6)


#define RCC_OSCRC_MASK   (0x03 << 4)
#define RCC_OSCRC_MOSC   (0x00 << 4)
#define RCC_OSCRC_IOSC   (0x01 << 4)
#define RCC_OSCRC_IOSC_Q (0x02 << 4)
#define RCC_OSCRC_30KHZ  (0x03 << 4)

#define RCC_IOSCDIS   (1 << 1)
#define RCC_MOSCDIS   (1 << 0)

/* RCC2 bits */
#define RCC2_USERRCC2       (1 << 31)
#define RCC2_SYSDIV2_MASK	0x7f
#define RCC2_SYSDIV2_SHIFT	23

#define RCC2_OFF       (1 << 13)
#define RCC2_BYPASS    (1 << 11)

/* RIS bit */
#define RIS_PLLLRIS    (1 << 6)


/* From Datasheet description for reset values 
 * Section 6.4 - Register Descriptions
 */

/* Register 8: RCC
 * Type R/W, reset 0x078E.3AD1
 */
#define RCC_RESET_VALUE   (0x078E3AD1)

/* Register 10: RCC2
 * Type R/W, reset 0x0780.2810
 */
#define RCC2_RESET_VALUE  (0x07802810)

BEGIN_DECLS

int rcc_clock_setup_in_xtal_8mhz_out_50mhz(void);

END_DECLS

#endif
