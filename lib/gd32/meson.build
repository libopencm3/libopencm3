# This file is part of the libopencm3 project.
#
# GD32 family dispatcher. Maps the target_platform option to the proper
# per-family subdir (mirrors lib/stm32/meson.build's pattern). GD32
# parts reuse a lot of the STM32 register layout — see lib/meson.build
# for where stm32/common is pulled in.

subdirs = {
	'gd32f1x0': 'f1x0',
}

if target_platform != 'all'
	if subdirs.has_key(target_platform)
		subdir(subdirs[target_platform])
	endif
else
	foreach subdir_name, subdir_path : subdirs
		subdir(subdir_path)
	endforeach
endif
