/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* GPIO port base addresses (for convenience) */
#define GPIOA				GPIO_PORT_A_BASE
#define GPIOB				GPIO_PORT_B_BASE
#define GPIOC				GPIO_PORT_C_BASE
#define GPIOD				GPIO_PORT_D_BASE
#define GPIOE				GPIO_PORT_E_BASE
#define GPIOF				GPIO_PORT_F_BASE
#define GPIOG				GPIO_PORT_G_BASE

/* GPIO number definitions (for convenience) */
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO8				(1 << 8)
#define GPIO9				(1 << 9)
#define GPIO10				(1 << 10)
#define GPIO11				(1 << 11)
#define GPIO12				(1 << 12)
#define GPIO13				(1 << 13)
#define GPIO14				(1 << 14)
#define GPIO15				(1 << 15)
#define GPIO_ALL			0xffff

/* --- Alternate function GPIOs -------------------------------------------- */

/* Default alternate functions of some pins (with and without remapping) */

/* CAN1 / CAN */
#define GPIO_CAN1_RX			GPIO11		/* PA11 */
#define GPIO_CAN1_TX			GPIO12		/* PA12 */
#define GPIO_CAN_RX			GPIO_CAN1_RX	/* Alias */
#define GPIO_CAN_TX			GPIO_CAN1_TX	/* Alias */

#define GPIO_CAN_PB_RX                  GPIO8           /* PB8 */
#define GPIO_CAN_PB_TX                  GPIO9           /* PB9 */
#define GPIO_CAN1_PB_RX                 GPIO_CAN_PB_RX  /* Alias */
#define GPIO_CAN1_PB_TX                 GPIO_CAN_PB_TX  /* Alias */

#define GPIO_CAN_PD_RX                  GPIO0           /* PD0 */
#define GPIO_CAN_PD_TX                  GPIO1           /* PD1 */
#define GPIO_CAN1_PD_RX                 GPIO_CAN_PD_RX  /* Alias */
#define GPIO_CAN1_PD_TX                 GPIO_CAN_PD_TX  /* Alias */

/* CAN2 */
#define GPIO_CAN2_RX			GPIO12		/* PB12 */
#define GPIO_CAN2_TX			GPIO13		/* PB13 */

#define GPIO_CAN2_RE_RX                 GPIO5           /* PB5 */
#define GPIO_CAN2_RE_TX                 GPIO6           /* PB6 */

/* JTAG/SWD */
#define GPIO_JTMS_SWDIO			GPIO13		/* PA13 */
#define GPIO_JTCK_SWCLK			GPIO14		/* PA14 */
#define GPIO_JTDI			GPIO15		/* PA15 */
#define GPIO_JTDO_TRACESWO		GPIO3		/* PB3 */
#define GPIO_JNTRST			GPIO4		/* PB4 */
#define GPIO_TRACECK			GPIO2		/* PE2 */
#define GPIO_TRACED0			GPIO3		/* PE3 */
#define GPIO_TRACED1			GPIO4		/* PE4 */
#define GPIO_TRACED2			GPIO5		/* PE5 */
#define GPIO_TRACED3			GPIO6		/* PE6 */

/* Timer5 */
#define GPIO_TIM5_CH4			GPIO3		/* PA3 */

/* Timer4 */
#define GPIO_TIM4_CH1			GPIO6		/* PB6 */
#define GPIO_TIM4_CH2			GPIO7		/* PB7 */
#define GPIO_TIM4_CH3			GPIO8		/* PB8 */
#define GPIO_TIM4_CH4			GPIO9		/* PB9 */

#define GPIO_TIM4_RE_CH1		GPIO12		/* PD12 */
#define GPIO_TIM4_RE_CH2		GPIO13		/* PD13 */
#define GPIO_TIM4_RE_CH3		GPIO14		/* PD14 */
#define GPIO_TIM4_RE_CH4		GPIO15		/* PD15 */

/* Timer3 */
#define GPIO_TIM3_CH1			GPIO6		/* PA6 */
#define GPIO_TIM3_CH2			GPIO7		/* PA7 */
#define GPIO_TIM3_CH3			GPIO0		/* PB0 */
#define GPIO_TIM3_CH4			GPIO1		/* PB1 */

