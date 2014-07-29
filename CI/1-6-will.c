
/*
 * Given an image represented by an NxN matrix,
 * where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees.
 * Can you do this in place?
 */


/* key point : Simplify problem
 *
 * rotate layer by layer
 *
 */

#include <stdio.h>


void cswap(unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d)
{
	unsigned int tmp;

	tmp = *a;
	*a = *b;
	*b = *c;
	*c = *d;
	*d = tmp;
	return;
}


void display(unsigned int image[][5])
{
	int i, j;

	printf("----------------------------\n");

	for(i=0; i < 5;i++) {
		for(j=0; j < 5; j++) {
			printf ("%2d ", image[i][j]);
		}
		printf ("\n");
	}

	printf("----------------------------\n");
	printf("\n\n");

		return;
}

unsigned int image[5][5] = {	{11,12,13,14,15}, \
								{21,22,23,24,25}, \
								{31,32,33,34,35}, \
								{41,42,43,44,45}, \
								{51,52,53,54,55}, };


void main(void)
{

	int start, end, layer, offset;

	display(image);


	for(layer = 0; layer < 5/2; layer++) {
		start = layer;
		end = 5 - 1 - layer;

		for(offset = 0; offset < end; offset++) {

			cswap(&image[start][start+offset], \
				&image[start+offset][end], \
				&image[end][end-offset], \
				&image[end-offset][start]);
		}

	}

	display(image);

	return;
}



