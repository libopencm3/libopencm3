/** @defgroup gpio_defines GPIO Defines

@brief <b>Defined Constants and Types for the AT32F40x General Purpose I/O</b>

@ingroup AT32F40x_defines

@version 1.0.0

@date 19 November 2022

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
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
/**@}*/

/* --- GPIO registers ------------------------------------------------------ */

/* Port configuration register low (GPIOx_CRL) */
#define GPIO_CRL(port)			MMIO32((port) + 0x00)
#define GPIOA_CRL			GPIO_CRL(GPIOA)
#define GPIOB_CRL			GPIO_CRL(GPIOB)
#define GPIOC_CRL			GPIO_CRL(GPIOC)
#define GPIOD_CRL			GPIO_CRL(GPIOD)
#define GPIOE_CRL			GPIO_CRL(GPIOE)

/* Port configuration register low (GPIOx_CRH) */
#define GPIO_CRH(port)			MMIO32((port) + 0x04)
#define GPIOA_CRH			GPIO_CRH(GPIOA)
#define GPIOB_CRH			GPIO_CRH(GPIOB)
#define GPIOC_CRH			GPIO_CRH(GPIOC)
#define GPIOD_CRH			GPIO_CRH(GPIOD)
#define GPIOE_CRH			GPIO_CRH(GPIOE)

/* Port input data register (GPIOx_IDR) */
#define GPIO_IDR(port)			MMIO32((port) + 0x08)
#define GPIOA_IDR			GPIO_IDR(GPIOA)
#define GPIOB_IDR			GPIO_IDR(GPIOB)
#define GPIOC_IDR			GPIO_IDR(GPIOC)
#define GPIOD_IDR			GPIO_IDR(GPIOD)
#define GPIOE_IDR			GPIO_IDR(GPIOE)

/* Port output data register (GPIOx_ODR) */
#define GPIO_ODR(port)			MMIO32((port) + 0x0c)
#define GPIOA_ODR			GPIO_ODR(GPIOA)
#define GPIOB_ODR			GPIO_ODR(GPIOB)
#define GPIOC_ODR			GPIO_ODR(GPIOC)
#define GPIOD_ODR			GPIO_ODR(GPIOD)
#define GPIOE_ODR			GPIO_ODR(GPIOE)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIO_BSRR(port)			MMIO32((port) + 0x10)
#define GPIOA_BSRR			GPIO_BSRR(GPIOA)
#define GPIOB_BSRR			GPIO_BSRR(GPIOB)
#define GPIOC_BSRR			GPIO_BSRR(GPIOC)
#define GPIOD_BSRR			GPIO_BSRR(GPIOD)
#define GPIOE_BSRR			GPIO_BSRR(GPIOE)

/* Port bit reset register (GPIOx_BRR) */
#define GPIO_BRR(port)			MMIO16((port) + 0x14)
#define GPIOA_BRR			GPIO_BRR(GPIOA)
#define GPIOB_BRR			GPIO_BRR(GPIOB)
#define GPIOC_BRR			GPIO_BRR(GPIOC)
#define GPIOD_BRR			GPIO_BRR(GPIOD)
#define GPIOE_BRR			GPIO_BRR(GPIOE)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIO_LCKR(port)			MMIO32((port) + 0x18)
#define GPIOA_LCKR			GPIO_LCKR(GPIOA)
#define GPIOB_LCKR			GPIO_LCKR(GPIOB)
#define GPIOC_LCKR			GPIO_LCKR(GPIOC)
#define GPIOD_LCKR			GPIO_LCKR(GPIOD)
#define GPIOE_LCKR			GPIO_LCKR(GPIOE)

/* Port huge current register (GPIOx_HDRV) */
#define GPIO_HDRV(port)			MMIO32((port) + 0x3c)
#define GPIOA_HDRV			GPIO_HDRV(GPIOA)
#define GPIOB_HDRV			GPIO_HDRV(GPIOB)
#define GPIOC_HDRV			GPIO_HDRV(GPIOC)
#define GPIOD_HDRV			GPIO_HDRV(GPIOD)
#define GPIOE_HDRV			GPIO_HDRV(GPIOE)

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
#define GPIO_MODE_INPUT			0x00	/* Default */
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

