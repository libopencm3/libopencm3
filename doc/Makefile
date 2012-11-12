# Makefile to build libopencm3 documentation

# 14 September 2012
# (C) Ken Sarkies <ksarkies@internode.on.net>

doc: html latex

html: cm3 stm32l1 stm32f1 stm32f2 stm32f4 efm32g efm32gg efm32lg efm32tg lm3s lpc13 lpc17 lpc43 top

cm3:
	cd cm3/; doxygen

lm3s:
	cd lm3s/; doxygen

efm32g:
	cd efm32g/; doxygen

efm32gg:
	cd efm32gg/; doxygen

efm32lg:
	cd efm32lg/; doxygen

efm32tg:
	cd efm32tg/; doxygen

lpc13:
	cd lpc13xx/; doxygen

lpc17:
	cd lpc17xx/; doxygen

lpc43:
	cd lpc43xx/; doxygen

stm32f1:
	cd stm32f1/; doxygen

stm32f2:
	cd stm32f2/; doxygen

stm32f4:
	cd stm32f4/; doxygen

stm32l1:
	cd stm32l1/; doxygen

top:
	doxygen

latex: stm32l1.pdf stm32f1.pdf stm32f2.pdf stm32f4.pdf lm3s.pdf lpc13.pdf lpc17.pdf lpc43.pdf efm32g.pdf efm32gg.pdf efm32lg.pdf efm32tg.pdf

stm32l1.pdf:
	cd stm32l1/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32l1.pdf

stm32f1.pdf:
	cd stm32f1/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f1.pdf

stm32f2.pdf:
	cd stm32f2/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f2.pdf

stm32f4.pdf:
	cd stm32f4/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f4.pdf

lm3s.pdf:
	cd lm3s/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../lm3s.pdf

lpc13.pdf:
	cd lpc13xx/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../lpc13.pdf

lpc17.pdf:
	cd lpc17xx/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../lpc17.pdf

lpc43.pdf:
	cd lpc43xx/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../lpc43.pdf

efm32g.pdf:
	cd efm32g/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../efm32g.pdf

efm32gg.pdf:
	cd efm32gg/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../efm32gg.pdf

efm32lg.pdf:
	cd efm32lg/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../efm32lg.pdf

efm32tg.pdf:
	cd efm32tg/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../efm32tg.pdf

clean:
	@rm -rf html/ */html/ */latex/ *.pdf */*.tag

.PHONY: doc html cm3 lm3s lpc13 lpc17 lpc43 stm32l1 stm32f1 stm32f2 stm32f4 efm32g efm32gg efm32lg efm32tg top latex

