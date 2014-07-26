/* 
Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. 
NOTE: One or two additional variables are fine. An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.
*/

/*
First, ask yourself, what does the interviewer mean by an additional buffer? 
Can we use an additional array of constant size?
Algorithm—No (Large) Additional Memory:
1. For each character, check if it is a duplicate of already found characters.
2. Skip duplicate characters and update the non duplicate characters.
Time complexity is O(N2).
*/

#include <stdio.h>
#include <string.h>
#include "type_def.h"

void removeDuplicates(char *str)
{
	//char *err = "Error";
	if(str == NULL) return;
	int len = strlen(str);
	int i, j;

	if(len < 2) return;

	int tail = 1;


	for(i=1; i < len; i++) {
		for(j=0; j < tail; j++) {
			if(str[i] == str[j]) break;
		}

		if(j == tail) {
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = '\0';

	printf("%s str=%s\n", __FUNCTION__, str);
}

main() {
	char str[] = "aaabbb";

	removeDuplicates(str);
}