/* AF remap and debug I/O configuration registers (AFIO_MAPRx) */
#define AFIO_MAPR2			MMIO32(AFIO_BASE + 0x1c)
#define AFIO_MAPR3			MMIO32(AFIO_BASE + 0x20)
#define AFIO_MAPR4			MMIO32(AFIO_BASE + 0x24)
#define AFIO_MAPR5			MMIO32(AFIO_BASE + 0x28)
#define AFIO_MAPR6			MMIO32(AFIO_BASE + 0x2c)
#define AFIO_MAPR7			MMIO32(AFIO_BASE + 0x30)
#define AFIO_MAPR8			MMIO32(AFIO_BASE + 0x34)

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

/* --- AFIO_EXTICRx values ------------------------------------------------- */

/** EXTICR port selection bits  */
#define AFIO_EXTICR_FIELDSIZE			4

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

/* --- Alternate function GPIOs -------------------------------------------- */

#define AFIOMUX(shift, mask, val) (MAPR << 24 | shift << 16 | mask << 8 | val)

/** @defgroup afio_mux Alternate Function Remap Controls
@ingroup gpio_defines
@{*/

enum afio_mux {

#define MAPR 4	/* offset of AFIO_BASE->MAPRx */

	AFIO_MUX_SPI1_MCK_B0	= AFIOMUX(31, 1, 0),	/*!< SPI1 MCK => B0 */
	AFIO_MUX_SPI1_MCK_B6	= AFIOMUX(31, 1, 1),	/*!< SPI1 MCK => B6 */

	AFIO_MUX_PTP_PPS_B5	= AFIOMUX(30, 1, 0),	/*!< PTP_PPS => B5 */
	AFIO_MUX_PTP_PPS_NONE	= AFIOMUX(30, 1, 1),	/*!< not connected */

	AFIO_MUX_TIM2_ITR1_TIM8	= AFIOMUX(29, 1, 0),	/*!< TIM8TRGO => TIM2ITR1 */
	AFIO_MUX_TIM2_ITR1_PTP	= AFIOMUX(29, 1, 1),	/*!< EMAC_PTP => TIM2ITR1 */

	AFIO_MUX_SPI3_A15	= AFIOMUX(28, 1, 0),	/*!< A15 B[3-5] */
	AFIO_MUX_SPI3_A4	= AFIOMUX(28, 1, 1),	/*!< A4 C[10-12] */

	AFIO_MUX_SWJ_FULL_SWJ	= AFIOMUX(24, 7, 0),	/*!< full swd/jtag */
	AFIO_MUX_SWJ_NO_JNTRST	= AFIOMUX(24, 7, 1),	/*!< full but B4 */
	AFIO_MUX_SWJ_NO_JTAG	= AFIOMUX(24, 7, 2),	/*!< swd only */
	AFIO_MUX_SWJ_NONE	= AFIOMUX(24, 7, 4),	/*!< all disabled */

	AFIO_MUX_ETHMAC_MII	= AFIOMUX(23, 1, 0),	/*!< MII */
	AFIO_MUX_ETHMAC_RMII	= AFIOMUX(23, 1, 1),	/*!< RMII */

	AFIO_MUX_CAN2_B12	= AFIOMUX(22, 1, 0),	/*!< B[12-13] */
	AFIO_MUX_CAN2_B5	= AFIOMUX(22, 1, 1),	/*!< B[5-6] */

	AFIO_MUX_ETHMAC_A7	= AFIOMUX(21, 1, 0),	/*!< A7 C[4-5] B[0-1] */
	AFIO_MUX_ETHMAC_D8	= AFIOMUX(21, 1, 1),	/*!< D[8-12] */

