/** @defgroup gpio_defines GPIO Defines

@brief <b>Defined Constants and Types for the STM32F1xx General Purpose I/O</b>

@ingroup STM32F1xx_defines

@version 1.0.0

@date 1 July 2012

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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

/**@{*/

#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H

#include <libopencm3/stm32/common/gpio_common_all.h>

/* --- Convenience macros -------------------------------------------------- */

/* GPIO port base addresses (for convenience) */
/** @defgroup gpio_port_id GPIO Port IDs
@ingroup gpio_defines

@{*/
/* GPIO port base addresses (for convenience) */
#define GPIOA				GPIO_PORT_A_BASE
#define GPIOB				GPIO_PORT_B_BASE
#define GPIOC				GPIO_PORT_C_BASE
#define GPIOD				GPIO_PORT_D_BASE
#define GPIOE				GPIO_PORT_E_BASE
#define GPIOF				GPIO_PORT_F_BASE
#define GPIOG				GPIO_PORT_G_BASE
/**@}*/

/* --- Alternate function GPIOs -------------------------------------------- */

/* Default alternate functions of some pins (with and without remapping) */

/* CAN1 / CAN GPIO */
#define GPIO_CAN1_RX			GPIO11		/* PA11 */
#define GPIO_CAN1_TX			GPIO12		/* PA12 */
#define GPIO_CAN_RX			GPIO_CAN1_RX	/* Alias */
#define GPIO_CAN_TX			GPIO_CAN1_TX	/* Alias */

#define GPIO_CAN_PB_RX			GPIO8		/* PB8 */
#define GPIO_CAN_PB_TX			GPIO9		/* PB9 */
#define GPIO_CAN1_PB_RX			GPIO_CAN_PB_RX	/* Alias */
#define GPIO_CAN1_PB_TX			GPIO_CAN_PB_TX	/* Alias */

#define GPIO_CAN_PD_RX			GPIO0		/* PD0 */
#define GPIO_CAN_PD_TX			GPIO1		/* PD1 */
#define GPIO_CAN1_PD_RX			GPIO_CAN_PD_RX	/* Alias */
#define GPIO_CAN1_PD_TX			GPIO_CAN_PD_TX	/* Alias */

/* CAN1 / CAN BANK */
#define GPIO_BANK_CAN1_RX		GPIOA		/* PA11 */
#define GPIO_BANK_CAN1_TX		GPIOA		/* PA12 */
#define GPIO_BANK_CAN_RX		GPIO_BANK_CAN1_RX /* Alias */
#define GPIO_BANK_CAN_TX		GPIO_BANK_CAN1_TX /* Alias */

#define GPIO_BANK_CAN_PB_RX		GPIOB		/* PB8 */
#define GPIO_BANK_CAN_PB_TX		GPIOB		/* PB9 */
#define GPIO_BANK_CAN1_PB_RX		GPIO_BANK_CAN_PB_RX /* Alias */
#define GPIO_BANK_CAN1_PB_TX		GPIO_BANK_CAN_PB_TX /* Alias */

#define GPIO_BANK_CAN_PD_RX		GPIOD		/* PD0 */
#define GPIO_BANK_CAN_PD_TX		GPIOD		/* PD1 */
#define GPIO_BANK_CAN1_PD_RX		GPIO_BANK_CAN_PD_RX /* Alias */
#define GPIO_BANK_CAN1_PD_TX		GPIO_BANK_CAN_PD_TX /* Alias */

/* CAN2 GPIO */
#define GPIO_CAN2_RX			GPIO12		/* PB12 */
#define GPIO_CAN2_TX			GPIO13		/* PB13 */

#define GPIO_CAN2_RE_RX			GPIO5		/* PB5 */
#define GPIO_CAN2_RE_TX			GPIO6		/* PB6 */

/* CAN2 BANK */
#define GPIO_BANK_CAN2_RX		GPIOB		/* PB12 */
#define GPIO_BANK_CAN2_TX		GPIOB		/* PB13 */

#define GPIO_BANK_CAN2_RE_RX		GPIOB		/* PB5 */
#define GPIO_BANK_CAN2_RE_TX		GPIOB		/* PB6 */

/* JTAG/SWD GPIO */
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

/* JTAG/SWD BANK */
#define GPIO_BANK_JTMS_SWDIO		GPIOA		/* PA13 */
#define GPIO_BANK_JTCK_SWCLK		GPIOA		/* PA14 */
#define GPIO_BANK_JTDI			GPIOA		/* PA15 */
#define GPIO_BANK_JTDO_TRACESWO		GPIOB		/* PB3 */
#define GPIO_BANK_JNTRST		GPIOB		/* PB4 */
#define GPIO_BANK_TRACECK		GPIOE		/* PE2 */
#define GPIO_BANK_TRACED0		GPIOE		/* PE3 */
#define GPIO_BANK_TRACED1		GPIOE		/* PE4 */
#define GPIO_BANK_TRACED2		GPIOE		/* PE5 */
#define GPIO_BANK_TRACED3		GPIOE		/* PE6 */

/* Timer5 GPIO */
#define GPIO_TIM5_CH1			GPIO0		/* PA0 */
#define GPIO_TIM5_CH2			GPIO1		/* PA1 */
#define GPIO_TIM5_CH3			GPIO2		/* PA2 */
#define GPIO_TIM5_CH4			GPIO3		/* PA3 */

/* Timer5 BANK */
#define GPIO_BANK_TIM5_CH1		GPIOA		/* PA0 */
#define GPIO_BANK_TIM5_CH2		GPIOA		/* PA1 */
#define GPIO_BANK_TIM5_CH3		GPIOA		/* PA2 */
#define GPIO_BANK_TIM5_CH4		GPIOA		/* PA3 */
#define GPIO_BANK_TIM5			GPIOA

