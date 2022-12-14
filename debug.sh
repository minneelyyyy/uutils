#!/bin/sh

make CFLAGS="-O0 -g" LDFLAGS="-g" ASFLAGS="-g" $@
