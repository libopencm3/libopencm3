/** @defgroup rcc_defines RCC Defines
@brief <b>Defined Constants and Types for the STM32MP1xx Reset and Clock
Control</b>
@ingroup STM32MP1xx_defines
@version 1.0.0
LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Brian Viele <vielster@allocor.tech>
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

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/cm3/common.h>
/**@{*/


#define RCC_OFFSET_MASK 0xFFF
#define RCC_BASE_LEN    12
#define RCC_BIT_POS_LEN 5
#define RCC_BIT_POS_MASK 0x1F
#define _REG_BIT(base, bit, clr_base, clr_pol) \
        ((((base) & RCC_OFFSET_MASK) << RCC_BIT_POS_LEN) \
         + ((bit) & 0x1F) \
         + (((clr_base) & RCC_OFFSET_MASK) << (RCC_BASE_LEN + RCC_BIT_POS_LEN)) \
         + (((clr_pol) & 0x1) << (2*RCC_BASE_LEN + RCC_BIT_POS_LEN)))
enum rcc_periph_clken {
	/* APB1 peripherals */
	RCC_TIM2   = _REG_BIT(0xA80, 0, 0xA84, 1),
	RCC_TIM3   = _REG_BIT(0xA80, 1, 0xA84, 1),
	RCC_TIM4   = _REG_BIT(0xA80, 2, 0xA84, 1),
	RCC_TIM5   = _REG_BIT(0xA80, 3, 0xA84, 1),
	RCC_TIM6   = _REG_BIT(0xA80, 4, 0xA84, 1),
	RCC_TIM7   = _REG_BIT(0xA80, 5, 0xA84, 1),
	RCC_TIM12  = _REG_BIT(0xA80, 6, 0xA84, 1),
	RCC_TIM13  = _REG_BIT(0xA80, 7, 0xA84, 1),
	RCC_TIM14  = _REG_BIT(0xA80, 8, 0xA84, 1),
	RCC_LPTIM1 = _REG_BIT(0xA80, 9, 0xA84, 1),
	RCC_SPI2   = _REG_BIT(0xA80, 11, 0xA84, 1),
	RCC_SPI3   = _REG_BIT(0xA80, 12, 0xA84, 1),
	RCC_USART2 = _REG_BIT(0xA80, 14, 0xA84, 1),
	RCC_USART3 = _REG_BIT(0xA80, 15, 0xA84, 1),
	RCC_UART4  = _REG_BIT(0xA80, 16, 0xA84, 1),
	RCC_UART5  = _REG_BIT(0xA80, 17, 0xA84, 1),
	RCC_UART7  = _REG_BIT(0xA80, 18, 0xA84, 1),
	RCC_UART8  = _REG_BIT(0xA80, 19, 0xA84, 1),
	RCC_I2C1   = _REG_BIT(0xA80, 21, 0xA84, 1),
	RCC_I2C2   = _REG_BIT(0xA80, 22, 0xA84, 1),
	RCC_I2C3   = _REG_BIT(0xA80, 23, 0xA84, 1),
	RCC_I2C5   = _REG_BIT(0xA80, 24, 0xA84, 1),
	RCC_SPDIF  = _REG_BIT(0xA80, 26, 0xA84, 1),
	RCC_CEC    = _REG_BIT(0xA80, 27, 0xA84, 1),
	RCC_DAC    = _REG_BIT(0xA80, 29, 0xA84, 1),
	RCC_MDIOS  = _REG_BIT(0xA80, 31, 0xA84, 1),

