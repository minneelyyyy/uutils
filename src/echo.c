#include <common.h>
#include <bufio.h>
#include <string.h>
#include <bool.h>

int main(int argc, char** argv) {
	int i;
	bool show_newline = true;
	bool no_more_flags = false;
	struct bufwriter stdout;

	file_open_w_(&stdout, 1);

	for (i = 1; i < argc; i++) {
		if (!no_more_flags && argv[i][0] == '-') {
			if (strequ(argv[i], "-n"))
				show_newline = false;

			continue;
		} else {
			no_more_flags = true;
		}

		b_puts(&stdout, argv[i]);
		if (i + 1 < argc)
			b_puts(&stdout, " ");
	}

	if (show_newline) b_puts(&stdout, "\n");
	else flush(&stdout);

	return 0;
}
