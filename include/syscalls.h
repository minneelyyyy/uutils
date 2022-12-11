#ifndef __SYSCALLS_H
#define __SYSCALLS_H

#include <defs.h>

void sys_exit(int qval);

ssize_t sys_read(int fd, void* buf, size_t sz);
ssize_t sys_write(int fd, const void* buf, size_t sz);

#define O_RDONLY        0x0
#define O_WRONLY        0x1
#define O_WDWR          0x2
#define O_EXEC          0x40000
#define O_NONBLOCK      0x4
#define O_APPEND        0x8
#define O_CREAT         0x200
#define O_TRUNC         0x400
#define O_EXCL          0x800
#define O_SHLOCK        0x10
#define O_EXLOCK        0x20
#define O_DIRECT        0x10000
#define O_FSYNC         0x80
#define O_SYNC          0x80
#define O_ASYNC         0x40
#define O_NOFOLLOW      0x100
#define O_NOCTTY        0x8000
#define O_TTY_INIT      0x80000
#define O_DIRECTORY     0x20000
#define O_CLOEXEC       0x100000
#define O_VERIFY        0x200000

#define S_IRWXU		0x700
#define S_IRUSR		0x400
#define S_IWUSR		0x200
#define S_IXUSR		0x100
#define S_IRWXG		0x070
#define S_IRGRP		0x040
#define S_IWGRP		0x020
#define S_IXGRP		0x010
#define S_IRWXO		0x007
#define S_IROTH		0x004
#define S_IWOTH		0x002
#define S_IXOTH		0x001

int sys_open(const char* path, int flags, ...);

int sys_close(int fd);

#endif
