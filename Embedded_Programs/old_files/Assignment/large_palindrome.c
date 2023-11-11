#include<stdio.h>
int main()
{
	int i,j,k,len,count=0,count1=0,p,ind1,ind2;
	char str[50];
	printf("Enter the string\n");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				count=0;
				for(k=i,p=j;p>k;p--,k++)
				{
					if(str[k]==str[p])
					{
						count++;
						if((j-i+1)/2==count)
						{
							if(count>count1)
							{
								ind1=i;
								ind2=j;
								count1=count;
							}
						}
						
					}
					else
						break;
				}
			}
			else
			{
				count=0;
				continue;
			}
		}
	}
	printf("Ind1 is:%d\nInd2 is %d\n",ind1,ind2);
	for(j=ind1;j<=ind2;j++)
	printf("%c",str[j]);
}





