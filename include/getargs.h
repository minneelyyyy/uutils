#ifndef __GETARGS_H
#define __GETARGS_H

/* getargs() macros only work inside of start,
 * and should be the first bit of code run */
#if defined(__i386__)
#	define getargs(argc, argv)					\
		do {							\
			asm("movl 0x4(%%ebp), %0" : "=r" (argc));	\
			asm("leal 0x8(%%ebp), %0" : "=r" (argv));	\
		} while (0)
#elif defined(__x86_64__)
#	define getargs(argc, argv)				\
		do {						\
			asm("movl (%%rdi), %0" : "=r" (argc));	\
			asm("leaq 8(%%rdi), %0" : "=r" (argv));	\
		} while (0)
#else
#error "only x86 and x86_64 are supported"
#endif

#endif /* __GETARGS_H */
