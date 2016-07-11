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

#ifndef LIBOPENCM3_SAM4L_ADCIFE_H
#define LIBOPENCM3_SAM4L_ADCIFE_H

#include <libopencm3/sam/memorymap.h>


/* Analog to Digital Converter Interface (ADCIFE) registers. */

/* 0x0000 Control Register CR Write-Only 0x00000000 */
#define ADCIFE_CR			MMIO32(ADCIFE_BASE + 0x0000)

/* 0x0004 Configuration Register CFG Read/Write 0x00000000 */
#define ADCIFE_CFG			MMIO32(ADCIFE_BASE + 0x0004)

/* 0x0008 Status Register SR Read-Only 0x00000000 */
#define ADCIFE_SR			MMIO32(ADCIFE_BASE + 0x008)

/* 0x000C Status Clear Register SCR Write-Only 0x00000000 */
#define ADCIFE_SCR			MMIO32(ADCIFE_BASE + 0x000C)

/* 0x0014 Sequencer Configuration Register SEQCFG Read/Write 0x00000000 */
#define ADCIFE_SEQCFG			MMIO32(ADCIFE_BASE + 0x0014)

/* 0x0018 Configuration Direct Memory Access Register CDMA Write-Only 0x00000000 */
#define ADCIFE_CDMA			MMIO32(ADCIFE_BASE + 0x0018)

/* 0x001C Timing Configuration Register TIM Read/Write 0x00000000 */
#define ADCIFE_TIM			MMIO32(ADCIFE_BASE + 0x001C)

/* 0x0020 Internal Timer Register ITIMER Read/Write 0x00000000 */
#define ADCIFE_ITIMER			MMIO32(ADCIFE_BASE + 0x0020)

/* 0x0024 Window Monitor Configuration Register WCFG Read/Write 0x00000000 */
#define ADCIFE_WCFG			MMIO32(ADCIFE_BASE + 0x0024)

/* 0x0028 Window Monitor Threshold Configuration Register WTH Read/Write 0x00000000 */
#define ADCIFE_WTH			MMIO32(ADCIFE_BASE + 0x0028)

/* 0x002C Sequencer Last Converted Value Register LCV Read-Only 0x00000000 */
#define ADCIFE_LCV			MMIO32(ADCIFE_BASE + 0x002C)

/* 0x0030 Interrupt Enable Register IER Write-Only 0x00000000 */
#define ADCIFE_IER			MMIO32(ADCIFE_BASE + 0x0030)

/* 0x0034 Interrupt Disable Register IDR Write-Only 0x00000000 */
#define ADCIFE_IDR			MMIO32(ADCIFE_BASE + 0x0034)

/* 0x0038 Interrupt Mask Register IMR Read-Only 0x00000000 */
#define ADCIFE_IMR			MMIO32(ADCIFE_BASE + 0x0038)

/* 0x003C Calibration Register CALIB Read/Write 0x00000000 */
#define ADCIFE_CALIB			MMIO32(ADCIFE_BASE + 0x003C)

/* 0x0040 Version Register VERSION Read-Only - */
#define ADCIFE_VERSION			MMIO32(ADCIFE_BASE + 0x0040)

/* 0x0044 Parameter Register PARAMETER Read-Only - */
#define ADCIFE_PARAMETER			MMIO32(ADCIFE_BASE + 0x0044)


/* --------- Register Contents --------------------------- */
#define ADCIFE_CR_SWRST			(1 << 0)
#define ADCIFE_CR_TSTOP			(1 << 1)
#define ADCIFE_CR_TSTART			(1 << 2)
#define ADCIFE_CR_STRIG			(1 << 3)
#define ADCIFE_CR_REFBUFEN			(1 << 4)
#define ADCIFE_CR_REFBUFDIS			(1 << 5)
#define ADCIFE_CR_EN			(1 << 8)
#define ADCIFE_CR_DIS			(1 << 9)
#define ADCIFE_CR_BGREQEN			(1 << 10)
#define ADCIFE_CR_BGREQDIS			(1 << 11)

#define _MASKED_VALUE(V, S, M)			(((V) << (S)) & (M))

