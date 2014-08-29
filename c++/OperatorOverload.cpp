#include <iostream>

using namespace std;

class NUMBOX
{
private:
	int num1, num2;

public:
	NUMBOX(int num1, int num2) : num1(num1), num2(num2) {}

	void ShowNumber() {
		cout << "num1: " << num1 << ", num2: " << num2 << endl;
	}

#if 0
	// NUMBOX + NUMBOX
	NUMBOX operator+(NUMBOX &ref) {
		cout << "ref.num1 : " << ref.num1 << endl;
		return NUMBOX(num1 + ref.num1, num2 + ref.num2);
	}
#endif

	// NUMBOX + int
	NUMBOX operator+(int num) {
		return NUMBOX(num1+num, num2+num);
	}

	// It's not member function - global function
	// so, it has "friend" to access member variables
	friend NUMBOX operator+(int num, NUMBOX ref);
	//NUMBOX operator+(int num, NUMBOX ref);

	// ++a
	NUMBOX operator++() {
		num1 += 1;
		num2 += 1;
		return *this; // this : object address, *this : object to pointer
	}

	// a++
	NUMBOX operator++(int) {
		NUMBOX temp(*this);
		num1 += 1;
		num2 += 1;
		return temp;
	}
};

// Global Function
NUMBOX operator+(int num, NUMBOX ref)
{
	ref.num1 += num;
	ref.num2 += num;

	return ref;
}

int main()
{
	NUMBOX nb1(10, 20);
	NUMBOX nb2(5, 2);
	//NUMBOX result = nb1 + nb2; //  = nb1.operator + (nb2);
	NUMBOX result = nb1 + 10;
	// NUMBOX result = 10 + nb1; // Compile Error

	NUMBOX result2 = 30 + nb1;

	nb1.ShowNumber();
	nb2.ShowNumber();
	result.ShowNumber();
	result2.ShowNumber();

	cout << "1 operator : " << endl;

	nb2 = nb1++; // nb1.operator++(int)
	nb2.ShowNumber();
	nb1.ShowNumber();

	nb2 = ++nb1; // nb1.operator++()
	nb2.ShowNumber();
	nb1.ShowNumber();
}
	

