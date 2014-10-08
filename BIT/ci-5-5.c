/*
5 5 Write a function to determine 
the number of bits required to convert integer A to integer B 
Input: 31, 14 Output: 2
*/

/*
SOLUTION
This seemingly complex problem is actually rather straightforward   

To approach this, 
ask yourself how you would figure out 
which bits in two numbers are different   

Simple: with an xor 

Each 1 in the xor will represent one different bit between A and B   
We then simply need to count the number of bits that are 1
*/
#include <stdio.h>

int bitSwapRequired(int a, int b)
{
	int c, count = 0;

	printf("[a^b]=[%x]\n", a^b);
	for( c = a ^ b; c != 0; c = c >> 1) {
		count += c & 1;
	}
	return count;
}

int main()
{
	int a = 31, b=14;
	int result=0;

	result = bitSwapRequired(a, b);
	printf("Result : [%d]\n", result);

	return 0;
}

