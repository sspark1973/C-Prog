/*
find max number of repetitions in an array.like {2,3,4,5,2,3,2} max repeat is 2. 
optimize it for space then in time.
*/

#include <stdio.h>

int main() 
{
   int array[] = {2,3,4,5,2,3,2};

   int i, j, count = 0, maxCount = 0, index = 0;
   int len = sizeof(array)/sizeof(array[0]);

   for(i=0; i<len; ++i) {
	  count = 0;

      for(j=0; j<len; ++j) {
   	     if(array[i] == array[j])
	  	    count += 1;
   	  }

	  if(count > maxCount) {
	  	maxCount = count;
		index = i;
		
	  }
   }

   printf("array[%d]=%d max count = [%d]\n", index, array[index], maxCount);
}

   
   
