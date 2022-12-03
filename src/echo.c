#include <common.h>
#include <bufio.h>
#include <string.h>
#include <bool.h>

int main(int argc, char** argv) {
	int i;
	bool show_newline = true;
	struct bufwriter stdout;

	if (argc > 1 && strequ(argv[1], "-n"))
		show_newline = false;

	file_open_w_(&stdout, 1);

	/* write all args! */
	for (i = !show_newline + 1; i < argc - 1; i++) {
		b_puts(&stdout, argv[i]);
		b_puts(&stdout, " ");
	}

	if (argc > 1 && show_newline)
		b_puts(&stdout, argv[i]);

	if (show_newline) b_puts(&stdout, "\n");

	return 0;
}
