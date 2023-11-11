#include<stdio.h>
int main()
{
	int num,temp;
	int sum=0;
	printf("Enter the number\n");
	scanf("%d",&num);
	int i,j,k=0,g=0;
	for(i=g;i<num;i++)
	{
		
		sum=sum+i;
		k=g;
		//printf("The sum:%d\n",sum);
		if(sum==num)
		{
			temp=k;
			for(j=k;j<=i;j++)
			{
				printf("%d\n",j);
			}
			k=i;
			printf("the values\n");
			sum=0;
			i=g++;
			//printf("g:%d\n",g);

		}
		if(sum>num)
		{
			i=g++;
			sum=0;
		}
	}
}