/* Timer4 GPIO */
#define GPIO_TIM4_CH1			GPIO6		/* PB6 */
#define GPIO_TIM4_CH2			GPIO7		/* PB7 */
#define GPIO_TIM4_CH3			GPIO8		/* PB8 */
#define GPIO_TIM4_CH4			GPIO9		/* PB9 */

#define GPIO_TIM4_RE_CH1		GPIO12		/* PD12 */
#define GPIO_TIM4_RE_CH2		GPIO13		/* PD13 */
#define GPIO_TIM4_RE_CH3		GPIO14		/* PD14 */
#define GPIO_TIM4_RE_CH4		GPIO15		/* PD15 */

/* Timer4 BANK */
#define GPIO_BANK_TIM4_CH1		GPIOB		/* PB6 */
#define GPIO_BANK_TIM4_CH2		GPIOB		/* PB7 */
#define GPIO_BANK_TIM4_CH3		GPIOB		/* PB8 */
#define GPIO_BANK_TIM4_CH4		GPIOB		/* PB9 */
#define GPIO_BANK_TIM4			GPIOB

#define GPIO_BANK_TIM4_RE_CH1		GPIOD		/* PD12 */
#define GPIO_BANK_TIM4_RE_CH2		GPIOD		/* PD13 */
#define GPIO_BANK_TIM4_RE_CH3		GPIOD		/* PD14 */
#define GPIO_BANK_TIM4_RE_CH4		GPIOD		/* PD15 */
#define GPIO_BANK_TIM4_RE		GPIOD

/* Timer3 GPIO */
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

/* Timer3 BANK */
#define GPIO_BANK_TIM3_CH1		GPIOA		/* PA6 */
#define GPIO_BANK_TIM3_CH2		GPIOA		/* PA7 */
#define GPIO_BANK_TIM3_CH3		GPIOB		/* PB0 */
#define GPIO_BANK_TIM3_CH4		GPIOB		/* PB1 */
#define GPIO_BANK_TIM3_CH12		GPIOA
#define GPIO_BANK_TIM3_CH34		GPIOB

#define GPIO_BANK_TIM3_PR_CH1		GPIOB		/* PB4 */
#define GPIO_BANK_TIM3_PR_CH2		GPIOB		/* PB5 */
#define GPIO_BANK_TIM3_PR_CH3		GPIOB		/* PB0 */
#define GPIO_BANK_TIM3_PR_CH4		GPIOB		/* PB1 */
#define GPIO_BANK_TIM3_PR		GPIOB

#define GPIO_BANK_TIM3_FR_CH1		GPIOC		/* PC6 */
#define GPIO_BANK_TIM3_FR_CH2		GPIOC		/* PC7 */
#define GPIO_BANK_TIM3_FR_CH3		GPIOC		/* PC8 */
#define GPIO_BANK_TIM3_FR_CH4		GPIOC		/* PC9 */
#define GPIO_BANK_TIM3_FR		GPIOC

/* Timer2 GPIO */
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

/* Timer2 BANK */
#define GPIO_BANK_TIM2_CH1_ETR		GPIOA		/* PA0 */
#define GPIO_BANK_TIM2_CH2		GPIOA		/* PA1 */
#define GPIO_BANK_TIM2_CH3		GPIOA		/* PA2 */
#define GPIO_BANK_TIM2_CH4		GPIOA		/* PA3 */
#define GPIO_BANK_TIM2			GPIOA

#define GPIO_BANK_TIM2_PR1_CH1_ETR	GPIOA		/* PA15 */
#define GPIO_BANK_TIM2_PR1_CH2		GPIOB		/* PB3 */
#define GPIO_BANK_TIM2_PR1_CH3		GPIOA		/* PA2 */
#define GPIO_BANK_TIM2_PR1_CH4		GPIOA		/* PA3 */
#define GPIO_BANK_TIM2_PR1_CH134	GPIOA

#define GPIO_BANK_TIM2_PR2_CH1_ETR	GPIOA		/* PA0 */
#define GPIO_BANK_TIM2_PR2_CH2		GPIOA		/* PA1 */
#define GPIO_BANK_TIM2_PR2_CH3		GPIOB		/* PB10 */
#define GPIO_BANK_TIM2_PR2_CH4		GPIOB		/* PB11 */
#define GPIO_BANK_TIM2_PR2_CH12		GPIOA
#define GPIO_BANK_TIM2_PR2_CH34		GPIOB

#define GPIO_BANK_TIM2_FR_CH1_ETR	GPIOA		/* PA15 */
#define GPIO_BANK_TIM2_FR_CH2		GPIOB		/* PB3 */
#define GPIO_BANK_TIM2_FR_CH3		GPIOB		/* PB10 */
#define GPIO_BANK_TIM2_FR_CH4		GPIOB		/* PB11 */
#define GPIO_BANK_TIM2_FR_CH234		GPIOB

/* Timer1 GPIO */
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

/* Timer1 BANK */
#define GPIO_BANK_TIM1_ETR		GPIOA		/* PA12 */
#define GPIO_BANK_TIM1_CH1		GPIOA		/* PA8 */
#define GPIO_BANK_TIM1_CH2		GPIOA		/* PA9 */
#define GPIO_BANK_TIM1_CH3		GPIOA		/* PA10 */
#define GPIO_BANK_TIM1_CH4		GPIOA		/* PA11 */
#define GPIO_BANK_TIM1_BKIN		GPIOB		/* PB12 */
#define GPIO_BANK_TIM1_CH1N		GPIOB		/* PB13 */
#define GPIO_BANK_TIM1_CH2N		GPIOB		/* PB14 */
#define GPIO_BANK_TIM1_CH3N		GPIOB		/* PB15 */
#define GPIO_BANK_TIM1_ETR_CH1234	GPIOA
#define GPIO_BANK_TIM1_BKIN_CH123N	GPIOB

