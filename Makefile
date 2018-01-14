# Compiler: GCC
CC := gcc
# Common GCC flags
CCFLAGS := -O1 -fno-stack-protector -lcrypt
# Compiler flags for x86_64
CCFLAGS64 := $(CCFLAGS) -m64

# Make anything
%: %.c
	make $@.64

# Build 64 bit binaries
%.64: %.c
	$(CC) $(CCFLAGS64) $< -o $@
	objcopy -N FILE $@

# Determine all C programs in directory
SRCS = $(wildcard *.c)
# Substitute the programs' names
PROGS = $(patsubst %.c,%.64,$(SRCS))
# All lets you make everything
all: $(PROGS)

# Delete everything
.PHONY: clean
clean:
	rm -f *.64