#define GPIO_TIM3_PR_CH1		GPIO4		/* PB4 */
#define GPIO_TIM3_PR_CH2		GPIO5		/* PB5 */
#define GPIO_TIM3_PR_CH3		GPIO0		/* PB0 */
#define GPIO_TIM3_PR_CH4		GPIO1		/* PB1 */

#define GPIO_TIM3_FR_CH1		GPIO6		/* PC6 */
#define GPIO_TIM3_FR_CH2		GPIO7		/* PC7 */
#define GPIO_TIM3_FR_CH3		GPIO8		/* PC8 */
#define GPIO_TIM3_FR_CH4		GPIO9		/* PC9 */

/* Timer2 */
#define GPIO_TIM2_CH1_ETR		GPIO0		/* PA0 */
#define GPIO_TIM2_CH2			GPIO1		/* PA1 */
#define GPIO_TIM2_CH3			GPIO2		/* PA2 */
#define GPIO_TIM2_CH4			GPIO3		/* PA3 */

#define GPIO_TIM2_PR1_CH1_ETR		GPIO15		/* PA15 */
#define GPIO_TIM2_PR1_CH2		GPIO3		/* PB3 */
#define GPIO_TIM2_PR1_CH3		GPIO2		/* PA2 */
#define GPIO_TIM2_PR1_CH4		GPIO3		/* PA3 */

#define GPIO_TIM2_PR2_CH1_ETR		GPIO0		/* PA0 */
#define GPIO_TIM2_PR2_CH2		GPIO1		/* PA1 */
#define GPIO_TIM2_PR2_CH3		GPIO10		/* PB10 */
#define GPIO_TIM2_PR2_CH4		GPIO11		/* PB11 */

#define GPIO_TIM2_FR_CH1_ETR		GPIO15		/* PA15 */
#define GPIO_TIM2_FR_CH2		GPIO3		/* PB3 */
#define GPIO_TIM2_FR_CH3		GPIO10		/* PB10 */
#define GPIO_TIM2_FR_CH4		GPIO11		/* PB11 */

/* Timer1 */
#define GPIO_TIM1_ETR			GPIO12		/* PA12 */
#define GPIO_TIM1_CH1			GPIO8		/* PA8 */
#define GPIO_TIM1_CH2			GPIO9		/* PA9 */
#define GPIO_TIM1_CH3			GPIO10		/* PA10 */
#define GPIO_TIM1_CH4			GPIO11		/* PA11 */
#define GPIO_TIM1_BKIN			GPIO12		/* PB12 */
#define GPIO_TIM1_CH1N			GPIO13		/* PB13 */
#define GPIO_TIM1_CH2N			GPIO14		/* PB14 */
#define GPIO_TIM1_CH3N			GPIO15		/* PB15 */

#define GPIO_TIM1_PR_ETR		GPIO12		/* PA12 */
#define GPIO_TIM1_PR_CH1		GPIO8		/* PA8 */
#define GPIO_TIM1_PR_CH2		GPIO9		/* PA9 */
#define GPIO_TIM1_PR_CH3		GPIO10		/* PA10 */
#define GPIO_TIM1_PR_CH4		GPIO11		/* PA11 */
#define GPIO_TIM1_PR_BKIN		GPIO6		/* PA6 */
#define GPIO_TIM1_PR_CH1N		GPIO7		/* PA7 */
#define GPIO_TIM1_PR_CH2N		GPIO0		/* PB0 */
#define GPIO_TIM1_PR_CH3N		GPIO1		/* PB1 */

#define GPIO_TIM1_FR_ETR		GPIO7		/* PE7 */
#define GPIO_TIM1_FR_CH1		GPIO9		/* PE9 */
#define GPIO_TIM1_FR_CH2		GPIO11		/* PE11 */
#define GPIO_TIM1_FR_CH3		GPIO13		/* PE13 */
#define GPIO_TIM1_FR_CH4		GPIO14		/* PE14 */
#define GPIO_TIM1_FR_BKIN		GPIO15		/* PE15 */
#define GPIO_TIM1_FR_CH1N		GPIO8		/* PE8 */
#define GPIO_TIM1_FR_CH2N		GPIO10		/* PE10 */
#define GPIO_TIM1_FR_CH3N		GPIO12		/* PE12 */