	AFIO_MUX_ADC2_ETRGREG_EXTI11	= AFIOMUX(20, 1, 0),	/*!< EXTI11 => ADC2 ETRG REG */
	AFIO_MUX_ADC2_ETRGREG_TIM8	= AFIOMUX(20, 1, 1),	/*!< TIM8 => ADC2 ETRG REG */
	AFIO_MUX_ADC2_ETRGINJ_EXTI15	= AFIOMUX(19, 1, 0),	/*!< EXTI15 => ADC2 ETRG INJ */
	AFIO_MUX_ADC2_ETRGINJ_TIM8	= AFIOMUX(19, 1, 1),	/*!< TIM8 => ADC2 ETRG INJ */

	AFIO_MUX_ADC1_ETRGREG_EXTI11	= AFIOMUX(18, 1, 0),	/*!< EXTI11 => ADC1 ETRG REG */
	AFIO_MUX_ADC1_ETRGREG_TIM8	= AFIOMUX(18, 1, 1),	/*!< TIM8 => ADC1 ETRG REG */
	AFIO_MUX_ADC1_ETRGINJ_EXTI15	= AFIOMUX(17, 1, 0),	/*!< EXTI15 => ADC1 ETRG INJ */
	AFIO_MUX_ADC1_ETRGINJ_TIM8	= AFIOMUX(17, 1, 1),	/*!< TIM8 => ADC1 ETRG INJ */

	AFIO_MUX_TIM5_CH4_A3	= AFIOMUX(16, 1, 0),	/*!< CH4 => A3 */
	AFIO_MUX_TIM5_CH4_LSI	= AFIOMUX(16, 1, 1),	/*!< LSI => CH4 */

	AFIO_MUX_PD01_NONE	= AFIOMUX(15, 1, 0),	/*!< not connected */
	AFIO_MUX_PD01_OSC	= AFIOMUX(15, 1, 1),	/*!< OSCx => D[0-1] */

	AFIO_MUX_CAN1_A11	= AFIOMUX(13, 3, 0),	/*!< A[11-12] */
	AFIO_MUX_CAN1_B8	= AFIOMUX(13, 3, 2),	/*!< B[8-9] */
	AFIO_MUX_CAN1_D0	= AFIOMUX(13, 3, 3),	/*!< D[0-1] */

	AFIO_MUX_TIM4_B6	= AFIOMUX(12, 1, 0),	/*!< B[6-9] */
	AFIO_MUX_TIM4_D12	= AFIOMUX(12, 1, 1),	/*!< D[12-15] */

	AFIO_MUX_TIM3_A6	= AFIOMUX(10, 3, 0),	/*!< A[6-7] B[0-1] */
	AFIO_MUX_TIM3_B4	= AFIOMUX(10, 3, 2),	/*!< B[4-5] B[0-1] */
	AFIO_MUX_TIM3_C6	= AFIOMUX(10, 3, 3),	/*!< C[6-9] */

	AFIO_MUX_TIM2_A0_A2	= AFIOMUX(8, 3, 0),	/*!< A[0-1] A[2-3] */
	AFIO_MUX_TIM2_A15_A2	= AFIOMUX(8, 3, 1),	/*!< A15 B3 A[2-3] */
	AFIO_MUX_TIM2_A0_B10	= AFIOMUX(8, 3, 2),	/*!< A[0-1] B[10-11] */
	AFIO_MUX_TIM2_A15_B10	= AFIOMUX(8, 3, 3),	/*!< A15 B3 B[10-11] */

	AFIO_MUX_TIM1_A12_B12	= AFIOMUX(6, 3, 0),	/*!< A[8-12] B[12-15] */
	AFIO_MUX_TIM1_A12_B6	= AFIOMUX(6, 3, 1),	/*!< A[8-12] A[6-7] B[0-1] */
	AFIO_MUX_TIM1_E7	= AFIOMUX(6, 3, 3),	/*!< E[7-15] */

	AFIO_MUX_USART3_B10	= AFIOMUX(4, 3, 0),	/*!< B[10-12] B[13-14] */
	AFIO_MUX_USART3_C10	= AFIOMUX(4, 3, 1),	/*!< C[10-12] B[13-14] */
	AFIO_MUX_USART3_D8	= AFIOMUX(4, 3, 3),	/*!< D[8-12] */

