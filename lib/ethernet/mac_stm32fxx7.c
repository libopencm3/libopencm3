/** @defgroup ethernet_mac_stm32fxx7_file MAC STM32Fxx7
 *
 * @ingroup ETH
 *
 * @brief <b>Ethernet MAC STM32Fxx7 Drivers</b>
 *
 * @version 1.0.0
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 1 September 2013
 *
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#include <string.h>
#include <libopencm3/ethernet/mac.h>
#include <libopencm3/ethernet/phy.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/nvic.h>

/**@{*/

uint32_t TxBD;
uint32_t RxBD;

/*---------------------------------------------------------------------------*/
/** @brief Set MAC to the PHY
 *
 * @param[in] mac uint8_t* Desired MAC
 */
void eth_set_mac(const uint8_t *mac)
{
	ETH_MACAHR(0) = ((uint32_t)mac[5] << 8) | (uint32_t)mac[4] |
			ETH_MACA0HR_MACA0H;
	ETH_MACALR(0) = ((uint32_t)mac[3] << 24) | ((uint32_t)mac[2] << 16) |
			((uint32_t)mac[1] << 8) | mac[0];
}

/*---------------------------------------------------------------------------*/
/** @brief Initialize buffers and descriptors.
 *
 * @param[in] buf uint8_t* Memory area for the descriptors and data buffers
 * @param[in] nTx uint32_t Count of transmit descriptors (equal to count of buffers)
 * @param[in] nRx uint32_t Count of receive descriptors (equal to count of buffers)
 * @param[in] cTx uint32_t Bytes in each transmit buffer, must be a
 *                         multiple of 4
 * @param[in] cRx uint32_t Bytes in each receive buffer, must be a
 *                         multiple of 4
 * @param[in] isext bool true if extended descriptors should be used
 *
 * Note, the space passed via buf pointer must be large enough to
 * hold all the buffers and one descriptor per buffer.
 */
void eth_desc_init(uint8_t *buf, uint32_t nTx, uint32_t nRx, uint32_t cTx,
		    uint32_t cRx, bool isext)
{
	uint32_t bd = (uint32_t)buf;
	uint32_t sz = isext ? ETH_DES_EXT_SIZE : ETH_DES_STD_SIZE;

	memset(buf, 0, nTx * (cTx + sz) + nRx * (cRx + sz));

	/* enable / disable extended frames */
	if (isext) {
		ETH_DMABMR |= ETH_DMABMR_EDFE;
	} else {
		ETH_DMABMR &= ~ETH_DMABMR_EDFE;
	}

	TxBD = bd;
	while (--nTx > 0) {
		ETH_DES0(bd) = ETH_TDES0_TCH;
		ETH_DES2(bd) = bd + sz;
		ETH_DES3(bd) = bd + sz + cTx;
		bd = ETH_DES3(bd);
	}

	ETH_DES0(bd) = ETH_TDES0_TCH;
	ETH_DES2(bd) = bd + sz;
	ETH_DES3(bd) = TxBD;
	bd += sz + cTx;

	RxBD = bd;
	while (--nRx > 0) {
		ETH_DES0(bd) = ETH_RDES0_OWN;
		ETH_DES1(bd) = ETH_RDES1_RCH | cRx;
		ETH_DES2(bd) = bd + sz;
		ETH_DES3(bd) = bd + sz + cRx;
		bd = ETH_DES3(bd);
	}

	ETH_DES0(bd) = ETH_RDES0_OWN;
	ETH_DES1(bd) = ETH_RDES1_RCH | cRx;
	ETH_DES2(bd) = bd + sz;
	ETH_DES3(bd) = RxBD;

	ETH_DMARDLAR = (uint32_t) RxBD;
	ETH_DMATDLAR = (uint32_t) TxBD;
}

/*---------------------------------------------------------------------------*/
/** @brief Transmit packet
 *
 * @param[in] ppkt uint8_t* Pointer to the beginning of the packet
 * @param[in] n uint32_t Size of the packet
 * @returns bool true, if success
 */
bool eth_tx(uint8_t *ppkt, uint32_t n)
{
	if (ETH_DES0(TxBD) & ETH_TDES0_OWN) {
		return false;
	}

	memcpy((void *)ETH_DES2(TxBD), ppkt, n);

	ETH_DES1(TxBD) = n & ETH_TDES1_TBS1;
	ETH_DES0(TxBD) |= ETH_TDES0_LS | ETH_TDES0_FS | ETH_TDES0_OWN;
	TxBD = ETH_DES3(TxBD);

	if (ETH_DMASR & ETH_DMASR_TBUS) {
		ETH_DMASR = ETH_DMASR_TBUS;
		ETH_DMATPDR = 0;
	}

	return true;
}

