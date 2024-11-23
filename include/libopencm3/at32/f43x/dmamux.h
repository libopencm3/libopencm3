/** @defgroup dmamux_defines DMAMUX Defines

@ingroup AT32F43x_defines

@brief Defined Constants and Types for the AT32F43x DMAMUX

@version 1.0.0

@date 16 November 2024

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

#ifndef LIBOPENCM3_DMAMUX_H
#define LIBOPENCM3_DMAMUX_H

/**@{*/

/* AT32F43x RM mentions only common DMA1/DMA2 base,
   actual offsets were taken from firmware library */
#define DMA1MUX_BASE				(DMA12_BASE + 0x0   + 0x104)
#define DMA2MUX_BASE				(DMA12_BASE + 0x200 + 0x104)

/** @defgroup dmamux_reg_base DMAMUX register base addresses
 * @{
 */
#define DMAMUX1					DMA1MUX_BASE
#define DMAMUX2					DMA2MUX_BASE
/**@}*/

/* DMA_MUXCxCTRL x=1..7 */
#define DMAMUX_CxCR(dmamux_base, dma_channel)	MMIO32((dmamux_base) + 4 * ((dma_channel) - 1))
#define DMAMUX1_CxCR(dma_channel)		DMAMUX_CxCR(DMAMUX1, (dma_channel))
#define DMAMUX2_CxCR(dma_channel)		DMAMUX_CxCR(DMAMUX2, (dma_channel))

/* DMA_MUXGxCTRL x=1..4 */
#define DMAMUX_RGxCR(dmamux_base, rg_channel)	MMIO32((dmamux_base) + 0x1c + 4 * ((rg_channel) - 1))
#define DMAMUX1_RGxCR(rg_channel)		DMAMUX_RGxCR(DMAMUX1, (rg_channel))
#define DMAMUX2_RGxCR(rg_channel)		DMAMUX_RGxCR(DMAMUX2, (rg_channel))

/* DMA_MUXSYNCSTS */
#define DMAMUX_CSR(dmamux_base)			MMIO32((dmamux_base) + 0x2c)
#define DMAMUX1_CSR				DMAMUX_CSR(DMAMUX1)
#define DMAMUX2_CSR				DMAMUX_CSR(DMAMUX2)

/* DMA_MUXSYNCCLR */
#define DMAMUX_CFR(dmamux_base)			MMIO32((dmamux_base) + 0x30)
#define DMAMUX1_CFR				DMAMUX_CFR(DMAMUX1)
#define DMAMUX2_CFR				DMAMUX_CFR(DMAMUX2)

/* DMA_MUXGSTS */
#define DMAMUX_RGSR(dmamux_base)		MMIO32((dmamux_base) + 0x34)
#define DMAMUX1_RGSR				DMAMUX_RSGR(DMAMUX1)
#define DMAMUX2_RGSR				DMAMUX_RSGR(DMAMUX2)

/* DMA_MUXGCLR */
#define DMAMUX_RGCFR(dmamux_base)		MMIO32((dmamux_base) + 0x38)
#define DMAMUX1_RGCFR				DMAMUX_RGCFR(DMAMUX1)
#define DMAMUX2_RGCFR				DMAMUX_RGCFR(DMAMUX2)

/* --- DMAMUX_CxCR (DMA_MUXCxCTRL) values ---------------------------------- */
/** @defgroup dmamux_cxcr CxCR DMA request line multiplexer channel x control register
@{*/

/** DMAMUX_CxCR_SYNC_ID Synchronization input selected */
#define DMAMUX_CxCR_SYNC_ID_SHIFT		24		/* SYNCSEL */
#define DMAMUX_CxCR_SYNC_ID_MASK		0x1f

/** DMAMUX_CxCR_NBREQ Number (minus 1) of DMA requests to forward */
#define DMAMUX_CxCR_NBREQ_SHIFT			19		/* REQCNT */
#define DMAMUX_CxCR_NBREQ_MASK			0x1f

