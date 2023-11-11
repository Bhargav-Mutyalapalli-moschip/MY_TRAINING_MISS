#include<stdio.h>
int main()
{
	char str[50];
	scanf("%s",str);
	int i,j,count=0,k;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
			continue;
		count=0;
		for(j=0;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				count++;
				k=j;
			}
		}
		printf("%c----%d\n",str[i],count);
		str[i]=' ';
		str[k]=' ';
	}
}
	
