#ifndef __DEFS_H
#define __DEFS_H

/* architecture specific defines */
#if defined(__i386)
typedef unsigned int size_t;
typedef signed int ssize_t;

#define WORDSIZE 2
#define DWORDSIZE 4
#define MAXWORDSIZE DWORDSIZE

#define LITTLE_ENDIAN

#elif defined(__x86_64)
typedef unsigned long size_t;
typedef signed long ssize_t;

#define WORDSIZE 2
#define DWORDSIZE 4
#define QWORDSIZE 8
#define MAXWORDSIZE QWORDSIZE

#define LITTLE_ENDIAN

#endif /* defined(__x86_64) */

#endif /* __DEFS_H */
