/*
Q : 
Assume you have a method isSubstring which checks if one word is a substring of another. 
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring 
(i.e., “waterbottle” is a rotation of “erbottlewat”).

A :
Just do the following checks
1. Check if length(s1) == length(s2). If not, return false.
2. Else, concatenate s1 with itself and see whether s2 is substring of the result.
input: s1 = apple, s2 = pleap ==> apple is a substring of pleappleap
input: s1 = apple, s2 = ppale ==> apple is not a substring of ppaleppale
*/

#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 80

int main()
{
  char str1[] = "apple";
  char str2[] = "pleap";
  char str3[NO_OF_CHARS] = "";
  char *pch;
  
  strcat(str3, str2);
  strcat(str3, str2);
  
  pch = strstr(str3, str1);
  
  printf("pch: %s\n", pch);
  
  return 0;
}
