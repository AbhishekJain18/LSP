//read 20 bytes from given position
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 20

int main(int argc, char *argv[])
{
    int iPos = 0, fd = 0, ret = 0;
    char Buffer[20] = {'\0'};
    if(argc != 3)
    {
        printf("insuffient arguments\n");
        return -1;
    }

    iPos = atoi(argv[2]);

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }

    lseek(fd,iPos,0);

    ret = read(fd,Buffer,MAXSIZE);
    
    printf("Data from file : \n");


    write(1,Buffer,MAXSIZE);


    return 0;
}