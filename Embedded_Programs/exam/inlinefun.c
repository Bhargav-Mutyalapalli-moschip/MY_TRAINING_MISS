#include<stdio.h>
static inline int foo()
{
	int i;
	while(i < 10000, i++);
    return 2;
}  
int main()
{
  
    int ret;
  
    // inline function call
    ret = foo();
  
    printf("Output is: %d\n", ret);
    return 0;
}
