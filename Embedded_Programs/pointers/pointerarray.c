#include<stdio.h>
int main()
{
	int i,j,n;
	printf("ENTER no of ELEMENTS________----------\n");
	scanf("%d",&n);
	int a[n];
	printf("ENTER THE ELEMNTS=======\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	        
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++)
		{			
			if(a[i]>a[j]){
				a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];
			}
		}
	//	printf("%d  ",a[i]);

	}
	printf("AFTER ARRANGING THE ORDER\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	

		
}
