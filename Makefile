# Makefile for ECOS
# Configuration of make process in ecos.mk

CFLAGS = -O2 -Wall -DLDL_LONG -DDLONG -Wextra -g#-ansi -ipo

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
# we're on a linux system, use accurate timer provided by clock_gettime()
LIBS = -lm -lrt
else
# we're on apple, no need to link rt library
LIBS = -lm
endif

## AR and RANLIB FOR GENERATING LIBRARIES
AR = ar
ARFLAGS = rcs
ARCHIVE = $(AR) $(ARFLAGS)
RANLIB = ranlib

## WHICH FILES TO CLEAN UP
CLEAN = *.o *.obj *.ln *.bb *.bbg *.da *.tcov *.gcov gmon.out *.bak *.d *.gcda *.gcno
C = $(CC) $(CFLAGS) -Iinclude  

# Compile all C code, including the C-callable routine
all: wrightOmega demo

# build ECOS
wrightOmega: wrightOmega.o
	$(ARCHIVE) libOmega.a *.o
	- $(RANLIB) libOmega.a

wrightOmega.o: src/wrightOmega.c include/wrightOmega.h
	$(C) -c src/wrightOmega.c -o wrightOmega.o

demo: wrightOmega src/wrightDemo.c
	$(C) -o wrightDemo.exe src/wrightDemo.c libOmega.a $(LIBS)
	echo Demo built successfully

# remove object files, but keep the compiled programs and library archives
clean:
	$(RM) $(CLEAN)

# clean, and then remove compiled programs and library archives
purge: clean
	( cd external/ldl    ; $(MAKE) purge )
	( cd external/amd    ; $(MAKE) purge )	
	- $(RM) libecos.a runecos

