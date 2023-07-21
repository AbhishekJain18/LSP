// write a program which accepts file name from user and read data from file 
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define MAXFLESZE 1024

int main(int argc, char* argv[])
{
    int fd = 0;
    int ret = 0;    // to get return value of read function
    char buffer[MAXFLESZE] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }

    //read till file size in a chunks of 1024 bytes
    while(ret = read(fd,buffer,sizeof(buffer)) != 0)
    {
        //write on consol so we used 1
        write(1,buffer,ret);
    }

    
    close(argv[1]);

    return 0;
}
