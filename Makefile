
CC?=cc
LD?=ld

PROGS=echo true false yes
OBJS=src/_start.o src/commonlib/string.o \
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
	$(CC) $(EXTRAFLAGS) -nostdlib -c $< -o $@

$(PROGS): src/syscalls/syscalls.o $(OBJS)
	@mkdir -p ./bin
	$(LD) $(LINKERFLAGS) -nostdlib -o $@ src/$@.o src/_start.o \
		src/syscalls/syscalls.o src/commonlib/string.o
	@mv $@ bin/$@

src/syscalls/syscalls.o:
	$(CC) $(EXTRAFLAGS) -nostdlib -c -o $@ src/syscalls/syscalls_`uname -m`.s

clean:
	rm -r -f $(OBJS) bin src/syscalls/syscalls.o
