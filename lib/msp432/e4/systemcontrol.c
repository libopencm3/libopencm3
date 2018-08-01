/** @defgroup systemcontrol_file System Control
 *
 * @ingroup MSP432E4xx
 *
 * @brief libopencm3 MSP432E4xx System Control
 *
 * @version 1.0.0
 *
 * @date 22 July 2018
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#include <libopencm3/msp432/e4/systemcontrol.h>
#include <stdbool.h>

#define _SYSCTL_REG(base, i)     MMIO32((base) + ((i) >> 5))
#define _SYSCTL_BIT(i)           (1 << ((i) & 0x1f))

/*----------------------------------------------------------------------------*/
/** @brief System Control Enable Peripheral Clock
 *
 * @param[in] clock_mode ::msp432_clock_mode Clock mode
 * @param[in] periph ::msp432_periph Peripheral block
 */
void sysctl_periph_clock_enable(enum msp432_clock_mode clock_mode,
                                enum msp432_periph periph)
{
    _SYSCTL_REG(SYSCTL_BASE + clock_mode, periph) |= _SYSCTL_BIT(periph);
}

/*----------------------------------------------------------------------------*/
/** @brief System Control Disable Peripheral Clock
 *
 * @param[in] clock_mode ::msp432_clock_mode Clock mode
 * @param[in] periph ::msp432_periph Peripheral block
 */
void sysctl_periph_clock_disable(enum msp432_clock_mode clock_mode,
                                 enum msp432_periph periph)
{
    _SYSCTL_REG(SYSCTL_BASE + clock_mode, periph) &= ~_SYSCTL_BIT(periph);
}

/*----------------------------------------------------------------------------*/
/** @brief System Control Peripheral Software Reset
 *
 * @param[in] periph ::msp432_periph Peripheral block
 */
void sysctl_periph_reset(enum msp432_periph periph)
{
    _SYSCTL_REG((uint32_t)&SYSCTL_SRWD, periph) |= _SYSCTL_BIT(periph);
}

/*----------------------------------------------------------------------------*/
/** @brief System Control Peripheral Clear Software Reset
 *
 * @param[in] periph ::msp432_periph Peripheral block
 */
void sysctl_periph_clear_reset(enum msp432_periph periph)
{
    _SYSCTL_REG((uint32_t)&SYSCTL_SRWD, periph) &= ~_SYSCTL_BIT(periph);
}

/*----------------------------------------------------------------------------*/
/** @brief System Control Peripheral Is Present
 *
 * @param[in] periph ::msp432_periph Peripheral block
 */
bool sysctl_periph_is_present(enum msp432_periph periph)
{
    uint32_t reg32 = _SYSCTL_REG((uint32_t)&SYSCTL_PPWD, periph);
    uint32_t mask = _SYSCTL_BIT(periph);

    return ((reg32 & mask) != 0);
}

/*----------------------------------------------------------------------------*/
/** @brief System Control Peripheral Is Ready
 *
 * @param[in] periph ::msp432_periph Peripheral block
 */
bool sysctl_periph_is_ready(enum msp432_periph periph)
{
    uint32_t reg32 = _SYSCTL_REG((uint32_t)&SYSCTL_PRWD, periph);
    uint32_t mask = _SYSCTL_BIT(periph);

    return ((reg32 & mask) != 0);
}

/*----------------------------------------------------------------------------*/
/** @brief System Control Peripheral Set Power State
 *
 * @param[in] power_mode ::msp432_power_mode Power mode
 * @param[in] periph ::msp432_periph Peripheral block
 *
 * @note If the module is in run, sleep or deep-sleep mode - the module
 * is powered and receives a clock regardless of the value of power mode.
 */
void sysctl_periph_set_power_state(enum msp432_power_mode power_mode,
                                   enum msp432_periph periph)
{
    if(power_mode == POWER_ENABLE) {
        _SYSCTL_REG((uint32_t)&SYSCTL_PCWD, periph) |= _SYSCTL_BIT(periph);
    } else {
        _SYSCTL_REG((uint32_t)&SYSCTL_PCWD, periph) &= ~_SYSCTL_BIT(periph);
    }
}

#undef _SYSCTL_REG
#undef _SYSCTL_BIT
