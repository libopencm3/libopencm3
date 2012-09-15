# Makefile to build libopencm3 documentation

# 14 September 2012
# (C) Ken Sarkies <ksarkies@internode.on.net>

doc: html latex

html: cm3 stm32 stm32f1 stm32f2 stm32f4 lm3s lpc13 lpc17 lpc43 top

cm3:
	cd cm3/; doxygen

lm3s:
	cd lm3s/; doxygen

lpc13:
	cd lpc13xx/; doxygen

lpc17:
	cd lpc17xx/; doxygen

lpc43:
	cd lpc43xx/; doxygen

stm32:
	cd stm32/; doxygen

stm32f1:
	cd stm32f1/; doxygen

stm32f2:
	cd stm32f2/; doxygen

stm32f4:
	cd stm32f4/; doxygen

top:
	doxygen

latex: stm32f1.pdf stm32f2.pdf stm32f4.pdf lm3s.pdf lpc13.pdf lpc17.pdf lpc43.pdf

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

clean:
	@rm -rf html/ */html/ */latex/ *.pdf */*.tag

.PHONY: doc html cm3 lm3s lpc13 lpc17 lpc43 stm32 stm32f1 stm32f2 stm32f4 top latex

