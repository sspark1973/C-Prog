/* Implement an algorithm to determine if a string has all unique characters. 
  What if you can not use additional data structures?
*/

/*
  For simplicity, assume char set is ASCII 
  (if not, we need to increase the storage size. The rest of the logic would be the same). 
  NOTE: This is a great thing to point out to your interviewer!
  */

#include <stdio.h>
#include <string.h>
#include "type_def.h"

bool8 isUniqueChar(char *str)
{
  int i;
  int len = strlen(str);  
  bool8 char_set[256] = {0};
  //memset(char_set, 0, 256);
  
  for(i=0; i < len; i++)
  {
    if(char_set[str[i]])
      return FALSE;
    char_set[str[i]] = TRUE;
  }
  
  return TRUE;
}

/* We can reduce our space usage a little bit by using a bit vector. 
  We will assume, in the below code, that the string is only lower case ‘a’ through ‘z’. 
  This will allow us to use just a single int
*/
bool8 isUniqueCharVB(char *str)
{
  int checker = 0, i, val;
  
  for(i=0; i < strlen(str); i++) {
    val = str[i] - 'a';
    if((checker & (1 << val)) > 0 ) return FALSE;
    checker |= (1 << val);
  }
  
  return TRUE;
}

main()
{
  char *str = "abcdef";
  char *str2 = "abcdefd";
  
  printf("Is %s Unique string : %d\n", str, isUniqueChar(str));
  printf("Is %s Unique string : %d\n", str, isUniqueCharVB(str));
  printf("Is %s Unique string : %d\n", str, isUniqueChar(str2));
  printf("Is %s Unique string : %d\n", str, isUniqueCharVB(str2));
}

