#include<stdio.h>
int main()
{
	char arr[100];
	scanf("%[^\n]",arr);
	int i=0;
	while(arr[i])
	{
		putchar(arr[i++]);
	}
}
