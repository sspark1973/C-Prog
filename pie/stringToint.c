/*
C program to convert string to integer: 
It is frequently required to convert a string to an integer in applications. 
String should consists of digits only and an optional '-' (minus) sign at beginning for integers. 
For string containing other characters 
we can stop conversion as soon as a non digit character is encountered 
but in our program we will handle ideal case when only valid characters are present in string. 
Library function atoi can be used to convert string to an integer but we will create our own function.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DIGITS 10

char *IntToStr(int num) {
	int i = 0, j = 0;
	bool isNeg = false;

	char temp[MAX_DIGITS + 1] = {0};

	if(num < 0) {
		num = -num;
		isNeg = true;
	}

	do {
		temp[i++] = (char)((num % 10) + '0');
		num /= 10;
	} while(num != 0);

	int slen = i;
	char *str = (char *)malloc(sizeof(slen + 1));

	if(!temp)
		return NULL;

	if(isNeg)
		str[j++] = '-';

	while( i > 0 )
		str[j++] = temp[--i];

	str[j] = '\0';

	printf("num[%d] str[%s]\n", num, str);

	return str;
		

}


int StrToInt(char a[]) {
	int c, sign = 0, offset = 0, n = 0;

	if(a[0] == '-')
		sign = -1;

	if(sign == -1)
		offset = 1;

	for(c = offset; a[c] != '\0'; c++) {
		n = n * 10 + a[c] - '0';
	}

	if(sign == -1)
		n = -n;

	return n;
}

int main()
{
	char a[100];
	int n;

	printf("input a valid string to convert to integer\n");
	scanf("%s", a);

	n = StrToInt(a);

	printf("String = %s\n Integer = %d\n", a, n);

	char *str = IntToStr(n);

	return 0;
}

