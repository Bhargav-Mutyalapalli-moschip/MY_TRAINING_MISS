#include<stdio.h>
int main()
{
	int i=10;
	int j=15;
	int k=0;
	k=(i+j,printf("%d\n",k));
        i=(j,printf("%d\n",i));
	j=(k=20,printf("%d\n",j));
	k=(k=41,printf("%d\n",k));
	k=(i+j+k,printf("%d\n",k));
        printf("%d",k);

}
