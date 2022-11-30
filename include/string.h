#ifndef _STRING_H
#define _STRING_H

#include <defs.h>

size_t strlen(const char* str);
int strequ(const char* s1, const char* s2);
void* memcpy(void* dest, const void* src, size_t sz);

#endif /* _STRING_H */
