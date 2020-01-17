/**
 * @brief GPIO definitions for the Qorvo PAC55xx series of microcontrollers.
 *
 *  @addtogroup PAC55xx_gpio GPIO
 *  @ingroup PAC55xx_defines
 *  @author Brian Viele <vielster@allocor.tech>
 *  LGPL License Terms @ref lgpl_license
 *  @date 1 Dec 2019
 *
 *  Definitions in this file come from the PAC55XX Family User Guide Rev 1.21
 *  by Active-Semi dated August 26, 2019.
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
#ifndef INCLUDE_LIBOPENCM3_PAC55XX_GPIO_H_
#define INCLUDE_LIBOPENCM3_PAC55XX_GPIO_H_

#include <libopencm3/cm3/common.h>

/* Note: CCS include file defines pinmux, drive strength, pull-up/pull-down, etc. */
#include <libopencm3/pac55xx/ccs.h>
#include <libopencm3/pac55xx/memorymap.h>

/**@{*/

/** GPIO port base addresses (for convenience)
 * @defgroup gpio_port_id GPIO Port IDs
 * @{*/
#define GPIOA GPIOA_BASE
#define GPIOB GPIOB_BASE
#define GPIOC GPIOC_BASE
#define GPIOD GPIOD_BASE
#define GPIOE GPIOE_BASE
#define GPIOF GPIOF_BASE
#define GPIOG GPIOG_BASE
/**@}*/

/** GPIO number definitions (for convenience)
 * @defgroup gpio_pin_id GPIO Pin Identifiers
 * @{*/
#define GPIO_MAX_PIN (7U)
#define GPIO0 BIT0
#define GPIO1 BIT1
#define GPIO2 BIT2
#define GPIO3 BIT3
#define GPIO4 BIT4
#define GPIO5 BIT5
#define GPIO6 BIT6
#define GPIO7 BIT7
#define GPIO_ALL 0xff
/**@}*/

/** GPIO Mode Register Definitions
 * @defgroup gpio_mode_regs GPIO MODE register mapping.
 * @{*/
/* Enum definitions for at least minimal type safety. */
typedef enum {
	GPIO_ANALOG_INPUT = 0,
	GPIO_PUSH_PULL_OUTPUT = 1,
	GPIO_OPEN_DRAIN_OUTPUT = 2,
	GPIO_HIGH_IMPEDENCE_INPUT = 3,
} gpio_mode_t;
#define GPIO_MODER(base) MMIO32((base) + 0x00)
#define GPIOA_MODER GPIO_MODER(GPIOA)
#define GPIOB_MODER GPIO_MODER(GPIOB)
#define GPIOC_MODER GPIO_MODER(GPIOC)
#define GPIOD_MODER GPIO_MODER(GPIOD)
#define GPIOE_MODER GPIO_MODER(GPIOE)
#define GPIOF_MODER GPIO_MODER(GPIOF)
#define GPIOG_MODER GPIO_MODER(GPIOG)
#define GPIO_MODER_MASK 0x3
#define GPIO_MODER_MASK_PIN(pin) (GPIO_MODER_MASK << ((pin)*2))
#define GPIO_MODER_MODE(pin, mode) (((mode)&GPIO_MODER_MASK) << ((pin)*2))
/**@}*/

/** GPIO Output Mask Register Definitions. This register may be used to lock the output value of
 * a pin as changes to masked pins will have no effect.
 * @defgroup gpio_outmask_regs GPIO OUTMASK register mapping.
 * @{*/
#define GPIO_OUTMASKR(base) MMIO32((base) + 0x04)
#define GPIOA_OUTMASKR GPIO_OUTMASKR(GPIOA)
#define GPIOB_OUTMASKR GPIO_OUTMASKR(GPIOB)
#define GPIOC_OUTMASKR GPIO_OUTMASKR(GPIOC)
#define GPIOD_OUTMASKR GPIO_OUTMASKR(GPIOD)
#define GPIOE_OUTMASKR GPIO_OUTMASKR(GPIOE)
#define GPIOF_OUTMASKR GPIO_OUTMASKR(GPIOF)
#define GPIOG_OUTMASKR GPIO_OUTMASKR(GPIOG)
/**@}*/

