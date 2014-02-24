# Makefile to build libopencm3 documentation

# 14 September 2012
# (C) Ken Sarkies <ksarkies@internode.on.net>

doc: html latex

html: cm3 usb stm32l1 stm32f0 stm32f1 stm32f2 stm32f3 stm32f4 efm32g efm32gg efm32lg efm32tg lm3s lm4f lpc13 lpc17 lpc43 sam3a sam3n sam3s sam3u sam3x top

cm3:
	cd cm3/; doxygen

usb:
	cd usb/; doxygen

lm3s:
	cd lm3s/; doxygen

lm4f:
	cd lm4f/; doxygen

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

stm32f0:
	cd stm32f0/; doxygen

stm32f1:
	cd stm32f1/; doxygen

stm32f2:
	cd stm32f2/; doxygen

stm32f3:
	cd stm32f3/; doxygen

stm32f4:
	cd stm32f4/; doxygen

stm32l1:
	cd stm32l1/; doxygen

sam3a:
	cd sam3a/; doxygen

sam3n:
	cd sam3n/; doxygen

sam3s:
	cd sam3s/; doxygen

sam3u:
	cd sam3u/; doxygen

sam3x:
	cd sam3x/; doxygen

top:
	doxygen

latex: stm32l1.pdf stm32f0.pdf stm32f1.pdf stm32f2.pdf stm32f3.pdf stm32f4.pdf lm3s.pdf lm4f.pdf lpc13.pdf lpc17.pdf lpc43.pdf efm32g.pdf efm32gg.pdf efm32lg.pdf efm32tg.pdf sam3a.pdf sam3n.pdf sam3s.pdf sam3u.pdf sam3x.pdf

stm32l1.pdf:
	cd stm32l1/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32l1.pdf

stm32f0.pdf:
	cd stm32f0/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f0.pdf

stm32f1.pdf:
	cd stm32f1/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f1.pdf

stm32f2.pdf:
	cd stm32f2/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f2.pdf

stm32f3.pdf:
	cd stm32f3/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f3.pdf

stm32f4.pdf:
	cd stm32f4/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../stm32f4.pdf

lm3s.pdf:
	cd lm3s/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../lm3s.pdf

lm4f.pdf:
	cd lm4f/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../lm4f.pdf

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

sam3a.pdf:
	cd sam3a/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../sam3a.pdf

sam3n.pdf:
	cd sam3n/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../sam3n.pdf

sam3s.pdf:
	cd sam3s/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../sam3s.pdf

sam3u.pdf:
	cd sam3u/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../sam3u.pdf

sam3x.pdf:
	cd sam3x/; doxygen Doxyfile_latex; cd latex/; $(MAKE); cp refman.pdf ../../sam3x.pdf

clean:
	@rm -rf html/ */html/ */latex/ *.pdf */*.tag

.PHONY: doc html cm3 usb lm3s lm4f lpc13 lpc17 lpc43 stm32l1 stm32f0 stm32f1 stm32f2 stm32f3 stm32f4 efm32g efm32gg efm32lg efm32tg sam3a sam3n sam3s sam3u sam3x top latex

