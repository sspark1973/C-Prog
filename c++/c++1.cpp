/*
������ ������ �����̱� ������ �������� ������ �����ϴ�.
call-by-reference using reference
*/

#include <iostream>

using namespace std;

/* �������� �ּҴ� �����ϴ� ���� ����... �׷��Ƿ� swap�ȴ�. */
void SwapByRef(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

void test(int *&a, int *&b)
{
	a = b;
	
	cout << "test a : " << a << endl;
	cout << "test b : " << b << endl;

	cout << "test *a : " << *a << endl;
	cout << "test *b : " << *b << endl;

}

int main()
{
	int val1 = 10;
	int val2 = 20;
	int *pa = &val1;
	int *pb = &val2;

	//SwapByRef(val1, val2);

	cout << "val1 = " << val1 << endl;
	cout << "val2 = " << val2 << endl;

	cout << "main pa : " << pa << endl;
	cout << "main pb : " << pb << endl;


	test(pa, pb);
	
	cout << *pa << endl;
	cout << *pb << endl;

	return 0;
}

