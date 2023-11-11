#include<stdio.h>
int main()
{
	char arr[100];
	scanf("%s",arr);
	char i,k=0,count=0,j;
	for(j=0;arr[j]!='\0';j++)
	{
		if(arr[j]==1)
			continue;
		count=0;
		for(i='0';i<='z';i++)
		{
			if(arr[j]==i)
			{
				count++;
				for(k=j+1;arr[k]!='\0';k++)
				{
					if(arr[j]==arr[k]){
						count++;
						arr[k]=1;
						


					}
				}
				printf("%c---------%d\n",i,count);
			}
		}
	}
}


