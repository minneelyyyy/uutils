
CC?=cc
LINKER?=cc

OBJPATH=objects
BINPATH=binaries
SRCPATH=sources
INCPATH=include

OPTLEVEL?=0
EXTRAFLAGS?=
LINKERFLAGS?=-g

programs := echo

all: $(OBJPATH) $(BINPATH) $(programs)

$(OBJPATH):
	mkdir $@

$(BINPATH):
	mkdir $@

$(programs): $(OBJPATH)/syscalls.o $(OBJPATH)/string.o
	$(CC) $(EXTRAFLAGS) -nostdlib -nostdinc -I./$(INCPATH)/ -c -O$(OPTLEVEL) -o $(OBJPATH)/$@.o $(SRCPATH)/$@.c
	$(LINKER) $(LINKERFLAGS) -nostdlib -o $(BINPATH)/$@ $(OBJPATH)/$@.o $(OBJPATH)/string.o $(OBJPATH)/syscalls.o

$(OBJPATH)/syscalls.o:
	$(CC) $(EXTRAFLAGS) -nostdlib -c -o $@ $(SRCPATH)/syscalls/syscalls_`uname -m`.s

$(OBJPATH)/string.o:
	$(CC) $(EXTRAFLAGS) -nostdlib -nostdinc -c -O$(OPTLEVEL) -o $@ $(SRCPATH)/string.c

clean:
	rm -r $(OBJPATH)/ $(BINPATH)/
