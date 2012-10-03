/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_STM32_F4_IRQ_H
#define LIBOPENCM3_STM32_F4_IRQ_H

#define IRQ_WWDG                  0
#define IRQ_PVD                   1
#define IRQ_TAMP_STAMP            2
#define IRQ_RTC_WKUP              3
#define IRQ_FLASH                 4
#define IRQ_RCC                   5
#define IRQ_EXTI0                 6
#define IRQ_EXTI1                 7
#define IRQ_EXTI2                 8
#define IRQ_EXTI3                 9
#define IRQ_EXTI4                10
#define IRQ_DMA1_STREAM0         11
#define IRQ_DMA1_STREAM1         12
#define IRQ_DMA1_STREAM2         13
#define IRQ_DMA1_STREAM3         14
#define IRQ_DMA1_STREAM4         15
#define IRQ_DMA1_STREAM5         16
#define IRQ_DMA1_STREAM6         17
#define IRQ_ADC                  18
#define IRQ_CAN1_TX              19
#define IRQ_CAN1_RX0             20
#define IRQ_CAN1_RX1             21
#define IRQ_CAN1_SCE             22
#define IRQ_EXTI9_5              23
#define IRQ_TIM1_BRK_TIM9        24
#define IRQ_TIM1_UP_TIM10        25
#define IRQ_TIM1_TRG_COM_TIM11   26
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
#define IRQ_USB_FS_WKUP          42
#define IRQ_TIM8_BRK_TIM12       43
#define IRQ_TIM8_UP_TIM13        44
#define IRQ_TIM8_TRG_COM_TIM14   45
#define IRQ_TIM8_CC              46
#define IRQ_DMA1_STREAM7         47
#define IRQ_FSMC                 48
#define IRQ_SDIO                 49
#define IRQ_TIM5                 50
#define IRQ_SPI3                 51
#define IRQ_UART4                52
#define IRQ_UART5                53
#define IRQ_TIM6_DAC             54
#define IRQ_TIM7                 55
#define IRQ_DMA2_STREAM0         56
#define IRQ_DMA2_STREAM1         57
#define IRQ_DMA2_STREAM2         58
#define IRQ_DMA2_STREAM3         59
#define IRQ_DMA2_STREAM4         60
#define IRQ_ETH                  61
#define IRQ_ETH_WKUP             62
#define IRQ_CAN2_TX              63
#define IRQ_CAN2_RX0             64
#define IRQ_CAN2_RX1             65
#define IRQ_CAN2_SCE             66
#define IRQ_OTG_FS               67
#define IRQ_DMA2_STREAM5         68
#define IRQ_DMA2_STREAM6         69
#define IRQ_DMA2_STREAM7         70
#define IRQ_USART6               71
#define IRQ_I2C3_EV              72
#define IRQ_I2C3_ER              73
#define IRQ_OTG_HS_EP1_OUT       74
#define IRQ_OTG_HS_EP1_IN        75
#define IRQ_OTG_HS_WKUP          76
#define IRQ_OTG_HS               77
#define IRQ_DCMI                 78
#define IRQ_CRYP                 79
#define IRQ_HASH_RNG             80

/* FIXME: number from list in lib/stm32/f4/vector.c, might miss irqs */
#define IRQ_COUNT                81

#define WEAK __attribute__ ((weak))

