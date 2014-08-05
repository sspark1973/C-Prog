/*
 * Imagine a robot sitting on the upper left hand corner of an NxN grid. 
 * The robot can only move in two directions: right and down. 
 * How many possible paths are there for the robot?
 *
 FOLLOW UP
 * Imagine certain squares are ¡°off limits¡±, such that the robot can not step on them. 
 * Design an algorithm to get all possible paths for the robot.
 */
#include <stdio.h>

#define ROW 4
#define COL 4

int countPaths(int (*target)[COL], int n, int row, int col)
{
	int innerCount = 0;

	if(n == 1)
		return 2;

	if(target[row][col+1] == 0)
		innerCount += countPaths(target, n-1, row, col+1);

	if(target[row+1][col] == 0)
		innerCount +=countPaths(target, n-1, row+1, col);
	
	
	return innerCount;
}

int main(void)
{
	int grid[ROW][COL] = {0};
	int n = ROW;
	int pathNum = countPaths(grid, n, 0, 0);
	printf("pathNum = %d \n", pathNum);

	return 0;
}
