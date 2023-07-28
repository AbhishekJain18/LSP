// file contains all the info of file which are present in that directory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/dir.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

#define MAXSIZE  1024

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    DIR *ptrDir = NULL;
    struct  dirent *ptrDirent = NULL;
    struct stat sobj;
    char buffer[1024] = {'\0'};
    char Fname[276] = {'\0'};
    if(argc != 3)
    {
        printf("Insuffient arguments\n");
        return -1;
    }

    fd = open(argv[2],O_RDWR);
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    } 

    ptrDir = opendir(argv[1]);
    if(ptrDir == NULL)
    {
        printf("Unable to find directory\n");
        close(fd);
        return -1;
    }

    while((ptrDirent = readdir(ptrDir))!= NULL)
    {
        sprintf(Fname,"%s/%s",argv[1],ptrDirent->d_name);
        stat(Fname,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            sprintf(buffer,"filename : %s\n Size : %ld\n Inode NO : %ld\n",ptrDirent->d_name,sobj.st_size,sobj.st_ino);
            write(fd,buffer,strlen(buffer));
        }
        memset(buffer,0,strlen(buffer));
    }

    while (ret = read(fd,buffer,MAXSIZE) != 0)
    {
        write(1,buffer,ret);
    }
    
    close(fd);
    closedir(ptrDir);

    return 0;
}