/*
Given a partially filled 9¡¿9 2D array ¡®grid[9][9]¡®, 
the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, 
and subgrid of size 3¡¿3 contains exactly one instance of the digits from 1 to 9.
*/

/*
Naive Algorithm
The Naive Algorithm is to generate all possible configurations of numbers from 1 to 9 to fill the empty cells. 
Try every configuration one by one until the correct configuration is found.

Backtracking Algorithm
Like all other Backtracking problems, 
we can solve Sudoku by one by one assigning numbers to empty cells. 

Before assigning a number, we check whether it is safe to assign. 
We basically check that the same number is not present in current row, current column and current 3X3 subgrid. 
After checking for safety, we assign the number, and recursively check whether this assignment leads to a solution or not. 
If the assignment doesn¡¯t lead to a solution, then we try next number for current empty cell. 
And if none of number (1 to 9) lead to solution, we return false.

  Find row, col of an unassigned cell
  If there is none, return true
  For digits from 1 to 9
    a) If there is no conflict for digit at row,col
        assign digit to row,col and recursively try fill in rest of grid
    b) If recursion successful, return true
    c) Else, remove digit and try another
  If all digits have been tried and nothing worked, return false
Following is C++ implementation for Sudoku problem. It prints the completely filled grid as output.
*/

#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0

#define N 9

bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
	for(row = 0; row < N; row++)
		for(col = 0; col < N; col++)
			if(grid[row][col] == UNASSIGNED)
				return true;

	return false;
}

bool UsedInRow(int grid[N][N], int row, int num)
{
	for(int col = 0; col < N; ++col) {
		if(grid[row][col] == num)
			return true;
	}
	
	return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
	for(int row = 0; row < N; ++row) {
		if(grid[row][col] == num)
			return true;
	}
	return false;
}

bool UsedInBox(int grid[N][N], int row_offset, int col_offset, int num)
{

	for(int row = 0; row < 3; ++row)
		for(int col = 0; col < 3; ++col) {
			if(grid[row+row_offset][col+col_offset] == num)
				return true;
		}
		return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
	return	!UsedInRow(grid, row, num) &&
			!UsedInCol(grid, col, num) &&
			!UsedInBox(grid, row - row%3, col - col%3, num); // 000 333 666
}


bool SolveSudoku(int grid[N][N])
{
	int row, col;

	if(!FindUnassignedLocation(grid, row, col))
		return true;

	//printf("%s row[%d]col[%d]\n", __FUNCTION__, row, col);

	for(int num = 1; num <= 9; num++) {
		if(isSafe(grid, row, col, num)) {
			grid[row][col] = num;

			if(SolveSudoku(grid))
				return true;

			printf("%s row[%d]col[%d] = [%d]\n", __FUNCTION__, row, col, grid[row][col]);			
			// failure, unmake & try again
			grid[row][col] = UNASSIGNED;

		}
	}
	return false;
}

void printGrid(int grid[N][N])
{
	int row, col;
	
	for(row = 0; row < N; ++row) {
		for(col = 0; col < N; ++col)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}

bool UsedInRowValid(int grid[N][N], int row, int col_offset, int num)
{
	for(int col = 0; col < N; ++col) {
		if(col == col_offset) continue;
		if(grid[row][col] == num)
			return true;
	}
	
	return false;
}

bool UsedInColValid(int grid[N][N], int row_offset, int col, int num)
{
	for(int row = 0; row < N; ++row) {
		if(row == row_offset) continue;
		if(grid[row][col] == num)
			return true;
	}
	return false;
}

bool UsedInBoxValid(int grid[N][N], int row_offset, int col_offset, int num)
{
	int rowStart = row_offset - row_offset % 3;
	int colStart = col_offset - col_offset % 3;
	
	for(int row = 0; row < 3; ++row)
		for(int col = 0; col < 3; ++col) {
			//printf("row[%d]rowStart[%d]-col[%d]colStart[%d]\n", row, rowStart, col, colStart);
			if((row == row_offset%3) && (col == col_offset%3)) continue;
			if(grid[row+rowStart][col+colStart] == num)
				return true;
		}
		return false;
}

bool isSafeValid(int grid[N][N], int &row, int &col, int num)
{
	return	!UsedInRowValid(grid, row, col, num) &&
			!UsedInColValid(grid, row, col, num) &&
			!UsedInBoxValid(grid, row, col, num);
}

bool isValidSudoku(int grid[N][N])
{
	for(int row = 0; row < N; ++row) {
		for(int col = 0; col < N; ++ col) {
			int num = grid[row][col];
			if(!isSafeValid(grid, row, col, num)) {
				printf("isValidSudoku row[%d]col[%d] = %d\n", row, col, num);
				return false;
			}
		}
	}
	return true;
}
		
int main()
{
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	int grid_ok[N][N] =	{ {3, 1, 6, 5, 7, 8, 4, 9, 2},
						  {5, 2, 9, 1, 3, 4, 7, 6 ,8},
						  {4, 8, 7, 6, 2, 9, 5, 3, 1},
						  {2, 6, 3, 4, 1, 5, 9, 8, 7},
						  {9, 7, 4, 8, 6, 3, 1, 2, 5},
						  {8, 5, 1, 7, 9, 2, 6, 4, 3},
						  {1, 3, 8, 9, 4, 7, 2, 5, 6},
						  {6, 9, 2, 3, 5, 1, 8, 7, 4},
						  {7, 4, 5, 2, 8, 6, 3, 1, 9}};
	if(SolveSudoku(grid) == true)
		printGrid(grid);
	else
		printf("No solution exists\n");


	if(isValidSudoku(grid_ok))
		printf("It's Valid\n");
	else
		printf("It's not Valid\n");

	return 0;
}

