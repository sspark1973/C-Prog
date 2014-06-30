#include "type_def.h"
#include "util.h"

#define MAX_STRING_LENGTH 19

uint32 atoi(char *input)
{
  uint32 len = string_len(input);
  uint32 result = 0;
  uint32 i;
  
  for(i=0; *input != '\0' && i < len; i++, input++) {
    if(*input >= '0' && *input <= '9') {
      result = result*10 + (*input - '0');
    } else {
      result = 0;
    }
  }
  
  return result;
}

/* Implement your own itoa()
itoa function converts integer into null-terminated string. 
It can convert negative numbers too. The standard definition of itoa function is give below:-

char* itoa(int num, char* buffer, int base) 
The third parameter base specify the conversion base. For example:- 
if base is 2, then it will convert the integer into its binary compatible string or 
if base is 16, then it will create hexadecimal converted string form of integer number.

If base is 10 and value is negative, the resulting string is preceded with a minus sign (-). 
With any other base, value is always considered unsigned.

Reference: http://www.cplusplus.com/reference/cstdlib/itoa/?kw=itoa

Examples:

  itoa(1567, str, 10) should return string "1567"
  itoa(-1567, str, 10) should return string "-1567"
  itoa(1567, str, 2) should return string "11000011111"
  itoa(1567, str, 16) should return string "61f"

*/

/* The Itoa code is in the public domain */
static const char dig[] =
	"0123456789"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *itoa(int value, char *str, int radix)
{
  int n = 0, neg = 0;
  unsigned int v;
  char *p, *q;
  char c;
  
  if(radix == 10 && value < 0) {
    value = -value;
    neg = 1;
  }
  
  v = value;
  
  do {
    str[n++] = dig[v%radix];
    v /= radix;
  } while(v);
  
  if(neg) {
    str[n++] = '-';
  }
  str[n] = '\0';
  
  for(p = str, q = p + (n-1); p < q; ++p, --q) {
    c = *p, *p = *q, *q = c;
  }
  
  return str;
}

void mem_cpy(void *target, void *source, uint32 size)
{
  uint32 i;
  uint8 *target_p = (uint8 *)target;
  uint8 *source_p = (uint8 *)source;
  
  for(i=0; i < size; i++, target_p++, source_p++) {
    *target_p = *source_p;
  }
  
  return;
}

void mem_set(void *target, uint8 value, uint32 size)
{
  uint32 i;
  uint8 *target_p = (uint8 *)target;
  
  for(i=0; i < size; i++, target_p++) {
    *target_p = value;
  }
  
  return;
}

/* return : 
      0 : if strings are same
      1 : if strings are different
*/
uint32 string_n_cmp(char *str1, char *str2, uint32 len)
{
  uint32 i;
  uint32 result = 0;
  
  for(i=0; i < len; i++) {
    if(str1[i] != str2[i]) {
      result = 1;
      break;
    }
  }
  
  return result;
}

uint32 string_len(char *input)
{
  uint32 len = 0;
  
  while(*input != '\0' && len < MAX_STRING_LENGTH) {
    len++;
    input++;
  }
  
  if(len == MAX_STRING_LENGTH) {
    return 0;
  } else {
    return len;
  }
}

int main(void)
{
  return 0;
}
