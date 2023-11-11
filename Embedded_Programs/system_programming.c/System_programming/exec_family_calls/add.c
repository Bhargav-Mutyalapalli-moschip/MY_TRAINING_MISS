#include<stdio.h>
#include<unistd.h>
int main()
{
	int a=10,b=20;
	a=a+b;
	printf("The output:%d\n",a);
	execlp("gnome-calculator","gnome-calculator",NULL);
}
