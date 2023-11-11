#include<stdio.h>
int main()
{
	/*int count;
	count=strcspn("pranav bhargav","zzv");
	printf("The return value:%d\n",count);*/
	char *p,str[]="                   main()";
	strcpy(str,str+strspn(str, " \t"));
//	puts(str);

}
