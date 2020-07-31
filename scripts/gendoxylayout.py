#!/usr/bin/env python
# This python program generates parameters for the linker script generator feature.

# This file is part of the libopencm3 project.
#
# 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

from xml.etree import ElementTree

import argparse


parser = argparse.ArgumentParser(prog='gendoxylayout')
parser.add_argument("--template", required=True)
parser.add_argument("--out", required=True)
parser.add_argument("--target")
parser.add_argument("devices", nargs='*')
args = parser.parse_args()

class CommentedTreeBuilder(ElementTree.TreeBuilder):
    def __init__(self, *args, **kwargs):
        super(CommentedTreeBuilder, self).__init__(*args, **kwargs)

    def comment(self, data):
        self.start(ElementTree.Comment, {})
        self.data(data)
        self.end(ElementTree.Comment)

tree = ElementTree.parse(args.template, ElementTree.XMLParser(target=CommentedTreeBuilder()))
parent_map = {c:p for p in tree.iter() for c in p}
for element in tree.iter(tag=ElementTree.Comment):
	if ("#devices#" in element.text):
		idx = (list(parent_map[element]).index(element))
		for device in args.devices:
			tab = ElementTree.Element('tab')

			tab.set("visible", "yes")
			tab.set("title", str(device).upper())
			tab.set("intro", "")

			if (args.target != None):
				if (device == args.target):
					tab.set("type", "modules")
				else:
					tab.set("type", "user")
					tab.set("url", "../../" + device + "/html/modules.html")
			else:
				tab.set("type", "user")
				tab.set("url", "../" + device + "/html/modules.html")

			parent_map[element].insert(idx, tab)
			idx = idx+1;
		parent_map[element].remove(element)

tree.write(args.out)
