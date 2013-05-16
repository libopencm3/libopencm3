/** @defgroup gpio_defines General Purpose I/O Defines
 *
 * @brief <b>Defined Constants and Types for the LM4F General Purpose I/O</b>
 *
 * @ingroup LM4Fxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 *
 * @date 10 March 2013
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#ifndef LM4F_GPIO_H
#define LM4F_GPIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lm4f/memorymap.h>

/* =============================================================================
 * Convenience macros
 * ---------------------------------------------------------------------------*/
/** @defgroup gpio_reg_base GPIO register base addresses
 * @{*/
#define GPIOA				GPIOA_BASE
#define GPIOB				GPIOB_BASE
#define GPIOC				GPIOC_BASE
#define GPIOD				GPIOD_BASE
#define GPIOE				GPIOE_BASE
#define GPIOF				GPIOF_BASE
#define GPIOG				GPIOG_BASE
#define GPIOH				GPIOH_BASE
#define GPIOJ				GPIOJ_BASE
#define GPIOK				GPIOK_BASE
#define GPIOL				GPIOL_BASE
#define GPIOM				GPIOM_BASE
#define GPION				GPION_BASE
#define GPIOP				GPIOP_BASE
#define GPIOQ				GPIOQ_BASE
/** @} */

/* =============================================================================
 * GPIO number definitions (for convenience)
 *
 * These are usable across all GPIO registers,
 * except GPIO_LOCK and GPIO_PCTL
 * ---------------------------------------------------------------------------*/
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO_ALL			0xff

/* =============================================================================
 * GPIO registers
 * ---------------------------------------------------------------------------*/

/* GPIO Data */
#define GPIO_DATA(port)			((volatile u32 *)(port + 0x000))

/* GPIO Direction */
#define GPIO_DIR(port)			MMIO32(port + 0x400)

/* GPIO Interrupt Sense */
#define GPIO_IS(port)			MMIO32(port + 0x404)

/* GPIO Interrupt Both Edges */
#define GPIO_IBE(port)			MMIO32(port + 0x408)

/* GPIO Interrupt Event */
#define GPIO_IEV(port)			MMIO32(port + 0x40c)

/* GPIO Interrupt Mask */
#define GPIO_IM(port)			MMIO32(port + 0x410)

/* GPIO Raw Interrupt Status */
#define GPIO_RIS(port)			MMIO32(port + 0x414)

/* GPIO Masked Interrupt Status */
#define GPIO_MIS(port)			MMIO32(port + 0x418)

/* GPIO Interrupt Clear */
#define GPIO_ICR(port)			MMIO32(port + 0x41c)

/* GPIO Alternate Function Select */
#define GPIO_AFSEL(port)		MMIO32(port + 0x420)

/* GPIO 2-mA Drive Select */
#define GPIO_DR2R(port)			MMIO32(port + 0x500)

/* GPIO 4-mA Drive Select */
#define GPIO_DR4R(port)			MMIO32(port + 0x504)

/* GPIO 8-mA Drive Select */
#define GPIO_DR8R(port)			MMIO32(port + 0x508)

/* GPIO Open Drain Select */
#define GPIO_ODR(port)			MMIO32(port + 0x50c)

/* GPIO Pull-Up Select */
#define GPIO_PUR(port)			MMIO32(port + 0x510)

/* GPIO Pull-Down Select */
#define GPIO_PDR(port)			MMIO32(port + 0x514)

/* GPIO Slew Rate Control Select */
#define GPIO_SLR(port)			MMIO32(port + 0x518)

/* GPIO Digital Enable */
#define GPIO_DEN(port)			MMIO32(port + 0x51c)

/* GPIO Lock */
#define GPIO_LOCK(port)			MMIO32(port + 0x520)

/* GPIO Commit */
#define GPIO_CR(port)			MMIO32(port + 0x524)

/* GPIO Analog Mode Select */
#define GPIO_AMSEL(port)		MMIO32(port + 0x528)

/* GPIO Port Control */
#define GPIO_PCTL(port)			MMIO32(port + 0x52C)

/* GPIO ADC Control */
#define GPIO_ADCCTL(port)		MMIO32(port + 0x530)

/* GPIO DMA Control */
#define GPIO_DMACTL(port)		MMIO32(port + 0x534)

/* GPIO Peripheral Identification */
#define GPIO_PERIPH_ID4(port)		MMIO32(port + 0xFD0)
#define GPIO_PERIPH_ID5(port)		MMIO32(port + 0xFD4)
#define GPIO_PERIPH_ID6(port)		MMIO32(port + 0xFD8)
#define GPIO_PERIPH_ID7(port)		MMIO32(port + 0xFDC)
#define GPIO_PERIPH_ID0(port)		MMIO32(port + 0xFE0)
#define GPIO_PERIPH_ID1(port)		MMIO32(port + 0xFE4)
#define GPIO_PERIPH_ID2(port)		MMIO32(port + 0xFE8)
#define GPIO_PERIPH_ID3(port)		MMIO32(port + 0xFEC)

/* GPIO PrimeCell Identification */
#define GPIO_PCELL_ID0(port)		MMIO32(port + 0xFF0)
#define GPIO_PCELL_ID1(port)		MMIO32(port + 0xFF4)
#define GPIO_PCELL_ID2(port)		MMIO32(port + 0xFF8)
#define GPIO_PCELL_ID3(port)		MMIO32(port + 0xFFC)


BEGIN_DECLS

void gpio_set(u32 gpioport, u8 gpios);
void gpio_clear(u32 gpioport, u8 gpios);

END_DECLS

#endif

/**@}*/

