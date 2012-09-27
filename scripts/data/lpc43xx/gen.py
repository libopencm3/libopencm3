#!/usr/bin/env python

import sys
import csv
from collections import OrderedDict

from pprint import pprint

reader = csv.reader(open(sys.argv[1], 'r'))

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

for register_name, register in registers.iteritems():
    print('/* --- %s values %s */' % (register_name, '-' * (50 - len(register_name))))
    print
    fields = register['fields']
    #for field_name, field in sorted(fields.items(), lambda x, y: cmp(x[1]['lsb'], y[1]['lsb'])):
    for field_name, field in fields.items():
        mask_bits = (1 << field['width']) - 1
        print('/* %s: %s */' % (field_name, field['description']))
        print('#define %s_%s_SHIFT (%d)' % (
            register_name, field_name, field['lsb'],
        ))
        if mask_bits > 1:
            print('#define %s_%s_MASK (0x%x << %s_%s_SHIFT)' % (
                register_name, field_name, mask_bits, register_name, field_name,
            ))
            print('#define %s_%s(x) ((x) << %s_%s_SHIFT)' % (
                register_name, field_name, register_name, field_name,
            ))
        else:
            print('#define %s_%s (1 << %s_%s_SHIFT)' % (
                register_name, field_name, register_name, field_name,
            ))
        print
