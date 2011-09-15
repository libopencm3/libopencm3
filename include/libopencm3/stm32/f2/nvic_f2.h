/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_NVIC_F2_H
#define LIBOPENCM3_NVIC_F2_H

/* --- IRQ channel numbers-------------------------------------------------- */

/* Note: These F2 specific user interrupt definitions supplement the
 * general NVIC definitions in ../nvic.h
 */

/* User Interrupts */
#define NVIC_WWDG_IRQ          0
#define PVD_IRQ                1
#define TAMP_STAMP_IRQ         2
#define RTC_WKUP_IRQ           3
#define FLASH_IRQ              4
#define RCC_IRQ                5
#define EXTI0_IRQ              6
#define EXTI1_IRQ              7
#define EXTI2_IRQ              8
#define EXTI3_IRQ              9
#define EXTI4_IRQ              10
#define DMA1_STREAM0_IRQ       11
#define DMA1_STREAM1_IRQ       12
#define DMA1_STREAM2_IRQ       13
#define DMA1_STREAM3_IRQ       14
#define DMA1_STREAM4_IRQ       15
#define DMA1_STREAM5_IRQ       16
#define DMA1_STREAM6_IRQ       17
#define ADC_IRQ                18
#define CAN1_TX_IRQ            19
#define CAN1_RX0_IRQ           20
#define CAN1_RX1_IRQ           21
#define CAN1_SCE_IRQ           22
#define EXTI9_5_IRQ            23
#define TIM1_BRK_TIM9_IRQ      24
#define TIM1_UP_TIM10_IRQ      25
#define TIM1_TRG_COM_TIM11_IRQ 26
#define TIM1_CC_IRQ            27
#define TIM2_IRQ               28
#define TIM3_IRQ               29
#define TIM4_IRQ               30
#define I2C1_EV_IRQ            31
#define I2C1_ER_IRQ            32
#define I2C2_EV_IRQ            33
#define I2C2_ER_IRQ            34
#define SPI1_IRQ               35
#define SPI2_IRQ               36
#define USART1_IRQ             37
#define USART2_IRQ             38
#define USART3_IRQ             39
#define EXTI15_10_IRQ          40
#define RTC_ALARM_IRQ          41
#define USB_FS_WKUP_IRQ        42
#define TIM8_BRK_TIM12_IRQ     43
#define TIM8_UP_TIM13_IRQ      44
#define TIM8_TRG_COM_TIM14_IRQ 45
#define TIM8_CC_IRQ            46
#define DMA1_STREAM7_IRQ       47
#define FSMC_IRQ               48
#define SDIO_IRQ               49
#define TIM5_IRQ               50
#define SPI3_IRQ               51
#define USART4_IRQ             52
#define USART5_IRQ             53
#define TIM6_DAC_IRQ           54
#define TIM7_IRQ               55
#define DMA2_STREAM0_IRQ       56
#define DMA2_STREAM1_IRQ       57
#define DMA2_STREAM2_IRQ       58
#define DMA2_STREAM3_IRQ       59
#define DMA2_STREAM4_IRQ       60
#define ETH_IRQ                61
#define ETH_WKUP_IRQ           62
#define CAN2_TX_IRQ            63
#define CAN2_RX0_IRQ           64
#define CAN2_RX1_IRQ           65
#define CAN2_SCE_IRQ           66
#define OTG_FS_IRQ             67
#define DMA2_STREAM5_IRQ       68
#define DMA2_STREAM6_IRQ       69
#define DMA2_STREAM7_IRQ       70
#define USART6_IRQ             71
#define I2C3_EV_IRQ            72
#define I2C3_ER_IRQ            73
#define OTG_HS_EP1_OUT_IRQ     74
#define OTG_HS_EP1_IN_IRQ      75
#define OTG_HS_WKUP_IRQ        76
#define OTG_HS_IRQ             77
#define DCMI_IRQ               78
#define CRYP_IRQ               79
#define HASH_RNG_IRQ           80

#endif
