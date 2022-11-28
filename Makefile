
PROGS=echo true false yes
COMMON_OBJS=src/_start.o \
            src/commonlib/string.o \
            src/commonlib/bufio.o \
            src/syscalls/syscalls.o

OBJS=$(COMMON_OBJS) src/echo.o src/true.o src/false.o src/yes.o

.SUFFIXES: .c .o
.PHONY: all clean

all: $(PROGS)

.c.o:
	$(CC) $(CFLAGS) -nostdlib -nostdinc -c -Iinclude $< -o $@

$(PROGS): src/syscalls/syscalls.o $(OBJS)
	@mkdir -p ./bin
	$(LD) $(LDFLAGS) -nostdlib -o bin/$@ src/$@.o $(COMMON_OBJS)

src/syscalls/syscalls.o:
	$(AS) $(ASFLAGS) -o $@ src/syscalls/syscalls_`uname -m`.s

clean:
	rm -r -f $(OBJS) bin/ src/syscalls/syscalls.o
