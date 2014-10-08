/*
How do you implement 3 stacks using a single array?
*/

#include <iostream>

int stackSize = 300;
int indexUsed = 0;
int stackPointer[3] = {-1, -1, -1};

public class StackNode {
	public int previous;
	public int value;
	public StackNode(int p, int v) {
		this.value = v;
		this.previous = p;
	}
}

int main(int argc, char **argv)
{
	return 0;
}

