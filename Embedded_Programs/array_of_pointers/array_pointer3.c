#include<stdio.h>
void ascend(int **dptr,int m);
void reverse_number(int **dptr,int m);
int *inputs(int *ptr,int n);
int *inputs1(int *ptr,int n);
void digit_count(int **dptr,int m);
void binary_number(int **jptr,int m);
void decimal_number(int **jptr,int m);
void descend(int **dptr,int m);
int main()
{
	int x[5];
	int y[5];
	int i,j;
	//int *ptr=inputs(x,5);
	//int *ptr1=inputs1(y,5);
	int *sptr[2]={x,y};
	for(i=0;i<2;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&sptr[i][j]);
		}
	}
	ascend(sptr,5);
	descend(sptr,5);
//	digit_count(sptr,5);
//	reverse_number(sptr,5);
/*	for(int i=0;i<5;i++)
	printf("the main values:%d\n",sptr[1][i]);*/
	//binary_number(sptr,5);
	decimal_number(sptr,5);


}
void ascend(int **dptr,int m)
{
	int i,j,k=0,l=0,temp;
	for(i=0;i<m;i++,k++)
	{
		for(j=i+1;j<m;j++)
		{
			if(dptr[l][i]>dptr[l][j])
			{
				temp=dptr[l][i];
				dptr[l][i]=dptr[l][j];
				dptr[l][j]=temp;

			}

		}
		printf("%d\n",dptr[l][i]);
	}
}

void descend(int **dptr,int m)
{
	int i,j,k=0,l=1,temp;
	for(i=0;i<m;i++,k++)
	{
		for(j=i+1;j<m;j++)
		{
			if(dptr[l][i]<dptr[l][j])
			{
				temp=dptr[l][i];
				dptr[l][i]=dptr[l][j];
				dptr[l][j]=temp;

			}

		}
		printf("%d\n",dptr[l][i]);
	}
}
void digit_count(int **dptr,int m)
{
	int a=0,b=0,rem=0;
	int i=0,j;
	for(j=0;j<m;j++)
	{
		rem=0;
		printf("The count values:%d\n",dptr[a][j]);
		while(dptr[a][j]!=0)
		{
			dptr[a][j]=dptr[a][j]/10;
			rem++;
			
		}
		printf("%d\n",rem);
	}
}
/*void reverse_numbi1er(int **dptr,int m)
{
	int a=0,b=0,rem=0,sum=0;
	int i,j;
	for(j=0;j<m;j++)
	{
		sum=0;
		while(dptr[a][j]!=0)
		{
			printf("ENtered\n");
			rem=(dptr[a][j])%10;
			sum=sum*10+rem;
			printf("The value:%d-----%d\n",sum,rem);
			dptr[a][j]=(dptr[a][j])/10;
		}
		printf("The reversed numbers is\n");
		printf("%d\n",sum);
	}
}*/

void reverse_number(int **jptr,int m)
{
	int a=0,b=0,rem=0;
	int i=0,j,temp;
	for(j=0;j<m;j++)
	{
		b=0;
		temp=jptr[a][j];
		printf("The comming values:%d\n",jptr[a][j]);
		while(temp!=0)
		{
			rem=temp%10;
                        b=b*10+rem;
			temp=temp/10;
	
			
		}
		printf("%d\n",b);
	}
}
void binary_number(int **jptr,int m)
{
        int a=0,b=0,rem=0,i=1;
        int j,temp;
        for(j=0;j<m;j++)
        {
                b=0;
		i=1;
                temp=jptr[a][j];
                printf("The comming values:%d\n",jptr[a][j]);
                while(temp!=0)
                {
                        rem=temp%2;
                        b=b+rem*i;
                        temp=temp/2;
			i=i*10;


                }
                printf("%d\n",b);
        }
}

void decimal_number(int **jptr,int m)
{
        int a=1,b=0,rem=0,i=1;
        int j,temp;
        for(j=0;j<m;j++)
        {
                b=0;
		i=1;
                temp=jptr[a][j];
                printf("The comming values:%d\n",jptr[a][j]);
                while(temp!=0)
                {
                        rem=temp%10;
			if(rem>2)
				break;
                        b=b+rem*i;
                        temp=temp/10;
			i=i*2;


                }
		if(rem>2)
			continue;
                printf("%d\n",b);
        }
}
int *inputs(int *ptr,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		__fpurge(stdin);
		scanf("%d",&ptr[i]);
	}
}
int *inputs1(int *ptr,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		__fpurge(stdin);
		scanf("%d",&ptr[i]);
	}
}
	











