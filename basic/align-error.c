#include <stdio.h>

void main(void)
{
    char array[4] = {0, 1, 2, 3};
    float *fpek;
    int i;
    for(i=0;i<4;i++)
    {
        fprintf(stderr,"i = %d ", i);
        fpek = (float *)(&array[i]);
		/* 
		even if your system-float is 4 bytes 
		you're immediately addressing (likely unaligned) data i bytes out of range of your array when assigning with i>0.
		*/
        fprintf(stderr, "fpek = %lx ", (unsigned long) fpek);
        *fpek = (float) i + 10;
        fprintf(stderr, "*fpek = %.2f\n", *fpek);
    }
}