/*---------------------------------------------------------------------------*/
/** @brief Receive packet
 *
 * @param[inout] ppkt uint8_t* Pointer to the data buffer where to store data
 * @param[inout] len uint32_t* Pointer to the variable with the packet length
 * @param[in] maxlen uint32_t Maximum length of the packet
 * @returns bool true, if the buffer contains readed packet data
 */
bool eth_rx(uint8_t *ppkt, uint32_t *len, uint32_t maxlen)
{
	bool fs = false;
	bool ls = false;
	bool overrun = false;
	uint32_t l = 0;

	while (!(ETH_DES0(RxBD) & ETH_RDES0_OWN) && !ls) {
		l = (ETH_DES0(RxBD) & ETH_RDES0_FL) >> ETH_RDES0_FL_SHIFT;

		fs |= ETH_DES0(RxBD) & ETH_RDES0_FS;
		ls |= ETH_DES0(RxBD) & ETH_RDES0_LS;
		/* frame buffer overrun ?*/
		overrun |= fs && (maxlen < l);

		if (fs && !overrun) {
			memcpy(ppkt, (void *)ETH_DES2(RxBD), l);
			ppkt += l;
			*len += l;
			maxlen -= l;
		}

		ETH_DES0(RxBD) = ETH_RDES0_OWN;
		RxBD = ETH_DES3(RxBD);
	}

	if (ETH_DMASR & ETH_DMASR_RBUS) {
		ETH_DMASR = ETH_DMASR_RBUS;
		ETH_DMARPDR = 0;
	}

	return fs && ls && !overrun;
}

/*---------------------------------------------------------------------------*/
/** @brief Start the Ethernet DMA processing
 */
void eth_start(void)
{
	ETH_MACCR |= ETH_MACCR_TE;
	ETH_DMAOMR |= ETH_DMAOMR_FTF;
	ETH_MACCR |= ETH_MACCR_RE;

	ETH_DMAOMR |= ETH_DMAOMR_ST;
	ETH_DMAOMR |= ETH_DMAOMR_SR;
}

/*---------------------------------------------------------------------------*/
/** @brief Initialize ethernet
 *
 * This function will initialize ethernet, set up clocks, and initialize DMA.
 *
 * @param[in] phy phy id
 * @param[in] clock enum eth_clk Core clock speed
 */
