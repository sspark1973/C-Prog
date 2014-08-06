#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *str = "abcabcabcabc";

bool subNstring(char *sub)
{

	bool result = false;

	if(sub == NULL)
		return result;
		
	int len = strlen(sub);
	int lenM = strlen(str);
	printf("len[%d] lenM[%d]\n", len, lenM);

	if((lenM % len) || (len > lenM))
		return result;

	int rep = lenM / len;
	int i, j, n = 0;

	result = true;

	for(i = 0; i < rep; i++) {
		for(j = 0; j < len; j++) {
			printf("str[%d]=%c, sub[%d]=%c\n", j+n, str[j+n], j, sub[j]);
			if(str[j + n] != sub[j]) {
				result = false;
				break;
			}
		}

		if(result == false) {
			printf("out first for loop\n");
			break;
		}
		n += len;
	}

	return result;
}

	

int main()
{
	bool result = false;
	char *substring = "ab";

	result = subNstring(substring);

	printf("result [%d] \n", result);
	
	return 0;
}
