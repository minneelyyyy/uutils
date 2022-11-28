#include <bufio.h>

struct bufio __Stdin;
struct bufio __Stdout;
struct bufio __Stderr;

void bufio_init() {
	stdin = &__Stdin;
	stdout = &__Stdout;
	stderr = &__Stderr;

	open_file(stdin, 0);
	open_file(stdout, 1);
	open_file(stderr, 2);
}

