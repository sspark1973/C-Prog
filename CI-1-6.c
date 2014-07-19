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
Once the exterior elements are rotated, we then rotate the interior region�s edges.
*/
#include <stdio.h>

void display(int (*matrix)[5], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("=====================================\n");
}

void rotate(int matrix[][5], int n){
	int layer, i;

	for (layer=0; layer < n/2; layer++) {
		int first = layer;
		int last = n - 1 - layer;

		for(i = first; i < last; i++) {
			int offset = i - first;
			int top = matrix[first][i]; // save top
			//left -> top
			matrix[first][i] = matrix[last-offset][first];

			//bottom -> left
			matrix[last-offset][first] = matrix[last][last-offset];

			// right -> bottom
			matrix[last][last-offset] = matrix[i][last];

			// top -> right
			matrix[i][last] = top; // right <-saved top
		}
	}

}

int main(int argc, char **argv)
{
	int matrix[5][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };

	display(matrix, 5);
	rotate(matrix, 5);
	display(matrix, 5);

	return 0;
}

