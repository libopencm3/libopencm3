/** @defgroup gpio_file GPIO

@ingroup LPC17xx

@brief <b>libopencm3 LPC17xx General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/lpc17xx/gpio.h>
#include <libopencm3/lpc17xx/pinconn.h>

void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	GPIO_SET(gpioport) = gpios;
}

void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	GPIO_CLR(gpioport) = gpios;
}

void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint32_t gpios)
{
    uint8_t shift = 0;
    do
    {
        if(gpios & 1)
        {
            switch(gpioport)
            {
                case GPIO0:     if(shift < 16)
                                          { 
                                            PINSEL0 &= ~(PINSEL_MASK << (shift * 2));
                                            PINSEL0 |= alt_func_num << (shift * 2);
                                         }
                                         else 
                                         {
                                            PINSEL1 &= ~(PINSEL_MASK << ((shift - 16) * 2));
                                            PINSEL1 |= alt_func_num << ((shift - 16) * 2);
                                         }
                    break;
                case GPIO1:     if(shift < 16)
                                          { 
                                            PINSEL2 &= ~(PINSEL_MASK << (shift * 2));
                                            PINSEL2 |= alt_func_num << (shift * 2);
                                         }
                                         else 
                                         {
                                            PINSEL3 &= ~(PINSEL_MASK << ((shift - 16) * 2));
                                            PINSEL3 |= alt_func_num << ((shift - 16) * 2);
                                         }
                    break;
                case GPIO2:     PINSEL4 &= ~(PINSEL_MASK << (shift * 2));
                                          PINSEL4 |= alt_func_num << (shift * 2);
                    break;
                case GPIO3:     PINSEL7  &= ~(PINSEL_MASK << ((shift -16) * 2));
                                          PINSEL7 |= alt_func_num << ((shift -16) * 2);
                    break;
                case GPIO4:    PINSEL9  &= ~(PINSEL_MASK << ((shift -16) * 2)); 
                                         PINSEL9 |= alt_func_num << ((shift -16) * 2);
                    break;
            }
        }
        gpios >>= 1;
        shift++;
    }while(gpios);
}

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint32_t gpios)
{
    uint8_t shift = 0;
    do
    {
        if(gpios & 1)
        {
            switch(gpioport)
            {
                case GPIO0:     if(shift < 16) 
                                         {
                                            PINMODE0 &= ~(PINMODE_MASK << (shift * 2));
                                            PINMODE0 = pull_up_down << (shift * 2);
                                         }
                                         else 
                                         {
                                            PINMODE1 &= ~(PINMODE_MASK << ((shift - 16) * 2));
                                            PINMODE1 = pull_up_down << ((shift - 16) * 2);
                                         }
                                         if(mode == GPIO_MODE_INPUT) GPIO0_DIR &= ~(1<<shift);
                                         else GPIO0_DIR |= (1<<shift);
                    break;
                case GPIO1:     if(shift < 16) 
                                         {
                                            PINMODE2 &= ~(PINMODE_MASK << (shift * 2));
                                            PINMODE2 = pull_up_down << (shift * 2);
                                         }
                                         else 
                                         {
                                            PINMODE3 &= ~(PINMODE_MASK << ((shift - 16) * 2));
                                            PINMODE3 = pull_up_down << ((shift - 16) * 2);
                                         }
                                         if(mode == GPIO_MODE_INPUT) GPIO1_DIR &= ~(1<<shift);
                                         else GPIO1_DIR |= (1<<shift);
                    break;
                case GPIO2:   PINMODE4 &= ~(PINMODE_MASK << (shift * 2));
                                        PINMODE4 = pull_up_down << (shift * 2);
                                        if(mode == GPIO_MODE_INPUT) GPIO2_DIR &= ~(1<<shift);
                                        else GPIO2_DIR |= (1<<shift);
                    break;
                case GPIO3:   PINMODE7 &= ~(PINMODE_MASK << ((shift - 16) * 2));
                                        PINMODE7 = pull_up_down << ((shift -16) * 2);
                                        if(mode == GPIO_MODE_INPUT) GPIO3_DIR &= ~(1<<shift);
                                        else GPIO3_DIR |= (1<<shift);
                    break;
                case GPIO4:   PINMODE9 &= ~(PINMODE_MASK << ((shift - 16) * 2)); 
                                        PINMODE9 = pull_up_down << ((shift -16) * 2);
                                        if(mode == GPIO_MODE_INPUT) GPIO4_DIR &= ~(1<<shift);
                                        else GPIO4_DIR |= (1<<shift);
                    break;
            }
        }
        gpios >>= 1;
        shift++;
    }while(gpios);
}

uint16_t gpio_get(uint32_t gpioport, uint32_t gpios)
{
    return (GPIO_PIN(gpioport) & gpios);
}

