//write a program which accept name and mode from user 
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int fd = 0;
    int mode = 0;

    // checking total no of arguments
    if(argc != 3)
    {
        printf("Insuffient arguments\n");
        return -1;
    }
    
    // user give mode in string format and need to convert it into macro
    if(strcmp(argv[2],"Read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"REWRI") ==0)
    {
        mode = O_RDWR;
    }

    fd = open(argv[1],mode);

    // check open is opened or not
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else{
        printf("file open successfully\n");
    }

    //close file since it is not in use
    close(fd);

    return 0;
}