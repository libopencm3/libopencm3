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

#include <libopencm3/stm32/flash.h>

static inline void flash_set_program_size(u32 psize)
{
	FLASH_CR &= ~(((1 << 0) | (1 << 1)) << 8);
	FLASH_CR |= psize;
}

void flash_dcache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_DCE;
}

void flash_dcache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_DCE;
}

void flash_icache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ICE;
}

void flash_icache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ICE;
}

void flash_prefetch_enable(void)
{
	FLASH_ACR |= FLASH_ACR_PRFTEN;
}

void flash_prefetch_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTEN;
}

void flash_dcache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_DCRST;
}

void flash_icache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ICRST;
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
	/* Clear the unlock sequence state. */
	FLASH_CR |= FLASH_CR_LOCK;

	/* Authorize the FPEC access. */
	FLASH_KEYR = FLASH_KEYR_KEY1;
	FLASH_KEYR = FLASH_KEYR_KEY2;
}

void flash_lock(void)
{
	FLASH_CR |= FLASH_CR_LOCK;
}

void flash_clear_pgserr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGSERR;
}

void flash_clear_pgperr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGPERR;
}

void flash_clear_pgaerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGAERR;
}

void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_SR_EOP;
}

void flash_clear_wrperr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPERR;
}

void flash_clear_bsy_flag(void)
{
	FLASH_SR &= ~FLASH_SR_BSY;
}

void flash_clear_status_flags(void)
{
	flash_clear_pgserr_flag();
	flash_clear_pgperr_flag();
	flash_clear_pgaerr_flag();
	flash_clear_eop_flag();
	flash_clear_wrperr_flag();
	flash_clear_bsy_flag();
}

void flash_unlock_option_bytes(void)
{
	/* Clear the unlock state. */
	FLASH_OPTCR |= FLASH_OPTCR_OPTLOCK;

	/* Unlock option bytes. */
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY1;
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY2;
}

void flash_lock_option_bytes(void)
{
	FLASH_OPTCR |= FLASH_OPTCR_OPTLOCK;
}

void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) == FLASH_SR_BSY)
		;
}

void flash_program_double_word(u32 address, u64 data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X64);

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the first half of the word. */
	MMIO64(address) = data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Disable writes to flash. */
	FLASH_CR &= ~FLASH_CR_PG;
}

void flash_program_word(u32 address, u32 data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X32);

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the first half of the word. */
	MMIO32(address) = data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Disable writes to flash. */
	FLASH_CR &= ~FLASH_CR_PG;
}

void flash_program_half_word(u32 address, u16 data)
{
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X16);

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;		/* Disable the PG bit. */
}

void flash_program_byte(u32 address, u8 data)
{
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X8);

	FLASH_CR |= FLASH_CR_PG;

	MMIO8(address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;		/* Disable the PG bit. */
}

void flash_program(u32 address, u8* data, u32 len)
{
  /* TODO: Use dword and word size program operations where possible for turbo
   * speed. */
  u32 i;
  for (i=0; i<len; i++)
    flash_program_byte(address+i, data[i]);
}

void flash_erase_sector(u8 sector, u32 program_size)
{
	flash_wait_for_last_operation();
	flash_set_program_size(program_size);

	FLASH_CR &= ~(0xF << 3);
	FLASH_CR |= (sector << 3) & 0x78;
	FLASH_CR |= FLASH_CR_SER;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_SER;
	FLASH_CR &= ~(0xF << 3);
}

void flash_erase_all_sectors(u32 program_size)
{
	flash_wait_for_last_operation();
	flash_set_program_size(program_size);

	FLASH_CR |= FLASH_CR_MER;		/* Enable mass erase. */
	FLASH_CR |= FLASH_CR_STRT;		/* Trigger the erase. */

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_MER;		/* Disable mass erase. */
}

void flash_program_option_bytes(u32 data)
{
	flash_wait_for_last_operation();

	if (FLASH_OPTCR & FLASH_OPTCR_OPTLOCK)
		flash_unlock_option_bytes();

	FLASH_OPTCR = data & ~0x3;
	FLASH_OPTCR |= FLASH_OPTCR_OPTSTRT;	/* Enable option byte programming. */
	flash_wait_for_last_operation();
}
