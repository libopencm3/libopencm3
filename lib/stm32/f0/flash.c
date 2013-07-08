/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

void flash_prefetch_buffer_enable(void)
{
	FLASH_ACR |= FLASH_ACR_PRFTBE;
}

void flash_prefetch_buffer_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTBE;
}

void flash_set_ws(uint32_t ws)
{
	FLASH_ACR = (FLASH_ACR & ~FLASH_ACR_LATENCY) | ws;
}

void flash_wait_busy(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) != 0);
}

void flash_program_u32(uint32_t address, uint32_t data)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = (uint16_t)data;

	flash_wait_busy();

	MMIO16(address + 2) = data >> 16;

	flash_wait_busy();

	FLASH_CR &= ~FLASH_CR_PG;
}

void flash_program_u16(uint32_t address, uint16_t data)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_busy();

	FLASH_CR &= ~FLASH_CR_PG;
}

void flash_erase_page(uint32_t page_address)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_PER;
	FLASH_AR = page_address;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_busy();
	FLASH_CR &= ~FLASH_CR_PER;
}

void flash_erase_all_pages(void)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_MER;		/* Enable mass erase. */
	FLASH_CR |= FLASH_CR_STRT;		/* Trigger the erase. */

	flash_wait_busy();
	FLASH_CR &= ~FLASH_CR_MER;		/* Disable mass erase. */
}
