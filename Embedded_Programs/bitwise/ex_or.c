#include<stdio.h>
int main()
{
	int i;
	printf("Enter the bit to which toggle\n");
	scanf("%d",&i);
	unsigned int num;
	scanf("%x",&num);
	num=(num^(0x1<<i));
	printf("The out:%x\n",num);
}
