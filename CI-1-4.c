/*
  http://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
  
  Count characters
  This method assumes that the set of possible characters in both strings is small. 
  In the following implementation, 
  it is assumed that the characters are stored using 8 bit and there can be 256 possible characters.
  1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
  2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
  3) Compare count arrays. If both count arrays are same, then return true.
*/
#include <stdio.h>
#include "type_def.h"

#define NO_OF_CHARS 256


/*
typedef int bool;
#define false 0
#define true 1

typedef enum { false, true } bool;
*/

//typedef enum {false, true} boolean;

/* function to check whether two strings are anagram of each other */
bool8 areAnagram(char *str1, char *str2)
{
  // Create two count arrays and initialize all values as 0
  int count1[NO_OF_CHARS] = {0};
  int count2[NO_OF_CHARS] = {0};
  int i;
  
  // For each character in input strings, increment count in
  // the corresponding count array
  for (i=0; str1[i] && str2[i]; i++)
  {
    count1[str1[i]]++;
    count2[str2[i]]++;
  }
  
  // If both strings are of different length. Removing this condition
  // will make the program fail for strings like "aaca" and "aca"
  if(str1[i] || str2[i])
    return FALSE;
    
  // Compare count arrays
  for(i=0; i < NO_OF_CHARS; i++)
    if(count1[i] != count2[i])
      return FALSE;
      
  return TRUE;
}

/* The above implementation can be further to use only one count array instead of two. 
   We can increment the value in count array for characters in str1 and decrement for characters in str2. 
   Finally, if all count values are 0, then the two strings are anagram of each other. 
*/
bool8 areAnagramAdvance(char *str1, char *str2)
{
  int count[NO_OF_CHARS] = {0};
  int i;
  
  for(i=0; str1[i] & str2[i]; i++)
  {
    count[str1[i]]++;
    count[str2[i]]--;
  }
  
  if(str1[i] | str2[i])
    return FALSE;
    
  for(i=0; i < NO_OF_CHARS; i++)
    if(count[i])
      return FALSE;
  
  return TRUE;
}

int main()
{
  char str1[] = "geeksforgeeks";
  char str2[] = "forgeeksgeeks";
  
  if(areAnagram(str1, str2))
    printf("The two strings are anagram of each other\n");
  else
    printf("The two strings are not anagram of each other\n");


  if(areAnagramAdvance(str1, str2))
    printf("The two strings are anagram of each other\n");
  else
    printf("The two strings are not anagram of each other\n");
    
  return 0;
}
