/** @addtogroup dmamux_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
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

/** @cond */
#if defined(LIBOPENCM3_DMAMUX_H)
/** @endcond */
#ifndef LIBOPENCM3_DMAMUX_COMMON_ALL_H
#define LIBOPENCM3_DMAMUX_COMMON_ALL_H

/**@{*/

#define DMAMUX_CxCR(dmamux_base, dma_channel)	MMIO32((dmamux_base) + 0x04 * ((dma_channel) - 1))
#define DMAMUX1_CxCR(dma_channel)				DMAMUX_CxCR(DMAMUX1, (dma_channel))
#define DMAMUX2_CxCR(dma_channel)				DMAMUX_CxCR(DMAMUX2, (dma_channel))

#define DMAMUX_CSR(dmamux_base)				MMIO32((dmamux_base) + 0x80)
#define DMAMUX1_CSR(dmamux_base)			DMAMUX_CSR(DMAMUX1)
#define DMAMUX2_CSR(dmamux_base)			DMAMUX_CSR(DMAMUX2)

#define DMAMUX_CFR(dmamux_base)				MMIO32((dmamux_base) + 0x84)
#define DMAMUX1_CFR(dmamux_base)			DMAMUX_CFR(DMAMUX1)
#define DMAMUX2_CFR(dmamux_base)			DMAMUX_CFR(DMAMUX2)

#define DMAMUX_RGxCR(dmamux_base, rg_channel)	MMIO32((dmamux_base) + 0x100 + 0x04 * ((rg_channel) - 1))
#define DMAMUX1_RGxCR(dmamux_base, rg_channel)	DMAMUX_RGxCR(DMAMUX1, (rg_channel))
#define DMAMUX2_RGxCR(dmamux_base, rg_channel)	DMAMUX_RGxCR(DMAMUX2, (rg_channel))

#define DMAMUX_RGSR(dmamux_base)			MMIO32((dmamux_base) + 0x140)
#define DMAMUX1_RGSR(dmamux_base)			DMAMUX_RSGR(DMAMUX1)
#define DMAMUX2_RGSR(dmamux_base)			DMAMUX_RSGR(DMAMUX2)

#define DMAMUX_RGCFR(dmamux_base)			MMIO32((dmamux_base) + 0x144)
#define DMAMUX1_RGCFR(dmamux_base)			DMAMUX_RGCFR(DMAMUX1)
#define DMAMUX2_RGCFR(dmamux_base)			DMAMUX_RGCFR(DMAMUX2)

/** @defgroup dmamux_cxcr CxCR DMA request line multiplexer channel x control register
@{*/

/** DMAMUX_CxCR_SYNC_ID Synchronization input selected */
#define DMAMUX_CxCR_SYNC_ID_SHIFT		24
#define DMAMUX_CxCR_SYNC_ID_MASK		0x1f

/** DMAMUX_CxCR_NBREQ Number (minus 1) of DMA requests to forward */
#define DMAMUX_CxCR_NBREQ_SHIFT		19
#define DMAMUX_CxCR_NBREQ_MASK		0x1f

#define DMAMUX_CxCR_SPOL_SHIFT		17
#define DMAMUX_CxCR_SPOL_MASK		0x03
/** @defgroup dmamux_cxcr_spol SPOL Event Polarity
* @brief Synchronization event type selector
@{*/
#define	DMAMUX_CxCR_SPOL_NO_EVENT	0
#define	DMAMUX_CxCR_SPOL_RISING_EDGE	1
#define	DMAMUX_CxCR_SPOL_FALLING_EDEG	2
#define	DMAMUX_CxCR_SPOL_BOTH_EDGES 3
/**@}*/

/** DMAMUX_CxCR_SE Synchronous operating mode enable/disable */
#define DMAMUX_CxCR_SE		(1 << 16)

/** DMAMUX_CxCR_EGE Event generation enable/disable */
#define DMAMUX_CxCR_EGE		(1 << 9)

/** DMAMUX_CxCR_SOIE Interrupt enable at synchronization event overrun */
#define DMAMUX_CxCR_SOIE		(1 << 8)

/** DMAMUX_CxCR_DMAREQ_ID Input DMA request line selected */
#define DMAMUX_CxCR_DMAREQ_ID_SHIFT		0
#define DMAMUX_CxCR_DMAREQ_ID_MASK		0xff

/**@}*/

/** @defgroup dmamux_csr CSR request line multiplexer interrupt channel status register
@{*/

/** DMAMUX_CSR_SOF Synchronization overrun event flag */
#define DMAMUX_CSR_SOF(dma_channel)		(1 << ((dma_channel) - 1))

/**@}*/

/** @defgroup dmamux_cfr CFR request line multiplexer interrupt clear flag register
@{*/

/** DMAMUX_CFR_CSOF Clear synchronization overrun event flag */
#define DMAMUX_CFR_CSOF(dma_channel)	(1 << ((dma_channel) - 1))

/**@}*/

/** @defgroup dmamux_rgxcr RGxCR DMA request generator channel x control register
@{*/

/** DMAMUX_RGxCR_GNBREQ GNBREQ Number (minus 1) of DMA requests to generate */
#define DMAMUX_RGxCR_GNBREQ_SHIFT		19
#define DMAMUX_RGxCR_GNBREQ_MASK		0x1f

#define DMAMUX_RGxCR_GPOL_SHIFT		17
#define DMAMUX_RGxCR_GPOL_MASK		0x03
/** @defgroup dmamux_rgxcr_gpol GPOL Event Polarity
* @brief DMA request generator trigger event type selection
@{*/
#define	DMAMUX_RGxCR_GPOL_NO_EVENT	0
#define	DMAMUX_RGxCR_GPOL_RISING_EDGE	1
#define	DMAMUX_RGxCR_GPOL_FALLING_EDEG	2
#define	DMAMUX_RGxCR_GPOL_BOTH_EDGES 3
/**@}*/

/** DMAMUX_RGxCR_GE GE DMA request generator channel enable/disable */
#define DMAMUX_RGxCR_GE		(1 << 16)

/** DMAMUX_RGxCR_OIE OIE Interrupt enable at trigger event overrun */
#define DMAMUX_RGxCR_OIE		(1 << 8)

/** DMAMUX_RGxCR_SIG_ID SIG_ID DMA request trigger input selected */
#define DMAMUX_RGxCR_SIG_ID_SHIFT		0
#define DMAMUX_RGxCR_SIG_ID_MASK		0x1f

/**@}*/

/** @defgroup dmamux_rgsr RGSR DMA request generator interrupt status register
@{*/

/** DMAMUX_RGSR_OF Trigger OF event overrun flag */
#define DMAMUX_RGSR_OF(rg_channel)	(1 << ((rg_channel) - 1))

/**@}*/

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
/** @cond */
#else
#warning "dmamux_common_all.h should not be included explicitly, only via dmamux.h"
#endif
/** @endcond */
