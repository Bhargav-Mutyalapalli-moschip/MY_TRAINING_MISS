#include<stdio.h>
int main()
{
        int i,j,k,n,temp=0,max=0;
        printf("enter the no of elememts : " );
        scanf("%d",&n);
        int arr[n];
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
        {
		temp=0;
                for(j=i;j<n;j++)
                {
                        if(arr[i]==arr[j])
				temp++;
              
                }





        }
	printf("%d is the most repeated \n",arr[i]);
}

