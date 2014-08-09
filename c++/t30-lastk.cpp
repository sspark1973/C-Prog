/*
Write a method to print the last K lines of an input file using C++.
*/

/*
SOLUTION
One brute force way could be to count the number of lines (N) and then print from N-10 to Nth line. 
But, this requires two reads of the file . potentially very costly if the file is large.
We need a solution which allows us to read just once and be able to print the last K lines. 
We can create extra space for K lines and then store each set of K lines in the array. 

So, initially, our array has lines 0 through 9, then 1 through 10, then 2 through 11, etc (if K = 10).
Each time that we read a new line, we purge the oldest line from the array. 
Instead of shifting the array each time (very inefficient), we will use a circular array. 
This will allow us to always find the oldest element in O(1) time.
Example of inserting elements into a circular array:
step 1 (initially): array = {a, b, c, d, e, f}. p = 0
step 2 (insert g): array = {g, b, c, d, e, f}. p = 1
step 3 (insert h): array = {g, h, c, d, e, f}. p = 2
step 4 (insert i): array = {g, h, i, d, e, f}. p = 3
*/

#include <iostream>
#include <fstream>
using namespace std;

void printLastKLines(ifstream &fin, int k) {
	string line[k];
	int lines = 0;
	string tmp;

	//while (fin.good()) {
	while (getline(fin, tmp)) {
		line[lines%k] = tmp;
		++lines;
	}

	cout << "lines : " << lines << endl;

	int start, cnt;

	if (lines < k) {
		start = 0;
		cnt = lines;
	} else {
		start = lines % k;
		cnt = k;
	}

	cout << "start : " << start << endl;

	for (int i = 0; i < cnt; ++i) {
		//cout << i << " " << line[(start+i)%k] << endl;
		cout << i << " " << line[(start+i)] << endl;

	}
}

int main() {
	ifstream fin("13.1.in");

	int k = 4;
	printLastKLines(fin, k);
	fin.close();
	return 0;
}

