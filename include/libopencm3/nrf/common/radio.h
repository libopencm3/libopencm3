/** @addtogroup radio_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Maxim Sloyko <maxims@google.com>
 * @author @htmlonly &copy; @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
 *
 **/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#pragma once

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/periph.h>
/**@{*/

/* 2.4 GHz Radio */

/* Tasks */

#define RADIO_TASK_TXEN			MMIO32(RADIO_BASE + 0x000)
#define RADIO_TASK_RXEN			MMIO32(RADIO_BASE + 0x004)
#define RADIO_TASK_START			MMIO32(RADIO_BASE + 0x008)
#define RADIO_TASK_STOP			MMIO32(RADIO_BASE + 0x00C)
#define RADIO_TASK_DISABLE			MMIO32(RADIO_BASE + 0x010)
#define RADIO_TASK_RSSISTART			MMIO32(RADIO_BASE + 0x014)
#define RADIO_TASK_RSSISTOP			MMIO32(RADIO_BASE + 0x018)
#define RADIO_TASK_BCSTART			MMIO32(RADIO_BASE + 0x01C)
#define RADIO_TASK_BCSTOP			MMIO32(RADIO_BASE + 0x020)

/* Events */

#define RADIO_EVENT_READY			MMIO32(RADIO_BASE + 0x100)
#define RADIO_EVENT_ADDRESS			MMIO32(RADIO_BASE + 0x104)
#define RADIO_EVENT_PAYLOAD			MMIO32(RADIO_BASE + 0x108)
#define RADIO_EVENT_END			MMIO32(RADIO_BASE + 0x10C)
#define RADIO_EVENT_DISABLED			MMIO32(RADIO_BASE + 0x110)
#define RADIO_EVENT_DEVMATCH			MMIO32(RADIO_BASE + 0x114)
#define RADIO_EVENT_DEVMISS			MMIO32(RADIO_BASE + 0x118)
#define RADIO_EVENT_RSSIEND			MMIO32(RADIO_BASE + 0x11C)

/* Registers */

#define RADIO_SHORTS			_PERIPH_SHORTS(RADIO_BASE)
#define RADIO_INTENSET			_PERIPH_INTENSET(RADIO_BASE)
#define RADIO_INTENCLR			_PERIPH_INTENCLR(RADIO_BASE)
#define RADIO_CRCSTATUS			MMIO32(RADIO_BASE + 0x400)
#define RADIO_RXMATCH			MMIO32(RADIO_BASE + 0x408)
#define RADIO_RXCRC			MMIO32(RADIO_BASE + 0x40C)
#define RADIO_DAI			MMIO32(RADIO_BASE + 0x410)
#define RADIO_PACKETPTR			MMIO32(RADIO_BASE + 0x504)
#define RADIO_FREQUENCY			MMIO32(RADIO_BASE + 0x508)
#define RADIO_TXPOWER			MMIO32(RADIO_BASE + 0x50C)
#define RADIO_MODE			MMIO32(RADIO_BASE + 0x510)
#define RADIO_PCNF0			MMIO32(RADIO_BASE + 0x514)
#define RADIO_PCNF1			MMIO32(RADIO_BASE + 0x518)
#define RADIO_BASE0			MMIO32(RADIO_BASE + 0x51C)
#define RADIO_BASE1			MMIO32(RADIO_BASE + 0x520)
#define RADIO_PREFIX0			MMIO32(RADIO_BASE + 0x524)
#define RADIO_PREFIX1			MMIO32(RADIO_BASE + 0x528)
#define RADIO_TXADDRESS			MMIO32(RADIO_BASE + 0x52C)
#define RADIO_RXADDRESSES			MMIO32(RADIO_BASE + 0x530)
#define RADIO_CRCCNF			MMIO32(RADIO_BASE + 0x534)
#define RADIO_CRCPOLY			MMIO32(RADIO_BASE + 0x538)
#define RADIO_CRCINIT			MMIO32(RADIO_BASE + 0x53C)
#define RADIO_TEST			MMIO32(RADIO_BASE + 0x540)
#define RADIO_TIFS			MMIO32(RADIO_BASE + 0x544)
#define RADIO_RSSISAMPLE			MMIO32(RADIO_BASE + 0x548)
#define RADIO_STATE			MMIO32(RADIO_BASE + 0x550)
#define RADIO_DATAWHITEIV			MMIO32(RADIO_BASE + 0x554)
#define RADIO_BCC			MMIO32(RADIO_BASE + 0x560)

/* Device Address Base segment */
#define RADIO_DAB(n)			MMIO32(RADIO_BASE + 0x600 + 0x4 * (n))
/* Device Address Prefix segment */
#define RADIO_DAP(n)			MMIO32(RADIO_BASE + 0x620 + 0x4 * (n))
#define RADIO_DACNF			MMIO32(RADIO_BASE + 0x640)