/* USART3 */
#define GPIO_USART3_TX			GPIO10		/* PB10 */
#define GPIO_USART3_RX			GPIO11		/* PB11 */
#define GPIO_USART3_CK			GPIO12		/* PB12 */
#define GPIO_USART3_CTS			GPIO13		/* PB13 */
#define GPIO_USART3_RTS			GPIO14		/* PB14 */

#define GPIO_USART3_PR_TX		GPIO10		/* PC10 */
#define GPIO_USART3_PR_RX		GPIO11		/* PC11 */
#define GPIO_USART3_PR_CK		GPIO12		/* PC12 */
#define GPIO_USART3_PR_CTS		GPIO13		/* PB13 */
#define GPIO_USART3_PR_RTS		GPIO14		/* PB14 */

#define GPIO_USART3_FR_TX		GPIO8		/* PD8 */
#define GPIO_USART3_FR_RX		GPIO9		/* PD9 */
#define GPIO_USART3_FR_CK		GPIO10		/* PD10 */
#define GPIO_USART3_FR_CTS		GPIO11		/* PD11 */
#define GPIO_USART3_FR_RTS		GPIO12		/* PD12 */

/* USART2 */
#define GPIO_USART2_CTS			GPIO0		/* PA0 */
#define GPIO_USART2_RTS			GPIO1		/* PA1 */
#define GPIO_USART2_TX			GPIO2		/* PA2 */
#define GPIO_USART2_RX			GPIO3		/* PA3 */
#define GPIO_USART2_CK			GPIO4		/* PA4 */

#define GPIO_USART2_RE_CTS		GPIO3		/* PD3 */
#define GPIO_USART2_RE_RTS		GPIO4		/* PD4 */
#define GPIO_USART2_RE_TX		GPIO5		/* PD5 */
#define GPIO_USART2_RE_RX		GPIO6		/* PD6 */
#define GPIO_USART2_RE_CK		GPIO7		/* PD7 */

/* USART1 */
#define GPIO_USART1_TX			GPIO9		/* PA9 */
#define GPIO_USART1_RX			GPIO10		/* PA10 */

#define GPIO_USART1_RE_TX		GPIO6		/* PB6 */
#define GPIO_USART1_RE_RX		GPIO7		/* PB7 */

/* I2C1 */
#define GPIO_I2C1_SMBAI			GPIO5		/* PB5 */
#define GPIO_I2C1_SCL			GPIO6		/* PB6 */
#define GPIO_I2C1_SDA			GPIO7		/* PB7 */

#define GPIO_I2C1_RE_SMBAI		GPIO5		/* PB5 */
#define GPIO_I2C1_RE_SCL		GPIO8		/* PB8 */
#define GPIO_I2C1_RE_SDA		GPIO9		/* PB9 */

/* I2C2 */
#define GPIO_I2C2_SCL			GPIO10		/* PB10 */
#define GPIO_I2C2_SDA			GPIO11		/* PB11 */
#define GPIO_I2C2_SMBAI			GPIO12		/* PB12 */

/* SPI1 */
#define GPIO_SPI1_NSS			GPIO4		/* PA4 */
#define GPIO_SPI1_SCK			GPIO5		/* PA5 */
#define GPIO_SPI1_MISO			GPIO6		/* PA6 */
#define GPIO_SPI1_MOSI			GPIO7		/* PA7 */

#define GPIO_SPI1_RE_NSS		GPIO15		/* PA15 */
#define GPIO_SPI1_RE_SCK		GPIO3		/* PB3 */
#define GPIO_SPI1_RE_MISO		GPIO4		/* PB4 */
#define GPIO_SPI1_RE_MOSI		GPIO5		/* PB5 */

/* SPI2 */
#define GPIO_SPI2_NSS			GPIO12		/* PB12 */
#define GPIO_SPI2_SCK			GPIO13		/* PB13 */
#define GPIO_SPI2_MISO			GPIO14		/* PB14 */
#define GPIO_SPI2_MOSI			GPIO15		/* PB15 */

