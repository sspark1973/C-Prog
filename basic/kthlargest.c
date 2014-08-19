/*
Take two sorted arrays, and find the kth largest element between them
*/
#include <stdio.h>

int a[] = {2, 3, 7, 12, 27, 81, 91};
int b[] = {1, 25, 32, 74, 89};

int main()
{
	int count = 1, k, res = 0;
	

	printf("Input K : \n");
	scanf("%d", &k);

	int a_len = sizeof(a) / sizeof(a[0]);
	int b_len = sizeof(b) / sizeof(b[0]);
	a_len--; b_len--;

	while(1) {
		if(count == k) {
			//printf("i[%d] =%d and b[%d]=%d\n", , a[i], j, b[j]);
			res = ( a[a_len] > b[b_len] ) ? a[a_len] : b[b_len];
			break;
		}

		if(a[a_len] > b[b_len]) {
			a_len--;
		} else {
			b_len--;
		}
		count++;

	}

	printf("[%d]th the largest number = [%d]\n", k, res); 
	
	return 0;
}