	AFIO_MUX_USART2_A0	= AFIOMUX(3, 1, 0),	/*!< A[0-4] */
	AFIO_MUX_USART2_D3	= AFIOMUX(3, 1, 1),	/*!< D[3-7] */

	AFIO_MUX_USART1_A9	= AFIOMUX(2, 1, 0),	/*!< A[9-10] */
	AFIO_MUX_USART1_B6	= AFIOMUX(2, 1, 1),	/*!< B[6-7] */

	AFIO_MUX_I2C1_B6	= AFIOMUX(1, 1, 0),	/*!< B[6-7] B5] */
	AFIO_MUX_I2C1_B8	= AFIOMUX(1, 1, 1),	/*!< B[8-9] B5] */

	AFIO_MUX_SPI1_A4	= AFIOMUX(0, 1, 0),	/*!< A[4-7] */
	AFIO_MUX_SPI1_A15	= AFIOMUX(0, 1, 1),	/*!< A15 B[3-5] */

#undef MAPR
#define MAPR 0x1c	/* MAPR2 */

	AFIO_MUX_SPI_FLASH_DIS	= AFIOMUX(21, 1, 0),	/*!< SPI FLASH disable */
	AFIO_MUX_SPI_FLASH_ENA	= AFIOMUX(21, 1, 1),	/*!< SPI FLASH enable */

	AFIO_MUX_SDIO2_C0	= AFIOMUX(19, 3, 0),	/*!< C[0-1] C3 A[4-7] C[4-5] */
	AFIO_MUX_SDIO2_A4	= AFIOMUX(19, 3, 1),	/*!< A[4-7] A[2-3] */

	AFIO_MUX_I2C3_C9	= AFIOMUX(18, 1, 0),	/*!< A[8-9] C9 */
	AFIO_MUX_I2C3_B4	= AFIOMUX(18, 1, 1),	/*!< A[8-9] B4 */

	AFIO_MUX_SPI4_E4	= AFIOMUX(17, 1, 0),	/*!< E2 E[4-6] C8 */
	AFIO_MUX_SPI4_E12	= AFIOMUX(17, 1, 1),	/*!< E[11-14] C8 */

	AFIO_MUX_FSMC_NADV	= AFIOMUX(10, 1, 0),	/*!< NADV is used */
	AFIO_MUX_FSMC_NO_NADV	= AFIOMUX(10, 1, 1),	/*!< NADV isn't used */

	AFIO_MUX_TIM9_A2	= AFIOMUX(5, 1, 0),	/*!< A[2-3] */
	AFIO_MUX_TIM9_E5	= AFIOMUX(5, 1, 1),	/*!< E[5-6] */

#undef MAPR
#define MAPR 0x20	/* MAPR3 */

	AFIO_GMUX_TIM9_A2	= AFIOMUX(0, 0xf, 0),	/*!< A[2-3] */
	AFIO_GMUX_TIM9_E5	= AFIOMUX(0, 0xf, 1),	/*!< E[5-6] */

#undef MAPR
#define MAPR 0x24	/* MAPR4 */

	AFIO_GMUX_TIM5_CH4_A3	= AFIOMUX(19, 1, 0),	/*!< CH4 -> A3 */
	AFIO_GMUX_TIM5_CH4_LSI	= AFIOMUX(19, 1, 1),	/*!< LSI -> CH4 */

	AFIO_GMUX_TIM4_B6	= AFIOMUX(12, 0xf, 0),	/*!< B[6-9] */
	AFIO_GMUX_TIM4_D12	= AFIOMUX(12, 0xf, 1),	/*!< D[12-15] */

	AFIO_GMUX_TIM3_A6	= AFIOMUX(8, 0xf, 0),	/*!< A[6-7] B[0-1] */
	AFIO_GMUX_TIM3_B4	= AFIOMUX(8, 0xf, 1),	/*!< B[4-5] B[0-1] */

