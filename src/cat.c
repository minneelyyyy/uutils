#include <common.h>
#include <string.h>
#include <bool.h>

void write_file(int fd, unsigned int flags) {
	char buffer[4096];
	size_t sz;

	for (;;) {
		sz = sys_read(fd, buffer, sizeof(buffer));
		if (sz == 0) return;

		sys_write(STDOUT_FILENO, buffer, sz);
	}
}

int main(int argc, char** argv) {
	unsigned int wf_flags = 0;
	int fd;
	int i;
	bool no_more_args = false;

	if (argc == 1) {
		write_file(STDIN_FILENO, wf_flags);
		return 0;
	}

	for (i = 1; i < argc; i++) {
		if (!no_more_args && argv[i][0] == '-') {
			/* handle args */
		} else {
			no_more_args = true;
		}

		if (strequ(argv[i], "-")) {
			write_file(STDIN_FILENO, wf_flags);
			continue;
		}

		fd = sys_open(argv[i], O_RDONLY);

		if (fd < 0) {
			const char* errmessage = "error: failed to open file\n";
			sys_write(STDERR_FILENO, errmessage, strlen(errmessage));
			return 1;
		}

		write_file(fd, wf_flags);
		sys_close(fd);
	}

	return 0;
}
