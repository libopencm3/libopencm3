# This is just a stub makefile used for travis builds
# to keep things all compiling. Normally you'd use
# one of the makefiles directly.

# These hoops are to enable parallel make correctly.
GZ_ALL := $(wildcard Makefile.*)

all: $(GZ_ALL:=.all)
clean: $(GZ_ALL:=.clean)
flash: $(GZ_ALL:=.flash)

%.all:
	$(MAKE) -f $* all
%.clean:
	$(MAKE) -f $* clean
%.flash:
	$(MAKE) -f $* flash
	
