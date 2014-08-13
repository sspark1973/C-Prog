/*
= operator overload problem
*/

#include <iostream>
using namespace std;

class Student
{
private:
	char *name;
	int age;
public:
	Student(char *name, int age) : age(age) {
		this->name = new char[10];
		strcpy(this->name, name);
	}

	void ShowInfo() {
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
	}

	// to cover swallow copy
	Student& operator=(Student& ref) {
		delete []name;
		name = new char[10];
		strcpy(name, ref.name);
		age = ref.age;

		return *this;
	}

	~Student() {
		delete []name;
		cout << "~Student Called" << endl;
	}
};

int main()
{
	Student st1("Kim CS", 14);
	Student st2("Hong KD", 15);

	st2 = st1; // swallow copy, just address

	st1.ShowInfo();
	st2.ShowInfo();

	cout << "End" << endl;

	return 0;
}
		

