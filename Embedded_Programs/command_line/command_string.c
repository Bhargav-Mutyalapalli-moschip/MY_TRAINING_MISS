#include<stdio.h>
int main(int count,char*arr[])
{
	int i,k;
	int zero;
	int sum=0;
	int temp,m=0;
	for(i=2;i<count;i++)
	{
		sum=0;
		for(k=0;arr[i][k]!='\0';k++)
				sum++;
		printf("The strings count%d\n",sum);
	}
}
	



