/*
Q : You are given an array of n integers which can contain integers from 1 to n only . 
Some elements can be repeated multiple times and some other elements can be absent from the array . 
Write a running code on paper which takes O(1) space apart from the input array and O(n) time to print which elements are not present in the array 
and the count of every element which is there in the array along with the element number .
*/

/*
First Let's see what all approaches we can take and then we check if it fits our requirement.


     1. Select an element from 1 to N and check it frequency of occurrence. But this will be O(n2) and not O(n) .
	2. XOR : but this technique won't work as question mentions an element can be repeated multiple times. so if element repeats 2 times or 4 times each time result of xor will be 0 so we cannot get the frequency of occurrences.

	3. HashMap : We can create a HashMap in O(n) key will be elements and value will be their frequency of occurrence. But since we have to do it in O(1) space we cannot take this approach.

So we cannot opt for any of the above 3 approach. We have to check for some 4th approach.
Since we have range of numbers given to us we have to think in those lines.
Array Index is from 0 to N-1 and range is from 1 to N. Can't we use the array as hash itself?
where array "Index-1" represents the key (element) and value stored at index will represent the "frequency of occurrence".
  
But how will we take care that an element present at any index is not overwritten as this can cause problem?
We can sort the array in that case value present at index i is I+1 itself.

What is the complexity of sorting the array?
since the range of element is given to us we can sort it in O(n).

ALGORITHM

Since array contains elements from 1 to N we cannot keep frequency in same array as it will confuse which one is frequency and which one is the element value.
To overcome this, store frequency in negative, -1 = element appear once and so on, by this we are able to distinguish between frequency of occurrence and elements.

Negative values/0 are frequency and +ve values are elements.
  
1.       Scan array from left to right.
                Pos =0 ; while pos < N
2.       If current element is ?ve or 0 then move forward (pos++).

3.       Desiredpos = arr[pos]-1.

       Check if arr[desiredPos] > 0

a. If yes that means no previous occurrence of current element.

           Hence copy arr[pos] = arr[desiredPos] and set arr[desiredPos] =-1 i.e. first occurrence.

b. Else if it is encountered earlier also then decrement the frequency (arr[desiredPos]--) and set arr[pos] =0.

         While displaying frequency multiply the elements with -1, as all elements in array will be either ?ve or 0.

*/


#include <iostream>
using namespace std;

void display(int arr[], int size)
{
	for(int i=0; i < size; i++) {
		cout <<"\nElement = " << i+1 << "\tFrequency = " << arr[i]*-1;
	}
}

void getDuplicate(int arr[], int size)
{
	int pos = 0;
	int desirePos = 0;

	while(pos < size) {
		if(arr[pos] <= 0) {
			pos++;
			continue;
		}

		desirePos = arr[pos] - 1;

		if(arr[desirePos] > 0) {
			arr[pos] = arr[desirePos];
			arr[desirePos] = -1;
		} else {
			arr[desirePos]--;
			arr[pos] = 0;
			pos++;
		}
	}
}

int main()
{
	int arr[] = {6,4,1,4,3,2,5,2,1};

	int size = sizeof(arr) / sizeof(arr[0]);
	getDuplicate(arr, size);
	display(arr, size);

	return 0;
}
