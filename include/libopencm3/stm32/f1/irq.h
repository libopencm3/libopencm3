/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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

#ifndef LIBOPENCM3_STM32_F1_IRQ_H
#define LIBOPENCM3_STM32_F1_IRQ_H

#define IRQ_WWDG                  0
#define IRQ_PVD                   1
#define IRQ_TAMPER                2
#define IRQ_RTC                   3
#define IRQ_FLASH                 4
#define IRQ_RCC                   5
#define IRQ_EXTI0                 6
#define IRQ_EXTI1                 7
#define IRQ_EXTI2                 8
#define IRQ_EXTI3                 9
#define IRQ_EXTI4                10
#define IRQ_DMA1_CHANNEL1        11
#define IRQ_DMA1_CHANNEL2        12
#define IRQ_DMA1_CHANNEL3        13
#define IRQ_DMA1_CHANNEL4        14
#define IRQ_DMA1_CHANNEL5        15
#define IRQ_DMA1_CHANNEL6        16
#define IRQ_DMA1_CHANNEL7        17
#define IRQ_ADC1_2               18
#define IRQ_USB_HP_CAN_TX        19
#define IRQ_USB_LP_CAN_RX0       20
#define IRQ_CAN_RX1              21
#define IRQ_CAN_SCE              22
#define IRQ_EXTI9_5              23
#define IRQ_TIM1_BRK             24
#define IRQ_TIM1_UP              25
#define IRQ_TIM1_TRG_COM         26
#define IRQ_TIM1_CC              27
#define IRQ_TIM2                 28
#define IRQ_TIM3                 29
#define IRQ_TIM4                 30
#define IRQ_I2C1_EV              31
#define IRQ_I2C1_ER              32
#define IRQ_I2C2_EV              33
#define IRQ_I2C2_ER              34
#define IRQ_SPI1                 35
#define IRQ_SPI2                 36
#define IRQ_USART1               37
#define IRQ_USART2               38
#define IRQ_USART3               39
#define IRQ_EXTI15_10            40
#define IRQ_RTC_ALARM            41
#define IRQ_USB_WAKEUP           42
#define IRQ_TIM8_BRK             43
#define IRQ_TIM8_UP              44
#define IRQ_TIM8_TRG_COM         45
#define IRQ_TIM8_CC              46
#define IRQ_ADC3                 47
#define IRQ_FSMC                 48
#define IRQ_SDIO                 49
#define IRQ_TIM5                 50
#define IRQ_SPI3                 51
#define IRQ_UART4                52
#define IRQ_UART5                53
#define IRQ_TIM6                 54
#define IRQ_TIM7                 55
#define IRQ_DMA2_CHANNEL1        56
#define IRQ_DMA2_CHANNEL2        57
#define IRQ_DMA2_CHANNEL3        58
#define IRQ_DMA2_CHANNEL4_5      59
#define IRQ_DMA2_CHANNEL5        60
#define IRQ_ETH                  61
#define IRQ_ETH_WKUP             62
#define IRQ_CAN2_TX              63
#define IRQ_CAN2_RX0             64
#define IRQ_CAN2_RX1             65
#define IRQ_CAN2_SCE             66
#define IRQ_OTG_FS               67

/* FIXME: number from list in lib/stm32/f1/vector.c, might miss irqs */
#define IRQ_COUNT                68

#define WEAK __attribute__ ((weak))

