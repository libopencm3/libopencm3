# This file is part of the libopencm3 project.
#
# GD32F1x0 family library build. Source list mirrors lib/gd32/f1x0/Makefile:
# gd32-specific (flash/rcc), plus stm32/common reuses (adc_common_v1,
# gpio_common_f0234, rcc_common_all, …), plus stm32/f1's adc.c + i2c.c.

gd32f1x0_cm3 = declare_dependency(
	sources: cm3_sources,
	include_directories: cm3_includes,
	dependencies: gd32f1x0_vector_nvic,
)

# Sources specific to the GD32F1x0 series (live in this directory).
libgd32f1x0_sources = files(
	'flash.c',
	'rcc.c',
)

# stm32/f1 contributes adc.c + i2c.c — same as the make-path VPATH.
# These are referenced from outside their canonical subdir; meson lets
# us spell them with files('../../stm32/f1/adc.c').
libstm32_f1_adc_source = files('../../stm32/f1/adc.c')
libstm32_f1_i2c_source = files('../../stm32/f1/i2c.c')

libgd32f1x0_compile_args = [
	'-mcpu=cortex-m3',
	'-mthumb',
	'-DGD32F1X0',
]

libgd32f1x0 = static_library(
	'opencm3_gd32f1x0',
	[
		libgd32f1x0_sources,
		libstm32_f1_adc_source,
		libstm32_f1_i2c_source,
		# stm32/common contributions, in OBJ-list order.
		libstm32_flash_f01_sources,
		libstm32_gpio_f0234_sources,
		libstm32_iwdg_sources,
		libstm32_rcc_sources,
		libstm32_timer_f0234_sources,
		libstm32_dma_sources,
		libstm32_usart_v2_sources,
		libstm32_adc_v1_sources,
		libstm32_i2c_v1_sources,
	],
	c_args: libgd32f1x0_compile_args,
	include_directories: common_includes,
	implicit_include_directories: false,
	dependencies: [
		gd32f1x0_cm3,
	],
	pic: false,
)

opencm3_gd32f1x0 = declare_dependency(
	compile_args: libgd32f1x0_compile_args,
	include_directories: common_includes,
	link_with: libgd32f1x0,
	link_args: [
		f'-L@locm3_ld_script_path@',
	],
)

meson.override_dependency('opencm3_gd32f1x0', opencm3_gd32f1x0)
