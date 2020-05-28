/** @addtogroup ipcc_defines
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
#ifndef LIBOPENCM3_IPCC_H
/** @endcond */
#define LIBOPENCM3_IPCC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/
enum ipcc_core {
	IPCC_CPU_A7 = 1,
	IPCC_MPU_M4 = 2
};

enum ipcc_channel_mask {
	IPCC_CH1 = (1 << 0),
	IPCC_CH2 = (1 << 1),
	IPCC_CH3 = (1 << 2),
	IPCC_CH4 = (1 << 3),
	IPCC_CH5 = (1 << 4),
	IPCC_CH6 = (1 << 5),
};

#define IPCC_MAX_CHANS 6

#define IPCC_CxCR(core)       MMIO32(IPCC_BASE + (((core) - 1) * 0x10) + 0x00)
#define IPCC_CxMR(core)       MMIO32(IPCC_BASE + (((core) - 1) * 0x10) + 0x04)
#define IPCC_CxSCR(core)      MMIO32(IPCC_BASE + (((core) - 1) * 0x10) + 0x08)
#define IPCC_CxTOCySR(core)   MMIO32(IPCC_BASE + (((core) - 1) * 0x10) + 0x0c)

#define IPCC_C1CR       IPCC_CxCR(1)
#define IPCC_C1MR       IPCC_CxMR(1)
#define IPCC_C1SCR      IPCC_CxSCR(1)
#define IPCC_C1TOC2SR   IPCC_CxTOCySR(1)
#define IPCC_C2CR       IPCC_CxCR(2)
#define IPCC_C2MR       IPCC_CxMR(2)
#define IPCC_C2SCR      IPCC_CxSCR(2)
#define IPCC_C2TOC1SR   IPCC_CxTOCySR(2)

#define IPCC_CxCR_RXOIE (1 << 0)
#define IPCC_CxCR_TXFIE (1 << 16)
#define IPCC_C1CR_RXOIE IPCC_CxCR_RXOIE
#define IPCC_C1CR_TXFIE IPCC_CxCR_TXFIE

#define IPCC_RX_MASK (0x3f)
#define IPCC_TX_MASK (0x3f0000)

#define IPCC_CxMR_CHnOM(n) ((1 << ((n) - 1)) & IPCC_RX_MASK)
#define IPCC_CxMR_CHnFM(n) ((1 << ((n) - 1 + 16)) & IPCC_TX_MASK)
#define IPCC_C1MR_CH1OM    IPCC_CxMR_CHnOM(1)
#define IPCC_C1MR_CH1FM    IPCC_CxMR_CHnFM(1)
#define IPCC_C1MR_CH2OM    IPCC_CxMR_CHnOM(2)
#define IPCC_C1MR_CH2FM    IPCC_CxMR_CHnFM(2)
#define IPCC_C1MR_CH3OM    IPCC_CxMR_CHnOM(3)
#define IPCC_C1MR_CH3FM    IPCC_CxMR_CHnFM(3)
#define IPCC_C1MR_CH4OM    IPCC_CxMR_CHnOM(4)
#define IPCC_C1MR_CH4FM    IPCC_CxMR_CHnFM(4)
#define IPCC_C1MR_CH5OM    IPCC_CxMR_CHnOM(5)
#define IPCC_C1MR_CH5FM    IPCC_CxMR_CHnFM(5)
#define IPCC_C1MR_CH6OM    IPCC_CxMR_CHnOM(6)
#define IPCC_C1MR_CH6FM    IPCC_CxMR_CHnFM(6)


#define IPCC_CxSCR_CHnC(n) ((1 << ((n) - 1)) & IPCC_RX_MASK)
#define IPCC_CxSCR_CHnS(n) ((1 << ((n) - 1 + 16)) & IPCC_TX_MASK)
#define IPCC_C1SCR_CH1C    IPCC_CxSCR_CHnC(1)
#define IPCC_C1SCR_CH1S    IPCC_CxSCR_CHnS(1)
#define IPCC_C1SCR_CH2C    IPCC_CxSCR_CHnC(2)
#define IPCC_C1SCR_CH2S    IPCC_CxSCR_CHnS(2)
#define IPCC_C1SCR_CH3C    IPCC_CxSCR_CHnC(3)
#define IPCC_C1SCR_CH3S    IPCC_CxSCR_CHnS(3)
#define IPCC_C1SCR_CH4C    IPCC_CxSCR_CHnC(4)
#define IPCC_C1SCR_CH4S    IPCC_CxSCR_CHnS(4)
#define IPCC_C1SCR_CH5C    IPCC_CxSCR_CHnC(5)
#define IPCC_C1SCR_CH5S    IPCC_CxSCR_CHnS(5)
#define IPCC_C1SCR_CH6C    IPCC_CxSCR_CHnC(6)
#define IPCC_C1SCR_CH6S    IPCC_CxSCR_CHnS(6)

