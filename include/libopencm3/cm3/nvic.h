/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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
/** @defgroup CM3_nvic_defines NVIC Defines
 *
 * @brief <b>libopencm3 Cortex Nested Vectored Interrupt Controller</b>
 *
 * @ingroup CM3_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Piotr Esden-Tempski <piotr@esden.net>
 *
 * @date 18 August 2012
 *
 * LGPL License Terms @ref lgpl_license
 */
/**@{*/

#ifndef LIBOPENCM3_NVIC_H
#define LIBOPENCM3_NVIC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>

/* --- NVIC Registers ------------------------------------------------------ */

/* ISER: Interrupt Set Enable Registers */
/* Note: 8 32bit Registers */
/* Note: Single register on CM0 */
#define NVIC_ISER(iser_id)		MMIO32(NVIC_BASE + 0x00 + \
						(iser_id * 4))

/* NVIC_BASE + 0x020 (0xE000 E120 - 0xE000 E17F): Reserved */

/* ICER: Interrupt Clear Enable Registers */
/* Note: 8 32bit Registers */
/* Note: Single register on CM0 */
#define NVIC_ICER(icer_id)		MMIO32(NVIC_BASE + 0x80 + \
						(icer_id * 4))

/* NVIC_BASE + 0x0A0 (0xE000 E1A0 - 0xE000 E1FF): Reserved */

/* ISPR: Interrupt Set Pending Registers */
/* Note: 8 32bit Registers */
/* Note: Single register on CM0 */
#define NVIC_ISPR(ispr_id)		MMIO32(NVIC_BASE + 0x100 + \
						(ispr_id * 4))

/* NVIC_BASE + 0x120 (0xE000 E220 - 0xE000 E27F): Reserved */

/* ICPR: Interrupt Clear Pending Registers */
/* Note: 8 32bit Registers */
/* Note: Single register on CM0 */
#define NVIC_ICPR(icpr_id)		MMIO32(NVIC_BASE + 0x180 + \
						(icpr_id * 4))

/* NVIC_BASE + 0x1A0 (0xE000 E2A0 - 0xE00 E2FF): Reserved */

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* IABR: Interrupt Active Bit Register */
/* Note: 8 32bit Registers */
#define NVIC_IABR(iabr_id)		MMIO32(NVIC_BASE + 0x200 + \
						(iabr_id * 4))
#endif

/* NVIC_BASE + 0x220 (0xE000 E320 - 0xE000 E3FF): Reserved */

/* IPR: Interrupt Priority Registers */
/* Note: 240 8bit Registers */
/* Note: 32 8bit Registers on CM0 */
#define NVIC_IPR(ipr_id)		MMIO8(NVIC_BASE + 0x300 + \
						ipr_id)

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* STIR: Software Trigger Interrupt Register */
#define NVIC_STIR			MMIO32(STIR_BASE)
#endif

/* --- IRQ channel numbers-------------------------------------------------- */

/* Cortex M0, M3 and M4 System Interrupts */
/** @defgroup nvic_sysint Cortex M0/M3/M4 System Interrupts
@ingroup CM3_nvic_defines

IRQ numbers -3 and -6 to -9 are reserved
@{*/
#define NVIC_NMI_IRQ			-14
#define NVIC_HARD_FAULT_IRQ		-13

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define NVIC_MEM_MANAGE_IRQ		-12
#define NVIC_BUS_FAULT_IRQ		-11
#define NVIC_USAGE_FAULT_IRQ		-10
#endif

/* irq numbers -6 to -9 are reserved */
#define NVIC_SV_CALL_IRQ		-5

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define DEBUG_MONITOR_IRQ		-4
#endif

/* irq number -3 reserved */
#define NVIC_PENDSV_IRQ			-2
#define NVIC_SYSTICK_IRQ		-1
/**@}*/

/* Note: User interrupts are family specific and are defined in a family
 * specific header file in the corresponding subfolder.
 */

#define WEAK __attribute__((weak))

#include <libopencm3/dispatch/nvic.h>

/* --- NVIC functions ------------------------------------------------------ */

BEGIN_DECLS

void nvic_enable_irq(uint8_t irqn);
void nvic_disable_irq(uint8_t irqn);
uint8_t nvic_get_pending_irq(uint8_t irqn);
void nvic_set_pending_irq(uint8_t irqn);
void nvic_clear_pending_irq(uint8_t irqn);
uint8_t nvic_get_irq_enabled(uint8_t irqn);
void nvic_set_priority(uint8_t irqn, uint8_t priority);

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
uint8_t nvic_get_active_irq(uint8_t irqn);
void nvic_generate_software_interrupt(uint16_t irqn);
#endif

void WEAK reset_handler(void);
void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK sv_call_handler(void);
void WEAK pend_sv_handler(void);
void WEAK sys_tick_handler(void);

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK debug_monitor_handler(void);
#endif

END_DECLS

/**@}*/

#endif
