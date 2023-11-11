#include<stdio.h>
#include<unistd.h>
int main()
{
	int num=10,var,val;
	scanf("%d",&var);
	val=var*num+var/var+num;
	printf("The output:%d\n",val);

}


