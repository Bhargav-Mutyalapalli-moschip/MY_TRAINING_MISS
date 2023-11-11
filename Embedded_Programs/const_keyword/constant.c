#include<stdio.h>
int main()
{
	char v=10;
	char c=26;
	const char *const ptr=&v;
	v++;

	printf("%d-----------%d\n",v,*ptr);
}
