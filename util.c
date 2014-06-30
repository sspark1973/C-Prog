#include "type_def.h"

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

int main(void)
{
  return 0;
}