#define GPIO_BANK_TIM1_PR_ETR		GPIOA		/* PA12 */
#define GPIO_BANK_TIM1_PR_CH1		GPIOA		/* PA8 */
#define GPIO_BANK_TIM1_PR_CH2		GPIOA		/* PA9 */
#define GPIO_BANK_TIM1_PR_CH3		GPIOA		/* PA10 */
#define GPIO_BANK_TIM1_PR_CH4		GPIOA		/* PA11 */
#define GPIO_BANK_TIM1_PR_BKIN		GPIOA		/* PA6 */
#define GPIO_BANK_TIM1_PR_CH1N		GPIOA		/* PA7 */
#define GPIO_BANK_TIM1_PR_CH2N		GPIOB		/* PB0 */
#define GPIO_BANK_TIM1_PR_CH3N		GPIOB		/* PB1 */
#define GPIO_BANK_TIM1_PR_ETR_CH1234_BKIN_CH1N	GPIOA
#define GPIO_BANK_TIM1_PR_CH23N		GPIOB

#define GPIO_BANK_TIM1_FR_ETR		GPIOE		/* PE7 */
#define GPIO_BANK_TIM1_FR_CH1		GPIOE		/* PE9 */
#define GPIO_BANK_TIM1_FR_CH2		GPIOE		/* PE11 */
#define GPIO_BANK_TIM1_FR_CH3		GPIOE		/* PE13 */
#define GPIO_BANK_TIM1_FR_CH4		GPIOE		/* PE14 */
#define GPIO_BANK_TIM1_FR_BKIN		GPIOE		/* PE15 */
#define GPIO_BANK_TIM1_FR_CH1N		GPIOE		/* PE8 */
#define GPIO_BANK_TIM1_FR_CH2N		GPIOE		/* PE10 */
#define GPIO_BANK_TIM1_FR_CH3N		GPIOE		/* PE12 */
#define GPIO_BANK_TIM1_FR		GPIOE

/* UART5 GPIO */
#define GPIO_UART5_TX			GPIO12		/* PC12 */
#define GPIO_UART5_RX			GPIO2		/* PD2 */

/* UART5 BANK */
#define GPIO_BANK_UART5_TX		GPIOC		/* PC12 */
#define GPIO_BANK_UART5_RX		GPIOD		/* PD2 */

/* UART4 GPIO */
#define GPIO_UART4_TX			GPIO10		/* PC10 */
#define GPIO_UART4_RX			GPIO11		/* PC11 */

/* UART4 BANK */
#define GPIO_BANK_UART4_TX		GPIOC		/* PC10 */
#define GPIO_BANK_UART4_RX		GPIOC		/* PC11 */

/* USART3 GPIO */
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

/* USART3 BANK */
#define GPIO_BANK_USART3_TX		GPIOB		/* PB10 */
#define GPIO_BANK_USART3_RX		GPIOB		/* PB11 */
#define GPIO_BANK_USART3_CK		GPIOB		/* PB12 */
#define GPIO_BANK_USART3_CTS		GPIOB		/* PB13 */
#define GPIO_BANK_USART3_RTS		GPIOB		/* PB14 */

#define GPIO_BANK_USART3_PR_TX		GPIOC		/* PC10 */
#define GPIO_BANK_USART3_PR_RX		GPIOC		/* PC11 */
#define GPIO_BANK_USART3_PR_CK		GPIOC		/* PC12 */
#define GPIO_BANK_USART3_PR_CTS		GPIOB		/* PB13 */
#define GPIO_BANK_USART3_PR_RTS		GPIOB		/* PB14 */

#define GPIO_BANK_USART3_FR_TX		GPIOD		/* PD8 */
#define GPIO_BANK_USART3_FR_RX		GPIOD		/* PD9 */
#define GPIO_BANK_USART3_FR_CK		GPIOD		/* PD10 */
#define GPIO_BANK_USART3_FR_CTS		GPIOD		/* PD11 */
#define GPIO_BANK_USART3_FR_RTS		GPIOD		/* PD12 */

/* USART2 GPIO */
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

/* USART2 BANK */
#define GPIO_BANK_USART2_CTS		GPIOA		/* PA0 */
#define GPIO_BANK_USART2_RTS		GPIOA		/* PA1 */
#define GPIO_BANK_USART2_TX		GPIOA		/* PA2 */
#define GPIO_BANK_USART2_RX		GPIOA		/* PA3 */
#define GPIO_BANK_USART2_CK		GPIOA		/* PA4 */

#define GPIO_BANK_USART2_RE_CTS		GPIOD		/* PD3 */
#define GPIO_BANK_USART2_RE_RTS		GPIOD		/* PD4 */
#define GPIO_BANK_USART2_RE_TX		GPIOD		/* PD5 */
#define GPIO_BANK_USART2_RE_RX		GPIOD		/* PD6 */
#define GPIO_BANK_USART2_RE_CK		GPIOD		/* PD7 */

/* USART1 GPIO */
#define GPIO_USART1_TX			GPIO9		/* PA9 */
#define GPIO_USART1_RX			GPIO10		/* PA10 */

#define GPIO_USART1_RE_TX		GPIO6		/* PB6 */
#define GPIO_USART1_RE_RX		GPIO7		/* PB7 */

