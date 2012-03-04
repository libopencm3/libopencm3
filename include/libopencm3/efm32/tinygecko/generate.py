#!/usr/bin/env python

import yaml
import logging
import textwrap

def commentblock(*textblocks, **formatargs):
    ret = []
    nowrapcommands = set("@defgroup")
    ret.extend(textwrap.wrap(textblocks[0].format(**formatargs), 80, initial_indent="/** ", subsequent_indent=" * "))
    last_block_was_at = textblocks[0].startswith('@')
    for b in textblocks[1:]:
        formatted = b.format(**formatargs)

        if not (last_block_was_at and b.startswith('@')):
            ret.append(" *")
        if any(b.startswith(c) for c in nowrapcommands):
            ret.append(" * " + formatted)
        else:
            ret.extend(textwrap.wrap(formatted, 80, initial_indent=" * ", subsequent_indent=" * "))
        last_block_was_at = b.startswith('@')
    return "\n".join(ret) + "\n */\n"

def yaml2h(filenamebase):
    headername = "%s.h"%filenamebase
    yamlname = "%s.yaml"%filenamebase
    conveniencename = "%s.convenienceheaders"%filenamebase

    logging.info("Generating %s from %s", headername, yamlname)

    data = yaml.load(open(yamlname))
    # some defaults
    data.setdefault("projectname", "libopencm3")
    data.setdefault("includeguard", "LIBOPENCM3_EFM32_TINYGECKO_%s_H"%data['shortname'])

    with open(headername, 'w') as outfile:
        def wc(*args, **kwargs): # wrap "outfile" and "data" (as default) arguments  -- i'm a lazy typer
            final_kwargs = data.copy()
            final_kwargs.update(kwargs)
            outfile.write(commentblock(*args, **final_kwargs))
        def wc_close():
            outfile.write("/** @} */\n")
        def nl(): outfile.write("\n")
        def define(key, value, comment=None):
            outfile.write("#define ")
            outfile.write(key)
            outfile.write(" "*max(24-len(key), 1))
            outfile.write(str(value))
            if comment is not None:
                outfile.write(" /**< %s */"%comment)
            nl()

        outfile.write(licensedata[data['license']].format(**data))
        nl()
        wc("@file", "@see {shortdocname}")
        nl()
        wc("Definitions for the {shortname} subsystem ({longname}).", "This corresponds to the description in {baseref}.", "@ingroup {ingroup}", "@defgroup {shortdocname} {shortname} ({longname})", "@{{")
        nl()
        outfile.write("#ifndef {includeguard}\n#define {includeguard}\n".format(**data))
        nl()
        outfile.write("#include <libopencm3/cm3/common.h>\n#include <libopencm3/efm32/memorymap.h>\n")
        nl()
        wc("Register definitions and register value definitions for the {shortname} subsystem", "@defgroup {shortdocname}_regsandvals {shortname} registers and values", "@{{")
        nl()

        regs = data['registers']

        for template in data.get('templateregs', []):
            template['is_template'] = []
            regs.append(template)

        regs_dict = dict((x['name'], x) for x in regs) # for easier access. they've got to be a list in yaml to preserve order

        wc("These definitions reflect {baseref}{registers_baserefext}", "@defgroup {shortdocname}_registers {shortname} registers", "@{{")
        nl()

        for regdata in regs:
            has_bits = "fields" in regdata
            has_values = "values" in regdata
            is_template = "is_template" in regdata
            if is_template:
                # this isn't a real register, just a template
                continue
            secondcomponent_name = regdata['name']
            if (has_bits and isinstance(regdata['fields'], str)) or (has_values and isinstance(regdata['values'], str)):
                # uses a template
                secondcomponent_name = regdata['fields'] if has_bits else regdata['values']
                regs_dict[secondcomponent_name]['is_template'].append(regdata['name'])

            define("%s_%s"%(data['shortname'], regdata['name']), "MMIO32(%s_BASE + %#.003x)"%(data['shortname'], regdata['offset']), "@see %s_%s_%s"%(data['shortdocname'], secondcomponent_name, 'values' if 'values' in regdata else 'bits') if has_bits or has_values else None)
        nl()
        wc_close() # close register definitions
        nl()

        for regdata in regs:
            has_bits = "fields" in regdata
            has_values = "values" in regdata
            is_template = "is_template" in regdata
            if not has_bits and not has_values:
                continue

            if (has_bits and isinstance(regdata['fields'], str)) or (has_values and isinstance(regdata['values'], str)):
                # uses a template, doesn't need own section
                continue

            commentlines = []
            if is_template:
                commentlines.append("%s for the {shortname} \"{name}\" group of registers (%s)"%("Bit states" if has_bits else "Values", ", ".join(regdata['is_template'])))
                assert len(regdata['is_template']) > 0, "What should I talk about when nobody uses this template?"
                if 'override_backref' in regdata:
                    commentlines.append(regdata['override_backref'])
                else:
                    commentlines.append("These registers use this:")
                    commentlines.append("<ul>") # FIXME: once we're using markdown 1.8, this can be changed to markdown
                    for user in regdata['is_template']:
                        userdata = regs_dict[user]
                        # FIXME: this is an ugly hack around this being in a single wc() line which doesn't take per-line contexts
                        mergeddata = data.copy()
                        mergeddata.update(userdata)
                        commentlines.append(("<li>The {shortname}_{name} register; see {baseref}{definition_baserefext} for definitions"+regdata.get("details", "."+"</li>")).format(**mergeddata))
                    commentlines.append("</ul>")
                commentlines.append('@defgroup {shortdocname}_{name}_%s {shortname} {name} %s'%(('bits' if has_bits else 'values', 'bits group' if has_bits else 'values group')))
            else:
                commentlines.append("%s for the {shortname}_{name} register"%("Bit states" if has_bits else "Values"))
                commentlines.append("See {baseref}{definition_baserefext} for definitions"+regdata.get("details", "."))
                commentlines.append('@defgroup {shortdocname}_{name}_%s {shortname} {name} %s'%(('bits' if has_bits else 'values',)*2))
            commentlines.append('@{{')
            wc(*commentlines, **regdata)
            nl()

            if has_bits:
                for field in regdata['fields']:
                    #shiftdefine = "_%s_%s_%s_shift"%(shortname, regdata['name'], field['name'])
                    #define(shiftdefine, field['shift'])

                    # there is one condition under which field's doc would get shown; show it immediately otherwise
                    if 'doc' in field and not ("values" not in field and field.get("length", 1) == 1):
                        wc(field['doc'])

                    if "values" in field:
                        for value in field.get("values"):
                            define("%s_%s_%s_%s"%(data['shortname'], regdata['name'], field['name'], value['name']), value['value'] if "mask" in field else "(%s<<%s)"%(value['value'], field['shift']), value.get('doc', None))
                    else:
                        if field.get('length', 1) == 1:
                            define("%s_%s_%s"%(data['shortname'], regdata['name'], field['name']), "(1<<%s)"%field['shift'], field.get('doc', None))
                        else:
                            # FIXME: this should require the 'type' parameter to be set on this field
                            pass

                    if "values" in field or field.get("length", 1) != 1:
                        if "mask" in field:
                            mask = field['mask']
                        else:
                            mask = "(%#x<<%s)"%(~(~0<<field.get('length', 1)), field['shift'])
                        define("%s_%s_%s_MASK"%(data['shortname'], regdata['name'], field['name']), mask)
            else:
                for value in regdata['values']:
                    define("%s_%s_%s"%(data['shortname'], regdata['name'], value['name']), value['value'], value.get('doc', None))

            nl()
            wc_close()
            nl()
        wc_close() # close registers and values
        nl()

        outfile.write(open(conveniencename).read())

        nl()
        wc_close() # close convenience
        nl()
        outfile.write("#endif\n")

if __name__ == "__main__":
    licensedata = yaml.load(open("generate-license.yaml"))
    for basename in yaml.load(open('generate.yaml')):
        yaml2h(basename)
