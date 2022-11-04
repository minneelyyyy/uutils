
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

$(programs): $(OBJPATH)/syscalls.o $(OBJPATH)/string.o
	$(CC) -nostdlib -nostdinc -I./$(INCPATH)/ -c -Os -o $(OBJPATH)/$@.o $(SRCPATH)/$@.c
	$(LINKER) -nostdlib -s -o $(BINPATH)/$@ $(OBJPATH)/$@.o $(OBJPATH)/string.o $(OBJPATH)/syscalls.o

$(OBJPATH)/syscalls.o:
	$(CC) -nostdlib -c -o $@ $(SRCPATH)/syscalls/syscalls_`uname -m`.s

$(OBJPATH)/string.o:
	$(CC) -nostdlib -nostdinc -c -Os -o $@ $(SRCPATH)/string.c

clean:
	rm -r $(OBJPATH)/ $(BINPATH)/
