#include<stdio.h>
int main()
{
	int var,i=1;
	printf("Enter the value\n");
	scanf("%d",&var);
	while(var!=0)
	{
		i=i*(var--);
	}
	printf("The factorial:%d\n",i);
}
		

