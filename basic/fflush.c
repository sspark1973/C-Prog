#include <stdio.h>

int main(void){

	char ch1,ch2;

	printf("2개의 문자를 입력하세요\n");
 
	ch1 = getchar(); 
	ch2 = getchar();

	printf("\n\n입력한 문자는 %c 와 %c 입니다.\n",ch1,ch2); 
	/*
	하지만 A를 누르고 엔터를치면 B를 입력하기도전에 A만 출력되는것을 볼수가있다.
	*/

	ch1 = getchar(); 
	getchar();
	ch2 = getchar();

	printf("\n\n입력한 문자는 %c 와 %c 입니다.\n",ch1,ch2); 
	/*
	A와 엔터값이 버퍼에 들어가게되고, 
	ch1에 A값이 들어가게되고, 다음라인인 getchar()를 통해 엔터값을 가져오지만 어느곳에도 넣지는 않는다.
	그리고 다음라인인 ch2=getchar()를 통해서  ch2에 B를 넣게되어 맨위의 그림과같이 출력을 할수 있게 된다.
	*/

	ch1 = getchar();
 	fflush(stdin);
	ch2 = getchar();

	printf("\n\n입력한 문자는 %c 와 %c 입니다.\n",ch1,ch2);
	/*
	fflush(stdin);함수를 이용하는것이다.
	fflush(stdin)함수는 stdin버퍼에있는 값을 비우는 함수이다.
	*/
 
	return 0;
}

