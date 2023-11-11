#include<stdio.h>
int main()
{
	int arr[3][4]={{10,11,12,13},{20,21,22,23},{31,32,33,34}};
	int *p=&arr[0][0];
	int i;
	for(i=0;i<12;i++)
	printf("%d\n",p[i]);
	printf("The total%lld",arr[0][0]);
}
