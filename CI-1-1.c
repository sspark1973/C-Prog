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
  
  for(i=0; i < len; i++)
  {
    if(char_set[str[i]])
      return FALSE;
    char_set[str[i]] = TRUE;
  }
  
  return TRUE;
}

main()
{
  char *str = "abcdef";
  
  printf("Is %s Unique string : %d\n", str, isUniqueChar(str));
}

