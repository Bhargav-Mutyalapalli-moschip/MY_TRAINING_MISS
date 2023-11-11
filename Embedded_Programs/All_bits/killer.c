#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void main(int count,char *str[])
{
	printf("Enter the first argument is process id\n");
	printf("Enter the second argument is Signal number\n");
	int arr[count];
	if(count==3)
	{
		int i,j,k=0,stat=0,temp,sum=0;
		for(i=1;i<count;i++)
		{
			sum=0;
			stat=0;
			if(str[i][0]=='-')
			{
				stat++;
			}
			for(j=stat;str[i][j]!='\0';j++)
			{
				if(str[i][j] >= '0' && str[i][j] <= '9')
				{
					temp=str[i][j]-48;
					sum=sum*10+temp;
				}
				else
				{
					printf("Invalid input\n");
					return;
				}

			}
			arr[k]=sum;
			k++;
		}
	}
	printf("process id to kill the particular process\n");
	int pid,signo;
	pid=arr[0];
	signo=arr[1];
	kill(pid,signo);

}





