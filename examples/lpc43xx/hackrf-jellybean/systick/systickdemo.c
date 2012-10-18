/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#include <libopencm3/lpc43xx/gpio.h>
#include <libopencm3/lpc43xx/scu.h>
#include <libopencm3/lpc43xx/cgu.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/scs.h>

#include "../jellybean_conf.h"

/* Global counter incremented by SysTick Interrupt each millisecond */
volatile u32 g_ulSysTickCount;
u32 g_NbCyclePerSecond;

void gpio_setup(void)
{
	/* Configure all GPIO as Input (safe state) */
	GPIO0_DIR = 0;
	GPIO1_DIR = 0;
	GPIO2_DIR = 0;
	GPIO3_DIR = 0;
	GPIO4_DIR = 0;
	GPIO5_DIR = 0;
	GPIO6_DIR = 0;
	GPIO7_DIR = 0;

	/* Configure SCU Pin Mux as GPIO */
	scu_pinmux(SCU_PINMUX_LED1, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_LED2, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_LED3, SCU_GPIO_FAST);
	
	scu_pinmux(SCU_PINMUX_EN1V8, SCU_GPIO_FAST);
	
	scu_pinmux(SCU_PINMUX_BOOT0, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_BOOT1, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_BOOT2, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_BOOT3, SCU_GPIO_FAST);

	/* Configure SSP1 Peripheral (to be moved later in SSP driver) */
	scu_pinmux(SCU_SSP1_MISO, (SCU_SSP_IO | SCU_CONF_FUNCTION5));
	scu_pinmux(SCU_SSP1_MOSI, (SCU_SSP_IO | SCU_CONF_FUNCTION5));
	scu_pinmux(SCU_SSP1_SCK,  (SCU_SSP_IO | SCU_CONF_FUNCTION1));
	scu_pinmux(SCU_SSP1_SSEL, (SCU_SSP_IO | SCU_CONF_FUNCTION1));

	/* Configure GPIO as Output */
	GPIO2_DIR |= (PIN_LED1|PIN_LED2|PIN_LED3); /* Configure GPIO2[1/2/8] (P4_1/2 P6_12) as output. */
	GPIO3_DIR |= PIN_EN1V8; /* GPIO3[6] on P6_10  as output. */
}

void systick_setup(void)
{
	u32 systick_reload_val;
	g_ulSysTickCount = 0;

	/* Disable IRQ globally */
	asm volatile ("cpsid i");

	/* Set processor Clock as Source Clock */
	systick_set_clocksource(STK_CTRL_CLKSOURCE);

	/* Get SysTick calibration value to obtain by default 1 tick = 10ms */
	systick_reload_val = systick_get_calib();
	/*
     * Calibration seems wrong on LPC43xx(TBC) for default Freq it assume System Clock is 12MHz but it is 12*8=96MHz
	 * Fix the Calibration value bu multiplication by 8
     */
	systick_reload_val = (systick_reload_val*8);

	/* To obtain 1ms per tick just divide by 10 the 10ms base tick and set the reload */
	systick_reload_val = systick_reload_val/10;
	systick_set_reload(systick_reload_val);

	systick_interrupt_enable();

	/* Start counting. */
	systick_counter_enable();

	/* Set SysTick Priority to maximum */
	nvic_set_priority(NVIC_SYSTICK_IRQ, 0xFF);

	/* Enable IRQ globally */
	asm volatile ("cpsie i");
}

void scs_dwt_cycle_counter_enabled(void)
{
	SCS_DEMCR |= SCS_DEMCR_TRCENA;
	SCS_DWT_CTRL  |= SCS_DWT_CTRL_CYCCNTENA;
}

u32 sys_tick_get_time_ms(void)
{
    return g_ulSysTickCount;
}

u32 sys_tick_delta_time_ms(u32 start, u32 end)
{
	#define MAX_T_U32 ((2^32)-1)
    u32 diff;

    if(end > start)
    {
        diff=end-start;
    }else
    {
        diff=MAX_T_U32-(start-end)+1;
    }
    
    return diff;
}

void sys_tick_wait_time_ms(u32 wait_ms)
{
    u32 start, end;
    u32 tickms;

    start = sys_tick_get_time_ms();

    do
    {
        end = sys_tick_get_time_ms();
        tickms = sys_tick_delta_time_ms(start, end);
    }while(tickms < wait_ms);
}

/* Called each 1ms/1000Hz by interrupt
 1) Count the number of cycle per second.
 2) Increment g_ulSysTickCount counter.
*/
void sys_tick_handler(void)
{
	if(g_ulSysTickCount==0)
	{
		/* Clear Cycle Counter*/
		SCS_DWT_CYCCNT = 0;
	}else if(g_ulSysTickCount==1000)
	{
		/* Capture number of cycle elapsed during 1 second */
		g_NbCyclePerSecond = SCS_DWT_CYCCNT;
	}

	g_ulSysTickCount++;
}

int main(void)
{
	systick_setup();

	gpio_setup();

	/* SCS & Cycle Counter enabled (used to count number of cycles executed per second see g_NbCyclePerSecond */
	scs_dwt_cycle_counter_enabled();

	while (1) 
	{
		gpio_set(PORT_LED1_3, (PIN_LED1|PIN_LED2|PIN_LED3)); /* LEDs on */

		sys_tick_wait_time_ms(500);

		gpio_clear(PORT_LED1_3, (PIN_LED1|PIN_LED2|PIN_LED3)); /* LED off */

		sys_tick_wait_time_ms(500);
	}

	return 0;
}
