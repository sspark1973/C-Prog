/*
Write code to reverse a C-Style String. 
(C-String means that “abcd” is represented as five characters, including the null character.)
*/

#include <stdio.h>
#include <string.h>
/*
This is a classic interview question. 
The only “gotcha” is to try to do it in place, and to be careful for the null character.
*/
char *reverse(char *str)
{
  char *src, *dst;
  char tmp;
  int len;
  
  if(str) {
    len = strlen(str);
    
    if(len > 1) {
      src = str;
      dst = src + len - 1;
    
      while(src < dst) {
        tmp = *src;
        *src = *dst;
        *dst = tmp;
        ++src;
        --dst;
      }
    }
  }
  
  return str;
}

char *str[] = {"", "a", "ab", "abc", "adbcd"};

main()
{
  int i;
  char s[256];
  
  for (i=0; i < sizeof(str)/sizeof(str[0]); i++) {
    strcpy(s, str[i]);
    printf("%s -> %s\n", str, reverse(s));
  }
}
