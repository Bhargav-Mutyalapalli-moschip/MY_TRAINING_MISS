#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
int mystringcmp(char* copy5,char* copy6,int n);
int main()
{
	char s1[100];
	char s2[100];
	int k,out,count=0,c1,c2,i;
	scanf("%[^\n]",s1);
	__fpurge(stdin);
	scanf("%s",s2);	
	c1=strlen(s1);
	c2=strlen(s2);
	printf("%d-------%d\n",c1,c2);
	void *compareptr;
	compareptr=mystringcmp;
	for(i=0;i<=(c1-c2); )
	{

	        out=((int(*)(char*,char*,int))compareptr)(&s1[i],s2,c2);
		if(out==0)
		{
			count++;

			i=i+c2;
		}
		i++;

	}
	printf("The string is found =====%d--------------%s\n",count,s2);
		



	

}
int mystringcmp(char* copy5,char* copy6,int n)
{
        int i,m=0;
        if((copy5==NULL) || (copy6==NULL))
        return;

        for(i=0;i<n;i++)
	{
		if(copy5[i]!=copy6[i])
		return -1;
		
	}
	return 0;
}
