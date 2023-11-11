#include<stdio.h>
int add(int num)
{
	static int res;
	if(num==0)
		return 0;
	else
	{
		res=res+num%10;
		add(num=num/10);
		return res;
	}
}
int main()
{
	int num=456,res;
	res=add(num);
	printf("%d\n",res);
}
