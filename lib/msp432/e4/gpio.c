/** @defgroup gpio_file General-Purpose I/O
 *
 * @ingroup MSP432E4xx
 *
 * @brief libopencm3 MSP432E4xx General Purpose Input/Outputs
 *
 * @version 1.0.0
 *
 * @date 16 September 2018
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 * Copyright (C) 2018 Dmitry Rezvanov <dmitry.rezvanov@yandex.ru>
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

#include <libopencm3/msp432/e4/gpio.h>
#include <libopencm3/msp432/e4/systemcontrol.h>

/** @brief General Purpose Input/Outputs Set Pin Mode
 *
 * Sets the Pin Direction and Analog/Digital Mode, and Output Pin Pullup,
 * for a set of GPIO pins on a given GPIO port.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] mode Pin mode (@ref gpio_mode) \n
 *            - GPIO_MODE_OUTPUT -- Configure pin as output \n
 *            - GPIO_MODE_INPUT  -- Configure pin as input \n
 *            - GPIO_MODE_ANALOG -- Configure pin as analog function
 * @param[in] pullup Pin pullup/pulldown configuration (@ref gpio_pullup) \n
 *            - GPIO_PUPD_NONE     -- Do not pull the pin high or low \n
 *            - GPIO_PUPD_PULLUP   -- Pull the pin high \n
 *            - GPIO_PUPD_PULLDOWN -- Pull the pin low
 * @param[in] gpios @ref gpio_pin_id.  If multiple pins are to be set,
 *            use bitwise OR '|' to separate them.
 */
void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode,
                     enum gpio_pullup pullup, uint8_t gpios)
{
    GPIO_AFSEL(gpioport) &= ~gpios;

    switch (mode) {
    case GPIO_MODE_OUTPUT:
        GPIO_DIR(gpioport) |= gpios;
        GPIO_DEN(gpioport) |= gpios;
        GPIO_AMSEL(gpioport) &= ~gpios;
        break;
    case GPIO_MODE_INPUT:
        GPIO_DIR(gpioport) &= ~gpios;
        GPIO_DEN(gpioport) |= gpios;
        GPIO_AMSEL(gpioport) &= ~gpios;
        break;
    case GPIO_MODE_ANALOG:
        GPIO_AFSEL(gpioport) |= gpios;
        GPIO_DEN(gpioport) &= ~gpios;
        GPIO_AMSEL(gpioport) |= gpios;
        break;
    default:
        /* Don't do anything */
        break;
    }

    /*
     * Setting a bit in the GPIO_PDR register clears the corresponding bit
     * in the GPIO_PUR register, and vice-versa.
     */
    switch (pullup) {
    case GPIO_PUPD_PULLUP:
        GPIO_PDR(gpioport) &= ~gpios;
        GPIO_PUR(gpioport) |= gpios;
        break;
    case GPIO_PUPD_PULLDOWN:
        GPIO_PUR(gpioport) &= ~gpios;
        GPIO_PDR(gpioport) |= gpios;
        break;
    case GPIO_PUPD_NONE:	/* Fall through */
    default:
        GPIO_PUR(gpioport) &= ~gpios;
        GPIO_PDR(gpioport) &= ~gpios;
        break;
    }
}

/** @brief General Purpose Input/Outputs Set Output Options
 *
 * Sets the output configuration and drive strength, of or a set of GPIO pins
 * for a set of GPIO pins in output mode.
 *
 * @param[in] gpioport GPIO block register address base (@ref gpio_reg_base)
 * @param[in] otype Output driver configuration (@ref gpio_output_type) \n
 *            - GPIO_OTYPE_PP -- Configure pin driver as push-pull \n
 *            - GPIO_OTYPE_OD -- Configure pin driver as open drain
 * @param[in] drive Pin drive strength (@ref gpio_drive_strength) \n
 *            - GPIO_DRIVE_2MA  -- 2mA drive \n
 *            - GPIO_DRIVE_4MA  -- 4mA drive \n
 *            - GPIO_DRIVE_6MA  -- 4mA drive \n
 *            - GPIO_DRIVE_8MA  -- 8mA drive \n
 *            - GPIO_DRIVE_10MA -- 10mA drive \n
 *            - GPIO_DRIVE_12MA -- 12mA drive
 * @param[in] slewctl Pin slew rate control select (@ref gpio_slew_ctl).
 *            Available only for 8, 10 and 12-ma drive strength.
 *            - GPIO_SLEW_CTL_ENABLE  -- Slew rate control enable
 *            - GPIO_SLEW_CTL_DISABLE -- Slew rate control disable
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *            by OR'ing then together
 */
