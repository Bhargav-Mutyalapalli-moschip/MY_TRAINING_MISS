#include<stdio.h>
int main()
{
	int x=10;
	int y=19;
	int *ptr[2]={&x,&y};
	//printf("THe value:%d\n",(*(*(ptr+1))));
	int j=10;
	printf("%p--------%p\n",&j,&j);
}
