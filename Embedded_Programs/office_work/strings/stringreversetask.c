#include<stdio.h>
#include<string.h>
int mystringrev(char*,int,int);
int main()
{
	char copy[100];
	scanf("%[^\n]",copy);
	int i=0,j=0,leng,k,a;
	a=strlen(copy);
	int start = 0;
	int ind = 0;
	for(i = 0; i < a; i++)
	{	
		
		//printf("ind:%d\n   i:%d \n",ind,i);
		if(copy[i] == ' ' || i+1 == a )
		{	
			
			//printf("--\n");
			if(i+1 == a)
				ind++;	
			start = mystringrev(copy, start, ind);
		}
		else
		{	ind = i;
			ind++;
			
		}

	}	
	copy[i] = '\0';
	printf("after reversing:\n%s\n",copy);
}
int mystringrev(char* ves,int s, int ind)
{
	int i,m,l;
	char temp;
	for(i=s,l=ind-1;i<l;i++,l--)
	{
		temp=ves[l];
		ves[l]=ves[i];
		ves[i]=temp;
		
	}
	printf("ind:%d\n",ind);
	ves[ind] = ' ';
	return ind+1;

}

	