void WEAK wwdg_isr(void);
void WEAK pvd_isr(void);
void WEAK tamper_isr(void);
void WEAK rtc_isr(void);
void WEAK flash_isr(void);
void WEAK rcc_isr(void);
void WEAK exti0_isr(void);
void WEAK exti1_isr(void);
void WEAK exti2_isr(void);
void WEAK exti3_isr(void);
void WEAK exti4_isr(void);
void WEAK dma1_channel1_isr(void);
void WEAK dma1_channel2_isr(void);
void WEAK dma1_channel3_isr(void);
void WEAK dma1_channel4_isr(void);
void WEAK dma1_channel5_isr(void);
void WEAK dma1_channel6_isr(void);
void WEAK dma1_channel7_isr(void);
void WEAK adc1_2_isr(void);
void WEAK usb_hp_can_tx_isr(void);
void WEAK usb_lp_can_rx0_isr(void);
void WEAK can_rx1_isr(void);
void WEAK can_sce_isr(void);
void WEAK exti9_5_isr(void);
void WEAK tim1_brk_isr(void);
void WEAK tim1_up_isr(void);
void WEAK tim1_trg_com_isr(void);
void WEAK tim1_cc_isr(void);
void WEAK tim2_isr(void);
void WEAK tim3_isr(void);
void WEAK tim4_isr(void);
void WEAK i2c1_ev_isr(void);
void WEAK i2c1_er_isr(void);
void WEAK i2c2_ev_isr(void);
void WEAK i2c2_er_isr(void);
void WEAK spi1_isr(void);
void WEAK spi2_isr(void);
void WEAK usart1_isr(void);
void WEAK usart2_isr(void);
void WEAK usart3_isr(void);
void WEAK exti15_10_isr(void);
void WEAK rtc_alarm_isr(void);
void WEAK usb_wakeup_isr(void);
void WEAK tim8_brk_isr(void);
void WEAK tim8_up_isr(void);
void WEAK tim8_trg_com_isr(void);
void WEAK tim8_cc_isr(void);
void WEAK adc3_isr(void);
void WEAK fsmc_isr(void);
void WEAK sdio_isr(void);
void WEAK tim5_isr(void);
void WEAK spi3_isr(void);
void WEAK uart4_isr(void);
void WEAK uart5_isr(void);
void WEAK tim6_isr(void);
void WEAK tim7_isr(void);
void WEAK dma2_channel1_isr(void);
void WEAK dma2_channel2_isr(void);
void WEAK dma2_channel3_isr(void);
void WEAK dma2_channel4_5_isr(void);
void WEAK dma2_channel5_isr(void);
void WEAK eth_isr(void);
void WEAK eth_wkup_isr(void);
void WEAK can2_tx_isr(void);
void WEAK can2_rx0_isr(void);
void WEAK can2_rx1_isr(void);
void WEAK can2_sce_isr(void);
void WEAK otg_fs_isr(void);

