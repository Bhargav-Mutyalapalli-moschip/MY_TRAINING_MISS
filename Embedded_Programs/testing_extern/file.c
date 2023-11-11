static void call();
void(*fptr)()=call;
extern int *ptr;
static void call()
{
	int x=*ptr;
	printf("%d",x);
}

