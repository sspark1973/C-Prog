/*
You are given two 32-bit numbers, N and M, 
and two bit positions, i and j  

Write a method to set all bits between i and j in N equal to M 
(e g , M becomes a substring of N located at i and starting at j)   

EXAMPLE: 
Input: N = 10000000000, M = 10101, i = 2, j = 6 
Output: N = 10001010100
*/

#include <stdio.h>

/*
bits counts from right to left. starting at index 0
N = 1010 1011 1101 1110
M = 1001 0110
i = 4, j = 11. i.e : should be doing: 1010|---- ----|1110           
max      = 1111 1111 1111 1111
left(j)  = 1111 1000 0000 0000
right(i) = 0000 0000 0000 0111
mask     = 1111 1000 0000 0111
result   = 
------------------------- left -----------------------------
(1<<j) 0001 0000 0000 0000     (max)   1111 1111 1111 1111 
  1    0000 0000 0000 0001 -   (temp)  0000 1111 1111 1111 -
       -------------------             -------------------
(temp) 0000 1111 1111 1111     (left)  1111 0000 0000 0000 
------------------------------------------------------------
 
----------- right -----------  -----------------------------
(1<<i)  0000 0000 0001 0000    (left)  1111 0000 0000 0000
  1     0000 0000 0000 0001 -  (right) 0000 0000 0000 1111 |
        -------------------            -------------------
(right) 0000 0000 0000 1111    (mask)  1111 0000 0000 1111
-----------------------------   ----------------------------
 
-----------------------------   ----------------------------
(n)     1010 1011 1101 1110     (temp) 1010 0000 0000 1110
(mask)  1111 0000 0000 1111 &   (m<<i) 0000 1001 0110 0000 |
        -------------------            -------------------
(temp)  1010 0000 0000 1110   (result) 1010 1001 0110 1110
-----------------------------   ----------------------------
*/

int updateBits(int n, int m, int i, int j)
{
	int max = ~0; /* All 1's */
	int left = max - (( 1 << j) - 1);
	int right = ((1 << i) - 1);
	int mask = left | right;

	return (n & mask) | (m << i);
}

int main()
{
	int n = 0xabde;
	int m = 0x96;
	int i=4, j=11;
	int result = 0;

	result = updateBits(n, m, i, j);

	printf("result:%#x\n", result);

	
	return 0;
}

