/*
Given an input array 
a={1,2,3,6,2,8----} 
product of all numbers=p=a[0]*a[1]*---a[n-1] where n is size of array 
output arrau should be b={p/a[0],p/a[1],p/a[2]-----}. you should not use division operator.Time complexity should be less than o(n2).
*/

/*
this one is simple 
you will need two array of same size 
solution as example: 
{a,b,c,d,e,f} 
generate 
{1,a,ab,abc,abcd,abcde} 
and 
{bcdef,cdef,def,ef,f,1} 
now do a dot product of the above two array 
you are done.. 
complexity O(3n)= O(n) 
the above array are easily calculable as they can be generated the first from the front of array and other from back with 1 multiplcation for each element.
*/

#include <iostream>

using namespace std;

int *prodExceptCurrElem(int *arr, int len)
{
	if(!arr || len < 0) return NULL;

	int *newArr = new int[len];

	int i = 0, prodSoFar = 1;

	for(i = 0;i < len; ++i) {
		newArr[i] = prodSoFar;
		prodSoFar *= arr[i];
	}

	prodSoFar = 1;

	for(i = len-1; i >= 0; i--) {
		newArr[i] *= prodSoFar;
		prodSoFar *= arr[i];
	}

	for(i = 0; i < len; ++i)
		cout << i << " : " << newArr[i] << " ";

	cout << endl;


	return newArr;
}

int main()
{
	int a[] = {1,2,3,6,2,8};

	int len = sizeof(a)/sizeof(a[0]);

	int *b = prodExceptCurrElem(a, len);


	for(int i = 0; i < len; ++i)
		cout << i << " : " << b[i] << " ";

	cout << endl;

	return 0;
}
	


