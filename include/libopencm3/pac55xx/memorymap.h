/**
 * @defgroup memorymap Peripheral Memory Map
 *
 * @ingroup PAC55xx_defines
 * @author Brian Viele <vielster@allocor.tech>
 * LGPL License Terms @ref lgpl_license
 * @date 1 Dec 2019
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
#ifndef INCLUDE_LIBOPENCM3_PAC55XX_MEMORYMAP_H_
#define INCLUDE_LIBOPENCM3_PAC55XX_MEMORYMAP_H_

/**@{*/

/** @defgroup address_memory Address Memory Map.
@{*/
#define FLASH_BASE (0x00000000UL)
#define INFO1_FLASH_BASE (0x00100000UL)
#define INFO2_FLASH_BASE (0x00100400UL)
#define INFO3_FLASH_BASE (0x00100800UL)
#define SRAM_BASE (0x20000000UL)
#define PERIPH_BASE (0x40000000UL)
/**@}*/
/** @defgroup peripheral_addresses Core Peripheral Memory Map.
@{*/
#define ADC_BASE (PERIPH_BASE + 0x00000)
#define I2C_BASE (PERIPH_BASE + 0x10000)
#define USARTA_BASE (PERIPH_BASE + 0x20000)
#define USARTB_BASE (PERIPH_BASE + 0x30000)
#define USARTC_BASE (PERIPH_BASE + 0x40000)
#define USARTD_BASE (PERIPH_BASE + 0x50000)
#define TIMERA_BASE (PERIPH_BASE + 0x60000)
#define TIMERB_BASE (PERIPH_BASE + 0x70000)
#define TIMERC_BASE (PERIPH_BASE + 0x80000)
#define TIMERD_BASE (PERIPH_BASE + 0x90000)
#define CAN_BASE (PERIPH_BASE + 0xA0000)
#define GPTIMERA_BASE (PERIPH_BASE + 0xB0000)
#define GPTIMERB_BASE (PERIPH_BASE + 0xC0000)
#define SYS_PERIPH_BASE (PERIPH_BASE + 0xD0000)
/**@}*/
/** @defgroup system_peripheral_addresses System Peripheral Memory Map.
@{*/
#define MEMCTL_BASE (SYS_PERIPH_BASE + 0x0000)
#define SCC_BASE (SYS_PERIPH_BASE + 0x0400)
#define WWDT_BASE (SYS_PERIPH_BASE + 0x0800)
#define RTC_BASE (SYS_PERIPH_BASE + 0x0C00)
#define CRC_BASE (SYS_PERIPH_BASE + 0x1000)
#define GPIOA_BASE (SYS_PERIPH_BASE + 0x1400)
#define GPIOB_BASE (SYS_PERIPH_BASE + 0x1800)
#define GPIOC_BASE (SYS_PERIPH_BASE + 0x1C00)
#define GPIOD_BASE (SYS_PERIPH_BASE + 0x2000)
#define GPIOE_BASE (SYS_PERIPH_BASE + 0x2400)
#define GPIOF_BASE (SYS_PERIPH_BASE + 0x2800)
#define GPIOG_BASE (SYS_PERIPH_BASE + 0x2C00)
/**@}*/
/**@}*/

#endif /* INCLUDE_LIBOPENCM3_PAC55XX_MEMORYMAP_H_ */
