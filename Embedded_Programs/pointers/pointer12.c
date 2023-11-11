#include<stdio.h>
int main()
{
	unsigned int h,k,l;
        printf("%x-----%x----%x\n",&h,&k,&l);
	unsigned int *ptr;
	int i,j,v,n;
	ptr=&h;
	printf("Enter number\n");
	scanf("%d",&n);
	__fpurge(stdin);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		printf("%p\n",ptr+i);
		scanf("%d",(ptr+i));
		__fpurge(stdin);
		//printf("%x ---->\n",(ptr+i));
	}
	//printf("%p ---- %p ----- %p\n",&h,&k,&l);
	//printf("%d-%d-%d\n",h,k,l);
	/*for(i=0;i<3;i++)
		printf("%p-%d\n",ptr+i,*(ptr+i));
		
	:printf("%p-%p-%p->>>%d-%d-%d\n",&h,&k,&l,h,k,l);
	printf("%d-%d-%d\n",h,k,l);*/

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

