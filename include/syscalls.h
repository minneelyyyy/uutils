#ifndef __SYSCALLS_H
#define __SYSCALLS_H

#include <defs.h>

ssize_t sys_write(int fd, void* buf, size_t sz);
void sys_exit(int qval);
int sys_fcntl(int fd, int cmd, ... /* arg */);

#endif
