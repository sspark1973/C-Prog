#include <iostream>

using std::cout;
using std::endl;

int squareByReference(int &length, int width = 1, int height = 1);

int main()
{
	int x = 2, &y = x;

	cout << "x = " << x << " before squareByReference\n";
	squareByReference(x);
	cout << "x = " << x << " after squareByReference\n";
	cout << "y = " << y << " after squareByReference\n";
	cout << "squareByReference(x,1,1) : " <<  squareByReference(x) << endl;
	cout << "x = " << x << " after squareByReference\n";

	cout << "squareByReference(x,2,1) : " <<  squareByReference(x, 2) << endl;
	cout << "x = " << x << " after squareByReference\n";

	cout << "squareByReference(x,4,6) : " <<  squareByReference(x, 4 ,6) << endl;
	cout << "x = " << x << " after squareByReference\n";

	return 0;
}

int squareByReference(int &cRef, int width, int height) {
	cRef *= cRef;
	return cRef * width * height;
	
	
}