void WEAK wwdg_isr(void);
void WEAK pvd_isr(void);
void WEAK tamp_stamp_isr(void);
void WEAK rtc_wkup_isr(void);
void WEAK flash_isr(void);
void WEAK rcc_isr(void);
void WEAK exti0_isr(void);
void WEAK exti1_isr(void);
void WEAK exti2_isr(void);
void WEAK exti3_isr(void);
void WEAK exti4_isr(void);
void WEAK dma1_stream0_isr(void);
void WEAK dma1_stream1_isr(void);
void WEAK dma1_stream2_isr(void);
void WEAK dma1_stream3_isr(void);
void WEAK dma1_stream4_isr(void);
void WEAK dma1_stream5_isr(void);
void WEAK dma1_stream6_isr(void);
void WEAK adc_isr(void);
void WEAK can1_tx_isr(void);
void WEAK can1_rx0_isr(void);
void WEAK can1_rx1_isr(void);
void WEAK can1_sce_isr(void);
void WEAK exti9_5_isr(void);
void WEAK tim1_brk_tim9_isr(void);
void WEAK tim1_up_tim10_isr(void);
void WEAK tim1_trg_com_tim11_isr(void);
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
void WEAK usb_fs_wkup_isr(void);
void WEAK tim8_brk_tim12_isr(void);
void WEAK tim8_up_tim13_isr(void);
void WEAK tim8_trg_com_tim14_isr(void);
void WEAK tim8_cc_isr(void);
void WEAK dma1_stream7_isr(void);
void WEAK fsmc_isr(void);
void WEAK sdio_isr(void);
void WEAK tim5_isr(void);
void WEAK spi3_isr(void);
void WEAK uart4_isr(void);
void WEAK uart5_isr(void);
void WEAK tim6_dac_isr(void);
void WEAK tim7_isr(void);
void WEAK dma2_stream0_isr(void);
void WEAK dma2_stream1_isr(void);
void WEAK dma2_stream2_isr(void);
void WEAK dma2_stream3_isr(void);
void WEAK dma2_stream4_isr(void);
void WEAK eth_isr(void);
void WEAK eth_wkup_isr(void);
void WEAK can2_tx_isr(void);
void WEAK can2_rx0_isr(void);
void WEAK can2_rx1_isr(void);
void WEAK can2_sce_isr(void);
void WEAK otg_fs_isr(void);
void WEAK dma2_stream5_isr(void);
void WEAK dma2_stream6_isr(void);
void WEAK dma2_stream7_isr(void);
void WEAK usart6_isr(void);
void WEAK i2c3_ev_isr(void);
void WEAK i2c3_er_isr(void);
void WEAK otg_hs_ep1_out_isr(void);
void WEAK otg_hs_ep1_in_isr(void);
void WEAK otg_hs_wkup_isr(void);
void WEAK otg_hs_isr(void);
void WEAK dcmi_isr(void);
void WEAK cryp_isr(void);
void WEAK hash_rng_isr(void);

