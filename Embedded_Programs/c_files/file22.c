#include <stdio.h>

int main()
{
	int n=0;

       //char arr[n];
	scanf("%d",&n);
        char arr[n];
	fgets(arr,sizeof(arr),stdin);
	puts(arr);
}
