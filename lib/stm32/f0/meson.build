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

stm32f0_cm3 = declare_dependency(
	sources: cm3_sources,
	include_directories: cm3_includes,
	dependencies: stm32f0_vector_nvic,
)

# Sources specific to the F0 series
libstm32f0_sources = files(
	'adc.c',
	'comparator.c',
	'flash.c',
	#'i2c.c', # XXX: This source is unused for some reason
	'rcc.c',
	#'syscfg.c', # XXX: This source is unused for some reason
)

libstm32f0_compile_args = [
	'-mcpu=cortex-m0',
	'-mthumb',
	'-DSTM32F0',
]

# Build a static library for the target platform
libstm32f0 = static_library(
	'opencm3_stm32f0',
	[
		libstm32f0_sources,
		libstm32_adc_v2_sources,
		libstm32_crc_v2_sources,
		libstm32_crs_sources,
		libstm32_dac_v1_sources,
		libstm32_desig_v1_sources,
		libstm32_dma_csel_sources,
		libstm32_exti_sources,
		libstm32_flash_f01_sources,
		libstm32_gpio_f0234_sources,
		libstm32_iwdg_sources,
		libstm32_i2c_v2_sources,
		libstm32_pwr_v1_sources,
		libstm32_rcc_sources,
		libstm32_rtc_l1f024_sources,
		libstm32_spi_v2_sources,
		libstm32_timer_f0234_sources,
		libstm32_usart_v2_sources,
		libstm32_can_sources,
	],
	c_args: libstm32f0_compile_args,
	include_directories: common_includes,
	implicit_include_directories: false,
	dependencies: [
		stm32f0_cm3,
		usb_common,
		libstm32_usb_fs_v2,
	],
	pic: false,
)

# Make the dependency available to use
opencm3_stm32f0 = declare_dependency(
	compile_args: libstm32f0_compile_args,
	include_directories: common_includes,
	link_with: libstm32f0,
	link_args: [
		f'-L@locm3_ld_script_path@',
	],
)

meson.override_dependency('opencm3_stm32f0', opencm3_stm32f0)
