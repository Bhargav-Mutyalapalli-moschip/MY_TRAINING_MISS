#include<stdio.h>
int main()
{
	char arr[100];
	int i;
	for(i=0;i<6;i++)
	{
		__fpurge(stdin);
		scanf("%c",&arr[i]);
	}
	//scanf("%[^\n]",arr);
	i=0;
	while(arr[i])
	{
		printf("%c----------------",arr[i]);
		putchar(arr[i++]);
		printf("\n");
	}
}