/* Override Registers */
#define RADIO_OVERRIDE(n)			MMIO32(RADIO_BASE + 0x724 + 0x4 * (n))
#define RADIO_POWER			MMIO32(RADIO_BASE + 0xFFC)

/* Register Details */

/** @addtogroup radio_shorts Radio event -> task shortcuts
 * @{
 */
#define RADIO_SHORTS_READY_START			(1 << 0)
#define RADIO_SHORTS_END_DISABLE			(1 << 1)
#define RADIO_SHORTS_DISABLED_TXEN			(1 << 2)
#define RADIO_SHORTS_DISABLED_RXEN			(1 << 3)
#define RADIO_SHORTS_ADDRESS_RSSISTART			(1 << 4)
#define RADIO_SHORTS_END_START			(1 << 5)
#define RADIO_SHORTS_ADDRESS_BCSTART			(1 << 6)
#define RADIO_SHORTS_DISABLED_RSSISTOP			(1 << 8)

/**@}*/

/** @addtogroup radio_inten Radio interrupts
 * @{
 */
#define RADIO_INTEN_READY			(1 << 0)
#define RADIO_INTEN_ADDRESS			(1 << 1)
#define RADIO_INTEN_PAYLOAD			(1 << 2)
#define RADIO_INTEN_END			(1 << 3)
#define RADIO_INTEN_DISABLED			(1 << 4)
#define RADIO_INTEN_DEVMATCH			(1 << 5)
#define RADIO_INTEN_DEVMISS			(1 << 6)
#define RADIO_INTEN_RSSIEND			(1 << 7)
#define RADIO_INTEN_BCMATCH			(1 << 10)

/**@}*/

#define RADIO_PCNF0_LFLEN_SHIFT			(0)
#define RADIO_PCNF0_LFLEN_MASK			(0xf << RADIO_PCNF0_LFLEN_SHIFT)
#define RADIO_PCNF0_LFLEN_MASKED(V)			(((V) << RADIO_PCNF0_LFLEN_SHIFT) \
		& RADIO_PCNF0_LFLEN_MASK)

#define RADIO_PCNF0_S0LEN_SHIFT			(8)
#define RADIO_PCNF0_S0LEN_MASK			(1 << RADIO_PCNF0_S0LEN_SHIFT)
#define RADIO_PCNF0_S0LEN_MASKED(V)			(((V) << RADIO_PCNF0_S0LEN_SHIFT) \
		& RADIO_PCNF0_S0LEN_MASK)

#define RADIO_PCNF0_S1LEN_SHIFT			(16)
#define RADIO_PCNF0_S1LEN_MASK			(0xf << RADIO_PCNF0_S1LEN_SHIFT)
#define RADIO_PCNF0_S1LEN_MASKED(V)			(((V) << RADIO_PCNF0_S1LEN_SHIFT) & \
		RADIO_PCNF0_S1LEN_MASK)

#define RADIO_PCNF1_MAXLEN_SHIFT			(0)
#define RADIO_PCNF1_MAXLEN_MASK			(0xff << RADIO_PCNF1_MAXLEN_SHIFT)
#define RADIO_PCNF1_MAXLEN_MASKED(V)			(((V) << RADIO_PCNF1_MAXLEN_SHIFT) & \
		RADIO_PCNF1_MAXLEN_MASK)

#define RADIO_PCNF1_STATLEN_SHIFT			(8)
#define RADIO_PCNF1_STATLEN_MASK			(0xff << RADIO_PCNF1_STATLEN_SHIFT)
#define RADIO_PCNF1_STATLEN_MASKED(V)			(((V) << RADIO_PCNF1_STATLEN_SHIFT) & \
		RADIO_PCNF1_STATLEN_MASK)

#define RADIO_PCNF1_BALEN_SHIFT			(16)
#define RADIO_PCNF1_BALEN_MASK			(7 << RADIO_PCNF1_BALEN_SHIFT)
#define RADIO_PCNF1_BALEN_MASKED(V)			(((V) << RADIO_PCNF1_BALEN_SHIFT) & \
		RADIO_PCNF1_BALEN_MASK)

#define RADIO_PCNF1_ENDIAN_BIG			(1 << 24)
#define RADIO_PCNF1_WHITEEN			(1 << 25)

#define RADIO_PREFIX0_AP0_SHIFT			(0)
#define RADIO_PREFIX0_AP0_MASK			(0xff << RADIO_PREFIX0_AP0_SHIFT)
#define RADIO_PREFIX0_AP0_MASKED(V)			(((V) << RADIO_PREFIX0_AP0_SHIFT) & \
		RADIO_PREFIX0_AP0_MASK)

