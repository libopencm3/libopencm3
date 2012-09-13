/** @defgroup STM32F_nvic_file NVIC

@ingroup STM32F_files

@brief <b>libopencm3 STM32F Nested Vectored Interrupt Controller</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
@author @htmlonly &copy; @endhtmlonly 2012 Fergus Noble <fergusnoble@gmail.com>

@date 18 August 2012

The STM32F series provides up to 68 maskable user interrupts for the STM32F10x
series, and 87 for the STM32F2xx and STM32F4xx series.

The NVIC registers are defined by the ARM standards but the STM32F series have some
additional limitations
@see Cortex-M3 Devices Generic User Guide
@see STM32F10xxx Cortex-M3 programming manual

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Fergus Noble <fergusnoble@gmail.com>
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

/**@{*/

#include <libopencm3/stm32/nvic.h>

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Enable Interrupt

Enables a user interrupt.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
*/

void nvic_enable_irq(u8 irqn)
{
	NVIC_ISER(irqn / 32) = (1 << (irqn % 32));
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Disable Interrupt

Disables a user interrupt.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
*/

void nvic_disable_irq(u8 irqn)
{
	NVIC_ICER(irqn / 32) = (1 << (irqn % 32));
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Return Pending Interrupt

True if the interrupt has occurred and is waiting for service.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
@return Boolean. Interrupt pending.
*/

u8 nvic_get_pending_irq(u8 irqn)
{
	return NVIC_ISPR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Set Pending Interrupt

Force a user interrupt to a pending state. This has no effect if the interrupt
is already pending.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
*/

void nvic_set_pending_irq(u8 irqn)
{
	NVIC_ISPR(irqn / 32) = (1 << (irqn % 32));
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Clear Pending Interrupt

Force remove a user interrupt from a pending state. This has no effect if the
interrupt is actively being serviced.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
*/

void nvic_clear_pending_irq(u8 irqn)
{
	NVIC_ICPR(irqn / 32) = (1 << (irqn % 32));
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Return Active Interrupt

Interrupt has occurred and is currently being serviced.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
@return Boolean. Interrupt active.
*/

u8 nvic_get_active_irq(u8 irqn)
{
	return NVIC_IABR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Return Enabled Interrupt

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
@return Boolean. Interrupt enabled.
*/

u8 nvic_get_irq_enabled(u8 irqn)
{
	return NVIC_ISER(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Set Interrupt Priority

There are 16 priority levels only, given by the upper four bits of the priority
byte, as required by ARM standards. The priority levels are interpreted according
to the pre-emptive priority grouping set in the SCB Application Interrupt and Reset
Control Register (SCB_AIRCR), as done in @ref scb_set_priority_grouping.

@param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
@param[in] priority Unsigned int8. Interrupt priority (0 ... 255 in steps of 16)
*/

void nvic_set_priority(u8 irqn, u8 priority)
{
	NVIC_IPR(irqn) = priority;
}

/*-----------------------------------------------------------------------------*/
/** @brief NVIC Software Trigger Interrupt

Generate an interrupt from software. This has no effect for unprivileged access
unless the privilege level has been elevated through the System Control Registers.

@param[in] irqn Unsigned int16. Interrupt number (0 ... 239)
*/

void nvic_generate_software_interrupt(u16 irqn)
{
	if (irqn <= 239)
		NVIC_STIR |= irqn;
}
/**@}*/

