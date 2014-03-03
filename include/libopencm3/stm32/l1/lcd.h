/** @defgroup lcd_defines LCD Defines
 *
 * @ingroup STM32L1xx_defines
 *
 * @brief Defined Constants and Types for the STM32L1xx LCD Controller
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Nikolay Merinov <nikolay.merinov@member.fsf.org>
 *
 * @date 2 March 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */

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

/**@{*/
#ifndef LIBOPENCM3_LCD_H
#define LIBOPENCM3_LCD_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- LCD registers ------------------------------------------------------ */
/****************************************************************************/
/** @defgroup lcd_reg_base LCD register base addresses
@ingroup lcd_defines
*/
/* @{ */
/* Control register */
#define LCD_CR			MMIO32(LCD_BASE + 0x00)
/* Frame control register */
#define LCD_FCR			MMIO32(LCD_BASE + 0x04)
/* Status register */
#define LCD_SR			MMIO32(LCD_BASE + 0x08)
/* Clear register */
#define LCD_CLR			MMIO32(LCD_BASE + 0x0C)
/* @} */

/* --- LCD display memory ------------------------------------------------- */
/* Base address of display memory */
#define LCD_RAM_BASE		(LCD_BASE + 0x14)

/* COM0 memory */
#define LCD_RAM_COM0		MMIO64(LCD_RAM_BASE + 0x00)
/* COM1 memory */
#define LCD_RAM_COM1		MMIO64(LCD_RAM_BASE + 0x08)
/* COM2 memory */
#define LCD_RAM_COM2		MMIO64(LCD_RAM_BASE + 0x10)
/* COM3 memory */
#define LCD_RAM_COM3		MMIO64(LCD_RAM_BASE + 0x18)
/* COM4 memory */
#define LCD_RAM_COM4		MMIO64(LCD_RAM_BASE + 0x20)
/* COM5 memory */
#define LCD_RAM_COM5		MMIO64(LCD_RAM_BASE + 0x28)
/* COM6 memory */
#define LCD_RAM_COM6		MMIO64(LCD_RAM_BASE + 0x30)
/* COM7 memory */
#define LCD_RAM_COM7		MMIO64(LCD_RAM_BASE + 0x38)

/* --- LCD_CR values ------------------------------------------------------ */
#define LCD_CR_LCDEN		(1 << 0)
#define LCD_CR_VSEL		(1 << 1)

#define LCD_CR_DUTY_SHIFT	2
#define LCD_CR_DUTY_MASK	0x7
#define LCD_CR_DUTY_STATIC	0x0
#define LCD_CR_DUTY_1_2		0x1
#define LCD_CR_DUTY_1_3		0x2
#define LCD_CR_DUTY_1_4		0x3
#define LCD_CR_DUTY_1_8		0x4

#define LCD_CR_BIAS_SHIFT	5
#define LCD_CR_BIAS_MASK	0x3
#define LCD_CR_BIAS_1_4		0x0
#define LCD_CR_BIAS_1_2		0x1
#define LCD_CR_BIAS_1_3		0x2

#define LCD_CR_MUX_SEG		(1 << 7)

/* --- LCD_FCR values ------------------------------------------------------ */
#define LCD_FCR_HD		(1 << 0)
#define LCD_FCR_SOFIE		(1 << 1)
#define LCD_FCR_UDDIE		(1 << 3)

#define LCD_FCR_PON_SHIFT	4
#define LCD_FCR_PON_MASK	0x7
#define LCD_FCR_PON_0		0x0
#define LCD_FCR_PON_1		0x1
#define LCD_FCR_PON_2		0x2
#define LCD_FCR_PON_3		0x3
#define LCD_FCR_PON_4		0x4
#define LCD_FCR_PON_5		0x5
#define LCD_FCR_PON_6		0x6
#define LCD_FCR_PON_7		0x7

#define LCD_FCR_DEAD_SHIFT	7
#define LCD_FCR_DEAD_MASK	0x7
#define LCD_FCR_DEAD_NONE	0x0
#define LCD_FCR_DEAD_1_PHASE	0x1
#define LCD_FCR_DEAD_2_PHASE	0x2
#define LCD_FCR_DEAD_3_PHASE	0x3
#define LCD_FCR_DEAD_4_PHASE	0x4
#define LCD_FCR_DEAD_5_PHASE	0x5
#define LCD_FCR_DEAD_6_PHASE	0x6
#define LCD_FCR_DEAD_7_PHASE	0x7

