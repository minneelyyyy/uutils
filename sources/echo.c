#include <common.h>
#include <string.h>

void _start(void) {
	int argc;
	char** argv;

	int i;
	int show_newline = 1;

	getargs(argc, argv);

	if (argc > 1 && strequ(argv[1], "-n")) show_newline = 0;

	for (i = !show_newline + 1; i < argc; i++) {
		sys_write(1, argv[i], strlen(argv[i]));

		if (i + 1 < argc) {
			sys_write(1, " ", 1);
		}
	}

	if (show_newline) {
		sys_write(1, "\n", sizeof("\n"));
	}

	sys_exit(0);
}
