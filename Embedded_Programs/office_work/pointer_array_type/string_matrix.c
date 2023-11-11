#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter the string\n");
	scanf("%s",str);
	char s;
	int i,j,big=0;
	int count=0;
	int n=strlen(str);
	for(i=0;i<n;i++)
	{
		s=str[i];
		for(j=i+1;j<n;j++)
		{
			if(s!=str[j])
			{
				printf("in if%c\n",str[j]);
				count++;
			}
			else
			{
				printf(" in else%c\n",str[j]);
				printf("count:%d\n",count);
				if(count>=big){
				big=count;
				count=0;
				}
				
			}
			printf("Inner\n");
		}
	}
	printf("%d",big);
}


