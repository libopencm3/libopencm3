/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_SPI_F4_H
#define LIBOPENCM3_SPI_F4_H

#include <libopencm3/stm32/spi.h>

/*
 * This file extends the common STM32 version with definitions only
 * applicable to the STM32F4 series of devices.
 */

/* --- SPI_CR2 values ------------------------------------------------------ */

/* FRF: Frame format */
/* Note: Not used in I2S mode. */
#define SPI_CR2_FRF			(1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE	(0 << 4)
#define SPI_CR2_FRF_TI_MODE		(1 << 4)

/* --- SPI_SR values ------------------------------------------------------- */

/* TIFRFE: TI frame format error */
#define SPI_SR_TIFRFE			(1 << 8)

#endif
