//hole of size 1kb at the end of file
#define _GNU_SOURCE // this define always needs to be above fcntl because of ifdef and ifndef
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
    int fd = 0, RET  = 0;
    
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY|O_TRUNC);
    if(fd == -1)
    {
        printf("unable to open file\n");
        return -1;
    }

    // this isn't working need to read 
    // RET = fallocate(fd,FALLOC_FL_PUNCH_HOLE|FALLOC_FL_KEEP_SIZE,0,1024);

    // if (RET < 0)
    // {
    //     /* code */
    //     printf("fail to allocate hole\n");
    // }
    



    close(fd);

    return 0;
}