/** GPIO Output Register Definitions.
 * @defgroup gpio_out_regs GPIO OUT register mapping.
 * @{*/
#define GPIO_OUTR(base) MMIO32((base) + 0x08)
#define GPIOA_OUTR GPIO_OUTR(GPIOA)
#define GPIOB_OUTR GPIO_OUTR(GPIOB)
#define GPIOC_OUTR GPIO_OUTR(GPIOC)
#define GPIOD_OUTR GPIO_OUTR(GPIOD)
#define GPIOE_OUTR GPIO_OUTR(GPIOE)
#define GPIOF_OUTR GPIO_OUTR(GPIOF)
#define GPIOG_OUTR GPIO_OUTR(GPIOG)
/**@}*/

/** GPIO Input Register Definitions.
 * @defgroup gpio_in_regs GPIO IN register mapping.
 * @{*/
#define GPIO_INR(base) MMIO32((base) + 0x0C)
#define GPIOA_INR GPIO_INR(GPIOA)
#define GPIOB_INR GPIO_INR(GPIOB)
#define GPIOC_INR GPIO_INR(GPIOC)
#define GPIOD_INR GPIO_INR(GPIOD)
#define GPIOE_INR GPIO_INR(GPIOE)
#define GPIOF_INR GPIO_INR(GPIOF)
#define GPIOG_INR GPIO_INR(GPIOG)
/**@}*/

/** GPIO Interrupt Enable Register Definitions.
 * @defgroup gpio_inten_regs GPIO INTEN register mapping.
 * @{*/
#define GPIO_INTENR(base) MMIO32((base) + 0x10)
#define GPIOA_INTENR GPIO_INTENR(GPIOA)
#define GPIOB_INTENR GPIO_INTENR(GPIOB)
#define GPIOC_INTENR GPIO_INTENR(GPIOC)
#define GPIOD_INTENR GPIO_INTENR(GPIOD)
#define GPIOE_INTENR GPIO_INTENR(GPIOE)
#define GPIOF_INTENR GPIO_INTENR(GPIOF)
#define GPIOG_INTENR GPIO_INTENR(GPIOG)
/**@}*/

/** GPIO Interrupt Flag Register Definitions.
 * @defgroup gpio_intflag_regs GPIO INTFLAG register mapping.
 * @{*/
#define GPIO_INTFLAGR(base) MMIO32((base) + 0x14)
#define GPIOA_INTFLAGR GPIO_INTFLAGR(GPIOA)
#define GPIOB_INTFLAGR GPIO_INTFLAGR(GPIOB)
#define GPIOC_INTFLAGR GPIO_INTFLAGR(GPIOC)
#define GPIOD_INTFLAGR GPIO_INTFLAGR(GPIOD)
#define GPIOE_INTFLAGR GPIO_INTFLAGR(GPIOE)
#define GPIOF_INTFLAGR GPIO_INTFLAGR(GPIOF)
#define GPIOG_INTFLAGR GPIO_INTFLAGR(GPIOG)
/**@}*/

/** GPIO Interrupt Clear Register Definitions.
 * @defgroup gpio_intclear_regs GPIO INTCLEAR register mapping.
 * @{*/
#define GPIO_INTCLEARR(base) MMIO32((base) + 0x1C)
#define GPIOA_INTCLEARR GPIO_INTCLEARR(GPIOA)
#define GPIOB_INTCLEARR GPIO_INTCLEARR(GPIOB)
#define GPIOC_INTCLEARR GPIO_INTCLEARR(GPIOC)
#define GPIOD_INTCLEARR GPIO_INTCLEARR(GPIOD)
#define GPIOE_INTCLEARR GPIO_INTCLEARR(GPIOE)
#define GPIOF_INTCLEARR GPIO_INTCLEARR(GPIOF)
#define GPIOG_INTCLEARR GPIO_INTCLEARR(GPIOG)
/**@}*/

/** GPIO Interrupt Type Register Definitions.
 * @defgroup gpio_inttype_regs GPIO INTTYPE register mapping.
 * @{*/
