/** @defgroup dma_defines DMA Defines

@ingroup AT32F42x_defines

@brief Defined Constants and Types for the AT32F42x DMA Controller

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
	DMA_REQ_ADC1		= 5,

	DMA_REQ_I2C1_RX		= 10,
	DMA_REQ_I2C1_TX		= 11,

	DMA_REQ_I2C2_RX		= 12,
	DMA_REQ_I2C2_TX		= 13,

	DMA_REQ_SPI1_RX		= 16,
	DMA_REQ_SPI1_TX		= 17,

	DMA_REQ_SPI2_RX		= 18,
	DMA_REQ_SPI2_TX		= 19,

	DMA_REQ_TIM1_CH1	= 20,
	DMA_REQ_TIM1_CH2	= 21,
	DMA_REQ_TIM1_CH3	= 22,
	DMA_REQ_TIM1_CH4	= 23,
	DMA_REQ_TIM1_TRIG_UP	= 24,
	DMA_REQ_TIM1_COM	= 25,

	DMA_REQ_TIM2_CH1	= 26,
	DMA_REQ_TIM2_CH2	= 27,
	DMA_REQ_TIM2_CH3	= 28,
	DMA_REQ_TIM2_CH4	= 29,
	DMA_REQ_TIM2_TRIG	= 30,
	DMA_REQ_TIM2_UP		= 31,

	DMA_REQ_TIM3_CH1	= 32,
	DMA_REQ_TIM3_CH2	= 33,
	DMA_REQ_TIM3_CH3	= 34,
	DMA_REQ_TIM3_CH4	= 35,
	DMA_REQ_TIM3_TRIG	= 36,
	DMA_REQ_TIM3_UP		= 37,

	DMA_REQ_TIM6_UP		= 38,
	DMA_REQ_TIM7_UP		= 39,

	DMA_REQ_TIM15_CH1	= 40,
	DMA_REQ_TIM15_CH2	= 41,
	DMA_REQ_TIM15_TRIG	= 42,
	DMA_REQ_TIM15_UP	= 43,

	DMA_REQ_TIM16_CH1	= 44,
	DMA_REQ_TIM16_UP	= 46,

	DMA_REQ_TIM17_CH1	= 47,
	DMA_REQ_TIM17_UP	= 49,

	DMA_REQ_USART1_RX	= 50,
	DMA_REQ_USART1_TX	= 51,

	DMA_REQ_USART2_RX	= 52,
	DMA_REQ_USART2_TX	= 53,

	DMA_REQ_USART3_RX	= 54,
	DMA_REQ_USART3_TX	= 55,

	DMA_REQ_UART4_RX	= 56,
	DMA_REQ_UART4_TX	= 57,

	DMA_REQ_SPI3_RX		= 60,
	DMA_REQ_SPI3_TX		= 61
};

/* --- DMA_MAP values ------------------------------------------------------ */
enum dma_request_map {
	DMA_REQ_ADC_REMAP	= (1 << 0),
	DMA_REQ_USART1_TX_REMAP	= (1 << 1),
	DMA_REQ_USART1_RX_REMAP	= (1 << 2),
	DMA_REQ_TIM16_REMAP	= (1 << 3),
	DMA_REQ_TIM17_REMAP	= (1 << 4)
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dma_enable_flex_mode(uint32_t dma);
void dma_disable_flex_mode(uint32_t dma);
void dma_set_request_map(enum dma_request_map map);
void dma_set_channel_request(uint32_t dma, uint8_t channel,
			     enum dma_request_id request);

END_DECLS

#endif
