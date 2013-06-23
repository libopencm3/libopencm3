/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Modified by Fernando Cortes <fermando.corcam@gmail.com>
 * modified by Guillermo Rivera <memogrg@gmail.com>
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

#include <libopencm3/stm32/f3/rcc.h>
#include <libopencm3/stm32/f3/adc.h>
#include <libopencm3/stm32/f3/usart.h>
#include <libopencm3/stm32/gpio.h>

#define LBLUE GPIOE, GPIO8
#define LRED GPIOE, GPIO9
#define LORANGE GPIOE, GPIO10
#define LGREEN GPIOE, GPIO11
#define LBLUE2 GPIOE, GPIO12
#define LRED2 GPIOE, GPIO13
#define LORANGE2 GPIOE, GPIO14
#define LGREEN2 GPIOE, GPIO15

#define LD4 GPIOE, GPIO8
#define LD3 GPIOE, GPIO9
#define LD5 GPIOE, GPIO10
#define LD7 GPIOE, GPIO11
#define LD9 GPIOE, GPIO12
#define LD10 GPIOE, GPIO13
#define LD8 GPIOE, GPIO14
#define LD6 GPIOE, GPIO15


void adc_setup(void) {
	//ADC
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_ADC12EN);
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_IOPAEN);
	//ADC
	gpio_mode_setup(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO0);
	gpio_mode_setup(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO1);
	adc_off(ADC1);
	adc_set_clk_prescale(ADC_CCR_CKMODE_DIV2);
        adc_set_single_conversion_mode(ADC1);
        adc_disable_external_trigger_regular(ADC1);
        adc_set_right_aligned(ADC1);
        /* We want to read the temperature sensor, so we have to enable it. */
        adc_enable_temperature_sensor();
        adc_set_sample_time_on_all_channels(ADC1, ADC_SMPR1_SMP_61DOT5CYC);
	u8 channel_array[16];
	channel_array[0]=16; // Vts (Internal temperature sensor
	channel_array[0]=1; //ADC1_IN1 (PA0)
	adc_set_regular_sequence(ADC1, 1, channel_array);
	adc_set_resolution(ADC1, ADC_CFGR_RES_12_BIT);
        adc_power_on(ADC1);

        /* Wait for ADC starting up. */
	int i;
        for (i = 0; i < 800000; i++)    /* Wait a bit. */
                __asm__("nop");

}

void usart_setup(void) {
  /* Enable clocks for GPIO port A (for GPIO_USART2_TX) and USART2. */
  rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
  rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_IOPAEN);

  /* Setup GPIO pin GPIO_USART2_TX/GPIO9 on GPIO port A for transmit. */
  gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2 | GPIO3);
  gpio_set_af(GPIOA, GPIO_AF7, GPIO2| GPIO3);

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
	/* Enable GPIOE clock. */
	/* Manually: */
	// RCC_AHB1ENR |= RCC_AHB1ENR_IOPDEN;
	/* Using API functions: */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_IOPEEN);


	/* Set GPIO12 (in GPIO port E) to 'output push-pull'. */
	/* Manually: */
	//GPIOE_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((8 - 8) * 4) + 2));
	//GPIOE_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((8 - 8) * 4));
	/* Using API functions: */
	gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8| GPIO9| GPIO10| GPIO11| GPIO12| GPIO13| GPIO14| GPIO15);
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

        for (i = nr_digits; i >= 0; i--) {
                usart_send_blocking(usart, buffer[i]);
        }

        usart_send_blocking(usart, '\r');
        usart_send_blocking(usart, '\n');
}

void clock_setup(void) {
  /*
  rcc_set_sysclk_source(RCC_CFGR_SW_HSI); //se cayo
  rcc_wait_for_sysclk_status(HSI);
  rcc_osc_off(PLL);
  rcc_wait_for_osc_not_ready(PLL);
  rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_DIV2);
  rcc_set_main_pll_hsi(RCC_CFGR_PLLMUL_PLL_IN_CLK_X11);
  rcc_osc_on(PLL);
  rcc_wait_for_osc_ready(PLL);
  rcc_set_hpre(RCC_CFGR_HPRE_DIV_NONE);
  rcc_set_ppre2(RCC_CFGR_PPRE2_DIV_NONE);
  rcc_set_ppre1(RCC_CFGR_PPRE1_DIV_2);
  rcc_set_sysclk_source(RCC_CFGR_SW_PLL); //se cayo
  rcc_wait_for_sysclk_status(PLL);
  */
  //rcc_clock_setup_hsi(&hsi_8mhz[CLOCK_44MHZ]);
  rcc_clock_setup_hsi(&hsi_8mhz[CLOCK_64MHZ]);
}

int main(void)
{
	int i, j;
       	u16 temp, inc=0;

	clock_setup();
	gpio_setup();
	adc_setup();
	usart_setup();

	/* Blink the LED (PC8) on the board. */
	while (1) {
	  /* Manually: */
	  // GPIOD_BSRR = GPIO12;		/* LED off */
	  // for (i = 0; i < 1000000; i++)	/* Wait a bit. */
	  // 	__asm__("nop");
	  // GPIOD_BRR = GPIO9;		/* LED on */
	  // for (i = 0; i < 1000000; i++)	/* Wait a bit. */
	  // 	__asm__("nop");

	  /* Using API functions gpio_set()/gpio_clear(): */
	  //gpio_set(GPIOE, GPIO9);	/* LED off */
	  // for (i = 0; i < 1000000; i++)	/* Wait a bit. */
	  // 	__asm__("nop");
	  //gpio_clear(GPIOE, GPIO9);	/* LED on */
	  // for (i = 0; i < 1000000; i++)	/* Wait a bit. */
	  // 	__asm__("nop");

	  /* Using API function gpio_toggle(): */
	  gpio_toggle(LRED);
	  for (i = 0; i < 200000; i++) /* Wait a bit. */
	    __asm__("nop");
	  gpio_toggle(LRED);
	  for (i = 0; i < 200000; i++) /* Wait a bit. */
	    __asm__("nop");
	  adc_start_conversion_regular(ADC1);
	  while (!(adc_eoc(ADC1)));
	  temp=adc_read_regular(ADC1);
	  gpio_port_write(GPIOE, temp << 4);
	  my_usart_print_int(USART2, temp);
	  //usart_send_blocking(USART2, 'a');
	  //usart_send_blocking(USART2, '\r');
	  //usart_send_blocking(USART2, '\n');

	  inc++;
	}

	return 0;
}

