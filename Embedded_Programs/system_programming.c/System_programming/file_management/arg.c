#include<stdio.h>
#include<stdarg.h>
void func(int val,...)
{
	int i=0;
	va_list num;
	va_start(num,val);
	for(i=val;i>=0;i=va_arg(num,int))
	printf("%d\n",i);
	va_end(num);
	printf("\n");

}
void main()
{
	func(80,217,218,417,423,418);
	func(999999999);
	func(8888);
}



