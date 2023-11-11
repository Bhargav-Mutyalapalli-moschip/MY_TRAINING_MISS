#include<stdio.h>
int main()
{
	char arr[100];
	scanf("%[^\n]",arr);
	char copy[100];
	int i;
	for(i=0;arr[i]!='\0';i++)
	{
		if(arr[i]==' ')
		copy[i]=arr[i];
	}
	printf("%s\n",copy);
}



