#include <common.h>

/* un-optimal strlen implementation. designed for size instead of speed. */
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
	char* d = (char*) dest;
	const char* s = (const char*) src;
	int i;

	for (i = 0; i < sz; i++) {
		d[i] = s[i];
	}
	
	return dest;
}
