#include <common.h>
#include <bufio.h>

extern int main(int argc, char** argv);

void _start(void) {
	int argc;
	char** argv;
	int rval;

	getargs(argc, argv);

	rval = main(argc, argv);

	sys_exit(rval);
}
