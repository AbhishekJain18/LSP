// check weather file is present or not in directory 
#include <stdio.h>
#include <sys/dir.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[])
{
    DIR *prtDir = NULL;
    struct dirent *objDirent = NULL;

    if(argc != 3)
    {
        printf("insuffient arguments\n");
        return -1;
    }

    prtDir = opendir(argv[1]);
    if(prtDir == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((objDirent = readdir(prtDir)) != NULL)
    {
        if(strcmp(argv[2],objDirent->d_name) == 0)
        {
            printf("file present in directory\n");
            break;
        }   
    }

    if(objDirent == NULL)
    {
        printf("file not in directory\n");
    }

    closedir(prtDir);
    
    return 0;
}