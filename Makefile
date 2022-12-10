
PROGS=echo true false yes
OBJS=src/_start.o lib/syscalls/syscalls.o lib/string.o lib/bufio.o

.SUFFIXES: .c .o
.PHONY: all clean

all: $(PROGS)

.c.o:
	$(CC) $(CFLAGS) -nostdlib -nostdinc -c -Iinclude $< -o $@

$(PROGS): $(OBJS) src/$@.o
	$(LD) $(LDFLAGS) -nostdlib -o $@ src/$@.o $(OBJS)

lib/syscalls/syscalls.o:
	$(AS) $(ASFLAGS) -o $@ lib/syscalls/syscalls_`uname -m`.s

clean:
	rm -r -f $(PROGS) `find . -name '*.o'`
