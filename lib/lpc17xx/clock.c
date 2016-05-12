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
            /* ( 2 * M * Fin ) / N = 200MHz
                Final div = 2
                Clk = 96MHz */
            .m = 25,
            .n = 3,
            .cclkdiv = 2,
        },
        {
            /* ( 2 * M * Fin ) / N = 240MHz
                Final div = 2
                Clk = 120MHz */
            .m = 30,
            .n = 3,
            .cclkdiv = 2,
        }
};
 void clock_setup(const clock_scale_t *clock)
{
     /* Enable the external clock */
     CLK_SCS |= CLK_SCS_OSCEN;                
     while((CLK_SCS & CLK_SCS_OSCSTAT) == 0);
     /* Select external oscilator */
     CLK_CLKSRCSEL = CLK_CLKSRCSEL_MAIN;   
     
     CLK_PLL0CFG = PLL0_CFG_VAL(clock->m, clock->n);
     /*Feed*/
     CLK_PLL0FEED=PLL_KICK0; 
     CLK_PLL0FEED=PLL_KICK1;
     /*PLL0 Enable */
     CLK_PLL0CON = CLK_PLLCON_ENABLE;
     /*Feed*/
     CLK_PLL0FEED=PLL_KICK0; 
     CLK_PLL0FEED=PLL_KICK1;
     /* Divide by 3 */
     CLK_CCLKCFG = clock->cclkdiv;
     /* wait until locked */
     while (!(CLK_PLL0STAT & CLK_PLL0STAT_PLOCK));
     /* see flash accelerator - TBD*/
     /*_FLASHCFG = (_FLASHCFG & 0xFFF) | (4<<12);*/
     /* PLL0 connect */
     CLK_PLL0CON |= CLK_PLLCON_CONNECT;
     /*Feed*/
     CLK_PLL0FEED=PLL_KICK0; 
     CLK_PLL0FEED=PLL_KICK1;
     /* PLL0 operational */
}

    
