/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#ifndef LIBOPENCM3_EFM32_ADC_H
#define LIBOPENCM3_EFM32_ADC_H

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define ADC_CTRL(base)		MMIO32((base) + 0x000)
#define ADC_CMD(base)		MMIO32((base) + 0x004)
#define ADC_STATUS(base)	MMIO32((base) + 0x008)
#define ADC_SINGLECTRL(base)	MMIO32((base) + 0x00C)
#define ADC_SCANCTRL(base)	MMIO32((base) + 0x010)
#define ADC_IEN(base)		MMIO32((base) + 0x014)
#define ADC_IF(base)		MMIO32((base) + 0x018)
#define ADC_IFS(base)		MMIO32((base) + 0x01C)
#define ADC_IFC(base)		MMIO32((base) + 0x020)
#define ADC_SINGLEDATA(base)	MMIO32((base) + 0x024)
#define ADC_SCANDATA(base)	MMIO32((base) + 0x028)
#define ADC_SINGLEDATAP(base)	MMIO32((base) + 0x02C)
#define ADC_SCANDATAP(base)	MMIO32((base) + 0x030)
#define ADC_CAL(base)		MMIO32((base) + 0x034)
#define ADC_BIASPROG(base)	MMIO32((base) + 0x03C)

/* ADC_CTRL */
#define ADC_CTRL_OVERSEL_SHIFT	(24)
#define ADC_CTRL_OVERSEL_MASK	(0xF << ADC_CTRL_OVERSEL_SHIFT)
#define ADC_CTRL_OVERSEL(v)	\
	(((v) << ADC_CTRL_OVERSEL_SHIFT) & ADC_CTRL_OVERSEL_MASK)
#define ADC_CTRL_OVERSEL_X2	ADC_CTRL_OVERSEL(0)
#define ADC_CTRL_OVERSEL_X4	ADC_CTRL_OVERSEL(1)
#define ADC_CTRL_OVERSEL_X8	ADC_CTRL_OVERSEL(2)
#define ADC_CTRL_OVERSEL_X16	ADC_CTRL_OVERSEL(3)
#define ADC_CTRL_OVERSEL_X32	ADC_CTRL_OVERSEL(4)
#define ADC_CTRL_OVERSEL_X64	ADC_CTRL_OVERSEL(5)
#define ADC_CTRL_OVERSEL_X128	ADC_CTRL_OVERSEL(6)
#define ADC_CTRL_OVERSEL_X256	ADC_CTRL_OVERSEL(7)
#define ADC_CTRL_OVERSEL_X512	ADC_CTRL_OVERSEL(8)
#define ADC_CTRL_OVERSEL_X1024	ADC_CTRL_OVERSEL(9)
#define ADC_CTRL_OVERSEL_X2048	ADC_CTRL_OVERSEL(10)
#define ADC_CTRL_OVERSEL_X4096	ADC_CTRL_OVERSEL(11)

#define ADC_CTRL_TIMEBASE_SHIFT	(16)
#define ADC_CTRL_TIMEBASE_MASK	(0x3F << ADC_CTRL_TIMEBASE_SHIFT)
#define ADC_CTRL_TIMEBASE(v)	\
	(((v) << ADC_CTRL_TIMEBASE_SHIFT) & ADC_CTRL_TIMEBASE_MASK)

#define ADC_CTRL_PRESC_SHIFT	(8)
#define ADC_CTRL_PRESC_MASK	(0x3F << ADC_CTRL_PRESC_SHIFT)
#define ADC_CTRL_PRESC(v)	\
	(((v) << ADC_CTRL_PRESC_SHIFT) & ADC_CTRL_PRESC_MASK)

#define ADC_CTRL_LPFMODE_SHIFT	(4)
#define ADC_CTRL_LPFMODE_MASK	(0x3 << ADC_CTRL_LPFMODE_SHIFT)
#define ADC_CTRL_LPFMODE(v)	\
	(((v) << ADC_CTRL_LPFMODEC_SHIFT) & ADC_CTRL_LPFMODEC_MASK)
