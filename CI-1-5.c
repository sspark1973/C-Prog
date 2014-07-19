/*
1.5 Write a method to replace all spaces in a string with ‘%20’.
*/

/*
SOLUTION
The algorithm is as follows:
1. Count the number of spaces during the first scan of the string.
2. Parse the string again from the end and for each character:
	If a space is encountered, store “%20”.
	Else, store the character as it is in the newly shifted location.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char src[] = "hello b roy";
	int len = 0, spaces = 0;

	while(src[len]) {
		if(src[len] == ' ')
			++spaces;
		++len;
	}

	int newLen = len + spaces*2 +1;
	char *dst = malloc(newLen);

	int srcIndex = 0, dstIndex = 0;

	while(src[srcIndex]) {
		if(src[srcIndex] == ' ') {
			dst[dstIndex++] = '%';
			dst[dstIndex++] = '2';
			dst[dstIndex++] = '0';
			++srcIndex;
		} else {
			dst[dstIndex++] = src[srcIndex++];
		}
	}

	dst[dstIndex] = '\0';

	printf("new string = %s\n", dst);

	free(dst);
	return 0;
}
		
		

