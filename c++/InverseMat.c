#include <stdio.h>

#define ROW 3
#define COL 3

int matrix[ROW][COL} = { {1,2,3}, {4,5,6}, {7,8,9}};

int main()
{
	int a[3][3], i, j;
	float determinant = 0;

#if 0
	printf("Enter the 9 elements of matrix : ");

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
#endif

	printf("\nThe Matrix is\n");
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	

	
