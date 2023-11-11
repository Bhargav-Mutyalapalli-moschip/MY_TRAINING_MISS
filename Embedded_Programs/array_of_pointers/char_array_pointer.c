#include<stdio.h>
int stringlen(char **cptr,int n);
char* stringcopy(char **cptr,char *ptr);
void stringreverse(char **cptr,int n);
char *ascend(char **cptr,int n);
char *descend(char **cptr,int n);
int main()
{
	char a[200];
	char b[200];
	char c[200];
	char *cptr[2]={a,b};
	int i,j,k=0;
	for(i=0;i<2;i++)
	{
		
		scanf("%s",cptr[i]);

	}
	for(i=0;i<2;i++)
	{
		printf("The output:%s\n",cptr[i]);
	}
	int res=stringlen(cptr,2);
	printf("The count:%d\n",res);
	stringreverse(cptr,res);
	//stringcopy(cptr,c);
	descend(cptr,res);
	ascend(cptr,res);
}
int stringlen(char **cptr,int n)
{
	int k,d=0,count=0;
	for(k=0;cptr[d][k]!='\0';k++)
	{
		count++;
	}
	return count;
}
void stringreverse(char **cptr,int n)
{

	int k,d=0,count=0;
	char temp;
	for(k=0,n=n-1;n>k;k++,n--)
	{
		printf("Entering\n");
		temp=cptr[d][n];
		cptr[d][n]=cptr[d][k];
		cptr[d][k]=temp;

	}
	printf("%s\n",cptr[0]);
}
char* stringcopy(char **cptr,char *ptr)
{
	int k,d=0,count=0;
	for(k=0;cptr[d][k]!='\0';k++)
	{
		ptr[k]=cptr[d][k];
	}
	ptr[k]='\0';
	printf("%s",ptr);
}
char *descend(char **cptr,int n)
{
	int i,j,l=0;
	char temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(cptr[l][i]<cptr[l][j])
			{
				/*temp=cptr[l][i];
				cptr[l][i]=cptr[l][j];
				cptr[l][j]=temp;*/
				cptr[l][i]=cptr[l][i]^cptr[l][j];
				cptr[l][j]=cptr[l][i]^cptr[l][j];
				cptr[l][i]=cptr[l][i]^cptr[l][j];
			}
		}
	}

	printf("%s\n",cptr[l]);
}
char *ascend(char **cptr,int n)
{
	int i,j,l=0;
	char temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(cptr[l][i]>cptr[l][j])
			{
				/*temp=cptr[l][i];
				cptr[l][i]=cptr[l][j];
				cptr[l][j]=temp;*/
				cptr[l][i]=cptr[l][i]^cptr[l][j];
				cptr[l][j]=cptr[l][i]^cptr[l][j];
				cptr[l][i]=cptr[l][i]^cptr[l][j];
			}
		}
	}

	printf("%s",cptr[l]);
}




