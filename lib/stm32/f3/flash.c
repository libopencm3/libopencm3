/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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

#include <libopencm3/stm32/f3/flash.h>

/* This function is probably wrong, since deactivated. Please check and fix!
static inline void flash_set_program_size(uint32_t psize)
{
	FLASH_CR &= ~(((1 << 0) | (1 << 1)) << 8);
	FLASH_CR |= psize;
}
*/

void flash_set_ws(uint32_t ws)
{
	uint32_t reg32;

	reg32 = FLASH_ACR;
	reg32 &= ~((1 << 0) | (1 << 1) | (1 << 2));
	reg32 |= ws;
	FLASH_ACR = reg32;
}

void flash_unlock(void)
{
	/* Authorize the FPEC access. */
	FLASH_KEYR = FLASH_KEY1;
	FLASH_KEYR = FLASH_KEY2;
}

void flash_lock(void)
{
	FLASH_CR |= FLASH_LOCK;
}

void flash_clear_pgperr_flag(void)
{
	FLASH_SR |= FLASH_PGPERR;
}

void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_EOP;
}

void flash_clear_bsy_flag(void)
{
	FLASH_SR &= ~FLASH_BSY;
}

void flash_clear_status_flags(void)
{
	flash_clear_pgperr_flag();
	flash_clear_eop_flag();
	flash_clear_bsy_flag();
}


void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_BSY) == FLASH_BSY)
		;
}

/*  Functions deactivated because flash_set_program_size function may not be */
/* working well */
/* void flash_program_double_word(uint32_t address, u64 data, uint32_t program_size) */
/* { */
/* 	/\* Ensure that all flash operations are complete. *\/ */
/* 	flash_wait_for_last_operation(); */
/* 	flash_set_program_size(program_size); */

/* 	/\* Enable writes to flash. *\/ */
/* 	FLASH_CR |= FLASH_PG; */

/* 	/\* Program the first half of the word. *\/ */
/* 	MMIO64(address) = data; */

/* 	/\* Wait for the write to complete. *\/ */
/* 	flash_wait_for_last_operation(); */

/* 	/\* Disable writes to flash. *\/ */
/* 	FLASH_CR &= ~FLASH_PG; */
/* } */

/* void flash_program_word(uint32_t address, uint32_t data, uint32_t program_size) */
/* { */
/* 	/\* Ensure that all flash operations are complete. *\/ */
/* 	flash_wait_for_last_operation(); */
/* 	flash_set_program_size(program_size); */

/* 	/\* Enable writes to flash. *\/ */
/* 	FLASH_CR |= FLASH_PG; */

/* 	/\* Program the first half of the word. *\/ */
/* 	MMIO32(address) = data; */

/* 	/\* Wait for the write to complete. *\/ */
/* 	flash_wait_for_last_operation(); */

/* 	/\* Disable writes to flash. *\/ */
/* 	FLASH_CR &= ~FLASH_PG; */
/* } */

/* void flash_program_half_word(uint32_t address, u16 data, uint32_t program_size) */
/* { */
/* 	flash_wait_for_last_operation(); */
/* 	flash_set_program_size(program_size); */

/* 	FLASH_CR |= FLASH_PG; */

/* 	MMIO16(address) = data; */

/* 	flash_wait_for_last_operation(); */

/* 	FLASH_CR &= ~FLASH_PG;		/\* Disable the PG bit. *\/ */
/* } */

/* void flash_program_byte(uint32_t address, u8 data, uint32_t program_size) */
/* { */
/* 	flash_wait_for_last_operation(); */
/* 	flash_set_program_size(program_size); */

/* 	FLASH_CR |= FLASH_PG; */

/* 	MMIO8(address) = data; */

/* 	flash_wait_for_last_operation(); */

/* 	FLASH_CR &= ~FLASH_PG;		/\* Disable the PG bit. *\/ */
/* } */

/* void flash_erase_page(uint32_t page, uint32_t program_size) */
/* { */
/* 	flash_wait_for_last_operation(); */
/* 	flash_set_program_size(program_size); */

/* 	FLASH_CR &= ~(((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3)) << 3); */
/* 	FLASH_CR |= page; */
/* 	FLASH_CR |= FLASH_PER; */
/* 	FLASH_CR |= FLASH_STRT; */

/* 	flash_wait_for_last_operation(); */
/* 	FLASH_CR &= ~FLASH_PER; */
/* 	FLASH_CR &= ~(((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3)) << 3); */
/* } */

/* void flash_erase_all_pages(uint32_t program_size) */
/* { */
/* 	flash_wait_for_last_operation(); */
/* 	flash_set_program_size(program_size); */

/* 	FLASH_CR |= FLASH_MER;		/\* Enable mass erase. *\/ */
/* 	FLASH_CR |= FLASH_STRT;		/\* Trigger the erase. *\/ */

/* 	flash_wait_for_last_operation(); */
/* 	FLASH_CR &= ~FLASH_MER;		/\* Disable mass erase. *\/ */
/* } */



