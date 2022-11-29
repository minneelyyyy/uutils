#ifndef __DEFS_H
#define __DEFS_H

/* architecture specific defines */
#if defined(__i386)
typedef unsigned int size_t;
typedef signed int ssize_t;

#define WORDSIZE 4
#define LITTLE_ENDIAN
#elif defined(__x86_64)
typedef unsigned long size_t;
typedef signed long ssize_t;

#define WORDSIZE 8
#define LITTLE_ENDIAN
#endif

#endif /* __DEFS_H */
