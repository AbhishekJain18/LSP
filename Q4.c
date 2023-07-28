// write program which accepts directory name from user write all data of that files <ZIP file>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/dir.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

#define MAXSIZE  1024
#define DELIMIITOR "\n~EOF~\n"
#define FILENAME "FILENAME :"
#define FSIZE "Size :"

int main(int argc, char *argv[])
{
    int fd = 0, fd2 = 0, ret = 0;
    DIR *ptrDir = NULL;
    struct  dirent *ptrDirent = NULL;
    struct stat sobj;
    char FName[] = "AllCombine.txt";
    char ReadFname[276] = {'\0'};  // for dirent->d_name = 256 + our 20 bytes
    char buffer[MAXSIZE] = {'\0'};
    char FInfoString[256] = {':'};
    if(argc != 2)
    {
        printf("insufficent argunets\n");
        return -1;
    }

    ptrDir = opendir(argv[1]);
    if(ptrDir == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = open(FName,O_RDWR);
    if(fd == -1)
    {
        printf("unable to open file\n");
        closedir(ptrDir);
        return -1;
    }


    while ((ptrDirent = readdir(ptrDir)) != NULL)
    {
        sprintf(ReadFname,"%s/%s",argv[1],ptrDirent->d_name);
        stat(ReadFname,&sobj);
        if(sobj.st_size > 0)
        {
            if(((fd2 = open(ReadFname,O_RDONLY)) != -1) && (S_ISREG(sobj.st_mode)))       /// opening file to read
            {
                sprintf(FInfoString,"%s%s %s%ld",FILENAME,ptrDirent->d_name,FSIZE,sobj.st_size);  // that file name and size for ref
                write(fd,FInfoString,sizeof(FInfoString));   
                while((ret = read(fd2,buffer,sizeof(buffer))) != 0)
                {                                      
                   write(fd,buffer,ret);                                                    //write into allcombine    
                }
                close(fd2);                                                                 //close reading file 
                memset(FInfoString,0,sizeof(FInfoString));
                memset(buffer,0,sizeof(buffer));
            }
        }

    }

    close(fd);      
    closedir(ptrDir);


    return 0;
}