void eth_init(uint8_t phy, enum eth_clk clock)
{
	ETH_MACMIIAR = clock;
	phy_reset(phy);

	ETH_MACCR = ETH_MACCR_CSTF | ETH_MACCR_FES | ETH_MACCR_DM |
		ETH_MACCR_APCS | ETH_MACCR_RD;
	ETH_MACFFR = ETH_MACFFR_RA | ETH_MACFFR_PM;
	ETH_MACHTHR = 0; /* pass all frames */
	ETH_MACHTLR = 0;
	ETH_MACFCR = (0x100 << ETH_MACFCR_PT_SHIFT);
	ETH_MACVLANTR = 0;
	ETH_DMAOMR = ETH_DMAOMR_DTCEFD | ETH_DMAOMR_RSF | ETH_DMAOMR_DFRF |
		ETH_DMAOMR_TSF | ETH_DMAOMR_FEF | ETH_DMAOMR_OSF;
	ETH_DMABMR = ETH_DMABMR_AAB | ETH_DMABMR_FB |
		(32 << ETH_DMABMR_RDP_SHIFT) | (32 << ETH_DMABMR_PBL_SHIFT) |
		ETH_DMABMR_PM_2_1 | ETH_DMABMR_USP;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the Ethernet IRQ
 *
 * @param[in] reason uint32_t Which irq will be enabled
 */
void eth_irq_enable(uint32_t reason)
{
	ETH_DMAIER |= reason;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the Ethernet IRQ
 *
 * @param[in] reason uint32_t Which irq will be disabled
 */
void eth_irq_disable(uint32_t reason)
{
	ETH_DMAIER &= ~reason;
}

/*---------------------------------------------------------------------------*/
/** @brief Check if IRQ is pending
 *
 * @param[in] reason uint32_t Which irq type has to be tested
 * @returns bool true, if IRQ is pending
 */
bool eth_irq_is_pending(uint32_t reason)
{
	return (ETH_DMASR & reason) != 0;
}

/*---------------------------------------------------------------------------*/
/** @brief Check if IRQ is pending, and acknowledge it
 *
 * @param[in] reason uint32_t Which irq type has to be tested
 * @returns bool true, if IRQ is pending
 */
bool eth_irq_ack_pending(uint32_t reason)
{
	reason &= ETH_DMASR;
	ETH_DMASR = reason;
	return reason != 0;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable checksum offload feature
 *
 * This function will enable the Checksum offload feature for all of the
 * transmit descriptors. Note to use this feature, descriptors must be in
 * extended format.
 */
void eth_enable_checksum_offload(void)
{
	uint32_t tab = TxBD;
	do {
		ETH_DES0(tab) |= ETH_TDES0_CIC_IPPLPH;
		tab = ETH_DES3(tab);
	}
	while (tab != TxBD);

	ETH_MACCR |= ETH_MACCR_IPCO;
}

/*---------------------------------------------------------------------------*/
/** @brief Process pending SMI transaction and wait to be done.
 */
static void eth_smi_transact(void)
{
	/* Begin transaction. */
	ETH_MACMIIAR |= ETH_MACMIIAR_MB;

	/* Wait for not busy. */
	while (ETH_MACMIIAR & ETH_MACMIIAR_MB);
}

/*---------------------------------------------------------------------------*/
/** @brief Write 16-bit register to the PHY
 *
 * @param[in] phy uint8_t ID of the PHY (defaults to 1)
 * @param[in] reg uint8_t Register address
 * @param[in] data uint16_t Data to write
 */
void eth_smi_write(uint8_t phy, uint8_t reg, uint16_t data)
{
	/* Write operation MW=1*/
	ETH_MACMIIAR = (ETH_MACMIIAR & ETH_MACMIIAR_CR) | /* save clocks */
			(phy << ETH_MACMIIAR_PA_SHIFT) |
			(reg << ETH_MACMIIAR_MR_SHIFT) |
			ETH_MACMIIAR_MW;

	ETH_MACMIIDR = data & ETH_MACMIIDR_MD;

	eth_smi_transact();
}

/*---------------------------------------------------------------------------*/
/** @brief Read the 16-bit register from the PHY
 *
 * @param[in] phy uint8_t ID of the PHY (defaults to 1)
 * @param[in] reg uint8_t Register address
 * @returns uint16_t Readed data
 */
uint16_t eth_smi_read(uint8_t phy, uint8_t reg)
{
	/* Read operation MW=0*/
	ETH_MACMIIAR = (ETH_MACMIIAR & ETH_MACMIIAR_CR) | /* save clocks */
			(phy << ETH_MACMIIAR_PA_SHIFT) |
			(reg << ETH_MACMIIAR_MR_SHIFT);

	eth_smi_transact();

	return (uint16_t)(ETH_MACMIIDR & ETH_MACMIIDR_MD);
}

/*---------------------------------------------------------------------------*/
/** @brief Process the bit-operation on PHY register
 *
 * @param[in] phy uint8_t ID of the PHY (defaults to 1)
 * @param[in] reg uint8_t Register address
 * @param[in] bits uint16_t Bits that have to be set (or'ed)
 * @param[in] mask uint16_t Bits that have to be clear (and'ed)
 */
void eth_smi_bit_op(uint8_t phy, uint8_t reg, uint16_t bits, uint16_t mask)
{
	uint16_t val = eth_smi_read(phy, reg);
	eth_smi_write(phy, reg, (val & mask) | bits);
}

/*---------------------------------------------------------------------------*/
/** @brief Clear bits in the register
 *
 * @param[in] phy uint8_t ID of the PHY (defaults to 1)
 * @param[in] reg uint8_t Register address
 * @param[in] clearbits uint16_t Bits that have to be cleared
 */
void eth_smi_bit_clear(uint8_t phy, uint8_t reg, uint16_t clearbits)
{
	uint16_t val = eth_smi_read(phy, reg);
	eth_smi_write(phy, reg, val & (uint16_t)~(clearbits));
}

/*---------------------------------------------------------------------------*/
/** @brief Set bits in the register
 *
 * @param[in] phy uint8_t ID of the PHY (defaults to 1)
 * @param[in] reg uint8_t Register address
 * @param[in] bits uint16_t Bits that have to be set (or'ed)
 */
void eth_smi_bit_set(uint8_t phy, uint8_t reg, uint16_t setbits)
{
	uint16_t val = eth_smi_read(phy, reg);
	eth_smi_write(phy, reg, val | setbits);
}

/*---------------------------------------------------------------------------*/

/**@}*/
