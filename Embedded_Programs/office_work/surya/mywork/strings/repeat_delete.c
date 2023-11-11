#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	printf("ENter the string\n");
	scanf("%s",str);
	int i,j,k,l;
	int n;
	char c,d;
	n=strlen(str);
	for(i=0;str[i]!='\0';i++)
	{
		c=str[i];
		printf("First innerloop\n");
		for(j=i+1;str[j]!='\0';j++)
		{
		        printf("second innerloop\n");
			if(c==str[j])
			{

				d=c;
				str[i]=1;
				for(k=j;str[k]!='\0';k++)
				{
					str[k]=str[k+1];
				}
		                printf("third innerloop\n");
				j=j-1;
			}
		}

	}
	printf("%s  ",str);
	
}



