/** @defgroup rcc_file RCC Controller

@brief <b>LM3S RCC Controller</b>

@ingroup LM3Sxx

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2011
Daniele Lacamera <root at danielinux dot net>

@date 21 November 2015

LGPL License Terms @ref lgpl_license
*/
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

#include "stdint.h"
#include "libopencm3/lm3s/rcc.h"

extern void __dmb(void);


/* PLL/Systick Configured values */
#define QEMU_SYSDIV_VAL        (3)
#define QEMU_PWMDIV_VAL        (7)
#define QEMU_XTAL_VAL          (14)

int rcc_lm3s_init(uint32_t sys_div, uint32_t pwm_div, uint32_t xtal)
{
    uint32_t rcc = RCC_DEFAULT_VALUE;
    uint32_t rcc2 = RCC2_DEFAULT_VALUE;

    /* Initials: set default values */

    RCC_CR = rcc;
    RCC2_CR = rcc2;


    /* Stage 1: Reset Oscillators and select configured values */
    rcc = (sys_div << RCC_SYSDIV_BITPOS) | (pwm_div << RCC_PWMDIV_BITPOS) | 
        (xtal << RCC_XTAL_BITPOS) | RCC_USEPWMDIV;

    rcc2 = (sys_div << RCC2_SYSDIV_BITPOS); 

    rcc  |= RCC_BYPASS | RCC_OFF;
    rcc2 |= RCC2_BYPASS | RCC2_OFF;

    RCC_CR = rcc;
    RCC2_CR = rcc2;
    __dmb();

    /* Stage 2: Power up oscillators */
    rcc  &= ~RCC_OFF;
    rcc2 &= ~RCC2_OFF;
    RCC_CR = rcc;
    RCC2_CR = rcc2;
    __dmb();

    /* Stage 3: Set USESYSDIV */
    rcc |= RCC_BYPASS | RCC_USESYSDIV;
    RCC_CR = rcc;
    __dmb();

    /* Stage 4: Wait for PLL raw interrupt */
    while ((RCC_RIS & RIS_PLLLRIS) == 0)
        ;

    /* Stage 5: Disable bypass */
    rcc  &= ~RCC_BYPASS;
    rcc2 &= ~RCC2_BYPASS;
    RCC_CR = rcc;
    RCC2_CR = rcc2;
    __dmb();
    return 0;
}

int rcc_qemu_init(void)
{
    const uint32_t SYS_CLOCK = 50000000;
    int ret;
    ret = rcc_lm3s_init(QEMU_SYSDIV_VAL, QEMU_PWMDIV_VAL, QEMU_XTAL_VAL);
    return ret;
}