#define ADCIFE_CFG_REFSEL_SHIFT			(1)
#define ADCIFE_CFG_REFSEL_MASK			(7 << ADCIFE_CFG_REFSEL_SHIFT)
#define ADCIFE_CFG_REFSEL_MASKED(V)			_MASKED_VALUE((V), ADCIFE_CFG_REFSEL_SHIFT, ADCIFE_CFG_REFSEL_MASK)
#define ADCIFE_CFG_SPEED_SHIFT			(4)
#define ADCIFE_CFG_SPEED_MASK			(3 << ADCIFE_CFG_SPEED_SHIFT)
#define ADCIFE_CFG_SPEED_MASKED(V)			_MASKED_VALUE((V), ADCIFE_CFG_SPEED_SHIFT, ADCIFE_CFG_SPEED_MASK)
#define ADCIFE_CFG_CLKSEL			(1 << 6)
#define ADCIFE_CFG_PRESCAL_SHIFT			(8)
#define ADCIFE_CFG_PRESCAL_MASK			(3 << ADCIFE_CFG_PRESCAL_SHIFT)
#define ADCIFE_CFG_PRESCAL_MASKED(V)			_MASKED_VALUE((V), ADCIFE_CFG_PRESCAL_SHIFT, ADCIFE_CFG_PRESCAL_MASK)

#define ADCIFE_SR_SEOC			(1 << 0)
#define ADCIFE_SR_LOVR			(1 << 1)
#define ADCIFE_SR_WM			(1 << 2)
#define ADCIFE_SR_SMTRG			(1 << 3)
#define ADCIFE_SR_TTO			(1 << 5)
#define ADCIFE_SR_EN			(1 << 24)
#define ADCIFE_SR_TBUSY			(1 << 25)
#define ADCIFE_SR_SBUSY			(1 << 26)
#define ADCIFE_SR_CBUSY			(1 << 27)
#define ADCIFE_SR_REFBUF			(1 << 28)
#define ADCIFE_SR_BGREQ			(1 << 30)

#define ADCIFE_IR_SEOC			(1 << 0)
#define ADCIFE_IR_LOVR			(1 << 1)
#define ADCIFE_IR_WM			(1 << 2)
#define ADCIFE_IR_SMTRG			(1 << 3)
#define ADCIFE_IR_TTO			(1 << 5)

#define ADCIFE_SEQCFG_HWLA			(1 << 0)
#define ADCIFE_SEQCFG_BIPOLAR			(1 << 2)
#define ADCIFE_SEQCFG_GAIN_SHIFT		(4)
#define ADCIFE_SEQCFG_GAIN_MASK			(7 << ADCIFE_SEQCFG_GAIN_SHIFT)
#define ADCIFE_SEQCFG_GAIN_MASKED(V)	_MASKED_VALUE((V), ADCIFE_SEQCFG_GAIN_SHIFT, ADCIFE_SEQCFG_GAIN_MASK)
#define ADCIFE_SEQCFG_GCOMP			(1 << 7)
#define ADCIFE_SEQCFG_TRGSEL_SHIFT		(8)
#define ADCIFE_SEQCFG_TRGSEL_MASK		(7 << ADCIFE_SEQCFG_TRGSEL_SHIFT)
#define ADCIFE_SEQCFG_TRGSEL_MASKED(V)	_MASKED_VALUE((V), ADCIFE_SEQCFG_TRGSEL_SHIFT, ADCIFE_SEQCFG_TRGSEL_MASK)
#define ADCIFE_SEQCFG_RES			(1 << 12)
#define ADCIFE_SEQCFG_INTERNAL_SHIFT	(14)
#define ADCIFE_SEQCFG_INTERNAL_MASK		(3 << ADCIFE_SEQCFG_INTERNAL_SHIFT)
#define ADCIFE_SEQCFG_INTERNAL_MASKED(V)	_MASKED_VALUE((V), ADCIFE_SEQCFG_INTERNAL_SHIFT, ADCIFE_SEQCFG_INTERNAL_MASK)
#define ADCIFE_SEQCFG_MUXPOS_SHIFT		(16)
#define ADCIFE_SEQCFG_MUXPOS_MASK		(0xf << ADCIFE_SEQCFG_MUXPOS_SHIFT)
#define ADCIFE_SEQCFG_MUXPOS_MASKED(V)	_MASKED_VALUE((V), ADCIFE_SEQCFG_MUXPOS_SHIFT, ADCIFE_SEQCFG_MUXPOS_MASK)
#define ADCIFE_SEQCFG_MUXNEG_SHIFT		(20)
#define ADCIFE_SEQCFG_MUXNEG_MASK		(7 << ADCIFE_SEQCFG_MUXNEG_SHIFT)
#define ADCIFE_SEQCFG_MUXNEG_MASKED(V)	_MASKED_VALUE((V), ADCIFE_SEQCFG_MUXNEG_SHIFT, ADCIFE_SEQCFG_MUXNEG_MASK)
#define ADCIFE_SEQCFG_ZOOMRANGE_SHIFT		(28)
#define ADCIFE_SEQCFG_ZOOMRANGE_MASK		(7 << ADCIFE_SEQCFG_ZOOMRANGE_SHIFT)
#define ADCIFE_SEQCFG_ZOOMRANGE_MASKED(V)	_MASKED_VALUE((V), ADCIFE_SEQCFG_ZOOMRANGE_SHIFT, ADCIFE_SEQCFG_ZOOMRANGE_MASK)

