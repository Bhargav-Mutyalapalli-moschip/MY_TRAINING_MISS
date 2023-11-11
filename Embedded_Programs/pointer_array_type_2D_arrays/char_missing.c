#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	printf("enter the number of characters\n");
	scanf("%d",&n);
	char str[20]="Acefz";
	int len;
	len=strlen(str);
	int j,p=0;
	char i,k,l;
	/*for(p=0;p<n;p++)
	{
		scanf("%c",&str[p]);
	}*/
	k=str[p];
	l=str[len-1];
	printf("%c----------%c\n",k,l);
	for(i=k,j=0;i<l;i++,j++)
	{
		if(i==str[j])
		continue;
		else
		{
			printf("The character:%c\n",i);
			j--;
		}
	}
}