/* USART1 BANK */
#define GPIO_BANK_USART1_TX		GPIOA		/* PA9 */
#define GPIO_BANK_USART1_RX		GPIOA		/* PA10 */

#define GPIO_BANK_USART1_RE_TX		GPIOB		/* PB6 */
#define GPIO_BANK_USART1_RE_RX		GPIOB		/* PB7 */

/* I2C1 GPIO */
#define GPIO_I2C1_SMBAI			GPIO5		/* PB5 */
#define GPIO_I2C1_SCL			GPIO6		/* PB6 */
#define GPIO_I2C1_SDA			GPIO7		/* PB7 */

#define GPIO_I2C1_RE_SMBAI		GPIO5		/* PB5 */
#define GPIO_I2C1_RE_SCL		GPIO8		/* PB8 */
#define GPIO_I2C1_RE_SDA		GPIO9		/* PB9 */

/* I2C1 BANK */
#define GPIO_BANK_I2C1_SMBAI		GPIOB		/* PB5 */
#define GPIO_BANK_I2C1_SCL		GPIOB		/* PB6 */
#define GPIO_BANK_I2C1_SDA		GPIOB		/* PB7 */

#define GPIO_BANK_I2C1_RE_SMBAI		GPIOB		/* PB5 */
#define GPIO_BANK_I2C1_RE_SCL		GPIOB		/* PB8 */
#define GPIO_BANK_I2C1_RE_SDA		GPIOB		/* PB9 */

/* I2C2 GPIO */
#define GPIO_I2C2_SCL			GPIO10		/* PB10 */
#define GPIO_I2C2_SDA			GPIO11		/* PB11 */
#define GPIO_I2C2_SMBAI			GPIO12		/* PB12 */

/* I2C2 BANK */
#define GPIO_BANK_I2C2_SCL		GPIOB		/* PB10 */
#define GPIO_BANK_I2C2_SDA		GPIOB		/* PB11 */
#define GPIO_BANK_I2C2_SMBAI		GPIOB		/* PB12 */

/* SPI1 GPIO */
#define GPIO_SPI1_NSS			GPIO4		/* PA4 */
#define GPIO_SPI1_SCK			GPIO5		/* PA5 */
#define GPIO_SPI1_MISO			GPIO6		/* PA6 */
#define GPIO_SPI1_MOSI			GPIO7		/* PA7 */

#define GPIO_SPI1_RE_NSS		GPIO15		/* PA15 */
#define GPIO_SPI1_RE_SCK		GPIO3		/* PB3 */
#define GPIO_SPI1_RE_MISO		GPIO4		/* PB4 */
#define GPIO_SPI1_RE_MOSI		GPIO5		/* PB5 */

/* SPI1 BANK */
#define GPIO_BANK_SPI1_NSS		GPIOA		/* PA4 */
#define GPIO_BANK_SPI1_SCK		GPIOA		/* PA5 */
#define GPIO_BANK_SPI1_MISO		GPIOA		/* PA6 */
#define GPIO_BANK_SPI1_MOSI		GPIOA		/* PA7 */

#define GPIO_BANK_SPI1_RE_NSS		GPIOA		/* PA15 */
#define GPIO_BANK_SPI1_RE_SCK		GPIOB		/* PB3 */
#define GPIO_BANK_SPI1_RE_MISO		GPIOB		/* PB4 */
#define GPIO_BANK_SPI1_RE_MOSI		GPIOB		/* PB5 */

/* SPI2 GPIO */
#define GPIO_SPI2_NSS			GPIO12		/* PB12 */
#define GPIO_SPI2_SCK			GPIO13		/* PB13 */
#define GPIO_SPI2_MISO			GPIO14		/* PB14 */
#define GPIO_SPI2_MOSI			GPIO15		/* PB15 */

/* SPI2 BANK */
#define GPIO_BANK_SPI2_NSS		GPIOB		/* PB12 */
#define GPIO_BANK_SPI2_SCK		GPIOB		/* PB13 */
#define GPIO_BANK_SPI2_MISO		GPIOB		/* PB14 */
#define GPIO_BANK_SPI2_MOSI		GPIOB		/* PB15 */

/* SPI3 GPIO */
#define GPIO_SPI3_NSS			GPIO15		/* PA15 */
#define GPIO_SPI3_SCK			GPIO3		/* PB3 */
#define GPIO_SPI3_MISO			GPIO4		/* PB4 */
#define GPIO_SPI3_MOSI			GPIO5		/* PB5 */

#define GPIO_SPI3_RE_NSS		GPIO4		/* PA4 */
#define GPIO_SPI3_RE_SCK		GPIO10		/* PC10 */
#define GPIO_SPI3_RE_MISO		GPIO11		/* PC11 */
#define GPIO_SPI3_RE_MOSI		GPIO12		/* PC12 */

/* SPI3 BANK */
#define GPIO_BANK_SPI3_NSS		GPIOA		/* PA15 */
#define GPIO_BANK_SPI3_SCK		GPIOB		/* PB3 */
#define GPIO_BANK_SPI3_MISO		GPIOB		/* PB4 */
#define GPIO_BANK_SPI3_MOSI		GPIOB		/* PB5 */

#define GPIO_BANK_SPI3_RE_NSS		GPIOA		/* PA4 */
#define GPIO_BANK_SPI3_RE_SCK		GPIOC		/* PC10 */
#define GPIO_BANK_SPI3_RE_MISO		GPIOC		/* PC11 */
#define GPIO_BANK_SPI3_RE_MOSI		GPIOC		/* PC12 */

