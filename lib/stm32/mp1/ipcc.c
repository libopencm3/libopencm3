/** @addtogroup ipcc_file IPCC peripheral API
 * @ingroup peripheral_apis
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

#include <stdint.h>
#include <libopencm3/stm32/ipcc.h>

#define IPCC_OTHER_CORE(core) (((core) == IPCC_CPU_A7) ? IPCC_MPU_M4 : IPCC_CPU_A7)

/**@{*/

void ipcc_enable_interrupt(enum ipcc_core core, uint32_t ipcc_irq_mask)
{
	IPCC_CxCR(core) |= ipcc_irq_mask;
}

void ipcc_disable_interrupt(enum ipcc_core core, uint32_t ipcc_irq_mask)
{
	IPCC_CxCR(core) &= ~ipcc_irq_mask;
}

void ipcc_enable_channel_interrupt(enum ipcc_core core, uint32_t ipcc_ch_irq_mask)
{
	IPCC_CxMR(core) &= ~ipcc_ch_irq_mask;
}

void ipcc_disable_channel_interrupt(enum ipcc_core core, uint32_t ipcc_ch_irq_mask)
{
	IPCC_CxMR(core) |= ipcc_ch_irq_mask;
}

uint32_t ipcc_get_active_channels_rx_interrupts(enum ipcc_core core)
{
	enum ipcc_core other_core = IPCC_OTHER_CORE(core);
	uint32_t mask = ~(IPCC_CxMR(core)) & IPCC_RX_MASK;
	uint32_t irqs = IPCC_CxTOCySR(other_core) & mask;
	return irqs;
}

bool ipcc_tx_channel_occupied(enum ipcc_core core, uint8_t channel)
{
	uint32_t res = IPCC_CxTOCySR(core) & IPCC_CxTOCySR_CHnF(channel);
	return (res != 0);
}

void ipcc_notify(enum ipcc_core core, uint32_t notif_mask)
{
	IPCC_CxSCR(core) = notif_mask;
}

/**@}*/
