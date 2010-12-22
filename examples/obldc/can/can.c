/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

#include <libopenstm32/rcc.h>
#include <libopenstm32/flash.h>
#include <libopenstm32/gpio.h>
#include <libopenstm32/nvic.h>
#include <libopenstm32/systick.h>
#include <libopenstm32/can.h>

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
	/* Enable GPIOA clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);

	gpio_set(GPIOA, GPIO6);		/* LED0 off */
	gpio_set(GPIOA, GPIO7);		/* LED1 off */
	gpio_set(GPIOB, GPIO0);		/* LED2 off */
	gpio_set(GPIOB, GPIO1);		/* LED3 off */

	/* Set GPIO6/7 (in GPIO port A) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO6);
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO7);

	/* Set GPIO6/7 (in GPIO port B) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO0);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO1);
}

void systick_setup()
{
	/* 72MHz / 8 => 9000000 counts per second */
	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB_DIV8);

	/* 9000000/9000 = 1000 overflows per second - every 1ms one interrupt */
	systick_set_reload(9000);

	systick_interrupt_enable();

	/* start counting */
	systick_counter_enable();
}

void can_setup()
{
	u32 wait_ack = 0x00000000;
	u32 can_msr_inak_timeout = 0x0000FFFF;

	/* Enable peripheral clocks */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_CANEN);

	/* Configure CAN pin: RX (input pull-up) */
	gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
		      GPIO_CNF_INPUT_PULL_UPDOWN, GPIO_CAN_RX);
	gpio_set(GPIOA, GPIO_CAN_RX);

	/* Configure CAN pin: TX */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_CAN_TX);

	/* NVIC setup */
	nvic_enable_irq(NVIC_USB_LP_CAN_RX0_IRQ);
	nvic_set_priority(NVIC_USB_LP_CAN_RX0_IRQ, 1);

	/* --- CAN cell init ------------------------------------------------ */

	/* Exit from sleep mode */
	CAN_MCR(CAN1) &= ~CAN_MCR_SLEEP;

	/* Request initialization "enter" */
	CAN_MCR(CAN1) |= CAN_MCR_INRQ;

	/* Wait for acknowledge */
	while ((wait_ack != can_msr_inak_timeout) &&
		((CAN_MSR(CAN1) & CAN_MSR_INAK) != CAN_MSR_INAK)) {
		wait_ack++;
	}

	/* Check the acknowledge */
	if ((CAN_MSR(CAN1) & CAN_MSR_INAK) != CAN_MSR_INAK) {
		/* we should set some flag here or so because we failed */
	} else {

		/* Set bit timings */
		CAN_BTR(CAN1) = CAN_BTR_SJW_1TQ |
			        CAN_BTR_TS2_3TQ |
			        CAN_BTR_TS2_4TQ |
			        (u32)(CAN_BTR_BRP_MASK & 12);

		/* Request initialization "leave" */
		CAN_MCR(CAN1) &= ~CAN_MCR_INRQ;

		/* Wait for acknowledge */
		wait_ack = 0x00000000;
		while ((wait_ack != can_msr_inak_timeout) && ((CAN_MSR(CAN1) & CAN_MSR_INAK) == CAN_MSR_INAK)) {
			wait_ack++;
		}

		if ((CAN_MSR(CAN1) & CAN_MSR_INAK) != CAN_MSR_INAK) {
			/* set some flag here because we failed */
		} else {
			/* set some flag here because we succeeded */
		}
	}

	/* --- CAN filter 0 init -------------------------------------------- */

	u32 filter_select_bit = 0x00000001;

	/* Request initialization "enter" */
	CAN_FMR(CAN1) |= CAN_FMR_FINIT;

	/* Deactivate the filter */
	CAN_FA1R(CAN1) &= ~filter_select_bit;

	/* Set 32-bit scale for the filter */
	CAN_FS1R(CAN1) |= filter_select_bit;

	/* Set the filter id to 0 */
	CAN_FiR1(CAN1, 0) = 0x00000000;

	/* Set the filter id mask to 0 */
	CAN_FiR2(CAN1, 0) = 0x00000000;

	/* Set filter mode to Id/Mask mode */
	CAN_FM1R(CAN1) &= ~filter_select_bit;

	/* Select FIFO0 as filter assignement */
	CAN_FFA1R(CAN1) &= ~filter_select_bit;

	/* Reactivate the filter */
	CAN_FA1R(CAN1) |= filter_select_bit;

	/* Request initialization "leave" */
	CAN_FMR(CAN1) &= ~CAN_FMR_FINIT;

	/* --- Enable CAN rx interrupt -------------------------------------- */

	CAN_IER(CAN1) |= CAN_IER_FMPIE0;
}

void can_transmit(u32 id, u8 length, u8 data)
{
	u32 mailbox = 0;

	if ((CAN_TSR(CAN1) & CAN_TSR_TME0) == CAN_TSR_TME0) {
		mailbox = CAN_MBOX0;
	} else if ((CAN_TSR(CAN1) & CAN_TSR_TME1) == CAN_TSR_TME1) {
		mailbox = CAN_MBOX1;
	} else if ((CAN_TSR(CAN1) & CAN_TSR_TME2) == CAN_TSR_TME2) {
		mailbox = CAN_MBOX2;
	} else {
		mailbox = 0; /* no mailbox */
	}

	if ( mailbox != 0 ) { /* check if we have an empty mailbox */
		/* Set the ID */
		CAN_TIxR(CAN1, mailbox) |= id << CAN_TIxR_STID_SHIFT;

		/* Set the DLC */
		CAN_TDTxR(CAN1, mailbox) &= 0xFFFFFFFF0;
		CAN_TDTxR(CAN1, mailbox) |= length & CAN_TDTxR_DLC_MASK;

		/* Set the data */
		CAN_TDLxR(CAN1, mailbox) = data;
		CAN_TDHxR(CAN1, mailbox) = 0x00000000;

		/* Request transmission */
		CAN_TIxR(CAN1, mailbox) |= CAN_TIxR_TXRQ;
	}
}

void sys_tick_handler()
{
	static int temp32 = 0;

	temp32++;

	/* we call this handler every 1ms so 1000ms = 1s on/off */
	if (temp32 == 1000) {
		gpio_toggle(GPIOA, GPIO6); /* LED2 on/off */
		temp32 = 0;

		/* --- Transmit CAN frame ----------------------------------- */

		can_transmit(0, 0, 10);
	}
}

int main(void)
{
        rcc_clock_setup_in_hse_16mhz_out_72mhz();
	gpio_setup();
	can_setup();
	systick_setup();

	while(1); /* Halt. */

	return 0;
}
