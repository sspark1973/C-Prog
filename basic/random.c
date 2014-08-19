/*
Given a function which produces a random integer in the range 1 to 5, 
write a function which produces a random integer in the range 1 to 7.


This is equivalent to Adam Rosenfield's solution, 
but may be a bit more clear for some readers. 

It assumes rand5() is a function that returns a statistically random integer in the range 1 through 5 inclusive.
*/

int rand7()
{
	int vals[5][5] = {
			{ 1, 2, 3, 4, 5 },
			{ 6, 7, 1, 2, 3 },
			{ 4, 5, 6, 7, 1 },
			{ 2, 3, 4, 5, 6 },
			{ 7, 0, 0, 0, 0 }};

	int result = 0;

	while(result == 0) {
		int i = rand5();
		int j = rand5();
		result = vals[i-1][j-1];
	}
	return result;
}

/*
How does it work? Think of it like this: 
imagine printing out this double-dimension array on paper, 
tacking it up to a dart board and randomly throwing darts at it. 

If you hit a non-zero value, it's a statistically random value between 1 and 7, 
since there are an equal number of non-zero values to choose from. 

If you hit a zero, just keep throwing the dart until you hit a non-zero. 
That's what this code is doing: the i and j indexes randomly select a location on the dart board, 
and if we don't get a good result, we keep throwing darts.

Like Adam said, this can run forever in the worst case, but statistically the worst case never happens. :)
*/
