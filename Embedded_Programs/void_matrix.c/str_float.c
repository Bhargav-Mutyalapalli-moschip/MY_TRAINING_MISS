#include<stdio.h>
#include<string.h>
int main()
{
	char str[20]="3145678.8555";
	int i,j,k=0;
	double arr;
	long int temp,var=1,c=0;
	long int sum=0;
	int len=strlen(str);
	printf("len:%d\n",len);
	for(i=0;i<len;i++)
	{
		if(str[i]=='.')
		{
			c++;
			var=c;
			continue;

		}
		if(c!=0)
		var=var*10;
		temp=str[i]-48;
		sum=sum*10+temp;
		


	}
	arr=(double)sum/(double)var;
	printf("The output:%lf\n",arr);
	




}
