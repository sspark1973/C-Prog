/*
http://forum.falinux.com/zbxe/?mid=lecture_tip&comment_srl=518031&l=es&page=18&document_srl=783410

http://egloos.zum.com/simple21/v/2465470
#pragma warning(disable : 4244; once : 4101; error : 4700)
�̶� disable�� �ش� warning�� outputâ�� ������ �ʵ��� �����϶�� ����
once�� ������ warning�� ���� �ѹ��� ������� ��
error�� �ش� warning�� error�� ����϶�� ���̴�.

*/


#include <stdio.h>

#pragma pack(2)
struct st1 { short s; int i; };  // 2����Ʈ ����
#pragma pack(push,4)             // Ǫ���ϸ鼭 4����Ʈ ���ķ� �ٲ�
struct st2 { short s; int i; };  // 4����Ʈ ����
#pragma pack(pop)                // ���� ���İ� ����
struct st3 { short s; int i; };
#pragma pack()           //�⺻���İ�
struct Park {short sNum; int iNum;}; 

int main()
{
  
  
  struct st1 C;
  struct st2 D;
  struct st3 E;
  struct Park B;
  
  printf("C: %d\n",sizeof(C));
  printf("D: %d\n",sizeof(D));
  printf("E: %d\n",sizeof(E));
  printf("B: %d\n",sizeof(B));
  return 0;
}

