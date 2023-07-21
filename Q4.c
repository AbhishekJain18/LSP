//write a program which accepts file name from use and displays all info 
#include<stdio.h>
#include<fcntl.h>
#include <sys/stat.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    //this structure decleared in header file <sys/stat.h>
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    // fetching all info in object of stat structure
    if(-1 ==stat(argv[1],&sobj))
    {
        printf("Error in getting INFO !!!");
        return -1;
    }

    printf("File Name : %s\n", argv[1]);     
    printf("Inode NO : %d\n",sobj.st_ino);
    printf("Size of file : %ld\n", sobj.st_size);

    return 0;
}