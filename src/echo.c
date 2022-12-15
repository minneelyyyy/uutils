#include <common.h>
#include <bufio.h>
#include <string.h>
#include <bool.h>

int main(int argc, char** argv) {
	int i = 1;
	bool show_newline = true;
	struct bufwriter stdout;

	file_open_w_(&stdout, 1);

	if (argc > 1 && strequ(argv[1], "-n")) {
		show_newline = false;
		i++;
	}

	for (; i < argc; i++) {
		if (i + 1 < argc) {
			b_puts(&stdout, argv[i]);
			b_puts(&stdout, " ");
		} else {
			size_t len = strlen(argv[i]);

			if (len >= 2 &&
			    argv[i][len - 2] == '\\' &&
			    argv[i][len - 1] == 'c') {
				show_newline = false;
				len -= 2;
			}

			b_write(&stdout, argv[i], len);
		}
	}

	if (show_newline) b_puts(&stdout, "\n");
	else flush(&stdout);

	return 0;
}
