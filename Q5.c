// remove all data from offset
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fd = 0, offset = 0;
    int lenTruncate = 0;
    struct stat sobj;
    if(argc != 3)
    {
        printf("Insufficient argv\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR|O_TRUNC);
    if(fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }
    fstat(fd, &sobj);
    offset = atoi(argv[2]);
    //lenTruncate = sobj.st_size - offset;

    lseek(fd,offset,SEEK_CUR);
    ftruncate(fd,offset);

    close(fd);
    
    return 0;
}