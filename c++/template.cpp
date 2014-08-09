#include <iostream>
using namespace std;


// function template

template <typename T> // template definition
void ShowData(T a, T b)
{
	cout << a << endl;
	cout << b << endl;
}

//template <typename T1, typename T2>
template <class T1, class T2> // same
void ShowData(T1 a, T2 b)
{
	cout << a << endl;
	cout << b << endl;
}

// template specialization
template <typename T>
int SizeOf(T a)
{
	return sizeof(a);
}

template<>
int SizeOf(char *a)
{
	return strlen(a);
}

int main(void)
{
	// function template - compiler makes this function int ShowData(int a, double b)
	// function template -> instance -> template function
	ShowData(1, 2);
	ShowData<int>(1,2);
	ShowData(3, 2.5); //error - Fix this error by second ShowData 
	ShowData(3.0, 2.5); 

	// template specialization
	int i = 10;
	double e = 7.7;
	char *str = "Good morning";
	string s = "Good morning";

	cout << SizeOf(i) << endl;
	cout << SizeOf(e) << endl;
	cout << SizeOf(str) << endl; // not 4 , it's 12
	cout << SizeOf(s) << endl; // 4

	return 0;
}
