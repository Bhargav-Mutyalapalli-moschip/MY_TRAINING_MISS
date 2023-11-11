#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	char big[50];
	int n,i,j,temp,count=0,res,k;
	char c;
	printf("enter the string\n");
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		c=str[i];
		for(j=i+1;j<n-1;j++,k++)
		{
			
			if(c==str[j])
			{
			
				big[j]=str[j];

			}
			else
			{
				count++;
				temp=count;
			}

		}
		if(temp>count){
			count=0;
		printf("%d",temp);
	       }
	}
}
		
		




