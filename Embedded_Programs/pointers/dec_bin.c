void dec_bin(int *ptr,int n)
{
	int i,sum,i1,rem;
	for(i=0;i<n;i++)
	{
		sum=0;
		i1=1;
		while((*(ptr+i))!=0)
		{
			rem=(*(ptr+i))%2;
			sum=sum+(i1*rem);
			(*(ptr+i))=(*(ptr+i))/2;
			i1=i1*10;
		}
		printf("%p-----%d\n   ",&ptr[i],sum);
	}
}