#define GPIO_INTTYPE_EDGE 0U
#define GPIO_INTTYPE_LEVEL 1U
#define GPIO_INTTYPER(base) MMIO32((base) + 0x20)
#define GPIOA_INTTYPER GPIO_INTTYPER(GPIOA)
#define GPIOB_INTTYPER GPIO_INTTYPER(GPIOB)
#define GPIOC_INTTYPER GPIO_INTTYPER(GPIOC)
#define GPIOD_INTTYPER GPIO_INTTYPER(GPIOD)
#define GPIOE_INTTYPER GPIO_INTTYPER(GPIOE)
#define GPIOF_INTTYPER GPIO_INTTYPER(GPIOF)
#define GPIOG_INTTYPER GPIO_INTTYPER(GPIOG)
/**@}*/

/** GPIO Interrupt Config Register Definitions.
 * @defgroup gpio_intcfg_regs GPIO INTCFG register mapping.
 * @{*/
#define GPIO_INTCFG_FALLING_LOW 0U
#define GPIO_INTCFG_RISING_HIGH 1U
#define GPIO_INTCFGR(base) MMIO32((base) + 0x24)
#define GPIOA_INTCFGR GPIO_INTCFGR(GPIOA)
#define GPIOB_INTCFGR GPIO_INTCFGR(GPIOB)
#define GPIOC_INTCFGR GPIO_INTCFGR(GPIOC)
#define GPIOD_INTCFGR GPIO_INTCFGR(GPIOD)
#define GPIOE_INTCFGR GPIO_INTCFGR(GPIOE)
#define GPIOF_INTCFGR GPIO_INTCFGR(GPIOF)
#define GPIOG_INTCFGR GPIO_INTCFGR(GPIOG)
/**@}*/

/** GPIO Interrupt Edge Both Definitions. This overrides the config if set.
 * @defgroup gpio_intedgeboth_regs GPIO INTEDGEBOTH register mapping.
 * @{*/
#define GPIO_INTEDGEBOTHR(base) MMIO32((base) + 0x28)
#define GPIOA_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOA)
#define GPIOB_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOB)
#define GPIOC_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOC)
#define GPIOD_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOD)
#define GPIOE_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOE)
#define GPIOF_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOF)
#define GPIOG_INTEDGEBOTHR GPIO_INTEDGEBOTHR(GPIOG)
/**@}*/

/** GPIO Clock Synchronization Settings. When set, this enables 3-clock synchronizer on pins.
 * @defgroup gpio_clksync_regs GPIO CLKSYNC register mapping.
 * @{*/
#define GPIO_CLKSYNCR(base) MMIO32((base) + 0x2C)
#define GPIOA_CLKSYNCR GPIO_CLKSYNCR(GPIOA)
#define GPIOB_CLKSYNCR GPIO_CLKSYNCR(GPIOB)
#define GPIOC_CLKSYNCR GPIO_CLKSYNCR(GPIOC)
#define GPIOD_CLKSYNCR GPIO_CLKSYNCR(GPIOD)
#define GPIOE_CLKSYNCR GPIO_CLKSYNCR(GPIOE)
#define GPIOF_CLKSYNCR GPIO_CLKSYNCR(GPIOF)
#define GPIOG_CLKSYNCR GPIO_CLKSYNCR(GPIOG)
/**@}*/

/** GPIO Set Register. This register can be used for atomic setting of outputs.
 * @defgroup gpio_doset_regs GPIO DOSET register mapping.
 * @{*/
#define GPIO_DOSETR(base) MMIO32((base) + 0x30)
#define GPIOA_DOSETR GPIO_DOSETR(GPIOA)
#define GPIOB_DOSETR GPIO_DOSETR(GPIOB)
#define GPIOC_DOSETR GPIO_DOSETR(GPIOC)
#define GPIOD_DOSETR GPIO_DOSETR(GPIOD)
#define GPIOE_DOSETR GPIO_DOSETR(GPIOE)
#define GPIOF_DOSETR GPIO_DOSETR(GPIOF)
#define GPIOG_DOSETR GPIO_DOSETR(GPIOG)
/**@}*/

