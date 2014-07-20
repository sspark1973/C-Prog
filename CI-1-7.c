/*
1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

SOLUTION
At first glance, this problem seems easy: 
	just iterate through the matrix and every time we see a 0, set that row and column to 0. 
	There’s one problem with that solution though: 
		we will “recognize” those 0s later on in our iteration and then set their row and column to zero. 
		Pretty soon, our entire matrix is 0s!

One way around this is to keep a second matrix which flags the 0 locations. 
We would then do a second pass through the matrix to set the zeros. 
This would take O(MN) space.

Do we really need O(MN) space? No. 
Since we’re going to set the entire row and column to zero, do we really need to track which cell in a row is zero? 
No. We only need to know that row 2, for example, has a zero.
The code below implement this algorithm. 
We keep track in two arrays all the rows with zeros and all the columns with zeros. 
We then make a second pass of the matrix and set a cell to zero if its row or column is zero.
*/
#include <stdio.h>
#include <stdlib.h>

int matrix[5][5] = { {1,2,0,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };

#define ROW 5
#define COL 5

void display(int rn, int cn) {
	int i, j;

	for(i=0; i < rn; i++) {
		for(j=0; j < cn; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	printf("--------------------------------\n");
}
	
void setZeros(int rn, int cn) {
	int row[ROW] = {0};
	int col[COL] = {0};
	int i, j;
	//int *row, *col;

	//row = (int *)malloc(rn);
	//col = (int *)malloc(cn);

	for(i=0; i < rn; i++) {
		for(j=0; j < cn; j++) {
			if(matrix[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(i=0; i < rn; i++) {
		for(j=0; j < cn; j++) {
			if( (row[i] == 1 || col[j] == 1) ) {
				matrix[i][j] = 0;
			}
		}
	}
}


int main(int argc, char **argv) {

	display(5, 5);
	setZeros(5, 5);
	display(5, 5);
	return 0;
}