/* ETH GPIO */
#define GPIO_ETH_RX_DV_CRS_DV		GPIO7		/* PA7 */
#define GPIO_ETH_RXD0			GPIO4		/* PC4 */
#define GPIO_ETH_RXD1			GPIO5		/* PC5 */
#define GPIO_ETH_RXD2			GPIO0		/* PB0 */
#define GPIO_ETH_RXD3			GPIO1		/* PB1 */

#define GPIO_ETH_RE_RX_DV_CRS_DV	GPIO8		/* PD8 */
#define GPIO_ETH_RE_RXD0		GPIO9		/* PD9 */
#define GPIO_ETH_RE_RXD1		GPIO10		/* PD10 */
#define GPIO_ETH_RE_RXD2		GPIO11		/* PD11 */
#define GPIO_ETH_RE_RXD3		GPIO12		/* PD12 */

/* ETH BANK */
#define GPIO_BANK_ETH_RX_DV_CRS_DV	GPIOA		/* PA7 */
#define GPIO_BANK_ETH_RXD0		GPIOC		/* PC4 */
#define GPIO_BANK_ETH_RXD1		GPIOC		/* PC5 */
#define GPIO_BANK_ETH_RXD2		GPIOB		/* PB0 */
#define GPIO_BANK_ETH_RXD3		GPIOB		/* PB1 */

#define GPIO_BANK_ETH_RE_RX_DV_CRS_DV	GPIOD		/* PD8 */
#define GPIO_BANK_ETH_RE_RXD0		GPIOD		/* PD9 */
#define GPIO_BANK_ETH_RE_RXD1		GPIOD		/* PD10 */
#define GPIO_BANK_ETH_RE_RXD2		GPIOD		/* PD11 */
#define GPIO_BANK_ETH_RE_RXD3		GPIOD		/* PD12 */

/* --- GPIO registers ------------------------------------------------------ */

/* Port configuration register low (GPIOx_CRL) */
#define GPIO_CRL(port)			MMIO32((port) + 0x00)
#define GPIOA_CRL			GPIO_CRL(GPIOA)
#define GPIOB_CRL			GPIO_CRL(GPIOB)
#define GPIOC_CRL			GPIO_CRL(GPIOC)
#define GPIOD_CRL			GPIO_CRL(GPIOD)
#define GPIOE_CRL			GPIO_CRL(GPIOE)
#define GPIOF_CRL			GPIO_CRL(GPIOF)
#define GPIOG_CRL			GPIO_CRL(GPIOG)

/* Port configuration register low (GPIOx_CRH) */
#define GPIO_CRH(port)			MMIO32((port) + 0x04)
#define GPIOA_CRH			GPIO_CRH(GPIOA)
#define GPIOB_CRH			GPIO_CRH(GPIOB)
#define GPIOC_CRH			GPIO_CRH(GPIOC)
#define GPIOD_CRH			GPIO_CRH(GPIOD)
#define GPIOE_CRH			GPIO_CRH(GPIOE)
#define GPIOF_CRH			GPIO_CRH(GPIOF)
#define GPIOG_CRH			GPIO_CRH(GPIOG)

/* Port input data register (GPIOx_IDR) */
#define GPIO_IDR(port)			MMIO32((port) + 0x08)
#define GPIOA_IDR			GPIO_IDR(GPIOA)
#define GPIOB_IDR			GPIO_IDR(GPIOB)
#define GPIOC_IDR			GPIO_IDR(GPIOC)
#define GPIOD_IDR			GPIO_IDR(GPIOD)
#define GPIOE_IDR			GPIO_IDR(GPIOE)
#define GPIOF_IDR			GPIO_IDR(GPIOF)
#define GPIOG_IDR			GPIO_IDR(GPIOG)

/* Port output data register (GPIOx_ODR) */
#define GPIO_ODR(port)			MMIO32((port) + 0x0c)
#define GPIOA_ODR			GPIO_ODR(GPIOA)
#define GPIOB_ODR			GPIO_ODR(GPIOB)
#define GPIOC_ODR			GPIO_ODR(GPIOC)
#define GPIOD_ODR			GPIO_ODR(GPIOD)
#define GPIOE_ODR			GPIO_ODR(GPIOE)
#define GPIOF_ODR			GPIO_ODR(GPIOF)
#define GPIOG_ODR			GPIO_ODR(GPIOG)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIO_BSRR(port)			MMIO32((port) + 0x10)
#define GPIOA_BSRR			GPIO_BSRR(GPIOA)
#define GPIOB_BSRR			GPIO_BSRR(GPIOB)
#define GPIOC_BSRR			GPIO_BSRR(GPIOC)
#define GPIOD_BSRR			GPIO_BSRR(GPIOD)
#define GPIOE_BSRR			GPIO_BSRR(GPIOE)
#define GPIOF_BSRR			GPIO_BSRR(GPIOF)
#define GPIOG_BSRR			GPIO_BSRR(GPIOG)

/* Port bit reset register (GPIOx_BRR) */
#define GPIO_BRR(port)			MMIO16((port) + 0x14)
#define GPIOA_BRR			GPIO_BRR(GPIOA)
#define GPIOB_BRR			GPIO_BRR(GPIOB)
#define GPIOC_BRR			GPIO_BRR(GPIOC)
#define GPIOD_BRR			GPIO_BRR(GPIOD)
#define GPIOE_BRR			GPIO_BRR(GPIOE)
#define GPIOF_BRR			GPIO_BRR(GPIOF)
#define GPIOG_BRR			GPIO_BRR(GPIOG)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIO_LCKR(port)			MMIO32((port) + 0x18)
#define GPIOA_LCKR			GPIO_LCKR(GPIOA)
#define GPIOB_LCKR			GPIO_LCKR(GPIOB)
#define GPIOC_LCKR			GPIO_LCKR(GPIOC)
#define GPIOD_LCKR			GPIO_LCKR(GPIOD)
#define GPIOE_LCKR			GPIO_LCKR(GPIOE)
#define GPIOF_LCKR			GPIO_LCKR(GPIOF)
#define GPIOG_LCKR			GPIO_LCKR(GPIOG)

