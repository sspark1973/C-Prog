#include <stdio.h>
 
int test(int i)
{
  if( __builtin_expect(i > 0, 1) )
  {
    i += 4;
    i *= 2;
  }
  else
  {
    i -= 4;
    i /= 2;
  }
 
  return i;
}
 
int main()
{
  printf( "%d\n", test(-3));
  return 0;
}

