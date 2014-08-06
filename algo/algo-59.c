/*
Eratosthenes's sieve �ƶ��佺�׳׽��� ü
�־��� N���� ���� �Ҽ��� ��� ���Ͽ���
����� ������?
*/

#include <stdio.h>
//nclude <alloc.h>
#include <stdlib.h>
#include <string.h> // memset

#define MAX 9999

void main(void)
{
	int *iptr;
	int i, j, n;

	printf("Enter a number :\n");
	scanf("%d", &n);

	//iptr = (int*)calloc(n, sizeof(int)); //  ã�ƺ���...
	
	iptr = (int *)malloc(n*sizeof(int));
	memset(iptr, 0, n*sizeof(int));
	

	if(iptr == NULL) {
		puts("\n Memory allocation error!");
		exit(1);
	}

	for(i=2; i < n; i++) {
		if(iptr[i] == 1)
			continue;
		j = i;

		for(j=i+i; j <= n; j += i)
		//while((j += i) <= MAX)
			iptr[j] = 1;
	}

	printf("Prime Numbers of [%d] :\n", n);

	for(i=2; i<=n; i++) {
		if(iptr[i] == 0)
			printf("\t%6d", i);
	}
	printf("\n");

	
}
 
