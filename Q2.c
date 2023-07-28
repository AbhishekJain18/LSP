// write a program which accepts file name from user and write string in that.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define MAXFLESZE 1029

int main(int argc, char* argv[])
{
    int fd =0;
    char buffer[MAXFLESZE] = {'\0'};
    fd = open(argv[1], O_RDWR);

    if (fd == -1)
    {
        printf("unable to open file \n");
        return -1;
    }
    //copy our input string in buffer 
    strcpy(buffer,argv[2]);

    write(fd,buffer,MAXFLESZE);

    close(fd);

    return 0;
}