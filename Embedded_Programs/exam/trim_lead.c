#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
void remove_spaces(char *str);
int main()
{
	int i,j;
	char str[100];
	printf("enter the string:");
	scanf("%[^\n]",str);
	__fpurge(stdin);
	remove_spaces(str);
}
void remove_spaces(char *str)
{
	int i,j,flag=0,len;
	len=strlen(str);
	int c=0;
	if(str[len-1] == ' ')
	{
		for(i=len-1;i>=0;i--)
		{
			if(str[i] == ' ')
			{
				str[i]='\0';
			}
			else
				break;
		}
	}
	for(i=0;str[i]!='\0';i++)
	{
		flag=0;
		if(i==0)
		{
			if(str[i] == ' ')
			{
				flag=1;
				for(j=i;str[j]!='\0';j++)
					str[j]=str[j+1];
			}
			if(flag == 1)
			{
				i=i-1;
			}

		}

	}


	printf("The string:%s\n",str);
	printf("The stlen:%d\n",strlen(str));
}






