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
These programs can be compiled simply with `make`.
This will build the programs in debug mode.
If you want release, you will want to use `./release.sh`.

If you want other custom command line arguments there are three variables
to remember: `EXTRAFLAGS`, `LINKERFLAGS`, and `OPTLEVEL`.

`EXTRAFLAGS` gets passed to the compiler (specified with `CC`).
`LINKERFLAGS` gets passed to the linker (specified with `LD`),
and `OPTLEVEL` is just for the -O flag.

### How to Get the Smallest Binaries Possible
Different combinations of compilers and linkers may provide the best possible
binary sizes. For example, on my system clang produces the smallest objects
and gcc can link them together and get the smallest executable.
Try playing with different combinations on your system.
`CC` specifies the compiler (source -> objects) and `LD` specifies
linker (objects -> executables).

### Installing
It might not be a good idea to replace system utilities with these in their
current state, because of this there is no `make install` option.
Just copy files from `bin/` to your designated install location if you wish.
