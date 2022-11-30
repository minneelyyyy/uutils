#include <common.h>

/* These string functions are not designed to be as fast as possible.
 * If I wanted to, I could write them all to check/copy up to 8 chars at a time,
 * this makes them much faster but also much larger.
 *
 * We never work with very long strings in the first place, so these optimizations
 * would not matter as much. */

size_t strlen(const char* str) {
	register size_t len = 0;

	while (str[len] != 0) len++;
	
	return len;
}

int strequ(const char* str1, const char* str2) {
	register size_t i;

	for (i = 0; str1[i] != 0; i++)
		if (str1[i] != str2[i]) return 0;

	return 1;
}

void* memcpy(void* dest, const void* src, size_t sz) {
	register size_t i;

	for (i = 0; i < sz; i++)
		((char*)dest)[i] = ((const char*)src)[i];
	
	return dest;
}
