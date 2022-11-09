#include <common.h>
#include <string.h>

int main(int argc, char** argv) {
	int i;

	if (argc == 1) {
		for (;;) {
			sys_write(1, "y\n", sizeof("y\n"));
		}
	}
	else {
		for (;;) {
			for (i = 1; i < argc - 1; i++) {
				sys_write(1, argv[i], strlen(argv[i]));
				sys_write(1, " ", sizeof(" "));
			}

			sys_write(1, argv[argc - 1], strlen(argv[argc - 1]));
			sys_write(1, "\n", sizeof("\n"));
		}
	}

	return 0;
}

