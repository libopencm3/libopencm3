/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

/* Linker script for HackRF Jellybean (LPC4330, 1M SPI flash, 264K SRAM). */

/* Define memory regions. */
MEMORY
{
  /* rom is really the shadow region that points to SPI flash or elsewhere */
  rom (rx)  : ORIGIN = 0x00000000, LENGTH =  1M
  ram (rwx) : ORIGIN = 0x10000000, LENGTH =  128K
  /* there are some additional RAM regions */
}

/* Include the common ld script. */
INCLUDE libopencm3_lpc43xx.ld
