/*
Big / little endian conversion C code

The conversion is done, simply by swapping the bytes in memory for a 32 bit number.
Byte0 is swapped with byte3. Byte1 is swapped with byte2.
The conversion works both ways - from big to little and from little to big.
*/

#include <stdio.h>

// Wrong
int EndianSwap32_1(int a)
{
	int b;

	b = (a << 24) 
		| ( a >> 24 ) 
		| ((a << 8) & 0xFF0000) 
		| ((a >> 8) & 0xFF00);

	return b;
}

int EndianSwap32_2(int x)
{
	int y = 0;
	y += (x & 0x000000FF) << 24;
	y += (x & 0xFF000000) >> 24;
	y += (x & 0x0000FF00) << 8;
	y += (x & 0x00FF0000) >> 8;

	return y;
}

int main()
{
	int a = 0x12345678;
	int b = EndianSwap32_1(a);
	int c = EndianSwap32_2(a);

	printf("%#010x -> %#010x\n", a, b);
	printf("%#010x -> %#010x\n", a, c);
	return 0;
}

