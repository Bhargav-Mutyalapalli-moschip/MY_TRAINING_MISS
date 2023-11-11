#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	int n;
	int j,i,c;
	printf("enter string\n");
	scanf("%[^\n]s",str);
	for(i=0;str[i]!='\0';i++)
	{
		if((str[i-1]=='\0')||(str[i-1]==' '))
			j=i;
		if((str[i]==' ')||(str[i+1]=='\0'))
		{
			c=i-1;
			if(str[i+1]=='\0')
				c=i;
			for(c,j;c>j;c--,j++)
			{
				n=str[c];
				str[c]=str[j];
				str[j]=n;
			}
		}
	}
	printf("%s\n",str);
}
