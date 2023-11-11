#include<stdio.h>
int main()
{
	int temp=0,fah=0,add=32;
	printf("enter the temperature");
	scanf("%d",&temp);
	fah=temp*1.8+add;
	printf("%d°f",fah);
}

