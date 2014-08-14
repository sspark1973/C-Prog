#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
	struct Element *next;
	void *data;
} Element;

bool push(Element **stack, void *data)
{
	Element *elem = (Element *)malloc(sizeof(Element));
	if(!elem)
		return false;

	elem->data = data;
	elem->next = *stack;
	*stack = elem;
	return true;
}

bool pop(Element **stack, void **data)
{
	Element *elem;
	if(!(elem = *stack)) return false;

	*data = elem->data;
	*stack = elem->next;
	free(elem);
	return true;
}

bool deleteStack(Element **stack)
{
	Element *next;

	while(*stack) {
		next = (*stack)-> next;
		free(*stack);
		*stack = next;
	}

	return true;
}
	
int main()
{
	return 0;
}
