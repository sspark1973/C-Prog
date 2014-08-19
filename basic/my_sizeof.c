#include <stdio.h>

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)

int main()
{
	long a;

	printf("my_sizeof long : %d\n", my_sizeof(a));
	return 0;
}
