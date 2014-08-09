/*
소수를 구하는 알고리즘
Prime - 1과 자기자신 외에는 나누어 덜어지는 정수가 없는 양의 정수 
*/

#include <stdio.h>
#include <math.h>

#define TRUE 1

int is_prime(int n)
{
	int i;

	for ( i=2; i < n; i++) {
		printf("[%d] % [%d] = %d\n", n, i, n%i);

		if(n % i == 0) {
			return !TRUE;
		}
	}

	return TRUE;
}

int is_prime2(int n)
{
	int i, sqrn;
	
	sqrn = (int)sqrt(n); // n의 제곱근 
	printf("sqrt(%d) = %d\n", n, sqrn);

	for(i=2; i < sqrn; i++) {
		if((n % i) == 0) {
			return !TRUE;
		}
	}

	return TRUE;
}
		
int main(void)
{
	int n;

	puts("\n Input number to test :\n");
	scanf("%d", &n);

	if(n<0)
		return 0;

	printf("\n Ans : %d is%s prime number\n", n, is_prime(n) ? "" : " not");
	printf("\n Ans : %d is%s prime number\n", n, is_prime2(n) ? "" : " not");
	return 0;
}
