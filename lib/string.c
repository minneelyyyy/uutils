#include <common.h>

#if WORDSIZE == 4
static const unsigned long lowmask  = 0x01010101;
static const unsigned long highmask = 0x80808080;
#elif WORDSIZE == 8
static const unsigned long lowmask  = 0x0101010101010101;
static const unsigned long highmask = 0x8080808080808080;
#else
#error "cpu uses a wordsize that is not supported"
#endif

#define LONGMASK (sizeof(long) - 1)

size_t strlen(const char* str) {
	const char* p;
	const unsigned long* lp;

	/* align str */
	for (p = str; (unsigned long)p & LONGMASK; p++)
		if (*p == 0)
			return p - str;

	for (lp = (const unsigned long*) p; ; lp++) {
		/*
		 * (word - 0x01010101) & 0x80808080
		 *
		 * this is a simple equation to tell you if 8 ascii
		 * characters contains a zero byte.
		 */
		if ((*lp - lowmask) & highmask) {
			/* we now have to check each individual byte to find out
			 * which one is zero */
			p = (const char*)lp;

			if (p[0] == 0)
				return p - str;
			if (p[1] == 0)
				return p - str + 1;
			if (p[2] == 0)
				return p - str + 2;
			if (p[3] == 0)
				return p - str + 3;
#if WORDSIZE == 8
			if (p[4] == 0)
				return p - str + 4;
			if (p[5] == 0)
				return p - str + 5;
			if (p[6] == 0)
				return p - str + 6;
			if (p[7] == 0)
				return p - str + 7;
#endif
		}
	}
	
	return 0;
}

int strequ(const char* str1, const char* str2) {
	register size_t i;

	for (i = 0; str1[i] != 0; i++)
		if (str1[i] != str2[i]) return 0;

	return 1;
}

