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

void open_file(struct bufio* file, int fd) {
}

void open_file_fs(struct bufio* file, const char* name, int flags) {
}

void close_file(struct bufio* file) {
}

void bufio_write(struct bufio* writer, void* buf, size_t sz) {
}

void bufio_puts(struct bufio* writer, const char* str) {
}

void bufio_read(struct bufio* reader, void* buf, size_t sz) {
}

void bufio_flush(struct bufio* writer) {
}

