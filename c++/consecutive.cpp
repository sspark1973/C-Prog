#include <iostream>

using namespace std;

const int MINIMUM = -10;
const int MAXIMUM = 100;
const unsigned int ARRAY_SIZE = MAXIMUM - MINIMUM;

int main()
{
	bool* hashOfIntegers = new bool[ARRAY_SIZE];
	const int someArrayOfIntegers[] = {-2, -3, 8, 6, 12, 14, -1, 0, 16, 18, 20};
	//const int someArrayOfIntegers[] = {10, 6, 5, 3, 1, 4, 2, 8, 7};
	//const int someArrayOfIntegers[] = {10, 5, 3, 1, 4, 2, 8, 7};
	
	const int SIZE_OF_ARRAY = sizeof(someArrayOfIntegers)/sizeof(someArrayOfIntegers[0]);

	cout << "size of array : " << SIZE_OF_ARRAY << endl;

	for(unsigned int i = 0; i < ARRAY_SIZE; i++) {
		hashOfIntegers[i] = false;
	}

	for(int i = 0; i < SIZE_OF_ARRAY; i++) {
		hashOfIntegers[someArrayOfIntegers[i] - MINIMUM] = true;
	}

	int sequence = 0;
	int maxSequence = 0;

	for(unsigned int i = 0; i < ARRAY_SIZE; i++) {
		if(hashOfIntegers[i]) sequence++;
		else sequence = 0;

		if(sequence > maxSequence) maxSequence = sequence;
	}

	cout << "MAX_SEQUENCE: " << maxSequence << endl;

	return 0;
}
