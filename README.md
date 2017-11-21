README
======
[![Build Status](https://travis-ci.org/libopencm3/libopencm3.svg?branch=master)](https://travis-ci.org/libopencm3/libopencm3)

[![Gitter channel](https://badges.gitter.im/libopencm3/discuss.svg)](https://gitter.im/libopencm3/discuss)

The libopencm3 project aims to create an open-source firmware library for
various ARM Cortex-M microcontrollers.

Currently (at least partly) supported microcontrollers:

 - ST STM32F0xx/F1xx/F2xx/F30x/F37x/F4xx/F7xx/L0xx/L1xx/L4xx series
 - Atmel SAM3A/3N/3S/3U/3X series, as well as SAMDxx and friends
 - NXP LPC1311/13/17/42/43
 - Stellaris LM3S series (discontinued, without replacement)
 - TI (Tiva) LM4F series (continuing as TM4F, pin and peripheral compatible)
 - EFM32 Gecko series (only core support)
 - Freescale Vybrid VF6xx

The library is written completely from scratch based on the vendor datasheets,
programming manuals, and application notes. The code is meant to be used
with a GCC toolchain for ARM (arm-elf or arm-none-eabi), flashing of the
code to a microcontroller can be done using the OpenOCD ARM JTAG software.


Status and API
--------------

The libopencm3 project is currently work in progress. Not all subsystems
of the microcontrollers are supported, yet.

**IMPORTANT**: The API of the library is _NOT_ yet considered stable! Please do
           not rely on it, yet! Changes to function names, macro names, etc.
           can happen at any time without prior notice!

_TIP_: Include this repository as a Git submodule in your project to make sure
     your users get the right version of the library to compile your project.
     For how that can be done refer to the libopencm3-examples repository.

Prerequisites
-------------

Building requires Python (Some code is generated).

**For Ubuntu/Fedora:**

 - An arm-none-eabi/arm-elf toolchain.

**For Windows:**

 Download and install:

 - msys - http://sourceforge.net/projects/mingw/files/MSYS/Base/msys-core/msys-1.0.11/MSYS-1.0.11.exe
 - Python - http://www.python.org/ftp/python/2.7/python-2.7.msi (any 2.7 release)
 - arm-none-eabi/arm-elf toolchain (for example this one https://launchpad.net/gcc-arm-embedded)

Run msys shell and set the path without standard Windows paths, so Windows programs such as 'find' won't interfere:

    export PATH="/c//Python27:/c/ARMToolchain/bin:/usr/local/bin:/usr/bin:/bin"

After that you can navigate to the folder where you've extracted libopencm3 and build it.

Toolchain
---------

The most heavily tested toolchain is "gcc-arm-embedded"
https://launchpad.net/gcc-arm-embedded

Other toolchains _should_ work, but they have not been nearly as well tested.
Toolchains targeting Linux, such as "gcc-arm-linux-gnu" or the like are
_not_ appropriate.

_NOTE_ We recommend that you use gcc-arm-embedded version 4.8 2014q3 or newer
to build all platforms covered by libopencm3 successfully.

Building
--------

    $ make

If you have an arm-elf toolchain (uncommon) you may want to override the
toolchain prefix (arm-none-eabi is the default)

    $ PREFIX=arm-elf make

For a more verbose build you can use

    $ make V=1

Fine-tuning the build
---------------------

The build may be fine-tuned with a limited number of parameters, by specifying
them as environment variables, for example:

    $ VARIABLE=value make

* `FP_FLAGS` - Control the floating-point ABI

   If the Cortex-M core supports a hard float ABI, it will be compiled with
   the best floating-point support by default. In cases where this is not desired, the
   behavior can be specified by setting `FP_FLAGS`.
   
   Currently, M4F cores default to `-mfloat-abi=hard -mfpu=fpv4-sp-d16`, and
   M7 cores defaults to double precision `-mfloat-abi=hard -mfpu=fpv5-d16` if available,
   and single precision `-mfloat-abi=hard -mfpu=fpv5-sp-d16` otherwise.
   Other architectures use no FP flags, in otherwords, traditional softfp.
   
   You may find which FP_FLAGS you can use in a particular architecture in the readme.txt 
   file shipped with the gcc-arm-embedded package.

   Examples:

        $ FP_FLAGS="-mfloat-abi=soft" make               # No hardfloat
        $ FP_FLAGS="-mfloat-abi=hard -mfpu=magic" make   # New FPU we don't know of

* `CFLAGS` - Add to or supersede compiler flags

   If the library needs to be compiled with additional flags, they can be
   passed to the build system via the environment variable `CFLAGS`. The
   contents of `CFLAGS` will be placed after all flags defined by the build
   system, giving the user a way to override any default if necessary.

   Examples:

        $ CFLAGS="-fshort-wchar" make    # Compile lib with 2 byte wide wchar_t

Example projects
----------------

The libopencm3 community has written and is maintaining a huge collection of
examples, displaying the capabilities and uses of the library. You can find all
of them in the libopencm3-examples repository:

https://github.com/libopencm3/libopencm3-examples

Installation
------------

Simply pass -I and -L flags to your own project.  See the libopencm3-examples
repository for an example of using this library as a Git submodule, the most
popular method of use.

It is strongly advised that you do not attempt to install this library to any
path inside your toolchain itself.  While this means you don't have to include
any `-I` or `-L` flags in your projects, it is _very_ easy to confuse a multi-library
linker from picking the right versions of libraries.  Common symptoms are
hardfaults caused by branches into ARM code.  You can use `arm-none-eabi-objdump`
to check for this in your final ELF file.  You have been warned.

Coding style and development guidelines
---------------------------------------

See HACKING.


License
-------

The libopencm3 code is released under the terms of the GNU Lesser General
Public License (LGPL), version 3 or later.

See COPYING.GPL3 and COPYING.LGPL3 for details.

Community
---------

 * Our [![Gitter channel](https://badges.gitter.im/libopencm3/discuss.svg)](https://gitter.im/libopencm3/discuss)
 * Our IRC channel on the freenode IRC network is called #libopencm3

Mailing lists
-------------

 * Developer mailing list (for patches and discussions):
   https://lists.sourceforge.net/lists/listinfo/libopencm3-devel

 * Commits mailing list (receives one mail per `git push`):
   https://lists.sourceforge.net/lists/listinfo/libopencm3-commits


Website
-------

 * http://libopencm3.org
 * http://sourceforge.net/projects/libopencm3/

