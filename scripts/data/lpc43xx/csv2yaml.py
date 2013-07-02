#!/usr/bin/env python

import sys
import yaml
import csv
from collections import OrderedDict

def repr_odict(dumper, data):
    """
    >>> data = OrderedDict([('foo', 'bar'), ('mumble', 'quux'), ('baz', 'gorp')])
    >>> yaml.dump(data, default_flow_style=False)
    '!!omap\\n- foo: bar\\n- mumble: quux\\n- baz: gorp\\n'
    >>> yaml.dump(data, default_flow_style=True)
    '!!omap [foo: bar, mumble: quux, baz: gorp]\\n'
    """
    return repr_pairs(dumper, u'tag:yaml.org,2002:omap', data.iteritems())
 
yaml.add_representer(OrderedDict, repr_odict)
 
def repr_pairs(dump, tag, sequence, flow_style=None):
    """This is the same code as BaseRepresenter.represent_sequence(),
    but the value passed to dump.represent_data() in the loop is a
    dictionary instead of a tuple."""
 
    value = []
    node = yaml.SequenceNode(tag, value, flow_style=flow_style)
    if dump.alias_key is not None:
        dump.represented_objects[dump.alias_key] = node
    best_style = True
    for (key, val) in sequence:
        item = dump.represent_data({key: val})
        if not (isinstance(item, yaml.ScalarNode) and not item.style):
            best_style = False
        value.append(item)
    if flow_style is None:
        if dump.default_flow_style is not None:
            node.flow_style = dump.default_flow_style
        else:
            node.flow_style = best_style
    return node
 
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