#define RADIO_PREFIX0_AP1_SHIFT			(8)
#define RADIO_PREFIX0_AP1_MASK			(0xff << RADIO_PREFIX0_AP1_SHIFT)
#define RADIO_PREFIX0_AP1_MASKED(V)			(((V) << RADIO_PREFIX0_AP1_SHIFT) & \
		RADIO_PREFIX0_AP1_MASK)

#define RADIO_PREFIX0_AP2_SHIFT			(16)
#define RADIO_PREFIX0_AP2_MASK			(0xff << RADIO_PREFIX0_AP2_SHIFT)
#define RADIO_PREFIX0_AP2_MASKED(V)			(((V) << RADIO_PREFIX0_AP2_SHIFT) & \
		RADIO_PREFIX0_AP2_MASK)

#define RADIO_PREFIX0_AP3_SHIFT			(24)
#define RADIO_PREFIX0_AP3_MASK			(0xff << RADIO_PREFIX0_AP3_SHIFT)
#define RADIO_PREFIX0_AP3_MASKED(V)			(((V) << RADIO_PREFIX0_AP3_SHIFT) & \
		RADIO_PREFIX0_AP3_MASK)

#define RADIO_PREFIX1_AP4_SHIFT			(0)
#define RADIO_PREFIX1_AP4_MASK			(0xff << RADIO_PREFIX1_AP4_SHIFT)
#define RADIO_PREFIX1_AP4_MASKED(V)			(((V) << RADIO_PREFIX1_AP4_SHIFT) & \
		RADIO_PREFIX1_AP4_MASK)

#define RADIO_PREFIX1_AP5_SHIFT			(8)
#define RADIO_PREFIX1_AP5_MASK			(0xff << RADIO_PREFIX1_AP5_SHIFT)
#define RADIO_PREFIX1_AP5_MASKED(V)			(((V) << RADIO_PREFIX1_AP5_SHIFT) & \
		RADIO_PREFIX1_AP5_MASK)

#define RADIO_PREFIX1_AP6_SHIFT			(16)
#define RADIO_PREFIX1_AP6_MASK			(0xff << RADIO_PREFIX1_AP6_SHIFT)
#define RADIO_PREFIX1_AP6_MASKED(V)			(((V) << RADIO_PREFIX1_AP6_SHIFT) & \
		RADIO_PREFIX1_AP6_MASK)

#define RADIO_PREFIX1_AP7_SHIFT			(24)
#define RADIO_PREFIX1_AP7_MASK			(0xff << RADIO_PREFIX1_AP7_SHIFT)
#define RADIO_PREFIX1_AP7_MASKED(V)			(((V) << RADIO_PREFIX1_AP7_SHIFT) & \
		RADIO_PREFIX1_AP7_MASK)

#define RADIO_PREFIX_AP(n)			((n) < 4 ? RADIO_PREFIX0 : RADIO_PREFIX1)
#define RADIO_PREFIX_AP_SHIFT(n)			(8 * (n & 3))
#define RADIO_PREFIX_AP_MASK(n)			(0xff << RADIO_PREFIX_AP_SHIFT(n))
#define RADIO_PREFIX_AP_MASKED(n, V)			(((V) << RADIO_PREFIX_AP_SHIFT(n)) & \
		RADIO_PREFIX_AP_MASK(n))

/* TODO: Get rid of this */
#define RADIO_PREFIX_AP_SET(n, V)			if ((n) < 4) {\
		RADIO_PREFIX0 = (V); } \
	else {\
		RADIO_PREFIX1 = (V); }

#define RADIO_TXADDRESSES_ADDR0			(1 << 0)
#define RADIO_TXADDRESSES_ADDR1			(1 << 1)
#define RADIO_TXADDRESSES_ADDR2			(1 << 2)
#define RADIO_TXADDRESSES_ADDR3			(1 << 3)
#define RADIO_TXADDRESSES_ADDR4			(1 << 4)
#define RADIO_TXADDRESSES_ADDR5			(1 << 5)
#define RADIO_TXADDRESSES_ADDR6			(1 << 6)
#define RADIO_TXADDRESSES_ADDR7			(1 << 7)
#define RADIO_TXADDRESSES_ADDR(n)			(1 << (n))

#define RADIO_CRCCNF_LEN_SHIFT			(0)
#define RADIO_CRCCNF_LEN_MASK			(3 << RADIO_CRCCNF_LEN_SHIFT)
#define RADIO_CRCCNF_LEN_MASKED(V)			(((V) << RADIO_CRCCNF_LEN_SHIFT) & \
		RADIO_CRCCNF_LEN_MASK)

