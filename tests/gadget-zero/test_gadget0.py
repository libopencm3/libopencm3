#!/usr/bin/env python3
"""
Tests for the libopencm3 USB stack.  Uses pyusb to make a variety of transfers, both legal and illegal to
exercise as many paths of the stack as possible for consistency and functionality.

By default, will attempt to run the test suite against any detected compatible firmware, based on a fixed
VID:PID pair defined in the firmware.  Can also be told to test just a single device

Requires pyusb.  unittest-xml-reporting also required for xUnit reports
"""
import argparse
import array
import datetime
import random
import usb.core
import usb.util as uu
import random
import sys

import unittest

VENDOR_ID=0xcafe
PRODUCT_ID=0xcafe

# you only need to worry about these if you are trying to explicitly test
# a single target.  Normally, the test will autofind the attached target
DUT_SERIAL=None
#DUT_SERIAL = "stm32f429i-disco"
#DUT_SERIAL = "stm32f4disco"
#DUT_SERIAL = "stm32f103-generic"
#DUT_SERIAL = "stm32l1-generic"
#DUT_SERIAL = "stm32f072disco"
#DUT_SERIAL = "stm32l053disco"

GZ_REQ_SET_PATTERN=1
GZ_REQ_PRODUCE=2
GZ_REQ_SET_ALIGNED=3
GZ_REQ_SET_UNALIGNED=4
GZ_REQ_WRITE_LOOPBACK_BUFFER=10
GZ_REQ_READ_LOOPBACK_BUFFER=11
GZ_REQ_INTEL_WRITE=0x5b
GZ_REQ_INTEL_READ=0x5c

class find_by_serial(object):
    def __init__(self, serial):
        self._serial = serial

    def __call__(self, device):
        return usb.util.get_string(device, device.iSerialNumber)


class TestGadget0(unittest.TestCase):
    # TODO - parameterize this with serial numbers so we can find
    # gadget 0 code for different devices.  (or use different PIDs?)
    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")
        self.longMessage = True

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def test_sanity(self):
        self.assertEqual(2, self.dev.bNumConfigurations, "Should have 2 configs")

    def test_config_switch_2(self):
        """
        Uses the API if you're interested in the cfg block
        """
        cfg = uu.find_descriptor(self.dev, bConfigurationValue=2)
        self.assertIsNotNone(cfg, "Config 2 should exist")
        self.dev.set_configuration(cfg)

    def test_config_switch_3(self):
        """
        Uses the simple API
        """
        self.dev.set_configuration(3)

    def test_config_zero_addressed(self):
        self.dev.set_configuration(0)
        x = self.dev.ctrl_transfer(0x80, 0x08, 0, 0, 1)
        self.assertEqual(0, x[0], "Should be configuration 0 before configuration is set")


    def test_fetch_config(self):
        self.dev.set_configuration(3)
        # FIXME - find a way to get the defines for these from pyusb
        x = self.dev.ctrl_transfer(0x80, 0x08, 0, 0, 1)
        self.assertEqual(3, x[0], "Should get the actual bConfigurationValue back")

    def test_invalid_config(self):
        try:
            # FIXME - find a way to get the defines for these from pyusb
            self.dev.ctrl_transfer(0x00, 0x09, 99)
            self.fail("Request of invalid cfg should have failed")
        except usb.core.USBError as e:
            # Note, this might not be as portable as we'd like.
            self.assertIn("Pipe", e.strerror)

