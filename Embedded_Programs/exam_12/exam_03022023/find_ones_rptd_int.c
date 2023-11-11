#include<stdio.h>
int main()
{
	int i,var,arr[9]={1,5,2,7,2,5,1,9,9};
	var=arr[0];
	for(i=0;i<8;i++)
	{
		var=var^arr[i+1];
	}
	printf("once repeated is : %d \n",var);
}
