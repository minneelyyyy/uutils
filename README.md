# μutils

This is a collection of POSIX utilities for FreeBSD.
They are all static binaries that do not rely on LIBC at all.
This contributes to their small size.

## Usage
You can use these programs freely and are allowed to copy, change,
and distribute as both code and binaries. Here are a few instructions
to make this program yours.
Read `LICENSE` for more information about copying.

### Compiling
There are a few options for this. The easiest way for a regular user is to use
the `release.sh` script. You can run `make` directly. Do this if you wish for
more control over compiler options.

If you are a developer, use the provided `debug.sh` script.

### How to Get the Smallest Binaries Possible
Different combinations of compilers and linkers may provide the best possible
binary sizes. For example, on my system clang produces the smallest objects
and gcc can link them together and get the smallest executable.
Try playing with different combinations on your system.

`CC` specifies the compiler (source -> objects) and `LD` specifies
linker (objects -> executables).

In the example above, in order to get the smallest binaries on my machine, I would
run the following:
```sh
$ ./release.sh CC=clang LD=gcc
```

If you want to compile a specific list of commands, just list them off.
```sh
$ ./release.sh echo yes
```

### Installing
I do not recommend installing these just yet. If you want to, you will have
to install them all manually. Just copy the programs to your chosen install location.

If you REALLY want to install these, the easist way would be to make just one quick update
to the Makefile. go to the $(PROGS) rule, and replace the following line.

```make
$(PROGS): $(OBJS) src/$@.o
	$(LD) $(LDFLAGS) -nostdlib -o $@ src/$@.o $(OBJS)
```
```make
$(PROGS): $(OBJS) src/$@.o
	$(LD) $(LDFLAGS) -nostdlib -o bin/$@ src/$@.o  $(OBJS)
```

Then `mkdir bin`. This will put the binaries in their own neat little folder, which you can then copy them easily from.
