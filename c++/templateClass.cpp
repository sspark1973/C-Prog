#include <iostream>
using namespace std;

template <typename T>
class Data
{
	T data;
public:
	Data(T d);
	void SetData(T d);
	T GetData();
};
/*
Create Instance : Memory alloc -> Constructor...
Data d1(10); 
	- Can't memory alloc - We have to know T's type 
	- We can know T's type after calling constructor
*/

template <typename T>
Data<T>::Data(T d) {
	data = d;
}

template <typename T>
void Data<T>::SetData(T d) {
	data = d;
}

template <typename T>
T Data<T>::GetData() {
	return data;
}

int main(void)
{
	Data<int> d1(0);
	d1.SetData(10);

	Data<char> d2('a');
	cout << d1.GetData() << endl;
	cout << d2.GetData() << endl;

	return 0;
}