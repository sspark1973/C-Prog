#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vnData;

	for(int a=1; a <= 10; ++a)
		vnData.push_back(a); // put a data to the vector

	vector<int>::const_iterator pos;

	for (pos = vnData.begin(); pos != vnData.end(); ++pos)
		cout << *pos << ' ';

	cout << endl;
}
