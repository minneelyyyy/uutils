
CC?=cc
LINKER?=cc

OBJPATH?=objects
BINPATH?=binaries
SRCPATH?=sources
INCPATH?=include

programs := echo

all: $(OBJPATH) $(BINPATH) $(programs)

$(OBJPATH):
	mkdir $@

$(BINPATH):
	mkdir $@

$(programs): $(OBJPATH)/syscalls.o
	$(CC) -nostdlib -nostdinc -I./$(INCPATH)/ -c -Os -o $(OBJPATH)/$@.o $(SRCPATH)/$@.c
	$(LINKER) -nostdlib -s -o $(BINPATH)/$@ $(OBJPATH)/$@.o $(OBJPATH)/syscalls.o

$(OBJPATH)/syscalls.o:
	$(CC) -nostdlib -c -o $@ $(SRCPATH)/syscalls/syscalls_`uname -m`.s

clean:
	rm -r $(OBJPATH)/ $(BINPATH)/