/* --- GPIO_CRL/GPIO_CRH values -------------------------------------------- */

/** @defgroup gpio_cnf GPIO Pin Configuration
@ingroup gpio_defines
If mode specifies input, configuration can be
@li Analog input
@li Floating input
@li Pull up/down input

If mode specifies output, configuration can be
@li Digital push-pull
@li Digital open drain
@li Alternate function push-pull or analog output
@li Alternate function open drain or analog output
@{*/
/* CNF[1:0] values when MODE[1:0] is 00 (input mode) */
/** Analog Input */
#define GPIO_CNF_INPUT_ANALOG		0x00
/** Digital Input Floating */
#define GPIO_CNF_INPUT_FLOAT		0x01	/* Default */
/** Digital Input Pull Up and Down */
#define GPIO_CNF_INPUT_PULL_UPDOWN	0x02
/* CNF[1:0] values when MODE[1:0] is != 00 (one of the output modes) */
/** Digital Output Pushpull */
#define GPIO_CNF_OUTPUT_PUSHPULL	0x00
/** Digital Output Open Drain */
#define GPIO_CNF_OUTPUT_OPENDRAIN	0x01
/** Alternate Function Output Pushpull */
#define GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	0x02
/** Alternate Function Output Open Drain */
#define GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN	0x03
/**@}*/

/* Pin mode (MODE[1:0]) values */
/** @defgroup gpio_mode GPIO Pin Mode
@ingroup gpio_defines
@li Input (default after reset)
@li Output mode at 10 MHz maximum speed
@li Output mode at 2 MHz maximum speed
@li Output mode at 50 MHz maximum speed
@{*/
#define GPIO_MODE_INPUT				0x00	/* Default */
#define GPIO_MODE_OUTPUT_10_MHZ		0x01
#define GPIO_MODE_OUTPUT_2_MHZ		0x02
#define GPIO_MODE_OUTPUT_50_MHZ		0x03
/**@}*/

/* --- GPIO_IDR values ----------------------------------------------------- */

/* GPIO_IDR[15:0]: IDRy[15:0]: Port input data (y = 0..15) */

/* --- GPIO_ODR values ----------------------------------------------------- */

/* GPIO_ODR[15:0]: ODRy[15:0]: Port output data (y = 0..15) */

/* --- GPIO_BSRR values ---------------------------------------------------- */

/* GPIO_BSRR[31:16]: BRy: Port x reset bit y (y = 0..15) */
/* GPIO_BSRR[15:0]: BSy: Port x set bit y (y = 0..15) */

/* --- GPIO_BRR values ----------------------------------------------------- */

/* GPIO_BRR[15:0]: BRy: Port x reset bit y (y = 0..15) */

/* --- AFIO registers ------------------------------------------------------ */

/* Event control register (AFIO_EVCR) */
#define AFIO_EVCR			MMIO32(AFIO_BASE + 0x00)

/* AF remap and debug I/O configuration register (AFIO_MAPR) */
#define AFIO_MAPR			MMIO32(AFIO_BASE + 0x04)

/* External interrupt configuration register [0..3] (AFIO_EXTICR[1..4])*/
#define AFIO_EXTICR(i)			MMIO32(AFIO_BASE + 0x08 + (i)*4)
#define AFIO_EXTICR1			AFIO_EXTICR(0)
#define AFIO_EXTICR2			AFIO_EXTICR(1)
#define AFIO_EXTICR3			AFIO_EXTICR(2)
#define AFIO_EXTICR4			AFIO_EXTICR(3)

/* AF remap and debug I/O configuration register (AFIO_MAPR) */
#define AFIO_MAPR2			MMIO32(AFIO_BASE + 0x1C)

/* --- AFIO_EVCR values ---------------------------------------------------- */

/* EVOE: Event output enable */
#define AFIO_EVCR_EVOE			(1 << 7)

/* PORT[2:0]: Port selection */
/** @defgroup afio_evcr_port EVENTOUT Port selection
@ingroup gpio_defines

@{*/
#define AFIO_EVCR_PORT_PA		(0x0 << 4)
#define AFIO_EVCR_PORT_PB		(0x1 << 4)
#define AFIO_EVCR_PORT_PC		(0x2 << 4)
#define AFIO_EVCR_PORT_PD		(0x3 << 4)
#define AFIO_EVCR_PORT_PE		(0x4 << 4)
/**@}*/

/* PIN[3:0]: Pin selection */
/** @defgroup afio_evcr_pin EVENTOUT Pin selection
@ingroup gpio_defines

@{*/
#define AFIO_EVCR_PIN_Px0		(0x0 << 0)
#define AFIO_EVCR_PIN_Px1		(0x1 << 0)
#define AFIO_EVCR_PIN_Px2		(0x2 << 0)
#define AFIO_EVCR_PIN_Px3		(0x3 << 0)
#define AFIO_EVCR_PIN_Px4		(0x4 << 0)
#define AFIO_EVCR_PIN_Px5		(0x5 << 0)
#define AFIO_EVCR_PIN_Px6		(0x6 << 0)
#define AFIO_EVCR_PIN_Px7		(0x7 << 0)
#define AFIO_EVCR_PIN_Px8		(0x8 << 0)
#define AFIO_EVCR_PIN_Px9		(0x9 << 0)
#define AFIO_EVCR_PIN_Px10		(0xA << 0)
#define AFIO_EVCR_PIN_Px11		(0xB << 0)
#define AFIO_EVCR_PIN_Px12		(0xC << 0)
#define AFIO_EVCR_PIN_Px13		(0xD << 0)
#define AFIO_EVCR_PIN_Px14		(0xE << 0)
#define AFIO_EVCR_PIN_Px15		(0xF << 0)
/**@}*/

