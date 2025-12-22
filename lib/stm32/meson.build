# This file is part of the libopencm3 project.
#
# Copyright (C) 2023-2024 1BitSquared <info@1bitsquared.com>
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

# Bring in all the common STM32 definitions
subdir('common')

# Sources specific to STM32 parts
libstm32_can_sources = files('can.c')
# Sources for the USB FS peripherals
libstm32_usb_fs_v1_sources = files('st_usbfs_v1.c')
libstm32_usb_fs_v2_sources = files('st_usbfs_v2.c')

# Define a dependency for each generation of USB FS peripheral
libstm32_usb_fs_v1 = declare_dependency(
	sources: [libstm32_usb_fs_sources, libstm32_usb_fs_v1_sources]
)

libstm32_usb_fs_v2 = declare_dependency(
	sources: [libstm32_usb_fs_sources, libstm32_usb_fs_v2_sources]
)

# Mapping of target platform names to subdirs
subdirs = {
	'stm32f0': 'f0',
	'stm32f1': 'f1',
	'stm32f3': 'f3',
	'stm32f4': 'f4',
	'stm32f7': 'f7',
	'stm32h7': 'h7',
	'stm32l4': 'l4',
}

# Bring in the proper target subdir for the requested target platform
if target_platform != 'all'
	subdir(subdirs[target_platform])
else
	foreach subdir_name, subdir_path : subdirs
		subdir(subdir_path)
	endforeach
endif
