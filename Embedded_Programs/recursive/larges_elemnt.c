#include<stdio.h>
#define NM 5
int ind=0,ind1;
int i1,i2=1;
int main()
{
	int arr[NM];
	int i,len,res;
	for(i=0;i<NM;i++)
	scanf("%d",&arr[i]);
	len=NM;
	largest_ele(arr,len);
	printf("The largest eleemnt is:%d\n",ind1);
	
}
void largest_ele(int *arr,int n)
{
	int temp,var=0;
	if(i2<n)
	{
		printf("i2:%d\n",i2);
		printf("ind:%d\n",ind);
		if(ind1<arr[i2])
		ind1=arr[i2];
		i2++;
		largest_ele(arr,n);
	}
	//return ind1;

	

}



