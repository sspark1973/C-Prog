#include <iostream>
using namespace std;

class Car {
public:
	virtual void Top_Speed(int a) {
		topspeed = a;
		cout << "Car Top Speed : " << topspeed << endl;
	}

protected:
	int topspeed;
};

class Ferrari : public Car {
public:
	void Top_Speed(int a) {
		topspeed = a;
		cout << "Ferrari Top Speed : " << a << endl;
	}
};

int main()
{
	Car car1;
	car1.Top_Speed(50);
	
	Car *car = new Ferrari;
	car->Top_Speed(30);

	return 0;
}
