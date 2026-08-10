# This file is part of the libopencm3 project.
#
# Generates the GD32F1x0 NVIC header + vector_nvic.c source via the
# irq2nvic_h script (same shape as the stm32 family meson.builds).

gd32f1x0_nvic_header = custom_target(
	'nvic.h',
	command: [irq2nvic, '@INPUT@'],
	input: 'irq.json',
	# This script writes three files; we only name one of them as the
	# meson output (the rest are tracked via path conventions):
	# - include/libopencm3/gd32/f1x0/nvic.h
	# - lib/gd32/f1x0/vector_nvic.c
	# - include/libopencmsis/gd32/f1x0/irqhandlers.h
	output: 'nvic.h',
	install: false,
)

gd32f1x0_vector_nvic = declare_dependency(
	sources: gd32f1x0_nvic_header,
)