#define DMAMUX_CxCR_SPOL_SHIFT			17		/* SYNCPOL */
#define DMAMUX_CxCR_SPOL_MASK			0x03

/** @defgroup dmamux_cxcr_spol SPOL Event Polarity
* @brief Synchronization event type selector
@{*/
#define	DMAMUX_CxCR_SPOL_NO_EVENT		0
#define	DMAMUX_CxCR_SPOL_RISING_EDGE		1
#define	DMAMUX_CxCR_SPOL_FALLING_EDEG		2
#define	DMAMUX_CxCR_SPOL_BOTH_EDGES		3
/**@}*/

/** DMAMUX_CxCR_SE Synchronous operating mode enable/disable */
#define DMAMUX_CxCR_SE				(1 << 16)	/* SYNCEN */

/** DMAMUX_CxCR_EGE Event generation enable/disable */
#define DMAMUX_CxCR_EGE				(1 << 9)	/* EVTGEN */

/** DMAMUX_CxCR_EGE Syncronization overrun interrupt enable/disable */
#define DMAMUX_CxCR_SOIE			(1 << 8)	/* SYNCOVIEN */

/** DMAMUX_CxCR_DMAREQ_ID Input DMA request line selected */
#define DMAMUX_CxCR_DMAREQ_ID_SHIFT		0		/* REQSEL */
#define DMAMUX_CxCR_DMAREQ_ID_MASK		0x7f

/**@}*/

/** @defgroup dmamux_cxcr_sync_id SYNCID Synchronization input selected
@{*/
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE0		0
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE1		1
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE2		2
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE3		3
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE4		4
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE5		5
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE6		6
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE7		7
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE8		8
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE9		9
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE10		10
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE11		11
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE12		12
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE13		13
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE14		14
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE15		15
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH0_EVT	16
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH1_EVT	17
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH2_EVT	18
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH3_EVT	19
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH4_EVT	20
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH5_EVT	21
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH6_EVT	22
/**@}*/

/** @defgroup dmamux_cxcr_dmareq_id DMAREQID DMA request line selected
@{*/
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN0	1
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN1	2
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN2	3
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN3	4
#define DMAMUX_CxCR_DMAREQ_ID_ADC1		5
#define DMAMUX_CxCR_DMAREQ_ID_DAC1		6
/* 7 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_TIM6_UP		8
#define DMAMUX_CxCR_DMAREQ_ID_TIM7_UP		9
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_RX		10
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_TX		11
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_RX		12
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_TX		13
#define DMAMUX_CxCR_DMAREQ_ID_SPI3_RX		14
#define DMAMUX_CxCR_DMAREQ_ID_SPI3_TX		15
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_RX		16
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_TX		17
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_RX		18
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_TX		19
#define DMAMUX_CxCR_DMAREQ_ID_I2C3_RX		20
#define DMAMUX_CxCR_DMAREQ_ID_I2C3_TX		21
/* 22-23 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_USART1_RX		24
#define DMAMUX_CxCR_DMAREQ_ID_USART1_TX		25
#define DMAMUX_CxCR_DMAREQ_ID_USART2_RX		26
#define DMAMUX_CxCR_DMAREQ_ID_USART2_TX		27
#define DMAMUX_CxCR_DMAREQ_ID_USART3_RX		28
#define DMAMUX_CxCR_DMAREQ_ID_USART3_TX		29
#define DMAMUX_CxCR_DMAREQ_ID_UART4_RX		30
#define DMAMUX_CxCR_DMAREQ_ID_UART4_TX		31
#define DMAMUX_CxCR_DMAREQ_ID_UART5_RX		32
#define DMAMUX_CxCR_DMAREQ_ID_UART5_TX		33
/* 34-35 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_ADC2		36
#define DMAMUX_CxCR_DMAREQ_ID_ADC3		37
/* 38 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_SDIO1		39
#define DMAMUX_CxCR_DMAREQ_ID_QSPI1		40
#define DMAMUX_CxCR_DMAREQ_ID_DAC2		41
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH1		42
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH2		43
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH3		44
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH4		45
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_UP		46
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_TRIG		47
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_COM		48
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH1		49
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH2		50
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH3		51
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH4		52
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_UP		53
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_TRIG		54
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_COM		55
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH1		56
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH2		57
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH3		58
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH4		59
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_UP		60
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH1		61
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH2		62
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH3		63
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH4		64
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_UP		65
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_TRIG		66
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH1		67
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH2		68
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH3		69
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH4		70
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_UP		71
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH1		72
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH2		73
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH3		74
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH4		75
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_UP		76
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_TRIG		77
/* 78-85 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH1		86
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH2		87
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH3		88
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH4		89
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_UP		90
/* 91-92 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_TRIG	93
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_COM		94
/* 95-102 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_SDIO2		103
#define DMAMUX_CxCR_DMAREQ_ID_QSPI2		104
#define DMAMUX_CxCR_DMAREQ_ID_DCMI		105
#define DMAMUX_CxCR_DMAREQ_ID_SPI4_RX		106
#define DMAMUX_CxCR_DMAREQ_ID_SPI4_TX		107
/* 108-109 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_I2S2_RX		110
#define DMAMUX_CxCR_DMAREQ_ID_I2S2_TX		111
#define DMAMUX_CxCR_DMAREQ_ID_I2S3_RX		112
#define DMAMUX_CxCR_DMAREQ_ID_I2S3_TX		113
#define DMAMUX_CxCR_DMAREQ_ID_USART6_RX		114
#define DMAMUX_CxCR_DMAREQ_ID_USART6_TX		115
#define DMAMUX_CxCR_DMAREQ_ID_UART7_RX		116
#define DMAMUX_CxCR_DMAREQ_ID_UART7_TX		117
#define DMAMUX_CxCR_DMAREQ_ID_UART8_RX		118
#define DMAMUX_CxCR_DMAREQ_ID_UART8_TX		119
/* 120-125 reserved */
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_TRIG		126
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_TRIG		127
/**@}*/

