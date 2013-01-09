/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2012-2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/**
 * \addtogroup Examples
 *
 * Flashes the Red, Green and Blue diodes on the board, in order.
 *
 * RED controlled by PF1
 * Green controlled by PF3
 * Blue controlled by PF2
 */
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/lm4f/systemcontrol.h>
#include <libopencm3/lm4f/rcc.h>
#include <libopencm3/lm4f/gpio.h>
#include <libopencm3/lm4f/nvic.h>

#include <stdbool.h>
#include <stdio.h>

/* This is how the RGB LED is connected on the stellaris launchpad */
#define RGB_PORT	GPIOF
enum {
	LED_R	= GPIO1,
	LED_G	= GPIO3,
	LED_B	= GPIO2,
};

/* This is how the user switches are connected to GPIOF */
enum {
	USR_SW1	= GPIO4,
	USR_SW2	= GPIO0,
};

/* The divisors we loop through when the user presses SW2 */
enum {
	PLL_DIV_80MHZ 	= 5,
	PLL_DIV_57MHZ 	= 7,
	PLL_DIV_40MHZ 	= 10,
	PLL_DIV_20MHZ 	= 20,
	PLL_DIV_16MHZ 	= 25,
};

static const u8 plldiv[] = {
	PLL_DIV_80MHZ,
	PLL_DIV_57MHZ,
	PLL_DIV_40MHZ,
	PLL_DIV_20MHZ,
	PLL_DIV_16MHZ,
	0
};
/* The PLL divisor we are currently on */
static size_t ipll = 0;
/* Are we bypassing the PLL, or not? */
static bool bypass = false;

/*
 * Clock setup:
 * Take the main crystal oscillator at 16MHz, run it through the PLL, and divide
 * the 400MHz PLL clock to get a system clock of 80MHz.
 */
static void clock_setup(void)
{
	rcc_sysclk_config(OSCSRC_MOSC, XTAL_16M, PLL_DIV_80MHZ);
}

/*
 * GPIO setup:
 * Enable the pins driving the RGB LED as outputs.
 */
static void gpio_setup(void)
{
	/*
	 * Configure GPIOF
	 * This port is used to control the RGB LED
	 */
	periph_clock_enable(RCC_GPIOF);
	const u32 outpins = (LED_R | LED_G | LED_B);

	GPIO_DIR(RGB_PORT) |= outpins; /* Configure outputs. */
	GPIO_DEN(RGB_PORT) |= outpins; /* Enable digital function on outputs. */

	/*
	 * Now take care of our buttons
	 */
	const u32 btnpins = USR_SW1 | USR_SW2;

	/*
	 * PF0 is locked by default. We need to unlock the GPIO_CR register,
	 * then enable PF0 commit. After we do this, we can setup PF0. If we
	 * don't do this, any configuration done to PF0 is lost, and we will not
	 * have a PF0 interrupt.
	 */
	GPIO_LOCK(GPIOF) = 0x4C4F434B;
	GPIO_CR(GPIOF) |= USR_SW2;

	/* Configure pins as inputs. */
	GPIO_DIR(GPIOF) &= ~btnpins;
	/* Enable digital function on the pins. */
	GPIO_DEN(GPIOF) |= btnpins;
	/* Pull-up the pins. We don't have an external pull-up */
	GPIO_PUR(GPIOF) |= btnpins;
}

/*
 * IRQ setup:
 * Trigger an interrupt whenever a button is depressed.
 */
static void irq_setup(void)
{
	const u32 btnpins = USR_SW1 | USR_SW2;
	/* Configure interrupt as edge-sensitive */
	GPIO_IS(GPIOF) &= ~btnpins;
	/* Interrupt only respond to rising or falling edge (single-edge) */
	GPIO_IBE(GPIOF) &= ~btnpins;
	/* Trigger interrupt on rising-edge (when button is depressed) */
	GPIO_IEV(GPIOF) |= btnpins;
	/* Finally, Enable interrupt */
	GPIO_IM(GPIOF) |= btnpins;
	/* Enable the interrupt in the NVIC as well */
	nvic_enable_irq(NVIC_GPIOF_IRQ);
}

#define FLASH_DELAY 800000
static void delay(void)
{
	int i;
	for (i = 0; i < FLASH_DELAY; i++)       /* Wait a bit. */
		__asm__("nop");
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();
	irq_setup();

	/* Blink each color of the RGB LED in order. */
	while (1) {
		/*
		 * Flash the Red diode
		 */
		gpio_set(RGB_PORT, LED_R);
		delay(); /* Wait a bit. */
		gpio_clear(RGB_PORT, LED_R);
		delay(); /* Wait a bit. */

		/*
		 * Flash the Green diode
		 */
		gpio_set(RGB_PORT, LED_G);
		delay(); /* Wait a bit. */
		gpio_clear(RGB_PORT, LED_G);
		delay(); /* Wait a bit. */

		/*
		 * Flash the Blue diode
		 */
		gpio_set(RGB_PORT, LED_B);
		delay(); /* Wait a bit. */
		gpio_clear(RGB_PORT, LED_B);
		delay(); /* Wait a bit. */
	}

	return 0;
}

void gpiof_isr(void)
{
	if (GPIO_RIS(GPIOF) & USR_SW1) {
		/* SW1 was just depressed */
		bypass = !bypass;
		if (bypass) {
			rcc_pll_bypass_enable();
			/*
			 * The divisor is still applied to the raw clock.
			 * Disable the divisor, or we'll divide the raw clock.
			 */
			SYSCTL_RCC &= ~SYSCTL_RCC_USESYSDIV;
		}
		else
		{
			rcc_change_pll_divisor(plldiv[ipll]);
		}
		/* Clear interrupt source */
		GPIO_ICR(GPIOF) = USR_SW1;
	}

	if (GPIO_RIS(GPIOF) & USR_SW2) {
		/* SW2 was just depressed */
		if (!bypass) {
			if (plldiv[++ipll] == 0)
				ipll = 0;
			rcc_change_pll_divisor(plldiv[ipll]);
		}
		/* Clear interrupt source */
		GPIO_ICR(GPIOF) = USR_SW2;
	}
}
