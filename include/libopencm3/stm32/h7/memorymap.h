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

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- STM32H7 specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define FLASH_BASE          (0x08000000U)
#define PERIPH_BASE         (0x40000000U)
#define SYSTEM_MEM_BASE     (0x1ff00000U)
#define PERIPH_BASE_APB1    (PERIPH_BASE + 0x00000000U)
#define PERIPH_BASE_APB2    (PERIPH_BASE + 0x00010000U)
#define PERIPH_BASE_APB3    (PERIPH_BASE + 0x10000000U)
#define PERIPH_BASE_APB4    (PERIPH_BASE + 0x18000000U)
#define PERIPH_BASE_AHB1    (PERIPH_BASE + 0x00020000U)
#define PERIPH_BASE_AHB2    (PERIPH_BASE + 0x08020000U)
#define PERIPH_BASE_AHB3    (PERIPH_BASE + 0x11000000U)
#define PERIPH_BASE_AHB4    (PERIPH_BASE + 0x18020000U)

/* Table 8: Register boundary addresses */

/* AHB4 Peripherals */
#define GPIO_PORT_A_BASE    (PERIPH_BASE_AHB4 + 0x0000U)
#define GPIO_PORT_B_BASE    (PERIPH_BASE_AHB4 + 0x0400U)
#define GPIO_PORT_C_BASE    (PERIPH_BASE_AHB4 + 0x0800U)
#define GPIO_PORT_D_BASE    (PERIPH_BASE_AHB4 + 0x0C00U)
#define GPIO_PORT_E_BASE    (PERIPH_BASE_AHB4 + 0x1000U)
#define GPIO_PORT_F_BASE    (PERIPH_BASE_AHB4 + 0x1400U)
#define GPIO_PORT_G_BASE    (PERIPH_BASE_AHB4 + 0x1800U)
#define GPIO_PORT_H_BASE    (PERIPH_BASE_AHB4 + 0x1C00U)
#define GPIO_PORT_I_BASE    (PERIPH_BASE_AHB4 + 0x2000U)
#define GPIO_PORT_J_BASE    (PERIPH_BASE_AHB4 + 0x2400U)
#define GPIO_PORT_K_BASE    (PERIPH_BASE_AHB4 + 0x2800U)
#define RCC_BASE            (PERIPH_BASE_AHB4 + 0x4400U)
#define POWER_CONTROL_BASE  (PERIPH_BASE_AHB4 + 0x4800U)
#define CRC_BASE            (PERIPH_BASE_AHB4 + 0x4C00U)
#define BDMA_BASE           (PERIPH_BASE_AHB4 + 0x5400U)
#define DMAMUX2_BASE        (PERIPH_BASE_AHB4 + 0x5800U)
#define ADC3_BASE           (PERIPH_BASE_AHB4 + 0x6000U)
#define HSEM_BASE           (PERIPH_BASE_AHB4 + 0x6400U)

/* APB4 Peripherals */
#define EXTI_BASE           (PERIPH_BASE_APB4 + 0x0000U)
#define SYSCFG_BASE         (PERIPH_BASE_APB4 + 0x0400U)
#define LPUART1_BASE        (PERIPH_BASE_APB4 + 0x0C00U)
#define SPI6_BASE           (PERIPH_BASE_APB4 + 0x1400U)
#define I2S6_BASE           (PERIPH_BASE_APB4 + 0x1400U)
#define I2C4_BASE           (PERIPH_BASE_APB4 + 0x1C00U)
#define LPTIM2_BASE         (PERIPH_BASE_APB4 + 0x2400U)
#define LPTIM3_BASE         (PERIPH_BASE_APB4 + 0x2800U)
#define LPTIM4_BASE         (PERIPH_BASE_APB4 + 0x2C00U)
#define LPTIM5_BASE         (PERIPH_BASE_APB4 + 0x3000U)
#define COMP1_BASE          (PERIPH_BASE_APB4 + 0x3800U)
#define COMP2_BASE          (PERIPH_BASE_APB4 + 0x3800U)
#define VREF_BASE           (PERIPH_BASE_APB4 + 0x3C00U)
#define RTC_BASE            (PERIPH_BASE_APB4 + 0x4000U)
#define IWDG1_BASE          (PERIPH_BASE_APB4 + 0x4800U)
#define SAI4_BASE           (PERIPH_BASE_APB4 + 0x5400U)
#define DTS_BASE            (PERIPH_BASE_APB4 + 0x6800U)

