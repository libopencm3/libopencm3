/** @defgroup dma_defines DMA Defines

@ingroup AT32F40x_defines

@brief Defined Constants and Types for the AT32F40x DMA Controller

@version 1.0.0

@date 26 November 2022

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

#ifndef LIBOPENCM3_DMA_H
#define LIBOPENCM3_DMA_H

#include <libopencm3/stm32/common/dma_common_l1f013.h>

/* --- DMA registers (continued) ------------------------------------------- */

/* DMA channel selection registers (DMAx_CSELRx) */
#define DMA_CSELR0(dma_base)		MMIO32((dma_base) + 0xA0)
#define DMA_CSELR1(dma_base)		MMIO32((dma_base) + 0xA4)

/* --- DMA_CSELRx values --------------------------------------------------- */
#define DMA_CSEL_FLEX_MODE		(1 << 24)

#define DMA_CSELR_CxS_SHIFT(channel)	(8 * (((channel) - 1) & 0x3))
#define DMA_CSELR_CxS_MASK		(0xff)

enum dma_request_id {
	DMA_REQ_ADC1		= 1,
	DMA_REQ_ADC3		= 3,

	DMA_REQ_DAC1		= 5,
	DMA_REQ_DAC2		= 6,

	DMA_REQ_SPI1_RX		= 9,
	DMA_REQ_SPI1_TX		= 10,

	DMA_REQ_SPI2_RX		= 11,
	DMA_REQ_SPI2_TX		= 12,

	DMA_REQ_SPI3_RX		= 13,
	DMA_REQ_SPI3_TX		= 14,

	DMA_REQ_SPI4_RX		= 15,
	DMA_REQ_SPI4_TX		= 16,

	DMA_REQ_I2S2EXT_RX	= 17,
	DMA_REQ_I2S2EXT_TX	= 18,

	DMA_REQ_I2S3EXT_RX	= 19,
	DMA_REQ_I2S3EXT_TX	= 20,

	DMA_REQ_USART1_RX	= 25,
	DMA_REQ_USART1_TX	= 26,

	DMA_REQ_USART2_RX	= 27,
	DMA_REQ_USART2_TX	= 28,

	DMA_REQ_USART3_RX	= 29,
	DMA_REQ_USART3_TX	= 30,

	DMA_REQ_UART4_RX	= 31,
	DMA_REQ_UART4_TX	= 32,

	DMA_REQ_UART5_RX	= 33,
	DMA_REQ_UART5_TX	= 34,

	DMA_REQ_USART6_RX	= 35,
	DMA_REQ_USART6_TX	= 36,

	DMA_REQ_UART7_RX	= 37,
	DMA_REQ_UART7_TX	= 38,

	DMA_REQ_UART8_RX	= 39,
	DMA_REQ_UART8_TX	= 40,

	DMA_REQ_I2C1_RX		= 41,
	DMA_REQ_I2C1_TX		= 42,

	DMA_REQ_I2C2_RX		= 43,
	DMA_REQ_I2C2_TX		= 44,

	DMA_REQ_I2C3_RX		= 45,
	DMA_REQ_I2C3_TX		= 46,

	DMA_REQ_SDIO1		= 49,
	DMA_REQ_SDIO2		= 50,

	DMA_REQ_TIM1_TRIG	= 53,
	DMA_REQ_TIM1_COM	= 54,
	DMA_REQ_TIM1_UP		= 55,
	DMA_REQ_TIM1_CH1	= 56,
	DMA_REQ_TIM1_CH2	= 57,
	DMA_REQ_TIM1_CH3	= 58,
	DMA_REQ_TIM1_CH4	= 59,

	DMA_REQ_TIM2_TRIG	= 61,
	DMA_REQ_TIM2_UP		= 63,
	DMA_REQ_TIM2_CH1	= 64,
	DMA_REQ_TIM2_CH2	= 65,
	DMA_REQ_TIM2_CH3	= 66,
	DMA_REQ_TIM2_CH4	= 67,

	DMA_REQ_TIM3_TRIG	= 69,
	DMA_REQ_TIM3_UP		= 71,
	DMA_REQ_TIM3_CH1	= 72,
	DMA_REQ_TIM3_CH2	= 73,
	DMA_REQ_TIM3_CH3	= 74,
	DMA_REQ_TIM3_CH4	= 75,

	DMA_REQ_TIM4_TRIG	= 77,
	DMA_REQ_TIM4_UP		= 79,
	DMA_REQ_TIM4_CH1	= 80,
	DMA_REQ_TIM4_CH2	= 81,
	DMA_REQ_TIM4_CH3	= 82,
	DMA_REQ_TIM4_CH4	= 83,

	DMA_REQ_TIM5_TRIG	= 85,
	DMA_REQ_TIM5_UP		= 87,
	DMA_REQ_TIM5_CH1	= 88,
	DMA_REQ_TIM5_CH2	= 89,
	DMA_REQ_TIM5_CH3	= 90,
	DMA_REQ_TIM5_CH4	= 91,

	DMA_REQ_TIM7_UP		= 103,

	DMA_REQ_TIM8_TRIG	= 109,
	DMA_REQ_TIM8_COM	= 110,
	DMA_REQ_TIM8_UP		= 111,
	DMA_REQ_TIM8_CH1	= 112,
	DMA_REQ_TIM8_CH2	= 113,
	DMA_REQ_TIM8_CH3	= 114,
	DMA_REQ_TIM8_CH4	= 115
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dma_enable_flex_mode(uint32_t dma);
void dma_disable_flex_mode(uint32_t dma);
void dma_set_channel_request(uint32_t dma, uint8_t channel,
			     enum dma_request_id request);

END_DECLS

#endif