	AFIO_GMUX_TIM2_ITR1_TIM8= AFIOMUX(6, 3, 0),	/*!< TIM8TRGO->TIM2ITR1 */
	AFIO_GMUX_TIM2_ITR1_PTP	= AFIOMUX(6, 3, 2),	/*!< EMAC_PTP->TIM2ITR1 */
	AFIO_GMUX_TIM2_ITR1_SOF	= AFIOMUX(6, 3, 3),	/*!< SOF->TIM2ITR1 */

	AFIO_GMUX_TIM2_A0_A2	= AFIOMUX(4, 3, 0),	/*!< A[0-1] A[2-3] */
	AFIO_GMUX_TIM2_A15_A2	= AFIOMUX(4, 3, 1),	/*!< A15 B3 A[2-3] */
	AFIO_GMUX_TIM2_A0_B10	= AFIOMUX(4, 3, 2),	/*!< A[0-1] B[10-11] */
	AFIO_GMUX_TIM2_A15_B10	= AFIOMUX(4, 3, 3),	/*!< A15 B3 B[10-11] */

	AFIO_GMUX_TIM1_A12_B12	= AFIOMUX(0, 0xf, 0),	/*!< A[8-12] B[12-15] */
	AFIO_GMUX_TIM1_A12_B6	= AFIOMUX(0, 0xf, 1),	/*!< A[6-12] B[0-1] */
	AFIO_GMUX_TIM1_E7	= AFIOMUX(0, 0xf, 3),	/*!< E[7-15] */

#undef MAPR
#define MAPR 0x28	/* MAPR5 */

	AFIO_GMUX_SPI4_E4	= AFIOMUX(28, 0xf, 0),	/*!< E2 E[4-6] C8 */
	AFIO_GMUX_SPI4_E12	= AFIOMUX(28, 0xf, 1),	/*!< E[11-14] C8 */
	AFIO_GMUX_SPI4_B6	= AFIOMUX(28, 0xf, 2),	/*!< B[6-9] C8 */
	AFIO_GMUX_SPI4_A10	= AFIOMUX(28, 0xf, 3),	/*!< B[6-9] A10 */

	AFIO_GMUX_SPI3_A15	= AFIOMUX(24, 0xf, 0),	/*!< A15 B[3-5] C7 */
	AFIO_GMUX_SPI3_A4	= AFIOMUX(24, 0xf, 1),	/*!< A4 C[10-12] C7 */
	AFIO_GMUX_SPI3_A15B	= AFIOMUX(24, 0xf, 2),	/*!< A15 B[3-5] B10 */
	AFIO_GMUX_SPI3_A4B	= AFIOMUX(24, 0xf, 3),	/*!< A4 C[10-12] B10 */

	AFIO_GMUX_SPI2_MCK_C6	= AFIOMUX(20, 0xf, 0),	/*!< MCK => C6 */
	AFIO_GMUX_SPI2_MCK_A3	= AFIOMUX(20, 0xf, 1),	/*!< MCK => A3 */
	AFIO_GMUX_SPI2_MCK_A6	= AFIOMUX(20, 0xf, 2),	/*!< MCK => A6 */

	AFIO_GMUX_SPI1_A4	= AFIOMUX(16, 0xf, 0),	/*!< A[4-7] B0 */
	AFIO_GMUX_SPI1_A15	= AFIOMUX(16, 0xf, 1),	/*!< A15 B[3-5] B0 */
	AFIO_GMUX_SPI1_A4B	= AFIOMUX(16, 0xf, 2),	/*!< A[4-7] B6 */
	AFIO_GMUX_SPI1_A15B	= AFIOMUX(16, 0xf, 3),	/*!< A15 B[3-5] B6 */

	AFIO_GMUX_I2C3_C9	= AFIOMUX(12, 0xf, 0),	/*!< A8 C9 A9 */
	AFIO_GMUX_I2C3_B4	= AFIOMUX(12, 0xf, 1),	/*!< A8 B4 A9 */

