#include <stdio.h>

int main(void){

	char ch1,ch2;

	printf("2���� ���ڸ� �Է��ϼ���\n");
 
	ch1 = getchar(); 
	ch2 = getchar();

	printf("\n\n�Է��� ���ڴ� %c �� %c �Դϴ�.\n",ch1,ch2); 
	/*
	������ A�� ������ ���͸�ġ�� B�� �Է��ϱ⵵���� A�� ��µǴ°��� �������ִ�.
	*/

	ch1 = getchar(); 
	getchar();
	ch2 = getchar();

	printf("\n\n�Է��� ���ڴ� %c �� %c �Դϴ�.\n",ch1,ch2); 
	/*
	A�� ���Ͱ��� ���ۿ� ���Եǰ�, 
	ch1�� A���� ���Եǰ�, ���������� getchar()�� ���� ���Ͱ��� ���������� ��������� ������ �ʴ´�.
	�׸��� ���������� ch2=getchar()�� ���ؼ�  ch2�� B�� �ְԵǾ� ������ �׸������� ����� �Ҽ� �ְ� �ȴ�.
	*/

	ch1 = getchar();
 	fflush(stdin);
	ch2 = getchar();

	printf("\n\n�Է��� ���ڴ� %c �� %c �Դϴ�.\n",ch1,ch2);
	/*
	fflush(stdin);�Լ��� �̿��ϴ°��̴�.
	fflush(stdin)�Լ��� stdin���ۿ��ִ� ���� ���� �Լ��̴�.
	*/
 
	return 0;
}