class TestIntelCompliance(unittest.TestCase):
    """
    Part of intel's usb 2.0 compliance is writing and reading back control transfers
    """
    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")

        self.cfg = uu.find_descriptor(self.dev, bConfigurationValue=2)
        self.assertIsNotNone(self.cfg, "Config 2 should exist")
        self.dev.set_configuration(self.cfg)

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def inner_t(self, mylen):
        data = [random.randrange(255) for x in range(mylen)]
        written = self.dev.ctrl_transfer(uu.CTRL_OUT | uu.CTRL_RECIPIENT_INTERFACE | uu.CTRL_TYPE_VENDOR, GZ_REQ_INTEL_WRITE, 0, 0, data)
        self.assertEqual(written, len(data), "Should have written all bytes plz")
        # now. in _theory_ I should be able to make a bulk transfer here and have it not "interfere"
        # fixme - try this out?
        read = self.dev.ctrl_transfer(uu.CTRL_IN | uu.CTRL_RECIPIENT_INTERFACE | uu.CTRL_TYPE_VENDOR, GZ_REQ_INTEL_READ, 0, 0, mylen)
        self.assertEqual(mylen, len(read))
        expected = array.array('B', [x for x in data])
        self.assertEqual(expected, read, "should have read back what we wrote")

    def test_ctrl_loopbacks(self):
        self.inner_t(0)
        self.inner_t(10)
        self.inner_t(63)
        self.inner_t(64)
        self.inner_t(65)
        self.inner_t(140)
        self.inner_t(183)


class TestConfigSourceSink(unittest.TestCase):
    """
    We could inherit, but it doesn't save much, and this saves me from remembering how to call super.
    """

    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")

        self.cfg = uu.find_descriptor(self.dev, bConfigurationValue=2)
        self.assertIsNotNone(self.cfg, "Config 2 should exist")
        self.dev.set_configuration(self.cfg)
        self.intf = self.cfg[(0, 0)]
        # heh, kinda gross...
        self.ep_out = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_OUT][0]
        self.ep_in = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_IN][0]

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def test_write_simple(self):
        """
        here we go, start off with just a simple write of < bMaxPacketSize and just make sure it's accepted
        :return:
        """
        data = [x for x in range(int(self.ep_out.wMaxPacketSize / 2))]
        written = self.dev.write(self.ep_out, data)
        self.assertEqual(written, len(data), "Should have written all bytes plz")

    def test_write_zlp(self):
        written = self.ep_out.write([])
        self.assertEqual(0, written, "should have written zero for a zero length write y0")

    def test_write_batch(self):
        """
        Write 50 max sized packets.  Should not stall.  Will stall if firmware isn't consuming data properly
        :return:
        """
        for i in range(50):
            data = [x for x in range(int(self.ep_out.wMaxPacketSize))]
            written = self.dev.write(self.ep_out, data)
            self.assertEqual(written, len(data), "Should have written all bytes plz")

    def test_write_mixed(self):
        for i in range(int(self.ep_out.wMaxPacketSize / 4), self.ep_out.wMaxPacketSize * 10, 11):
            data = [x & 0xff for x in range(i)]
            written = self.ep_out.write(data)
            self.assertEqual(written, len(data), "should have written all bytes plz")

    def test_read_zeros(self):
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 0)
        self.ep_in.read(self.ep_in.wMaxPacketSize)  # Clear out any prior pattern data
        # unless, you know _exactly_ how much will be written by the device, always read
        # an integer multiple of max packet size, to avoid overflows.
        # the returned data will have the actual length.
        # You can't just magically read out less than the device wrote.
        read_size = self.ep_in.wMaxPacketSize * 10
        data = self.dev.read(self.ep_in, read_size)
        self.assertEqual(len(data), read_size, "Should have read as much as we asked for")
        expected = array.array('B', [0 for x in range(read_size)])
        self.assertEqual(data, expected, "In pattern 0, all source data should be zeros: ")

    def test_read_sequence(self):
        # switching to the mod63 pattern requires resynching carefully to read out any zero frames already
        # queued, but still make sure we start the sequence at zero.
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 1)
        self.ep_in.read(self.ep_in.wMaxPacketSize)  # Potentially queued zeros, or would have been safe.
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 1)
        self.ep_in.read(self.ep_in.wMaxPacketSize)  # definitely right pattern now, but need to restart at zero.
        read_size = self.ep_in.wMaxPacketSize * 3
        data = self.dev.read(self.ep_in, read_size)
        self.assertEqual(len(data), read_size, "Should have read as much as we asked for")
        expected = array.array('B', [x % 63 for x in range(read_size)])
        self.assertEqual(data, expected, "In pattern 1, Should be % 63")

    def test_read_write_interleaved(self):
        for i in range(1, 20):
            ii = self.ep_in.read(self.ep_in.wMaxPacketSize * i)
            dd = [x & 0xff for x in range(i * 20 + 3)]
            oo = self.ep_out.write(dd)
            self.assertEqual(len(ii), self.ep_in.wMaxPacketSize * i, "should have read full packet")
            self.assertEqual(oo, len(dd), "should have written full packet")

    def test_control_known(self):
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 0)
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 1)
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 99)
        self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, GZ_REQ_SET_PATTERN, 0)

    def test_control_unknown(self):
        try:
            self.dev.ctrl_transfer(uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE, 42, 69)
            self.fail("Should have got a stall")
        except usb.core.USBError as e:
            # Note, this might not be as portable as we'd like.
            self.assertIn("Pipe", e.strerror)


