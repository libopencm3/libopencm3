/** @addtogroup dmamux_file DMAMUX peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>

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

#include <libopencm3/stm32/dmamux.h>

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Reset DMA Channel

Reset DMA Request configuration and interrupt flags for given DMA channel.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_reset_dma_channel(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) = 0;
	dmamux_clear_dma_request_sync_overrun(dmamux, channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set DMA Channel Request

Set DMA Request Signal ID (@ref dmamux_cxcr_dmareq_id) for given DMA channel.
Request must be set before enabling and after configuring said DMA channel.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
@param[in] request_id DMA request (@ref dmamux_cxcr_dmareq_id)
*/
void dmamux_set_dma_channel_request(uint32_t dmamux, uint8_t channel, uint8_t request_id)
{
	uint32_t reg32 = DMAMUX_CxCR(dmamux, channel);
	reg32 &= ~(DMAMUX_CxCR_DMAREQ_ID_MASK << DMAMUX_CxCR_DMAREQ_ID_SHIFT);
	reg32 |= ((request_id & DMAMUX_CxCR_DMAREQ_ID_MASK) << DMAMUX_CxCR_DMAREQ_ID_SHIFT);
	DMAMUX_CxCR(dmamux, channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Get DMA Channel Request Selection

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
@returns DMA request (@ref dmamux_cxcr_dmareq_id)
*/
uint8_t dmamux_get_dma_channel_request(uint32_t dmamux, uint8_t channel)
{
	return (DMAMUX_CxCR(dmamux, channel) >> DMAMUX_CxCR_DMAREQ_ID_SHIFT) & DMAMUX_CxCR_DMAREQ_ID_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Enable DMA Request Event Generation

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_enable_dma_request_event_generation(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) |= DMAMUX_CxCR_EGE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Disable DMA Request Event Generation

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_disable_dma_request_event_generation(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) &= ~DMAMUX_CxCR_EGE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set DMA Request Synchronization Input

Set DMAMUX request synchronization input trigger signal id (@ref dmamux_cxcr_sync_id)
for a given DMA channel.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
@param[in] sync_input_id synchronization signal input id (@ref dmamux_cxcr_sync_id)
*/
void dmamux_set_dma_request_sync_input(uint32_t dmamux, uint8_t channel, uint8_t sync_input_id)
{
	uint32_t reg32 = DMAMUX_CxCR(dmamux, channel);
	reg32 &= ~(DMAMUX_CxCR_SYNC_ID_MASK << DMAMUX_CxCR_SYNC_ID_SHIFT);
	reg32 |= ((sync_input_id & DMAMUX_CxCR_SYNC_ID_MASK) << DMAMUX_CxCR_SYNC_ID_SHIFT);
	DMAMUX_CxCR(dmamux, channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set DMA Request Synchronization Event Polarity

Set DMAMUX request synchronization input signal polarity (@ref dmamux_cxcr_spol)
for a given DMA channel.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
@param[in] polarity synchronization signal input polarity (@ref dmamux_cxcr_spol)
*/
void dmamux_set_dma_request_sync_pol(uint32_t dmamux, uint8_t channel, uint8_t polarity)
{
	uint32_t reg32 = DMAMUX_CxCR(dmamux, channel);
	reg32 &= ~(DMAMUX_CxCR_SPOL_MASK << DMAMUX_CxCR_SPOL_SHIFT);
	reg32 |= ((polarity & DMAMUX_CxCR_SPOL_MASK) << DMAMUX_CxCR_SPOL_SHIFT);
	DMAMUX_CxCR(dmamux, channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Enable DMA Request Synchronization

Enable DMAMUX request synchronization for a given DMA channel, propagating DMA
request when configured event edge (DMAREQ_CxCR_SPOL) is detected on previously
selected synchronization trigger input id.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_enable_dma_request_sync(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) |= DMAMUX_CxCR_SE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Disable DMA Request Synchronization

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_disable_dma_request_sync(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) &= ~DMAMUX_CxCR_SE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set DMA Request NBREQ To Forward

Set number of request to forward (minus 1) to the dma controller after a synchronization
event. This must be configured with synchronization and event generation disabled.

@param[in] dmamux DMAMUX Controller base address (@ref dmamux_reg_base)
@param[in] channel DMA Channel Number (@ref dma_ch)
@param[in] nbreq Number of DMA Requests to Forward - minus 1 (0..31)
*/
void dmamux_set_dma_request_sync_nbreq(uint32_t dmamux, uint8_t channel, uint8_t nbreq)
{
	uint32_t reg32 = DMAMUX_CxCR(dmamux, channel);
	reg32 &= ~(DMAMUX_CxCR_NBREQ_MASK << DMAMUX_CxCR_NBREQ_SHIFT);
	reg32 |= ((nbreq & DMAMUX_CxCR_NBREQ_MASK) << DMAMUX_CxCR_NBREQ_SHIFT);
	DMAMUX_CxCR(dmamux, channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Enable DMA Request Overrun Interrupt

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_enable_dma_request_sync_overrun_interrupt(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) |= DMAMUX_CxCR_SOIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Disable DMA Request Overrun Interrupt

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_disable_dma_request_sync_overrun_interrupt(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CxCR(dmamux, channel) &= ~DMAMUX_CxCR_SOIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Get DMA Request Synchronization Overrun Interrupt Flag

Get DMA Request Synchronization Overrun Interrupt for given DMA channel

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
@returns DMA Channel Synchronization Overrun Interrupt Flag
*/
uint32_t dmamux_get_dma_request_sync_overrun(uint32_t dmamux, uint8_t channel)
{
	return DMAMUX_CSR(dmamux) & DMAMUX_CSR_SOF(channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Clear DMA Request Synchronization Overrun Interrupt Flag

Clear DMA Request Synchronization Overrun Interrupt for given DMA channel

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] channel DMA channel number (@ref dma_ch)
*/
void dmamux_clear_dma_request_sync_overrun(uint32_t dmamux, uint8_t channel)
{
	DMAMUX_CFR(dmamux) = DMAMUX_CFR_CSOF(channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Reset Request Generator Channel

Reset Request Generator Channel Configuration and interrupt flags.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
*/
void dmamux_reset_request_generator_channel(uint32_t dmamux, uint8_t rg_channel)
{
	DMAMUX_CxCR(dmamux, rg_channel) = 0;
	dmamux_clear_request_generator_trigger_overrun_interrupt(dmamux, rg_channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Enable Request Generator Channel

Enable Request Generator Channel, Producting DMA Request on input signal trigger.
These Requests are usable by the DMA Request Router.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
*/
void dmamux_enable_request_generator(uint32_t dmamux, uint8_t rg_channel)
{
	DMAMUX_RGxCR(dmamux, rg_channel) |= DMAMUX_RGxCR_GE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Disable Request Generator Channel

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
*/
void dmamux_disable_request_generator(uint32_t dmamux, uint8_t rg_channel)
{
	DMAMUX_RGxCR(dmamux, rg_channel) &= ~DMAMUX_RGxCR_GE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set Request Generator Input Trigger Signal

Set DMAMUX Request Generator input signal id (@ref dmamux_rgxcr_sig_id) for given
Request Generator Channel.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
@param[in] sig_id Request Generator Channel Input Signal Id (@ref dmamux_rgxcr_sig_id)
*/
void dmamux_set_request_generator_trigger(uint32_t dmamux, uint8_t rg_channel, uint8_t sig_id)
{
	uint32_t reg32 = DMAMUX_RGxCR(dmamux, rg_channel);
	reg32 &= ~(DMAMUX_RGxCR_SIG_ID_MASK << DMAMUX_RGxCR_SIG_ID_SHIFT);
	reg32 |= ((sig_id & DMAMUX_RGxCR_SIG_ID_MASK) << DMAMUX_RGxCR_SIG_ID_SHIFT);
	DMAMUX_RGxCR(dmamux, rg_channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set Request Generator Trigger Polarity

Set DMAMUX Request Generator input signal polarity (@ref dmamux_rgxcr_gpol).

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
@param[in] polarity Trigger signal input polarity (@ref dmamux_rgxcr_gpol)
*/
void dmamux_set_request_generator_trigger_pol(uint32_t dmamux, uint8_t rg_channel, uint8_t polarity)
{
	uint32_t reg32 = DMAMUX_RGxCR(dmamux, rg_channel);
	reg32 &= ~(DMAMUX_RGxCR_GPOL_MASK << DMAMUX_RGxCR_GPOL_SHIFT);
	reg32 |= ((polarity & DMAMUX_RGxCR_GPOL_MASK) << DMAMUX_RGxCR_GPOL_SHIFT);
	DMAMUX_RGxCR(dmamux, rg_channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Set Request Generator Trigger GNBREQ

Set number of request to generate (minus 1).  This must be configured while
given Request Generator is disabled.

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
@param[in] gnbreq Number of DMA Requests to Generate - minus 1 (0..31).
*/
void dmamux_set_request_generator_trigger_gnbreq(uint32_t dmamux, uint8_t rg_channel, uint8_t gnbreq)
{
	uint32_t reg32 = DMAMUX_RGxCR(dmamux, rg_channel);
	reg32 &= ~(DMAMUX_RGxCR_GNBREQ_MASK << DMAMUX_RGxCR_GNBREQ_SHIFT);
	reg32 |= ((gnbreq & DMAMUX_RGxCR_GNBREQ_MASK) << DMAMUX_RGxCR_GNBREQ_SHIFT);
	DMAMUX_RGxCR(dmamux, rg_channel) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Enable Request Generator Trigger Overrun Interrupt

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
*/
void dmamux_enable_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel)
{
	DMAMUX_RGxCR(dmamux, rg_channel) |= DMAMUX_RGxCR_OIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Disable Request Generator Trigger Overrun Interrupt

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
*/
void dmamux_disable_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel)
{
	DMAMUX_RGxCR(dmamux, rg_channel) &= ~DMAMUX_RGxCR_OIE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Get Request Generator Trigger Overrun Interrupt Flag

Get DMA Request Synchronization Overrun Interrupt Flag for given Request Generator Channel

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
@returns Request Generator Channel Trigger Overrun Interrupt Flag
*/
uint32_t dmamux_get_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel)
{
	return DMAMUX_RGSR(dmamux) & DMAMUX_RGSR_OF(rg_channel);
}

/*---------------------------------------------------------------------------*/
/** @brief DMAMUX Clear Request Generator Trigger Overrun Interrupt Flag

Clear DMA Request Synchronization Overrun Interrupt Flag for given Request Generator
Channel

@param[in] dmamux DMAMUX controller base address (@ref dmamux_reg_base)
@param[in] rg_channel Request Generator Channel Number (@ref dmamux_rg_channel)
*/
void dmamux_clear_request_generator_trigger_overrun_interrupt(uint32_t dmamux, uint8_t rg_channel)
{
	DMAMUX_RGCFR(dmamux) = DMAMUX_RGCFR_COF(rg_channel);
}


/**@}*/