/* --- DMAMUX_RGxCR (DMA_MUXGxCTRL) values --------------------------------- */
/** @defgroup dmamux_rgxcr RGxCR DMA request generator channel x control register
@{*/

/** DMAMUX_RGxCR_GNBREQ GNBREQ Number (minus 1) of DMA requests to generate */
#define DMAMUX_RGxCR_GNBREQ_SHIFT		19		/* GREQCNT */
#define DMAMUX_RGxCR_GNBREQ_MASK		0x1f

#define DMAMUX_RGxCR_GPOL_SHIFT			17		/* GPOL */
#define DMAMUX_RGxCR_GPOL_MASK			0x03
/** @defgroup dmamux_rgxcr_gpol GPOL Event Polarity
* @brief DMA request generator trigger event type selection
@{*/
#define	DMAMUX_RGxCR_GPOL_NO_EVENT		0
#define	DMAMUX_RGxCR_GPOL_RISING_EDGE		1
#define	DMAMUX_RGxCR_GPOL_FALLING_EDEG		2
#define	DMAMUX_RGxCR_GPOL_BOTH_EDGES		3
/**@}*/

/** DMAMUX_RGxCR_GE GE DMA request generator channel enable/disable */
#define DMAMUX_RGxCR_GE				(1 << 16)	/* GEN */

/** DMAMUX_RGxCR_OIE OIE Interrupt enable at trigger event overrun */
#define DMAMUX_RGxCR_OIE			(1 << 8)	/* TRGOVIEN */

/** DMAMUX_RGxCR_SIG_ID SIG_ID DMA request trigger input selected */
#define DMAMUX_RGxCR_SIG_ID_SHIFT		0
#define DMAMUX_RGxCR_SIG_ID_MASK		0x1f		/* SIGSEL */

/**@}*/

/* --- DMAMUX_CSR (DMA_MUXSYNCSTS) values ---------------------------------- */
/** @defgroup dmamux_csr CSR request line multiplexer interrupt channel status register
@{*/
/** DMAMUX_CSR_SOF Synchronization overrun event flag */
#define DMAMUX_CSR_SOF(dma_channel)		(1 << ((dma_channel) - 1))
/**@}*/

