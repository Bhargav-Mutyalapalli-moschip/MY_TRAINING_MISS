#include<stdio.h>
int main(int argc,char *argv[])
{
	//argv[1][0]='-';
	//if(argc<=2)
	//printf("It has few arguments\n");
	int i,j,stat=0,m=0,k;
	int temp,sum=0;
	int arr[argc-2];
	for(i=2;i<argc;i++)
	{
		stat=0;
		sum=0;
		if(argv[i][0]=='-')
			stat++;
		for(k=stat;argv[i][k]!='\0';k++)
		{
			if(argv[i][k]>='0' && argv[i][k]<='9')
			{
				temp=argv[i][k]-48;
				sum=sum*10+temp;
			}
			else
			{
				printf("Invalid inputs\n");
				return 0;
			}
		}
		if(stat==1)
			sum=-(sum);
		arr[m]=sum;
		m++;
	}
	for(i=0;i<argc-2;i++)
		printf("The elements:%d\n",arr[i]);
}