/* --- AFIO_MAPR values ---------------------------------------------------- */

/* 31 reserved */

/** @defgroup afio_remap_cld Alternate Function Remap Controls for Connectivity
Line Devices only
@ingroup gpio_defines

@{*/
/* PTP_PPS_REMAP: */
/** Ethernet PTP PPS remapping (only connectivity line devices) */
#define AFIO_MAPR_PTP_PPS_REMAP			(1 << 30)

/* TIM2ITR1_IREMAP: */
/** TIM2 internal trigger 1 remapping (only connectivity line devices) */
#define AFIO_MAPR_TIM2ITR1_IREMAP		(1 << 29)

/* SPI3_REMAP: */
/** SPI3/I2S3 remapping (only connectivity line devices) */
#define AFIO_MAPR_SPI3_REMAP			(1 << 28)

/* MII_REMAP: */
/** MII or RMII selection (only connectivity line devices) */
#define AFIO_MAPR_MII_RMII_SEL			(1 << 23)

/* CAN2_REMAP: */
/**  CAN2 I/O remapping (only connectivity line devices) */
#define AFIO_MAPR_CAN2_REMAP			(1 << 22)

/* ETH_REMAP: */
/**  Ethernet MAC I/O remapping (only connectivity line devices) */
#define AFIO_MAPR_ETH_REMAP			(1 << 21)

/**@}*/

/* 27 reserved */

/* SWJ_CFG[2:0]: Serial wire JTAG configuration */
/** @defgroup afio_swj_disable Serial Wire JTAG disables
@ingroup gpio_defines

@{*/
#define AFIO_MAPR_SWJ_MASK			(0x7 << 24)
/** Full Serial Wire JTAG capability */
#define AFIO_MAPR_SWJ_CFG_FULL_SWJ		(0x0 << 24)
/** Full Serial Wire JTAG capability without JNTRST */
#define AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST	(0x1 << 24)
/** JTAG-DP disabled with SW-DP enabled */
#define AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_ON	(0x2 << 24)
/** JTAG-DP disabled and SW-DP disabled */
#define AFIO_MAPR_SWJ_CFG_JTAG_OFF_SW_OFF	(0x4 << 24)
/**@}*/

/** @defgroup afio_remap Alternate Function Remap Controls
@ingroup gpio_defines

@{*/
/* ADC2_ETRGREG_REMAP: */
/**
 * ADC2 external trigger regulator conversion remapping
 * (only low-, medium-, high- and XL-density devices)
 */
#define AFIO_MAPR_ADC2_ETRGREG_REMAP		(1 << 20)

/* ADC2_ETRGINJ_REMAP: */
/**
 * ADC2 external trigger injected conversion remapping
 * (only low-, medium-, high- and XL-density devices)
 */
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP		(1 << 19)

/* ADC1_ETRGREG_REMAP: */
/**
 * ADC1 external trigger regulator conversion remapping
 * (only low-, medium-, high- and XL-density devices)
 */
#define AFIO_MAPR_ADC1_ETRGREG_REMAP		(1 << 18)

/* ADC1_ETRGINJ_REMAP: */
/**
 * ADC1 external trigger injected conversion remapping
 * (only low-, medium-, high- and XL-density devices)
 */
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP		(1 << 17)

/* TIM5CH4_IREMAP: */
/** TIM5 channel 4 internal remap */
#define AFIO_MAPR_TIM5CH4_IREMAP		(1 << 16)

/* PD01_REMAP: */
/** Port D0/Port D1 mapping on OSC_IN/OSC_OUT */
#define AFIO_MAPR_PD01_REMAP			(1 << 15)

/* TIM4_REMAP: */
/** TIM4 remapping */
#define AFIO_MAPR_TIM4_REMAP			(1 << 12)

/* USART2_REMAP[1:0]: */
/** USART2 remapping */
#define AFIO_MAPR_USART2_REMAP			(1 << 3)

/* USART1_REMAP[1:0]: */
/** USART1 remapping */
#define AFIO_MAPR_USART1_REMAP			(1 << 2)

/* I2C1_REMAP[1:0]: */
/** I2C1 remapping */
#define AFIO_MAPR_I2C1_REMAP			(1 << 1)

/* SPI1_REMAP[1:0]: */
/** SPI1 remapping */
#define AFIO_MAPR_SPI1_REMAP			(1 << 0)
/**@}*/

/* CAN_REMAP[1:0]: CAN1 alternate function remapping */
/** @defgroup afio_remap_can1 Alternate Function Remap Controls for CAN 1
@ingroup gpio_defines

@{*/
#define AFIO_MAPR_CAN1_REMAP_PORTA		(0x0 << 13)
#define AFIO_MAPR_CAN1_REMAP_PORTB		(0x2 << 13) /* Not 36pin pkg */
#define AFIO_MAPR_CAN1_REMAP_PORTD		(0x3 << 13)
/**@}*/

