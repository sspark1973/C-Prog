/*
3 3 Imagine a (literal) stack of plates   
If the stack gets too high, it might topple(³Ñ¾îÁöå´Ù).   
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
Implement a data structure SetOfStacks that mimics this.   
SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity
SetOfStacks push() and SetOfStacks pop() should behave identically to a single stack 
(that is, pop() should return the same values as it would if there were just a single stack) 

FOLLOW UP 
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class SetOfStacks
{
	private:
		static const int max = 100;
		int arr[max];
		int capacity;
		int top;

	public:
		SetOfStacks(int capacity) { capacity = capacity; top = -1; }
		void push(int v);
		int pop();
		int popAt(int index);
		int leftShift(int index, bool removeTop);
		bool isEmpty();
		bool isFull();
		void displayStack();
};

bool SetOfStacks::isEmpty()
{
	if( top == -1 )
		return true;
	return false;
}

bool SetOfStacks::isFull()
{
	if( top == (max - 1) )
		return true;
	return false;
}

void SetOfStacks::push(int data)
{
	if( isFull() )
		abort();

	top++;
	arr[top] = data;
	
	return;
}

int SetOfStacks::pop()
{
	int data;
	
	if( isEmpty() )
		abort();

	top;
	data = arr[top--];
	
	return data;
}

int SetOfStacks::popAt()
{
	return leftShift(index, true);
}

int SetOfStacks::leftShift(int index, bool removeTop)
{
	return leftShift(index, true);
}


void SetOfStacks::displayStack()
{
	int i;
	
	if( isEmpty() )
		return;

	for(int i=0; i <= top; i++) {
		cout << arr[i] << "\t";
	}

	cout << endl;

}


int main()
{
	SetOfStacks sStack(100);

	sStack.push(10);
	sStack.push(20);
	sStack.displayStack();
	
	return 0;
}

