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

# Sources common to all USB implementations
usb_common_sources = files(
	# Base USB implementation
	'usb.c',
	'usb_control.c',
	'usb_standard.c',
	# Descriptor extension implementations
	'usb_bos.c',
	'usb_microsoft.c',
	# Specific protocol implementations
	'usb_audio.c',
	'usb_cdc.c',
	'usb_hid.c',
	'usb_midi.c',
	'usb_msc.c',
)

# Platform-specific USB sources, gruped by peripheral family
usb_efm32_sources = files('usb_efm32.c')
usb_efm32hg_sources = files('usb_efm32hg.c')
usb_stm32_dwc_sources = files('usb_dwc_common.c')
usb_stm32_f107_sources = files('usb_f107.c')
usb_stm32_f207_sources = files('usb_f207.c')
usb_lm4f_sources = files('usb_lm4f.c')

usb_includes = include_directories('..')

# Define a dependency for the common part
usb_common = declare_dependency(
	sources: usb_common_sources,
	include_directories: usb_includes,
)

# Define a dependency for the DWC peripheral
usb_stm32_dwc = declare_dependency(
	sources: usb_stm32_dwc_sources,
	dependencies: usb_common
)