	AFIO_GMUX_I2C1_B6	= AFIOMUX(4, 0xf, 0),	/*!< B6 B7 B5 */
	AFIO_GMUX_I2C1_B8	= AFIOMUX(4, 0xf, 1),	/*!< B8 B9 B5 */

	AFIO_GMUX_USART5_C12	= AFIOMUX(0, 0xf, 0),	/*!< C12 D12 */
	AFIO_GMUX_USART5_B9	= AFIOMUX(0, 0xf, 1),	/*!< B9 B8 */

#undef MAPR
#define MAPR 0x2c	/* MAPR6 */

	AFIO_GMUX_UART4_C10	= AFIOMUX(28, 0xf, 0),	/*!< C10 C11 */
	AFIO_GMUX_UART4_A0	= AFIOMUX(28, 0xf, 1),	/*!< A0 A1 */

	AFIO_GMUX_USART3_B10	= AFIOMUX(24, 0xf, 0),	/*!< B[10-12] B[13-14] */
	AFIO_GMUX_USART3_C10	= AFIOMUX(24, 0xf, 1),	/*!< C[10-12] B[13-14] */
	AFIO_GMUX_USART3_D8	= AFIOMUX(24, 0xf, 3),	/*!< D[8-12] */

	AFIO_GMUX_USART2_A0	= AFIOMUX(20, 0xf, 0),	/*!< A[0-4] */
	AFIO_GMUX_USART2_D3	= AFIOMUX(20, 0xf, 1),	/*!< D[3-7] */

	AFIO_GMUX_USART1_A9	= AFIOMUX(16, 0xf, 0),	/*!< A9 A10 */
	AFIO_GMUX_USART1_B6	= AFIOMUX(16, 0xf, 1),	/*!< B6 B7 */

	AFIO_GMUX_SDIO2_C0	= AFIOMUX(12, 0xf, 0),	/*!< C[0-1] C[3-5] A[4-7] */
	AFIO_GMUX_SDIO2_A4	= AFIOMUX(12, 0xf, 1),	/*!< A[2-7] */

	AFIO_GMUX_CAN2_B12	= AFIOMUX(4, 0xf, 0),	/*!< B12 B13 */
	AFIO_GMUX_CAN2_B5	= AFIOMUX(4, 0xf, 1),	/*!< B5 B6 */

	AFIO_GMUX_CAN1_A11	= AFIOMUX(0, 0xf, 0),	/*!< A11 A12 */
	AFIO_GMUX_CAN1_B8	= AFIOMUX(0, 0xf, 2),	/*!< B8 B9 */
	AFIO_GMUX_CAN1_D0	= AFIOMUX(0, 0xf, 3),	/*!< D0 D1 */

#undef MAPR
#define MAPR 0x30	/* MAPR7 */

	AFIO_GMUX_FSMC_NADV	= AFIOMUX(27, 1, 0),	/*!< NADV is used */
	AFIO_GMUX_FSMC_NO_NADV	= AFIOMUX(27, 1, 1),	/*!< NADV isn't used */

	AFIO_GMUX_FSMC_D5	= AFIOMUX(24, 7, 0),	/*!< D5 ... */
	AFIO_GMUX_FSMC_D2	= AFIOMUX(24, 7, 1),	/*!< D2 ... */
	AFIO_GMUX_FSMC_C2	= AFIOMUX(24, 7, 2),	/*!< C2 ... */

	AFIO_GMUX_PD01_NONE	= AFIOMUX(20, 1, 0),	/*!< not connected */
	AFIO_GMUX_PD01_OSC	= AFIOMUX(20, 1, 1),	/*!< OSCx => D[0-1] */

	AFIO_GMUX_SWJ_FULL_SWJ	= AFIOMUX(16, 7, 0),	/*!< full swd/jtag */
	AFIO_GMUX_SWJ_NO_JNTRST	= AFIOMUX(16, 7, 1),	/*!< full but B4 */
	AFIO_GMUX_SWJ_NO_JTAG	= AFIOMUX(16, 7, 2),	/*!< swd only */
	AFIO_GMUX_SWJ_NONE	= AFIOMUX(16, 7, 4),	/*!< all disabled */

