#include<stdio.h>
void main()
{
	char str[100];
	char arr[20];
	scanf("%[^\n]",str);
	__fpurge(stdin);
	scanf("%s",arr);
	int len1,len2;
	len1=strlen(str);
	len2=strlen(arr);
	int i,j,k,count=0,inc=0;
	for(i=0;i<=(len1-len2);i++)
	{
		k=i;
		count=0;
		for(j=0;j<len2;j++,k++)
		{
			if(str[k]==arr[j])
			{
				count++;
			}
		}
		if(count==len2)
		{
			inc++;
			i=i+len2;
		}
	}
	if(inc>0)
		printf("The string is found of %d times\n",inc);
}


