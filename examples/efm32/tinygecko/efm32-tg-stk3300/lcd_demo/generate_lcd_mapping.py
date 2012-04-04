#!/usr/bin/env python

import yaml

class Font(dict):
    def __init__(self, letterdict):
        for (k, v) in letterdict.items():
            self[k] = set(v.split())

class Display(object):
    def __init__(self, data):
        self.mapping = {}

        for c, segs in enumerate(data['coms']):
            for s, name in enumerate(segs):
                self.mapping[name] = (c, s)

    def render_text(self, text, symbols, font):
        cursor = 1
        segments = set()
        for letter in text:
            if letter == '.':
                segments.add("a%s_dp"%(cursor-1))
            elif letter == ':':
                segments.add("a%s_colon"%(cursor-1))
            elif letter in font:
                for segment in font[letter]:
                    segments.add("a%s_%s"%(cursor, segment))
                cursor += 1

        for s in symbols:
            segments.add(s)

        coms = {}
        for segment in segments:
            com, seg = self.mapping[segment]
            coms[com] = coms.get(com, 0) | (1<<seg)

        return coms

def main():
    data = yaml.load(open("lcd_mapping.yaml"))

    d = Display(data)

    text = "{FNORD}"
    symbols = ['gecko']
    f = Font({
        '-': 'g1 g2',
        'A': 'e f a b c g1 g2',
        'C': 'a f e d',
        'D': 'a b c d i l',
        'E': 'a f g1 g2 e d',
        'F': 'a f g1 g2 e',
        'H': "f b g1 g2 e c",
        'I': "i l a d",
        'L': 'f e d',
        'M': 'e f h j b c',
        'N': 'e f h m c b',
        'O': 'a f e d c b',
        'R': 'a e f g1 j m',
        'T': 'i l a',
        'U': 'f e d c b',
        '[': 'a d e f',
        ']': 'a b c d',
        '{': 'a d k h g1',
        '}': 'a j g2 m d',
        })

    for com, data in d.render_text(text, symbols, f).items():
        print "set_bank(%d, %#08.0x);"%(com, data)
#    with open('lcd_mapping.c', 'w') as outfile:
#        for symbol in data['symbols']:

if __name__ == "__main__":
    main()
