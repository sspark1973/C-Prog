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
#include <stdbool.h>
#include <stdlib.h>

//#include "type_def.h"

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

char *removeChars(char *str, char *remove) {
	int src, dst = 0;
	bool flags[128] = {0};

	int str_len = strlen(str);

	char *dstr = (char *)malloc(str_len + 1);

	for(src = 0; src < strlen(remove); ++src) {
		flags[remove[src]] = true;
	}

	for(src = 0; src < str_len; ++src) {
		if(!flags[str[src]]) {
			dstr[dst++] = str[src];
		}
	}
	dstr[dst] = '\0';

	return dstr;
}
	

main() {
	char str[] = "acaabcbbdd";
	char str2[] = "Battle of the Vowels: Hawaii vs. Grozny";
	char remove[] = "aeiou";

	char *dstr = removeChars(str2, remove);
	printf("str[%s] dstr[%s]\n", str2, dstr);

	free(dstr);
	removeDuplicates(str);
}