	/* APB2 peripherals */
	RCC_TIM1    = _REG_BIT(0xA88, 0, 0xA8C, 1),
	RCC_TIM8    = _REG_BIT(0xA88, 1, 0xA8C, 1),
	RCC_TIM15   = _REG_BIT(0xA88, 2, 0xA8C, 1),
	RCC_TIM16   = _REG_BIT(0xA88, 3, 0xA8C, 1),
	RCC_TIM17   = _REG_BIT(0xA88, 4, 0xA8C, 1),
	RCC_SPI1    = _REG_BIT(0xA88, 8, 0xA8C, 1),
	RCC_SPI4    = _REG_BIT(0xA88, 9, 0xA8C, 1),
	RCC_SPI5    = _REG_BIT(0xA88, 10, 0xA8C, 1),
	RCC_USART6  = _REG_BIT(0xA88, 13, 0xA8C, 1),
	RCC_SAI1    = _REG_BIT(0xA88, 16, 0xA8C, 1),
	RCC_SAI2    = _REG_BIT(0xA88, 17, 0xA8C, 1),
	RCC_SAI3    = _REG_BIT(0xA88, 18, 0xA8C, 1),
	RCC_DFSDM   = _REG_BIT(0xA88, 20, 0xA8C, 1),
	RCC_ADDFSDM = _REG_BIT(0xA88, 21, 0xA8C, 1),
	RCC_FDCAN   = _REG_BIT(0xA88, 24, 0xA8C, 1),

	/* APB3 peripherals */
	RCC_LPTIM2 = _REG_BIT(0xA90, 0, 0xA94, 1),
	RCC_LPTIM3 = _REG_BIT(0xA90, 1, 0xA94, 1),
	RCC_LPTIM4 = _REG_BIT(0xA90, 2, 0xA94, 1),
	RCC_LPTIM5 = _REG_BIT(0xA90, 3, 0xA94, 1),
	RCC_SAI4   = _REG_BIT(0xA90, 8, 0xA94, 1),
	RCC_SYSCFG = _REG_BIT(0xA90, 11, 0xA94, 1),
	RCC_VREF   = _REG_BIT(0xA90, 13, 0xA94, 1),
	RCC_DTS    = _REG_BIT(0xA90, 16, 0xA94, 1),
	RCC_HDP    = _REG_BIT(0xA90, 20, 0xA94, 1),

	/* APB4 peripherals */
	RCC_LTDC     = _REG_BIT(0x280, 0, 0x284, 1),
	RCC_DSI      = _REG_BIT(0x280, 4, 0x284, 1),
	RCC_DDRPERFM = _REG_BIT(0x280, 8, 0x284, 1),
	RCC_USBPHY   = _REG_BIT(0x280, 16, 0x284, 1),
	RCC_STGENRO  = _REG_BIT(0x280, 20, 0x284, 1),

	/* APB5 peripherals */
	RCC_SPI6   = _REG_BIT(0x288, 0, 0x28C, 1),
	RCC_I2C4   = _REG_BIT(0x288, 2, 0x28C, 1),
	RCC_I2C6   = _REG_BIT(0x288, 3, 0x28C, 1),
	RCC_USART1 = _REG_BIT(0x288, 4, 0x28C, 1),
	RCC_RTCAPB = _REG_BIT(0x288, 8, 0x28C, 1),
	RCC_TZC1   = _REG_BIT(0x288, 11, 0x28C, 1),
	RCC_TZC2   = _REG_BIT(0x288, 12, 0x28C, 1),
	RCC_TZP    = _REG_BIT(0x288, 13, 0x28C, 1),
	RCC_BSEC   = _REG_BIT(0x288, 16, 0x28C, 1),
	RCC_STGEN  = _REG_BIT(0x288, 20, 0x28C, 1),

	/* AHB5 peripherals */
	RCC_GPIOZ   = _REG_BIT(0x290, 0, 0x294, 1),
	RCC_CRYP1   = _REG_BIT(0x290, 4, 0x294, 1),
	RCC_HASH1   = _REG_BIT(0x290, 5, 0x294, 1),
	RCC_RNG1    = _REG_BIT(0x290, 6, 0x294, 1),
	RCC_BKPSRAM = _REG_BIT(0x290, 8, 0x294, 1),

