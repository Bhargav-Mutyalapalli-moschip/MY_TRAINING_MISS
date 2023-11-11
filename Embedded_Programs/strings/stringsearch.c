#include<stdio.h>
int mystringcmp(char* copy5,char* copy6);
int main()
{
	char s1[100];
	char s2[100];
	int k;
	scanf("%[^\n]",s1);
	__fpurge(stdin);
	scanf("%s",s2);
	k=mystringcmp(s1,s2);
	if(
	

}
int mystringcmp(char* copy5,char* copy6)
{
        int i,m=0;
        if((copy5==NULL) || (copy6==NULL))
        return;
        for(i=0;copy5[i]!='/0';i++)
	{
		if(copy6[m]==copy5[i]){
			m++;
		}
		
	}
}