/* SPI3 */
#define GPIO_SPI3_NSS			GPIO15		/* PA15 */
#define GPIO_SPI3_SCK			GPIO3		/* PB3 */
#define GPIO_SPI3_MISO			GPIO4		/* PB4 */
#define GPIO_SPI3_MOSI			GPIO5		/* PB5 */

#define GPIO_SPI3_RE_NSS		GPIO4		/* PA4 */
#define GPIO_SPI3_RE_SCK		GPIO10		/* PC10 */
#define GPIO_SPI3_RE_MISO		GPIO11		/* PC11 */
#define GPIO_SPI3_RE_MOSI		GPIO12		/* PC12 */

/* ETH */
#define GPIO_ETH_RX_DV_CRS_DV		GPIO7		/* PA7 */
#define GPIO_ETH_RXD0  			GPIO4		/* PC4 */
#define GPIO_ETH_RXD1			GPIO5		/* PC5 */
#define GPIO_ETH_RXD2			GPIO0		/* PB0 */
#define GPIO_ETH_RXD3			GPIO1		/* PB1 */

#define GPIO_ETH_RE_RX_DV_CRS_DV	GPIO8		/* PD8 */
#define GPIO_ETH_RE_RXD0  		GPIO9		/* PD9 */
#define GPIO_ETH_RE_RXD1		GPIO10		/* PD10 */
#define GPIO_ETH_RE_RXD2		GPIO11		/* PD11 */
#define GPIO_ETH_RE_RXD3		GPIO12		/* PD12 */

/* --- GPIO registers ------------------------------------------------------ */

/* Port configuration register low (GPIOx_CRL) */
#define GPIO_CRL(port)			MMIO32(port + 0x00)
#define GPIOA_CRL			GPIO_CRL(GPIOA)
#define GPIOB_CRL			GPIO_CRL(GPIOB)
#define GPIOC_CRL			GPIO_CRL(GPIOC)
#define GPIOD_CRL			GPIO_CRL(GPIOD)
#define GPIOE_CRL			GPIO_CRL(GPIOE)
#define GPIOF_CRL			GPIO_CRL(GPIOF)
#define GPIOG_CRL			GPIO_CRL(GPIOG)

/* Port configuration register low (GPIOx_CRH) */
#define GPIO_CRH(port)			MMIO32(port + 0x04)
#define GPIOA_CRH			GPIO_CRH(GPIOA)
#define GPIOB_CRH			GPIO_CRH(GPIOB)
#define GPIOC_CRH			GPIO_CRH(GPIOC)
#define GPIOD_CRH			GPIO_CRH(GPIOD)
#define GPIOE_CRH			GPIO_CRH(GPIOE)
#define GPIOF_CRH			GPIO_CRH(GPIOF)
#define GPIOG_CRH			GPIO_CRH(GPIOG)

/* Port input data register (GPIOx_IDR) */
#define GPIO_IDR(port)			MMIO32(port + 0x08)
#define GPIOA_IDR			GPIO_IDR(GPIOA)
#define GPIOB_IDR			GPIO_IDR(GPIOB)
#define GPIOC_IDR			GPIO_IDR(GPIOC)
#define GPIOD_IDR			GPIO_IDR(GPIOD)
#define GPIOE_IDR			GPIO_IDR(GPIOE)
#define GPIOF_IDR			GPIO_IDR(GPIOF)
#define GPIOG_IDR			GPIO_IDR(GPIOG)

/* Port output data register (GPIOx_ODR) */
#define GPIO_ODR(port)			MMIO32(port + 0x0c)
#define GPIOA_ODR			GPIO_ODR(GPIOA)
#define GPIOB_ODR			GPIO_ODR(GPIOB)
#define GPIOC_ODR			GPIO_ODR(GPIOC)
#define GPIOD_ODR			GPIO_ODR(GPIOD)
#define GPIOE_ODR			GPIO_ODR(GPIOE)
#define GPIOF_ODR			GPIO_ODR(GPIOF)
#define GPIOG_ODR			GPIO_ODR(GPIOG)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIO_BSRR(port)			MMIO32(port + 0x10)
#define GPIOA_BSRR			GPIO_BSRR(GPIOA)
#define GPIOB_BSRR			GPIO_BSRR(GPIOB)
#define GPIOC_BSRR			GPIO_BSRR(GPIOC)
#define GPIOD_BSRR			GPIO_BSRR(GPIOD)
#define GPIOE_BSRR			GPIO_BSRR(GPIOE)
#define GPIOF_BSRR			GPIO_BSRR(GPIOF)
#define GPIOG_BSRR			GPIO_BSRR(GPIOG)

