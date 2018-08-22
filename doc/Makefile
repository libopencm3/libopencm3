# Makefile to build libopencm3 documentation

# 14 September 2012
# (C) Ken Sarkies <ksarkies@internode.on.net>

ARCHS := stm32f0 stm32f1 stm32f2 stm32f3 stm32f4 stm32f7
ARCHS += stm32l0 stm32l1 stm32l4
ARCHS += efm32g efm32gg efm32hg efm32lg efm32tg
ARCHS += lm3s lm4f msp432e4
ARCHS += lpc13xx lpc17xx lpc43xx
ARCHS += sam3a sam3n sam3s sam3u sam3x
ARCHS += vf6xx

doc: html

html: rebuildsources $(ARCHS)
	doxygen

$(ARCHS):
	cd $@/; doxygen

clean:
	@rm -rf html/ */html/ */*.tag */doxy.sourcelist */doxygen_*.log

rebuildsources:
	@printf "Manually regenerating source lists from build deps\n"
	../scripts/gendoxylist ../lib/stm32/f0 stm32f0
	../scripts/gendoxylist ../lib/stm32/f1 stm32f1
	../scripts/gendoxylist ../lib/stm32/f2 stm32f2
	../scripts/gendoxylist ../lib/stm32/f3 stm32f3
	../scripts/gendoxylist ../lib/stm32/f4 stm32f4
	../scripts/gendoxylist ../lib/stm32/f7 stm32f7
	../scripts/gendoxylist ../lib/stm32/l0 stm32l0
	../scripts/gendoxylist ../lib/stm32/l1 stm32l1
	../scripts/gendoxylist ../lib/stm32/l4 stm32l4
	../scripts/gendoxylist ../lib/efm32/g efm32g
	../scripts/gendoxylist ../lib/efm32/gg efm32gg
	../scripts/gendoxylist ../lib/efm32/hg efm32hg
	../scripts/gendoxylist ../lib/efm32/lg efm32lg
	../scripts/gendoxylist ../lib/efm32/tg efm32tg
	../scripts/gendoxylist ../lib/lm3s lm3s
	../scripts/gendoxylist ../lib/lm4f lm4f
	../scripts/gendoxylist ../lib/msp432/e4 msp432e4
	../scripts/gendoxylist ../lib/lpc13xx lpc13xx
	../scripts/gendoxylist ../lib/lpc17xx lpc17xx
	../scripts/gendoxylist ../lib/sam/3a sam3a
	../scripts/gendoxylist ../lib/sam/3n sam3n
	../scripts/gendoxylist ../lib/sam/3s sam3s
	../scripts/gendoxylist ../lib/sam/3u sam3u
	../scripts/gendoxylist ../lib/sam/3x sam3x
	../scripts/gendoxylist ../lib/vf6xx vf6xx

.PHONY: doc html $(ARCHS) rebuildsources

