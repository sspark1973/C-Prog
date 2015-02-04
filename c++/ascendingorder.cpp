#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int arraySize = 10;
	int hold;
	int a[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 87 };

	for(int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];
	cout << endl;

	for(int pass = 0; pass < arraySize - 1; pass++)
		for(int i = 0; i < arraySize - 1; i++)
			if(a[i] > a[i+1]) {
				hold = a[i];
				a[i] = a[i+1];
				a[i+1] = hold;
			}

	for(int i = 0; i < arraySize; i++)
		cout << setw(4) << a[i];
	cout << endl;
			
	return 0;
}

