/*
C program to find second most frequent character
July 24, 2014
Given a string, find the second most frequent character in it. Expected time complexity is O(n) where n is the length of the input string.

Examples:

Input: str = "aabababa";
Output: Second most frequent character is 'b'

Input: str = "geeksforgeeks";
Output: Second most frequent character is 'g'

Input: str = "geeksquiz";
Output: Second most frequent character is 'g'
The output can also be any other character with 
count 1 like 'z', 'i'.

Input: str = "abcd";
Output: No Second most frequent character

A simple solution is to start from the first character, count its occurrences, then second character and so on. 
While counting these occurrence keep track of max and second max. Time complexity of this solution is O(n2).

We can solve this problem in O(n) time using a count array with size equal to 256 (Assuming characters are stored in ASCII format). 
Following is C implementation of the approach.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER  256

char getSecondMostFreq(char *str)
{
	if(*str == '\0')
		return '\0';

	int check_buf[MAX_BUFFER] = {0};

	//int len = strlen(str), i;

	for(i = 0; str[i]; i++) {
		check_buf[str[i]]++;
	}

	int first = 0, second = 0;

	for(i = 0; i < MAX_BUFFER; i++) {
		if(check_buf[i] > check_buf[first]) {
			second = first;
			first = i;
		} else if (check_buf[i] > check_buf[second] && check_buf[i] != check_buf[first])
			second = i;
	}


	return second;
}

int main()
{
	char str[] = "geeksforgeeks";
	char res = getSecondMostFreq(str);

	if(res != '\0')
		printf("Second most frequent char is [%c]\n", res);
	else
		printf("No second most frequent charater\n");

	return 0;
}
