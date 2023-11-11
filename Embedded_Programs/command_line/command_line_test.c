#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int arr[100];
	int i,sum=0,temp,k,l=0,flag=0,stat=0;
	if(argc > 1)
	{
		for(i=1;i<argc;i++)
		{
			sum=0;
			stat=0;
			flag=0;
			if(argv[i][0] == '-')
			{
				flag=1;
				stat++;
				
			}
			for(k=stat;argv[i][k]!='\0';k++)
			{
				if(argv[i][k] >= '0' && argv[i][k] <= '9')
				{
					temp=argv[i][k]-48;
					sum=sum*10+temp;
				}
				else
				{
					printf("Invalid parameters\n");
					exit(1);
				}
			}
			if(flag == 1)
				sum=(-sum);
			arr[l]=sum;
			l++;
		}
	}
	for(i=0;i<argc-1;i++)
		printf("%d\n",arr[i]);
}









