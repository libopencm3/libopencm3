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

stm32g4_cm3 = declare_dependency(
	sources: cm3_sources,
	include_directories: cm3_includes,
	dependencies: stm32g4_vector_nvic,
)

# Sources specific to the G4 series
libstm32g4_sources = files(
	'adc.c',
	'fdcan.c',
	'flash.c',
	'pwr.c',
	'rcc.c',
	#'vector_chipset.c', # This source is included by lib/dispatch/vector_chipset.c
)

libstm32g4_compile_args = [
	'-mcpu=cortex-m4',
	'-mthumb',
	'-mfloat-abi=hard',
	'-mfpu=fpv4-sp-d16',
	'-DSTM32G4',
]

# Build a static library for the target platform
libstm32g4 = static_library(
	'opencm3_stm32g4',
	[
		libstm32g4_sources,
		libstm32_adc_v2_multi_sources,
		libstm32_cordic_v1_sources,
		libstm32_crs_sources,
		libstm32_crc_v2_sources,
		libstm32_dac_v2_sources,
		libstm32_desig_v1_sources,
		libstm32_dma_sources,
		libstm32_dmamux_sources,
		libstm32_exti_sources,
		libstm32_fdcan_sources,
		libstm32_flash_f_sources,
		libstm32_flash_idcache_sources,
		libstm32_gpio_f0234_sources,
		libstm32_i2c_v2_sources,
		libstm32_iwdg_sources,
		libstm32_opamp_v2_sources,
		libstm32_qspi_v1_sources,
		libstm32_rcc_sources,
		libstm32_rng_v1_sources,
		libstm32_spi_v2_sources,
		libstm32_timer_f0234_sources,
		libstm32_usart_fifos_sources,
		libstm32_usart_v2_sources,
	],
	c_args: libstm32g4_compile_args,
	include_directories: common_includes,
	implicit_include_directories: false,
	dependencies: [
		stm32g4_cm3,
		usb_common,
		libstm32_usb_fs_v2,
	],
	pic: false,
)

# Make the dependency available to use
opencm3_stm32g4 = declare_dependency(
	compile_args: libstm32g4_compile_args,
	include_directories: common_includes,
	link_with: libstm32g4,
	link_args: [
		f'-L@locm3_ld_script_path@',
	],
)

meson.override_dependency('opencm3_stm32g4', opencm3_stm32g4)
