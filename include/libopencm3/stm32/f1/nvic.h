/*
 * This file is part of the libopencm3 project.
 *
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

#ifndef LIBOPENCM3_NVIC_H
#define LIBOPENCM3_NVIC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- NVIC Registers ------------------------------------------------------ */

/* ISER: Interrupt Set Enable Registers */
/* Note: 8 32bit Registers */
#define NVIC_ISER(iser_id)              MMIO32(NVIC_BASE + 0x00 + (iser_id * 4))

/* NVIC_BASE + 0x020 (0xE000 E120 - 0xE000 E17F): Reserved */

/* ICER: Interrupt Clear Enable Registers */
/* Note: 8 32bit Registers */
#define NVIC_ICER(icer_id)              MMIO32(NVIC_BASE + 0x80 + (icer_id * 4))

/* NVIC_BASE + 0x0A0 (0xE000 E1A0 - 0xE000 E1FF): Reserved */

/* ISPR: Interrupt Set Pending Registers */
/* Note: 8 32bit Registers */
#define NVIC_ISPR(ispr_id)              MMIO32(NVIC_BASE + 0x100 + (ispr_id * 4))

/* NVIC_BASE + 0x120 (0xE000 E220 - 0xE000 E27F): Reserved */

/* ICPR: Interrupt Clear Pending Registers */
/* Note: 8 32bit Registers */
#define NVIC_ICPR(icpr_id)              MMIO32(NVIC_BASE + 0x180 + (icpr_id * 4))

/* NVIC_BASE + 0x1A0 (0xE000 E2A0 - 0xE00 E2FF): Reserved */

/* IABR: Interrupt Active Bit Register */
/* Note: 8 32bit Registers */
#define NVIC_IABR(iabr_id)              MMIO32(NVIC_BASE + 0x200 + (iabr_id * 4))

/* NVIC_BASE + 0x220 (0xE000 E320 - 0xE000 E3FF): Reserved */

/* IPR: Interrupt Priority Registers */
/* Note: 240 8bit Registers */
#define NVIC_IPR(ipr_id)                MMIO8(NVIC_BASE + 0x300 + ipr_id)

/* STIR: Software Trigger Interrupt Register */
#define NVIC_STIR                       MMIO32(STIR_BASE)

/* --- IRQ channel numbers-------------------------------------------------- */

/* Cortex M3 System Interrupts */
#define NVIC_NMI_IRQ			-14
#define NVIC_HARD_FAULT_IRQ		-13
#define NVIC_MEM_MANAGE_IRQ		-12
#define NVIC_BUS_FAULT_IRQ		-11
#define NVIC_USAGE_FAULT_IRQ		-10
/* irq numbers -6 to -9 are reserved */
#define NVIC_SV_CALL_IRQ		-5
#define DEBUG_MONITOR_IRQ		-4
/* irq number -3 reserved */
#define NVIC_PENDSV_IRQ			-2
#define NVIC_SYSTICK_IRQ		-1

/* User Interrupts */
#define NVIC_WWDG_IRQ			0
#define NVIC_PVD_IRQ			1
#define NVIC_TAMPER_IRQ			2
#define NVIC_RTC_IRQ			3
#define NVIC_FLASH_IRQ			4
#define NVIC_RCC_IRQ			5
#define NVIC_EXTI0_IRQ			6
#define NVIC_EXTI1_IRQ			7
#define NVIC_EXTI2_IRQ			8
#define NVIC_EXTI3_IRQ			9
#define NVIC_EXTI4_IRQ			10
#define NVIC_DMA1_CHANNEL1_IRQ		11
#define NVIC_DMA1_CHANNEL2_IRQ		12
#define NVIC_DMA1_CHANNEL3_IRQ		13
#define NVIC_DMA1_CHANNEL4_IRQ		14
#define NVIC_DMA1_CHANNEL5_IRQ		15
#define NVIC_DMA1_CHANNEL6_IRQ		16
#define NVIC_DMA1_CHANNEL7_IRQ		17
#define NVIC_ADC1_2_IRQ			18
#define NVIC_USB_HP_CAN_TX_IRQ		19
#define NVIC_USB_LP_CAN_RX0_IRQ		20
#define NVIC_CAN_RX1_IRQ		21
#define NVIC_CAN_SCE_IRQ		22
#define NVIC_EXTI9_5_IRQ		23
#define NVIC_TIM1_BRK_IRQ		24
#define NVIC_TIM1_UP_IRQ		25
#define NVIC_TIM1_TRG_COM_IRQ		26
#define NVIC_TIM1_CC_IRQ		27
#define NVIC_TIM2_IRQ			28
#define NVIC_TIM3_IRQ			29
#define NVIC_TIM4_IRQ			30
#define NVIC_I2C1_EV_IRQ		31
#define NVIC_I2C1_ER_IRQ		32
#define NVIC_I2C2_EV_IRQ		33
#define NVIC_I2C2_ER_IRQ		34
#define NVIC_SPI1_IRQ			35
#define NVIC_SPI2_IRQ			36
#define NVIC_USART1_IRQ			37
#define NVIC_USART2_IRQ			38
#define NVIC_USART3_IRQ			39
#define NVIC_EXTI15_10_IRQ		40
#define NVIC_RTC_ALARM_IRQ		41
#define NVIC_USB_WAKEUP_IRQ		42
#define NVIC_TIM8_BRK_IRQ		43
#define NVIC_TIM8_UP_IRQ		44
#define NVIC_TIM8_TRG_COM_IRQ		45
#define NVIC_TIM8_CC_IRQ		46
#define NVIC_ADC3_IRQ			47
#define NVIC_FSMC_IRQ			48
#define NVIC_SDIO_IRQ			49
#define NVIC_TIM5_IRQ			50
#define NVIC_SPI3_IRQ			51
#define NVIC_USART4_IRQ			52
#define NVIC_USART5_IRQ			53
#define NVIC_TIM6_IRQ			54
#define NVIC_TIM7_IRQ			55
#define NVIC_DMA2_CHANNEL1_IRQ		56
#define NVIC_DMA2_CHANNEL2_IRQ		57
#define NVIC_DMA2_CHANNEL3_IRQ		58
#define NVIC_DMA2_CHANNEL4_5_IRQ	59
#define NVIC_DMA2_CHANNEL5_IRQ		60
#define NVIC_ETH_IRQ			61
#define NVIC_ETH_WKUP_IRQ		62
#define NVIC_CAN2_TX_IRQ		63
#define NVIC_CAN2_RX0_IRQ		64
#define NVIC_CAN2_RX1_IRQ		65
#define NVIC_CAN2_SCE_IRQ		66
#define NVIC_OTG_FS_IRQ			67

/* --- NVIC functions ------------------------------------------------------ */

void nvic_enable_irq(u8 irqn);
void nvic_disable_irq(u8 irqn);
u8 nvic_get_pending_irq(u8 irqn);
void nvic_set_pending_irq(u8 irqn);
void nvic_clear_pending_irq(u8 irqn);
u8 nvic_get_active_irq(u8 irqn);
u8 nvic_get_irq_enabled(u8 irqn);
void nvic_set_priority(u8 irqn, u8 priority);
void nvic_generate_software_interrupt(u8 irqn);

#endif
