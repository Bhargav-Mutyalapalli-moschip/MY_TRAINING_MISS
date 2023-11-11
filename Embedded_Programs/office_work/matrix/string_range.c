#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,count=0,temp=0,var=0,new,old,es;
	char str[26];
	char d;
	printf("Enter a string\n");
	scanf("%s",str);
	n=strlen(str);
	char c;
	for(i=0;i<n;i++)
	{
		c=str[i];
		printf("The i value:%d\n temp:%d\n",i,temp);
		for(j=temp+1;j<n;)
		{
			if(c==str[j])
			{
				
				temp=i;
				new=j-i-1;
				if(new>var)
				{
					old=var;
					var=new;
			        }
				j=j+1;
			}
			if(var>old)
			{
				d=c;
				es=var;
			}
			else
			{
				d=c;
				es=old;
			}
			j++;
		}
	}
	printf("The range:%d\n",es);
	printf("The characetr:%c\n",d);
}
