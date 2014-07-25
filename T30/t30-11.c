/*
11.Write a program to generate the Fibonacci series.
Fibonacci series: Any number in the series is obtained by adding the previous two numbers of the series.
Let f(n) be n'th term.
f(0)=0;
f(1)=1;
f(n)=f(n-1 )+f(n-2); (for n>=2)
Series is as follows
011
(1+0)
2 (1+1)
3 (1+2)
5 (2+3)
8 (3+5)
13 (5+8)
21 (8+13)
34 (13+21)
...and so on
*/
#include <stdio.h>

int main()
{
	int i, fib[25];

	fib[0] = 0;
	fib[1] = 1;

	for(i=2; i < 30; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	printf("The fibonacci series is as following \n");

	for(i=0; i < 30; i++) {
		printf("%d\n", fib[i]);
	}

	return 0;
}

	
