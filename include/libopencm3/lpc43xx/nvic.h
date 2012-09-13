/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_NVIC_H
#define LPC43XX_NVIC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- NVIC Registers ------------------------------------------------------ */

/* ISER: Interrupt Set Enable Registers */
/* Note: 8 32bit Registers */
#define NVIC_ISER(iser_id)		MMIO32(NVIC_BASE + 0x00 + (iser_id * 4))

/* NVIC_BASE + 0x020 (0xE000 E120 - 0xE000 E17F): Reserved */

/* ICER: Interrupt Clear Enable Registers */
/* Note: 8 32bit Registers */
#define NVIC_ICER(icer_id)		MMIO32(NVIC_BASE + 0x80 + (icer_id * 4))

/* NVIC_BASE + 0x0A0 (0xE000 E1A0 - 0xE000 E1FF): Reserved */

/* ISPR: Interrupt Set Pending Registers */
/* Note: 8 32bit Registers */
#define NVIC_ISPR(ispr_id)		MMIO32(NVIC_BASE + 0x100 + (ispr_id * 4))

/* NVIC_BASE + 0x120 (0xE000 E220 - 0xE000 E27F): Reserved */

/* ICPR: Interrupt Clear Pending Registers */
/* Note: 8 32bit Registers */
#define NVIC_ICPR(icpr_id)		MMIO32(NVIC_BASE + 0x180 + (icpr_id * 4))

/* NVIC_BASE + 0x1A0 (0xE000 E2A0 - 0xE00 E2FF): Reserved */

/* IABR: Interrupt Active Bit Register */
/* Note: 8 32bit Registers */
#define NVIC_IABR(iabr_id)		MMIO32(NVIC_BASE + 0x200 + (iabr_id * 4))

/* NVIC_BASE + 0x220 (0xE000 E320 - 0xE000 E3FF): Reserved */

/* IPR: Interrupt Priority Registers */
/* Note: 240 8bit Registers */
#define NVIC_IPR(ipr_id)		MMIO8(NVIC_BASE + 0x300 + ipr_id)

/* STIR: Software Trigger Interrupt Register */
#define NVIC_STIR			MMIO32(STIR_BASE)

/* --- IRQ channel numbers-------------------------------------------------- */

/* Cortex M4 System Interrupts */
#define NVIC_NMI_IRQ                    -14
#define NVIC_HARD_FAULT_IRQ             -13
#define NVIC_MEM_MANAGE_IRQ             -12
#define NVIC_BUS_FAULT_IRQ              -11
#define NVIC_USAGE_FAULT_IRQ            -10
/* irq numbers -6 to -9 are reserved */
#define NVIC_SV_CALL_IRQ                -5
#define DEBUG_MONITOR_IRQ               -4
/* irq number -3 reserved */
#define NVIC_PENDSV_IRQ                 -2
#define NVIC_SYSTICK_IRQ                -1

/* LPC43xx M4 specific user interrupts */
#define NVIC_M4_DAC_IRQ                 0
#define NVIC_M4_M0CORE_IRQ              1
#define NVIC_M4_DMA_IRQ                 2
#define NVIC_M4_ETHERNET_IRQ            5
#define NVIC_M4_SDIO_IRQ                6
#define NVIC_M4_LCD_IRQ                 7
#define NVIC_M4_USB0_IRQ                8
#define NVIC_M4_USB1_IRQ                9
#define NVIC_M4_SCT_IRQ                 10
#define NVIC_M4_RITIMER_IRQ             11
#define NVIC_M4_TIMER0_IRQ              12
#define NVIC_M4_TIMER1_IRQ              13
#define NVIC_M4_TIMER2_IRQ              14
#define NVIC_M4_TIMER3_IRQ              15
#define NVIC_M4_MCPWM_IRQ               16
#define NVIC_M4_ADC0_IRQ                17
#define NVIC_M4_I2C0_IRQ                18
#define NVIC_M4_I2C1_IRQ                19
#define NVIC_M4_SPI_IRQ                 20
#define NVIC_M4_ADC1_IRQ                21
#define NVIC_M4_SSP0_IRQ                22
#define NVIC_M4_SSP1_IRQ                23
#define NVIC_M4_USART0_IRQ              24
#define NVIC_M4_UART1_IRQ               25
#define NVIC_M4_USART2_IRQ              26
#define NVIC_M4_USART3_IRQ              27
#define NVIC_M4_I2S0_IRQ                28
#define NVIC_M4_I2S1_IRQ                29
#define NVIC_M4_SPIFI_IRQ               30
#define NVIC_M4_SGPIO_IRQ               31
#define NVIC_M4_PIN_INT0_IRQ            32
#define NVIC_M4_PIN_INT1_IRQ            33
#define NVIC_M4_PIN_INT2_IRQ            34
#define NVIC_M4_PIN_INT3_IRQ            35
#define NVIC_M4_PIN_INT4_IRQ            36
#define NVIC_M4_PIN_INT5_IRQ            37
#define NVIC_M4_PIN_INT6_IRQ            38
#define NVIC_M4_PIN_INT7_IRQ            39
#define NVIC_M4_GINT0_IRQ               40
#define NVIC_M4_GINT1_IRQ               41
#define NVIC_M4_EVENTROUTER_IRQ         42
#define NVIC_M4_C_CAN1_IRQ              43
#define NVIC_M4_ATIMER_IRQ              46
#define NVIC_M4_RTC_IRQ                 47
#define NVIC_M4_WWDT_IRQ                49
#define NVIC_M4_C_CAN0_IRQ              51
#define NVIC_M4_QEI_IRQ                 52

/* LPC43xx M0 specific user interrupts */
//TODO

/* --- NVIC functions ------------------------------------------------------ */

BEGIN_DECLS

void nvic_enable_irq(u8 irqn);
void nvic_disable_irq(u8 irqn);
u8 nvic_get_pending_irq(u8 irqn);
void nvic_set_pending_irq(u8 irqn);
void nvic_clear_pending_irq(u8 irqn);
u8 nvic_get_active_irq(u8 irqn);
u8 nvic_get_irq_enabled(u8 irqn);
void nvic_set_priority(u8 irqn, u8 priority);
void nvic_generate_software_interrupt(u8 irqn);

END_DECLS

#endif
