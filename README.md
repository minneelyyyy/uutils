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
It might not be a good idea to replace system utilities with these in their
current state, because of this there is no `make install` option.
Just copy files from `bin/` to your designated install location if you wish.
