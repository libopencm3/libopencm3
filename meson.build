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

project(
	'libopencm3',
	'c',
	default_options: [
		'c_std=c99',
		'warning_level=3',
		'b_ndebug=if-release',
	],
	version: '0.8.0',
	license: 'GPL-3.0-or-later OR BSD-3-Clause OR MIT',
)

# Ensure we are cross-compiling and not building for the build host
assert(meson.is_cross_build(), 'libopencm3 must be cross-compiled')

# Ensure we are using a GCC compiler
cc = meson.get_compiler('c')
assert(cc.get_id() == 'gcc', 'libopencm3 must be compiled with GCC')

# Project wide flags
extended_warnings = [
	'-Warith-conversion',
	'-Wbad-function-cast',
	# '-Wcast-align=strict',
	'-Wcast-function-type',
	# '-Wcast-qual',
	# '-Wconversion',
	'-Wdangling-else',
	'-Wdouble-promotion',
	'-Wduplicated-branches',
	'-Wfloat-conversion',
	'-Wformat-overflow=2',
	'-Wformat-signedness',
	'-Wformat-truncation',
	'-Wformat=2',
	'-Wimplicit-fallthrough',
	'-Wmaybe-uninitialized',
	'-Wmissing-attributes',
	'-Wmissing-braces',
	'-Wno-char-subscripts',
	'-Wnull-dereference',
	# '-Wpacked',
	'-Wredundant-decls',
	'-Wreturn-type',
	'-Wsequence-point',
	'-Wshadow=local',
	# '-Wsign-conversion',
	'-Wstack-protector',
	'-Wstrict-aliasing',
	'-Wstrict-overflow=2',
	'-Wstring-compare',
	'-Wstringop-overflow',
	'-Wunknown-pragmas',
	'-Wunsafe-loop-optimizations',
	'-Wunsuffixed-float-constants',
	'-Wunused-const-variable=2',
	'-Wunused-local-typedefs',
	'-Wunused',
	'-Wvla-parameter',
	# '-Wvla',
]
add_project_arguments(
	cc.get_supported_arguments(extended_warnings),
	language: 'c',
)

# Options controlling how object files are generated for linking
common_args = [
	'-ffunction-sections',
	'-fdata-sections',
]
add_project_arguments(
	common_args,
	language: 'c',
)

# Grab the IRQ -> nvic.h script and Python for the include system
python = import('python').find_installation()
irq2nvic = [
	python,
	files('scripts/irq2nvic_h'),
	'--builddir',
	meson.current_build_dir(),
]

# Extract what we're supposed to build for and start traversing to the appropriate library
target_platform = get_option('target')
subdir('include')
subdir('lib')
