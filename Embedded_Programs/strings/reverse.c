#include<string.h>
int main()
{
	char str[100];
	scanf("%[^\n]",str);
	int i,len,k=0;
	len=strlen(str);
	for(i=0;i<=len;i++)
	{
		if(str[i]== ' ' || i==len)
		{
			reverse(str,k,(i-1));
			k=i+1;
		}
	}
	printf("The reveresed:%s\n",str);
}
void reverse(char *str,int s,int e)
{
	int i,j;
	char c;
	for(i=s,j=e;i<j;i++,j--)
	{
		c=str[i];
		str[i]=str[j];
		str[j]=c;
	}
}


