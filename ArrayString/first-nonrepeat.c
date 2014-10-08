/*
Page 87

Given a string, find the first non-repeating character in it. 
For example, if the input string is ¡°GeeksforGeeks¡±, then output should be ¡®f¡¯ 
and if input string is ¡°GeeksQuiz¡±, then output should be ¡®G¡¯.
*/

/*
We can use string characters as index and build a count array. Following is the algorithm.

1) Scan the string from left to right and construct the count array.
2) Again, scan the string from left to right and check for count of each
 character, if you find an element who's count is 1, return it.
Example:

Input string: str = geeksforgeeks
1: Construct character count array from the input string.
   ....
  count['e'] = 4
  count['f'] = 1
  count['g'] = 2
  count['k'] = 2
  ¡¦¡¦
2: Get the first character who's count is 1 ('f').
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define NO_OF_CHARS 256

int *getCharCountArray(char *str) {
	int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
	int i;

	for(i = 0; *(str + i); i++)
		count[*(str + i)]++;

	return count;
}

int fristNonRepeating(char *str) {
	int *count = getCharCountArray(str);
	int index = -1, i;

	for(i=0; *(str + i); ++i) {
		if(count[*(str + i)] == 1) {
			index = i;
			break;
		}
	}

	free(count);
	return index;
}

/*
Can we do it by traversing the string only once?
The above approach takes O(n) time, but in practice it can be improved. 
The first part of the algorithm runs through the string to construct the count array (in O(n) time). This is reasonable. 

But the second part about running through the string again just to find the first non-repeater is not good in practice. 
In real situations, your string is expected to be much larger than your alphabet. 
Take DNA sequences for example: they could be millions of letters long with an alphabet of just 4 letters. 

What happens if the non-repeater is at the end of the string? Then we would have to scan for a long time (again).
We can augment the count array by storing not just counts but also the index of the first time you encountered the character 
e.g. (3, 26) for ¡®a¡¯ meaning that ¡®a¡¯ got counted 3 times and the first time it was seen is at position 26. 

So when it comes to finding the first non-repeater, we just have to scan the count array, instead of the string. 

Thanks to Ben for suggesting this approach.

Following is C implementation of the extended approach that traverses the input string only once.
*/

struct countIndex {
	int count;
	int index;
};

struct countIndex *getCharCountArray2(char *str) {
	struct countIndex *count = (struct countIndex *)calloc(sizeof(struct countIndex), NO_OF_CHARS);
	int i;

	for(i = 0; *(str + i); i++) {
		(count[*(str + i)].count)++;

		if(count[*(str+i)].count == 1)
			count[*(str+i)].index = i;
	}

	return count;
}

int fristNonRepeating2(char *str) {
	struct countIndex *count = getCharCountArray2(str);
	int result = INT_MAX, i;

	for(i=0; i < NO_OF_CHARS; ++i) {
		if(count[i].count == 1 && result > count[i].index) {
			result = count[i].index;
		}
	}

	free(count);
	return result;
}


int main()
{
	char str[] = "geeksforgeeks";
	int index = fristNonRepeating2(str);

	if(index == INT_MAX)
		printf("Either all characters are repeating or string is empty\n");
	else
		printf("First non-repeating character is %c, INT_MAX[%d]\n", str[index], INT_MAX);
	

	return 0;
}


