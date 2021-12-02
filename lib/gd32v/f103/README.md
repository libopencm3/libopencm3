GD32VF103
=========

GD32V is a family of microcontrollers from GigaDevice. They combine
peripherals that seem to be mostly compatible with STM32 (and GD32 for that
matter) with a RISC-V core. That makes them a good candidate for working
well with libopencm3.

Differences from STM32F103
==========================

Most of the peripherals mimic the behavior of their STM32 counterparts,
typically STM32F103. Howerver, the register and device names used
throughout the
[GD datasheet](https://github.com/riscv-mcu/GD32VF103_DataSheets/raw/83802112/GD32VF103_User_Manual_EN_V1.0.pdf)
are annoyingly different. The libopencm3 drivers and API stick to the
naming that's already used accross the library.

CPU Core and Memory Map
-----------------------

The memory maps is mostly the same as on STM32F103. Some peripherals are
missing, others, described below, are different. RAM and Flash are mapped
at the same addresses -- 0x20000000 and 0x08000000 respectively. The Flash
is also aliased from address 0x00000000.

The RV32IMAC CPU core is called "Bumblebee" and is based on Nuclei N200.
It starts execution from the address 0x00000000 in the aliased Flash.
The first instruction just jumps to the real Flash range at 0x08000000.

The interrupt vector also starts at address 0x00000000. It is not practical
to put it elsewhere without the risk of wasting too much memory due to
weird alignment requirement it has. The first interrupt entry is reserved
so that it doesn't colide with the jump instruction that is there.

Clock Unit
----------

The clock configuration is similar to STM32F3 or GD32. The main clock can
be created from an external source, a crystal or internal RC oscillator,
either high or low speed.

The chip itself can run at 108 MHz, compared to 72 MHz of STM32F103. This
results in some slight differences; e.g. when creating the 48 MHz clock for
the USB FS unit.

Interrupt Controller
--------------------

Interrupt controller, called ECLIC, is entirely different from what's used
on chips with Cortex-M cores. The API for enabling the interrupts is
therefore also different, though the naming with NVIC references sometimes
stuck.

Only the bare minimum is currently implemented. The ECLIC is being used in
vectored mode, with the vector table largely resembling
one on Cortex-M cores.

The fancy features of the ECLIC such as the priorities, non-vectored mode
and tail chaining of the interrupts are currently not supported.

System Tick
-----------

The hardware is different. The clock value can't auto-reset after the
interrupt triggers and needs to be reset manually to start counting another
period.

USB OTG FS support
------------------

The USB core is capable of host and device mode, OTG support and full speed
opreation. It is the DWC controller that seems to be the same as is used on
STM32F7.


Building
========

riscv-\*-elf toolchains should work. The
[RISC-V GNU Toolchain](https://nucleisys.com/download.php) conveniently
provided by Nuclei works on Linux on x86\_64.

The target for the GD32VF103 is called `gd32v/f103`. For the time being, it
is not enabled by default and and you need to explicitly specify it on the
make command line:

    $ make TARGETS=gd32v/f103

A different toolchain can be used:

    $ make TARGETS=gd32v/f103 PREFIX=riscv-none-elf-

You can also build it alongside the other, ARM-based targets:

    $ make TARGETS='stm32/f1 gd32v/f103'

The toolchain can be specified per architecture:

    $ make TARGETS='stm32/f1 gd32v/f103' \
        RISCV_PREFIX=riscv-none-elf- \
        ARM_PREFIX=arm-none-elf-
