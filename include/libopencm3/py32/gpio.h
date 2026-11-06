/*
 * This file is part of the libopencm3 project.
 *
 * PY32 family GPIO dispatch header.
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#ifndef LIBOPENCM3_PY32_GPIO_H
#define LIBOPENCM3_PY32_GPIO_H

#if defined(PY32F0)
#  include <libopencm3/py32/f0/gpio.h>
#else
#  error "py32 family not defined"
#endif

#endif
