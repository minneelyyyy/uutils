#ifndef __COMMON_H
#define __COMMON_H

#if defined(__i386__)
// warning: only use inside of _start
#	define getargs(argc, argv)					\
		do {							\
			asm("movl 0x4(%%ebp), %0" : "=r" (argc));	\
			asm("leal 0x8(%%ebp), %0" : "=r" (argv));	\
		} while (0)
#elif defined (__x86_64__)
#error "sorry, x86_64 not implemented yet!"
// warning: only use inside of _start
#	define getargs(argc, argv) ((void) 0)
#else
#error "only x86 and x86_64 are supported"
#endif

extern unsigned int sys_write(int fd, void* buf, unsigned int len);
extern void sys_exit(int exit_status);

#endif /* __COMMON_H */
