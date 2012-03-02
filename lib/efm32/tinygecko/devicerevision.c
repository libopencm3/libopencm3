/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/tinygecko/devicerevision.h>

u8 devicerevision_revision_get(void)
{
	/* probably this is more elegant, more readable and closer to the spec,
	 * and i'll just get used to doing things like that:
	return (DEVICEREVISION_PID2 & 0xf0) | ((DEVICEREVISION_PID3 & 0xf0) >> 4);
	*/
	return ((DEVICEREVISION_PID2 & DEVICEREVISION_REVISION_MASK) >> DEVICEREVISION_REVISION_SHIFT << DEVICEREVISION_REVISION_LENGTH) | ((DEVICEREVISION_PID3 & DEVICEREVISION_REVISION_MASK) >> DEVICEREVISION_REVISION_SHIFT);
}
