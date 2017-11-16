# Compiler: GCC
CC := gcc
# Common GCC flags
CCFLAGS := -g -O1 -fno-stack-protector
# Compiler flags for x86_64
CCFLAGS64 := $(CCFLAGS) -m64
# Compiler flags for x86
CCFLAGS32 := $(CCFLAGS) -m32

# Build anything
%: %.c
	$(CC) $(CCFLAGS64) $< -o $@.64
	$(CC) $(CCFLAGS32) $< -o $@.32

# Delete everything
.PHONY: clean
clean:
	rm -f *.64 *.32

