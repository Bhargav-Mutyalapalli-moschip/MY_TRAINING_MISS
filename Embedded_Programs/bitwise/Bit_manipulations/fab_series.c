void fab_series(int a,int b,int n)
{
	int c;
	while(n>0)
	{
		c=a+b;
		a=b;
		b=c;
		printf("%d ",b);
		n--;
		
	}
	
	
}