#pragma weak wwdg_isr = null_handler
#pragma weak pvd_isr = null_handler
#pragma weak tamp_stamp_isr = null_handler
#pragma weak rtc_wkup_isr = null_handler
#pragma weak flash_isr = null_handler
#pragma weak rcc_isr = null_handler
#pragma weak exti0_isr = null_handler
#pragma weak exti1_isr = null_handler
#pragma weak exti2_isr = null_handler
#pragma weak exti3_isr = null_handler
#pragma weak exti4_isr = null_handler
#pragma weak dma1_stream0_isr = null_handler
#pragma weak dma1_stream1_isr = null_handler
#pragma weak dma1_stream2_isr = null_handler
#pragma weak dma1_stream3_isr = null_handler
#pragma weak dma1_stream4_isr = null_handler
#pragma weak dma1_stream5_isr = null_handler
#pragma weak dma1_stream6_isr = null_handler
#pragma weak adc_isr = null_handler
#pragma weak can1_tx_isr = null_handler
#pragma weak can1_rx0_isr = null_handler
#pragma weak can1_rx1_isr = null_handler
#pragma weak can1_sce_isr = null_handler
#pragma weak exti9_5_isr = null_handler
#pragma weak tim1_brk_tim9_isr = null_handler
#pragma weak tim1_up_tim10_isr = null_handler
#pragma weak tim1_trg_com_tim11_isr = null_handler
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
#pragma weak usb_fs_wkup_isr = null_handler
#pragma weak tim8_brk_tim12_isr = null_handler
#pragma weak tim8_up_tim13_isr = null_handler
#pragma weak tim8_trg_com_tim14_isr = null_handler
#pragma weak tim8_cc_isr = null_handler
#pragma weak dma1_stream7_isr = null_handler
#pragma weak fsmc_isr = null_handler
#pragma weak sdio_isr = null_handler
#pragma weak tim5_isr = null_handler
#pragma weak spi3_isr = null_handler
#pragma weak uart4_isr = null_handler
#pragma weak uart5_isr = null_handler
#pragma weak tim6_dac_isr = null_handler
#pragma weak tim7_isr = null_handler
#pragma weak dma2_stream0_isr = null_handler
#pragma weak dma2_stream1_isr = null_handler
#pragma weak dma2_stream2_isr = null_handler
#pragma weak dma2_stream3_isr = null_handler
#pragma weak dma2_stream4_isr = null_handler
#pragma weak eth_isr = null_handler
#pragma weak eth_wkup_isr = null_handler
#pragma weak can2_tx_isr = null_handler
#pragma weak can2_rx0_isr = null_handler
#pragma weak can2_rx1_isr = null_handler
#pragma weak can2_sce_isr = null_handler
#pragma weak otg_fs_isr = null_handler
#pragma weak dma2_stream5_isr = null_handler
#pragma weak dma2_stream6_isr = null_handler
#pragma weak dma2_stream7_isr = null_handler
#pragma weak usart6_isr = null_handler
#pragma weak i2c3_ev_isr = null_handler
#pragma weak i2c3_er_isr = null_handler
#pragma weak otg_hs_ep1_out_isr = null_handler
#pragma weak otg_hs_ep1_in_isr = null_handler
#pragma weak otg_hs_wkup_isr = null_handler
#pragma weak otg_hs_isr = null_handler
#pragma weak dcmi_isr = null_handler
#pragma weak cryp_isr = null_handler
#pragma weak hash_rng_isr = null_handler

#define IRQ_HANDLERS \
	wwdg_isr, \
	pvd_isr, \
	tamp_stamp_isr, \
	rtc_wkup_isr, \
	flash_isr, \
	rcc_isr, \
	exti0_isr, \
	exti1_isr, \
	exti2_isr, \
	exti3_isr, \
	exti4_isr, \
	dma1_stream0_isr, \
	dma1_stream1_isr, \
	dma1_stream2_isr, \
	dma1_stream3_isr, \
	dma1_stream4_isr, \
	dma1_stream5_isr, \
	dma1_stream6_isr, \
	adc_isr, \
	can1_tx_isr, \
	can1_rx0_isr, \
	can1_rx1_isr, \
	can1_sce_isr, \
	exti9_5_isr, \
	tim1_brk_tim9_isr, \
	tim1_up_tim10_isr, \
	tim1_trg_com_tim11_isr, \
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
	usb_fs_wkup_isr, \
	tim8_brk_tim12_isr, \
	tim8_up_tim13_isr, \
	tim8_trg_com_tim14_isr, \
	tim8_cc_isr, \
	dma1_stream7_isr, \
	fsmc_isr, \
	sdio_isr, \
	tim5_isr, \
	spi3_isr, \
	uart4_isr, \
	uart5_isr, \
	tim6_dac_isr, \
	tim7_isr, \
	dma2_stream0_isr, \
	dma2_stream1_isr, \
	dma2_stream2_isr, \
	dma2_stream3_isr, \
	dma2_stream4_isr, \
	eth_isr, \
	eth_wkup_isr, \
	can2_tx_isr, \
	can2_rx0_isr, \
	can2_rx1_isr, \
	can2_sce_isr, \
	otg_fs_isr, \
	dma2_stream5_isr, \
	dma2_stream6_isr, \
	dma2_stream7_isr, \
	usart6_isr, \
	i2c3_ev_isr, \
	i2c3_er_isr, \
	otg_hs_ep1_out_isr, \
	otg_hs_ep1_in_isr, \
	otg_hs_wkup_isr, \
	otg_hs_isr, \
	dcmi_isr, \
	cryp_isr, \
	hash_rng_isr,

#endif
