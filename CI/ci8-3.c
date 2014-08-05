/*
Power Set
Power Set Power set P(S) of a set S is the set of all subsets of S. 
For example 
S = {a, b, c} then 
P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.

If S has n elements in it then P(s) will have 2^n elements
*/

/*
Algorithm:

Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size
          (i) If ith bit in counter is set
               Print ith element from set for this subset
     (b) Print seperator for subsets i.e., newline
*/

#include <stdio.h>
#include <math.h>

//void printPowerSet(char[] set, int number) - compile error
void printPowerSet(char *set, int set_size)
{
	unsigned int pow_set_size = pow(2, set_size);
	printf("pow_set_size = %d \n", pow_set_size);

	int counter, j;

	for(counter=0; counter < pow_set_size; counter++) {
		for(j=0; j < set_size; j++) {
			if(counter & (1 << j))
				printf("%c", set[j]);
		}
		printf("\n");
	}

}

int main()
{
	char set[] = {'a', 'b', 'c'};
	printPowerSet(set, 3);

	getchar();
	return 0;
}

