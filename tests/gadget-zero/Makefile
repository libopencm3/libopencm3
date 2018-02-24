# This is just a stub makefile used for travis builds
# to keep things all compiling. Normally you'd use
# one of the makefiles directly.

# These hoops are to enable parallel make correctly.
GZ_ALL := $(wildcard Makefile.*)

all: $(GZ_ALL:=.all)
clean: $(GZ_ALL:=.clean)

%.all:
	make -f $* all
%.clean:
	make -f $* clean
	
