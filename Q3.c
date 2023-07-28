//compare content of two files  
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
    int fd1 = 0,fd2 = 0;    
    struct stat sobj1, sobj2;
    int ret = 0;
    char buffer1[1024]={'\0'};
    char buffer2[1024]={'\0'};
    int icnt = 0;

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("unable to open file \n");
        return -1;
    }

    stat(argv[1],&sobj1);
    stat(argv[2],&sobj2);


    if(sobj1.st_size != sobj2.st_size)
    {
        printf("file are different\n");
        return -1;
    }

    while((ret = read(fd1,buffer1,sizeof(buffer1))) != 0)
    {
        ret = read(fd2,buffer2,sizeof(buffer2));
        if(memcmp(buffer1,buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("both files are identical\n");
    }
    else
    {
        printf("both file are different\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}