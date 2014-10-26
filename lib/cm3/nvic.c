/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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
/** @defgroup CM3_nvic_file NVIC
 *
 * @ingroup CM3_files
 *
 * @brief <b>libopencm3 Cortex Nested Vectored Interrupt Controller</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2012 Fergus Noble
 * <fergusnoble@gmail.com>
 *
 * @date 18 August 2012
 *
 * Cortex processors provide 14 cortex-defined interrupts (NMI, usage faults,
 * systicks etc.) and varying numbers of implementation defined interrupts
 * (typically peripherial interrupts and DMA).
 *
 * @see Cortex-M3 Devices Generic User Guide
 * @see STM32F10xxx Cortex-M3 programming manual
 *
 * LGPL License Terms @ref lgpl_license
*/
/**@{*/

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scs.h>

/*---------------------------------------------------------------------------*/
/** @brief NVIC Enable Interrupt
 *
 * Enables a user interrupt.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 */

void nvic_enable_irq(uint8_t irqn)
{
	NVIC_ISER(irqn / 32) = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Disable Interrupt
 *
 * Disables a user interrupt.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 */

void nvic_disable_irq(uint8_t irqn)
{
	NVIC_ICER(irqn / 32) = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Return Pending Interrupt
 *
 * True if the interrupt has occurred and is waiting for service.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 * @return Boolean. Interrupt pending.
 */

uint8_t nvic_get_pending_irq(uint8_t irqn)
{
	return NVIC_ISPR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Set Pending Interrupt
 *
 * Force a user interrupt to a pending state. This has no effect if the
 * interrupt is already pending.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 */

void nvic_set_pending_irq(uint8_t irqn)
{
	NVIC_ISPR(irqn / 32) = (1 << (irqn % 32));
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Clear Pending Interrupt
 *
 * Force remove a user interrupt from a pending state. This has no effect if
 * the interrupt is actively being serviced.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 */

void nvic_clear_pending_irq(uint8_t irqn)
{
	NVIC_ICPR(irqn / 32) = (1 << (irqn % 32));
}



/*---------------------------------------------------------------------------*/
/** @brief NVIC Return Enabled Interrupt
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 * @return Boolean. Interrupt enabled.
 */

uint8_t nvic_get_irq_enabled(uint8_t irqn)
{
	return NVIC_ISER(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Set Interrupt Priority
 *
 * CM3, CM4:
 *
 * There are 16 priority levels only, given by the upper four bits of the
 * priority byte, as required by ARM standards. The priority levels are
 * interpreted according to the pre-emptive priority grouping set in the
 * SCB Application Interrupt and Reset Control Register (SCB_AIRCR), as done
 * in @ref scb_set_priority_grouping.
 *
 * CM0:
 *
 * There are 4 priority levels only, given by the upper two bits of the
 * priority byte, as required by ARM standards. No grouping available.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 * @param[in] priority Unsigned int8. Interrupt priority (0 ... 255 in steps of
 * 16)
 */

void nvic_set_priority(uint8_t irqn, uint8_t priority)
{
	/* code from lpc43xx/nvic.c -- this is quite a hack and alludes to the
	 * negative interrupt numbers assigned to the system interrupts. better
	 * handling would mean signed integers. */
	if (irqn >= NVIC_IRQ_COUNT) {
		/* Cortex-M  system interrupts */
		SCS_SHPR((irqn & 0xF) - 4) = priority;
	} else {
		/* Device specific interrupts */
		NVIC_IPR(irqn) = priority;
	}
}

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/*---------------------------------------------------------------------------*/
/** @brief NVIC Return Active Interrupt
 *
 * Interrupt has occurred and is currently being serviced.
 *
 * @param[in] irqn Unsigned int8. Interrupt number @ref nvic_stm32f1_userint
 * @return Boolean. Interrupt active.
 */

uint8_t nvic_get_active_irq(uint8_t irqn)
{
	return NVIC_IABR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief NVIC Software Trigger Interrupt
 *
 * Generate an interrupt from software. This has no effect for unprivileged
 * access unless the privilege level has been elevated through the System
 * Control Registers.
 *
 * @param[in] irqn Unsigned int16. Interrupt number (0 ... 239)
 */

void nvic_generate_software_interrupt(uint16_t irqn)
{
	if (irqn <= 239) {
		NVIC_STIR |= irqn;
	}
}
#endif
/**@}*/