/* --- DMAMUX_CFR (DMA_MUXSYNCCLR) values ---------------------------------- */
/** @defgroup dmamux_cfr CFR request line multiplexer interrupt clear flag register
@{*/
/** DMAMUX_CFR_CSOF Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF(dma_channel)		(1 << ((dma_channel) - 1))
/**@}*/

/* --- DMAMUX_RGSR (DMA_MUXGSTS) values ------------------------------------ */
/** @defgroup dmamux_rgsr RGSR DMA request generator interrupt status register
@{*/
/** DMAMUX_RGSR_OF Trigger OF event overrun flag */
#define DMAMUX_RGSR_OF(rg_channel)		(1 << ((rg_channel) - 1))
/**@}*/

/* --- DMAMUX_RGCFR (DMA_MUXGCLR) values ----------------------------------- */
/** @defgroup dmamux_rgcfr RGCFR DMA request generator clear flag register
@{*/
/** DMAMUX_RGCFR_COF COF Clear trigger event overrun flag */
#define DMAMUX_RGCFR_COF(rg_channel)	(1 << ((rg_channel) - 1))
/**@}*/

/* --- Generic values ---------------------------------------- */

/** @defgroup dmamux_rg_channel DMAMUX Request Generator Channel Number
@{*/
#define DMAMUX_RG_CHANNEL1			1
#define DMAMUX_RG_CHANNEL2			2
#define DMAMUX_RG_CHANNEL3			3
#define DMAMUX_RG_CHANNEL4			4
/**@}*/

/* --- function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dmamux_reset_dma_channel(uint32_t dmamux, uint8_t channel);
void dmamux_enable_dma_request_event_generation(uint32_t dmamux, uint8_t channel);
void dmamux_disable_dma_request_event_generation(uint32_t dmamux, uint8_t channel);

void dmamux_set_dma_channel_request(uint32_t dmamux, uint8_t channel, uint8_t request_id);
uint8_t dmamux_get_dma_channel_request(uint32_t dmamux, uint8_t channel);

void dmamux_enable_dma_request_sync(uint32_t dmamux, uint8_t channel);
void dmamux_disable_dma_request_sync(uint32_t dmamux, uint8_t channel);

void dmamux_set_dma_request_sync_input(uint32_t dmamux, uint8_t channel, uint8_t sync_id);
void dmamux_set_dma_request_sync_pol(uint32_t dmamux, uint8_t channel, uint8_t polarity);
void dmamux_set_dma_request_sync_nbreq(uint32_t dmamux, uint8_t channel, uint8_t nbreq);

void dmamux_enable_dma_request_sync_overrun_interrupt(uint32_t dmamux, uint8_t channel);
void dmamux_disable_dma_request_sync_overrun_interrupt(uint32_t dmamux, uint8_t channel);
uint32_t dmamux_get_dma_request_sync_overrun(uint32_t dmamux, uint8_t channel);
void dmamux_clear_dma_request_sync_overrun(uint32_t dmamux, uint8_t channel);

void dmamux_reset_request_generator_channel(uint32_t dmamux, uint8_t rg_channel);
void dmamux_enable_request_generator(uint32_t dmamux, uint8_t rg_channel);
void dmamux_disable_request_generator(uint32_t dmamux, uint8_t rg_channel);

void dmamux_set_request_generator_trigger(uint32_t dmamux, uint8_t rg_channel, uint8_t sig_id);
void dmamux_set_request_generator_trigger_pol(uint32_t dmamux, uint8_t rg_channel, uint8_t polarity);
void dmamux_set_request_generator_trigger_gnbreq(uint32_t dmamux, uint8_t rg_channel, uint8_t gnbreq);

void dmamux_enable_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel);
void dmamux_disable_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel);
uint32_t dmamux_get_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel);
void dmamux_clear_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel);

END_DECLS

/**@}*/

#endif
