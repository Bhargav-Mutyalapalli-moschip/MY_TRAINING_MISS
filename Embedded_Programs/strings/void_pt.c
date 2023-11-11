#include<stdio.h>
int main()
{
/*	char *ptr="void pointer";
	void *vptr;
	vptr=&ptr;
	printf("%s\n",ptr);
	printf("%s\n",*((char **)vptr));*/
	int n=0x12345678;
	char *ptr=(char *)&n;
	for(int i=4;i>0;i--)
	printf("%x",ptr[i-1]);

	
}

