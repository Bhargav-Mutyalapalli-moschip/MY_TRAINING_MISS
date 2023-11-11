#include<stdio.h>
#include<string.h>
int main()
{
	char s1[] = "hello",s2[]="abce";
	strcpy(s1," ");
	s2[0] = s1[0];
	printf("%ld---%ld",strlen(s1),strlen(s2));
}