#define ADC_CTRL_LPFMODE_BYPASS	ADC_CTRL_LPFMODE(0)
#define ADC_CTRL_LPFMODE_DECAP	ADC_CTRL_LPFMODE(1)
#define ADC_CTRL_LPFMODE_RCFILT	ADC_CTRL_LPFMODE(2)

#define ADC_CTRL_TAILGATE	(1 << 3)

#define ADC_CTRL_WARMUPMODE_SHIFT	(0)
#define ADC_CTRL_WARMUPMODE_MASK	(0x3 << ADC_CTRL_WARMUPMODE_SHIFT)
#define ADC_CTRL_WARMUPMODE(v)		\
	(((v) << ADC_CTRL_WARMUPMODE_SHIFT) & ADC_CTRL_WARMUPMODE_MASK)
#define ADC_CTRL_WARMUPMODE_NORMAL	ADC_CTRL_WARMUPMODE(0)
#define ADC_CTRL_WARMUPMODE_FASTBG	ADC_CTRL_WARMUPMODE(1)
#define ADC_CTRL_WARMUPMODE_KEEPSCANREFWARM	ADC_CTRL_WARMUPMODE(2)
#define ADC_CTRL_WARMUPMODE_KEEPADCWARM		ADC_CTRL_WARMUPMODE(3)

/* ADC_CMD */
#define ADC_CMD_SCANSTOP	(1 << 3)
#define ADC_CMD_SCANSTART	(1 << 2)
#define ADC_CMD_SINGLESTOP	(1 << 1)
#define ADC_CMD_SINGLESTART	(1 << 0)

/* ADC_STATUS */
#define ADC_STATUS_SCANDATASRC_SHIFT	(0)
#define ADC_STATUS_SCANDATASRC_MASK	(0x7 << ADC_STATUS_SCANDATASRC_SHIFT)
#define ADC_STATUS_SCANDATASRC(v)	\
	(((v) << ADC_STATUS_SCANDATASRC_SHIFT) & ADC_STATUS_SCANDATASRC_MASK)

#define ADC_STATUS_SCANDV		(1 << 17)
#define ADC_STATUS_SINGLEDV		(1 << 16)
#define ADC_STATUS_WARM			(1 << 12)
#define ADC_STATUS_SCANREFWARM		(1 << 9)
#define ADC_STATUS_SINGLEREFWARM	(1 << 8)
#define ADC_STATUS_SCANACT		(1 << 1)
#define ADC_STATUS_SINGLEACT		(1 << 0)

/* ADC_SINGLECTRL */
#define ADC_SINGLECTRL_PRSSEL_SHIFT	(28)
#define ADC_SINGLECTRL_PRSSEL_MASK	(0xF << ADC_SINGLECTRL_PRSSEL_SHIFT)
#define ADC_SINGLECTRL_PRSSEL(v)	\
	(((v)  << ADC_SINGLECTRL_PRSSEL_SHIFT) & ADC_SINGLECTRL_PRSSEL_MASK)
#define ADC_SINGLECTRL_PRSSEL_PRSCHx(x)	ADC_SINGLECTRL_PRSSEL(x)
#define ADC_SINGLECTRL_PRSSEL_PRSCH0	ADC_SINGLECTRL_PRSSEL_PRSCHx(0)
#define ADC_SINGLECTRL_PRSSEL_PRSCH1	ADC_SINGLECTRL_PRSSEL_PRSCHx(1)
#define ADC_SINGLECTRL_PRSSEL_PRSCH2	ADC_SINGLECTRL_PRSSEL_PRSCHx(2)
#define ADC_SINGLECTRL_PRSSEL_PRSCH3	ADC_SINGLECTRL_PRSSEL_PRSCHx(3)
#define ADC_SINGLECTRL_PRSSEL_PRSCH4	ADC_SINGLECTRL_PRSSEL_PRSCHx(4)
#define ADC_SINGLECTRL_PRSSEL_PRSCH5	ADC_SINGLECTRL_PRSSEL_PRSCHx(5)
#define ADC_SINGLECTRL_PRSSEL_PRSCH6	ADC_SINGLECTRL_PRSSEL_PRSCHx(6)
#define ADC_SINGLECTRL_PRSSEL_PRSCH7	ADC_SINGLECTRL_PRSSEL_PRSCHx(7)
#define ADC_SINGLECTRL_PRSSEL_PRSCH8	ADC_SINGLECTRL_PRSSEL_PRSCHx(8)
#define ADC_SINGLECTRL_PRSSEL_PRSCH9	ADC_SINGLECTRL_PRSSEL_PRSCHx(9)
#define ADC_SINGLECTRL_PRSSEL_PRSCH10	ADC_SINGLECTRL_PRSSEL_PRSCHx(10)
#define ADC_SINGLECTRL_PRSSEL_PRSCH11	ADC_SINGLECTRL_PRSSEL_PRSCHx(11)

