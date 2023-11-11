#include<stdio.h>
int main()
{
           FILE *fp;
           char buff[2];
           fp=fopen("sample.txt","r");
           while(fscanf(fp,"%s",buff)!=EOF)
           {
                printf("%s",buff);
           }
           fclose(fp);
}