#pragma weak wwdg_isr = null_handler
#pragma weak pvd_isr = null_handler
#pragma weak tamper_isr = null_handler
#pragma weak rtc_isr = null_handler
#pragma weak flash_isr = null_handler
#pragma weak rcc_isr = null_handler
#pragma weak exti0_isr = null_handler
#pragma weak exti1_isr = null_handler
#pragma weak exti2_isr = null_handler
#pragma weak exti3_isr = null_handler
#pragma weak exti4_isr = null_handler
#pragma weak dma1_channel1_isr = null_handler
#pragma weak dma1_channel2_isr = null_handler
#pragma weak dma1_channel3_isr = null_handler
#pragma weak dma1_channel4_isr = null_handler
#pragma weak dma1_channel5_isr = null_handler
#pragma weak dma1_channel6_isr = null_handler
#pragma weak dma1_channel7_isr = null_handler
#pragma weak adc1_2_isr = null_handler
#pragma weak usb_hp_can_tx_isr = null_handler
#pragma weak usb_lp_can_rx0_isr = null_handler
#pragma weak can_rx1_isr = null_handler
#pragma weak can_sce_isr = null_handler
#pragma weak exti9_5_isr = null_handler
#pragma weak tim1_brk_isr = null_handler
#pragma weak tim1_up_isr = null_handler
#pragma weak tim1_trg_com_isr = null_handler
#pragma weak tim1_cc_isr = null_handler
#pragma weak tim2_isr = null_handler
#pragma weak tim3_isr = null_handler
#pragma weak tim4_isr = null_handler
#pragma weak i2c1_ev_isr = null_handler
#pragma weak i2c1_er_isr = null_handler
#pragma weak i2c2_ev_isr = null_handler
#pragma weak i2c2_er_isr = null_handler
#pragma weak spi1_isr = null_handler
#pragma weak spi2_isr = null_handler
#pragma weak usart1_isr = null_handler
#pragma weak usart2_isr = null_handler
#pragma weak usart3_isr = null_handler
#pragma weak exti15_10_isr = null_handler
#pragma weak rtc_alarm_isr = null_handler
#pragma weak usb_wakeup_isr = null_handler
#pragma weak tim8_brk_isr = null_handler
#pragma weak tim8_up_isr = null_handler
#pragma weak tim8_trg_com_isr = null_handler
#pragma weak tim8_cc_isr = null_handler
#pragma weak adc3_isr = null_handler
#pragma weak fsmc_isr = null_handler
#pragma weak sdio_isr = null_handler
#pragma weak tim5_isr = null_handler
#pragma weak spi3_isr = null_handler
#pragma weak uart4_isr = null_handler
#pragma weak uart5_isr = null_handler
#pragma weak tim6_isr = null_handler
#pragma weak tim7_isr = null_handler
#pragma weak dma2_channel1_isr = null_handler
#pragma weak dma2_channel2_isr = null_handler
#pragma weak dma2_channel3_isr = null_handler
#pragma weak dma2_channel4_5_isr = null_handler
#pragma weak dma2_channel5_isr
#pragma weak eth_isr = null_handler
#pragma weak eth_wkup_isr = null_handler
#pragma weak can2_tx_isr = null_handler
#pragma weak can2_rx0_isr = null_handler
#pragma weak can2_rx1_isr = null_handler
#pragma weak can2_sce_isr = null_handler
#pragma weak otg_fs_isr = null_handler

#define IRQ_HANDLERS \
	wwdg_isr, \
	pvd_isr, \
	tamper_isr, \
	rtc_isr, \
	flash_isr, \
	rcc_isr, \
	exti0_isr, \
	exti1_isr, \
	exti2_isr, \
	exti3_isr, \
	exti4_isr, \
	dma1_channel1_isr, \
	dma1_channel2_isr, \
	dma1_channel3_isr, \
	dma1_channel4_isr, \
	dma1_channel5_isr, \
	dma1_channel6_isr, \
	dma1_channel7_isr, \
	adc1_2_isr, \
	usb_hp_can_tx_isr, \
	usb_lp_can_rx0_isr, \
	can_rx1_isr, \
	can_sce_isr, \
	exti9_5_isr, \
	tim1_brk_isr, \
	tim1_up_isr, \
	tim1_trg_com_isr, \
	tim1_cc_isr, \
	tim2_isr, \
	tim3_isr, \
	tim4_isr, \
	i2c1_ev_isr, \
	i2c1_er_isr, \
	i2c2_ev_isr, \
	i2c2_er_isr, \
	spi1_isr, \
	spi2_isr, \
	usart1_isr, \
	usart2_isr, \
	usart3_isr, \
	exti15_10_isr, \
	rtc_alarm_isr, \
	usb_wakeup_isr, \
	tim8_brk_isr, \
	tim8_up_isr, \
	tim8_trg_com_isr, \
	tim8_cc_isr, \
	adc3_isr, \
	fsmc_isr, \
	sdio_isr, \
	tim5_isr, \
	spi3_isr, \
	uart4_isr, \
	uart5_isr, \
	tim6_isr, \
	tim7_isr, \
	dma2_channel1_isr, \
	dma2_channel2_isr, \
	dma2_channel3_isr, \
	dma2_channel4_5_isr, \
	dma2_channel5_isr, \
	eth_isr, \
	eth_wkup_isr, \
	can2_tx_isr, \
	can2_rx0_isr, \
	can2_rx1_isr, \
	can2_sce_isr, \
	otg_fs_isr, \

#endif
