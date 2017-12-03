# Compiler: GCC
CC := gcc
# Common GCC flags
CCFLAGS := -O1 -fno-stack-protector
# Compiler flags for x86_64
CCFLAGS64 := $(CCFLAGS) -m64

# Build anything
%: %.c
	$(CC) $(CCFLAGS64) $< -o $@.64
	objcopy -N FILE $@.64

# Delete everything
.PHONY: clean
clean:
	rm -f *.64

