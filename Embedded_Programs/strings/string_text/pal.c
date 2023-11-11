#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k;
	char str[20];
	printf("Enter the string \n");
	scanf("%s",str);
	k=strlen(str);
	for(i=0,k=k-1;k>=i;k--,i++)
	{
		if(str[i]!=str[k])
			break;
	}
	if(k<i)
		printf("pal\n");
	else
		printf("not pal\n");
}
	