#define ADC_SINGLECTRL_PRSEN	(1 << 24)

#define ADC_SINGLECTRL_AT_SHIFT	(20)
#define ADC_SINGLECTRL_AT_MASK	(0xF << ADC_SINGLECTRL_AT_SHIFT)
#define ADC_SINGLECTRL_AT(v)	\
	(((v) << ADC_SINGLECTRL_AT_SHIFT) & ADC_SINGLECTRL_AT_MASK)
#define ADC_SINGLECTRL_AT_1CYCLE	ADC_SINGLECTRL_AT(0x0)
#define ADC_SINGLECTRL_AT_2CYCLES	ADC_SINGLECTRL_AT(0x1)
#define ADC_SINGLECTRL_AT_4CYCLES	ADC_SINGLECTRL_AT(0x2)
#define ADC_SINGLECTRL_AT_8CYCLES	ADC_SINGLECTRL_AT(0x3)
#define ADC_SINGLECTRL_AT_16CYCLES	ADC_SINGLECTRL_AT(0x4)
#define ADC_SINGLECTRL_AT_32CYCLES	ADC_SINGLECTRL_AT(0x5)
#define ADC_SINGLECTRL_AT_64CYCLES	ADC_SINGLECTRL_AT(0x6)
#define ADC_SINGLECTRL_AT_128CYCLES	ADC_SINGLECTRL_AT(0x7)
#define ADC_SINGLECTRL_AT_256CYCLES	ADC_SINGLECTRL_AT(0x8)

#define ADC_SINGLECTRL_REF_SHIFT	(16)
#define ADC_SINGLECTRL_REF_MASK		(0xF << ADC_SINGLECTRL_REF_SHIFT)
#define ADC_SINGLECTRL_REF(v)		\
	(((v) << ADC_SINGLECTRL_REF_SHIFT) & ADC_SINGLECTRL_REF_MASK)
#define ADC_SINGLECTRL_REF_1V25		ADC_SINGLECTRL_REF(0)
#define ADC_SINGLECTRL_REF_2V5		ADC_SINGLECTRL_REF(1)
#define ADC_SINGLECTRL_REF_VDD		ADC_SINGLECTRL_REF(2)
#define ADC_SINGLECTRL_REF_5VDIFF	ADC_SINGLECTRL_REF(3)
#define ADC_SINGLECTRL_REF_EXTSINGLE	ADC_SINGLECTRL_REF(4)
#define ADC_SINGLECTRL_REF_2XEXTDIFF	ADC_SINGLECTRL_REF(5)
#define ADC_SINGLECTRL_REF_2XVDD	ADC_SINGLECTRL_REF(6)

#define ADC_SINGLECTRL_INPUTSEL_SHIFT	(8)
#define ADC_SINGLECTRL_INPUTSEL_MASK	(0xF << ADC_SINGLECTRL_INPUTSEL_SHIFT)
#define ADC_SINGLECTRL_INPUTSEL(v)	\
	(((v) << ADC_SINGLECTRL_INPUTSEL_SHIFT) & ADC_SINGLECTRL_INPUTSEL_MASK)
