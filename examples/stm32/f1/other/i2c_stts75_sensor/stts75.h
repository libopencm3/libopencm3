/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#ifndef STTS75_H
#define STTS75_H

#include <stdint.h>

#define STTS75_SENSOR0		0x48
#define STTS75_SENSOR1		0x49
#define STTS75_SENSOR2		0x4a
#define STTS75_SENSOR3		0x4b
#define STTS75_SENSOR4		0x4c
#define STTS75_SENSOR5		0x4d
#define STTS75_SENSOR6		0x4e
#define STTS75_SENSOR7		0x4f

void stts75_write_config(u32 i2c, u8 sensor);
void stts75_write_temp_os(u32 i2c, u8 sensor, u16 temp_os);
void stts75_write_temp_hyst(u32 i2c, u8 sensor, u16 temp_hyst);
u16 stts75_read_temperature(u32 i2c, u8 sensor);

#endif