/* Port bit reset register (GPIOx_BRR) */
#define GPIO_BRR(port)			MMIO16(port + 0x14)
#define GPIOA_BRR			GPIO_BRR(GPIOA)
#define GPIOB_BRR			GPIO_BRR(GPIOB)
#define GPIOC_BRR			GPIO_BRR(GPIOC)
#define GPIOD_BRR			GPIO_BRR(GPIOD)
#define GPIOE_BRR			GPIO_BRR(GPIOE)
#define GPIOF_BRR			GPIO_BRR(GPIOF)
#define GPIOG_BRR			GPIO_BRR(GPIOG)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIO_LCKR(port)			MMIO32(port + 0x18)
#define GPIOA_LCKR			GPIO_LCKR(GPIOA)
#define GPIOB_LCKR			GPIO_LCKR(GPIOB)
#define GPIOC_LCKR			GPIO_LCKR(GPIOC)
#define GPIOD_LCKR			GPIO_LCKR(GPIOD)
#define GPIOE_LCKR			GPIO_LCKR(GPIOE)
#define GPIOF_LCKR			GPIO_LCKR(GPIOF)
#define GPIOG_LCKR			GPIO_LCKR(GPIOG)

/* --- GPIO_CRL/GPIO_CRH values -------------------------------------------- */

/* CNF[1:0] values when MODE[1:0] is 00 (input mode) */
#define GPIO_CNF_INPUT_ANALOG		0x00
#define GPIO_CNF_INPUT_FLOAT		0x01	/* Default */
#define GPIO_CNF_INPUT_PULL_UPDOWN	0x02

/* Output mode (MODE[1:0]) values */
#define GPIO_MODE_INPUT			0x00	/* Default */
#define GPIO_MODE_OUTPUT_10_MHZ		0x01
#define GPIO_MODE_OUTPUT_2_MHZ		0x02
#define GPIO_MODE_OUTPUT_50_MHZ		0x03

/* CNF[1:0] values when MODE[1:0] is != 00 (one of the output modes) */
#define GPIO_CNF_OUTPUT_PUSHPULL	0x00
#define GPIO_CNF_OUTPUT_OPENDRAIN	0x01
#define GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	0x02
#define GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN	0x03

/* --- GPIO_IDR values ----------------------------------------------------- */

/* GPIO_IDR[15:0]: IDRy[15:0]: Port input data (y = 0..15) */

/* --- GPIO_ODR values ----------------------------------------------------- */

/* GPIO_ODR[15:0]: ODRy[15:0]: Port output data (y = 0..15) */

/* --- GPIO_BSRR values ---------------------------------------------------- */

/* GPIO_BSRR[31:16]: BRy: Port x reset bit y (y = 0..15) */
/* GPIO_BSRR[15:0]: BSy: Port x set bit y (y = 0..15) */

/* --- GPIO_BRR values ----------------------------------------------------- */

/* GPIO_BRR[15:0]: BRy: Port x reset bit y (y = 0..15) */

/* --- GPIO_LCKR values ---------------------------------------------------- */

#define GPIO_LCKK			(1 << 16)
/* GPIO_LCKR[15:0]: LCKy: Port x lock bit y (y = 0..15) */

/* --- AFIO registers ------------------------------------------------------ */

/* Event control register (AFIO_EVCR) */
#define AFIO_EVCR			MMIO32(AFIO_BASE + 0x00)

/* AF remap and debug I/O configuration register (AFIO_MAPR) */
#define AFIO_MAPR			MMIO32(AFIO_BASE + 0x04)

/* External interrupt configuration register 1 (AFIO_EXTICR1) */
#define AFIO_EXTICR1			MMIO32(AFIO_BASE + 0x08)

/* External interrupt configuration register 2 (AFIO_EXTICR2) */
#define AFIO_EXTICR2			MMIO32(AFIO_BASE + 0x0c)

