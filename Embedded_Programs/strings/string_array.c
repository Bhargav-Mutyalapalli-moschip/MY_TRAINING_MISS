#include<stdio.h>
int main()
{
	char *p[]={"Pranav","Ram","bhargav","vijay","dharmi"};
	char arr[20];
	printf("%s------%s-------%s\n",p[0],p[1],p[2]);
	strcpy(arr,"PRANAV""RAM");
	printf("The inner string:%s\n",arr);

}
