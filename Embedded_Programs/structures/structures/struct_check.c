#include<stdio.h>
struct book
{
	char name[32];
	int nop;
	float price;
};
int main()
{
	int x=10;
	{
        static struct book eop={"C",550,350.32};
	printf("Welc123ome\n");
	printf("%s\n",eop.name);
	}
        printf("%s\n",eop.name);
}




	
