This project, inspired by [usbtest](http://www.linux-usb.org/usbtest/) and
the linux usb gadget zero driver is used for regression testing changes to the
libopencm3 usb stack.

The firmware itself is meant to be portable to any supported hardware, and then
identical unit test code is run against all platforms.  This project can and
should be built for multiple devices.

## Requirements:
 * [pyusb](https://walac.github.io/pyusb/) for running the tests. 
 * [openocd](http://openocd.org/) >= 0.9 for automated flashing of specific boards
 * python3 for running the tests at the command line.
 
### Example using virtual environments
```
pyvenv .env  # ensures a python3 virtual env
. .env/bin/activate
pip install pyusb
```

You _will_ need to modify the openocd config files, as they contain specific
serial numbers of programming hardware. You should set these up for the set of
available boards at your disposal.

Tests marked as @unittest.skip are either for functionality that is known to be
broken, and are awaiting code fixes, or are long running performance tests

## Running the tests
Below is an example of running the full suite of tests from the command line.
```
$ python -m unittest
.........ss..............
----------------------------------------------------------------------
Ran 25 tests in 0.381s

OK (skipped=2)
```

You can also run individual tests, or individual sets of tests, see the [unittest documentation](https://docs.python.org/3/library/unittest.html) for more information.

Many development environments, such as [PyCharm](https://www.jetbrains.com/pycharm/) can
also be used to edit and run the tests, in whole or individually, with a nice visual test runner.
