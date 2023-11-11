#include<stdio.h>
int add(int,int);
int main()
{

	int a=10,b=20,res;
	int(*fptr)(int,int);
	//res=add(a,b);
	fptr=add;
	res=fptr(a,b);
	printf("%d\n",res);
}
int add(int a,int b)
{
	return (a+b);
}
