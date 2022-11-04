
unsigned int strlen(const char* str) {
	unsigned int len = 0;

	while (str[len] != 0) len++;

	return len;
}

int strequ(const char* str1, const char* str2) {
	int i;

	if (strlen(str1) != strlen(str2)) return 0;

	for (i = 0; i < strlen(str1); i++)
		if (str1[i] != str2[i]) return 0;

	return 1;
}