	AFIO_GMUX_ADC2_ETRGREG_EXTI11	= AFIOMUX(9, 1, 0),	/*!< EXTI11 => ADC2 ETRG REG */
	AFIO_GMUX_ADC2_ETRGREG_TIM8	= AFIOMUX(9, 1, 1),	/*!< TIM8 => ADC2 ETRG REG */
	AFIO_GMUX_ADC2_ETRGINJ_EXTI15	= AFIOMUX(8, 1, 0),	/*!< EXTI15 => ADC2 ETRG INJ */
	AFIO_GMUX_ADC2_ETRGINJ_TIM8	= AFIOMUX(8, 1, 1),	/*!< TIM8 => ADC2 ETRG INJ */

	AFIO_GMUX_ADC1_ETRGREG_EXTI11	= AFIOMUX(5, 1, 0),	/*!< EXTI11 => ADC1 ETRG REG */
	AFIO_GMUX_ADC1_ETRGREG_TIM8	= AFIOMUX(5, 1, 1),	/*!< TIM8 => ADC1 ETRG REG */
	AFIO_GMUX_ADC1_ETRGINJ_EXTI15	= AFIOMUX(4, 1, 0),	/*!< EXTI15 => ADC1 ETRG INJ */
	AFIO_GMUX_ADC1_ETRGINJ_TIM8	= AFIOMUX(4, 1, 1),	/*!< TIM8 => ADC1 ETRG INJ */

	AFIO_GMUX_SPI_FLASH_DIS	= AFIOMUX(3, 1, 0),	/*!< SPI FLASH disable */
	AFIO_GMUX_SPI_FLASH_ENA	= AFIOMUX(3, 1, 1),	/*!< SPI FLASH enable */

	AFIO_GMUX_SPI_FLASH_A11	= AFIOMUX(0, 7, 0),	/*!< B1 A8 A11 ... */
	AFIO_GMUX_SPI_FLASH_B10	= AFIOMUX(0, 7, 1),	/*!< B1 A8 B10 ... */

#undef MAPR
#define MAPR 0x34	/* MAPR8 */

	AFIO_GMUX_UART8_E1	= AFIOMUX(28, 0xf, 0),	/*!< E1 E0 */
	AFIO_GMUX_UART8_C2	= AFIOMUX(28, 0xf, 1),	/*!< C2 C3 */

	AFIO_GMUX_UART7_E8	= AFIOMUX(24, 0xf, 0),	/*!< E8 E7 */
	AFIO_GMUX_UART7_B4	= AFIOMUX(24, 0xf, 1),	/*!< B4 B3 */

	AFIO_GMUX_USART6_C6	= AFIOMUX(20, 0xf, 0),	/*!< C6 C7 */
	AFIO_GMUX_USART6_A4	= AFIOMUX(20, 0xf, 1),	/*!< A4 A5 */

	AFIO_GMUX_PTP_PPS_NONE	= AFIOMUX(19, 1, 0),	/*!< not connected */
	AFIO_GMUX_PTP_PPS_B5	= AFIOMUX(19, 1, 1),	/*!< PTP_PPS->PB5 */

	AFIO_GMUX_ETHMAC_MII	= AFIOMUX(18, 1, 0),	/*!< MII */
	AFIO_GMUX_ETHMAC_RMII	= AFIOMUX(18, 1, 1),	/*!< RMII */

	AFIO_GMUX_ETHMAC_A7	= AFIOMUX(16, 3, 0),	/*!< A7 C[4-5] B[0-1] */
	AFIO_GMUX_ETHMAC_D8	= AFIOMUX(16, 3, 1),	/*!< D[8-12] */

#undef MAPR

};

/**@}*/

#undef AFIOMUX

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void gpio_set_mode(uint32_t gpioport, uint8_t mode, uint8_t cnf,
		   uint16_t gpios);
void gpio_set_eventout(uint8_t evoutport, uint8_t evoutpin);
void gpio_set_mux(enum afio_mux mux);

END_DECLS

#endif
