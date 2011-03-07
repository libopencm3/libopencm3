/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LIBOPENCM3_CM3_SCS_H
#define LIBOPENCM3_CM3_SCS_H

#define SCS_DHCSR		MMIO32(SCS_BASE + 0xDF0)
#define SCS_DCRSR		MMIO32(SCS_BASE + 0xDF4)
#define SCS_DCRDR		MMIO32(SCS_BASE + 0xDF8)
#define SCS_DEMCR		MMIO32(SCS_BASE + 0xDFC)

/* Debug Halting Control and Status Register (DHCSR) */
#define SCS_DHCSR_DBGKEY	0xA05F0000
#define SCS_DHCSR_C_DEBUGEN	0x00000001
#define SCS_DHCSR_C_HALT	0x00000002
#define SCS_DHCSR_C_STEP	0x00000004
#define SCS_DHCSR_C_MASKINTS	0x00000008
#define SCS_DHCSR_C_SNAPSTALL	0x00000020
#define SCS_DHCSR_S_REGRDY	0x00010000
#define SCS_DHCSR_S_HALT	0x00020000
#define SCS_DHCSR_S_SLEEP	0x00040000
#define SCS_DHCSR_S_LOCKUP	0x00080000
#define SCS_DHCSR_S_RETIRE_ST	0x01000000
#define SCS_DHCSR_S_RESET_ST	0x02000000

/* Debug Core Register Selector Register (DCRSR) */
#define SCS_DCRSR_REGSEL_MASK	0x0000001F
#define SCS_DCRSR_REGSEL_XPSR	0x00000010
#define SCS_DCRSR_REGSEL_MSP	0x00000011
#define SCS_DCRSR_REGSEL_PSP	0x00000012

/* Debug Exception and Monitor Control Register (DEMCR) */
/* Bits 31:25 - Reserved */
#define SCS_DEMCR_TRCENA	(1 << 24)
/* Bits 23:20 - Reserved */
#define SCS_DEMCR_MON_REQ	(1 << 19)
#define SCS_DEMCR_MON_STEP	(1 << 18)
#define SCS_DEMCR_VC_MON_PEND	(1 << 17)
#define SCS_DEMCR_VC_MON_EN	(1 << 16)
/* Bits 15:11 - Reserved */
#define SCS_DEMCR_VC_HARDERR	(1 << 10)
#define SCS_DEMCR_VC_INTERR	(1 << 9)
#define SCS_DEMCR_VC_BUSERR	(1 << 8)
#define SCS_DEMCR_VC_STATERR	(1 << 7)
#define SCS_DEMCR_VC_CHKERR	(1 << 6)
#define SCS_DEMCR_VC_NOCPERR	(1 << 5)
#define SCS_DEMCR_VC_MMERR	(1 << 4)
/* Bits 3:1 - Reserved */
#define SCS_DEMCR_VC_CORERESET	(1 << 0)

#endif
