/*
5 6 Write a program to swap odd and even bits in an integer with as few instructions as possible 
(e g , bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc)
*/

/*
For example, if the given number is 23 (00010111), it should be converted to 43 (00101011). 
Every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), 
and every odd position bit is swapped with adjacent on left side.

If we take a closer look at the example, 
we can observe that we basically need to right shift (>>) all even bits (In the above example, 
even bits of 23 are highlighted) by 1 so that they become odd bits (highlighted in 43), 
and left shift (<<) all odd bits by 1 so that they become even bits. 
The following solution is based on this observation. 
The solution assumes that input number is stored using 32 bits.

Let the input number be x
1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. 
The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
2) Get all odd bits of x by doing bitwise and of x with 0x55555555. 
The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
3) Right shift all even bits.
4) Left shift all odd bits.
5) Combine new even and odd bits and return.


SOLUTION
Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in the even bits   
Then, perform a similar operation for even bits   This takes a total 5 instructions 
*/

#include <stdio.h>

unsigned int swapBits(unsigned int x)
{
	unsigned int even_bits = x & 0xAAAAAAAA;
	unsigned int odd_bits = x & 0x55555555;

	even_bits >>= 1;
	odd_bits <<= 1;

	return( even_bits | odd_bits );
}

int main()
{
	unsigned int x = 0xA5A5A5A5;
	unsigned int result = 0;

	result = swapBits(x);

	printf("%#10x swapBits %#10x\n", x, result);

	return 0;
}
	



