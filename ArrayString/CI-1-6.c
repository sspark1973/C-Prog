/*
1.6 Given an image represented by an NxN matrix, 
where each pixel in the image is 4 bytes, 
write a method to rotate the image by 90 degrees. Can you do this in place?
*/

/*
SOLUTION
The rotation can be performed in layers, where you perform a cyclic swap on the edges on each layer. 
In the first for loop, we rotate the first layer (outermost edges). 
We rotate the edges by doing a four-way swap first on the corners, then on the element clockwise from the edges, then on the element three steps away.
Once the exterior elements are rotated, we then rotate the interior region’s edges.
*/
#include <stdio.h>
#include <stdlib.h>

void display(int matrix[][5], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n===================================\n");
}

void rotate(int matrix[][5], int n){
	int layer, i, j, rn=n, cn=n;
	int row[5] = {0};
	int col[5] = {0};

	for (layer=0; layer < n/2; layer++) {
		int first = layer;
		int last = n - 1 - layer;

		for(i = first; i < last; i++) {
			int offset = i - first;
			int top = matrix[first][i]; // save LeftTop
			//LeftBottom -> LeftTop
			matrix[first][i] = matrix[last-offset][first];

			//RightBottom -> LeftBottom
			matrix[last-offset][first] = matrix[last][last-offset];

			// RightTop -> RightBottom
			matrix[last][last-offset] = matrix[i][last];

			// LeftTop -> RightTop
			matrix[i][last] = top; // RightTop <-saved LeftTop
		}
	}
}

void setZeros(int matrix[][5], int rn, int cn) {
	int row[5] = {0};
	int col[5] = {0};
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

	for(i=0; i<rn; i++)
		printf("%d\t", row[i]);
	for(i=0; i<cn; i++)
		printf("%d\t", col[i]);
	

	for(i=0; i < rn; i++) {
		for(j=0; j < cn; j++) {
			if( (row[i] == 1 || col[j] == 1) ) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main(int argc, char **argv)
{
	int matrix[][5] = { {1,2,0,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };

	display(matrix, 5);
	rotate(matrix, 5);
	display(matrix, 5);
	setZeros(matrix, 5, 5);
	display(matrix, 5);

	return 0;
}

