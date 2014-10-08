/*
Page 86
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool reverseWords(char *str)
{
	char *buffer;
	int slen, tokenReadPos, wordReadPos, wordEnd, writePos = 0;

	slen = strlen(str);

	tokenReadPos = slen - 1;
	buffer = (char *)malloc(slen + 1);

	if(!buffer)
		return false;

	while(tokenReadPos >= 0) {
		if(str[tokenReadPos] == ' ') {
			buffer[writePos++] = str[tokenReadPos--];
		} else {
			wordEnd = tokenReadPos;
			while(tokenReadPos >= 0 && str[tokenReadPos] != ' ')
				tokenReadPos--;
			wordReadPos = tokenReadPos + 1;
			while(wordReadPos <= wordEnd) {
				buffer[writePos++] = str[wordReadPos++];
			}
		}
	}

	buffer[writePos] = '\0';
	strncpy(str, buffer, slen + 1);
	free(buffer);

	return true;
}

void wcReverseString(char *str, int start, int end) {
	char temp;

	while(end > start) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++; end--;
	}
}

void wcReverseWords(char *str)
{
	int start = 0, end = 0, length;
	length = strlen(str);

	wcReverseString(str, start, length - 1);

	while(end < length) {
		if(str[end] != ' ') {
			start = end;
			while(end < length && str[end] != ' ')
				end++;
			end--;
			wcReverseString(str, start, end);
		}
		end++;
	}
}

int main()
{
	char str[] = "Do or do not, there is no try.";
	// char *str = "Do or do not, there is no try.";	// Error!

	printf("before reverseWords = %s\n", str);
	//reverseWords(str);
	wcReverseWords(str);
	printf("after reverseWords = %s\n", str);

	return 0;
}

	
