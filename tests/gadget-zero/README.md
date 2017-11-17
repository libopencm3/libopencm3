This project, inspired by [usbtest](http://www.linux-usb.org/usbtest/) and
the linux usb gadget zero driver is used for regression testing changes to the
libopencm3 usb stack.

The firmware itself is meant to be portable to any supported hardware, and then
identical unit test code is run against all platforms.  This project can and
should be built for multiple devices.

## Requirements:
 * [pyusb](https://walac.github.io/pyusb/) for running the tests. 
 * [OpenOCD](http://openocd.org/) >= 0.9 for automated flashing of specific boards
 * python3 for running the tests at the command line.

### Building the device firmware
There are Makefile.xxxxx files for all the currently tested targets.
```
make -f Makefile.stm32f4disco clean all V=1
```
The ```V=1``` is optional, and turns on verbose mode, which can be useful if
things don't work. This will give you a .elf file you can program using your
own toolchain, but if you have a functional OpenOCD installed, then...
```
make -f Makefile.stm32f4disco clean all flash
```
Will handle flashing as well.
 
### Setting up the test runner (using python virtual environments)
```
pyvenv .env  # ensures a python3 virtual env
. .env/bin/activate
pip install pyusb
```

If you have multiple test boards connected, have a look at opencd.common.cfg
for some tips on selectively matching the right board.  For people with just
a single matching board, you don't need to do anything.

Tests marked as @unittest.skip are either for functionality that is known to be
broken, and are awaiting code fixes, or are long running performance tests

### Access rights
On some systems (most linux systems) you probably won't have access to the
usb vendor id being used/hijacked by the test cases.  See 70-libopencm3.rules
for installation instructions, or, if you have your own system, grant yourself
access to the usb vid: 0xcafe

## Running the tests
Below is an example of running the full suite of tests from the command line.
The argument specifies the serial number to look for in the usb gadget, if
you have more than one.  No argument will the tests against all
gadget-zero's found.
```
$ python test_gadget0.py
Running tests for DUT:  stm32f072disco
.........ss................
----------------------------------------------------------------------
Ran 27 tests in 0.388s

OK (skipped=2)
```

To be even more brutal, run this in a shell loop.
```
$ while true; do python test_gadget0.py stm32f072disco; done
```

You can also run individual tests, or individual sets of tests, see the [unittest documentation](https://docs.python.org/3/library/unittest.html) for more information.

Many development environments, such as [PyCharm](https://www.jetbrains.com/pycharm/) can
also be used to edit and run the tests, in whole or individually, with a nice visual test runner.
