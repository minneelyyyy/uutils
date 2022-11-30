#ifndef __BUFIO_H
#define __BUFIO_H

#include <defs.h>

#define BUFIO_WCAPACITY 1024

struct bufwriter {
	int fd;
	size_t buffer_size;
	char buffer[BUFIO_WCAPACITY];
};

/* file control */
void file_open_w(struct bufwriter* writer, const char* fname);
void file_open_w_(struct bufwriter* writer, int fd);
void file_close(struct bufwriter* writer);

/* writing */
void b_write(struct bufwriter* writer, void* buf, size_t sz);
void flush(struct bufwriter* writer);

#endif
