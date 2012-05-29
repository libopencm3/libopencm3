/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_SSP_H
#define LPC43XX_SSP_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* SSP port base addresses (for convenience) */
#define SSP0                            SSP0_BASE
#define SSP1                            SSP1_BASE


/* --- SSP registers ------------------------------------------------------- */

/* Control Register 0 */
#define SSP_CR0(port)                   MMIO32(port + 0x000)
#define SSP0_CR0                        SSP_CR0(SSP0)
#define SSP1_CR0                        SSP_CR0(SSP1)

/* Control Register 1 */
#define SSP_CR1(port)                   MMIO32(port + 0x004)
#define SSP0_CR1                        SSP_CR1(SSP0)
#define SSP1_CR1                        SSP_CR1(SSP1)

/* Data Register */
#define SSP_DR(port)                    MMIO32(port + 0x008)
#define SSP0_DR                         SSP_DR(SSP0)
#define SSP1_DR                         SSP_DR(SSP1)

/* Status Register */
#define SSP_SR(port)                    MMIO32(port + 0x00C)
#define SSP0_SR                         SSP_SR(SSP0)
#define SSP1_SR                         SSP_SR(SSP1)

/* Clock Prescale Register */
#define SSP_CPSR(port)                  MMIO32(port + 0x010)
#define SSP0_CPSR                       SSP_CPSR(SSP0)
#define SSP1_CPSR                       SSP_CPSR(SSP1)

/* Interrupt Mask Set and Clear Register */
#define SSP_IMSC(port)                  MMIO32(port + 0x014)
#define SSP0_IMSC                       SSP_IMSC(SSP0)
#define SSP1_IMSC                       SSP_IMSC(SSP1)

/* Raw Interrupt Status Register */
#define SSP_RIS(port)                   MMIO32(port + 0x018)
#define SSP0_RIS                        SSP_RIS(SSP0)
#define SSP1_RIS                        SSP_RIS(SSP1)

/* Masked Interrupt Status Register */
#define SSP_MIS(port)                   MMIO32(port + 0x01C)
#define SSP0_MIS                        SSP_MIS(SSP0)
#define SSP1_MIS                        SSP_MIS(SSP1)

/* SSPICR Interrupt Clear Register */
#define SSP_ICR(port)                   MMIO32(port + 0x020)
#define SSP0_ICR                        SSP_ICR(SSP0)
#define SSP1_ICR                        SSP_ICR(SSP1)

/* SSP1 DMA control register */
#define SSP_DMACR(port)                 MMIO32(port + 0x024)
#define SSP0_DMACR                      SSP_DMACR(SSP0)
#define SSP1_DMACR                      SSP_DMACR(SSP1)

#endif
