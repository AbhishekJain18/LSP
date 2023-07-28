//write first read first 10 bytes from files present in directory
#include<stdio.h>
#include<sys/stat.h>
#include<sys/dir.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE  10

int main(int argc, char *argv[])
{
    DIR *ptrDir = NULL;
    struct dirent *ptrdirent = NULL;
    struct stat sobj;
    char Buffer[10] = {'\0'};
    int fd1 = 0, fd2 = 0,ret = 0;
    char Filename[276] = {'\0'};
    
    if(argc != 3)
    {
        printf("insuffient arguments\n");
        return -1;
    }

    ptrDir = opendir(argv[1]);
    if(ptrDir == NULL)
    {
        printf("unable to directory file\n");
        return -1;
    }

    fd1 = open(argv[2],O_RDWR);
    if(fd1 == -1)
    {
        printf("unable to open file\n");
        closedir(ptrDir);
        return -1;
    }

    while((ptrdirent = readdir(ptrDir)) != NULL)
    {
        sprintf(Filename,"%s/%s",argv[1],ptrdirent->d_name);
        //printf("%s\n",Filename);
        fd2 = open(Filename,O_RDONLY);
        if((fd2 != -1) && ((ret = read(fd2,Buffer,MAXSIZE)) != 0))         
        {
            write(fd1,Buffer,ret);
        }
        close(fd2);
        memset(Buffer,0,MAXSIZE);
    }   

    close(fd1);
    closedir(ptrDir);


    return 0;
}