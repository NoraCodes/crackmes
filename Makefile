CC := gcc
CCFLAGS := -g -O1


%: %.c
	$(CC) $(CCFLAGS) $< -o $@.x

.PHONY: clean
clean:
	rm -f *.x

