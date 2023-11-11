#include<stdio.h>
int main()
{
	int i,n,j,n1;
	scanf("%d",&n);
        int a[n];
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	printf("output is\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				if(a[i]==a[j])
				continue;


				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
		
	}
	for(i=0;i<n; )
	{
		
		if(a[i]<a[i+1])
		{
			printf("%d",a[i+1]);
			break;
		}
		else
			i++;
			

	}


}


