#include "common.h"

unsigned int strlen(const char* str) {
	unsigned int len = 0;

	while (str[len] != 0) len++;

	return len;
}

int strequ(const char* str1, const char* str2) {
	int i;

	if (strlen(str1) != strlen(str2)) return 0;

	for (i = 0; i < strlen(str1); i++)
		if (str1[i] != str2[i]) return 0;

	return 1;
}

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
