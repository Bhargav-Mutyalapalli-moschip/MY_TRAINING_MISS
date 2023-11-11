#include<stdio.h>
int main()
{
	int arr[10]={25,30,35,40,45,50,55,60,65,70};
	int *p;
	for(p=&arr[0];p<arr+10;p++)
	{
		printf("%d\n",*p);
	}
}
