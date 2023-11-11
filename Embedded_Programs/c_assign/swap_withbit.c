void swap_withbit(int a,int b)
{
	a=a^b;
	b=a^b;
	a=a^b;
	printf("A after swapping:%d\n B after swapping:%d\n",a,b);
}