/* DIFF=0 */
#define ADC_SINGLECTRL_INPUTSEL_CHx(x)		ADC_SINGLECTRL_INPUTSEL(x)
#define ADC_SINGLECTRL_INPUTSEL_CH0		ADC_SINGLECTRL_INPUTSEL_CHx(0)
#define ADC_SINGLECTRL_INPUTSEL_CH1		ADC_SINGLECTRL_INPUTSEL_CHx(1)
#define ADC_SINGLECTRL_INPUTSEL_CH2		ADC_SINGLECTRL_INPUTSEL_CHx(2)
#define ADC_SINGLECTRL_INPUTSEL_CH3		ADC_SINGLECTRL_INPUTSEL_CHx(3)
#define ADC_SINGLECTRL_INPUTSEL_CH4		ADC_SINGLECTRL_INPUTSEL_CHx(4)
#define ADC_SINGLECTRL_INPUTSEL_CH5		ADC_SINGLECTRL_INPUTSEL_CHx(5)
#define ADC_SINGLECTRL_INPUTSEL_CH6		ADC_SINGLECTRL_INPUTSEL_CHx(6)
#define ADC_SINGLECTRL_INPUTSEL_CH7		ADC_SINGLECTRL_INPUTSEL_CHx(7)
#define ADC_SINGLECTRL_INPUTSEL_TEMP		ADC_SINGLECTRL_INPUTSEL(8)
#define ADC_SINGLECTRL_INPUTSEL_VDDDIV3		ADC_SINGLECTRL_INPUTSEL(9)
#define ADC_SINGLECTRL_INPUTSEL_VDD		ADC_SINGLECTRL_INPUTSEL(10)
#define ADC_SINGLECTRL_INPUTSEL_VSS		ADC_SINGLECTRL_INPUTSEL(11)
#define ADC_SINGLECTRL_INPUTSEL_VREFDIV2	ADC_SINGLECTRL_INPUTSEL(12)
#define ADC_SINGLECTRL_INPUTSEL_DAC0OUT0	ADC_SINGLECTRL_INPUTSEL(13)
#define ADC_SINGLECTRL_INPUTSEL_DAC0OUT1	ADC_SINGLECTRL_INPUTSEL(14)
/* DIFF=1 */
#define ADC_SINGLECTRL_INPUTSEL_CH0CH1		ADC_SINGLECTRL_INPUTSEL(0)
#define ADC_SINGLECTRL_INPUTSEL_CH2CH3		ADC_SINGLECTRL_INPUTSEL(1)
#define ADC_SINGLECTRL_INPUTSEL_CH4CH5		ADC_SINGLECTRL_INPUTSEL(2)
#define ADC_SINGLECTRL_INPUTSEL_CH6CH7		ADC_SINGLECTRL_INPUTSEL(3)
#define ADC_SINGLECTRL_INPUTSEL_DIFF0		ADC_SINGLECTRL_INPUTSEL(4)

#define ADC_SINGLECTRL_RES_SHIFT	(4)
#define ADC_SINGLECTRL_RES_MASK		(0x3 << ADC_SINGLECTRL_RES_SHIFT)
#define ADC_SINGLECTRL_RES(v)		\
	(((v) << ADC_SINGLECTRL_RES_SHIFT) & ADC_SINGLECTRL_RES_MASK)
#define ADC_SINGLECTRL_RES_12BIT	ADC_SINGLECTRL_RES(0)
#define ADC_SINGLECTRL_RES_8BIT		ADC_SINGLECTRL_RES(1)
#define ADC_SINGLECTRL_RES_6BIT		ADC_SINGLECTRL_RES(2)
#define ADC_SINGLECTRL_RES_OVS		ADC_SINGLECTRL_RES(3)

#define ADC_SINGLECTRL_ADJ	(1 << 2)
#define ADC_SINGLECTRL_DIFF	(1 << 1)
#define ADC_SINGLECTRL_REP	(1 << 0)

/* ADC_SCANCTRL */
#define ADC_SCANCTRL_PRSSEL_SHIFT	(28)
#define ADC_SCANCTRL_PRSSEL_MASK	(0xF << ADC_SCANCTRL_PRSSEL_SHIFT)
#define ADC_SCANCTRL_PRSSEL(v)		\
	(((v)  << ADC_SCANCTRL_PRSSEL_SHIFT) & ADC_SCANCTRL_PRSSEL_MASK)