/* AHB3 Peripherals */
#define GPV_BASE            (PERIPH_BASE_AHB3 + 0x00000000U)
#define MDMA_BASE           (PERIPH_BASE_AHB3 + 0x01000000U)
#define CHROMART_BASE       (PERIPH_BASE_AHB3 + 0x01001000U)
#define FLASH_MEM_INTERFACE_BASE (PERIPH_BASE_AHB3 + 0x01002000U)
#define JPEG_BASE           (PERIPH_BASE_AHB3 + 0x01003000U)
#define FMC_BASE            (PERIPH_BASE_AHB3 + 0x01004000U)
#define QUADSPI1_BASE       (PERIPH_BASE_AHB3 + 0x01005000U)
#define DELAY_QSPI1_BASE    (PERIPH_BASE_AHB3 + 0x01006000U)
#define SDMMC1_BASE         (PERIPH_BASE_AHB3 + 0x01007000U)
#define DELAY_SDMMC1_BASE   (PERIPH_BASE_AHB3 + 0x01008000U)
#define RAMECC_D1_BASE      (PERIPH_BASE_AHB3 + 0x01009000U)
#define QUADSPI2_BASE       (PERIPH_BASE_AHB3 + 0x0100A000U)
#define DELAY_QSPI2_BASE    (PERIPH_BASE_AHB3 + 0x0100B000U)
#define QSPI_IO_BASE        (PERIPH_BASE_AHB3 + 0x0100B400U)
#define OTFDEC1_BASE        (PERIPH_BASE_AHB3 + 0x0100B800U)
#define OTFDEC2_BASE        (PERIPH_BASE_AHB3 + 0x0100BC00U)

/* APB3 Peripherals */
#define LTDC_BASE           (PERIPH_BASE_APB3 + 0x1000U)
#define WWDG1_BASE          (PERIPH_BASE_APB3 + 0x3000U)

/* AHB2 Peripherals */
#define DCMI_BASE           (PERIPH_BASE_AHB2 + 0x0000U)
#define PSSI_BASE           (PERIPH_BASE_AHB2 + 0x0400U)
#define CRYPTO_BASE         (PERIPH_BASE_AHB2 + 0x1000U)
#define HASH_BASE           (PERIPH_BASE_AHB2 + 0x1400U)
#define RNG_BASE            (PERIPH_BASE_AHB2 + 0x1800U)
#define SDMMC2_BASE         (PERIPH_BASE_AHB2 + 0x2400U)
#define DELAY_SDMMC2_BASE   (PERIPH_BASE_AHB2 + 0x2800U)
#define RAMECC_D2_BASE      (PERIPH_BASE_AHB2 + 0x3000U)
#define FMAC_BASE           (PERIPH_BASE_AHB2 + 0x4000U)
#define CORDIC_BASE         (PERIPH_BASE_AHB2 + 0x4400U)

/* AHB1 Peripherals */
#define DMA1_BASE           (PERIPH_BASE_AHB1 + 0x0000U)
#define DMA2_BASE           (PERIPH_BASE_AHB1 + 0x0400U)
#define DMAMUX1_BASE        (PERIPH_BASE_AHB1 + 0x0800U)
#define ADC1_ADC2_BASE      (PERIPH_BASE_AHB1 + 0x2000U)
#define ETHERNET_MAC_BASE   (PERIPH_BASE_AHB1 + 0x8000U)
#define USB1_OTG_HS_BASE    (PERIPH_BASE_AHB1 + 0x00020000U)
#define USB2_OTG_FS_BASE    (PERIPH_BASE_AHB1 + 0x00060000U)

/* APB2 Peripherals */
#define TIM1_BASE           (PERIPH_BASE_APB2 + 0x0000U)
#define TIM8_BASE           (PERIPH_BASE_APB2 + 0x0400U)
#define USART1_BASE         (PERIPH_BASE_APB2 + 0x1000U)
#define USART6_BASE         (PERIPH_BASE_APB2 + 0x1400U)
#define UART9_BASE          (PERIPH_BASE_APB2 + 0x1800U)
#define USART10_BASE        (PERIPH_BASE_APB2 + 0x1C00U)
#define SPI1_BASE           (PERIPH_BASE_APB2 + 0x3000U)
#define I2S1_BASE           (PERIPH_BASE_APB2 + 0x3000U)
#define SPI4_BASE           (PERIPH_BASE_APB2 + 0x3400U)
#define TIM15_BASE          (PERIPH_BASE_APB2 + 0x4000U)
#define TIM16_BASE          (PERIPH_BASE_APB2 + 0x4400U)
#define TIM17_BASE          (PERIPH_BASE_APB2 + 0x4800U)
#define SPI5_BASE           (PERIPH_BASE_APB2 + 0x5000U)
#define SAI1_BASE           (PERIPH_BASE_APB2 + 0x5800U)
#define SAI2_BASE           (PERIPH_BASE_APB2 + 0x5C00U)
#define SAI3_BASE           (PERIPH_BASE_APB2 + 0x6000U)
#define DFSDM2_BASE         (PERIPH_BASE_APB2 + 0x7000U)
#define HRTIM_BASE          (PERIPH_BASE_APB2 + 0x7400U)
#define DFSDM1_BASE         (PERIPH_BASE_APB2 + 0x7800U)

