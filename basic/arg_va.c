/*

Description
The C library macro void va_start(va_list ap, last_arg) initializes ap variable to be used with the va_arg and va_end macros. 
The last_arg is the last known fixed argument being passed to the function ie. the argument before the ellipsis.

This macro must be called before using va_arg and va_end.

Declaration
Following is the declaration for va_start() macro.

void va_start(va_list ap, last_arg);

Parameters
ap -- This is the object of va_list and it will hold the information needed to retrieve the additional arguments with va_arg.
last_arg -- This is the last known fixed argument being passed to the function.

*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int, ...);
int my_strcpy(char *, ...);

int main(void)
{
	printf("Sum of 10, 20 and 30 = %d\n", sum(3, 10, 20, 30) );
	printf("Sum of 4, 20, 25 and 30 = %d\n", sum(4, 4, 20, 25, 30) );

	char *strs[4] = { "Park", "Roy", "Sung", (char*)0 };
	char imsi[30] = {0};

	my_strcpy(imsi, strs[0], strs[1], strs[2], strs[3]);

	printf("my_strcpy [%s]\n", imsi);

	return 0;
}

int my_strcpy(char *p1, ...) {

	va_list list;
	char *temp = NULL;
	int str_len = 0;
	char *re_str = NULL;
	
	//va_start(list, p1);
	//while( (temp = va_arg(list, char*)) != NULL ) {
	//	str_len += strlen(temp);
	//}
	//va_end(list);
	//p1 = (char*)malloc(str_len + 1);

	va_start(list, p1);

	while( (temp = va_arg(list, char*)) != NULL ) {
		strcat(p1, temp);
	}

	va_end(list);

	return 0;
	
}


int sum(int num_args, ...)
{
	int val = 0;
	va_list ap;
	int i;

	va_start(ap, num_args);

	for(i = 0; i < num_args; i++)
	{
		val += va_arg(ap, int);
	}

	va_end(ap);

	return val;
}
		