#define ADC_SCANCTRL_PRSSEL_PRSCHx(x)	ADC_SCANCTRL_PRSSEL(x)
#define ADC_SCANCTRL_PRSSEL_PRSCH0	ADC_SCANCTRL_PRSSEL_PRSCHx(0)
#define ADC_SCANCTRL_PRSSEL_PRSCH1	ADC_SCANCTRL_PRSSEL_PRSCHx(1)
#define ADC_SCANCTRL_PRSSEL_PRSCH2	ADC_SCANCTRL_PRSSEL_PRSCHx(2)
#define ADC_SCANCTRL_PRSSEL_PRSCH3	ADC_SCANCTRL_PRSSEL_PRSCHx(3)
#define ADC_SCANCTRL_PRSSEL_PRSCH4	ADC_SCANCTRL_PRSSEL_PRSCHx(4)
#define ADC_SCANCTRL_PRSSEL_PRSCH5	ADC_SCANCTRL_PRSSEL_PRSCHx(5)
#define ADC_SCANCTRL_PRSSEL_PRSCH6	ADC_SCANCTRL_PRSSEL_PRSCHx(6)
#define ADC_SCANCTRL_PRSSEL_PRSCH7	ADC_SCANCTRL_PRSSEL_PRSCHx(7)
#define ADC_SCANCTRL_PRSSEL_PRSCH8	ADC_SCANCTRL_PRSSEL_PRSCHx(8)
#define ADC_SCANCTRL_PRSSEL_PRSCH9	ADC_SCANCTRL_PRSSEL_PRSCHx(9)
#define ADC_SCANCTRL_PRSSEL_PRSCH10	ADC_SCANCTRL_PRSSEL_PRSCHx(10)
#define ADC_SCANCTRL_PRSSEL_PRSCH11	ADC_SCANCTRL_PRSSEL_PRSCHx(11)

#define ADC_SCANCTRL_PRSEN	(1 << 24)

#define ADC_SCANCTRL_AT_SHIFT	(20)
#define ADC_SCANCTRL_AT_MASK	(0xF << ADC_SCANCTRL_AT_SHIFT)
#define ADC_SCANCTRL_AT(v)			\
	(((v) << ADC_SCANCTRL_AT_SHIFT) & ADC_SCANCTRL_AT_MASK)
#define ADC_SCANCTRL_AT_1CYCLE		ADC_SCANCTRL_AT(0)
#define ADC_SCANCTRL_AT_2CYCLES		ADC_SCANCTRL_AT(1)
#define ADC_SCANCTRL_AT_4CYCLES		ADC_SCANCTRL_AT(2)
#define ADC_SCANCTRL_AT_8CYCLES		ADC_SCANCTRL_AT(3)
#define ADC_SCANCTRL_AT_16CYCLES	ADC_SCANCTRL_AT(4)
#define ADC_SCANCTRL_AT_32CYCLES	ADC_SCANCTRL_AT(5)
#define ADC_SCANCTRL_AT_64CYCLES	ADC_SCANCTRL_AT(6)
#define ADC_SCANCTRL_AT_128CYCLES	ADC_SCANCTRL_AT(7)
#define ADC_SCANCTRL_AT_256CYCLES	ADC_SCANCTRL_AT(8)

#define ADC_SCANCTRL_REF_SHIFT	(16)
#define ADC_SCANCTRL_REF_MASK	(0xF << ADC_SCANCTRL_REF_SHIFT)
#define ADC_SCANCTRL_REF(v)			\
	(((v) << ADC_SCANCTRL_REF_SHIFT) & ADC_SCANCTRL_REF_MASK)
#define ADC_SCANCTRL_REF_1V25		ADC_SCANCTRL_REF(0)
#define ADC_SCANCTRL_REF_2V5		ADC_SCANCTRL_REF(1)
#define ADC_SCANCTRL_REF_VDD		ADC_SCANCTRL_REF(2)
#define ADC_SCANCTRL_REF_5VDIFF		ADC_SCANCTRL_REF(3)
#define ADC_SCANCTRL_REF_EXTSCAN	ADC_SCANCTRL_REF(4)
#define ADC_SCANCTRL_REF_2XEXTDIFF	ADC_SCANCTRL_REF(5)
#define ADC_SCANCTRL_REF_2XVDD		ADC_SCANCTRL_REF(6)