void gpio_set_output_options(uint32_t gpioport,
                            enum gpio_output_type otype,
                            enum gpio_drive_strength drive,
                            enum gpio_slew_ctl slewctl,
                            uint8_t gpios)
{
    uint8_t i;
    uint8_t pin_mask;

    if (otype == GPIO_OTYPE_OD) {
        GPIO_ODR(gpioport) |= gpios;
    } else {
        GPIO_ODR(gpioport) &= ~gpios;
    }

    GPIO_PP(gpioport) |= GPIO_PP_EDE;

    for (i = 0; i < 8; i++) {
        pin_mask = (1 << i);

        if (!(gpios & pin_mask)) {
            continue;
        }

        GPIO_PC(gpioport) &= ~GPIO_EDM_MASK(i);
        GPIO_PC(gpioport) |= GPIO_EDM(i, GPIO_EDM_FULL_RANGE);
    }

    GPIO_DR4R(gpioport) &= ~gpios;
    GPIO_DR8R(gpioport) &= ~gpios;
    GPIO_DR12R(gpioport) &= ~gpios;

    switch (drive) {
    case GPIO_DRIVE_4MA:
        GPIO_DR4R(gpioport) |= gpios;
        break;
    case GPIO_DRIVE_6MA:
        GPIO_DR8R(gpioport) |= gpios;
        break;
    case GPIO_DRIVE_8MA:
        GPIO_DR4R(gpioport) |= gpios;
        GPIO_DR8R(gpioport) |= gpios;
        break;
    case GPIO_DRIVE_10MA:
        GPIO_DR8R(gpioport) |= gpios;
        GPIO_DR12R(gpioport) |= gpios;
        break;
    case GPIO_DRIVE_12MA:
        GPIO_DR4R(gpioport) |= gpios;
        GPIO_DR8R(gpioport) |= gpios;
        GPIO_DR12R(gpioport) |= gpios;
        break;
    case GPIO_DRIVE_2MA:	/* Fall through */
    default:
        /* don't anything */
        break;
    }

    if ((slewctl == GPIO_SLEW_CTL_ENABLE) &&
       ((drive ==  GPIO_DRIVE_8MA) || (drive ==  GPIO_DRIVE_10MA) ||
        (drive ==  GPIO_DRIVE_12MA))) {
        GPIO_SLR(gpioport) |= gpios;
    } else {
        GPIO_SLR(gpioport) &= ~gpios;
    }
}

#define PCTL_AF(pin, af)        ((af) << ((pin) * 4))
#define PCTL_MASK(pin)          PCTL_AF((pin), 0xf)

/** @brief General Purpose Input/Outputs Set Alternate Function Selection
 *
 * Mux the pin or group of pins to the given alternate function. Note that a
 * number of pins may be set but only with a single AF number. This is useful
 * when one or more of a peripheral's pins are assigned to the same alternate
 * function.
 *
 * Because AF0 is not used on the LM4F, passing 0 as the alt_func_num parameter
 * will disable the alternate function of the given pins.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] alt_func_num Pin alternate function number or 0 to disable the
 *            alternate function multiplexing.
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *            by OR'ing then together
 */
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint8_t gpios)
{
    uint32_t pctl32;
    uint8_t pin_mask;
    uint8_t i;

    /* Did we mean to disable the alternate function? */
    if (alt_func_num == 0) {
        GPIO_AFSEL(gpioport) &= ~gpios;
        return;
    }

    /* Enable the alternate function */
    GPIO_AFSEL(gpioport) |= gpios;

    /* Now take care of the actual multiplexing */
    pctl32 = GPIO_PCTL(gpioport);
    for (i = 0; i < 8; i++) {
        pin_mask = (1 << i);

        if (!(gpios & pin_mask)) {
            continue;
        }

        pctl32 &= ~PCTL_MASK(i);
        pctl32 |= PCTL_AF(i, (alt_func_num & 0xf));
    }

    GPIO_PCTL(gpioport) = pctl32;
}

