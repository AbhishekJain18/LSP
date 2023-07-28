//write a program which accepts the file name from user and read the whole file
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXFLESZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;
    char buffer[MAXFLESZE] = {'\0'};

    if(argc != 2)
    {
        printf("insuffient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open a file\n");
        return -1;
    }

    while((ret = read(fd,buffer,sizeof(buffer))) != 0)
    {
        write(1,buffer,sizeof(buffer));
    }


    close(fd);


    return 0;
}