#include<stdio.h>
void palindrome(char *str,int i,int j);
int main()
{
	char str[20];
	printf("Enter the string to check the palindrome pr not\n");
	scanf("%s",str);
	int i,j,ind;
	for(i=0;str[i]!='\0';i++)
	{
		for(j=i;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				ind=j;
				palindrome(str,i,j);
			}
			
		}
		i=i+ind;
	}




}
void palindrome(char *str,int i,int j)
{

	int n,count=0,check,len;
	int arr[10];
	static int x=0;
	arr[x]=j-i;
	x++;
	check=j/2;
	len=j;
	for(i;len,i<len;len--,i++)
	{
		if(str[i]==str[len])
			count++;
	}
	if(count==check)
	{
		printf("Plaindrome string\n");
		printf("%s",str);
	}
	else
		printf("Not a palindrome\n");
	for(i=0;i<x;i++)
	printf("The values:%d\n",x);
}

