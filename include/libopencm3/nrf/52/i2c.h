/** @defgroup i2c_defines I2C Defines
 *
 * @brief <b>Defined Constants and Types for the NRF52xx I2C</b>
 *
 * @ingroup NRF52xx_defines
 *
 * @version 1.0.0
 *
 * @date Nov 2021
 *
 *LGPL License Terms @ref lgpl_license
 */
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
#include <libopencm3/nrf/common/i2c.h>

/**@{*/

#define I2C_EVENT_RXSTARTED(i2c)	MMIO32((i2c) + 0x14C)
#define I2C_EVENT_TXSTARTED(i2c)	MMIO32((i2c) + 0x150)
#define I2C_EVENT_LASTRX(i2c)		MMIO32((i2c) + 0x15C)
#define I2C_EVENT_LASTTX(i2c)		MMIO32((i2c) + 0x160)

#define I2C_RXDPTR(i2c)				MMIO32((i2c) + 0x534)
#define I2C_RXDMAXCNT(i2c)			MMIO32((i2c) + 0x538)
#define I2C_RXDAMOUNT(i2c)			MMIO32((i2c) + 0x53C)
#define I2C_RXDLIST(i2c)			MMIO32((i2c) + 0x540)
#define I2C_TXDPTR(i2c)				MMIO32((i2c) + 0x544)
#define I2C_TXDMAXCNT(i2c)			MMIO32((i2c) + 0x548)
#define I2C_TXDAMOUNT(i2c)			MMIO32((i2c) + 0x54C)
#define I2C_TXDLIST(i2c)			MMIO32((i2c) + 0x550)

/** @addtogroup i2c_shorts
 * @{
 */

/** On start of last byte transmission, activate start of reception task */
#define I2C_SHORTS_LASTTX_STARTRX	(1 << 7)

/** On start of last byte transmission, activate suspend task */
#define I2C_SHORTS_LASTTX_SUSPEND	(1 << 8)

/** On start of last byte transmission, activate stop task */
#define I2C_SHORTS_LASTTX_STOP		(1 << 9)

/** On start of last byte reception, activate start of transmission task */
#define I2C_SHORTS_LASTRX_STARTTX	(1 << 10)

/** On start of last byte reception, activate stop task */
#define I2C_SHORTS_LASTRX_STOP		(1 << 12)
/** @} */

/** @addtogroup i2c_inten I2C interrupt enable flags
 * @{ */

#define I2C_INTEN_SUSPENDED			(1 << 18)
#define I2C_INTEN_RXSTARTED			(1 << 19)
#define I2C_INTEN_TXSTARTED			(1 << 20)
#define I2C_INTEN_LASTRX			(1 << 23)
#define I2C_INTEN_LASTTX			(1 << 24)

/** @} */

/** @addtogroup i2c_mode I2C peripheral mode 
 * @{
 */

/** NRF52 I2C Master mode with EasyDMA support */
#define I2C_MODE_MASTER           (6)
/**@}*/


BEGIN_DECLS

void i2c_set_tx_buffer(uint32_t i2c, const uint8_t * buffer, uint8_t len);
void i2c_set_rx_buffer(uint32_t i2c, uint8_t * buffer, uint8_t len);

END_DECLS

/** @} */