	/* AHB6 peripherals */
	RCC_MDMA   = _REG_BIT(0x298, 0, 0x29C, 1),
	RCC_GPU    = _REG_BIT(0x298, 5, 0x29C, 1),
	RCC_ETHCK  = _REG_BIT(0x298, 7, 0x29C, 1),
	RCC_ETHTX  = _REG_BIT(0x298, 8, 0x29C, 1),
	RCC_ETHRX  = _REG_BIT(0x298, 9, 0x29C, 1),
	RCC_ETHMAC = _REG_BIT(0x298, 10, 0x29C, 1),
	RCC_FMC    = _REG_BIT(0x298, 12, 0x29C, 1),
	RCC_QSPI   = _REG_BIT(0x298, 14, 0x29C, 1),
	RCC_SDMMC1 = _REG_BIT(0x298, 16, 0x29C, 1),
	RCC_SDMMC2 = _REG_BIT(0x298, 17, 0x29C, 1),
	RCC_CRC1   = _REG_BIT(0x298, 20, 0x29C, 1),
	RCC_USBH   = _REG_BIT(0x298, 24, 0x29C, 1),

	/* AHB2 peripherals */
	RCC_DMA1   = _REG_BIT(0xA98, 0, 0xA9C, 1),
	RCC_DMA2   = _REG_BIT(0xA98, 1, 0xA9C, 1),
	RCC_DMAMUX = _REG_BIT(0xA98, 2, 0xA9C, 1),
	RCC_ADC    = _REG_BIT(0xA98, 5, 0xA9C, 1),
	RCC_USBO   = _REG_BIT(0xA98, 8, 0xA9C, 1),
	RCC_SDMMC3 = _REG_BIT(0xA98, 16, 0xA9C, 1),

	/* AHB3 peripherals */
	RCC_DCMI  = _REG_BIT(0xAA0, 0, 0xAA4, 1),
	RCC_CRYP2 = _REG_BIT(0xAA0, 4, 0xAA4, 1),
	RCC_HASH2 = _REG_BIT(0xAA0, 5, 0xAA4, 1),
	RCC_RNG2  = _REG_BIT(0xAA0, 6, 0xAA4, 1),
	RCC_CRC2  = _REG_BIT(0xAA0, 7, 0xAA4, 1),
	RCC_HSEM  = _REG_BIT(0xAA0, 11, 0xAA4, 1),
	RCC_IPCC  = _REG_BIT(0xAA0, 12, 0xAA4, 1),

	/* AHB4 peripherals */
	RCC_GPIOA = _REG_BIT(0xAA8, 0, 0xAAC, 1),
	RCC_GPIOB = _REG_BIT(0xAA8, 1, 0xAAC, 1),
	RCC_GPIOC = _REG_BIT(0xAA8, 2, 0xAAC, 1),
	RCC_GPIOD = _REG_BIT(0xAA8, 3, 0xAAC, 1),
	RCC_GPIOE = _REG_BIT(0xAA8, 4, 0xAAC, 1),
	RCC_GPIOF = _REG_BIT(0xAA8, 5, 0xAAC, 1),
	RCC_GPIOG = _REG_BIT(0xAA8, 6, 0xAAC, 1),
	RCC_GPIOH = _REG_BIT(0xAA8, 7, 0xAAC, 1),
	RCC_GPIOI = _REG_BIT(0xAA8, 8, 0xAAC, 1),
	RCC_GPIOJ = _REG_BIT(0xAA8, 9, 0xAAC, 1),
	RCC_GPIOK = _REG_BIT(0xAA8, 10, 0xAAC, 1),

	/* AXI peripherals */
	RCC_SYSRAM = _REG_BIT(0xAB0, 0, 0xAB4, 1),

	/* ML */
	RCC_RETRAM = _REG_BIT(0xAB8, 4, 0xABC, 1),
};

