#include<stdio.h>
int main()
{
	char b;
	scanf("%c",&b);
	if((b>=65)&&(b<=90)){
			b=b+32;
			printf("%c",b);
	}
	else if((b>=97)&&(b<=120))
			b=b-32;
			printf("%c",b);
	else
	{
		printf("It is special");
	}
	





}
