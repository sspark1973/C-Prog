/*
** Describe how you could use a single array to implement three stacks.
*/

#include <stdio.h>

#define SINGLE_STACK_SIZE 100

int stack[ SINGLE_STACK_SIZE * 3 ];
int stack_pointer[ 3 ] = { -1, -1, -1 };

int push( int stack_index, int value )
{
	if( stack_pointer[stack_index] == SINGLE_STACK_SIZE - 1 )
	{
		printf("The stack %d is full.\n", stack_index);
		return -1;
	}

	stack[ stack_index * SINGLE_STACK_SIZE + ++stack_pointer[stack_index] ] = value;
	printf("Push to the stck %d: %d\n", stack_index, value);

	return (stack_pointer[stack_index]);
}

int pop( int stack_index )
{
	int value;

	if( stack_pointer[stack_index] == -1 )
	{
		printf("There is nothing in the stack %d\n", stack_index);
		return -1;
	}

	value = stack[ stack_index * SINGLE_STACK_SIZE + stack_pointer[stack_index] ];
	stack[ stack_index * SINGLE_STACK_SIZE + stack_pointer[stack_index]-- ] = 0;
	printf("Pop from the stck %d: %d\n", stack_index, value);

	return value;
}

int peek( int stack_index )
{
	int value;

	if( stack_pointer[stack_index] == -1 )
	{
		printf("There is nothing in the stack %d\n", stack_index);
		return -1;
	}
	
	value = stack[ stack_index * SINGLE_STACK_SIZE + stack_pointer[stack_index] ];
	printf("Peek from the stck %d: %d\n", stack_index, value);

	return value;
}

void main( void )
{
	push( 1, 5 );
	push( 1, 6 );
	push( 0, 100 );
	push( 1, 7 );
	pop( 0 );
	pop( 0 );
	pop( 1 );
	peek( 1 );
	pop( 1 );
	pop( 1 );
}
	
