#include<stdio.h>
int main()
{
	double p=50.96;
	double *ptr=NULL;
	ptr=&p;
	*ptr=53.49;
	printf("%p--%lf--%d--%d\n",&p,p,sizeof(&p),sizeof(p));
	 printf("%p--%d\n",ptr,sizeof(ptr));
	  printf("%lf--%d\n",*ptr,sizeof(*ptr));
	   printf("%p--%d\n",&ptr,sizeof(ptr));
	  }
