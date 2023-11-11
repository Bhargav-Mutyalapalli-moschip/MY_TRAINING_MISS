#include<stdio.h>
int main()
{
	int i,j,n;
	unsigned int h,g,k,l,m=0;
	printf("%x--%x--%x--%x--%x",&h,&g,&k,&l,&m);
	unsigned int *ptr=&h;

	printf("ENTER no of ELEMENTS________----------\n");
	scanf("%d",&n);
	//int a[n];
	printf("ENTER THE ELEMNTS=======\n");
	for(i=0;i<n;i++){
		scanf("%d",ptr+i);
		__fpurge(stdin);
	        
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++)
		{			
			if((*(ptr+i))>(*(ptr+j))){

				*(ptr+i)=(*(ptr+i))^(*(ptr+j));
				*(ptr+j)=(*(ptr+i))^(*(ptr+j));
				*(ptr+i)=(*(ptr+i))^(*(ptr+j));
				
			}
		}
		printf("%d  ",ptr[i]);

	}
	/*printf("AFTER ARRANGING THE ORDER\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}*/
	

		
}
