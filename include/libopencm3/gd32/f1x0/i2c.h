/** @defgroup i2c_defines I2C Defines
 *
 * @brief <b>Defined Constants and Types for the GD32F1x0 I2C</b>
 *
 * @ingroup GD32F1x0_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * GD32F1x0 I2C uses the *STM32F1-style v1 layout* (CTL0/CTL1 + CKCFG +
 * RT registers; not the v2 TIMINGR-based layout used by stm32/f0). See
 * decisions/v0.2/I2C.md. Forward to stm32/f1/i2c.h. No header guard on
 * this side — the forwarded file has its own.
 */
#include <libopencm3/stm32/f1/i2c.h>
