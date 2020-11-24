#!/usr/bin/env python3
# This python program generates parameters for the linker script generator feature.

# This file is part of the libopencm3 project.
#
# 2017 George-Cristian Jiglau <noonien>
#
# This library is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library. If not, see <http://www.gnu.org/licenses/>.
from __future__ import print_function
import fnmatch
import sys
import re
import os

if len(sys.argv) != 4:
    print("usage: %s <device-data-file> <device> <mode>" % sys.argv[0], file=sys.stderr)
    sys.exit(1)

data_file_path = sys.argv[1]
find = sys.argv[2].lower()
mode = sys.argv[3].upper()

device = {
    'info': {},
    'defs': [],
    'family': [],
}

# open device data file
with open(data_file_path, 'r') as data_file:
    # iterate lines
    for line in data_file:
        # strip whitespace from the beginning and end of line
        line = line.strip()

        # skip empty lines and comments
        if line == '' or line.startswith('#'):
            continue

        # split line into it's parts: <pattern> <parent> <data..>
        parts = line.split()
        pattern, parent, data = parts[0], parts[1], parts[2:]

        # skip line if pattern did not match first element
        if not fnmatch.fnmatch(find, pattern):
            continue

        # extract data
        for d in data:
            # split into K=V
            try:
                (k, v) = d.split('=')
            except:
                continue

            # skip invalid datas
            if not re.match('^[A-Z0-9_]+$', k):
                continue

            # add FPU and CPU to info, not defs
            if k in ('FPU', 'CPU'):
                device['info'][k.lower()] = v
                continue

            device['defs'].append((k, v))

        # if parent is +, there's more data for this pattern
        if parent == '+':
            continue

        # device family
        device['family'].append(find)

        # break if this was the last line in this chain
        if parent == 'END':
            break

        # look for the parent
        find = parent

# reverse device list
device['family'] = device['family'][::-1]

# device was not found
if len(device['family']) == 0:
    sys.exit(1)

# for CPPFLAGS and DEFS, define device family
if mode in ('CPPFLAGS', 'DEFS'):
    sys.stdout.write(' '.join('-D%s' % d.upper() for d in device['family']))

# defines
if mode == 'DEFS':
    if len(device['defs']) > 0:
        defs = ' '.join('-D_%s=%s' % d for d in device['defs'])
        sys.stdout.write(' ' + defs)

# device family
elif mode == 'FAMILY':
    if len(device['family']) > 0:
        sys.stdout.write(device['family'][0])

# device subfamily
elif mode == 'SUBFAMILY':
    if len(device['family']) > 1:
        sys.stdout.write(device['family'][1])

# device info
else:
    info = mode.lower()
    if info in device['info']:
        sys.stdout.write(device['info'][info])

sys.stdout.flush()
