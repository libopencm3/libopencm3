This project is used as a demonstrator on how to run a small baremetal application
on a LM3S6965 board, which can be emulated on qemu as well (using qemu-system-arm
with -M lm3s6965evb).

For this reason, this application is not portable to other platforms at the moment.

To execute in qemu run:

`make qemu`

To debug using gcc run:

`make qemu-dbg`

and then attach a gdb to localhost tcp port 3333.

Requirements:
qemu-system-arm
openocd

