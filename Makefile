
PROGS=echo yes cat
SIMPLE_PROGS=true false
OBJS=src/_start.o lib/syscalls/syscalls.o lib/string.o lib/bufio.o lib/errno.o
SIMPLE_OBJS=lib/syscalls/syscalls.o lib/string.o lib/errno.o

.SUFFIXES: .c .s .o
.PHONY: all clean

all: $(PROGS) $(SIMPLE_PROGS)

.c.o:
	$(CC) $(CFLAGS) -nostdlib -nostdinc -c -Iinclude $< -o $@

.s.o:
	$(AS) $(ASFLAGS) -o $@ $<

$(PROGS): $(OBJS) src/$@.o
	$(LD) $(LDFLAGS) -nostdlib -o $@ src/$@.o $(OBJS)

$(SIMPLE_PROGS): $(SIMPLE_OBJS) src/$@.o
	$(LD) $(LDFLAGS) -nostdlib -o $@ src/$@.o $(SIMPLE_OBJS)

lib/syscalls/syscalls.o:
	$(AS) $(ASFLAGS) -o $@ lib/syscalls/syscalls_`uname -m`.s

clean:
	rm -r -f $(PROGS) $(SIMPLE_PROGS) `find . -name '*.o'`
