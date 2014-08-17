/*
Print a given matrix in spiral form
Given a 2D array, print it in spiral form. See the following examples.

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/
#include <stdio.h>

#define R 3
#define C 6

void spiralPrint(int row, int col, int arr[][col])
{
	int i, r = 0, c = 0;

	while(r < row && c < col) {

		for(i = c; i < col; ++i)
			printf("%d ", arr[r][i]);

		r++;

		for(i = r; i < row; ++i)
			printf("%d ", arr[i][col-1]);

		col--;

		if(r < row) {
			for(i = col-1; i >= 1; --i)
				printf("%d ", arr[row-1][i]);
			row--;
		}

		if(c < col) {
			for(i = row-1; i >= r; --i)
				printf("%d ", arr[i][c]);
			c++;
		}
	}

	printf("\n");
}

int main()
{
	int a[R][C] = { {1, 2, 3, 4, 5, 6},
					{7, 8, 9, 10, 11, 12},
					{13, 14, 15, 16, 17, 18}};

	spiralPrint(R, C, a);
	return 0;
}

