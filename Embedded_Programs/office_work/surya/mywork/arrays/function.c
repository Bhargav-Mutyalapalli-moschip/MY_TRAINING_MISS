#include<stdio.h>
void func(int a,int b);
int main()
{
	int x=func(1,2)+100;
	printf("%d\n",x);
	return 0;

}
void func(int x,int y)
{
	int z;
	z=x+y;
	//printf("ood");
}