/** GPIO Set Register. This register can be used for atomic setting of outputs.
 * @defgroup gpio_doclear_regs GPIO DOCLEAR register mapping.
 * @{*/
#define GPIO_DOCLEARR(base) MMIO32((base) + 0x34)
#define GPIOA_DOCLEARR GPIO_DOCLEARR(GPIOA)
#define GPIOB_DOCLEARR GPIO_DOCLEARR(GPIOB)
#define GPIOC_DOCLEARR GPIO_DOCLEARR(GPIOC)
#define GPIOD_DOCLEARR GPIO_DOCLEARR(GPIOD)
#define GPIOE_DOCLEARR GPIO_DOCLEARR(GPIOE)
#define GPIOF_DOCLEARR GPIO_DOCLEARR(GPIOF)
#define GPIOG_DOCLEARR GPIO_DOCLEARR(GPIOG)
/**@}*/

/**@}*/

BEGIN_DECLS
/** GPIO Application Programming Interface.
 * @defgroup gpio_api GPIO Peripheral API
 * @ingroup peripheral_apis
@{*/
/**
 * Set the IO mode and pull-up/down configuration for the pins.
 * @param[in] gpioport  Port to configure the alternate function on.
 * @param[in] mode  IO Mode to configure (analog, input, output).
 * @param[in] pull_up_down  Pull configuration (up/down/none) to set for the pins..
 * @param[in] gpios  Pins to set with the mode and pull config specified.
 */
void gpio_mode_setup(uint32_t gpioport, gpio_mode_t mode,
		     ccs_pull_updown_t pull_up_down, uint16_t gpios);
/**
 * Set the output mask (disable changes) to the output pins specified.
 * @param[in] gpioport  Port to set output mask on.
 * @param[in] enable  Whether to enable or disable output masking.
 * @param[in] gpios  bitfield of pins to set.
 */
void gpio_set_outmask(uint32_t gpioport, bool enable, uint16_t gpios);
/**
 * Set the port pins specified to the true state.
 * @param[in] gpioport  Port to set bits on.
 * @param[in] gpios  bitfield of pins to set.
 */
void gpio_set(uint32_t gpioport, uint16_t gpios);
/**
 * Clear the port pins specified to the false state.
 * @param[in] gpioport  Port to clear bits on.
 * @param[in] gpios  bitfield of pins to clear.
 */
void gpio_clear(uint32_t gpioport, uint16_t gpios);
/**
 * Return a masked bitfield of the port specified.
 * @param[in] gpioport  Port to read the bits from.
 * @param[in] gpios  bitfield mask to apply to the port read.
 * @return masked bitfield of the port.
 */
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
/**
 * Set the function of the pin for this port. This will modify the pinmux,
 * @param[in] gpioport  Port to configure the alternate function on.
 * @param[in] muxsel  Mux select mode to configure on the port and pins.
 * @param[in] gpios  Pins to set with the function specified.
 */
void gpio_set_af(uint32_t gpioport, ccs_muxsel_func_t muxsel, uint16_t gpios);

/**
 * Set special output options for the gpio pin. For this MCU, this is only the drive strength.
 * @param[in] gpioport  Port to configure the alternate function on.
 * @param[in] strength  Drive strength (DS_XXMA from ccs.h).
 * @param[in] gpios  Pins to set with the drive strength specified.
 */
void gpio_set_output_options(uint32_t gpioport, ccs_drive_strength_t strength,
			     uint16_t gpios);
/**
 * Set input schmidt trigger for glitch rejection on the input pin.
 * @param[in] gpioport  Port to configure the alternate function on.
 * @param[in] enable  True to enable, false to disable the schmidt trigger.
 * @param[in] gpios  Pins to set with the schmidt trigger setting specified.
 */
void gpio_set_schmidt_trigger(uint32_t gpioport, bool enable, uint16_t gpios);
/**@}*/

END_DECLS

#endif /* INCLUDE_LIBOPENCM3_PAC55XX_GPIO_H_ */
