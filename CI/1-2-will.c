
/*
 * 1.2 Write code to reverse a C-Style String.
 *
 */



#include <stdio.h>

#define SWAP_NOT_USING_TEMP_VARIABE

int reverse(char *str)
{
	char *end = str;
	char *start = str;
	char temp;

	/* Input error handling */
	if(*start == 0)	{
		printf("Input is Null!!!\n");
		return -1;
	}

	printf("input  : %s\n", str);

	/* Move end to point to last charactor */
	while(*end !=0) {
		end++;
	}

	/* Move before NULL */
	end--;

	while(start < end) {

		/* swap charactor */
		printf("swapping %c %c ->",*start, *end);

#if !defined(SWAP_NOT_USING_TEMP_VARIABE)
		temp = *start;
		*start = *end;
		*end = temp;
#else
		*start = *start ^ *end;
		*end = *start ^ *end;
		*start = *start ^ *end;

#endif
		printf("%c %c\n",*start, *end);
		start++;
		end--;
	}

	printf("output : %s\n", str);
	return 1;
}

void main(void)
{
	char str1[] = "";
	char str2[] = "ab";
	char str3[] = "abc";
	char str4[] = "abcd";


	reverse(str1);
	reverse(str2);
	reverse(str3);
	reverse(str4);
	return;
}


