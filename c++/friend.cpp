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
		point.PrivatePrint(); // PointWrapper�� Point ��ü �ܺ��̹Ƿ� ���� �Ұ� - friend �����ؼ� ��
		point.PublicPrint();
	}
};

void main()
{
	PointWrapper pw;
	pw.Print();
}