#define IPCC_CxTOCySR_CHnF(n) ((1 << ((n) - 1)) & 0x3f)
#define IPCC_C1TOC2SR_CH1F    IPCC_CxTOCySR_CHnF(1)
#define IPCC_C1TOC2SR_CH2F    IPCC_CxTOCySR_CHnF(2)
#define IPCC_C1TOC2SR_CH3F    IPCC_CxTOCySR_CHnF(3)
#define IPCC_C1TOC2SR_CH4F    IPCC_CxTOCySR_CHnF(4)
#define IPCC_C1TOC2SR_CH5F    IPCC_CxTOCySR_CHnF(5)
#define IPCC_C1TOC2SR_CH6F    IPCC_CxTOCySR_CHnF(6)

#define IPCC_C2CR_RXOIE IPCC_CxCR_RXOIE
#define IPCC_C2CR_TXFIE IPCC_CxCR_TXFIE

#define IPCC_C2MR_CH1OM    IPCC_CxMR_CHnOM(1)
#define IPCC_C2MR_CH1FM    IPCC_CxMR_CHnFM(1)
#define IPCC_C2MR_CH2OM    IPCC_CxMR_CHnOM(2)
#define IPCC_C2MR_CH2FM    IPCC_CxMR_CHnFM(2)
#define IPCC_C2MR_CH3OM    IPCC_CxMR_CHnOM(3)
#define IPCC_C2MR_CH3FM    IPCC_CxMR_CHnFM(3)
#define IPCC_C2MR_CH4OM    IPCC_CxMR_CHnOM(4)
#define IPCC_C2MR_CH4FM    IPCC_CxMR_CHnFM(4)
#define IPCC_C2MR_CH5OM    IPCC_CxMR_CHnOM(5)
#define IPCC_C2MR_CH5FM    IPCC_CxMR_CHnFM(5)
#define IPCC_C2MR_CH6OM    IPCC_CxMR_CHnOM(6)
#define IPCC_C2MR_CH6FM    IPCC_CxMR_CHnFM(6)

#define IPCC_C2SCR_CH1C    IPCC_CxSCR_CHnC(1)
#define IPCC_C2SCR_CH1S    IPCC_CxSCR_CHnS(1)
#define IPCC_C2SCR_CH2C    IPCC_CxSCR_CHnC(2)
#define IPCC_C2SCR_CH2S    IPCC_CxSCR_CHnS(2)
#define IPCC_C2SCR_CH3C    IPCC_CxSCR_CHnC(3)
#define IPCC_C2SCR_CH3S    IPCC_CxSCR_CHnS(3)
#define IPCC_C2SCR_CH4C    IPCC_CxSCR_CHnC(4)
#define IPCC_C2SCR_CH4S    IPCC_CxSCR_CHnS(4)
#define IPCC_C2SCR_CH5C    IPCC_CxSCR_CHnC(5)
#define IPCC_C2SCR_CH5S    IPCC_CxSCR_CHnS(5)
#define IPCC_C2SCR_CH6C    IPCC_CxSCR_CHnC(6)
#define IPCC_C2SCR_CH6S    IPCC_CxSCR_CHnS(6)

#define IPCC_C2TOC1SR_CH1F    IPCC_CxTOCySR_CHnF(1)
#define IPCC_C2TOC1SR_CH2F    IPCC_CxTOCySR_CHnF(2)
#define IPCC_C2TOC1SR_CH3F    IPCC_CxTOCySR_CHnF(3)
#define IPCC_C2TOC1SR_CH4F    IPCC_CxTOCySR_CHnF(4)
#define IPCC_C2TOC1SR_CH5F    IPCC_CxTOCySR_CHnF(5)
#define IPCC_C2TOC1SR_CH6F    IPCC_CxTOCySR_CHnF(6)

/* --- Function prototypes ------------------------------------------------- */
BEGIN_DECLS
void ipcc_enable_interrupt(enum ipcc_core core, uint32_t ipcc_irq_mask);
void ipcc_disable_interrupt(enum ipcc_core core, uint32_t ipcc_irq_mask);
void ipcc_enable_channel_interrupt(enum ipcc_core core, uint32_t ipcc_ch_irq_mask);
void ipcc_disable_channel_interrupt(enum ipcc_core core, uint32_t ipcc_ch_irq_mask);
uint32_t ipcc_get_active_channels_rx_interrupts(enum ipcc_core core);
void ipcc_notify(enum ipcc_core core, uint32_t notif_mask);
bool ipcc_tx_channel_occupied(enum ipcc_core core, uint8_t channel);
END_DECLS

/** @cond */
#endif
/** @endcond */
/**@}*/
