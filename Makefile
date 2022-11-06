
CC?=cc
LINKER?=cc

OBJPATH=objects
BINPATH=binaries
SRCPATH=sources
INCPATH=include

OPTLEVEL?=0
EXTRAFLAGS?=-g
LINKERFLAGS?=-g

programs := echo true false yes

all: $(OBJPATH) $(BINPATH) $(programs)

$(OBJPATH):
	mkdir $@

$(BINPATH):
	mkdir $@

$(programs): $(OBJPATH)/_start.o $(OBJPATH)/syscalls.o $(OBJPATH)/string.o
	$(CC) $(EXTRAFLAGS) -nostdlib -nostdinc -I./$(INCPATH)/ -c \
		-O$(OPTLEVEL) -o $(OBJPATH)/$@.o $(SRCPATH)/$@.c
	$(LINKER) $(LINKERFLAGS) -nostdlib -o $(BINPATH)/$@ $(OBJPATH)/$@.o \
		$(OBJPATH)/_start.o $(OBJPATH)/string.o $(OBJPATH)/syscalls.o

$(OBJPATH)/_start.o:
	$(CC) $(EXTRAFLAGS) -nostdlib -nostdinc -I./$(INCPATH)/ \
		-c -O$(OPTLEVEL) -o $@ $(SRCPATH)/_start.c

$(OBJPATH)/syscalls.o:
	$(CC) $(EXTRAFLAGS) -nostdlib -c \
		-o $@ $(SRCPATH)/syscalls/syscalls_`uname -m`.s

$(OBJPATH)/string.o:
	$(CC) $(EXTRAFLAGS) -nostdlib -nostdinc -I./$(INCPATH)/ \
		-c -O$(OPTLEVEL) -o $@ $(SRCPATH)/commonlib/string.c

clean:
	rm -r -f $(OBJPATH)/ $(BINPATH)/
