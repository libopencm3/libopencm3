/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <efm32_acmp.h>
#include <efm32_adc.h>
#include <efm32_aes.h>
#include <efm32_assert.h>
#include <efm32_bitband.h>
#include <efm32_burtc.h>
#include <efm32_chip.h>
#include <efm32_cmu.h>
#include <efm32_common.h>
#include <efm32_dac.h>
#include <efm32_dbg.h>
#include <efm32_dma.h>
#include <efm32_ebi.h>
#include <efm32_emu.h>
#include <efm32_gpio.h>
#include <efm32_i2c.h>
#include <efm32_int.h>
#include <efm32_lcd.h>
#include <efm32_lesense.h>
#include <efm32_letimer.h>
#include <efm32_leuart.h>
#include <efm32_mpu.h>
#include <efm32_msc.h>
#include <efm32_opamp.h>
#include <efm32_pcnt.h>
#include <efm32_prs.h>
#include <efm32_rmu.h>
#include <efm32_rtc.h>
#include <efm32_system.h>
#include <efm32_timer.h>
#include <efm32_usart.h>
#include <efm32_vcmp.h>
#include <efm32_version.h>
#include <efm32_wdog.h>

#include <stdio.h>

void setup(void);
void led_toggle(void);
bool button_is_pressed(void);
void debug(int a);

#define LOG_SIZE 1024
volatile char logbuffer[LOG_SIZE];

int main(void)
{
	int x;
	int n_pressed = 0;

	setup();

	while(1) {
		if (button_is_pressed())
		{
			for(x = 0; x < 200000; ++x) asm("mov r0,r0"); /* no-op, prevent compiler from optimizing this away */
			n_pressed += 1;
			debug(n_pressed);
		}
		led_toggle();
	};
}

void debug(int a)
{
	snprintf(logbuffer, LOG_SIZE, "Data %d.\n", a);
}

void setup(void)
{
	// Before GPIO works, according to d0034_efm32tg_reference_manual.pdf
	// note in section 28.3.7, we'll have to enable GPIO in CMU_HFPERCLKEN0
	
	CMU->HFPERCLKEN0 |= _CMU_HFPERCLKEN0_GPIO_MASK;
	
	GPIO_PinModeSet(gpioPortE, 1, gpioModePushPull, 0);
	GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 0);

	GPIO_PinModeSet(gpioPortE, 0, gpioModeInputPull, 1); /* pull up */

	// Counter-blink the other user LED

	GPIO_PinOutToggle(gpioPortE, 2);
}

void led_toggle(void)
{
	GPIO_PinOutToggle(gpioPortE, 1);
	GPIO_PinOutToggle(gpioPortE, 2);
}

bool button_is_pressed(void)
{
	return !GPIO_PinInGet(gpioPortE, 0);
}
