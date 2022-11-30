#include <common.h>
#include <string.h>
#include <bufio.h>

int main(int argc, char** argv) {
	int i;

	if (argc == 1) {
		for (;;) {
			sys_write(1, "y\n", sizeof("y\n"));
		}
	}
	else {
		struct bufwriter stdout;
		file_open_w_(&stdout, 1);

		for (;;) {
			for (i = 1; i < argc - 1; i++) {
				b_puts(&stdout, argv[i]);
				b_puts(&stdout, " ");
			}

			b_puts(&stdout, argv[argc - 1]);
			b_puts(&stdout, "\n");
		}
	}

	return 0;
}

