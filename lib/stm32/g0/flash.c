/** @defgroup flash_file FLASH peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32G0xx FLASH</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

/**@{*/

#include <libopencm3/stm32/flash.h>

/** @brief Wait until Last Flash Operation has Ended */
void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) == FLASH_SR_BSY);
}

/** @brief Program a 64bits word to FLASH
 *
 * Program a 64bit word to FLASH memory.
 * Flash programing error must be checked and cleared if needed
 * before starting programming.
 *
 * @param[in] address Address in FLASH
 * @param[in] data Double word to write
 */
void flash_program_double_word(uint32_t address, uint64_t data)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_PG;

	MMIO32(address) = (uint32_t)data;
	MMIO32(address+4) = (uint32_t)(data >> 32);

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;
}

/** @brief Program a Data Block to FLASH
 *
 * This programs an arbitrary length data block to FLASH memory.
 * The program error flag should be checked separately for the event that memory
 * was not properly erased.
 *
 * @param[in] address Starting address in Flash.
 * @param[in] data Pointer to start of data block.
 * @param[in] len Length of data block in bytes (multiple of 8).
 **/
void flash_program(uint32_t address, uint8_t *data, uint32_t len)
{
	for (uint32_t i = 0; i < len; i += 8) {
		flash_program_double_word(address+i, *(uint64_t*)(data + i));
	}
}

/** @brief Erase a page of FLASH
 * @param[in] page
 */
void flash_erase_page(uint32_t page)
{
	flash_wait_for_last_operation();

	uint32_t reg = FLASH_CR;
	reg &= ~(FLASH_CR_PNB_MASK << FLASH_CR_PNB_SHIFT);
	reg |= (page & FLASH_CR_PNB_MASK)  << FLASH_CR_PNB_SHIFT;
	reg |= FLASH_CR_PER;
	reg |= FLASH_CR_STRT;

	FLASH_CR = reg;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PER;
}

/** @brief Erase All FLASH
 * This performs all operations necessary to erase all sectors in the FLASH
 * memory.
 */
void flash_erase_all_pages(void)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_MER;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_MER;
}

/** @brief Clear the Programming Sequence Error Flag */
void flash_clear_pgserr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGSERR;
}

/** @brief Clear the End of Operation Flag */
void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_SR_EOP;
}

/** @brief Clear programming size error flag */
void flash_clear_size_flag(void)
{
	FLASH_SR |= FLASH_SR_SIZERR;
}

/** @brief Clear the Programming Alignment Error Flag
 */
void flash_clear_pgaerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGAERR;
}

/** @brief Clear the Write Protected Error Flag
 */
void flash_clear_wrperr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPERR;
}

/** @brief Clear the Programming Error Status Flag
 */
void flash_clear_progerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PROGERR;
}

/** @brief Clear the Operation Error Status Flag
 */
void flash_clear_operr_flag(void)
{
	FLASH_SR |= FLASH_SR_OPERR;
}

/** @brief Clear All Status Flags */
void flash_clear_status_flags(void)
{
	flash_clear_pgserr_flag();
	flash_clear_size_flag();
	flash_clear_pgaerr_flag();
	flash_clear_wrperr_flag();
	flash_clear_progerr_flag();
	flash_clear_eop_flag();
	flash_clear_operr_flag();
}

void flash_icache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ICEN;
}

void flash_icache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ICEN;
}

void flash_icache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ICRST;
}

void flash_unlock_progmem(void)
{
	FLASH_KEYR = FLASH_KEYR_KEY1;
	FLASH_KEYR = FLASH_KEYR_KEY2;
}

void flash_lock_progmem(void)
{
	FLASH_CR |= FLASH_CR_LOCK;
}

void flash_lock_option_bytes(void)
{
	FLASH_CR |= FLASH_CR_OPTLOCK;
}

void flash_unlock(void)
{
	flash_unlock_progmem();
	flash_unlock_option_bytes();
}

void flash_lock(void)
{
	flash_lock_option_bytes();
	flash_lock_progmem();
}

/**@}*/
