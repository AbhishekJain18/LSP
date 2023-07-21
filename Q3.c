//open the file and check the weather we can open in given mode 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int mode = 0;
    //checking req number of arguments from use 
    if(argc != 3)
    {
        printf("Insuffient arguments \n");
        return -1;
    }

    // user give mode in string format and need to convert it into macro
    // and access too
    if(strcmp(argv[2],"Read") == 0  &&          // validate input 
        0 == access(argv[2],R_OK)               // validate access
    )
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0 &&
        0 == access(argv[2],W_OK))
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"REWRI") ==0 &&
        0 == access(argv[2],R_OK|W_OK)
    )
    {
        mode = O_RDWR;
    }

    fd = open(argv[1],mode);

    //check file is open or not 
    if(fd == -1){
        printf("unable to open file \n");
        return -1;
    }
    else{
        printf("file open successfully \n");
    }

    //close file since it is not in use
    close(fd);

    return 0;
}