#include <stdio.h>

int main() {
	char *str[5] = { "roy", "park", "jin", "jonathan", "211"};

	printf("sizeof-str[%d]\n", sizeof(str));
	printf("sizeof-str[0][%d]\n", sizeof(str[0]));

	printf("number of array : [%d]\n", sizeof(str)/sizeof(*str));

	return 0;
}
