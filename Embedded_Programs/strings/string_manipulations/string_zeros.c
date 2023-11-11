#include<stdio.h>
#define NM 5
int main()
{
	int arr[NM];
	int i,j,temp,k=0,d=0,l=0;
	for(i=0;i<NM;i++)
	{
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<NM;i++)
	{
		d=i+k;;
		if(arr[d]==0)
		{
                   	temp=arr[d];
			for(j=d;j<NM;j++)
			{
				arr[j]=arr[j+1];
			}
			arr[NM-1]=temp;
			k--;
			printf("The value of D%d\n",k);
			
			
		}
		
	}
	for(i=0;i<NM;i++)
	printf("%d\t",arr[i]);
}


