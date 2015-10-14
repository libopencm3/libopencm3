/** @defgroup i2s_defines I2S Defines

@brief <b>Defined Constants and Types for the LPC43xx I2S</b>

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

#ifndef LPC43XX_I2S_H
#define LPC43XX_I2S_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* I2S port base addresses (for convenience) */
#define I2S0                            I2S0_BASE
#define I2S1                            I2S1_BASE

/* --- I2S registers ------------------------------------------------------- */

/* I2S Digital Audio Output Register */
#define I2S_DAO(port)                   MMIO32((port) + 0x000)
#define I2S0_DAO                        I2S_DAO(I2S0)
#define I2S1_DAO                        I2S_DAO(I2S1)

/* I2S Digital Audio Input Register */
#define I2S_DAI(port)                   MMIO32((port) + 0x004)
#define I2S0_DAI                        I2S_DAI(I2S0)
#define I2S1_DAI                        I2S_DAI(I2S1)

/* I2S Transmit FIFO */
#define I2S_TXFIFO(port)                MMIO32((port) + 0x008)
#define I2S0_TXFIFO                     I2S_TXFIFO(I2S0)
#define I2S1_TXFIFO                     I2S_TXFIFO(I2S1)

/* I2S Receive FIFO */
#define I2S_RXFIFO(port)                MMIO32((port) + 0x00C)
#define I2S0_RXFIFO                     I2S_RXFIFO(I2S0)
#define I2S1_RXFIFO                     I2S_RXFIFO(I2S1)

/* I2S Status Feedback Register */
#define I2S_STATE(port)                 MMIO32((port) + 0x010)
#define I2S0_STATE                      I2S_STATE(I2S0)
#define I2S1_STATE                      I2S_STATE(I2S1)

/* I2S DMA Configuration Register 1 */
#define I2S_DMA1(port)                  MMIO32((port) + 0x014)
#define I2S0_DMA1                       I2S_DMA1(I2S0)
#define I2S1_DMA1                       I2S_DMA1(I2S1)

/* I2S DMA Configuration Register 2 */
#define I2S_DMA2(port)                  MMIO32((port) + 0x018)
#define I2S0_DMA2                       I2S_DMA2(I2S0)
#define I2S1_DMA2                       I2S_DMA2(I2S1)

/* I2S Interrupt Request Control Register */
#define I2S_IRQ(port)                   MMIO32((port) + 0x01C)
#define I2S0_IRQ                        I2S_IRQ(I2S0)
#define I2S1_IRQ                        I2S_IRQ(I2S1)

/* I2S Transmit MCLK divider */
#define I2S_TXRATE(port)                MMIO32((port) + 0x020)
#define I2S0_TXRATE                     I2S_TXRATE(I2S0)
#define I2S1_TXRATE                     I2S_TXRATE(I2S1)

/* I2S Receive MCLK divider */
#define I2S_RXRATE(port)                MMIO32((port) + 0x024)
#define I2S0_RXRATE                     I2S_RXRATE(I2S0)
#define I2S1_RXRATE                     I2S_RXRATE(I2S1)

/* I2S Transmit bit rate divider */
#define I2S_TXBITRATE(port)             MMIO32((port) + 0x028)
#define I2S0_TXBITRATE                  I2S_TXBITRATE(I2S0)
#define I2S1_TXBITRATE                  I2S_TXBITRATE(I2S1)

/* I2S Receive bit rate divider */
#define I2S_RXBITRATE(port)             MMIO32((port) + 0x02C)
#define I2S0_RXBITRATE                  I2S_RXBITRATE(I2S0)
#define I2S1_RXBITRATE                  I2S_RXBITRATE(I2S1)

/* I2S Transmit mode control */
#define I2S_TXMODE(port)                MMIO32((port) + 0x030)
#define I2S0_TXMODE                     I2S_TXMODE(I2S0)
#define I2S1_TXMODE                     I2S_TXMODE(I2S1)

/* I2S Receive mode control */
#define I2S_RXMODE(port)                MMIO32((port) + 0x034)
#define I2S0_RXMODE                     I2S_RXMODE(I2S0)
#define I2S1_RXMODE                     I2S_RXMODE(I2S1)

/**@}*/

#endif
