

#include <stdio.h>

void func(int a) {
	printf("func called\n");
}

int main() {

	static int j = 5;

	int i = 1;

	while( (i++ + j++) < 10 ) {
		func(i++);
		printf("i[%d] j[%d] = i+j[%d]\n", i, j, i + j);
	}
	return 0;
}
