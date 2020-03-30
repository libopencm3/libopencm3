/**
 * @brief <b>PAC55xxxx Memory Controller Driver</b>
 * @author @htmlonly &copy; @endhtmlonly 2020 Kevin Stefanik <kevin@allocor.tech>
 * @date April 1, 2020
 *
 * This library supports the Memory Controller in the PAC55xx SoC from Qorvo.
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
#include <libopencm3/pac55xx/memctl.h>

void memctl_flash_set_wstate(uint32_t wstate) {
	MEMCTL_MEMCTLR = (MEMCTL_MEMCTLR & ~MEMCTL_MEMCTLR_WSTATE(MEMCTL_MEMCTLR_WSTATE_MASK)) | MEMCTL_MEMCTLR_WSTATE(wstate);
}
void memctl_flash_set_mclkdiv(uint32_t div) {
	MEMCTL_MEMCTLR = (MEMCTL_MEMCTLR & ~MEMCTL_MEMCTLR_MCLKDIV(16)) | MEMCTL_MEMCTLR_MCLKDIV(div);
}
void memctl_flash_reset_write_buffer(void) {
	MEMCTL_MEMCTLR = (MEMCTL_MEMCTLR & ~MEMCTL_MEMCTLR_WRITEWORDCNT(MEMCTL_MEMCTLR_WRITEWORDCNT_MASK));
}
void memctl_flash_standby_mode_enable(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_STBY;
}
void memctl_flash_standby_mode_disable(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_STBY;
}
void memctl_flash_cache_enable(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_CACHEDIS;
}
void memctl_flash_cache_disable(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_CACHEDIS;
}
void memctl_flash_select_roscclk(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_MCLKSEL;
}
void memctl_flash_select_mclk(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_MCLKSEL;
}
void memctl_sram_ecc_enable(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_ECCDIS;
}
void memctl_sram_ecc_disable(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_ECCDIS;
}
void memctl_sram_ecc_single_bit_interrupt_enable(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_SEIE;
}
void memctl_sram_ecc_single_bit_interrupt_disable(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_SEIE;
}
void memctl_sram_ecc_dual_bit_interrupt_enable(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_DEIE;
}
void memctl_sram_ecc_dual_bit_interrupt_disable(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_DEIE;
}
void memctl_invaddr_interrupt_enable(void) {
	MEMCTL_MEMCTLR |= MEMCTL_MEMCTLR_INVADDRIE;
}
void memctl_invaddr_interrupt_disable(void) {
	MEMCTL_MEMCTLR &= ~MEMCTL_MEMCTLR_INVADDRIE;
}
