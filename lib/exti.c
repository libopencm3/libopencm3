/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopenstm32/exti.h>
#include <libopenstm32/gpio.h>

void exti_set_trigger(u32 extis, exti_trigger_type trig)
{
  switch(trig)
  {
    case EXTI_TRIGGER_RISING: 
      EXTI_RTSR |= extis;
      EXTI_FTSR &= ~extis;
      break;
    case EXTI_TRIGGER_FALLING:
      EXTI_RTSR &= ~extis;
      EXTI_FTSR |= extis;
      break;
    case EXTI_TRIGGER_BOTH:
      EXTI_RTSR |= extis;
      EXTI_FTSR |= extis;
      break;
  }
}

void exti_enable_request(u32 extis)
{
 //enable interrupts
 EXTI_IMR |= extis;
 //enable events
 EXTI_EMR |= extis;
}

void exti_disable_request(u32 extis)
{
 //disable interrupts
 EXTI_IMR &= ~extis;
 //disable events
 EXTI_EMR &= ~extis;
} 

/*
Reset the interrupt request by writing a 1 to the corresponding 
pending bit register 
*/
void exti_reset_request(u32 extis)
{
  EXTI_PR |= extis;  
}


/*Remap an external interrupt line to the corresponding
pin on the specified GPIO port  TODO: this could be rewritten in less lines of code */
void exti_select_source(u32 exti, u32 gpioport)
{
  u8 shift =0;
  u8 bits = 0;
  switch (exti)
  {
    case EXTI0:
    case EXTI4:
    case EXTI8:
    case EXTI12:
      shift = 0;
      break;
    case EXTI1:
    case EXTI5:
    case EXTI9:
    case EXTI13:	
      shift = 4;
      break;
    case EXTI2:
    case EXTI6:
    case EXTI10:
    case EXTI14:
      shift = 8;
      break;
    case EXTI3:
    case EXTI7:
    case EXTI11:
    case EXTI15:
      shift = 12;
      break;
  }
  
  switch (gpioport)
  {
    case GPIOA:
      bits = 0xF;
      break;
    case GPIOB:
      bits = 0xE;
      break;
    case GPIOC:
      bits = 0xD;
      break;
    case GPIOD:
      bits = 0xC;
      break;
    case GPIOE:
      bits = 0xB;
      break;
    case GPIOF:
      bits = 0xA;
      break;
    case GPIOG:
      bits = 0x9;
      break;
  }
    
  if(exti < EXTI4) AFIO_EXTICR1 &=~ ( bits << shift );
  else if (exti < EXTI8) AFIO_EXTICR2 &=~ ( bits << shift );
  else if (exti < EXTI12) AFIO_EXTICR3 &=~ ( bits << shift );
  else if (exti < EXTI16) AFIO_EXTICR4 &=~ ( bits << shift ); //ensure that only valid EXTI lines are used
}