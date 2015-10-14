/** @defgroup gpio_defines General Purpose I/O Defines
 *
 * @brief <b>Defined Constants and Types for the LM4F General Purpose I/O</b>
 *
 * @ingroup LM4Fxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Gareth McMullin <gareth@blacksphere.co.nz>
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Alexandru Gagniuc <mr.nuke.me@gmail.com>
 *
 * @date 16 March 2013
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
/** @defgroup gpio_pin_id GPIO pin identifiers
 * @{*/
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO_ALL			0xff
/** @} */

/* =============================================================================
 * GPIO registers
 * ---------------------------------------------------------------------------*/

/* GPIO Data */
#define GPIO_DATA(port)			(&MMIO32((port) + 0x000))

/* GPIO Direction */
#define GPIO_DIR(port)			MMIO32((port) + 0x400)

/* GPIO Interrupt Sense */
#define GPIO_IS(port)			MMIO32((port) + 0x404)

/* GPIO Interrupt Both Edges */
#define GPIO_IBE(port)			MMIO32((port) + 0x408)

/* GPIO Interrupt Event */
#define GPIO_IEV(port)			MMIO32((port) + 0x40c)

/* GPIO Interrupt Mask */
#define GPIO_IM(port)			MMIO32((port) + 0x410)

/* GPIO Raw Interrupt Status */
#define GPIO_RIS(port)			MMIO32((port) + 0x414)

/* GPIO Masked Interrupt Status */
#define GPIO_MIS(port)			MMIO32((port) + 0x418)

/* GPIO Interrupt Clear */
#define GPIO_ICR(port)			MMIO32((port) + 0x41c)

/* GPIO Alternate Function Select */
#define GPIO_AFSEL(port)		MMIO32((port) + 0x420)

/* GPIO 2-mA Drive Select */
#define GPIO_DR2R(port)			MMIO32((port) + 0x500)

/* GPIO 4-mA Drive Select */
#define GPIO_DR4R(port)			MMIO32((port) + 0x504)

/* GPIO 8-mA Drive Select */
#define GPIO_DR8R(port)			MMIO32((port) + 0x508)

/* GPIO Open Drain Select */
#define GPIO_ODR(port)			MMIO32((port) + 0x50c)

/* GPIO Pull-Up Select */
#define GPIO_PUR(port)			MMIO32((port) + 0x510)

/* GPIO Pull-Down Select */
#define GPIO_PDR(port)			MMIO32((port) + 0x514)

/* GPIO Slew Rate Control Select */
#define GPIO_SLR(port)			MMIO32((port) + 0x518)

/* GPIO Digital Enable */
#define GPIO_DEN(port)			MMIO32((port) + 0x51c)

/* GPIO Lock */
#define GPIO_LOCK(port)			MMIO32((port) + 0x520)

/* GPIO Commit */
#define GPIO_CR(port)			MMIO32((port) + 0x524)

/* GPIO Analog Mode Select */
#define GPIO_AMSEL(port)		MMIO32((port) + 0x528)

/* GPIO Port Control */
#define GPIO_PCTL(port)			MMIO32((port) + 0x52C)

/* GPIO ADC Control */
#define GPIO_ADCCTL(port)		MMIO32((port) + 0x530)

/* GPIO DMA Control */
#define GPIO_DMACTL(port)		MMIO32((port) + 0x534)

/* GPIO Peripheral Identification */
#define GPIO_PERIPH_ID4(port)		MMIO32((port) + 0xFD0)
#define GPIO_PERIPH_ID5(port)		MMIO32((port) + 0xFD4)
#define GPIO_PERIPH_ID6(port)		MMIO32((port) + 0xFD8)
#define GPIO_PERIPH_ID7(port)		MMIO32((port) + 0xFDC)
#define GPIO_PERIPH_ID0(port)		MMIO32((port) + 0xFE0)
#define GPIO_PERIPH_ID1(port)		MMIO32((port) + 0xFE4)
#define GPIO_PERIPH_ID2(port)		MMIO32((port) + 0xFE8)
#define GPIO_PERIPH_ID3(port)		MMIO32((port) + 0xFEC)

/* GPIO PrimeCell Identification */
#define GPIO_PCELL_ID0(port)		MMIO32((port) + 0xFF0)
#define GPIO_PCELL_ID1(port)		MMIO32((port) + 0xFF4)
#define GPIO_PCELL_ID2(port)		MMIO32((port) + 0xFF8)
#define GPIO_PCELL_ID3(port)		MMIO32((port) + 0xFFC)

/* =============================================================================
 * Convenience enums
 * ---------------------------------------------------------------------------*/
enum gpio_mode {
	GPIO_MODE_OUTPUT,	/**< Configure pin as output */
	GPIO_MODE_INPUT,	/**< Configure pin as input */
	GPIO_MODE_ANALOG,	/**< Configure pin as analog function */
};

enum gpio_pullup {
	GPIO_PUPD_NONE,		/**< Do not pull the pin high or low */
	GPIO_PUPD_PULLUP,	/**< Pull the pin high */
	GPIO_PUPD_PULLDOWN,	/**< Pull the pin low */
};

enum gpio_output_type {
	GPIO_OTYPE_PP,		/**< Push-pull configuration */
	GPIO_OTYPE_OD,		/**< Open drain configuration */
};

