#include<stdio.h>
int main()
{
	char str[10]="5689";
	char str1[20]="136.589";
	int x;
	float y;
	sscanf(str,"%d",&x);
	printf("The int:%d\n",x);
}
