#include<stdio.h>
int add(int,int,int(*pranavf)(char*,...));
int main()
{
	int a=10,b=20;
	int(*pranavf)(char*,...);
	pranavf=printf;
	int(*fptr)(int a,int b,int(*pranavf)(char*,...));
	fptr=add;
	fptr(a,b,printf);
}
int add(int a,int b,int(*pranavf)(char*,...))
{
	pranavf("%d\n",a+b);
}