enum rcc_periph_rst {
	/* APB1 peripherals */
	RST_TIM2   = _REG_BIT(0x980, 0, 0x984, 1),
	RST_TIM3   = _REG_BIT(0x980, 1, 0x984, 1),
	RST_TIM4   = _REG_BIT(0x980, 2, 0x984, 1),
	RST_TIM5   = _REG_BIT(0x980, 3, 0x984, 1),
	RST_TIM6   = _REG_BIT(0x980, 4, 0x984, 1),
	RST_TIM7   = _REG_BIT(0x980, 5, 0x984, 1),
	RST_TIM12  = _REG_BIT(0x980, 6, 0x984, 1),
	RST_TIM13  = _REG_BIT(0x980, 7, 0x984, 1),
	RST_TIM14  = _REG_BIT(0x980, 8, 0x984, 1),
	RST_LPTIM1 = _REG_BIT(0x980, 9, 0x984, 1),
	RST_SPI2   = _REG_BIT(0x980, 11, 0x984, 1),
	RST_SPI3   = _REG_BIT(0x980, 12, 0x984, 1),
	RST_USART2 = _REG_BIT(0x980, 14, 0x984, 1),
	RST_USART3 = _REG_BIT(0x980, 15, 0x984, 1),
	RST_UART4  = _REG_BIT(0x980, 16, 0x984, 1),
	RST_UART5  = _REG_BIT(0x980, 17, 0x984, 1),
	RST_UART7  = _REG_BIT(0x980, 18, 0x984, 1),
	RST_UART8  = _REG_BIT(0x980, 19, 0x984, 1),
	RST_I2C1   = _REG_BIT(0x980, 21, 0x984, 1),
	RST_I2C2   = _REG_BIT(0x980, 22, 0x984, 1),
	RST_I2C3   = _REG_BIT(0x980, 23, 0x984, 1),
	RST_I2C5   = _REG_BIT(0x980, 24, 0x984, 1),
	RST_SPDIF  = _REG_BIT(0x980, 26, 0x984, 1),
	RST_CEC    = _REG_BIT(0x980, 27, 0x984, 1),
	RST_DAC    = _REG_BIT(0x980, 29, 0x984, 1),
	RST_MDIOS  = _REG_BIT(0x980, 31, 0x984, 1),

	/* APB2 peripherals */
	RST_TIM1    = _REG_BIT(0x988, 0, 0x98C, 1),
	RST_TIM8    = _REG_BIT(0x988, 1, 0x98C, 1),
	RST_TIM15   = _REG_BIT(0x988, 2, 0x98C, 1),
	RST_TIM16   = _REG_BIT(0x988, 3, 0x98C, 1),
	RST_TIM17   = _REG_BIT(0x988, 4, 0x98C, 1),
	RST_SPI1    = _REG_BIT(0x988, 8, 0x98C, 1),
	RST_SPI4    = _REG_BIT(0x988, 9, 0x98C, 1),
	RST_SPI5    = _REG_BIT(0x988, 10, 0x98C, 1),
	RST_USART6  = _REG_BIT(0x988, 13, 0x98C, 1),
	RST_SAI1    = _REG_BIT(0x988, 16, 0x98C, 1),
	RST_SAI2    = _REG_BIT(0x988, 17, 0x98C, 1),
	RST_SAI3    = _REG_BIT(0x988, 18, 0x98C, 1),
	RST_DFSDM   = _REG_BIT(0x988, 20, 0x98C, 1),
	RST_ADDFSDM = _REG_BIT(0x988, 21, 0x98C, 1),
	RST_FDCAN   = _REG_BIT(0x988, 24, 0x98C, 1),

	/* APB3 peripherals */
	RST_LPTIM2 = _REG_BIT(0x990, 0, 0x994, 1),
	RST_LPTIM3 = _REG_BIT(0x990, 1, 0x994, 1),
	RST_LPTIM4 = _REG_BIT(0x990, 2, 0x994, 1),
	RST_LPTIM5 = _REG_BIT(0x990, 3, 0x994, 1),
	RST_SAI4   = _REG_BIT(0x990, 8, 0x994, 1),
	RST_SYSCFG = _REG_BIT(0x990, 11, 0x994, 1),
	RST_VREF   = _REG_BIT(0x990, 13, 0x994, 1),
	RST_DTS    = _REG_BIT(0x990, 16, 0x994, 1),
	RST_HDP    = _REG_BIT(0x990, 20, 0x994, 1),

	/* AHB2 peripherals */
	RST_DMA1   = _REG_BIT(0x998, 0, 0x99C, 1),
	RST_DMA2   = _REG_BIT(0x998, 1, 0x99C, 1),
	RST_DMAMUX = _REG_BIT(0x998, 2, 0x99C, 1),
	RST_ADC    = _REG_BIT(0x998, 5, 0x99C, 1),
	RST_USBO   = _REG_BIT(0x998, 8, 0x99C, 1),
	RST_SDMMC3 = _REG_BIT(0x998, 16, 0x99C, 1),

