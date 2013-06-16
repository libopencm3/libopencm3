/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef SAM3X_PWM_H
#define SAM3X_PWM_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- Pulse Width Modulation (PWM) registers ----------------------- */

#define PWM_CLK				MMIO32(PWM_BASE + 0x0000)
#define PWM_ENA				MMIO32(PWM_BASE + 0x0004)
#define PWM_DIS				MMIO32(PWM_BASE + 0x0008)
#define PWM_SR				MMIO32(PWM_BASE + 0x000C)
#define PWM_IER1			MMIO32(PWM_BASE + 0x0010)
#define PWM_IDR1			MMIO32(PWM_BASE + 0x0014)
#define PWM_IMR1			MMIO32(PWM_BASE + 0x0018)
#define PWM_ISR1			MMIO32(PWM_BASE + 0x001C)
#define PWM_SCM				MMIO32(PWM_BASE + 0x0020)
/* 0x0024 - Reserved */
#define PWM_SCUC			MMIO32(PWM_BASE + 0x0028)
#define PWM_SCUP			MMIO32(PWM_BASE + 0x002C)
#define PWM_SCUPUPD			MMIO32(PWM_BASE + 0x0030)
#define PWM_IER2			MMIO32(PWM_BASE + 0x0034)
#define PWM_IDR2			MMIO32(PWM_BASE + 0x0038)
#define PWM_IMR2			MMIO32(PWM_BASE + 0x003C)
#define PWM_ISR2			MMIO32(PWM_BASE + 0x0040)
#define PWM_OOV				MMIO32(PWM_BASE + 0x0044)
#define PWM_OS				MMIO32(PWM_BASE + 0x0048)
#define PWM_OSS				MMIO32(PWM_BASE + 0x004C)
#define PWM_OSC				MMIO32(PWM_BASE + 0x0050)
#define PWM_OSSUPD			MMIO32(PWM_BASE + 0x0054)
#define PWM_OSCUPD			MMIO32(PWM_BASE + 0x0058)
#define PWM_FMR				MMIO32(PWM_BASE + 0x005C)
#define PWM_FSR				MMIO32(PWM_BASE + 0x0060)
#define PWM_FCR				MMIO32(PWM_BASE + 0x0064)
#define PWM_FPV				MMIO32(PWM_BASE + 0x0068)
#define PWM_FPE1			MMIO32(PWM_BASE + 0x006C)
#define PWM_FPE2			MMIO32(PWM_BASE + 0x0070)
/* 0x0074:0x0078 - Reserved */
#define PWM_ELMR0			MMIO32(PWM_BASE + 0x007C)
#define PWM_ELMR1			MMIO32(PWM_BASE + 0x0080)
/* 0x0084:0x00AC - Reserved */
#define PWM_SMMR			MMIO32(PWM_BASE + 0x00B0)
/* 0x00B4:0x00E0 - Reserved */
#define PWM_WPCR			MMIO32(PWM_BASE + 0x00E4)
#define PWM_WPSR			MMIO32(PWM_BASE + 0x00E8)
/* 0x00EC:0x00FC - Reserved */
/* 0x0100:0x012C - Reserved */
#define PWM_CMPV(x)			MMIO32(PWM_BASE + 0x0130 + 0x10*(x))
#define PWM_CMPVUPD(x)			MMIO32(PWM_BASE + 0x0134 + 0x10*(x))
#define PWM_CMMV(x)			MMIO32(PWM_BASE + 0x0138 + 0x10*(x))
#define PWM_CMMVUPD(x)			MMIO32(PWM_BASE + 0x013C + 0x10*(x))
/* 0x01B0:0x01FC - Reserved */
#define PWM_CMR(x)			MMIO32(PWM_BASE + 0x0200 + 0x20*(x))
#define PWM_CDTY(x)			MMIO32(PWM_BASE + 0x0204 + 0x20*(x))
#if defined(SAM3X)
#	define PWM_CDTYUPD(x)		MMIO32(PWM_BASE + 0x0208 + 0x20*(x))
#	define PWM_CPRD(x)		MMIO32(PWM_BASE + 0x020C + 0x20*(x))
#	define PWM_CPRDUPD(x)		MMIO32(PWM_BASE + 0x0210 + 0x20*(x))
#	define PWM_CCNT(x)		MMIO32(PWM_BASE + 0x0214 + 0x20*(x))
#	define PWM_DT(x)		MMIO32(PWM_BASE + 0x0218 + 0x20*(x))
#	define PWM_DTUPD(x)		MMIO32(PWM_BASE + 0x021C + 0x20*(x))
#elif defined(SAM3N)
#	define PWM_CPRD(x)		MMIO32(PWM_BASE + 0x0208 + 0x20*(x))
#	define PWM_CCNT(x)		MMIO32(PWM_BASE + 0x020C + 0x20*(x))
#	define PWM_CUPD(x)		MMIO32(PWM_BASE + 0x0210 + 0x20*(x))
#else
#	error "Processor family not defined."
#endif

static inline void pwm_set_period(int ch, uint32_t period)
{
	PWM_CPRD(ch) = period;
}

static inline void pwm_set_duty(int ch, uint32_t duty)
{
	PWM_CDTY(ch) = duty;
}

static inline void pwm_enable(int ch)
{
	PWM_ENA = 1 << ch;
}

static inline void pwm_disable(int ch)
{
	PWM_DIS = 1 << ch;
}

#endif
