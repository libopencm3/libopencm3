/* This provides unification of code over SAM subfamilies */

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

#if defined(SAM3A)
#       include <libopencm3/sam/common/periph_common_3a3x.h>
#elif defined(SAM3N)
#       include <libopencm3/sam/3n/periph.h>
#elif defined(SAM3S)
#       include <libopencm3/sam/3s/periph.h>
#elif defined(SAM3U)
#       include <libopencm3/sam/3u/periph.h>
#elif defined(SAM3X)
#       include <libopencm3/sam/common/periph_common_3a3x.h>
#else
#       error "sam family not defined."
#endif
