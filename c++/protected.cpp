/*
protected Ű����� member-list�� Ŭ���� ����� ���� �׼����� 
���� �׼��� ������(public �Ǵ� private) �Ǵ� Ŭ���� ������ ������ �����մϴ�. 

protected �� ����� Ŭ���� ����� �������� ����� �� �ֽ��ϴ�.
	���� �� ����� ������ Ŭ������ ��� �Լ�
	���� �� ����� ������ Ŭ������ friend
	���� �� ����� ������ Ŭ�������� public �Ǵ� protected �׼����� �Ļ��� Ŭ����
	protected ����� ���� ���� �׼��� ������ ������ �������� ���� �Ļ��� Ŭ����

�⺻ Ŭ���� �̸� �տ� ���� protected Ű����� 
	�⺻ Ŭ������ ���� �� ��ȣ�� ����� �Ļ��� �ش� Ŭ������ ��ȣ�� ������ �����մϴ�.

��ȣ�� ����� ����� Ŭ������ ������� �׼����� �� �ִ� private �����ŭ ������ �ƴ����� 
��� �Լ������� �׼����� �� �ִ� public �����ŭ public�� �ƴմϴ�.

static���ε� ����� protected ����� �Ļ��� Ŭ������ friend�� ��� �Լ��� �׼����� �� �ֽ��ϴ�. 
static���� ������� ���� protected ����� 
�Ļ��� Ŭ������ ������, ���� �Ǵ� ��ü�� ���ؼ��� �Ļ��� Ŭ������ friend�� ��� �Լ��� �׼����� �� �ֽ��ϴ�.
*/

#include <iostream>

using namespace std;

class X {
public:
	void setProtMemb(int i) { m_protMemb = i; } // ���� �� ����� ������ Ŭ������ ��� �Լ�
	void Display() { cout << m_protMemb << endl; }
	friend void SetXPrint(X&);

protected:
	int m_protMemb;
	void ProtFunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
	void useProtfunc() { ProtFunc(); } // ���� �� ����� ������ Ŭ�������� public �Ǵ� protected �׼����� �Ļ��� Ŭ����
} y;

void SetXPrint(X& x)
{
    x.ProtFunc( ); // �ܺο��� ���� �Ұ���. ����~~ -> friend ��
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
