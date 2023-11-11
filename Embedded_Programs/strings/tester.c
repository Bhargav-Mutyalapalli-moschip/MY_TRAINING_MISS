
#include<stdio.h>
#include<limits.h>
#include<string.h>
int main()
{
	char str[50];
	int k,p;
	scanf("%[^\n]",str);
	int len,count1=0,count2=0,i,smallind1,smallind2,largind1,largind2,ind,ind1,count3=0,count4=0;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]!=' ')
		{
			if(count1==0)
				ind=i;
			count1++;
			if(count1>count2)
			{
				largind1=ind;
				count2=count1;
				largind2=i;
			}
		}
		else
		{
			count1=0;
			ind=0;
		}
	}
	printf("The largest is %d ------   %d\n",largind1,largind2);
	count4=INT_MAX;
	for(i=0;i<=len;i++)
	{
		
		if(str[i] == ' ' || i==len)
		{
			if(count3<count4)
			{
				smallind1=ind1;
				smallind2=i-1;
			        count4=count3;
			}
			count3=0;
		}
		else
			count3++;
		printf("count:%d\n",count3);


	}
	 printf("The smallest is %d ------   %d\n",smallind1,smallind2);
        printf("Smallest string is:\n");
        for(k=smallind1;k<=smallind2;k++)
        printf("%c",str[k]);
        printf("\n");
        printf("Largest string is:\n");
        for(k=largind1;k<=largind2;k++)
        printf("%c",str[k]);
        printf("\n");

}
