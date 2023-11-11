#include<stdio.h>
int main()
{
	long long int arr[10];
	int x=0xaabbccdd;
	if((0xff&x)==0xaa)
	{
		printf("big endian format\n");
	}
	else
	{
		printf("Little endian format\n");
	}
	printf("%x",(0xff&x));
	printf("the way:%x\n",);
}
