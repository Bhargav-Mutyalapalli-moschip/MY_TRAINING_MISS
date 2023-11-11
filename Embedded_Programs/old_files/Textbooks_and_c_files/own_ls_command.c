#include <stdio.h>
#include <dirent.h>
int main()
{
	int i=0;
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    folder = opendir(".");
    if(folder == NULL)
    {
        perror("Unable to read directory");
        return(1);
    }
    while( (entry=readdir(folder)) )
    {
        files++;
        printf("%d:%s\n",i,entry->d_name );
	i++;
    }
    closedir(folder);
    return(0);
}
