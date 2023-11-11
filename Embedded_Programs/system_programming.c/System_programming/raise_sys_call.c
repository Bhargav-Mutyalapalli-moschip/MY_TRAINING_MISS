#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{
	 int i=0;
	while(1)
	{
		
		printf("Hello");
		printf("%d\n", i++);
		//i++;
		if(i>=10)
		raise(9);
	}
}


