//delete all file whose size is greater than 100 kb
#include<stdio.h>
#include<sys/dir.h>
#include <unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define MAXFILESIZE 100

int main(int argc, char*argv[])
{
    int fd = 0;
    char FileName[276] = {'\0'};
    DIR *ptrDir = NULL;
    struct dirent *ptrDirent = NULL;
    struct stat sobj;
    
    if(argc != 2)
    {
        printf("Insuffient arguments\n");
        return -1;
    }

    ptrDir = opendir(argv[1]);
    if(ptrDir == NULL)
    {
        printf("unable to open directory\n");
        return -1;
    }

    while((ptrDirent = readdir(ptrDir)) != NULL)
    {
        sprintf(FileName, "%s/%s",argv[1],ptrDirent->d_name);
        stat(FileName, &sobj);
        if((sobj.st_size > MAXFILESIZE) && (sobj.st_mode == S_ISREG))
        {
            if((remove(FileName))==-1)
            {
                printf("Unable to delete file\n");
            }
            else{
                printf("File deleted successfully\n");
            }
        }
    }

    closedir(ptrDir);

    return 0;
}