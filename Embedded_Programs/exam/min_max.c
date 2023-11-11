#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int main()
{
	int a=4,b=25,result;
	result = a ^ ((a ^ b) & -(a < b));
	printf("The num after rotation:%d\n",result);
}



