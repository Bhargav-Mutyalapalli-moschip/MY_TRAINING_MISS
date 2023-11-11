#include<stdio.h>

main() {

	int p = 35,q;
	int c=104;
	q = p++,p=c;

	printf("%d",q);
	printf("%d",p);

}
