/*
19.3 Write an algorithm which computes the number of trailing zeros in n factorial.

What does the number of trailing zeros mean exactly?
for example, 720 has one trailing zero since it ends with one zero, 
and 24 has no trailing zeros since it does not end with any zeros at all.
*/

/*

http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/

SOLUTION
Trailing zeros are contributed by pairs of 5 and 2, because 5*2 = 10. 

To count the number of pairs, 
we just have to count the number of multiples of 5. 
Note that while 5 contributes to one multiple of 10, 25 contributes two (because 25 = 5*5).
 Let°Øs walk through an example to see how this works: Suppose num = 26. 
 In the first loop, we count how many multiples of five there are by doing 26 / 5 = 5 
 (these multiples are 5, 10, 15, 20, and 25). 
 In the next loop, we count how many multiples of 25 there are: 26 / 25 = 1 (this multiple is 25). 
 Thus, we see that we get one zero from 5, 10, 15 and 20, and two zeros from 25 (note how it was counted twice in the loops). 
 Therefore, 26! has six zeros.

OBSERVATIONS AND SUGGESTIONS:
°Ì°ÌThis is a bit of a brain teaser, 
but it can be approached logically (as shown above). 
By thinking through what exactly will contribute a zero, 
and what doesn°Øt matter, you can come up with a solution. 
Again, be very clear in your rules up front so that you can implement this correctly.
*/
#include <stdio.h>

int numZeros(int num)
{
	int count = 0, i;

	if(num < 0) {
		printf("Factorial is not defined for < 0");
		return 0;
	}

	for(i = 5; num / i > 0; i *= 5) {
		count += num / i;
	}

	return count;
}

int factorial(int num)
{
	if(num < 0) {
		printf("Factorial is not defined for < 0");
		return 0;
	} 

	if(num == 1)
		return 1;
	else
		return num * factorial(num - 1);
}

int main()
{
	int num;
	printf("Enter the number :\n");
	scanf("%d", &num);

	int fact;
	fact = factorial(num);

	int nZeros;
	nZeros = numZeros(num);

	printf("%d factorial[%d] numZeros[%d]\n", num, fact, nZeros);
	return 0;
}

