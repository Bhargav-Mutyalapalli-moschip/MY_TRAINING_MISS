#include<stdio.h>
#define NM 5
int main()
{
	int arr[NM];
	int n;
	printf("Enter the value to check for number of times\n");
	scanf("%d",&n);
	int i,j,temp;
	for(i=0;i<NM;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
                temp=arr[0];
		for(j=0;j<NM-1;j++)
		{
			arr[j]=arr[j+1];
		}
		arr[NM-1]=temp;
	}
	for(i=0;i<NM;i++)
	printf("%d\t",arr[i]);
}


