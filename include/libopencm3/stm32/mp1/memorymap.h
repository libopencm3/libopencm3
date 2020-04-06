/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

/* --- STM32MP1 specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define PERIPH1_BASE                    (0x40000000U)
#define PERIPH_BASE_APB1                (PERIPH1_BASE + 0x00000000)
#define PERIPH_BASE_APB2                (PERIPH1_BASE + 0x04000000)
#define PERIPH_BASE_AHB2                (PERIPH1_BASE + 0x08000000)
#define PERIPH_BASE_AHB3                (PERIPH1_BASE + 0x0c000000)
#define PERIPH2_BASE                    (0x50000000U)
#define PERIPH_BASE_AHB4                (PERIPH2_BASE + 0x00000000)
#define PERIPH_BASE_APB3                (PERIPH2_BASE + 0x00020000)
#define PERIPH_BASE_APB_DBG             (PERIPH2_BASE + 0x00080000)
#define PERIPH_BASE_AHB5                (PERIPH2_BASE + 0x04000000)
#define PERIPH_BASE_AHB6                (PERIPH2_BASE + 0x08000000)
#define PERIPH_BASE_APB4                (PERIPH2_BASE + 0x0a000000)
#define PERIPH_BASE_APB5                (PERIPH2_BASE + 0x0c000000)

/* Register boundary addresses */

/* APB1 */
#define TIM2_BASE                       (PERIPH_BASE_APB1 + 0x00000)
#define TIM3_BASE                       (PERIPH_BASE_APB1 + 0x01000)
#define TIM4_BASE                       (PERIPH_BASE_APB1 + 0x02000)
#define TIM5_BASE                       (PERIPH_BASE_APB1 + 0x03000)
#define TIM6_BASE                       (PERIPH_BASE_APB1 + 0x04000)
#define TIM7_BASE                       (PERIPH_BASE_APB1 + 0x05000)
#define TIM12_BASE                      (PERIPH_BASE_APB1 + 0x06000)
#define TIM13_BASE                      (PERIPH_BASE_APB1 + 0x07000)
#define TIM14_BASE                      (PERIPH_BASE_APB1 + 0x08000)
#define LPTIM1_BASE                     (PERIPH_BASE_APB1 + 0x09000)
#define WWDG_BASE                       (PERIPH_BASE_APB1 + 0x0a000)
#define SPI2_BASE                       (PERIPH_BASE_APB1 + 0x0b000)
#define SPI3_BASE                       (PERIPH_BASE_APB1 + 0x0c000)
#define SPDIFRX_BASE                    (PERIPH_BASE_APB1 + 0x0d000)
#define USART2_BASE                     (PERIPH_BASE_APB1 + 0x0e000)
#define USART3_BASE                     (PERIPH_BASE_APB1 + 0x0f000)
#define UART4_BASE                      (PERIPH_BASE_APB1 + 0x10000)
#define UART5_BASE                      (PERIPH_BASE_APB1 + 0x11000)
#define I2C1_BASE                       (PERIPH_BASE_APB1 + 0x12000)
#define I2C2_BASE                       (PERIPH_BASE_APB1 + 0x13000)
#define I2C3_BASE                       (PERIPH_BASE_APB1 + 0x14000)
#define I2C5_BASE                       (PERIPH_BASE_APB1 + 0x15000)
#define CEC_BASE                        (PERIPH_BASE_APB1 + 0x16000)
#define DAC_BASE                        (PERIPH_BASE_APB1 + 0x17000)
#define UART7_BASE                      (PERIPH_BASE_APB1 + 0x18000)
#define UART8_BASE                      (PERIPH_BASE_APB1 + 0x19000)
#define MDIOS_BASE                      (PERIPH_BASE_APB1 + 0x1c000)

