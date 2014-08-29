/*
Given an int, write code to return the number of bits that are 1 in O(m) time, 
where m is the number of bits that are 1.
*/
#include <stdio.h>

int main() 
{
   int i, n;
   n = 0x01;

   for(i=0; n>0; ++i) n &= (n-1);

   printf("number bits : %d\n", i);
}



