#include <common.h>
#include <string.h>

int main(int argc, char** argv) {
	int i;
	int show_newline = 1;

	if (argc > 1 && strequ(argv[1], "-n")) show_newline = 0;

	for (i = !show_newline + 1; i < argc - 1; i++) {
		sys_write(1, argv[i], strlen(argv[i]));
		sys_write(1, " ", 1);
	}

	if (argc > 1 && show_newline)
		sys_write(1, argv[i], strlen(argv[i]));

	if (show_newline) sys_write(1, "\n", sizeof("\n"));

	return 0;
}