#define ADC_SCANCTRL_INPUTSEL_SHIFT	(8)
#define ADC_SCANCTRL_INPUTSEL_MASK	(0xFF << ADC_SCANCTRL_INPUTSEL_SHIFT)
#define ADC_SCANCTRL_INPUTSEL(v)		\
	(((v) << ADC_SCANCTRL_INPUTSEL_SHIFT) & ADC_SCANCTRL_INPUTSEL_MASK)
/* DIFF=0 */
#define ADC_SCANCTRL_INPUTSEL_CHx(x)	ADC_SCANCTRL_INPUTSEL(1 << (x))
#define ADC_SCANCTRL_INPUTSEL_CH0	ADC_SCANCTRL_INPUTSEL_CHx(0)
#define ADC_SCANCTRL_INPUTSEL_CH1	ADC_SCANCTRL_INPUTSEL_CHx(1)
#define ADC_SCANCTRL_INPUTSEL_CH2	ADC_SCANCTRL_INPUTSEL_CHx(2)
#define ADC_SCANCTRL_INPUTSEL_CH3	ADC_SCANCTRL_INPUTSEL_CHx(3)
#define ADC_SCANCTRL_INPUTSEL_CH4	ADC_SCANCTRL_INPUTSEL_CHx(4)
#define ADC_SCANCTRL_INPUTSEL_CH5	ADC_SCANCTRL_INPUTSEL_CHx(5)
#define ADC_SCANCTRL_INPUTSEL_CH6	ADC_SCANCTRL_INPUTSEL_CHx(6)
#define ADC_SCANCTRL_INPUTSEL_CH7	ADC_SCANCTRL_INPUTSEL_CHx(7)
/* DIFF=1 */
#define ADC_SCANCTRL_INPUTSEL_CH0CH1	ADC_SCANCTRL_INPUTSEL(1 << 0)
#define ADC_SCANCTRL_INPUTSEL_CH2CH3	ADC_SCANCTRL_INPUTSEL(1 << 1)
#define ADC_SCANCTRL_INPUTSEL_CH4CH5	ADC_SCANCTRL_INPUTSEL(1 << 2)
#define ADC_SCANCTRL_INPUTSEL_CH6CH7	ADC_SCANCTRL_INPUTSEL(1 << 3)

#define ADC_SCANCTRL_RES_SHIFT		(4)
#define ADC_SCANCTRL_RES_MASK		(0x3 << ADC_SCANCTRL_RES_SHIFT)
#define ADC_SCANCTRL_RES(v)			\
	(((v) << ADC_SCANCTRL_RES_SHIFT) & ADC_SCANCTRL_RES_MASK)
#define ADC_SCANCTRL_RES_12BIT		ADC_SCANCTRL_RES(0)
#define ADC_SCANCTRL_RES_8BIT		ADC_SCANCTRL_RES(1)
#define ADC_SCANCTRL_RES_6BIT		ADC_SCANCTRL_RES(2)
#define ADC_SCANCTRL_RES_OVS		ADC_SCANCTRL_RES(3)

#define ADC_SCANCTRL_ADJ	(1 << 2)
#define ADC_SCANCTRL_DIFF	(1 << 1)
#define ADC_SCANCTRL_REP	(1 << 0)

/* ADC_IEN */
#define ADC_IEN_SCANOF		(1 << 9)
#define ADC_IEN_SINGLEOF	(1 << 8)
#define ADC_IEN_SCAN		(1 << 1)
#define ADC_IEN_SINGLE		(1 << 0)

/* ADC_IF */
#define ADC_IF_SCANOF		(1 << 9)
#define ADC_IF_SINGLEOF		(1 << 8)
#define ADC_IF_SCAN		(1 << 1)
#define ADC_IF_SINGLE		(1 << 0)

