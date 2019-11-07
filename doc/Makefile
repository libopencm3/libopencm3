# Makefile to build libopencm3 documentation

# 14 September 2012
# (C) Ken Sarkies <ksarkies@internode.on.net>

# setup TARGETS if not set for legacy and ease of debug.
TARGETS ?= stm32/f0 stm32/f1 stm32/f2 stm32/f3 stm32/f4 stm32/f7 stm32/h7 \
		   stm32/l0 stm32/l1 stm32/l4 \
		   stm32/g0 \
		   gd32/f1x0 \
		   efm32/g efm32/gg efm32/hg efm32/lg efm32/tg \
		   efm32/wg efm32/ezr32wg \
		   lm3s lm4f \
		   msp432/e4 \
		   lpc13xx lpc17xx lpc43xx \
		   sam/3a sam/3n sam/3s sam/3u sam/3x \
		   vf6xx \
		   swm050 \
   		   pac55xx


TARGETS_DIRS = $(subst /,,$(TARGETS))

doc: html


DoxygenLayout.xml: templates/DoxygenLayout_Root.xml
	../scripts/gendoxylayout.py --template $< --out $@ $(TARGETS_DIRS)

define gen_DOC_TARGET
DOC_TARGETS += doc_$(1)
CLEAN_TARGETS += clean_$(1)

$(1)/:
	@mkdir -p $$@

$(1)/doxy.sourcelist: $(1)/
	@../scripts/gendoxylist ../lib/$(TARGET_SRC_DIR) $(1)

$(1)/Doxyfile: templates/Doxyfile_Device | $(1)/
	@cat $$< | sed s/#device#/$(1)/g > $$@

$(1)/DoxygenLayout_$(1).xml: templates/DoxygenLayout_Device.xml | $(1)/
	@../scripts/gendoxylayout.py --template $$< --out $$@ --target $(1) $$(TARGETS_DIRS)

doc_$(1): $(1)/doxy.sourcelist $(1)/Doxyfile $(1)/DoxygenLayout_$(1).xml
	@(cd $(1); doxygen)

clean_$(1):
	@$(RM) -rf $(1)/doxy.sourcelist $(1)/Doxyfile $(1)/DoxygenLayout_$1.xml $(1)/doxygen_$(1).log $(1)/html $(1)/$(1).tag

endef

$(foreach TARGET_SRC_DIR, $(TARGETS), $(eval $(call gen_DOC_TARGET,$(subst /,,$(TARGET_SRC_DIR)))))

html: $(DOC_TARGETS) DoxygenLayout.xml
	doxygen

clean: $(CLEAN_TARGETS)
	@rm -rf html/ DoxygenLayout.xml doxygen.log
 
.PHONY: doc html $(DOC_TARGETS) $(CLEAN_TARGETS)