/** @brief General Purpose Input/Outputs Unlock the commit control
 *
 * Unlocks the commit control of the given pin or group of pins. If a pin is a
 * JTAG/SWD or NMI, the pin may then be reconfigured as a GPIO pin. If the pin
 * is not locked by default, this has no effect.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *            by OR'ing then together.
 */
void gpio_unlock_commit(uint32_t gpioport, uint8_t gpios)
{
    /* Unlock the GPIO_CR register */
    GPIO_LOCK(gpioport) = GPIO_LOCK_UNLOCK_CODE;
    /* Enable committing changes */
    GPIO_CR(gpioport) |= gpios;
    /* Lock the GPIO_CR register */
    GPIO_LOCK(gpioport) = ~GPIO_LOCK_UNLOCK_CODE;
}

/**
 * @brief General Purpose Input/Outputs Toggle a Group of Pins
 *
 * Toggle one or more pins of the given GPIO port.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios Pin identifiers. @ref gpio_pin_id
 */
void gpio_toggle(uint32_t gpioport, uint8_t gpios)
{
    /* The mask makes sure we only toggle the GPIOs we want to */
    GPIO_DATA(gpioport)[gpios] ^= GPIO_ALL;
}

/** @brief Configure the interrupt trigger on the given GPIO pins
 *
 * Sets the Pin direction, analog/digital mode, and pull-up configuration of
 * or a set of GPIO pins on a given GPIO port.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] trigger Trigger configuration (@ref gpio_trigger) \n
 *            - GPIO_TRIG_LVL_LOW -- Trigger on low level \n
 *            - GPIO_TRIG_LVL_HIGH -- Trigger on high level \n
 *            - GPIO_TRIG_EDGE_FALL -- Trigger on falling edges \n
 *            - GPIO_TRIG_EDGE_RISE -- Trigger on rising edges \n
 *            - GPIO_TRIG_EDGE_BOTH -- Trigger on all edges
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *            by OR'ing then together
 */
void gpio_configure_trigger(uint32_t gpioport, enum gpio_trigger trigger,
                            uint8_t gpios)
{
    switch (trigger) {
    case GPIO_TRIG_LVL_LOW:
        GPIO_IS(gpioport) |= gpios;
        GPIO_IEV(gpioport) &= ~gpios;
        break;
    case GPIO_TRIG_LVL_HIGH:
        GPIO_IS(gpioport) |= gpios;
        GPIO_IEV(gpioport) |= gpios;
        break;
    case GPIO_TRIG_EDGE_FALL:
        GPIO_IS(gpioport) &= ~gpios;
        GPIO_IBE(gpioport) &= ~gpios;
        GPIO_IEV(gpioport) &= ~gpios;
        break;
    case GPIO_TRIG_EDGE_RISE:
        GPIO_IS(gpioport) &= ~gpios;
        GPIO_IBE(gpioport) &= ~gpios;
        GPIO_IEV(gpioport) |= gpios;
        break;
    case GPIO_TRIG_EDGE_BOTH:
        GPIO_IS(gpioport) &= ~gpios;
        GPIO_IBE(gpioport) |= gpios;
        break;
    default:
        /* Don't do anything */
        break;
    }
}

/** @brief Enable interrupts on specified GPIO pins
 *
 * Enable interrupts on the specified GPIO pins
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Pins whose interrupts to enable. Any
 *            combination of pins may be specified by OR'ing them together.
 */
void gpio_enable_interrupts(uint32_t gpioport, uint8_t gpios)
{
    GPIO_IM(gpioport) |= gpios;
}

/** @brief Disable interrupts on specified GPIO pins
 *
 * Disable interrupts on the specified GPIO pins
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Pins whose interrupts to disable. Any
 *            combination of pins may be specified by OR'ing them together.
 */
void gpio_disable_interrupts(uint32_t gpioport, uint8_t gpios)
{
    GPIO_IM(gpioport) &= ~gpios;
}