enum gpio_drive_strength {
	GPIO_DRIVE_2MA,		/**< 2mA drive */
	GPIO_DRIVE_4MA,		/**< 4mA drive */
	GPIO_DRIVE_8MA,		/**< 8mA drive */
	GPIO_DRIVE_8MA_SLEW_CTL,/**< 8mA drive with slew rate control */
};

enum gpio_trigger {
	GPIO_TRIG_LVL_LOW,	/**< Level trigger, signal low */
	GPIO_TRIG_LVL_HIGH,	/**< Level trigger, signal high */
	GPIO_TRIG_EDGE_FALL,	/**< Falling edge trigger */
	GPIO_TRIG_EDGE_RISE,	/**< Rising edge trigger*/
	GPIO_TRIG_EDGE_BOTH,	/**< Falling and Rising edges trigger*/
};
/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void gpio_enable_ahb_aperture(void);
void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode,
		     enum gpio_pullup pullup, uint8_t gpios);
void gpio_set_output_config(uint32_t gpioport, enum gpio_output_type otype,
			    enum gpio_drive_strength drive, uint8_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint8_t gpios);

void gpio_toggle(uint32_t gpioport, uint8_t gpios);
void gpio_unlock_commit(uint32_t gpioport, uint8_t gpios);

/* Let's keep these ones inlined. GPIO control should be fast */
/** @ingroup gpio_control
 * @{ */

/**
 * \brief Get status of a Group of Pins (atomic)
 *
 * Reads the level of the given pins. Bit 0 of the returned data corresponds to
 * GPIO0 level, bit 1 to GPIO1 level. and so on. Bits corresponding to masked
 * pins (corresponding bit of gpios parameter set to zero) are returned as 0.
 *
 * This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 *
 * @return The level of the GPIO port. The pins not specified in gpios are
 *	   masked to zero.
 */
static inline uint8_t gpio_read(uint32_t gpioport, uint8_t gpios)
{
	return GPIO_DATA(gpioport)[gpios];
}

/**
 * \brief Set level of a Group of Pins (atomic)
 *
 * Sets the level of the given pins. Bit 0 of the data parameter corresponds to
 * GPIO0, bit 1 to GPIO1. and so on. Maskedpins (corresponding bit of gpios
 * parameter set to zero) are returned not affected.
 *
 * This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 * @param[in] data Level to set pin to. Bit 0 of data corresponds to GPIO0, bit
 *		   1 to GPIO1. and so on.
 */
static inline void gpio_write(uint32_t gpioport, uint8_t gpios, uint8_t data)
{
	/* ipaddr[9:2] mask the bits to be set, hence the array index */
	GPIO_DATA(gpioport)[gpios] = data;
}

/**
 * \brief Set a Group of Pins (atomic)
 *
 * Set one or more pins of the given GPIO port. This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 */
static inline void gpio_set(uint32_t gpioport, uint8_t gpios)
{
	gpio_write(gpioport, gpios, 0xff);
}

/**
 * \brief Clear a Group of Pins (atomic)
 *
 * Clear one or more pins of the given GPIO port. This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 */
static inline void gpio_clear(uint32_t gpioport, uint8_t gpios)
{
	gpio_write(gpioport, gpios, 0);
}

/**
 * \brief Read level of all pins from a port (atomic)
 *
 * Read the current value of the given GPIO port. This is an atomic operation.
 *
 * This is functionally identical to @ref gpio_read (gpioport, GPIO_ALL).
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 *
 * @return The level of all the pins on the GPIO port.
 */
static inline uint8_t gpio_port_read(uint32_t gpioport)
{
	return gpio_read(gpioport, GPIO_ALL);
}

/**
 * \brief Set level of of all pins from a port (atomic)
 *
 * Set the level of all pins on the given GPIO port. This is an atomic
 * operation.
 *
 * This is functionally identical to @ref gpio_write (gpioport, GPIO_ALL, data).
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 * @param[in] data Level to set pin to. Bit 0 of data corresponds to GPIO0, bit
 *		   1 to GPIO1. and so on.
 */
static inline void gpio_port_write(uint32_t gpioport, uint8_t data)
{
	gpio_write(gpioport, GPIO_ALL, data);
}
/** @} */

void gpio_configure_trigger(uint32_t gpioport, enum gpio_trigger trigger,
			    uint8_t gpios);
void gpio_enable_interrupts(uint32_t gpioport, uint8_t gpios);
void gpio_disable_interrupts(uint32_t gpioport, uint8_t gpios);


/* Let's keep these ones inlined. GPIO. They are designed to be used in ISRs */
/** @ingroup gpio_irq
 * @{ */
/** \brief Determine if interrupt is generated by the given pin
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] srcpins source pin or group of pins to check.
 */
static inline bool gpio_is_interrupt_source(uint32_t gpioport, uint8_t srcpins)
{
	return GPIO_MIS(gpioport) & srcpins;
}

/**
 * \brief Mark interrupt as serviced
 *
 * After an interrupt is services, its flag must be cleared. If the flag is not
 * cleared, then execution will jump back to the start of the ISR after the ISR
 * returns.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 */
static inline void gpio_clear_interrupt_flag(uint32_t gpioport, uint8_t gpios)
{
	GPIO_ICR(gpioport) |= gpios;
}

/** @} */
END_DECLS

#endif

/**@}*/

