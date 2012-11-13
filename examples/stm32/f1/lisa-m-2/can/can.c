/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010-2011 Piotr Esden-Tempski <piotr@esden.net>
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
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/can.h>

struct can_tx_msg {
	u32 std_id;
	u32 ext_id;
	u8 ide;
	u8 rtr;
	u8 dlc;
	u8 data[8];
};

struct can_rx_msg {
	u32 std_id;
	u32 ext_id;
	u8 ide;
	u8 rtr;
	u8 dlc;
	u8 data[8];
	u8 fmi;
};

struct can_tx_msg can_tx_msg;
struct can_rx_msg can_rx_msg;

void gpio_setup(void)
{
        /* Enable Alternate Function clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);

	/* Enable GPIOA clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);

	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);

	/* Enable GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

	/* Preconfigure LEDs. */
	gpio_set(GPIOA, GPIO8);  /* LED1 off */
	gpio_set(GPIOB, GPIO4);  /* LED2 off */
	gpio_set(GPIOC, GPIO2);  /* LED3 off */
	gpio_set(GPIOC, GPIO5);  /* LED4 off */
	gpio_set(GPIOC, GPIO15); /* LED5 off */

	/* Configure LED GPIOOs. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO4);
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO2);
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO15);

	/* Configure PB4 as GPIO. */
	AFIO_MAPR |= AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST;

}

void systick_setup(void)
{
	/* 72MHz / 8 => 9000000 counts per second */
	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB_DIV8);

	/* 9000000/9000 = 1000 overflows per second - every 1ms one interrupt */
	systick_set_reload(9000);

	systick_interrupt_enable();

	/* Start counting. */
	systick_counter_enable();
}

void can_setup(void)
{
	/* Enable peripheral clocks. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_CAN1EN);

	AFIO_MAPR |= AFIO_MAPR_CAN1_REMAP_PORTB;

	/* Configure CAN pin: RX (input pull-up). */
	gpio_set_mode(GPIO_BANK_CAN1_PB_RX, GPIO_MODE_INPUT,
		      GPIO_CNF_INPUT_PULL_UPDOWN, GPIO_CAN1_PB_RX);
	gpio_set(GPIO_BANK_CAN1_PB_RX, GPIO_CAN1_PB_RX);

	/* Configure CAN pin: TX. */
	gpio_set_mode(GPIO_BANK_CAN1_PB_TX, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_CAN1_PB_TX);

	/* NVIC setup. */
	nvic_enable_irq(NVIC_USB_LP_CAN_RX0_IRQ);
	nvic_set_priority(NVIC_USB_LP_CAN_RX0_IRQ, 1);

	/* Reset CAN. */
	can_reset(CAN1);

	/* CAN cell init. */
	if (can_init(CAN1,
		     false,           /* TTCM: Time triggered comm mode? */
		     true,            /* ABOM: Automatic bus-off management? */
		     false,           /* AWUM: Automatic wakeup mode? */
		     false,           /* NART: No automatic retransmission? */
		     false,           /* RFLM: Receive FIFO locked mode? */
		     false,           /* TXFP: Transmit FIFO priority? */
		     CAN_BTR_SJW_1TQ,
		     CAN_BTR_TS1_3TQ,
		     CAN_BTR_TS2_4TQ,
		     12))             /* BRP+1: Baud rate prescaler */
	{
		gpio_set(GPIOA, GPIO8);   /* LED1 off */
		gpio_set(GPIOB, GPIO4);   /* LED2 off */
		gpio_set(GPIOC, GPIO2);   /* LED3 off */
		gpio_clear(GPIOC, GPIO5); /* LED4 on */
		gpio_set(GPIOC, GPIO15);  /* LED5 off */

		/* Die because we failed to initialize. */
		while (1)
			__asm__("nop");
	}

	/* CAN filter 0 init. */
	can_filter_id_mask_32bit_init(CAN1,
				0,     /* Filter ID */
				0,     /* CAN ID */
				0,     /* CAN ID mask */
				0,     /* FIFO assignment (here: FIFO0) */
				true); /* Enable the filter. */

	/* Enable CAN RX interrupt. */
	can_enable_irq(CAN1, CAN_IER_FMPIE0);
}

void sys_tick_handler(void)
{
	static int temp32 = 0;
	static u8 data[8] = {0, 1, 2, 0, 0, 0, 0, 0};

	/* We call this handler every 1ms so every 100ms = 0.1s
	 * resulting in 100Hz message rate.
	 */
	if (++temp32 != 100)
		return;

	temp32 = 0;

	/* Transmit CAN frame. */
	data[0]++;
	if (can_transmit(CAN1,
			 0,     /* (EX/ST)ID: CAN ID */
			 false, /* IDE: CAN ID extended? */
			 false, /* RTR: Request transmit? */
			 8,     /* DLC: Data length */
			 data) == -1)
	{
		gpio_set(GPIOA, GPIO8);    /* LED1 off */
		gpio_set(GPIOB, GPIO4);    /* LED2 off */
		gpio_set(GPIOC, GPIO2);    /* LED3 off */
		gpio_set(GPIOC, GPIO5);    /* LED4 off */
		gpio_clear(GPIOC, GPIO15); /* LED5 on */
	}
}

void usb_lp_can_rx0_isr(void)
{
	u32 id, fmi;
	bool ext, rtr;
	u8 length, data[8];

	can_receive(CAN1, 0, false, &id, &ext, &rtr, &fmi, &length, data);

	if (data[0] & 1)
		gpio_clear(GPIOA, GPIO8);
	else
		gpio_set(GPIOA, GPIO8);

	if (data[0] & 2)
		gpio_clear(GPIOB, GPIO4);
	else
		gpio_set(GPIOB, GPIO4);

	if (data[0] & 4)
		gpio_clear(GPIOC, GPIO2);
	else
		gpio_set(GPIOC, GPIO2);

	if (data[0] & 8)
		gpio_clear(GPIOC, GPIO5);
	else
		gpio_set(GPIOC, GPIO5);

	can_fifo_release(CAN1, 0);
}

int main(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();
	gpio_setup();
	can_setup();
	systick_setup();

	while (1); /* Halt. */

	return 0;
}
