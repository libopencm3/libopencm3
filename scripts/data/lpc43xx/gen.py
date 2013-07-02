#!/usr/bin/env python

import sys
import yaml
import yaml_odict
from collections import OrderedDict

from pprint import pprint

registers = yaml.load(open(sys.argv[1], 'r'))

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
        print('#define %s_%s_MASK (0x%x << %s_%s_SHIFT)' % (
            register_name, field_name, mask_bits, register_name, field_name,
        ))
        print('#define %s_%s(x) ((x) << %s_%s_SHIFT)' % (
            register_name, field_name, register_name, field_name,
        ))
        print
