/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_NVIC_H
#define LIBOPENSTM32_NVIC_H

#include <libopenstm32/memorymap.h>
#include <libopenstm32/common.h>

/* --- NVIC Registers ------------------------------------------------------ */

/* ISER: Interrupt Set Enable Registers */
/* Note: 8 32bit Registers */
#define NVIC_ISER(iser_id)              MMIO32(NVIC_BASE + 0x00 + (iser_id * 4))

/* NVIC_BASE + 0x020 (0xE000 E120 - 0xE000 E17F): Reserved */

/* ICER: Interrupt Clear Enable Registers */
/* Note: 8 32bit Registers */
#define NVIC_ICER(icer_id)              MMIO32(NVIC_BASE + 0x80 + (icer_id * 4))

/* NVIC_BASE + 0x0A0 (0xE000 E1A0 - 0xE000 E1FF): Reserved */

/* ISPR: Interrupt Set Priority Registers */
/* Note: 8 32bit Registers */
#define NVIC_ISPR(ispr_id)              MMIO32(NVIC_BASE + 0x100 + (ispr_id * 4))

/* NVIC_BASE + 0x120 (0xE000 E220 - 0xE000 E27F): Reserved */

/* ICPR: Interrupt Clear Priority Registers */
/* Note: 8 32bit Registers */
#define NVIC_ICPR(icpr_id)              MMIO32(NVIC_BASE + 0x180 + (icpr_id * 4))

/* NVIC_BASE + 0x1A0 (0xE000 E2A0 - 0xE00 E2FF): Reserved */

/* IABR: Interrupt Active Bit Register */
/* Note: 8 32bit Registers */
#define NVIC_IABR(iabr_id)              MMIO32(NVIC_BASE + 0x200 + (iabr_id * 4))

/* NVIC_BASE + 0x220 (0xE000 E320 - 0xE000 E3FF): Reserved */

/* IPR: Interrupt Priority Registers */
/* Note: 240 8bit Registers */
#define NVIC_IPR(ipr_id)                MMIO8(NVIC_BASE + 0x300 + ipr_id)

/* STIR: Software Trigger Interrupt Register */
#define NVIC_STIR                       MMIO32(STIR_BASE)

/* --- SCB: Registers ------------------------------------------------------ */

/* CPUID: CPUID base register */
#define SCB_CPUID                       MMIO32(SCB_BASE + 0x00)

/* ICSR: Interrupt Control State Register */
#define SCB_ICSR                        MMIO32(SCB_BASE + 0x04)

/* VTOR: Vector Table Offset Register */
#define SCB_VTOR                        MMIO32(SCB_BASE + 0x08)

/* AIRCR: Application Interrupt and Reset Control Register */
#define SCB_AIRCR                       MMIO32(SCB_BASE + 0x0C)

/* SCR: System Control Register */
#define SCB_SCR                         MMIO32(SCB_BASE + 0x10)

/* CCR: Configuration Control Register */
#define SCB_CCR                         MMIO32(SCB_BASE + 0x14)

/* SHP: System Handler Priority Registers */
/* Note: 12 8bit registers */
#define SCB_SHPR(shpr_id)               MMIO8(SCB_BASE + 0x18 + shpr_id)

/* SHCSR: System Handler Control and State Register */
#define SCB_SHCSR                       MMIO32(SCB_BASE + 0x24)

/* CFSR: Configurable Fault Status Registers */
#define SCB_CFSR                        MMIO32(SCB_BASE + 0x28)

/* HFSR: Hard Fault Status Register */
#define SCB_HFSR                        MMIO32(SCB_BASE + 0x2C)

/* DFSR: Debug Fault Status Register */
#define SCB_DFSR                        MMIO32(SCB_BASE + 0x30)

/* MMFAR: Memory Manage Fault Address Register */
#define SCB_MMFAR                       MMIO32(SCB_BASE + 0x34)

/* BFAR: Bus Fault Address Register */
#define SCB_BFAR                        MMIO32(SCB_BASE + 0x38)

/* AFSR: Auxiliary Fault Status Register */
#define SCB_AFSR                        MMIO32(SCB_BASE + 0x3C)

/* --- NVIC functions ------------------------------------------------------ */

void nvic_enable_irq(s32 irqn);
void nvic_disable_irq(s32 irqn);
s32 nvic_get_pending_irq(s32 irqn);
void nvic_set_pending_irq(s32 irqn);
void nvic_clear_pending_irq(s32 irqn);
s32 nvic_get_active(s32 irqn);

#endif
