/*
Euclid's algorithm
GCD : Greatest Common Divisor - �ִ�����
Example : 280�� 30�� �ִ������� ���϶�
280�� ��� : 1,2,3,4,5,7,8,10,14....
30�� ��� : 1,2,3,4,5,7,8,10
���� ū ����� 10 -> �ִ�����
*/

#include <stdio.h>
#include <bios.h>

int get_gcd(int u, int v)
{
	int t;

	while(u) {
		if (u < v) {
			t = u; u = v; v = t;
		}
		u = u - v;
	}

	return v;
}
			
int gcd_modules(int u, int v)
{
	int t;

	while(v) {
		if(u < v) {
			t = u; u = v; v =t;
		}

		t = u % v;
		u = v;
		v = t;
	}

	return u;
}
		
void main()
{
	int u, v;

	puts("\n EUCLID1 : Get GCD of two positive integer"
		 "\n 	Input 0 to end program");

	while(1) {
		puts("\n\n Input two positive integer -> ");
		scanf("%d %d", &u, &v);

		if(u < 0 || v < 0)
			continue;
		if(u == 0 || v == 0)
			break;
		printf("\n GCD of %d and %d is %d\n", u, v, get_gcd(u,v));
		printf("\n GCD modules of %d and %d is %d\n", u, v, gcd_modules(u,v));
	}
}
