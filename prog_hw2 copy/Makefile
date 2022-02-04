CC=riscv32-unknown-elf-gcc
DEFINES  += -DDEBUG
CFLAGS   += -O0 -g -ggdb
CFLAGS   += -ffreestanding  -nostartfiles -nostdlib -nodefaultlibs
LDFILE   = riscv32-console.ld
LDFLAGS  += -Wl,--gc-sections -Wl,-T,$(LDFILE)

EXECUTABLES = count_target sum_within_range maxes

all: $(EXECUTABLES)

# I can't figure out how to combine these three lines with
# a generic pattern rule.
count_target: count_target.s input_count_target.s
sum_within_range: sum_within_range.s input_sum_within_range.s
maxes: maxes.s input_maxes.s

$(EXECUTABLES): crt0.o startup.o
	$(CC) $^ -o $@ $(CFLAGS) $(DEFINES) $(LDFLAGS)

%.o: %.s
	$(CC) $(CFLAGS) $(DEFINES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEFINES) -c $< -o $@

clean:
	rm -f $(EXECUTABLES) *.o
