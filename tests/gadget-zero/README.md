This project, inspired by [usbtest](http://www.linux-usb.org/usbtest/) and
the linux usb gadget zero driver is used for regression testing changes to the
libopencm3 usb stack.

The firmware itself is meant to be portable to any supported hardware, and then
identical unit test code is run against all platforms.  This project can and
should be built for multiple devices.

Requirements:
pyusb for running the tests.
openocd >= 0.9 for automated flashing of specific boards
python3 for running the tests at the command line.

You _will_ need to modify the openocd config files, as they contain specific
serial numbers of programming hardware. You should set these up for the set of
available boards at your disposal.

Tests marked as @unittest.skip are either for functionality that is known to be
broken, and are awaiting code fixes, or are long running performance tests

An example of a successful test run:


