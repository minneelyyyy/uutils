#include <common.h>
#include <bufio.h>

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
#error "only x86 and x86_64 are supported"
#endif

extern int main(int argc, char** argv);

void _start(void) {
	int argc;
	char** argv;
	int rval;

	getargs(argc, argv);

	rval = main(argc, argv);

	sys_exit(rval);
}
