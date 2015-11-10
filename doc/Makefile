# Makefile to build libopencm3 documentation

# 14 September 2012
# (C) Ken Sarkies <ksarkies@internode.on.net>

ARCHS := stm32f0 stm32f1 stm32f2 stm32f3 stm32f4 stm32f7
ARCHS += stm32l0 stm32l1 stm32l4
ARCHS += efm32g efm32gg efm32lg efm32tg
ARCHS += lm3s lm4f
ARCHS += lpc13xx lpc17xx lpc43xx
ARCHS += sam3a sam3n sam3s sam3u sam3x
ARCHS += vf6xx

PDFS := $(ARCHS:=.pdf)

doc: html latex

html: cm3 usb $(ARCHS)
	doxygen

latex: $(PDFS)

cm3:
	cd cm3/; doxygen

usb:
	cd usb/; doxygen

$(ARCHS):
	cd $@/; doxygen

%.pdf:
	cd $*/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../$(*).pdf

clean:
	@rm -rf html/ */html/ */latex/ *.pdf */*.tag

.PHONY: doc html cm3 usb $(ARCHS) latex

