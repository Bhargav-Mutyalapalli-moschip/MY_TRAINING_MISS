#include<stdio.h>
#include<string.h>
void reverse_string(char *str,int start,int end);
int main()
{
	int i=0,len;
	char str[100];
	printf("enter the string:");
	scanf("%s",str);
	len=strlen(str);
	len=len-1;
	reverse_string(str,i,len);
	printf("After reverseing:%s\n",str);
}
void reverse_string(char *str,int start,int end)
{
	char temp;
	if(start < end)
	{
		temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
		reverse_string(str,start,end);
	}
}


