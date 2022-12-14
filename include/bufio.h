#ifndef __BUFIO_H
#define __BUFIO_H

#include <defs.h>

#define BUFWRITER_CAPACITY 1024

struct bufwriter {
	int fd;
	size_t buffer_size;
	char buffer[BUFWRITER_CAPACITY];
};

/* file control */
void file_open_w(struct bufwriter* writer, const char* fname);
void file_open_w_(struct bufwriter* writer, int fd);
void file_close(struct bufwriter* writer);

/* writing */
void b_write(struct bufwriter* writer, void* buf, size_t sz);
void flush(struct bufwriter* writer);

#define b_puts(writer, s) b_write(writer, s, strlen(s))

#endif
