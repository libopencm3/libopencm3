/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Piotr Esden-Tempski <piotr@esden.net>
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

	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);

	/* Preconfigure LEDs. */
	gpio_set(GPIOB, GPIO4);  /* LED green off */
	gpio_set(GPIOB, GPIO5);  /* LED red off */

	/* Configure LED GPIOs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO4);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);

	/* Configure PB4 as GPIO. */
	AFIO_MAPR |= AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST;

}

void systick_setup(void)
{
	/* 64MHz / 8 => 8000000 counts per second */
	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB_DIV8);

	/* 8000000/8000 = 1000 overflows per second - every 1ms one interrupt */
	systick_set_reload(8000);

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

	/* CAN cell init.
	 * Setting the bitrate to 1MBit. APB1 = 32MHz, 
	 * prescaler = 2 -> 16MHz time quanta frequency.
	 * 1tq sync + 9tq bit segment1 (TS1) + 6tq bit segment2 (TS2) = 
	 * 16time quanto per bit period, therefor 16MHz/16 = 1MHz
	 */
	if (can_init(CAN1,
		     false,           /* TTCM: Time triggered comm mode? */
		     true,            /* ABOM: Automatic bus-off management? */
		     false,           /* AWUM: Automatic wakeup mode? */
		     false,           /* NART: No automatic retransmission? */
		     false,           /* RFLM: Receive FIFO locked mode? */
		     false,           /* TXFP: Transmit FIFO priority? */
		     CAN_BTR_SJW_1TQ,
		     CAN_BTR_TS1_9TQ,
		     CAN_BTR_TS2_6TQ,
		     2))             /* BRP+1: Baud rate prescaler */
	{
		gpio_clear(GPIOB, GPIO4); /* LED green on */
		gpio_set(GPIOB, GPIO5);   /* LED red off */

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
	static u8 data[8] = {0, 1, 2, 0, 0, 0, 0, 0};

	/* We call this handler every 1ms so every 1ms = 0.001s
	 * resulting in 1000Hz message rate.
	 */

	/* Transmit CAN frame. */
	data[0]++;
	if (can_transmit(CAN1,
			 0,     /* (EX/ST)ID: CAN ID */
			 false, /* IDE: CAN ID extended? */
			 false, /* RTR: Request transmit? */
			 8,     /* DLC: Data length */
			 data) == -1)
	{
		gpio_set(GPIOB, GPIO4);   /* LED green off */
		gpio_clear(GPIOB, GPIO5); /* LED red on */
	}
}

void usb_lp_can_rx0_isr(void)
{
	u32 id, fmi;
	bool ext, rtr;
	u8 length, data[8];

	can_receive(CAN1, 0, false, &id, &ext, &rtr, &fmi, &length, data);

	if (data[0] & 0x40)
		gpio_clear(GPIOB, GPIO4);
	else
		gpio_set(GPIOB, GPIO4);

	if (data[0] & 0x80)
		gpio_clear(GPIOB, GPIO5);
	else
		gpio_set(GPIOB, GPIO5);

	can_fifo_release(CAN1, 0);
}

int main(void)
{
	rcc_clock_setup_in_hsi_out_64mhz();
	gpio_setup();
	can_setup();
	systick_setup();

	while (1); /* Halt. */

	return 0;
}
