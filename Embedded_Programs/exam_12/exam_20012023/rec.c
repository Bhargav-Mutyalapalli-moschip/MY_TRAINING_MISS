#include<stdio.h>
int add(int num)
{
	/*static int res;
	if(num==0)
		return 0;
	else
	{
		res=res+num%10;
		add(num=num/10);
		return res;
	}*/
	static int sum=0;
	int rem;
	rem=num%10;
	num=num/10;
	sum=sum+rem;
	if(num==0)
		return 0;
	add(num);
	return sum;
}
int main()
{
	int num=567,res;
	res=add(num);
	printf("%d\n",res);
}
