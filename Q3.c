// accept a file name and directory name from user and create that file in it 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dir.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    DIR * ptrDir = NULL;
    char FileName[64] = {'\0'};
    if(argc != 3)
    {
        printf("insufficient arguments\n");
        return -1;
    }

    ptrDir = opendir(argc[1]);
    if(ptrDir == NULL)
    {
        printf("unable to open directory\n");
        return -1;
    }

    sprintf(FileName,"%s/%s",argv[1],argv[2]);
    creat(FileName,0777);

    if((fd = open(FileName,O_RDONLY)) != -1)
    {
        printf("File is successfuly created\n");
        close(fd);
    }
    else{
        printf("unable to create file\n");
    }

    closedir(ptrDir);


    return 0;
}