/* If x is of type enum adcife_prescal, the prescale value is 2^(x + 2) */
enum adcife_prescal {
	ADCIFE_PRESCAL_DIV4,
	ADCIFE_PRESCAL_DIV8,
	ADCIFE_PRESCAL_DIV16,
	ADCIFE_PRESCAL_DIV32,
	ADCIFE_PRESCAL_DIV64,
	ADCIFE_PRESCAL_DIV128,
	ADCIFE_PRESCAL_DIV256,
	ADCIFE_PRESCAL_DIV512,
};

enum adcife_speed {
	ADCIFE_SPEED_300KSPS,
	ADCIFE_SPEED_225KSPS,
	ADCIFE_SPEED_150KSPS,
	ADCIFE_SPEED_75KSPS,
};

enum adcife_refsel {
	ADCIFE_REFSEL_INTERNAL1V,
	ADCIFE_REFSEL_0_625xVCC,
	ADCIFE_REFSEL_EXTERNAL1,
	ADCIFE_REFSEL_EXTERNAL2,
	ADCIFE_REFSEL_HALF_VCC,
};

enum adcife_clk {
	ADCIFE_CLK_GENERIC,
	ADCIFE_CLK_APB = ADCIFE_CFG_CLKSEL,
};

enum adcife_channel {
	ADCIFE_CHANNEL_AD0,
	ADCIFE_CHANNEL_AD1,
	ADCIFE_CHANNEL_AD2,
	ADCIFE_CHANNEL_AD3,
	ADCIFE_CHANNEL_AD4,
	ADCIFE_CHANNEL_AD5,
	ADCIFE_CHANNEL_AD6,
	ADCIFE_CHANNEL_AD7,
	ADCIFE_CHANNEL_AD8,
	ADCIFE_CHANNEL_AD9,
	ADCIFE_CHANNEL_AD10,
	ADCIFE_CHANNEL_AD11,
	ADCIFE_CHANNEL_AD12,
	ADCIFE_CHANNEL_AD13,
	ADCIFE_CHANNEL_AD14,
};

enum adcife_resolution {
	ADCIFE_RESOLUTION_12BITS,
	ADCIFE_RESOLUTION_8BITS,
};

enum adcife_trigger {
	ADCIFE_TRIGGER_SW,
	ADCIFE_TRIGGER_IADC_TMR,
	ADCIFE_TRIGGER_ITS,
	ADCIFE_TRIGGER_CONT,
	ADCIFE_TRIGGER_EXT_RIS,
	ADCIFE_TRIGGER_EXT_FALL,
	ADCIFE_TRIGGER_EXT_BOTH,
};

enum adcife_gain {
	ADCIFE_GAIN_1X,
	ADCIFE_GAIN_2X,
	ADCIFE_GAIN_4X,
	ADCIFE_GAIN_8X,
	ADCIFE_GAIN_16X,
	ADCIFE_GAIN_32X,
	ADCIFE_GAIN_64X,
	ADCIFE_GAIN_0_5X,
};

struct adcife_lcv {
	union {
		uint32_t lcv;
		struct {
			uint16_t value;
			uint8_t channel;
			uint8_t reserved;
		} _lc_s;
	} _lc_u;
};

#define lc_channel _lc_u._lc_s.channel
#define lc_value _lc_u._lc_s.value

BEGIN_DECLS

void adcife_enable_sync(void);
void adcife_configure(
		enum adcife_refsel ref,
		enum adcife_speed speed,
		enum adcife_clk clk,
		enum adcife_prescal prescal);
void adcife_select_channel(enum adcife_channel ad);
void adcife_set_resolution(enum adcife_resolution res);
void adcife_select_trigger(enum adcife_trigger trig);
void adcife_set_gain(enum adcife_gain gain);
void adcife_set_bipolar(bool enable);
void adcife_set_left_adjust(bool enable);
void adcife_start_conversion(void);
void adcife_wait_conversion(void);
struct adcife_lcv adcife_get_lcv(void);
void adcife_enable_interrupts(uint32_t imask);
void adcife_disable_interrupts(uint32_t imask);
void adcife_timer_start(void);
void adcife_timer_stop(void);
void adcife_timer_set_timeout(uint16_t timeout);

END_DECLS

#endif
