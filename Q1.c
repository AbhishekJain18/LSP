// A1 - Q1 write a program which accepts a file name from use and open that file 

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    
    int fd = 0;
    // check for number of argumenrts from command line
    if (argc != 2)
    {
        printf("Insuffient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd ==  -1)
    {
        printf("unable to open file\n");
        return -1;
    }
    else
    {
        printf("file open succefully\n");
    }

    //close file since it is not in use
    close(fd);

    return 0;
}