/*
19.5 The Game of Master Mind is played as follows:
The computer has four slots containing balls that are red (R), yellow (Y), green (G) or blue (B). 

For example, the computer might have RGGB (e.g., Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).
You, the user, are trying to guess the solution. You might, for example, guess YRGB.
When you guess the correct color for the correct slot, you get a ¡°hit¡±. 
If you guess a color that exists but is in the wrong slot, you get a ¡°pseudo-hit¡±. 

For example, the guess YRGB has 2 hits and one pseudo hit.
For each guess, you are told the number of hits and pseudo-hits.
Write a method that, given a guess and a solution, returns the number of hits and pseudo hits.
*/

#include <stdio.h>

struct result {
	int hits;
	int pseudoHits;
};

struct result estimate(char *guess, char *solution)
{
	struct result res;
	int solution_mask = 0, i;
	res.hits = 0;
	res.pseudoHits = 0;

	for(i = 0; i < 8; ++i) {
//		solution_mask |= 1 << (1 + solution[i] - 'A'); it's okay without '1 + '
		solution_mask |= 1 << (solution[i] - 'A');
		printf("mask[%#010x] math[%d] [%d]\n", solution_mask, (1 + solution[i] - 'A'), solution[i] - 'A');
	}

	for(i = 0; i < 8; ++i) {
		if(guess[i] == solution[i]) {
			++res.hits;
//		} else if ((solution_mask & ( 1 << (1 + guess[i] - 'A'))) >= 1) {
		} else if ((solution_mask & ( 1 << (guess[i] - 'A'))) >= 1) {
			++res.pseudoHits;
		}
	}

	
	//res.hits = 1;
	//res.pseudoHits = 2;

	return res;
}

int main()
{
	char *solution = "RGGBABBA";
	char *guess = "YRGBDBDA";
	struct result res = estimate(guess, solution);

	printf("Hits:%d PseudoHits:%d\n", res.hits, res.pseudoHits);
	return 0;
}
