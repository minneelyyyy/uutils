#ifndef __COMMON_H
#define __COMMON_H

#include <defs.h>
#include <syscalls.h>

#if defined(__i386__)
/* warning: only use inside of _start */
#	define getargs(argc, argv)					\
		do {							\
			asm("movl 0x4(%%ebp), %0" : "=r" (argc));	\
			asm("leal 0x8(%%ebp), %0" : "=r" (argv));	\
		} while (0)
#elif defined(__x86_64__)
/* warning: only use inside of _start, run before any other code */
#	define getargs(argc, argv)				\
		do {						\
			asm("movl (%%rdi), %0" : "=r" (argc));	\
			asm("leaq 8(%%rdi), %0" : "=r" (argv));	\
		} while (0)
#error "only x86 and x86_64 are supported"
#endif

#endif /* __COMMON_H */
