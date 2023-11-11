#include<stdio.h>
int main()
{
	int num,rem,sum=0,i=0,temp;
	char arr[50];
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
		rem=temp%16;
		if(rem<10)
		{
			rem=rem+48;
			arr[i]=rem;
		}
		else{
			rem=rem+87;
		        arr[i]=rem;
		}
		i++;
		temp=temp/16;
	}
	for(i=i-1;i>=0;i--)
	{
		printf("%c",arr[i]);
		
	}
	printf("\n");
	
}

