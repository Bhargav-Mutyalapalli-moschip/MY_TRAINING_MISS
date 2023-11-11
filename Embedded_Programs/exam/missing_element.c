#include<stdio.h>
int main()
{
	int arr[10]={1,2,3,6,7,8,9,10,11,12};
	int i,num,j,k;
	i=arr[0];
	k=arr[10-1];
	for(i,j=0;i<k;i++,j++)
	{
		if(i==arr[j])
		{
			continue;
		}
		else
		{
			printf("The out:%d\n",i);
			j--;
		}

	}
}





