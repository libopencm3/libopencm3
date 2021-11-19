/** @addtogroup ppi_defines
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
/**@{*/

/* Programmable Peripheral Interconnect */

/* Tasks */

#define PPI_TASK_CHG_EN(n)			MMIO32(PPI_BASE + 0x8 * (n))
#define PPI_TASK_CHG_DIS(n)			MMIO32(PPI_BASE + 0x8 * (n) + 0x4)

/* Registers */

#define PPI_CHEN			MMIO32(PPI_BASE + 0x500)
#define PPI_CHENSET			MMIO32(PPI_BASE + 0x504)
#define PPI_CHENCLR			MMIO32(PPI_BASE + 0x508)

/* Event End Point n = 0 .. 15 */
#define PPI_CH_EEP(n)			MMIO32(PPI_BASE + 0x510 + 0x8 * (n))
/* Task End Point n = 0 .. 15 */
#define PPI_CH_TEP(n)			MMIO32(PPI_BASE + 0x514 + 0x8 * (n))

/* Channel Groups */
#define PPI_CHG(n)			MMIO32(PPI_BASE + 0x800 + 0x4 * (n))

#define PPI_CH(n)			(1 << (n))
/** @addtogroup PPI Channel identifiers
 * @{
 */
#define PPI_CH0			(1 << 0)
#define PPI_CH1			(1 << 1)
#define PPI_CH2			(1 << 2)
#define PPI_CH3			(1 << 3)
#define PPI_CH4			(1 << 4)
#define PPI_CH5			(1 << 5)
#define PPI_CH6			(1 << 6)
#define PPI_CH7			(1 << 7)
#define PPI_CH8			(1 << 8)
#define PPI_CH9			(1 << 9)
#define PPI_CH10			(1 << 10)
#define PPI_CH11			(1 << 11)
#define PPI_CH12			(1 << 12)
#define PPI_CH13			(1 << 13)
#define PPI_CH14			(1 << 14)
#define PPI_CH15			(1 << 15)
/* Channels 16-19 are reserved */
#define PPI_CH20			(1 << 20)
#define PPI_CH21			(1 << 21)
#define PPI_CH22			(1 << 22)
#define PPI_CH23			(1 << 23)
#define PPI_CH24			(1 << 24)
#define PPI_CH25			(1 << 25)
#define PPI_CH26			(1 << 26)
#define PPI_CH27			(1 << 27)
#define PPI_CH28			(1 << 28)
#define PPI_CH29			(1 << 29)
#define PPI_CH30			(1 << 30)
#define PPI_CH31			(1 << 31)

/**@}*/

#define PPI_MAX_PROG_CHANNEL			(15)

/* Preprogrammed channels */
/* TIMER0->EVENTS_COMPARE0 -- RADIO->TASKS_TXEN */
#define PPI_CH_TMR0CC0_RADIOTXEN			PPI_CH20

/* TIMER0->EVENTS_COMPARE0 -- RADIO->TASKS_RXEN */
#define PPI_CH_TMR0CC0_RADIORXEN			PPI_CH21

/* TIMER0->EVENTS_COMPARE1 -- RADIO->TASKS_DISABLE */
#define PPI_CH_TMR0CC1_RADIODIS			PPI_CH22

/* RADIO->EVENTS_BCMATCH -- AAR->TASKS_START */
#define PPI_CH_RADIOBCMATCH_AARSTART			PPI_CH23

/* RADIO->EVENTS_READY -- CCM->TASKS_KSGEN */
#define PPI_CH_RADIOREADY_CCMKSGEN			PPI_CH24

/* RADIO->EVENTS_ADDRESS -- CCM->TASKS_CRYPT */
#define PPI_CH_RADIOADDR_CCMCRYPT			PPI_CH25

/* RADIO->EVENTS_ADDRESS -- TIMER0->TASKS_CAPTURE1 */
#define PPI_CH_RADIOADDR_TMR0CAPT1			PPI_CH26

/* RADIO->EVENTS_END -- TIMER0->TASKS_CAPTURE2 */
#define PPI_CH_RADIOEND_TMR0CAPT2			PPI_CH27

/* RTC0->EVENTS_COMPARE[0] -- RADIO->TASKS_TXEN */
#define PPI_CH_RTC0CC0_RADIOTXEN			PPI_CH28

/* RTC0->EVENTS_COMPARE[0] -- RADIO->TASKS_RXEN */
#define PPI_CH_RTC0CC0_RADIORXEN			PPI_CH29

/* RTC0->EVENTS_COMPARE[0] -- TIMER0->TASKS_CLEAR */
#define PPI_CH_RTC0CC0_TMR0CLEAR			PPI_CH30

/* RTC0->EVENTS_COMPARE[0] -- TIMER0->TASKS_START */
#define PPI_CH_RTC0CC0_TMR0START			PPI_CH31
/**@}*/

BEGIN_DECLS

void ppi_configure_channel(uint8_t chan_num, uint32_t eep, uint32_t tep);
void ppi_enable_channels(uint32_t channels);
void ppi_disable_channels(uint32_t channels);

void ppi_set_group(uint8_t group, uint32_t channels);
void ppi_enable_group(uint8_t group);
void ppi_disable_group(uint8_t group);

/* Simpler API, that requires the client to store channel map. */
uint8_t ppi_add_channel(uint32_t *chan_map, uint32_t eep, uint32_t tep, bool enable);
void ppi_remove_channel(uint32_t *chan_map, uint8_t chan_num);

END_DECLS


