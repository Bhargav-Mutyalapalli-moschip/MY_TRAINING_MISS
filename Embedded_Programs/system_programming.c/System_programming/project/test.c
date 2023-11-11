#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
	    if(strcmp("bank_server.c",dir->d_name)==0)
		    printf("File found\n");
	    else
		   printf("Not found\n");
	
        }
        closedir(d);
    }
    return(0);
}
