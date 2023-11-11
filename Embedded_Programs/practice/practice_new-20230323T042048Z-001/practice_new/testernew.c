#include<stdio.h>
int main()
{
	volatile int i=300;
	volatile char *ptr=&i;
	

	*ptr++ = 3;
	printf("The out:%d\n",i);
}
