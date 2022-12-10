#ifndef __DEFS_H
#define __DEFS_H

/* architecture specific defines */
#if defined(__i386)
typedef unsigned int size_t;
typedef signed int ssize_t;

#define WORDSIZE 2
#define WORD short
#define DWORDSIZE 4
#define DWORD int
#define MAXWORDSIZE DWORDSIZE
#define MAXWORD DWORD

#define LITTLE_ENDIAN

#elif defined(__x86_64)
typedef unsigned long size_t;
typedef signed long ssize_t;

#define WORDSIZE 2
#define WORD short
#define DWORDSIZE 4
#define DWORD int
#define QWORDSIZE 8
#define QWORD long
#define MAXWORDSIZE QWORDSIZE
#define MAXWORD QWORD

#define LITTLE_ENDIAN

#endif /* defined(__x86_64) */

#endif /* __DEFS_H */
