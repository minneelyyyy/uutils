# Tiny FreeBSD Utilities

#### This is a collection of POSIX utilities for FreeBSD. They are all static binaries that do not rely on LIBC at all. This contributes to their small size.

## Usage

You can use these programs freely and are allowed to copy, change, and distribute as both code and binaries. Here are a few instructions to make this program yours. Read `LICENSE` for more information.

### Compiling
These programs can be compiled simply with `make`. This will build the programs in debug mode. If you want release, you will want to use `./release.sh`.

If you want other custom command line arguments there are three variables to remember: `EXTRAFLAGS`, `LINKERFLAGS`, and `OPTLEVEL`.

`EXTRAFLAGS` gets passed to the compiler (specified with `CC`). `LINKERFLAGS` gets passed to the linker (specified with `LINKER`), and `OPTLEVEL` is just for the -O flag.

### Installing
It might not be a good idea to replace system libraries with these in their current state, because of this there is no `make install` option. Just copy files from `binaries/` to your designated install location.
