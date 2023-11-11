#include<stdio.h>
#include<string.h>
void reverse_string(char *str,int end,int start);
int main()
{
	int i,j,k=0;
	char str[100];
	printf("--enter the sentence----:");
	scanf("%[^\n]",str);
	j=strlen(str);
	for(i=0;i<=j;i++)
	{
		if(str[i] == ' ' || i==j)
		{
			if(i!=j)
			{
				if(str[i+1] == ' ')
					continue;
			}
			reverse_string(str,(i-1),k);
			k=i+1;
		}
	}
	printf("The reversed string:----:%s\n",str);
}
void reverse_string(char *str,int end,int start)
{
	printf("The start:%d------The end:%d\n",start,end);
	char temp;
	int i,j;
	for(i=start,j=end;i<=j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
}