/* APB2 */
#define TIM1_BASE                       (PERIPH_BASE_APB2 + 0x00000)
#define TIM8_BASE                       (PERIPH_BASE_APB2 + 0x01000)
#define USART6_BASE                     (PERIPH_BASE_APB2 + 0x03000)
#define SPI1_BASE                       (PERIPH_BASE_APB2 + 0x04000)
#define SPI4_BASE                       (PERIPH_BASE_APB2 + 0x05000)
#define TIM15_BASE                      (PERIPH_BASE_APB2 + 0x06000)
#define TIM16_BASE                      (PERIPH_BASE_APB2 + 0x07000)
#define TIM17_BASE                      (PERIPH_BASE_APB2 + 0x08000)
#define SPI5_BASE                       (PERIPH_BASE_APB2 + 0x09000)
#define SAI1_BASE                       (PERIPH_BASE_APB2 + 0x0a000)
#define SAI2_BASE                       (PERIPH_BASE_APB2 + 0x0b000)
#define SAI3_BASE                       (PERIPH_BASE_APB2 + 0x0c000)
#define DFSDM1_BASE                     (PERIPH_BASE_APB2 + 0x0d000)
#define FDCAN1_BASE                     (PERIPH_BASE_APB2 + 0x0e000)
#define FDCAN2_BASE                     (PERIPH_BASE_APB2 + 0x0f000)
#define CAN_CCU_BASE                    (PERIPH_BASE_APB2 + 0x10000)
#define CAN_SRAM_BASE                   (PERIPH_BASE_APB2 + 0x11000)

/* AHB2 */
#define DMA1_BASE                       (PERIPH_BASE_AHB2 + 0x00000)
#define DMA2_BASE                       (PERIPH_BASE_AHB2 + 0x01000)
#define DMAMUX_BASE                     (PERIPH_BASE_AHB2 + 0x02000)
#define ADC12_BASE                      (PERIPH_BASE_AHB2 + 0x03000)
#define ADC1_BASE                       (ADC12_BASE + 0x000)
#define ADC2_BASE                       (ADC12_BASE + 0x100)
#define ADC_CMN_BASE                    (ADC12_BASE + 0x300)
#define SDMMC3_BASE                     (PERIPH_BASE_AHB2 + 0x04000)
#define DLYBSD3_BASE                    (PERIPH_BASE_AHB2 + 0x05000)
#define USB_OTG_BASE                    (PERIPH_BASE_AHB2 + 0x01000000)

/* AHB3 */
#define HSEM_BASE                       (PERIPH_BASE_AHB3 + 0x0000)
#define IPCC_BASE                       (PERIPH_BASE_AHB3 + 0x1000)
#define HASH2_BASE                      (PERIPH_BASE_AHB3 + 0x2000)
#define RNG2_BASE                       (PERIPH_BASE_AHB3 + 0x3000)
#define CRC2_BASE                       (PERIPH_BASE_AHB3 + 0x4000)
#define CRYP2_BASE                      (PERIPH_BASE_AHB3 + 0x5000)
#define DCMI_BASE                       (PERIPH_BASE_AHB3 + 0x6000)

/* AHB4 */
#define RCC_BASE                        (PERIPH_BASE_AHB4 + 0x0000)
#define PWR_BASE                        (PERIPH_BASE_AHB4 + 0x1000)
#define GPIO_PORT_A_BASE                (PERIPH_BASE_AHB4 + 0x2000)
#define GPIO_PORT_B_BASE                (PERIPH_BASE_AHB4 + 0x3000)
#define GPIO_PORT_C_BASE                (PERIPH_BASE_AHB4 + 0x4000)
#define GPIO_PORT_D_BASE                (PERIPH_BASE_AHB4 + 0x5000)
#define GPIO_PORT_E_BASE                (PERIPH_BASE_AHB4 + 0x6000)
#define GPIO_PORT_F_BASE                (PERIPH_BASE_AHB4 + 0x7000)
#define GPIO_PORT_G_BASE                (PERIPH_BASE_AHB4 + 0x8000)
#define GPIO_PORT_H_BASE                (PERIPH_BASE_AHB4 + 0x9000)
#define GPIO_PORT_I_BASE                (PERIPH_BASE_AHB4 + 0xa000)
#define GPIO_PORT_J_BASE                (PERIPH_BASE_AHB4 + 0xb000)
#define GPIO_PORT_K_BASE                (PERIPH_BASE_AHB4 + 0xc000)
#define EXTI_BASE                       (PERIPH_BASE_AHB4 + 0xd000)