#define LCD_FCR_CC_SHIFT	10
#define LCD_FCR_CC_MASK		0x7
#define LCD_FCR_CC_0		0x0
#define LCD_FCR_CC_1		0x1
#define LCD_FCR_CC_2		0x2
#define LCD_FCR_CC_3		0x3
#define LCD_FCR_CC_4		0x4
#define LCD_FCR_CC_5		0x5
#define LCD_FCR_CC_6		0x6
#define LCD_FCR_CC_7		0x7

#define LCD_FCR_BLINKF_SHIFT	13
#define LCD_FCR_BLINKF_MASK	0x7
#define LCD_FCR_BLINKF_8	0x0
#define LCD_FCR_BLINKF_16	0x1
#define LCD_FCR_BLINKF_32	0x2
#define LCD_FCR_BLINKF_64	0x3
#define LCD_FCR_BLINKF_128	0x4
#define LCD_FCR_BLINKF_256	0x5
#define LCD_FCR_BLINKF_512	0x6
#define LCD_FCR_BLINKF_1024	0x7

#define LCD_FCR_BLINK_SHIFT		16
#define LCD_FCR_BLINK_MASK		0x3
#define LCD_FCR_BLINK_DISABLE		0x0
#define LCD_FCR_BLINK_SEG0_COM0_ENABLE	0x1
#define LCD_FCR_BLINK_SEG0_ENABLE	0x2
#define LCD_FCR_BLINK_ALL_ENABLE	0x3

#define LCD_FCR_DIV_SHIFT	18
#define LCD_FCR_DIV_MASK	0xF
#define LCD_FCR_DIV_16		0x0
#define LCD_FCR_DIV_17		0x1
#define LCD_FCR_DIV_18		0x2
#define LCD_FCR_DIV_19		0x3
#define LCD_FCR_DIV_20		0x4
#define LCD_FCR_DIV_21		0x5
#define LCD_FCR_DIV_22		0x6
#define LCD_FCR_DIV_23		0x7
#define LCD_FCR_DIV_24		0x8
#define LCD_FCR_DIV_25		0x9
#define LCD_FCR_DIV_26		0xA
#define LCD_FCR_DIV_27		0xB
#define LCD_FCR_DIV_28		0xC
#define LCD_FCR_DIV_29		0xD
#define LCD_FCR_DIV_30		0xE
#define LCD_FCR_DIV_31		0xF

#define LCD_FCR_PS_SHIFT	22
#define LCD_FCR_PS_MASK		0xF
#define LCD_FCR_PS_1		0x0
#define LCD_FCR_PS_2		0x1
#define LCD_FCR_PS_4		0x2
#define LCD_FCR_PS_8		0x3
#define LCD_FCR_PS_16		0x4
#define LCD_FCR_PS_32		0x5
#define LCD_FCR_PS_64		0x6
#define LCD_FCR_PS_128		0x7
#define LCD_FCR_PS_256		0x8
#define LCD_FCR_PS_512		0x9
#define LCD_FCR_PS_1024		0xA
#define LCD_FCR_PS_2048		0xB
#define LCD_FCR_PS_4096		0xC
#define LCD_FCR_PS_8192		0xD
#define LCD_FCR_PS_16384	0xE
#define LCD_FCR_PS_32768	0xF

/* --- LCD_SR values ------------------------------------------------------ */
#define LCD_SR_ENS		(1 << 0)
#define LCD_SR_SOF		(1 << 1)
#define LCD_SR_UDR		(1 << 2)
#define LCD_SR_UDD		(1 << 3)
#define LCD_SR_RDY		(1 << 4)
#define LCD_SR_FCRSF		(1 << 5)

/* --- LCD_CLR values ----------------------------------------------------- */
#define LCD_CLR_SOFC		(1 << 1)
#define LCD_CLR_UDDC		(1 << 3)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void lcd_enable(void);
void lcd_update(void);

void lcd_wait_for_lcd_enabled(void);
void lcd_wait_for_step_up_ready(void);
void lcd_wait_for_update_ready(void);

int lcd_is_enabled(void);
int lcd_is_step_up_ready(void);
int lcd_is_for_update_ready(void);

void lcd_set_contrast(uint8_t contrast);
void lcd_set_bias(uint8_t bias);
void lcd_set_duty(uint8_t duty);
void lcd_set_prescaler(uint8_t ps);
void lcd_set_divider(uint8_t div);
void lcd_enable_segment_multiplexing(void);
void lcd_disable_segment_multiplexing(void);
void lcd_set_refresh_frequency(uint32_t frequency);

END_DECLS

#endif
/**@}*/
