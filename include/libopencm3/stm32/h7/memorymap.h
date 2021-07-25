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
#define FLASH_BASE          0x08000000U
#define PERIPH_BASE         0x40000000U
#define PERIPH_BASE_APB1    0x40000000U
#define PERIPH_BASE_APB2    0x40010000U
#define PERIPH_BASE_APB3    0x50000000U
#define PERIPH_BASE_AHB1    0x40020000U
#define PERIPH_BASE_AHB2    0x48020000U
#define PERIPH_BASE_AHB3    0x51000000U
#define PERIPH_BASE_AHB4    0x58000000U

/* Table 8: Register boundary addresses */

/* AHB4 Peripherals */
#define GPIO_PORT_A_BASE    0x58020000U
#define GPIO_PORT_B_BASE    0x58020400U
#define GPIO_PORT_C_BASE    0x58020800U
#define GPIO_PORT_D_BASE    0x58020C00U
#define GPIO_PORT_E_BASE    0x58021000U
#define GPIO_PORT_F_BASE    0x58021400U
#define GPIO_PORT_G_BASE    0x58021800U
#define GPIO_PORT_H_BASE    0x58021C00U
#define GPIO_PORT_I_BASE    0x58022000U
#define GPIO_PORT_J_BASE    0x58022400U
#define GPIO_PORT_K_BASE    0x58022800U
#define RCC_BASE            0x58024400U
#define POWER_CONTROL_BASE  0x58024800U
#define CRC_BASE            0x58024C00U
#define BDMA_BASE           0x58025400U
#define DMAMUX2_BASE        0x58025800U
#define ADC3_BASE           0x58026000U
#define HSEM_BASE           0x58026400U

/* APB4 Peripherals */
#define SAI4_BASE           0x58005400U
#define IWDG1_BASE          0x58004800U
#define RTC_BASE            0x58004000U
#define VREF_BASE           0x58003C00U
#define COMP1_BASE          0x58003800U
#define LPTIM5_BASE         0x58003000U
#define LPTIM4_BASE         0x58002C00U
#define LPTIM3_BASE         0x58002800U
#define LPTIM2_BASE         0x58002400U
#define I2C4_BASE           0x58001C00U
#define SPI6_BASE           0x58001400U
#define LPUART1_BASE        0x58000C00U
#define SYSCFG_BASE         0x58000400U
#define EXTI_BASE           0x58000000U

/* AHB3 Peripherals */
#define DELAY_SDMMC1_BASE   0x52008000U
#define SDMMC1_BASE         0x52007000U
#define DELAY_QSPI_BASE     0x52006000U
#define QUADSPI_BASE        0x52005000U
#define FMC_BASE            0x52004000U
#define JPEG_BASE           0x52003000U
#define FLASH_MEM_INTERFACE_BASE  0x52002000U
#define CHROMART_BASE       0x52001000U
#define MDMA_BASE           0x52000000U
#define GPV_BASE            0x51000000U

/* APB3 Peripherals */
#define WWDG1_BASE          0x50003000U
#define LTDC_BASE           0x50001000U

/* AHB2 Peripherals */
#define DELAY_SDMMC2_BASE   0x48022800U
#define SDMMC2_BASE         0x48022400U
#define RNG_BASE            0x48021800U
#define HASH_BASE           0x48021400U
#define CRYPTO_BASE         0x48021000U
#define DCMI_BASE           0x48020000U

/* AHB1 Peripherals */
#define USB2_OTG_FS_BASE    0x40080000U
#define USB1_OTG_HS_BASE    0x40040000U
#define ETHERNET_MAC_BASE   0x40028000U
#define ADC1_ADC2_BASE      0x40022000U
#define DMAMUX1_BASE        0x40020800U
#define DMA2_BASE           0x40020400U
#define DMA1_BASE           0x40020000U

/* APB2 Peripherals */
#define HRTIM_BASE          0x40017400U
#define DFSDM1_BASE         0x40017000U
#define SAI3_BASE           0x40016000U
#define SAI2_BASE           0x40015C00U
#define SAI1_BASE           0x40015800U
#define SPI5_BASE           0x40015000U
#define TIM17_BASE          0x40014800U
#define TIM16_BASE          0x40014400U
#define TIM15_BASE          0x40014000U
#define SPI4_BASE           0x40013400U
#define SPI1_BASE           0x40013000U
#define USART6_BASE         0x40011400U
#define USART1_BASE         0x40011000U
#define TIM8_BASE           0x40010400U
#define TIM1_BASE           0x40010000U

/* APB1 Peripherals */
#define CAN_MSG_BASE        0x4000AC00U
#define CAN_CCU_BASE        0x4000A800U
#define FDCAN2_BASE         0x4000A400U
#define FDCAN1_BASE         0x4000A000U
#define MDIOS_BASE          0x40009400U
#define OPAMP_BASE          0x40009000U
#define SWPMI_BASE          0x40008800U
#define CRS_BASE            0x40008400U
#define UART8_BASE          0x40007C00U
#define UART7_BASE          0x40007800U
#define DAC_BASE            0x40007400U
#define HDMI_CEC_BASE       0x40006C00U
#define I2C3_BASE           0x40005C00U
#define I2C2_BASE           0x40005800U
#define I2C1_BASE           0x40005400U
#define UART5_BASE          0x40005000U
#define UART4_BASE          0x40004C00U
#define USART3_BASE         0x40004800U
#define USART2_BASE         0x40004400U
#define SPDIFRX1_BASE       0x40004000U
#define SPI3_BASE           0x40003C00U
#define SPI2_BASE           0x40003800U
#define LPTIM1_BASE         0x40002400U
#define TIM14_BASE          0x40002000U
#define TIM13_BASE          0x40001C00U
#define TIM12_BASE          0x40001800U
#define TIM7_BASE           0x40001400U
#define TIM6_BASE           0x40001000U
#define TIM5_BASE           0x40000C00U
#define TIM4_BASE           0x40000800U
#define TIM3_BASE           0x40000400U
#define TIM2_BASE           0x40000000U

/* Debug/Trace Peripherals */
#define DBGMCU_BASE         0x5C001000U

#endif
