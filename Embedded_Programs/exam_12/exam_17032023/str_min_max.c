#include<stdio.h>
#include<string.h>
#include<limits.h>
int main()
{
	char arr[100];
	int temp,ind=0,maxind=0,min=INT_MAX,i,j,max=0,minind=0;
        int len;
	printf("\nentr the strings : ");
	scanf("%[^\n]s",arr);
	printf("\nthe string is :%s",arr);
	len=strlen(arr);
	printf("len : %d ",len);
	for(i=0;i<=len;i++)
	{
		if((arr[i]==' ')||(arr[i]=='\0'))
		{
			if(max<(i-ind))
			{
				max=i-ind;
				maxind=ind;
			}
			if(min>(i-ind))
			{
				min=i-ind;
				minind=ind;
			}
			ind=i+1;
		}
	}

	printf("\n\nthe max string is :");
	for(i=0;i<max;i++)
	{
		printf("%c",arr[maxind]);
		maxind++;
	}
	printf("\n\nthe min string is :");
	for(i=0;i<min;i++)
	{
		printf("%c",arr[minind]);
		minind++;
	}
	printf("\n");
}
