#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

using std::setw;

unsigned long factorial(unsigned long);
unsigned long fibonacci(unsigned long);

inline double cube(const double s) { return s*s*s; }

int main()
{
	cout << "unsigned long size : " << sizeof(unsigned long) << endl;
	cout << "int : " << sizeof(int) << endl;
	
	for(int i=0; i <= 10; i++)
		cout << setw(2) << i << "! = " << factorial(i) << endl;

	cout << "cube[" << 10 << "] = " << cube(10) << endl; 

	for(int i=2; i <= 10; i++)
		cout << setw(2) << i << "! = " << fibonacci(i) << endl;

	cout << "cube[" << 8 << "] = " << cube(8) << endl;

	return 0;
}

unsigned long factorial(unsigned long x) {

	if(x <= 1)
		return 1;
	else
		return x*factorial(x-1);
}

unsigned long fibonacci(unsigned long x) {

	if((x == 0) || (x == 1))
		return x;
	else
		return fibonacci(x-1) + fibonacci(x-2);
}