/* External interrupt configuration register 3 (AFIO_EXTICR3) */
#define AFIO_EXTICR3			MMIO32(AFIO_BASE + 0x10)

/* External interrupt configuration register 4 (AFIO_EXTICR4) */
#define AFIO_EXTICR4			MMIO32(AFIO_BASE + 0x14)

/* --- AFIO_EVCR values ---------------------------------------------------- */

/* EVOE: Event output enable */
#define AFIO_EVCR_EVOE                  (1 << 7)

/* PORT[2:0]: Port selection */
#define AFIO_EVCR_PORT_PA               (0x0 << 4)
#define AFIO_EVCR_PORT_PB               (0x1 << 4)
#define AFIO_EVCR_PORT_PC               (0x2 << 4)
#define AFIO_EVCR_PORT_PD               (0x3 << 4)
#define AFIO_EVCR_PORT_PE               (0x4 << 4)

/* PIN[3:0]: Pin selection */
#define AFIO_EVCR_PIN_Px0               (0x0 << 0)
#define AFIO_EVCR_PIN_Px1               (0x1 << 0)
#define AFIO_EVCR_PIN_Px2               (0x2 << 0)
#define AFIO_EVCR_PIN_Px3               (0x3 << 0)
#define AFIO_EVCR_PIN_Px4               (0x4 << 0)
#define AFIO_EVCR_PIN_Px5               (0x5 << 0)
#define AFIO_EVCR_PIN_Px6               (0x6 << 0)
#define AFIO_EVCR_PIN_Px7               (0x7 << 0)
#define AFIO_EVCR_PIN_Px8               (0x8 << 0)
#define AFIO_EVCR_PIN_Px9               (0x9 << 0)
#define AFIO_EVCR_PIN_Px10              (0xA << 0)
#define AFIO_EVCR_PIN_Px11              (0xB << 0)
#define AFIO_EVCR_PIN_Px12              (0xC << 0)
#define AFIO_EVCR_PIN_Px13              (0xD << 0)
#define AFIO_EVCR_PIN_Px14              (0xE << 0)
#define AFIO_EVCR_PIN_Px15              (0xF << 0)

/* --- AFIO_MAPR values ---------------------------------------------------- */

/* 31 reserved */

/* PTP_PPS_REMAP: Ethernet PTP PPS remapping
 * (only connectivity line devices) */
#define AFIO_MAPR_PTP_PPS_REMAP              (1 << 30)

/* TIM2ITR1_IREMAP: TIM2 internal trigger 1 remapping
 * (only connectivity line devices) */
#define AFIO_MAPR_TIM2ITR1_IREMAP            (1 << 29)

/* SPI3_REMAP: SPI3/I2S3 remapping
 * (only connectivity line devices) */
#define AFIO_MAPR_SPI3_REMAP                 (1 << 28)

/* 27 reserved */

/* SWJ_CFG[2:0]: Serial wire JTAG configuration */
#define AFIO_MAPR_SWJ_CFG_FULL_SWJ           (0x0 << 24)
#define AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST (0x1 << 24)
#define AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_ON     (0x2 << 24)
#define AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_OFF    (0x4 << 24)

/* MII_REMAP: MII or RMII selection
 * (only connectivity line devices) */
#define AFIO_MAPR_MII_RMII_SEL               (1 << 23)

/* CAN2_REMAP: CAN2 I/O remapping
 * (only connectivity line devices) */
#define AFIO_MAPR_CAN2_REMAP                 (1 << 22)

/* ETH_REMAP: Ethernet MAC I/O remapping
 * (only connectivity line devices) */
#define AFIO_MAPR_ETH_REMAP                  (1 << 21)

/* ADC2_ETRGREG_REMAP: ADC2 external trigger regulator conversion remapping
 * (only low-, medium-, high- and XL-densitiy devices) */
#define AFIO_MAPR_ADC2_ETRGREG_REMAP         (1 << 20)

/* ADC2_ETRGINJ_REMAP: ADC2 external trigger injected conversion remapping
 * (only low-, medium-, high- and XL-densitiy devices) */
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP         (1 << 19)

/* ADC1_ETRGREG_REMAP: ADC1 external trigger regulator conversion remapping
 * (only low-, medium-, high- and XL-densitiy devices) */
