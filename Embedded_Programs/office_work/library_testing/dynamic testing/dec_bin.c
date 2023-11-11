void dec_bin(void *ptr,int n)
{
	int i,sum,i1,rem;
	for(i=0;i<n;i++)
	{
		sum=0;
		i1=1;
		while((*(((int *) ptr)+i))!=0)
		{
			rem=(*(((int *) ptr)+i))%2;
			sum=sum+(i1*rem);
			(*(((int *) ptr)+i))=(*(((int *) ptr)+i))/2;
			i1=i1*10;
		}
		printf("%p-----%d\n   ",&((int *) ptr)[i],sum);
	}
}
