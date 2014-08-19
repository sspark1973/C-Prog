
#include <stdio.h>

struct foo {
	char a;
	char *b;
};

struct foo2 {
	char *b;
	char a;
};

struct customer {
	char name;
	char height;
	char weight;
};

struct customer2 {
	char name;
	char height;
	char weight;
	int age;
};


int main()
{
	printf("sizeof char = %d\n", sizeof(char));
	printf("sizeof char* = %d\n", sizeof(char *));
	printf("sizeof long = %d\n", sizeof(long));
	printf("sizeof long long = %d\n", sizeof(long));

	printf("sizeof foo = %d\n", sizeof(struct foo));
	printf("sizeof foo2 = %d\n", sizeof(struct foo2));

	printf("sizeof customer = %d\n", sizeof(struct customer));
	printf("sizeof customer2 = %d\n", sizeof(struct customer2));

	return 0;
}	
