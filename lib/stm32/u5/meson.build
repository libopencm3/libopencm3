# This file is part of the libopencm3 project.
#
# Copyright (C) 2025 1BitSquared <info@1bitsquared.com>
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

stm32u5_cm3 = declare_dependency(
	sources: cm3_sources,
	include_directories: cm3_includes,
	dependencies: stm32u5_vector_nvic,
)

# Sources specific to the H7 series
libstm32u5_sources = files(
	'dma.c',
	'adc.c',
	'flash.c',
	'pwr.c',
	'rcc.c',
	'spi.c',
	'timer.c',
)

libstm32u5_compile_args = [
	'-mfloat-abi=hard',
	'-mfpu=fpv5-sp-d16',
	'-mcpu=cortex-m33',
	'-mthumb',
	'-DSTM32U5',
]

# Build a static library for the target platform
libstm32u5 = static_library(
	'opencm3_stm32u5',
	[
		libstm32u5_sources,
		libstm32_adc_v2_multi_sources,
		libstm32_crs_sources,
		libstm32_exti_sources,
		libstm32_flash_sources,
		libstm32_gpio_f0234_sources,
		libstm32_i2c_v2_sources,
		libstm32_iwdg_sources,
		libstm32_rcc_sources,
		libstm32_timer_sources,
		libstm32_usart_v2_sources,
		usb_stm32_f107_sources,
		usb_stm32_f207_sources,
	],
	c_args: libstm32u5_compile_args,
	include_directories: common_includes,
	implicit_include_directories: false,
	dependencies: [
		stm32u5_cm3,
		usb_common,
		usb_stm32_dwc,
	],
	pic: false,
)

# Make the dependency available to use
libopencm3_stm32u5 = declare_dependency(
	compile_args: libstm32u5_compile_args,
	include_directories: common_includes,
	link_with: libstm32u5,
	link_args: [
		f'-L@locm3_ld_script_path@',
	],
)

meson.override_dependency('opencm3_stm32u5', libopencm3_stm32u5)
