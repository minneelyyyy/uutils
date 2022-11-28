#include <common.h>
#include <bufio.h>
#include <string.h>

int main(int argc, char** argv) {
	int i;
	int show_newline = 1;

	if (argc > 1 && strequ(argv[1], "-n")) show_newline = 0;

	/* write all args! */
	for (i = !show_newline + 1; i < argc - 1; i++) {
		bufio_puts(stdout, argv[i]);
		bufio_puts(stdout, " ");
	}

	if (argc > 1 && show_newline)
		bufio_puts(stdout, argv[i]);

	if (show_newline) bufio_puts(stdout, "\n");

	return 0;
}
