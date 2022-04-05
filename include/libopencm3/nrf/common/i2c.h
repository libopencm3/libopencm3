/** @addtogroup i2c_defines
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

/* I2C bus */
/** @addtogroup i2c_block I2C instances
 * @{
 */

#define I2C0            I2C0_BASE
#define I2C1            I2C1_BASE

/**@}*/

/* Tasks */

#define I2C_TASK_STARTRX(i2c)      MMIO32((i2c) + 0x000)
#define I2C_TASK_STARTTX(i2c)      MMIO32((i2c) + 0x008)
#define I2C_TASK_STOP(i2c)         MMIO32((i2c) + 0x014)
#define I2C_TASK_SUSPEND(i2c)      MMIO32((i2c) + 0x01c)
#define I2C_TASK_RESUME(i2c)       MMIO32((i2c) + 0x020)
/* Events */

#define I2C_EVENT_STOPPED(i2c)     MMIO32((i2c) + 0x104)
#define I2C_EVENT_RXDREADY(i2c)    MMIO32((i2c) + 0x108)
#define I2C_EVENT_TXDSENT(i2c)     MMIO32((i2c) + 0x11c)
#define I2C_EVENT_ERROR(i2c)       MMIO32((i2c) + 0x124)
#define I2C_EVENT_BB(i2c)          MMIO32((i2c) + 0x138)
#define I2C_EVENT_SUSPENDED(i2c)   MMIO32((i2c) + 0x148)
/* Registers */

#define I2C_SHORTS(i2c)            MMIO32((i2c) + 0x200)
#define I2C_INTEN(i2c)             MMIO32((i2c) + 0x300)
#define I2C_INTENSET(i2c)          MMIO32((i2c) + 0x304)
#define I2C_INTENCLR(i2c)          MMIO32((i2c) + 0x308)
#define I2C_ERRORSRC(i2c)          MMIO32((i2c) + 0x4c4)
#define I2C_ENABLE(i2c)            MMIO32((i2c) + 0x500)
#define I2C_PSELSCL(i2c)           MMIO32((i2c) + 0x508)
#define I2C_PSELSDA(i2c)           MMIO32((i2c) + 0x50c)
#define I2C_RXD(i2c)               MMIO32((i2c) + 0x518)
#define I2C_TXD(i2c)               MMIO32((i2c) + 0x51c)
#define I2C_FREQUENCY(i2c)         MMIO32((i2c) + 0x524)
#define I2C_ADDRESS(i2c)           MMIO32((i2c) + 0x588)

/* Register Contents */

/** @addtogroup i2c_shorts I2C event -> task shortcuts
 * The effect of activated shortcut is, that upon I2C event
 * triggering, the hardware will automatically start chosen
 * task without intervention of the software.
 * @{
 */

/** On byte boundary, activate suspend task. */
#define I2C_SHORTS_BB_SUSPEND      (1 << 0)

/** On byte boundary, activate stop task. */
#define I2C_SHORTS_BB_STOP         (1 << 1)

/**@}*/

/** @addtogroup i2c_interrupts I2C interrupts
 * @{
 */
#define I2C_INTEN_STOPPED          (1 << 1)
#define I2C_INTEN_RXDREADY         (1 << 2)
#define I2C_INTEN_TXDSENT          (1 << 7)
#define I2C_INTEN_ERROR            (1 << 9)
#define I2C_INTEN_BB               (1 << 14)

/**@}*/

#define I2C_ERRORSRC_OVERRUN       (1 << 0)
#define I2C_ERRORSRC_ANACK         (1 << 1)
#define I2C_ERRORSRC_DNACK         (1 << 2)

/** @addtogroup i2c_mode I2C peripheral mode 
 * @{
 */
/** NRF51 legacy mode. 
 * On NRF51, this is the only mode available.
 * On NRF52, this mode does not support EasyDMA.
 */
#define I2C_MODE_LEGACY           (5)
/**@}*/

/** @addtogroup i2c_freq_const I2C frequency constants
 * @{
 */

/** 100kHz */
#define I2C_FREQUENCY_100K         (0x01980000)
/** 250kHz */
#define I2C_FREQUENCY_250K         (0x04000000)
/** 390kHz
 * @note: This value is not documented in datasheet. It provides
 * ~390kHz clock with correct timing.
 */
#define I2C_FREQUENCY_390K         (0x06200000)
/** 400kHz
 * @note: According to datasheet, there is HW bug which prevents
 * MCU from generating correct timings, therefore it might be
 * unusable. Use @ref I2C_FREQUENCY_390K instead, if this affects
 * you.
 */
#define I2C_FREQUENCY_400K         (0x06680000)
/**@}*/

#define I2C_PSEL_OFF               (0xffffffff)

/**@}*/

BEGIN_DECLS

void i2c_enable(uint32_t i2c, uint32_t mode);
void i2c_disable(uint32_t i2c);
void i2c_start_tx(uint32_t i2c);
void i2c_start_rx(uint32_t i2c);
void i2c_send_stop(uint32_t i2c);
void i2c_set_fast_mode(uint32_t i2c);
void i2c_set_standard_mode(uint32_t i2c);
void i2c_set_frequency(uint32_t i2c, uint32_t freq);
void i2c_send_data(uint32_t i2c, uint8_t data);
uint8_t i2c_get_data(uint32_t i2c);
void i2c_select_pins(uint32_t i2c, uint32_t scl_pin, uint32_t sda_pin);
void i2c_set_address(uint32_t i2c, uint8_t addr);
void i2c_resume(uint32_t i2c);
void i2c_set_shorts(uint32_t i2c, uint32_t shorts);

END_DECLS


