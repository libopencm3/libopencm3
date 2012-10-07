/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 Stephen Dwyer <dwyer.sc@gmail.com>
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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/flash.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/f1/adc.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/timer.h>

void usart_setup(void)
{
	/* Enable clocks for GPIO port A (for GPIO_USART1_TX) and USART1. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);

	/* Setup GPIO pin GPIO_USART1_TX/GPIO9 on GPIO port A for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART2, 115200);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void gpio_setup(void)
{
	/* Enable GPIO clocks. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

	/* Setup the LEDs. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO15);
}

void timer_setup(void)
{
	/* Set up the timer TIM2 for injected sampling */
	uint32_t timer;
    volatile uint32_t *rcc_apbenr;
    uint32_t rcc_apb;

	timer   = TIM2;
    rcc_apbenr = &RCC_APB1ENR;
    rcc_apb = RCC_APB1ENR_TIM2EN;

	rcc_peripheral_enable_clock(rcc_apbenr, rcc_apb);

	/* Time Base configuration */
    timer_reset(timer);
    timer_set_mode(timer, TIM_CR1_CKD_CK_INT,
	    TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
    timer_set_period(timer, 0xFF);
    timer_set_prescaler(timer, 0x8);
    timer_set_clock_division(timer, 0x0);
    /* Generate TRGO on every update. */
    timer_set_master_mode(timer, TIM_CR2_MMS_UPDATE);
    timer_enable_counter(timer);
}

void adc_setup(void)
{
	int i;

	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_ADC1EN);

	/* Make sure the ADC doesn't run during config. */
	adc_off(ADC1);

	/* We configure everything for one single timer triggered injected conversion. */
	adc_disable_scan_mode(ADC1);
	adc_set_single_conversion_mode(ADC1);
	/* We can only use discontinuous mode on either the regular OR injected channels, not both */
	adc_disable_discontinuous_mode_regular(ADC1);
	adc_enable_discontinuous_mode_injected(ADC1);
	/* We want to start the injected conversion with the TIM2 TRGO */
	adc_enable_external_trigger_injected(ADC1,ADC_CR2_JEXTSEL_TIM2_TRGO);
	adc_set_right_aligned(ADC1);
	/* We want to read the temperature sensor, so we have to enable it. */
	adc_enable_temperature_sensor(ADC1);
	adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR_SMP_28DOT5CYC);

	adc_power_on(ADC1);

	/* Wait for ADC starting up. */
	for (i = 0; i < 800000; i++)    /* Wait a bit. */
		__asm__("nop");

	adc_reset_calibration(ADC1);
	while ((ADC_CR2(ADC1) & ADC_CR2_RSTCAL) != 0);
	adc_calibration(ADC1);
	while ((ADC_CR2(ADC1) & ADC_CR2_CAL) != 0);
}

void my_usart_print_int(u32 usart, int value)
{
	s8 i;
	u8 nr_digits = 0;
	char buffer[25];

	if (value < 0) {
		usart_send_blocking(usart, '-');
		value = value * -1;
	}

	while (value > 0) {
		buffer[nr_digits++] = "0123456789"[value % 10];
		value /= 10;
	}

	for (i = (nr_digits - 1); i >= 0; i--) {
		usart_send_blocking(usart, buffer[i]);
	}

	usart_send_blocking(usart, '\r');
}

int main(void)
{
	u8 channel_array[16];
	u16 temperature = 0;

	rcc_clock_setup_in_hse_12mhz_out_72mhz();
	gpio_setup();
	usart_setup();
	timer_setup();
	adc_setup();

	gpio_set(GPIOA, GPIO8);	                /* LED1 on */
	gpio_set(GPIOC, GPIO15);		/* LED2 on */

	/* Send a message on USART1. */
	usart_send_blocking(USART2, 's');
	usart_send_blocking(USART2, 't');
	usart_send_blocking(USART2, 'm');
	usart_send_blocking(USART2, '\r');
	usart_send_blocking(USART2, '\n');

	/* Select the channel we want to convert. 16=temperature_sensor. */
	channel_array[0] = 16;
	/* Set the injected sequence here, with number of channels */
	adc_set_injected_sequence(ADC1, 1, channel_array);

	/* Continously convert and poll the temperature ADC. */
	while (1) {
		/*
		 * Since the injected sampling is triggered by the timer, it gets
		 * updated automatically, we just need to periodically read out the value.
		 * It would be better to check if the JEOC bit is set, and clear it following
		 * so that you do not read the same value twice, especially for a slower
		 * sampling rate.
		 */

		temperature = adc_read_injected(ADC1,1); //get the result from ADC_JDR1 on ADC1 (only bottom 16bits)

		/*
		 * That's actually not the real temperature - you have to compute it
		 * as described in the datasheet.
		 */
		my_usart_print_int(USART2, temperature);

		gpio_toggle(GPIOA, GPIO8); /* LED2 on */

	}

	return 0;
}
