#include<stdio.h>
void mystringcmp(char *s1)
{
	mystrlen(s1);


}
int mystringlen(char *s1)
{
	int i,len=0;
if(s1==NULL)
	return 0;
else
	for(i=0;i!='\0';i++)
	{
	len++;
	}
	return len;
}
int main()
{

}

