#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;

	void PrivatePrint() const
	{
		cout << x << ", " << y << endl;
	}
public:
	Point(int _x = 0, int _y = 0):x(_x), y(_y)
	{
	}

	void PublicPoint() const
	{
		PrivatePrint();
	}
	friend class PointWrapper;
};

class PointWrapper
{
private:
	Point point;
public:
	void PrintPoint()
	{
		point.PrivatePrint(); // PointWrapper는 Point 객체 외부이므로 접근 불가 - friend 선언해서 해
		point.PublicPrint();
	}
};

void main()
{
	PointWrapper pw;
	pw.Print();
}

