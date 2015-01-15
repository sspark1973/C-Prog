#include <stdio.h>

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)
#define my_sizeof2(X) \
({\
__typeof(X) x; \
(char *)(&x + 1) - (char *)(&x); \
})

#define my_sizeof3(X) (char *)(&X + 1) - (char *)(&X)

int main()
{
	long a;

	printf("my_sizeof long : %d\n", my_sizeof(a));
	printf("my_sizeof2 long : %d\n", my_sizeof2(long));
	printf("my_sizeof3 long : %d\n", my_sizeof3(a));
	return 0;
}
