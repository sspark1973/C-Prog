/*
Write code to reverse a C-Style String. 
(C-String means that “abcd” is represented as five characters, including the null character.)
*/

#include <stdio.h>
/*
This is a classic interview question. 
The only “gotcha” is to try to do it in place, and to be careful for the null character.
*/
void reverse(char *str)
{
  char *end = str;
  char tmp;
  
  if(str) {
    while(*end) {
      ++end;
    }

    --end;
  
    while(str < end) {
      tmp = *str;
      *str = *end;
      *end = tmp;
      ++str;
      --end;
      
    }
  }
}
  


main()
{
  char *str = "gotcha";
  
  printf("%s \n", str);
  reverse(str);
  printf("reverse %s\n", str);
}
