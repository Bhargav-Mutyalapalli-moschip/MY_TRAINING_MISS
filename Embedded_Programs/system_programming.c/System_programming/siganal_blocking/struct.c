#include<stdio.h>
#include<string.h>
union det
{
	char c[5];
	int s;
	char ch[5];
}n={"ank",56,"itha"},t;
int main()
{
	strcpy(t.c,"aksh");
	t.s=10;
	strcpy(t.ch,"akki");
	printf("%s%s\n%d\n",t.c,t.ch,t.s);
	printf("%s%s\n%d\n",n.c,n.ch,n.s);
	
}
	
