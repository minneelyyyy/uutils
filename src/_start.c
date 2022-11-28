#include <common.h>

/* not meant to be publicly accessible, only called here as part of _start.
 * this is why we do not put it in bufio.h */
extern void bufio_init();

extern int main(int argc, char** argv);

void _start(void) {
	int argc;
	char** argv;
	int rval;

	getargs(argc, argv);

	bufio_init();
	rval = main(argc, argv);

	sys_exit(rval);
}
