void sec_high(void *ptr,int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++)
		{
			if((*(((int *) ptr)+i))>(*(((int *) ptr)+j))){

				*(((int *) ptr)+i)=(*(((int *) ptr)+i))^(*(((int *) ptr)+j));
				*(((int *) ptr)+j)=(*(((int *) ptr)+i))^(*(((int *) ptr)+j));
				*(((int *) ptr)+i)=(*(((int *) ptr)+i))^(*(((int *) ptr)+j));

			}
		}
		

	}
	printf("%p-----%d",&((int *) ptr)[n-2],((int *) ptr)[n-2]);
}
