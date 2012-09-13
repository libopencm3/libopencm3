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
#include <libopencm3/lpc43xx/ssp.h>

#include "../jellybean_conf.h"

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

int main(void)
{
	int i;
	u8 ssp_val;
	u8 serial_clock_rate;
	u8 clock_prescale_rate;

	gpio_setup();

	/* Freq About 1.12MHz => Freq = PCLK / (CPSDVSR * [SCR+1]) with PCLK=PLL1=288MHz */
	clock_prescale_rate = 2;
	serial_clock_rate = 128;

	ssp_init(SSP1_NUM,
			SSP_DATA_8BITS,
			SSP_FRAME_SPI,
			SSP_CPOL_0_CPHA_0,
			serial_clock_rate,
			clock_prescale_rate,
			SSP_MODE_NORMAL,
			SSP_MASTER,
			SSP_SLAVE_OUT_ENABLE);

	ssp_val = 0x0;

	while (1) {

		ssp_write(SSP1_NUM, (u16)ssp_val);

		gpio_set(GPIO2, GPIOPIN1); /* LED on */

		for (i = 0; i < 1000; i++) /* Wait a bit. */
			__asm__("nop");

		gpio_clear(GPIO2, GPIOPIN1); /* LED off */

		ssp_val++;
	}

	return 0;
}
