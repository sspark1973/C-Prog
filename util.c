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
