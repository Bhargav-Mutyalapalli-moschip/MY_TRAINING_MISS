#include<stdio.h>
int main()
{
	unsigned int h,k,l;
//	printf("%x ---- %x ----- %x\n",&h,&k,&l);
	unsigned int *ptr=&h;
	int i,j,v,n;
	scanf("%d",&n);
	__fpurge(stdin);
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	for(i=0;i<1;i++)
	{
		for(j=i+1;j<2;j++)
		{
			for(v=j+1;v<3;v++)
			{
				if(((*(ptr+i))>(*(ptr+j)))&&((*(ptr+i))>(*(ptr+v))))
					printf("A is bigest %d\n",(*(ptr+i)));
				else if(((*(ptr+j))>(*(ptr+i)))&&((*(ptr+j))>(*(ptr+v))))	
					printf("B is bigest %d\n",(*(ptr+j)));
				else
                                        printf("c is bigest %d\n",(*(ptr+v)));
			}
		}
	}
}

