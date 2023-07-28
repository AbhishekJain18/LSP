// directory name from use and print file names from directory 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/dir.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    //struct present in sys/dir.h file 
    DIR *dirObj = NULL;
    //struct present in dirent.h file
    struct dirent *direntobj = NULL;
    if(argc != 2)
    {
        printf("Insuffient arguments \n");
        return -1;
    }

    dirObj = opendir(argv[1]);
    if(dirObj == NULL)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((direntobj = readdir(dirObj)) != NULL)
    {
        printf("%s\n",direntobj->d_name);
    }

    closedir(dirObj);

    return 0;
}