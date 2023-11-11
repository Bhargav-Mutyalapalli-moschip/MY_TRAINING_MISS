#include<stdio.h>
#include<string.h>
int main()
{
	char str[20]="3.145";
	int i,j,k=0;
	float arr[20];
	int temp;
	int sum=0;
	int power=0;
	int len=strlen(str);
	printf("len:%d\n",len);
	for(i=0;i<=len;i++)
	{
		if(str[i]=='.')
		{
			continue;

		}
		else
		{
			temp=str[i]-48;
			sum=sum*10+temp;
		}


	}
	//printf("%d",sum);
	if(len<=6)
	power=100;
	else
		power=1000;
	float percent;
	printf("Power:%d\n",power);
	percent=((float)sum/(float)power);
	printf("%f",percent);


	
			

}
