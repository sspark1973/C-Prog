#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

using std::setw;
using std::setiosflags;
using std::setprecision;

#include <cmath> // math.h - pow
#include <cstdlib> // stdlib.h - rand
#include <ctime> // time.h

const double PI = 3.14159265358979;

void b(void);

int main()
{
	double 	amount,
			printcipal = 1000.0,
			rate = .05;

	int year = 1,
		grade, x, y;

	unsigned seed;
	time_t t;

	const float PI = static_cast< float >(::PI);

	cout << setprecision(20)
		 << " Local float value of PI = " << PI
		 << "\nGlobal double value of PI = " << ::PI << endl; // Unary Scope Resolution Operator(::) - global variable

	cout << "Enter two integers in the range 1-20: ";
	cin >> x >> y;

	b();
	//seed = (unsigned)time(&t);
	seed = (unsigned)time(0);
	srand(seed);
	
	cout << "Enter the letter grades." << endl
		<< "Enter the EOF character to end input." << endl;

	grade = cin.get(); // read one character from the keyboard 'a' = 97, '0' = 48 

	cout << "Year" << setw(21)
		<< "Amount on deposit" << endl;

	// set the floating-point number format
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	amount = printcipal * (pow(1.0 + rate, grade)); // pow : (1 + r ) year½Â

	cout << setw(4) << "pow:" << setw(21) << pow(1.0 + rate, year) << endl;
	cout << setw(4) << "grad" << setw(21) << grade << endl;
	cout << setw(4) << "x" << setw(21) << x << endl;
	cout << setw(4) << "y" << setw(21) << y << endl;
	cout << setw(4) << "seed" << setw(21) << seed << endl;

	for(int i = 0; i < 10; i++) {
		cout << "f[" << i << "]" << setw(21) << (1 + rand() % 6) << endl; // 1 <= face <= 6 
	}

	cout << setw(4) << year << setw(21) << amount << endl;
	b();
		
	return 0;
}

void b(void) {
	static int x = 50; // static initialization only first time b is called

	cout << endl << "local static x is" << x
		<< " on entering b" << endl;
	++x;

	cout << endl << "local static x is" << x
		<< " on exiting b" << endl;
}
