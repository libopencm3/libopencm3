/** @defgroup quadspi_defines QuadSPI Defines
 * @brief Defined constants and types for the STM32H7 QuadSPI peripheral
 * @ingroup STM32H7xx_defines
 * @copyright SPDX: LGPL-3.0-or-later
 * @{
 */

#pragma once

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/common/quadspi_common_v1.h>

/** Enable free running clock mode, for testing */
#define QUADSPI_CCR_FRCM    (1 << 29)

/**@}*/