#include<stdio_ext.h>
int main()
{
        int i,j,k,n,temp=0,max=0;
        printf("enter the no of elememts : " );
        scanf("%d",&n);
	__fpurge(stdin);
        int arr[n];
        for(i=0;i<n;i++)
	{
                scanf("%d",&arr[i]);
		__fpurge(stdin);
	}
        for(i=0;i<n;i++)
        {
		temp=0;
                for(j=i+1;j<n;j++)
                {
                        if(arr[i]==arr[j])
				temp++;
                }
		if(max<temp)
		{
			max=temp;
			printf("max:%d  val:%d \n",max,arr[i]);
			k=i;
		}
        }
	printf("%d is the most repeated \n",arr[k]);
}

