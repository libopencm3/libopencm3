/*
 * This file is part of the libopencm3 project.
 *
 * PY32 family generic memory map dispatch.
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#ifndef LIBOPENCM3_PY32_MEMORYMAP_H
#define LIBOPENCM3_PY32_MEMORYMAP_H

#if defined(PY32F0)
#  include <libopencm3/py32/f0/memorymap.h>
#else
#  error "py32 family not defined"
#endif

#endif
