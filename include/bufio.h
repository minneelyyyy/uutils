#ifndef __BUFIO_H
#define __BUFIO_H

#include <defs.h>

/* the structure itself */
struct bufio {
	int fd;
	char* head;
	char buffer[1024];
};

/* file control */
void open_file(struct bufio* writer, int fd);
void open_file_fs(struct bufio* writer, const char* name, int flags);
void close_file(struct bufio* writer);

/* writing */
void bufio_write(struct bufio* writer, void* buf, size_t sz);
void bufio_puts(struct bufio* writer, const char* str);

/* reading */
void bufio_read(struct bufio* reader, void* buf, size_t sz);

/* buffer control */
void bufio_flush(struct bufio* writer);

/* buffers opened by default */
struct bufio* stdin;
struct bufio* stdout;
struct bufio* stderr;

#endif