	/* AHB3 peripherals */
	RST_DCMI  = _REG_BIT(0x9A0, 0, 0x9A4, 1),
	RST_CRYP2 = _REG_BIT(0x9A0, 4, 0x9A4, 1),
	RST_HASH2 = _REG_BIT(0x9A0, 5, 0x9A4, 1),
	RST_RNG2  = _REG_BIT(0x9A0, 6, 0x9A4, 1),
	RST_CRC2  = _REG_BIT(0x9A0, 7, 0x9A4, 1),
	RST_HSEM  = _REG_BIT(0x9A0, 11, 0x9A4, 1),
	RST_IPCC  = _REG_BIT(0x9A0, 12, 0x9A4, 1),

	/* AHB4 peripherals */
	RST_GPIOA = _REG_BIT(0x9A8, 0, 0x9AC, 1),
	RST_GPIOB = _REG_BIT(0x9A8, 1, 0x9AC, 1),
	RST_GPIOC = _REG_BIT(0x9A8, 2, 0x9AC, 1),
	RST_GPIOD = _REG_BIT(0x9A8, 3, 0x9AC, 1),
	RST_GPIOE = _REG_BIT(0x9A8, 4, 0x9AC, 1),
	RST_GPIOF = _REG_BIT(0x9A8, 5, 0x9AC, 1),
	RST_GPIOG = _REG_BIT(0x9A8, 6, 0x9AC, 1),
	RST_GPIOH = _REG_BIT(0x9A8, 7, 0x9AC, 1),
	RST_GPIOI = _REG_BIT(0x9A8, 8, 0x9AC, 1),
	RST_GPIOJ = _REG_BIT(0x9A8, 9, 0x9AC, 1),
	RST_GPIOK = _REG_BIT(0x9A8, 10, 0x9AC, 1),

	/* APB4 peripherals */
	RST_LTDC     = _REG_BIT(0x180, 0, 0x184, 1),
	RST_DSI      = _REG_BIT(0x180, 4, 0x184, 1),
	RST_DDRPERFM = _REG_BIT(0x180, 8, 0x184, 1),
	RST_USBPHY   = _REG_BIT(0x180, 16, 0x184, 1),

	/* APB5 peripherals */
	RST_SPI6   = _REG_BIT(0x188, 0, 0x18C, 1),
	RST_I2C4   = _REG_BIT(0x188, 2, 0x18C, 1),
	RST_I2C6   = _REG_BIT(0x188, 3, 0x18C, 1),
	RST_USART1 = _REG_BIT(0x188, 4, 0x18C, 1),
	RST_STGEN  = _REG_BIT(0x188, 20, 0x18C, 1),

	/* AHB5 peripherals */
	RST_GPIOZ   = _REG_BIT(0x190, 0, 0x194, 1),
	RST_CRYP1   = _REG_BIT(0x190, 4, 0x194, 1),
	RST_HASH1   = _REG_BIT(0x190, 5, 0x194, 1),
	RST_RNG1    = _REG_BIT(0x190, 6, 0x194, 1),
	RST_BKPSRAM = _REG_BIT(0x190, 8, 0x194, 1),

	/* AHB6 peripherals */
	RST_GPU    = _REG_BIT(0x198, 5, 0x19C, 1),
	RST_ETHMAC = _REG_BIT(0x198, 10, 0x19C, 1),
	RST_FMC    = _REG_BIT(0x198, 12, 0x19C, 1),
	RST_QSPI   = _REG_BIT(0x198, 14, 0x19C, 1),
	RST_SDMMC1 = _REG_BIT(0x198, 16, 0x19C, 1),
	RST_SDMMC2 = _REG_BIT(0x198, 17, 0x19C, 1),
	RST_CRC1   = _REG_BIT(0x198, 20, 0x19C, 1),
	RST_USBH   = _REG_BIT(0x198, 24, 0x19C, 1),
};
/**@}*/

#undef RCC_OFFSET_MASK
#undef RCC_BASE_LEN
#undef RCC_BIT_POS_LEN
#undef RCC_BIT_POS_MASK
#undef _REG_BIT

#include <libopencm3/stm32/common/rcc_common_all.h>
#endif