/* ADC_IFS */
#define ADC_IFS_SCANOF		(1 << 9)
#define ADC_IFS_SINGLEOF	(1 << 8)
#define ADC_IFS_SCAN		(1 << 1)
#define ADC_IFS_SINGLE		(1 << 0)

/* ADC_IFC */
#define ADC_IFC_SCANOF		(1 << 9)
#define ADC_IFC_SINGLEOF	(1 << 8)
#define ADC_IFC_SCAN		(1 << 1)
#define ADC_IFC_SINGLE		(1 << 0)

/* ADC_CAL */
#define ADC_CAL_SCANGAIN_SHIFT	(24)
#define ADC_CAL_SCANGAIN_MASK	(0x7F)

#define ADC_CAL_SCANOFF_SHIFT	(16)
#define ADC_CAL_SCANOFF_MASK	(0x7F)

#define ADC_CAL_SINGLEGAIN_SHIFT (8)
#define ADC_CAL_SINGLEGAIN_MASK	(0x7F)

#define ADC_CAL_SINGLEOFF_SHIFT	(0)
#define ADC_CAL_SINGLEOFF_MASK	(0x7F)

/* ADC_BIASPROG */
#define ADC_BIASPROG_COMPBIAS_SHIFT	(8)
#define ADC_BIASPROG_COMPBIAS_MASK	(0xF)

#define ADC_BIASPROG_HALFBIAS		(1 << 6)

#define ADC_BIASPROG_BIASPROG_SHIFT	(0)
#define ADC_BIASPROG_BIASPROG_MASK	(0xF)

/* ADC0 */
#define ADC0			ADC0_BASE
#define ADC0_CTRL		ADC_CTRL(ADC0)
#define ADC0_CMD		ADC_CMD(ADC0)
#define ADC0_STATUS		ADC_STATUS(ADC0)
#define ADC0_SINGLECTRL		ADC_SINGLECTRL(ADC0)
#define ADC0_SCANCTRL		ADC_SCANCTRL(ADC0)
#define ADC0_IEN		ADC_IEN(ADC0)
#define ADC0_IF			ADC_IF(ADC0)
#define ADC0_IFS		ADC_IFS(ADC0)
#define ADC0_IFC		ADC_IFC(ADC0)
#define ADC0_SINGLEDATA		ADC_SINGLEDATA(ADC0)
#define ADC0_SCANDATA		ADC_SCANDATA(ADC0)
#define ADC0_SINGLEDATAP	ADC_SINGLEDATAP(ADC0)
#define ADC0_SCANDATAP		ADC_SCANDATAP(ADC0)
#define ADC0_CAL		ADC_CAL(ADC0)
#define ADC0_BIASPROG		ADC_BIASPROG(ADC0)

/** @defgroup adc_ch ADC Channel Number
@ingroup adc_defines

@{*/
#define ADC_CH0			0
#define ADC_CH1			1
#define ADC_CH2			2
#define ADC_CH3			3
#define ADC_CH4			4
#define ADC_CH5			5
#define ADC_CH6			6
#define ADC_CH7			7
#define ADC_CH_TEMP		8
#define ADC_CH_VDDDIV3		9
#define ADC_CH_VDD		10
#define ADC_CH_VSS		11
#define ADC_CH_VREFDIV2		12
#define ADC_CH_DAC0OUT0		13
#define ADC_CH_DAC0OUT1		14

#define ADC_CH_CH0CH1		0
#define ADC_CH_CH2CH3		1
#define ADC_CH_CH4CH5		2
#define ADC_CH_CH6CH7		3
#define ADC_CH_DIFF0		4
/**@}*/

BEGIN_DECLS

void adc_set_oversampling(uint32_t adc, uint32_t oversamp);
void adc_set_warm_up(uint32_t adc, uint8_t clocks);
void adc_set_clock_prescaler(uint32_t adc, uint8_t factor);
void adc_set_lowpass_filter(uint32_t adc, uint32_t lpfmode);

void adc_enable_tailgating(uint32_t adc);
void adc_disable_tailgating(uint32_t adc);

