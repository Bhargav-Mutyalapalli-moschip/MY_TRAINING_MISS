#include<stdio.h>
int main()
{
	char sen[100];
	scanf("%[^\n]",sen);
	strrev(sen);
	printf("%s",sen);
}
