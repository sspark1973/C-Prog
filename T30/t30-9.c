/*
9. Write a program to check whether the given number is a palindromi c number.
If a number, which when read in both forward and backward way is same, then such a number is called a palindrome number.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int n, temp, rev=0, rem;

	printf("Enter any number:\n");
	scanf("%d", &n);

	temp = n;

	while (temp > 0) {
		rem = temp%10;
		rev = rev*10 + rem;
		temp /= 10;
	}

	if(n == rev) {
		printf("Given number[%d] is a palindromi c number\n", n);
	} else {
		printf("Given number[%d] is not a palindromi c number\n", n);
	}

	char str[20];
	int i, length;
	int flag = 0;

	printf("Enter a string:\n");
	scanf("%s", str);
	length = strlen(str);

	for(i=0; i < length/2; i++) {
		if(str[i] != str[length-i-1]) {
			flag = 1;
			break;
		}
	}

	if(flag)
		printf("%s is not a palindrome\n", str);
	else
		printf("%s is a palindrome\n", str);


	return 0;
}
