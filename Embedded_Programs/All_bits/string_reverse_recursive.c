#include<stdio.h>
#include<string.h>
void string_reverse(int n);
int x=0;
char str[50];
char c;
int main()
{
	int len=0;
	scanf("%s",str);
	len=strlen(str);
	str[len]='\0';
	len=len-1;
	printf("The length:%d\n",len);
	string_reverse(len);
	printf("The output:%s\n",str);
}
void string_reverse(int n)
{
	if(x<n)
	{
		c=str[x];
		str[x]=str[n];
		str[n]=c;
		x++;
		n--;
		string_reverse(n);
	}
}


	
