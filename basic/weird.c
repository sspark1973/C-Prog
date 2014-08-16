#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("char : [%d]\n", sizeof(char));
	printf("short : [%d]\n", sizeof(short));
	printf("int : [%d]\n", sizeof(int));
	printf("long : [%d]\n", sizeof(long));

	printf(" abcd ef");
	printf("\n");

	printf("malloc(-10) -> [%d]\n", sizeof(malloc(-10)));

	return 0;
}
