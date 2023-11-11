#include<stdio.h>
int main()
{
	int i,j;
	int mat[3][3]={1,2,3,4,5,6,7,8,9};
	for(i=2;i>=0;i--)
	{
		for(j=2;j>=0;j--)
			printf("%d",*(*(mat+j)+i));
	}
}
