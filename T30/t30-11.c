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

//#if 0

int fibo(int n)
{
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else {
		return fibo(n-1) + fibo(n-2);
	}
}

int main()
{
	int i, fib[30];

	fib[0] = 0;
	fib[1] = 1;

	for(i=2; i < 30; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	printf("The fibonacci series is as following \n");

	for(i=0; i < 30; i++) {
		printf("fib[%d] = %d\n", i, fib[i]);
	}

	int n, result;

	scanf("%d", &n);

	result = fibo(n);

	printf("fibo[%d] = %d\n", n, result);


	return 0;
}
//#endif

#if 0
int fibo(int n)
{
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else {
		return fibo(n-1) + fibo(n-1);
	}
}

	

int main()
{
	int n, result;

	scanf("%d", &n);

	result = fibo(n);
}
#endif
