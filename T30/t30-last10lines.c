/*
Program to print last 10 lines
Given some text lines in one string, each line is separated by ¡®\n¡¯ character. 
Print the last ten lines. If number of lines is less than 10, then print all lines.

Source: Microsoft Interview | Set 10

Following are the steps
1) Find the last occurrence of DELIM or ¡®\n¡¯
2) Initialize target position as last occurrence of ¡®\n¡¯ and count as 0 , and do following while count < 10
......2.a) Find the next instance of ¡®\n¡¯ and update target position
¡¦..2.b) Skip ¡®\n¡¯ and increment count of ¡®\n¡¯ and update target position
3) Print the sub-string from target position.
*/

/* Program to print the last 10 lines. If number of lines is less
   than 10, then print all lines. */

#include <stdio.h>
#include <string.h>

#define DELIM '\n'

#if 0
void print_last_lines(char *str, int n)
{
	if (n <= 0)
		return;

	size_t cnt = 0;
	char *target_pos = NULL;

	target_pos = strrchr(str, DELIM);
	/* The strrchr function searches string for the last occurrence of c. 
	The null character terminating string is included in the search.
	*/

	if (target_pos == NULL) {
		fprintf(stderr, "ERROR: string doesn't contain '\\n' character\n");
		return;
	}

	while (cnt < n) {
		while (str < target_pos && *target_pos != DELIM)
			--target_pos;

		if (*target_pos == DELIM)
			--target_pos, ++cnt;
		else
			break;
	}

	if (str < target_pos)
		target_pos += 2;

	printf("%s\n", target_pos);
}
#endif

// Driver program to test above function
int main(void)
{
    char *str1 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9"
                 "\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17"
                 "\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";
    char *str2 = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7";
    char *str3 = "\n";
    char *str4 = "";
 
    //print_last_lines(str1, 10);
    printf("-----------------\n");
 
    //print_last_lines(str2, 10);
    printf("-----------------\n");
 
    //print_last_lines(str3, 10);
    printf("-----------------\n");
 
    //print_last_lines(str4, 10);
    printf("-----------------\n");
 
    return 0;
}
