/*
http://forum.falinux.com/zbxe/?mid=lecture_tip&comment_srl=518031&l=es&page=18&document_srl=783410

http://egloos.zum.com/simple21/v/2465470
#pragma warning(disable : 4244; once : 4101; error : 4700)
이때 disable은 해당 warning이 output창에 나오지 않도록 무시하라는 지정
once는 동일한 warning에 대해 한번만 나오라는 것
error는 해당 warning을 error로 취급하라는 것이다.

*/


#include <stdio.h>

#pragma pack(2)
struct st1 { short s; int i; };  // 2바이트 정렬
#pragma pack(push,4)             // 푸시하면서 4바이트 정렬로 바꿈
struct st2 { short s; int i; };  // 4바이트 정렬
#pragma pack(pop)                // 원래 정렬값 복원
struct st3 { short s; int i; };
#pragma pack()           //기본정렬값
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

