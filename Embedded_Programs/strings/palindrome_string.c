#include<stdio.h>
#include<string.h>
int main()
{
	int i,len,n=0,l;
	char str[100];
	printf("Enter the string\n");
	scanf("%s",str);
	len=strlen(str);
	printf("The len:%d\n",len);
	l=len-1;
	for(i=0,l;i<l;i++,l--)
	{
		if(str[i]==str[l])
			n++;
	}
	printf("The n:%d\n",n);
	printf("The len:%d\n",len);
	if(n==(len/2))
	printf("%s is a palindrome string\n",str);
	else
	printf("%s is not a palindrome string\n",str);
}
	
		