void adc_set_warm_up_mode(uint32_t adc, uint32_t warmupmode);

void adc_single_start(uint32_t adc);
void adc_single_stop(uint32_t adc);

void adc_scan_start(uint32_t adc);
void adc_scan_stop(uint32_t adc);

/* TODO: ADC_STATUS */

void adc_set_single_prs_trigger(uint32_t adc, uint8_t prssel);
void adc_enable_single_prs_trigger(uint32_t adc);
void adc_disable_single_prs_trigger(uint32_t adc);
void adc_set_single_acquisition_cycle(uint32_t adc, uint32_t at);
void adc_set_single_reference(uint32_t adc, uint32_t ref);
void adc_set_single_channel(uint32_t adc, uint8_t ch);
void adc_set_single_resolution(uint32_t adc, uint32_t res);
void adc_set_single_left_aligned(uint32_t adc);
void adc_set_single_right_aligned(uint32_t adc);
void adc_set_single_single_ended(uint32_t adc);
void adc_set_single_differential(uint32_t adc);
void adc_enable_single_repeat_conv(uint32_t adc);
void adc_disable_single_repeat_conv(uint32_t adc);

void adc_set_scan_prs_trigger(uint32_t adc, uint8_t prssel);
void adc_enable_scan_prs_trigger(uint32_t adc);
void adc_disable_scan_prs_trigger(uint32_t adc);
void adc_set_scan_acquisition_cycle(uint32_t adc, uint32_t at);
void adc_set_scan_reference(uint32_t adc, uint32_t ref);
void adc_set_scan_channel(uint32_t adc, uint8_t length,
			  uint8_t channel[]);
void adc_set_scan_resolution(uint32_t adc, uint32_t res);
void adc_set_scan_left_aligned(uint32_t adc);
void adc_set_scan_right_aligned(uint32_t adc);
void adc_set_scan_single_ended(uint32_t adc);
void adc_set_scan_differential(uint32_t adc);
void adc_enable_scan_repeat_conv(uint32_t adc);
void adc_disable_scan_repeat_conv(uint32_t adc);

void adc_enable_single_result_overflow_interrupt(uint32_t adc);
void adc_disable_single_result_overflow_interrupt(uint32_t adc);
void adc_enable_single_conversion_complete_interrupt(uint32_t adc);
void adc_disable_single_conversion_complete_interrupt(uint32_t adc);
void adc_enable_scan_result_overflow_interrupt(uint32_t adc);
void adc_disable_scan_result_overflow_interrupt(uint32_t adc);
void adc_enable_scan_conversion_complete_interrupt(uint32_t adc);
void adc_disable_scan_conversion_complete_interrupt(uint32_t adc);

bool adc_get_single_result_overflow_flag(uint32_t adc);
bool adc_get_single_conversion_complete_flag(uint32_t adc);
bool adc_get_scan_result_overflow_flag(uint32_t adc);
bool adc_get_scan_conversion_complete_flag(uint32_t adc);

void adc_set_single_result_overflow_flag(uint32_t adc);
void adc_set_single_conversion_complete_flag(uint32_t adc);
void adc_set_scan_result_overflow_flag(uint32_t adc);
void adc_set_scan_conversion_complete_flag(uint32_t adc);

void adc_clear_single_result_overflow_flag(uint32_t adc);
void adc_clear_single_conversion_complete_flag(uint32_t adc);
void adc_clear_scan_result_overflow_flag(uint32_t adc);
void adc_clear_scan_conversion_complete_flag(uint32_t adc);

uint32_t adc_single_data(uint32_t adc);
uint32_t adc_scan_data(uint32_t adc);

uint32_t adc_single_data_peak(uint32_t adc);
uint32_t adc_scan_data_peak(uint32_t adc);

void adc_set_calibration_scan_gain(uint32_t adc, uint8_t scan_gain);
void adc_set_calibration_scan_offset(uint32_t adc, uint8_t scan_offset);

void adc_set_calibration_single_gain(uint32_t adc, uint8_t single_gain);
void adc_set_calibration_single_offset(uint32_t adc, uint8_t single_offset);

END_DECLS

#endif

