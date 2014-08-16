#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 256
char input[] = "Hello world dude"; // -> "Helo wrdu"

int main()
{
	int input_size = strlen(input);
	bool used[MAX_LEN] = {0};
	char new_str[MAX_LEN] = {0};
		
	int i, j;

	for(i = 0; i < input_size; ++i) {
		if(used[input[i]] == 0) {
			used[input[i]] = 1;
			new_str[j] = input[i];
			j++;
		}

		//new_str[j] = '\0';
	}

	printf("%s -> %s\n", input, new_str);
	return 0;
}
	
	