/* APB1 Peripherals */
#define TIM2_BASE           (PERIPH_BASE_APB1 + 0x0000U)
#define TIM3_BASE           (PERIPH_BASE_APB1 + 0x0400U)
#define TIM4_BASE           (PERIPH_BASE_APB1 + 0x0800U)
#define TIM5_BASE           (PERIPH_BASE_APB1 + 0x0C00U)
#define TIM6_BASE           (PERIPH_BASE_APB1 + 0x1000U)
#define TIM7_BASE           (PERIPH_BASE_APB1 + 0x1400U)
#define TIM12_BASE          (PERIPH_BASE_APB1 + 0x1800U)
#define TIM13_BASE          (PERIPH_BASE_APB1 + 0x1C00U)
#define TIM14_BASE          (PERIPH_BASE_APB1 + 0x2000U)
#define LPTIM1_BASE         (PERIPH_BASE_APB1 + 0x2400U)
#define SPI2_BASE           (PERIPH_BASE_APB1 + 0x3800U)
#define I2S2_BASE           (PERIPH_BASE_APB1 + 0x3800U)
#define SPI3_BASE           (PERIPH_BASE_APB1 + 0x3C00U)
#define I2S3_BASE           (PERIPH_BASE_APB1 + 0x3C00U)
#define SPDIFRX1_BASE       (PERIPH_BASE_APB1 + 0x4000U)
#define USART2_BASE         (PERIPH_BASE_APB1 + 0x4400U)
#define USART3_BASE         (PERIPH_BASE_APB1 + 0x4800U)
#define UART4_BASE          (PERIPH_BASE_APB1 + 0x4C00U)
#define UART5_BASE          (PERIPH_BASE_APB1 + 0x5000U)
#define I2C1_BASE           (PERIPH_BASE_APB1 + 0x5400U)
#define I2C2_BASE           (PERIPH_BASE_APB1 + 0x5800U)
#define I2C3_BASE           (PERIPH_BASE_APB1 + 0x5C00U)
#define I2C5_BASE           (PERIPH_BASE_APB1 + 0x6400U)
#define HDMI_CEC_BASE       (PERIPH_BASE_APB1 + 0x6C00U)
#define DAC1_DAC2_BASE      (PERIPH_BASE_APB1 + 0x7400U)
#define UART7_BASE          (PERIPH_BASE_APB1 + 0x7800U)
#define UART8_BASE          (PERIPH_BASE_APB1 + 0x7C00U)
#define CRS_BASE            (PERIPH_BASE_APB1 + 0x8400U)
#define SWPMI_BASE          (PERIPH_BASE_APB1 + 0x8800U)
#define OPAMP_BASE          (PERIPH_BASE_APB1 + 0x9000U)
#define MDIOS_BASE          (PERIPH_BASE_APB1 + 0x9400U)
#define FDCAN1_BASE         (PERIPH_BASE_APB1 + 0xA000U)
#define FDCAN2_BASE         (PERIPH_BASE_APB1 + 0xA400U)
#define CAN_CCU_BASE        (PERIPH_BASE_APB1 + 0xA800U)
#define CAN_MSG_BASE        (PERIPH_BASE_APB1 + 0xAC00U)
#define FDCAN3_BASE         (PERIPH_BASE_APB1 + 0xD400U)
#define TIM23_BASE          (PERIPH_BASE_APB1 + 0xE000U)
#define TIM24_BASE          (PERIPH_BASE_APB1 + 0xE400U)

/* Debug/Trace Peripherals */
#define DBGMCU_BASE         0x5C001000U

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE (SYSTEM_MEM_BASE + 0x1E880U)
#define DESIG_UNIQUE_ID_BASE  (SYSTEM_MEM_BASE + 0x1E800U)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 8)

/* These aren't strictly memory map, but they need to be visible everywhere like the memory map */

/* Device variant constants */
enum device_variant {
	STM32H72x = 0x483U, /* RM0468 */
	STM32H74x = 0x450U, /* RM0433, RM0399 */
	STM32H7Bx = 0x480U, /* RM0455 */
};

#endif /*LIBOPENCM3_MEMORYMAP_H*/
