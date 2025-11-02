/** @defgroup quadspi_defines QuadSPI Defines
 * @brief Defined constants and types for the STM32H7 QuadSPI peripheral
 * @ingroup STM32H7xx_defines
 * @copyright SPDX: LGPL-3.0-or-later
 * @{
 */

#ifndef LIBOPENCM3_QUADSPI_H
#define LIBOPENCM3_QUADSPI_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/common/quadspi_common_v1.h>

/**@{*/
/** @defgroup quadspi_reg_base QuadSPI register base addresses
 * Holds all the QuadSPI peripherals supported.
 * @{
 */
#define QUADSPI1        QUADSPI1_BASE
#define QUADSPI2        QUADSPI2_BASE
/**@}*/

BEGIN_DECLS

END_DECLS

/** Enable free running clock mode, for testing */
#define QUADSPI_CCR_FRCM    (1 << 29)

/**@}*/

#endif
