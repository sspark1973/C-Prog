/*
protected 키워드는 member-list의 클래스 멤버에 대한 액세스를 
다음 액세스 지정자(public 또는 private) 또는 클래스 정의의 끝까지 지정합니다. 

protected 로 선언된 클래스 멤버는 다음에만 사용할 수 있습니다.
	원래 이 멤버를 선언한 클래스의 멤버 함수
	원래 이 멤버를 선언한 클래스의 friend
	원래 이 멤버를 선언한 클래스에서 public 또는 protected 액세스로 파생된 클래스
	protected 멤버에 대해 전용 액세스 권한이 있으며 전용으로 직접 파생된 클래스

기본 클래스 이름 앞에 오는 protected 키워드는 
	기본 클래스의 공용 및 보호된 멤버가 파생된 해당 클래스의 보호된 멤버라고 지정합니다.

보호된 멤버는 선언된 클래스의 멤버에만 액세스할 수 있는 private 멤버만큼 전용은 아니지만 
어느 함수에서나 액세스할 수 있는 public 멤버만큼 public도 아닙니다.

static으로도 선언된 protected 멤버는 파생된 클래스의 friend나 멤버 함수에 액세스할 수 있습니다. 
static으로 선언되지 않은 protected 멤버는 
파생된 클래스의 포인터, 참조 또는 개체를 통해서만 파생된 클래스의 friend와 멤버 함수에 액세스할 수 있습니다.
*/

#include <iostream>

using namespace std;

class X {
public:
	void setProtMemb(int i) { m_protMemb = i; } // 원래 이 멤버를 선언한 클래스의 멤버 함수
	void Display() { cout << m_protMemb << endl; }
	friend void SetXPrint(X&);

protected:
	int m_protMemb;
	void ProtFunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
	void useProtfunc() { ProtFunc(); } // 원래 이 멤버를 선언한 클래스에서 public 또는 protected 액세스로 파생된 클래스
} y;

void SetXPrint(X& x)
{
    x.ProtFunc( ); // 외부에서 접근 불가능. 에러~~ -> friend 선
    x.setProtMemb(10);
	x.Display();
}

int main()
{
	// x.m_protMemb; error, m_protMemb is protected
	x.setProtMemb(0);
	x.Display();

	y.setProtMemb(5);
	y.Display();

	//x.ProtFunc(); error, Protfunc() is protected
	y.useProtfunc();

	SetXPrint(x);
}
