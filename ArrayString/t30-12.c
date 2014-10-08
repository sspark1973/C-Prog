/*
12.Write a program to print"Hello World"without using semicolon anywhere in the code.
Generally when we use printf("") statement, we have to use a semicolon at the end. 

If printf is used inside an if Condition, semicolon can be avoided.

printf function returns the length of the string printed. 
Hence the statement if (printf("H ello World")) prints the string

"Hello World".

*/

#include <stdio.h>

int main()
{
	if(printf("Hello World\n")) {
		//do nothing
	}

	
	/*
	13.Write a program to print a semicolon without using a semicolon anywhere in the code.
	Generally when use printf("") statement we have to use semicolon at the end.
	
	If we want to print a semicolon, we use the statement: printf(";" );
	In above statement, we are using two semicolons . 
	
	The task of printing a semicolon without using semicolon anywhere in the code can be accomplish ed by using the ascii value of';'
	which is equal to 59.
	*/
	
	if(printf("%c\n", 59)) {
		// print semicolon
	}

	return 0;
}

