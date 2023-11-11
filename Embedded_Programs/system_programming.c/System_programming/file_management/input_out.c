#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int a;
	scanf("%d",&a);
	//__fpurge();
        fputs("This is a line of text\n", stdout);
	printf("The out:%d\n",stdout);
	printf("The out:%f\n",stdout);
	printf("The out:%c\n",stdout);
	printf("The out:%s\n",&stdout);
	printf("The out:%d\n",stdout);
	printf("The out:%x\n",stdout);
	printf("The out:%o\n",stdout);
	printf("The out:%g\n",stdout);
	printf("The out:%b\n",stdout);
	printf("The out:%u\n",stdout);
	printf("The out:%p\n",&stdout);
	printf("The out:%e\n",&stdout);
}
