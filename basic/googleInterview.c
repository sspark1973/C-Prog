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

