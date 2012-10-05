/*
 * This file is part of the libopencm3 project.
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


#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/f4/gpio.h>
#include <libopencm3/stm32/f4/rng.h>

static void rcc_setup(void)
{
	rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_120MHZ]);

	/* Enable GPIOD clock for onboard leds. */
	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPDEN);

	/* Enable rng clock */
	rcc_peripheral_enable_clock(&RCC_AHB2ENR, RCC_AHB2ENR_RNGEN);
}

static void rng_setup(void)
{
	/* Enable interupt */
	/* Set the IE bit in the RNG_CR register. */
	RNG_CR |= RNG_CR_IE;
	/* Enable the random number generation by setting the RNGEN bit in the RNG_CR
	register. This activates the analog part, the RNG_LFSR and the error detector.
	*/
	RNG_CR |= RNG_CR_EN;
}

static void gpio_setup(void)
{
	/* Setup onboard led */
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12 | GPIO13);
}

/* Tried to folow the guidelines in the stm32f4 user manual.*/
static u32 random_int(void)
{
	static u32 last_value=0;
	static u32 new_value=0;
	u32 error_bits = 0;
	error_bits = RNG_SR_SEIS | RNG_SR_CEIS;
	while (new_value==last_value) {
		/* Check for error flags and if data is ready. */
		if ( ((RNG_SR & error_bits) == 0) && ( (RNG_SR & RNG_SR_DRDY) == 1 ) )
			new_value=RNG_DR;
	}
	last_value=new_value;
	return new_value;
}


int main(void)
{
	int i,j;
	rcc_setup();
	gpio_setup();
	rng_setup();
	while(1){
		u32 rnd;
		rnd = random_int();
		for(i=0;i!=32;++i){
			if ( (rnd & (1 << i))!=0 )
				gpio_set(GPIOD, GPIO12);
			else
				gpio_clear(GPIOD, GPIO12);
			/* Delay */
			for(j=0;j!=5000000;++j)
				__asm__("nop");
		}		
	}
}
