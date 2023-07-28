// directory name from use and print file names and types from directory 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/dir.h>
#include <dirent.h>


int main(int argc, char *argv[])
{
    char DIRNAME[20] = {'\0'};
    DIR *dirObj = NULL;
    struct dirent *direntobj = NULL;
     
    printf("Enter directory name : \n");
    scanf("%s", DIRNAME);

    dirObj = opendir(DIRNAME);
    while((direntobj = readdir(dirObj)) != NULL)
    {
        printf("%s and type %d\n",direntobj->d_name,direntobj->d_type);
    }   

    closedir(dirObj);

    return 0;
}