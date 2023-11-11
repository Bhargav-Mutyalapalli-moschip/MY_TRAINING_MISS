#include<stdio.h>
int main()
{
	char *p="%s ram %ld";
	char *q="%s ramram %s";
	char *r="%s ramu %s";
	printf(p,q,r);
	printf("\n");
}
