/*
 * This file is part of the libopencm3 project.
 *
 * Copyright 2020 Lubomir Rintel <lkundrak@v3.sk>
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
/** @defgroup CM3_nvic_defines GD32V ECLIC Defines
 *
 * @brief <b>libopencm3 Enhanced Core Local Interrupt Controller</b>
 *
 * @ingroup GD32V_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2020 Lubomir Rintel <lkundrak@v3.sk>
 *
 * @date 3 July 2020
 *
 * LGPL License Terms @ref lgpl_license
 *
 * @see https://doc.nucleisys.com/nuclei_spec/isa/eclic.html
 */
/**@{*/

#ifndef LIBOPENCM3_ECLIC_H
#define LIBOPENCM3_ECLIC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/** @defgroup eclic_registers ECLIC Registers
 * @{
 */

/** CLICCFG: Global Configuration Register */
#define ECLIC_CFG		MMIO32(ECLIC_BASE + 0x0000)

/** CLICINFO: Global Info Register */
#define ECLIC_INFO		MMIO32(ECLIC_BASE + 0x0004)

/** MTH: Target Interrupt Threshold Level Register */
#define ECLIC_MTH		MMIO32(ECLIC_BASE + 0x000b)

/** CLICINTIP: Interrupt Pending Flag Registers */
#define ECLIC_INTIP(irq)	MMIO8(ECLIC_BASE + 0x1000 + 4 * (irq))

/** CLICINTIE: Interrupt Enable Registers */
#define ECLIC_INTIE(irq)	MMIO8(ECLIC_BASE + 0x1001 + 4 * (irq))

/** CLICINTATTR: Interrupt Source Attribute Registers */
#define ECLIC_INTATTR(irq)	MMIO8(ECLIC_BASE + 0x1002 + 4 * (irq))

/** CLICINTCTL: Interrupt Level an Priority Control Registers */
#define ECLIC_INTCFG(irq)	MMIO8(ECLIC_BASE + 0x1003 + 4 * (irq))

/**@}*/

/** @defgroup eclic_sysint GD32V System Interrupts
@ingroup CM3_nvic_defines

@{*/

#define ECLIC_SV_CALL_IRQ		-16
#define ECLIC_SYSTICK_IRQ		-12
#define ECLIC_BUS_FAULT_IRQ		-2
#define ECLIC_PERFORMANCE_MONITOR_IRQ	-1

/**@}*/

#include <libopencm3/dispatch/nvic.h>

BEGIN_DECLS

void eclic_init(uint32_t num_irqs);

void eclic_enable_irq(uint32_t irq);
void eclic_disable_irq(uint32_t irq);

void bus_fault_handler(void);
void performance_monitor_handler(void);
void sv_call_handler(void);
void sys_tick_handler(void);

END_DECLS

/**@}*/

#endif
