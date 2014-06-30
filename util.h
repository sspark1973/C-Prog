#ifndef UTIL_H
#define UTIL_H

#include "type_def.h"
#include <stdarg.h>

extern void mem_cpy(void *target, void *source, uint32 size);
extern void mem_set(void *target,uint8 value, uint32 size);
extern uint32 string_len(char *input);
extern uint32 string_n_cmp(char *str1, char *str2, uint32 len);

#endif
