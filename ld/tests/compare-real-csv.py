#!/usr/bin/env python3
"""
Runs the linker script generator portion against a csv of "correct" device properties to check for regexp madness.
"""

import argparse
import csv
import dataclasses

import genlink


@dataclasses.dataclass
class InputDevice:
    name: str
    ram: str
    flash: str


def domain(opts):
    fi = csv.DictReader(filter(lambda row: row[0]!='#', opts.input))
    idevs = [InputDevice(name=row['name'], ram=row['ram'], flash=row['flash']) for row in fi]
    good_count = 0
    for idev in idevs:
        print(f"checking: {idev.name}")
        x = genlink.get_device_data(opts.devices_data, idev.name, exit_on_fail=False)
        if not x:
            print(f"Failed to match: {idev.name}")
            continue
        xram: str = [lol for lol in x["defs"] if lol[0] == "RAM"][0][1]
        xrom: str = [lol for lol in x["defs"] if lol[0] == "ROM"][0][1]
        assert(xram.lower() == idev.ram.lower())
        assert(xrom.lower() == idev.flash.lower())
        good_count += 1
        print(f"Validated {idev.name} with flash: {idev.flash} and ram: {idev.name}")

    assert(good_count == len(idevs))


def get_parser():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("-d", "--devices_data", help="devices.data file to check against", required=True)
    parser.add_argument("-i", "--input", help="csv input file to check against", type=argparse.FileType('r'), required=True)
    return parser


if __name__ == "__main__":
    p = get_parser()
    opts = p.parse_args()
    domain(opts)

