#include<stdio.h>
int main()
{
	int arr[10];
	int i,larg=0,sec=0,third=0,four=0,var;
	for(i=0;i<10;i++)
	{
		printf("Enter the vale\n");
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<10;i++)
	{
		if(arr[i]>=larg)
		{
			if(arr[i]==larg)
			continue;
			four=third;
			third=sec;
			sec=larg;
			larg=arr[i];
		}
		else if(arr[i]>=sec)
		{
			if(arr[i]==sec)
			continue;
			sec=arr[i];
		}
		else if(arr[i]>=third)
		{
			if(arr[i]==third)
			continue;
			third=arr[i];
		}
		else if(arr[i]>=four)
		{
			if(arr[i]==four)
			continue;
			four=arr[i];
		}
	}
	printf("%d--------%d--------%d---------%d\n",larg,sec,third,four);

}







