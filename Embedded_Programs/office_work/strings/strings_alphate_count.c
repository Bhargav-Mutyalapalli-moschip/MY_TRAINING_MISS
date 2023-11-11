#include<stdio.h>
int main()
{
	char str[100];
	scanf("%[^\n]",str);
	int i,count=0,var=0,n;
	n=strlen(str);
	for(i=0;i<=n;i++)
	{
		if(str[i]!=' ')
		{
			if(str[i]=='a')
			{
				count=-1;
			}
		}
		if(str[i]==' ' || i==n)
		{
			
			if(count==0)
			{
				var++;
			}
			count=0;
		}
		
	}
	printf("The count:%d\n",var);
}



