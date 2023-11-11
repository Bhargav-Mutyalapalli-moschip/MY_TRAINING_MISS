void big(int *ptr,int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++)
		{
			if((*(ptr+i))>(*(ptr+j))){

				*(ptr+i)=(*(ptr+i))^(*(ptr+j));
				*(ptr+j)=(*(ptr+i))^(*(ptr+j));
				*(ptr+i)=(*(ptr+i))^(*(ptr+j));

			}
		}
		

	}
	printf("%p-----%d",&ptr[n-1],ptr[n-1]);
}
