#include<stdio.h>
int main()
{
	int i,j,n;
	unsigned int h;
	unsigned char*ptr=&h;

	printf("ENTER no of ELEMENTS________----------\n");
	scanf("%d",&n);
	//int a[n];
	printf("ENTER THE ELEMNTS=======\n");
	for(i=0;i<1;i++){
		scanf("%x",ptr+i);
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
		printf("%x  ",ptr[i]);

	}
	/*printf("AFTER ARRANGING THE ORDER\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}*/
	

		
}
