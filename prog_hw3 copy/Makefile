CC=riscv32-unknown-elf-gcc
DEFINES  += -DDEBUG
CFLAGS   += -O0 -g -ggdb
CFLAGS   += -ffreestanding  -nostartfiles -nostdlib -nodefaultlibs
LDFILE   = riscv32-console.ld
LDFLAGS  += -Wl,--gc-sections -Wl,-T,$(LDFILE)

EXECUTABLES = call_rotate call_interleave call_transpose

all: $(EXECUTABLES)

call_rotate: call_rotate.s
call_interleave: call_interleave.s
call_transpose: call_transpose.s

$(EXECUTABLES): functions.o crt0.o startup.o
	$(CC) $^ -o $@ $(CFLAGS) $(DEFINES) $(LDFLAGS)

%.o: %.s
	$(CC) $(CFLAGS) $(DEFINES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEFINES) -c $< -o $@

clean:
	rm -f $(EXECUTABLES) *.o
