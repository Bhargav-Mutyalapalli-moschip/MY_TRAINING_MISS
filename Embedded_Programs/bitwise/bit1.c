#include<stdio.h>
void main(){
	unsigned int x=243344435;
	x=x|(((x<<24)&(0xf<<28))|((x>>24)&(0xf<<4)));
	printf("%x",x);
}

