/** @defgroup nvic_defines Nested Vectored Interrupt Controller

@brief <b>Defined Constants and Types for the LM4F Nested Vectored Interrupt
Controller</b>

@ingroup LM4Fxx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012
Alexandru Gagniuc <mr.nuke.me@gmail.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#ifndef LIBOPENCM3_LM4F_NVIC_H
#define LIBOPENCM3_LM4F_NVIC_H

/**@{*/

#include <libopencm3/cm3/nvic.h>

/** @ingroup nvic_defines
 * The LM3S interrupt table applies to the LM4F as well.  Some interrupt
 * vectors marked as reserved in LM3S are used in LM4F, and some vectors in
 * LM3S are marked reserved for LM4F. However, the common vectors are
 * identical, and we can safely use the same interrupt table. Reserved vectors
 * will never be triggered, so having them is perfectly safe.
 */
#include <libopencm3/lm3s/nvic.h>

/**@}*/

#endif /* LIBOPENCM3_LM4F_NVIC_H */
