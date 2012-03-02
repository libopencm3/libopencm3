/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef __ADXL345_H
#define __ADXL345_H

/* Register addresses */
#define ADXL345_DEVID		0x00
#define ADXL345_POWER_CTL	0x2D
#define ADXL345_DATA_FORMAT	0x31
#define ADXL345_DATAX0		0x32
#define ADXL345_DATAX1		0x33
#define ADXL345_DATAY0		0x34
#define ADXL345_DATAY1		0x35
#define ADXL345_DATAZ0		0x36
#define ADXL345_DATAZ1		0x37

#define ADXL345_POWER_CTL_MEASURE	(1 << 3)
#define ADXL345_DATA_FORMAT_LALIGN	(1 << 2)

#endif

