/*
Write a method to generate the nth Fibonacci number
*/
#include <stdio.h>

int fibo(int n) 
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else if (n > 1) {
		return fibo(n-1) + fibo(n-2);
	} else
		return -1;
}

int main()
{
	int n = 10, res = 0;

	res = fibo(n);
	printf("n[%d] fibo[%d]\n", n, res);

	n = 0;
	res = fibo(n);
	printf("n[%d] fibo[%d]\n", n, res);

	n = 1;
	res = fibo(n);
	printf("n[%d] fibo[%d]\n", n, res);

	n = 2;
	res = fibo(n);
	printf("n[%d] fibo[%d]\n", n, res);
	return 0;
}	
