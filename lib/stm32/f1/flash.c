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

#include <libopencm3/stm32/f1/flash.h>

void flash_prefetch_buffer_enable(void)
{
	FLASH_ACR |= FLASH_PRFTBE;
}

void flash_prefetch_buffer_disable(void)
{
	FLASH_ACR &= ~FLASH_PRFTBE;
}

void flash_halfcycle_enable(void)
{
	FLASH_ACR |= FLASH_HLFCYA;
}

void flash_halfcycle_disable(void)
{
	FLASH_ACR &= ~FLASH_HLFCYA;
}

void flash_set_ws(u32 ws)
{
	u32 reg32;

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

void flash_clear_pgerr_flag(void)
{
	FLASH_SR |= FLASH_PGERR;
}

void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_EOP;
}

void flash_clear_wrprterr_flag(void)
{
	FLASH_SR |= FLASH_WRPRTERR;
}

void flash_clear_bsy_flag(void)
{
	FLASH_SR &= ~FLASH_BSY;
}

void flash_clear_status_flags(void)
{
	flash_clear_pgerr_flag();
	flash_clear_eop_flag();
	flash_clear_wrprterr_flag();
	flash_clear_bsy_flag();
}

void flash_unlock_option_bytes(void)
{
	FLASH_OPTKEYR = FLASH_KEY1;
	FLASH_OPTKEYR = FLASH_KEY2;
}

void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_BSY) == FLASH_BSY)
		;
}

void flash_program_word(u32 address, u32 data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_PG;

	/* Program the first half of the word. */
	(*(volatile u16 *)address) = (u16)data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Program the second half of the word. */
	(*(volatile u16 *)(address + 2)) = data >> 16;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Disable writes to flash. */
	FLASH_CR &= ~FLASH_PG;
}

void flash_program_half_word(u32 address, u16 data)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_PG;

	(*(volatile u16 *)address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_PG;		/* Disable the PG bit. */
}

void flash_erase_page(u32 page_address)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_PER;
	FLASH_AR = page_address;
	FLASH_CR |= FLASH_STRT;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_PER;
}

void flash_erase_all_pages(void)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_MER;		/* Enable mass erase. */
	FLASH_CR |= FLASH_STRT;		/* Trigger the erase. */

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_MER;		/* Disable mass erase. */
}

void flash_erase_option_bytes(void)
{
	flash_wait_for_last_operation();

	if ((FLASH_CR & FLASH_OPTWRE) == 0)
		flash_unlock_option_bytes();

	FLASH_CR |= FLASH_OPTER;	/* Enable option byte erase. */
	FLASH_CR |= FLASH_STRT;
	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_OPTER;	/* Disable option byte erase. */
}

void flash_program_option_bytes(u32 address, u16 data)
{
	flash_wait_for_last_operation();

	if ((FLASH_CR & FLASH_OPTWRE) == 0)
		flash_unlock_option_bytes();

	FLASH_CR |= FLASH_OPTPG;	/* Enable option byte programming. */
	(*(volatile u16 *)address) = data;
	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_OPTPG;	/* Disable option byte programming. */
}
