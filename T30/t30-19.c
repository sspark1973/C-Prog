/*
19.Write a C program which asks the user for a number between 1 to 9 and shows the number. 

If the user inputs a number out of the specified range, 
the program should show an error and prompt the user for a valid input.
*/

#include <stdio.h>

int getnumber();

int main()
{
	int input = 0;
	input = getnumber();

	while(!(input