class TestConfigLoopBack(unittest.TestCase):
    """
    We could inherit, but it doesn't save much, and this saves me from remembering how to call super.
    """

    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")

        self.cfg = uu.find_descriptor(self.dev, bConfigurationValue=3)
        self.assertIsNotNone(self.cfg, "Config 3 should exist")
        self.dev.set_configuration(self.cfg)
        self.intf = self.cfg[(0, 0)]
        # heh, kinda gross...
        self.eps_out = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_OUT]
        self.eps_in = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_IN]

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def _inner_basic(self, ep_out, ep_in, data):
        written = self.dev.write(ep_out, data)
        self.assertEqual(written, len(data), "Should have written all bytes plz")
        read = self.dev.read(ep_in, len(data))
        self.assertEqual(len(data), len(read))
        expected = array.array('B', [x for x in data])
        self.assertEqual(expected, read, "should have read back what we wrote")


    def test_simple_loop(self):
        """Plain simple loopback, does it work at all"""
        eout = self.eps_out[0]
        ein = self.eps_in[0]
        data = [random.randrange(255) for _ in range(eout.wMaxPacketSize)]
        self._inner_basic(eout, ein, data)

    def test_dual_loop(self):
        """Testing that we don't mix our data up, just plain and simple"""
        dlen = self.eps_out[0].wMaxPacketSize
        data = [
            [0xaa for _ in range(dlen)],
            [0xbb for _ in range(dlen)],
        ]
        for epo, epi, data in zip(self.eps_out, self.eps_in, data):
            self._inner_basic(epo, epi, data)

    def test_dual_loop_back_to_back(self):
        """
        write to both, _before_ we read back...
        This can expose problems with buffer management
        """
        dlen = self.eps_out[0].wMaxPacketSize
        data = [
            [0xaa for _ in range(dlen)],
            [0xbb for _ in range(dlen)],
        ]
        written = [
            self.dev.write(self.eps_out[0], data[0]),
            self.dev.write(self.eps_out[1], data[1]),
        ]
        read = [
            self.dev.read(self.eps_in[0], dlen),
            self.dev.read(self.eps_in[1], dlen),
        ]

        for w, r, dat in zip(written, read, data):
            self.assertEqual(w, len(dat), "Should have written all bytes plz")
            self.assertEqual(len(dat), len(r), "Should have read back same size")
            expected = array.array('B', [x for x in dat])
            self.assertEqual(expected, r, "should have read back what we wrote")


