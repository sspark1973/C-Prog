/*
Q1:  

ASCII ->    'A' -> 65

1-byte:    0xxx  xxxx
2-byte:    110x  xxxx      10xx  xxxx
3-byte:    1110  xxxx      10xx  xxxx     10xx  xxxx
4-byte:    1111  0xxx      10xx  xxxx     10xx  xxxx     10xx  xxxx
¡¦
¡¦

example : 

   1101 0000	1010 0010		0100 0000 = valid string

   1110 0010	1100 0000 = not valid string

Given a string of byte sequence, report if it's valid
*/

#include <stdio.h>
#include <stdbool.h>

int numberOfOnes(char a) {
	int count = 0, i;

	for(i=7; i >= 0; i--) {
		if (( a >> i) & 0x1) count++;
		else break;
	}

	printf("%s count = [%d]\n", __FUNCTION__,  count);
	return count;
}

bool checkNextString(char *str, int count) {

	bool isValid = false, i;

	for(i = 0; i < (count - 1); i++) {
		char a = str[i];
		if((a >> 6) & 0x10) {
			isValid = true;
		} else {
			isValid = false;
			break;
		}
	}

	printf("checkNextString isValid[%d]\n", isValid);

	return isValid;
}	

bool inValid(char *str)
{
	if(str == NULL)
		return false;

	char a;
	bool isValid = true;
	int count = 0;
	
	while(*str) {
		a = *str;

		printf("inValid c[%x] \n", a);
		count = numberOfOnes(a); 
		if(count > 1) {
			str++;
			isValid = checkNextString(str, count);
			if(isValid) {
				str = str + (count - 1);
				printf("inValid str[%s]\n", str);
			}
		} else {
			str++;
		}
	}
	return isValid;
}

int main(void)
{
	char str[5] = {0x41, 0xc8, 0xa3, 0x41, NULL};
	bool isValid = inValid(str);
	printf("isValid = %d\n", isValid);
	return 0;
}

