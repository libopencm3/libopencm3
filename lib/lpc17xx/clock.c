/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Silvio Gissi <silvio.gissi@outlook.com>
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
#include <libopencm3/lpc17xx/clock.h>

const clock_scale_t clock_scale[] = {
        {
            /* ( 2 * M * Fin ) / N = 288MHz
                Final div = 3
                Clk = 96MHz */
            .m = 12,
            .n = 1,
            .cclkdiv = 3,
        },
        {
            /* ( 2 * M * Fin ) / N = 360MHz
                Final div = 3
                Clk = 120MHz */
            .m = 15,
            .n = 1,
            .cclkdiv = 3,
        }
};
 void clock_setup(const clock_scale_t *clock)
{
    volatile uint32_t scs;
    volatile uint32_t pll0ctrl;
    /* Check if PLL0 is already connected, if so, disconnect */
    if (CLK_PLL0STAT & (CLK_PLL1STAT_CONNECT)) {
        pll0ctrl = CLK_PLL0CON;
        pll0ctrl &= ~(CLK_PLL1STAT_CONNECT);
        CLK_PLL0CON = pll0ctrl;
    }
    
    /* Check if PLL0 is already ON, if so, disable */
    if (CLK_PLL0STAT & (CLK_PLL0STAT_ENABLE)) {
        pll0ctrl = CLK_PLL0CON;
        pll0ctrl &= ~(CLK_PLL0STAT_ENABLE);
        CLK_PLL0CON = pll0ctrl;
    }

    /* Check if oscillator is enabled, otherwise enable */
    do {
        scs = CLK_SCS;
        scs |= (CLK_SCS_OSCEN);
        CLK_SCS = scs;
    } while ((scs & (CLK_SCS_OSCSTAT)) == 0);

    /* Reset CPU Clock divider */
    CLK_CCLKCFG = 0u;

    /* Select Main Oscillator as primary clock source */
    CLK_CLKSRCSEL = CLK_CLKSRCSEL_MAIN;

    /* Set oscillator frequency to 384 MHz */
    CLK_PLL0CFG = PLL0_CFG_VAL(clock->m, clock->n);

    /* Enable oscillator */
    CLK_PLL0CON = 1;

    /* Enable oscillator */
    pll0ctrl = CLK_PLL0CON;
    pll0ctrl |= (CLK_PLL0STAT_ENABLE);
    CLK_PLL0CON = pll0ctrl;

    /* Kickstart oscillator */
    CLK_PLL0FEED = PLL_KICK0;
    CLK_PLL0FEED = PLL_KICK1;

    /* Set correct divider */
    CLK_CCLKCFG = clock->cclkdiv;

    /* Wait for lock */
    while ((CLK_PLL0STAT & CLK_PLL0STAT_PLOCK) == 0){}

    /* Connect oscillator */ 
    pll0ctrl = CLK_PLL0CON;
    pll0ctrl |= (CLK_PLL1STAT_CONNECT);
    CLK_PLL0CON = pll0ctrl;

}

    
