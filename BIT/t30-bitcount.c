/*
Count the bits in an Integer
*/
#include <stdio.h>

unsigned int countOnes(unsigned int n)
{
	unsigned int count;
	printf("number[%#010x]\n", n);
	for( count = 0; n; count++) {
		n &= n-1;
		printf("number[%#010x]\n", n);
	}

	return count;
}
	

int main()
{
	unsigned int a = 0x1111;
	unsigned int b = 0x3333;
	unsigned int c = 0x7777;

	unsigned int result = 0;

	result = countOnes(a);
	printf("number[%#010x], One's bit[%d]\n", a, result);
	
	result = countOnes(b);
	printf("number[%#010x], One's bit[%d]\n", b, result);

	result = countOnes(c);
	printf("number[%#010x], One's bit[%d]\n", c, result);

	return 0;
}

	