@unittest.skip("Perf tests only on demand (comment this line!)")
class TestConfigSourceSinkPerformance(unittest.TestCase):
    """
    Read/write throughput, roughly
    """

    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")

        self.cfg = uu.find_descriptor(self.dev, bConfigurationValue=2)
        self.assertIsNotNone(self.cfg, "Config 2 should exist")
        self.dev.set_configuration(self.cfg)
        self.intf = self.cfg[(0, 0)]
        # heh, kinda gross...
        self.ep_out = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_OUT][0]
        self.ep_in = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_IN][0]

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def tput(self, xc, te):
        return (xc / 1024 / max(1, te.seconds + te.microseconds /
                                1000000.0))

    def test_read_perf(self):
        # I get around 990kps here...
        ts = datetime.datetime.now()
        rxc = 0
        while rxc < 5 * 1024 * 1024:
            desired = 100 * 1024
            data = self.ep_in.read(desired, timeout=0)
            self.assertEqual(desired, len(data), "Should have read all bytes plz")
            rxc += len(data)
        te = datetime.datetime.now() - ts
        print("read %s bytes in %s for %s kps" % (rxc, te, self.tput(rxc, te)))

    def test_write_perf(self):
        # caps out around 420kps?
        ts = datetime.datetime.now()
        txc = 0
        data = [x & 0xff for x in range(100 * 1024)]
        while txc < 5 * 1024 * 1024:
            w = self.ep_out.write(data, timeout=0)
            self.assertEqual(w, len(data), "Should have written all bytes plz")
            txc += w
        te = datetime.datetime.now() - ts
        print("wrote %s bytes in %s for %s kps" % (txc, te, self.tput(txc, te)))


class TestControlTransfer_Reads(unittest.TestCase):
    """
    https://github.com/libopencm3/libopencm3/pull/194
    and
    https://github.com/libopencm3/libopencm3/pull/505
    """

    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")

        self.cfg = uu.find_descriptor(self.dev, bConfigurationValue=2)
        self.assertIsNotNone(self.cfg, "Config 2 should exist")
        self.dev.set_configuration(self.cfg)
        self.req = uu.CTRL_IN | uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE

    def inner_t(self, wVal, read_len):
        wVal = int(wVal)
        read_len = int(read_len)
        q = self.dev.ctrl_transfer(self.req, GZ_REQ_PRODUCE, wVal, 0, read_len)
        self.assertEqual(len(q), wVal, "Should have read as much as we asked for?")

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def test_basic(self):
        x = self.dev.ctrl_transfer(self.req, GZ_REQ_PRODUCE, 32, 0, 32)
        self.assertEqual(32, len(x))

    def test_matching_sizes(self):
        """
        Can we request x control in when we tell the device to produce x?
        :return:
        """
        def inner(x):
            x = int(x)
            q = self.dev.ctrl_transfer(self.req, GZ_REQ_PRODUCE, x, 0, x)
            self.assertEqual(len(q), x, "Should have read as much as we asked for")

        ep0_size = self.dev.bMaxPacketSize0
        inner(ep0_size)
        inner(ep0_size * 3)
        inner(ep0_size / 3)
        inner(ep0_size - 7)
        inner(ep0_size + 11)
        inner(ep0_size * 4 + 11)

    def test_waytoobig(self):
        """
        monster reads should fail, but not fatally.
        (Don't make them too, big, or libusb will reject you outright, see MAX_CTRL_BUFFER_LENGTH in libusb sources)
        """
        try:
            self.dev.ctrl_transfer(self.req, GZ_REQ_PRODUCE, 10 * self.dev.bMaxPacketSize0, 0, 10 * self.dev.bMaxPacketSize0)
            self.fail("Should have got a stall")
        except usb.core.USBError as e:
            # Note, this might not be as portable as we'd like.
            self.assertIn("Pipe", e.strerror)

    def test_read_longer(self):
        """
        Attempt to read more than the device replied with.
        This is explicitly allowed by spec:
        "On an input request, a device must never return more data than is indicated
        by the wLength value; it may return less"
        """

        ep0_size = self.dev.bMaxPacketSize0
        self.inner_t(ep0_size / 2, ep0_size)
        self.inner_t(ep0_size / 2, ep0_size * 2)
        self.inner_t(ep0_size + 31, ep0_size * 5)

    def test_read_needs_zlp(self):
        ep0_size = self.dev.bMaxPacketSize0
        self.inner_t(ep0_size, ep0_size + 10)
        self.inner_t(ep0_size * 2, ep0_size * 5)

    def test_read_zero(self):
        """
        try and read > 0, but have the device only produce 0
        """
        self.inner_t(0, self.dev.bMaxPacketSize0)
        self.inner_t(0, 200)

    def test_read_nothing(self):
        """
        Don't read anything, don't create anything (no data stage)
        """
        self.inner_t(0, 0)

    def test_mean_limits(self):
        """
        tell the device to produce more than we ask for.
        Note, this doesn't test the usb stack, it tests the application code behaves.
        """
        q = self.dev.ctrl_transfer(self.req, GZ_REQ_PRODUCE, 100, 0, 10)
        self.assertEqual(len(q), 10, "In this case, should have gotten wLen back")


