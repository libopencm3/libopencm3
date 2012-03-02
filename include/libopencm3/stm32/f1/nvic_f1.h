/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

#ifndef LIBOPENCM3_NVIC_F1_H
#define LIBOPENCM3_NVIC_F1_H

/* --- IRQ channel numbers-------------------------------------------------- */

/* Note: These F1 specific user interrupt definitions supplement the
 * general NVIC definitions in ../nvic.h
 */

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
#define NVIC_UART4_IRQ			52
#define NVIC_UART5_IRQ			53
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

#endif
