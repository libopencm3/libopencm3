#!/usr/bin/env python

import sys
import yaml
import csv
from collections import OrderedDict
 
def convert_file(fname):
    reader = csv.reader(open(fname, 'r'))

    registers = OrderedDict()
    for register_name, lsb, width, field_name, description, reset_value, access in reader:
        if register_name not in registers:
            registers[register_name] = {
                'fields': OrderedDict(),
            }

        register = registers[register_name]
        fields = register['fields']
        if field_name in fields:
            raise RuntimeError('Duplicate field name "%s" in register "%s"' %
                    field_name, register_name)
        else:
            fields[field_name] = {
                'lsb': int(lsb),
                'width': int(width),
                'description': description,
                'reset_value': reset_value,
                'access': access,
            }

    with open(fname.replace('.csv', '.yaml'), 'w') as out_file:
        yaml.dump(registers, out_file, default_flow_style=False)

for fname in sys.argv[1:]:
    convert_file(fname)