#define AFIO_MAPR_ADC1_ETRGREG_REMAP         (1 << 18)

/* ADC1_ETRGINJ_REMAP: ADC1 external trigger injected conversion remapping
 * (only low-, medium-, high- and XL-densitiy devices) */
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP         (1 << 17)

/* TIM5CH4_IREMAP: TIM5 channel4 internal remap */
#define AFIO_MAPR_TIM5CH4_IREMAP             (1 << 16)

/* PD01_REMAP: Port D0/Port D1 mapping on OSC_IN/OSC_OUT */
#define AFIO_MAPR_PD01_REMAP                 (1 << 15)

/* CAN_REMAP[1:0]: CAN1 alternate function remapping */
#define AFIO_MAPR_CAN1_REMAP_PORTA           (0x0 << 13)
#define AFIO_MAPR_CAN1_REMAP_PORTB           (0x2 << 13) /* Not on 36pin pkg */
#define AFIO_MAPR_CAN1_REMAP_PORTD           (0x3 << 13)

/* TIM4_REMAP: TIM4 remapping */
#define AFIO_MAPR_TIM4_REMAP                 (1 << 12)

/* TIM3_REMAP[1:0]: TIM3 remapping */
#define AFIO_MAPR_TIM3_REMAP_NO_REMAP        (0x0 << 10)
#define AFIO_MAPR_TIM3_REMAP_PARTIAL_REMAP   (0x2 << 10)
#define AFIO_MAPR_TIM3_REMAP_FULL_REMAP      (0x3 << 10)

/* TIM2_REMAP[1:0]: TIM2 remapping */
#define AFIO_MAPR_TIM2_REMAP_NO_REMAP        (0x0 << 8)
#define AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP1  (0x1 << 8)
#define AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP2  (0x2 << 8)
#define AFIO_MAPR_TIM2_REMAP_FULL_REMAP      (0x3 << 8)

/* TIM1_REMAP[1:0]: TIM1 remapping */
#define AFIO_MAPR_TIM1_REMAP_NO_REMAP        (0x0 << 6)
#define AFIO_MAPR_TIM1_REMAP_PARTIAL_REMAP   (0x1 << 6)
#define AFIO_MAPR_TIM1_REMAP_FULL_REMAP      (0x3 << 6)

/* USART3_REMAP[1:0]: USART3 remapping */
#define AFIO_MAPR_USART3_REMAP_NO_REMAP      (0x0 << 4)
#define AFIO_MAPR_USART3_REMAP_PARTIAL_REMAP (0x1 << 4)
#define AFIO_MAPR_USART3_REMAP_FULL_REMAP    (0x3 << 4)

/* USART2_REMAP[1:0]: USART2 remapping */
#define AFIO_MAPR_USART2_REMAP               (1 << 3)

/* USART1_REMAP[1:0]: USART1 remapping */
#define AFIO_MAPR_USART1_REMAP               (1 << 2)

/* I2C1_REMAP[1:0]: I2C1 remapping */
#define AFIO_MAPR_I2C1_REMAP                 (1 << 1)

/* SPI1_REMAP[1:0]: SPI1 remapping */
#define AFIO_MAPR_SPI1_REMAP                 (1 << 0)

/* --- AFIO_EXTICR1 values ------------------------------------------------- */
/* --- AFIO_EXTICR2 values ------------------------------------------------- */
/* --- AFIO_EXTICR3 values ------------------------------------------------- */
/* --- AFIO_EXTICR4 values ------------------------------------------------- */

/* EXTI0 - EXTI15 interrupt source selection registers */

/* Note: For using them we should define a function that calculates the right
 *       registers, using definitions is probably not a good idea.
 */

/* --- Function prototypes ------------------------------------------------- */

void gpio_set_mode(u32 gpioport, u8 mode, u8 cnf, u16 gpios);
void gpio_set(u32 gpioport, u16 gpios);
void gpio_clear(u32 gpioport, u16 gpios);
u16 gpio_get(u32 gpioport, u16 gpios);
void gpio_toggle(u32 gpioport, u16 gpios);
u16 gpio_port_read(u32 gpioport);
void gpio_port_write(u32 gpioport, u16 data);
void gpio_port_config_lock(u32 gpioport, u16 gpios);

#endif
