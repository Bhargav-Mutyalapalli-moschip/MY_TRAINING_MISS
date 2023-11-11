#include<stdio.h>
int main()
{
	char arr[100];
	scanf("%[^\n]",arr);
	char check[2];
	scanf("%s",check);
	int i,j=0,k;
	for(i=0;arr[i]!='\0';i++)
	{
		if(check[j]==arr[i])
		{
			arr[i]=' ';
			for(k=i;arr[k]!='\0';k++)
			{
				arr[k]=arr[k+1];
			}
			i=i-1;
			
		}
	}
	printf("%s\n",arr);
}
		
