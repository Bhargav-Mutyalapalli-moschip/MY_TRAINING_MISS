#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,n,count=0,temp=0,var=0,new,old,es;
	char str[26];
	printf("Enter a string\n");
	scanf("%s",str);
	n=strlen(str);
	char c;
	for(i=0;i<n;i++)
	{
		c=str[i];
		for(j=i+1;j<n;j++)
		{
			if(c==str[j])
			{
				temp=i;
				new=j-i-1;
				old=var;
				var=new;
			}
			if(var>old)
			{
				es=var;
			}
			else
				es=old;
		}
	}
	printf("The range:%d\n",es);
}