class TestUnaligned(unittest.TestCase):
    """
    M0 and M0+ cores don't support unaligned memory accesses. These test
    how the stack behaves with aligned vs unaligned buffers.
    https://github.com/libopencm3/libopencm3/issues/401
    https://github.com/libopencm3/libopencm3/issues/461
    """

    def setUp(self):
        self.dev = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, custom_match=find_by_serial(DUT_SERIAL))
        self.assertIsNotNone(self.dev, "Couldn't find locm3 gadget0 device")

        self.cfg = uu.find_descriptor(self.dev, bConfigurationValue=2)
        self.assertIsNotNone(self.cfg, "Config 2 should exist")
        self.dev.set_configuration(self.cfg);
        self.req = uu.CTRL_OUT | uu.CTRL_TYPE_VENDOR | uu.CTRL_RECIPIENT_INTERFACE
        self.intf = self.cfg[(0, 0)]
        # heh, kinda gross...
        self.ep_out = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_OUT][0]
        self.ep_in = [ep for ep in self.intf if uu.endpoint_direction(ep.bEndpointAddress) == uu.ENDPOINT_IN][0]

    def tearDown(self):
        uu.dispose_resources(self.dev)

    def set_unaligned(self):
        # GZ_REQ_SET_UNALIGNED
        self.dev.ctrl_transfer(self.req, GZ_REQ_SET_UNALIGNED, 0, 0)

    def set_aligned(self):
        # GZ_REQ_SET_ALIGNED
        self.dev.ctrl_transfer(self.req, GZ_REQ_SET_ALIGNED, 0, 0)

    def do_readwrite(self):
        """
        transfer garbage data to/from bulk EP; alignment issues will hardfault the target
        """
        data = [x for x in range(int(self.ep_out.wMaxPacketSize / 2))]
        written = self.dev.write(self.ep_out, data)
        self.assertEqual(written, len(data), "Should have written all bytes plz")

        read_size = self.ep_in.wMaxPacketSize * 10
        data = self.dev.read(self.ep_in, read_size)
        self.assertEqual(len(data), read_size, "Should have read as much as we asked for")

    def test_aligned(self):
        self.set_aligned()
        self.do_readwrite()

    def test_unaligned(self):
        self.set_unaligned()
        self.do_readwrite()


def run_ci_test(dut):
    # Avoids the import for non-CI users!
    import xmlrunner
    print("Running (CI) tests for DUT: ", dut)
    #with open("TEST-%s.xml" % dut, 'wb') as output:
    unittest.main(exit=False, argv=[__file__], testRunner=xmlrunner.XMLTestRunner(output="tests/test-%s" % dut))

def run_user_test(dut):
    print("Running (user) tests for DUT: ", dut)
    unittest.main(exit=False, argv=[__file__])

def get_parser():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("-d", "--dut", help="Specify a particular DUT serial to test")
    parser.add_argument("-X", "--xunit", help="Write xml 'junit' style outputs, intended for CI use", action="store_true")
    parser.add_argument("-l", "--list", help="List all detected matching devices, but don't run any tests", action="store_true")
    return parser

if __name__ == "__main__":
    p = get_parser()
    opts = p.parse_args()
    runner = run_user_test
    if opts.xunit:
        runner = run_ci_test

    if opts.dut:
        runner(opts.dut)
    else:
        # scan for available and try them all!
        devs = usb.core.find(idVendor=VENDOR_ID, idProduct=PRODUCT_ID, find_all=True)
        for dev in devs:
            DUT_SERIAL = dev.serial_number
            if opts.list:
                print("Detected %s on bus:port-address: %s:%s-%s" % (DUT_SERIAL, dev.bus, '.'.join(map(str,dev.port_numbers)), dev.address))
            else:
                runner(DUT_SERIAL)

