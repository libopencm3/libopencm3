# This file is part of the libopencm3 project.
#
# Copyright (C) 2023 1BitSquared <info@1bitsquared.com>
# Written by Rachel Mant <git@dragonmux.network>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

libstm32_adc_v1_sources = files('adc_common_v1.c')
libstm32_adc_v1_multi_sources = [
	libstm32_adc_v1_sources,
	files('adc_common_v1_multi.c'),
]
libstm32_adc_v2_sources = files('adc_common_v2.c')
libstm32_adc_v2_multi_sources = [
	libstm32_adc_v2_sources,
	files('adc_common_v2_multi.c'),
]
libstm32_adc_f47_sources = files('adc_common_f47.c')
libstm32_crc_v1_sources = files('crc_common_all.c')
libstm32_crc_v2_sources = [
	libstm32_crc_v1_sources,
	files('crc_v2.c'),
]
libstm32_crs_sources = files('crs_common_all.c')
libstm32_crypto_f24_sources = files('crypto_common_f24.c')
libstm32_dac_sources = files('dac_common_all.c')
libstm32_dac_v1_sources = [
	libstm32_dac_sources,
	files('dac_common_v1.c'),
]
libstm32_dac_v2_sources = [
	libstm32_dac_sources,
	files('dac_common_v2.c'),
]
libstm32_dcmi_f47_sources = files('dcmi_common_f47.c')
libstm32_desig_sources = files('desig_common_all.c')
libstm32_desig_v1_sources = [
	libstm32_desig_sources,
	files('desig_common_v1.c'),
]
libstm32_dma_sources = files('dma_common_l1f013.c')
libstm32_dma_f24_sources = files('dma_common_f24.c')
libstm32_dma_csel_sources = [
	libstm32_dma_sources,
	files('dma_common_csel.c'),
]
libstm32_dma2d_f47_sources = files('dma2d_common_f47.c')
libstm32_dmamux_sources = files('dmamux.c')
libstm32_dsi_f47_sources = files('dsi_common_f47.c')
libstm32_exti_sources = files('exti_common_all.c')
libstm32_fdcan_sources = files('fdcan_common.c')
libstm32_flash_sources = files('flash_common_all.c')
libstm32_flash_f_sources = [
	libstm32_flash_sources,
	files('flash_common_f.c'),
]
libstm32_flash_f01_sources = [
	libstm32_flash_f_sources,
	files('flash_common_f01.c'),
]
libstm32_flash_f24_sources = [
	libstm32_flash_f_sources,
	files('flash_common_f24.c'),
]
libstm32_flash_idcache_sources = files('flash_common_idcache.c')
libstm32_fmc_f47_sources = files('fmc_common_f47.c')
libstm32_gpio_sources = files('gpio_common_all.c')
libstm32_gpio_f0234_sources = [
	libstm32_gpio_sources,
	files('gpio_common_f0234.c'),
]
libstm32_hash_f24_sources = files('hash_common_f24.c')
libstm32_iwdg_sources = files('iwdg_common_all.c')
libstm32_i2c_v1_sources = files('i2c_common_v1.c')
libstm32_i2c_v2_sources = files('i2c_common_v2.c')
libstm32_lptimer_sources = files('lptimer_common_all.c')
libstm32_ltdc_f47_sources = files('ltdc_common_f47.c')
libstm32_opamp_sources = files('opamp_common_all.c')
libstm32_opamp_v1_sources = [
	libstm32_opamp_sources,
	files('opamp_common_v1.c'),
]
libstm32_opamp_v2_sources = [
	libstm32_opamp_sources,
	files('opamp_common_v2.c'),
]
libstm32_pwr_v1_sources = files('pwr_common_v1.c')
libstm32_pwr_v2_sources = files('pwr_common_v2.c')
libstm32_qspi_v1_sources = files('quadspi_common_v1.c')
libstm32_rcc_sources = files('rcc_common_all.c')
libstm32_rng_v1_sources = files('rng_common_v1.c')
libstm32_rtc_l1f024_sources = files('rtc_common_l1f024.c')
libstm32_spi_sources = files('spi_common_all.c')
libstm32_spi_v1_sources = [
	libstm32_spi_sources,
	files('spi_common_v1.c'),
]
libstm32_spi_v1_frf_sources = [
	libstm32_spi_v1_sources,
	files('spi_common_v1_frf.c'),
]
libstm32_spi_v2_sources = [
	libstm32_spi_sources,
	files('spi_common_v2.c'),
]
libstm32_timer_sources = files('timer_common_all.c')
libstm32_timer_f0234_sources = [
	libstm32_timer_sources,
	files('timer_common_f0234.c'),
]
libstm32_timer_f24_sources = [
	libstm32_timer_f0234_sources,
	files('timer_common_f24.c'),
]
libstm32_usart_sources = files('usart_common_all.c')
libstm32_usart_f124_sources = [
	libstm32_usart_sources,
	files('usart_common_f124.c'),
]
libstm32_usart_v2_sources = [
	libstm32_usart_sources,
	files('usart_common_v2.c'),
]
libstm32_usart_fifos_sources = files('usart_common_fifos.c')

libstm32_usb_fs_sources = files('st_usbfs_core.c')