#define RADIO_CRCCNF_SKIPADDR			(1 << 8)

#define RADIO_TEST_CONSTCARRIER			(1 << 0)
#define RADIO_TEST_PLLLOCK			(1 << 1)

#define RADIO_DACNF_ENA(n)			(1 << (n))
#define RADIO_DACNF_ENA0			RADIO_DACNF_ENA(0)
#define RADIO_DACNF_ENA1			RADIO_DACNF_ENA(1)
#define RADIO_DACNF_ENA2			RADIO_DACNF_ENA(2)
#define RADIO_DACNF_ENA3			RADIO_DACNF_ENA(3)
#define RADIO_DACNF_ENA4			RADIO_DACNF_ENA(4)
#define RADIO_DACNF_ENA5			RADIO_DACNF_ENA(5)
#define RADIO_DACNF_ENA6			RADIO_DACNF_ENA(6)
#define RADIO_DACNF_ENA7			RADIO_DACNF_ENA(7)

#define RADIO_DACNF_TXADD(n)			(1 << ((n) + 8))
#define RADIO_DACNF_TXADD0			RADIO_DACNF_TXADD(0)
#define RADIO_DACNF_TXADD1			RADIO_DACNF_TXADD(1)
#define RADIO_DACNF_TXADD2			RADIO_DACNF_TXADD(2)
#define RADIO_DACNF_TXADD3			RADIO_DACNF_TXADD(3)
#define RADIO_DACNF_TXADD4			RADIO_DACNF_TXADD(4)
#define RADIO_DACNF_TXADD5			RADIO_DACNF_TXADD(5)
#define RADIO_DACNF_TXADD6			RADIO_DACNF_TXADD(6)
#define RADIO_DACNF_TXADD7			RADIO_DACNF_TXADD(7)

/* Override 4 register has special bit and the override value is masked. */
#define RADIO_OVERRIDE4_ENABLE			(1 << 31)
#define RADIO_OVERRIDE4_OVERRIDE_MASK			(0x0fffffff)

#define RADIO_POWER_ENABLED			(1)
#define RADIO_POWER_DISABLED			(0)

/* Bluetooth Low Energy parameters */
#define RADIO_BLE_TIFS			(150)
#define RADIO_BLE_CRCLEN			(3)
#define RADIO_BLE_CRCPOLY			(0x65B)
#define RADIO_BLE_CRCINIT			(0x555555)

enum radio_txpower {
	RADIO_TXPOWER_POS_4DBM = 0x4,
	RADIO_TXPOWER_0DBM = 0,
	RADIO_TXPOWER_NEG_4DBM = 0xFC,
	RADIO_TXPOWER_NEG_8DBM = 0xF8,
	RADIO_TXPOWER_NEG_12DBM = 0xF4,
	RADIO_TXPOWER_NEG_16DBM = 0xF0,
	RADIO_TXPOWER_NEG_20DBM = 0xEC,
	RADIO_TXPOWER_NEG_30DBM = 0xD8,
};

enum radio_state {
	RADIO_STATE_DISABLED,
	RADIO_STATE_RXRU,
	RADIO_STATE_RXIDLE,
	RADIO_STATE_RX,
	RADIO_STATE_RXDISABLE,
	RADIO_STATE_TXRU = 9,
	RADIO_STATE_TXIDLE,
	RADIO_STATE_TX,
	RADIO_STATE_TXDISABLE,
};

/**@}*/

BEGIN_DECLS

void radio_configure_ble(void);
void radio_disable_crc(void);
void radio_disable(void);
void radio_enable(void);
void radio_set_crclen(uint8_t crc_len);
void radio_set_lsbfirst(void);
void radio_set_msbfirst(void);
void radio_set_txpower(enum radio_txpower txpower);
void radio_disable_whitening(void);
void radio_enable_whitening(void);
void radio_configure_packet(uint8_t lf_len_bits, uint8_t s0_len_bytes, uint8_t s1_len_bits);
void radio_set_balen(uint8_t ba_len);
void radio_set_frequency(uint8_t freq);
void radio_set_datawhiteiv(uint8_t iv);
void radio_set_addr(uint8_t addr_index, uint32_t base, uint8_t prefix);
void radio_set_tx_address(uint8_t addr_index);
void radio_set_packet_ptr(uint8_t *packet_ptr);
void radio_enable_shorts(uint16_t shorts);
void radio_disable_shorts(uint16_t shorts);
void radio_clear_shorts(void);
void radio_enable_tx(void);
void radio_enable_rx(void);
void radio_set_maxlen(uint8_t maxlen);
void radio_set_crc_skipaddr(bool is_skip_addr);

END_DECLS



