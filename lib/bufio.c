#include <bufio.h>
#include <syscalls.h>
#include <string.h>

void file_open_w(struct bufwriter* writer, const char* fname) {
	int fd = sys_open(fname, O_WRONLY | O_CREAT);
	file_open_w_(writer, fd);
}

void file_open_w_(struct bufwriter* writer, int fd) {
	writer->fd = fd;
	writer->buffer_size = 0;
}

void file_close(struct bufwriter* writer) {
	sys_close(writer->fd);
}

void b_write(struct bufwriter* writer, void* buf, size_t sz) {
	char* pos;

	if (writer->buffer_size + sz >= BUFIO_WCAPACITY) {
		flush(writer);
	}

	pos = writer->buffer + writer->buffer_size;
	memcpy(pos, buf, sz);
	writer->buffer_size += sz;

	if (writer->buffer_size > 0 && writer->buffer[writer->buffer_size - 1] == '\n') {
		flush(writer);
	}
}

void flush(struct bufwriter* writer) {
	sys_write(writer->fd, writer->buffer, writer->buffer_size);
	writer->buffer_size = 0;
}
