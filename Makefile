
PROGS=echo true false yes
COMMON_OBJS=src/_start.o src/commonlib/string.o src/commonlib/bufio.o src/syscalls/syscalls.o
OBJS=$(COMMON_OBJS) \
     src/echo.o src/true.o src/false.o src/yes.o

OPTLEVEL?=0
EXTRAFLAGS?=-g
LINKERFLAGS=-g

.SUFFIXES: .c .s .o
.PHONY: all clean

all: $(PROGS)

.c.o:
	$(CC) -O$(OPTLEVEL) $(EXTRAFLAGS) -nostdlib -nostdinc -c -Iinclude $< -o $@

.s.o:
	$(AS) $< -o $@

$(PROGS): src/syscalls/syscalls.o $(OBJS)
	@mkdir -p ./bin
	$(LD) $(LINKERFLAGS) -nostdlib -o $@ src/$@.o $(COMMON_OBJS)
	@mv $@ bin/$@

src/syscalls/syscalls.o:
	$(AS) -o $@ src/syscalls/syscalls_`uname -m`.s

clean:
	rm -r -f $(OBJS) bin src/syscalls/syscalls.o
