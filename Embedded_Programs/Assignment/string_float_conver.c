#include<stdio.h>
int main()
{
	char arr[10]="3.1453";
	int sum=0,temp,i;
	float res;
	int power=1000;
	for(i=0;arr[i]!='\0';i++)
	{
		if(arr[i]>='0' && arr[i]<='9')
		{
			temp=arr[i]-48;
			sum=sum*10+temp;
		}
	}
	printf("Sum:%d\n",sum);

	res=(float)sum/(float)power;
	printf("float value:%f\n",res);


}



