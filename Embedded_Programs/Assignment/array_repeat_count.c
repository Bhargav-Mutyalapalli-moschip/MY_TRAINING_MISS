#include <stdio.h>
int main() {
    int arr[]={2,7,4,7,8,3,4,7};
    int i,count=0,j,var;
    for(i=0;i<8;i++)
    {
	    for(j=i+1;j<8;j++)
	    {
		    
		    if(arr[i]==arr[j])
		    {
			    count++;
			    if(count==1)
			    printf("The repetaed elements:%d\n",arr[j]);
		    }
		   

	    }
	    count=0;
    }


}