/* TIM3_REMAP[1:0]: TIM3 remapping */
/** @defgroup afio_remap_tim3 Alternate Function Remap Controls for Timer 3
@ingroup gpio_defines

@{*/
#define AFIO_MAPR_TIM3_REMAP_NO_REMAP		(0x0 << 10)
#define AFIO_MAPR_TIM3_REMAP_PARTIAL_REMAP	(0x2 << 10)
#define AFIO_MAPR_TIM3_REMAP_FULL_REMAP		(0x3 << 10)
/**@}*/

/* TIM2_REMAP[1:0]: TIM2 remapping */
/** @defgroup afio_remap_tim2 Alternate Function Remap Controls for Timer 2
@ingroup gpio_defines

@{*/
#define AFIO_MAPR_TIM2_REMAP_NO_REMAP		(0x0 << 8)
#define AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP1	(0x1 << 8)
#define AFIO_MAPR_TIM2_REMAP_PARTIAL_REMAP2	(0x2 << 8)
#define AFIO_MAPR_TIM2_REMAP_FULL_REMAP		(0x3 << 8)
/**@}*/

/* TIM1_REMAP[1:0]: TIM1 remapping */
/** @defgroup afio_remap_tim1 Alternate Function Remap Controls for Timer 1
@ingroup gpio_defines

@{*/
#define AFIO_MAPR_TIM1_REMAP_NO_REMAP		(0x0 << 6)
#define AFIO_MAPR_TIM1_REMAP_PARTIAL_REMAP	(0x1 << 6)
#define AFIO_MAPR_TIM1_REMAP_FULL_REMAP		(0x3 << 6)
/**@}*/

/* USART3_REMAP[1:0]: USART3 remapping */
/** @defgroup afio_remap_usart3 Alternate Function Remap Controls for USART 3
@ingroup gpio_defines

@{*/
#define AFIO_MAPR_USART3_REMAP_NO_REMAP		(0x0 << 4)
#define AFIO_MAPR_USART3_REMAP_PARTIAL_REMAP	(0x1 << 4)
#define AFIO_MAPR_USART3_REMAP_FULL_REMAP	(0x3 << 4)
/**@}*/

/** @defgroup afio_remap2 Alternate Function Remap Controls Secondary Set
@ingroup gpio_defines

@{*/
/** various remaps, dma/dac/timer triggers (HD only) */
#define AFIO_MAPR2_MISC_REMAP			(1 << 13)

/** TIM12_CH1 and TIM12_CH2 remapping (HD only) */
#define AFIO_MAPR2_TIM12_REMAP			(1 << 12)

/** TIM76_DAC_DMA remap to DMA1/DMA2 */
#define AFIO_MAPR2_TIM76_DAC_DMA_REMAPE		(1 << 11)

/* FSMC_NADV_DISCONNECT: */
/** The NADV is disconnected from its allocated pin */
#define AFIO_MAPR2_FSMC_NADV_DISCONNECT			(1 << 10)

/* TIM14_REMAP: */
/**  TIM14 remapping */
#define AFIO_MAPR2_TIM14_REMAP			(1 << 9)

/* TIM13_REMAP: */
/**  TIM13 remapping */
#define AFIO_MAPR2_TIM13_REMAP			(1 << 8)

/* TIM11_REMAP: */
/**  TIM11 remapping */
#define AFIO_MAPR2_TIM11_REMAP			(1 << 7)

/* TIM10_REMAP: */
/**  TIM10 remapping */
#define AFIO_MAPR2_TIM10_REMAP			(1 << 6)

/* TIM9_REMAP: */
/**  TIM9 remapping */
#define AFIO_MAPR2_TIM9_REMAP			(1 << 5)

/** TIM1_DMA channel 1/2 remapping */
#define AFIO_MAPR2_TIM1_DMA_REMAP		(1 << 4)

/** CEC remapping (PB8 vs PB10) */
#define AFIO_MAPR2_CEC_REMAP			(1 << 3)

/** TIM17 remapping (PB9 vs PB7) */
#define AFIO_MAPR2_TIM17_REMAP			(1 << 2)

/** TIM16 remapping (PB8 vs PB6) */
#define AFIO_MAPR2_TIM16_REMAP			(1 << 1)

/** TIM15 remapping channels 1/2 */
#define AFIO_MAPR1_TIM16_REMAP			(1 << 0)

/**@}*/

/* --- AFIO_EXTICR1 values ------------------------------------------------- */
/* --- AFIO_EXTICR2 values ------------------------------------------------- */
/* --- AFIO_EXTICR3 values ------------------------------------------------- */
/* --- AFIO_EXTICR4 values ------------------------------------------------- */

/** @defgroup afio_exti Alternate Function EXTI pin number
@ingroup gpio_defines

@{*/

#define AFIO_EXTI0                 0
#define AFIO_EXTI1                 1
#define AFIO_EXTI2                 2
#define AFIO_EXTI3                 3
#define AFIO_EXTI4                 4
#define AFIO_EXTI5                 5
#define AFIO_EXTI6                 6
#define AFIO_EXTI7                 7
#define AFIO_EXTI8                 8
#define AFIO_EXTI9                 9
#define AFIO_EXTI10               10
#define AFIO_EXTI11               11
#define AFIO_EXTI12               12
#define AFIO_EXTI13               13
#define AFIO_EXTI14               14
#define AFIO_EXTI15               15

/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void gpio_set_mode(uint32_t gpioport, uint8_t mode, uint8_t cnf,
		   uint16_t gpios);
void gpio_set_eventout(uint8_t evoutport, uint8_t evoutpin);
void gpio_primary_remap(uint32_t swjenable, uint32_t maps);
void gpio_secondary_remap(uint32_t maps);

END_DECLS

#endif
/**@}*/

