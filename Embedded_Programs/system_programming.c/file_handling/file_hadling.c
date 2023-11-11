#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("sample.txt","w+");
	fprintf(fp,"%s");
}
