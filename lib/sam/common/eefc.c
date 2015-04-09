/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Owen Kirby <osk@exegin.com>
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
#include <libopencmsis/core_cm3.h>
#include <libopencm3/sam/eefc.h>

/*
 * Flash read operations MUST execute from RAM, since the banks of flash will
 * be remapped while the operation is in progress. TODO: We should update the
 * linker script to have a dedicated section for this thing.
 */
void __attribute__((section(".data.ramfunc")))
eefc_do_read(uint32_t port, uint32_t start, uint32_t stop, void *dst, uint32_t len)
{
    uint32_t fsr;
    /* ISRs will cause a fault due to remapping of the vector table. */
    CM_ATOMIC_CONTEXT();
    
    /* Start the read command and wait for the flash controller to become ready. */
    EEFC_FCR(port) = EEFC_FCR_FKEY | start;
	do {
	    fsr = EEFC_FSR(port);
	} while (fsr & EEFC_FSR_FRDY);
	
	/* Copy memory from the remapped flash, we have to do it manually because
	 * the libc functions are all going to exist in the remapped flash.
	 *
	 * TODO: The source address should be retrieved from the linker script, and
	 * may also depend on the bank and GPNVM bits for dual-banked chips.
     */
	if (((intptr_t)dst & 3) == 0) {
        uint32_t *p = dst;
        uint32_t *end = (uint32_t *)((uint8_t *)p + len);
        const uint32_t *src = (uint32_t *)0x400000;
	    while (p < end) *p++ = *src++;
	}
	/* Unaligned version. */
	else {
	    uint8_t *p = dst;
        uint8_t *end = (uint8_t *)p + len;
        const uint32_t *src = (uint32_t *)0x400000;
	    while (p < end) *p++ = *src++;
	}
	
	/* Stop the read command, and wait for the flash controller to become ready. */
	EEFC_FCR(port) = EEFC_FCR_FKEY | stop;
	do {
	    fsr = EEFC_FSR(port);
	} while ((fsr & EEFC_FSR_FRDY) == 0);
} /* eefc_do_read */

/* Reads the 128-bit flash unique ID. */
void
eefc_read_uniqueid(uint32_t port, void *uid)
{
    eefc_do_read(port, EEFC_FCR_FCMD_STUI, EEFC_FCR_FCMD_SPUI, uid, EEFC_UNIQUEID_SIZE);
} /* eefc_read_uniqueid */

