#include<stdio.h>
int main(int count,char *str[])
{
	int i,j;
	for(i=0;i<count;i++)
	{
		printf("%p \n",str[i]);
	}
}
