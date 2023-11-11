#define SWAP(a,b) (a=a+b,b=a-b,a=a-b)
int main()
{
	int a=10,b=20,h;
        h=SWAP(a,b);
	printf("%d %d %d\n",a,b,h);
}
	
