/** @defgroup i2c_defines I2C Defines

@brief <b>Defined Constants and Types for the LPC43xx I2C</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_I2C_H
#define LPC43XX_I2C_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* I2C port base addresses (for convenience) */
#define I2C0                            I2C0_BASE
#define I2C1                            I2C1_BASE

/* --- I2C registers ------------------------------------------------------- */

/* I2C Control Set Register */
#define I2C_CONSET(port)                MMIO32((port) + 0x000)
#define I2C0_CONSET                     I2C_CONSET(I2C0)
#define I2C1_CONSET                     I2C_CONSET(I2C1)

/* I2C Status Register */
#define I2C_STAT(port)                  MMIO32((port) + 0x004)
#define I2C0_STAT                       I2C_STAT(I2C0)
#define I2C1_STAT                       I2C_STAT(I2C1)

/* I2C Data Register */
#define I2C_DAT(port)                   MMIO32((port) + 0x008)
#define I2C0_DAT                        I2C_DAT(I2C0)
#define I2C1_DAT                        I2C_DAT(I2C1)

/* I2C Slave Address Register 0 */
#define I2C_ADR0(port)                  MMIO32((port) + 0x00C)
#define I2C0_ADR0                       I2C_ADR0(I2C0)
#define I2C1_ADR0                       I2C_ADR0(I2C1)

/* SCH Duty Cycle Register High Half Word */
#define I2C_SCLH(port)                  MMIO32((port) + 0x010)
#define I2C0_SCLH                       I2C_SCLH(I2C0)
#define I2C1_SCLH                       I2C_SCLH(I2C1)

/* SCL Duty Cycle Register Low Half Word */
#define I2C_SCLL(port)                  MMIO32((port) + 0x014)
#define I2C0_SCLL                       I2C_SCLL(I2C0)
#define I2C1_SCLL                       I2C_SCLL(I2C1)

/* I2C Control Clear Register */
#define I2C_CONCLR(port)                MMIO32((port) + 0x018)
#define I2C0_CONCLR                     I2C_CONCLR(I2C0)
#define I2C1_CONCLR                     I2C_CONCLR(I2C1)

/* Monitor mode control register */
#define I2C_MMCTRL(port)                MMIO32((port) + 0x01C)
#define I2C0_MMCTRL                     I2C_MMCTRL(I2C0)
#define I2C1_MMCTRL                     I2C_MMCTRL(I2C1)

/* I2C Slave Address Register 1 */
#define I2C_ADR1(port)                  MMIO32((port) + 0x020)
#define I2C0_ADR1                       I2C_ADR1(I2C0)
#define I2C1_ADR1                       I2C_ADR1(I2C1)

/* I2C Slave Address Register 2 */
#define I2C_ADR2(port)                  MMIO32((port) + 0x024)
#define I2C0_ADR2                       I2C_ADR2(I2C0)
#define I2C1_ADR2                       I2C_ADR2(I2C1)

/* I2C Slave Address Register 3 */
#define I2C_ADR3(port)                  MMIO32((port) + 0x028)
#define I2C0_ADR3                       I2C_ADR3(I2C0)
#define I2C1_ADR3                       I2C_ADR3(I2C1)

/* Data buffer register */
#define I2C_DATA_BUFFER(port)           MMIO32((port) + 0x02C)
#define I2C0_DATA_BUFFER                I2C_DATA_BUFFER(I2C0)
#define I2C1_DATA_BUFFER                I2C_DATA_BUFFER(I2C1)

/* I2C Slave address mask register 0 */
#define I2C_MASK0(port)                 MMIO32((port) + 0x030)
#define I2C0_MASK0                      I2C_MASK0(I2C0)
#define I2C1_MASK0                      I2C_MASK0(I2C1)

/* I2C Slave address mask register 1 */
#define I2C_MASK1(port)                 MMIO32((port) + 0x034)
#define I2C0_MASK1                      I2C_MASK1(I2C0)
#define I2C1_MASK1                      I2C_MASK1(I2C1)

/* I2C Slave address mask register 2 */
#define I2C_MASK2(port)                 MMIO32((port) + 0x038)
#define I2C0_MASK2                      I2C_MASK2(I2C0)
#define I2C1_MASK2                      I2C_MASK2(I2C1)

/* I2C Slave address mask register 3 */
#define I2C_MASK3(port)                 MMIO32((port) + 0x03C)
#define I2C0_MASK3                      I2C_MASK3(I2C0)
#define I2C1_MASK3                      I2C_MASK3(I2C1)

/* --- I2Cx_CONCLR values -------------------------------------------------- */

#define I2C_CONCLR_AAC   (1 << 2) /* Assert acknowledge Clear */
#define I2C_CONCLR_SIC   (1 << 3) /* I2C interrupt Clear */
#define I2C_CONCLR_STAC  (1 << 5) /* START flag Clear */
#define I2C_CONCLR_I2ENC (1 << 6) /* I2C interface Disable bit */

/* --- I2Cx_CONSET values -------------------------------------------------- */

#define I2C_CONSET_AA   (1 << 2) /* Assert acknowledge flag */
#define I2C_CONSET_SI   (1 << 3) /* I2C interrupt flag */
#define I2C_CONSET_STO  (1 << 4) /* STOP flag */
#define I2C_CONSET_STA  (1 << 5) /* START flag */
#define I2C_CONSET_I2EN (1 << 6) /* I2C interface enable */

/* --- I2C const definitions ----------------------------------------------- */

#define I2C_WRITE           0
#define I2C_READ            1

/* --- I2C function prototypes --------------------------------------------- */

BEGIN_DECLS

void i2c0_init(const uint16_t duty_cycle_count);
void i2c0_tx_start(void);
void i2c0_tx_byte(uint8_t byte);
uint8_t i2c0_rx_byte(void);
void i2c0_stop(void);

END_DECLS

/**@}*/

#endif