/* APB3 */
#define SYSCFG_BASE                     (PERIPH_BASE_APB3 + 0x0000)
#define LPTIM2_BASE                     (PERIPH_BASE_APB3 + 0x1000)
#define LPTIM3_BASE                     (PERIPH_BASE_APB3 + 0x2000)
#define LPTIM4_BASE                     (PERIPH_BASE_APB3 + 0x3000)
#define LPTIM5_BASE                     (PERIPH_BASE_APB3 + 0x4000)
#define VREFBUF_BASE                    (PERIPH_BASE_APB3 + 0x5000)
#define SAI4_BASE                       (PERIPH_BASE_APB3 + 0x7000)
#define DTS_BASE                        (PERIPH_BASE_APB3 + 0x8000)
#define HDP_BASE                        (PERIPH_BASE_APB3 + 0xa000)

/* AHB5 */
#define BKPSRAM_BASE                    (PERIPH_BASE_AHB5 + 0x0000)
#define CRYP1_BASE                      (PERIPH_BASE_AHB5 + 0x1000)
#define HASH1_BASE                      (PERIPH_BASE_AHB5 + 0x2000)
#define RNG1_BASE                       (PERIPH_BASE_AHB5 + 0x3000)
#define GPIO_PORT_Z_BASE                (PERIPH_BASE_AHB5 + 0x4000)

/* AXIM */
#define AXIMC_BASE                      (PERIPH2_BASE + 0x07000000)

/* AHB6 */
#define MDMA_BASE                       (PERIPH_BASE_AHB6 + 0x0000)
#define FMC_BASE                        (PERIPH_BASE_AHB6 + 0x2000)
#define QUAD_SPI_BASE                   (PERIPH_BASE_AHB6 + 0x3000)
#define DLYBQS_BASE                     (PERIPH_BASE_AHB6 + 0x4000)
#define SDMMC1_BASE                     (PERIPH_BASE_AHB6 + 0x5000)
#define DLYBSD1_BASE                    (PERIPH_BASE_AHB6 + 0x6000)
#define SDMMC2_BASE                     (PERIPH_BASE_AHB6 + 0x7000)
#define DLYBSD2_BASE                    (PERIPH_BASE_AHB6 + 0x8000)
#define CRC1_BASE                       (PERIPH_BASE_AHB6 + 0x9000)
#define ETHERNET_BASE                   (PERIPH_BASE_AHB6 + 0xa000)
#define USBH_OHCI_BASE                  (PERIPH_BASE_AHB6 + 0xc000)
#define USBH_EHCI_BASE                  (PERIPH_BASE_AHB6 + 0xd000)
#define GPU_BASE                        (PERIPH_BASE_AHB6 + 0x01000000)

/* APB4 */
#define DSI_BASE                        (PERIPH_BASE_APB4 + 0x0000)
#define LTDC_BASE                       (PERIPH_BASE_APB4 + 0x1000)
#define IWDG2_BASE                      (PERIPH_BASE_APB4 + 0x2000)
#define DDRCTRL_BASE                    (PERIPH_BASE_APB4 + 0x3000)
#define DDRPHYC_BASE                    (PERIPH_BASE_APB4 + 0x4000)
#define STGENR_BASE                     (PERIPH_BASE_APB4 + 0x5000)
#define USBPHYC_BASE                    (PERIPH_BASE_APB4 + 0x6000)
#define DDRPERFM_BASE                   (PERIPH_BASE_APB4 + 0x7000)

/* APB5 */
#define USART1_BASE                     (PERIPH_BASE_APB5 + 0x0000)
#define SPI6_BASE                       (PERIPH_BASE_APB5 + 0x1000)
#define I2C4_BASE                       (PERIPH_BASE_APB5 + 0x2000)
#define IWDG1_BASE                      (PERIPH_BASE_APB5 + 0x3000)
#define RTC_BASE                        (PERIPH_BASE_APB5 + 0x4000)
#define BSEC_BASE                       (PERIPH_BASE_APB5 + 0x5000)
#define TZC_BASE                        (PERIPH_BASE_APB5 + 0x6000)
#define ETZPC_BASE                      (PERIPH_BASE_APB5 + 0x7000)
#define STGENC_BASE                     (PERIPH_BASE_APB5 + 0x8000)
#define I2C6_BASE                       (PERIPH_BASE_APB5 + 0x9000)
#define TAMP_BASE                       (PERIPH_BASE_APB5 + 0xa000)

/* Device Electronic Signature */
#define DESIG_UNIQUE_ID_BASE            (BSEC_BASE + 0x234)
#define DESIG_UNIQUE_ID0                MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1                MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2                MMIO32(DESIG_UNIQUE_ID_BASE + 8)

#endif
