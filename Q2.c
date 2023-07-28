//create a new directory
#include <stdio.h>
#include <sys/dir.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    DIR *ptrDir = NULL;
    int ret = 0;
    if(argc != 2)
    {
        printf("insufficient arguments\n");
        return -1;
    }
    
    ret = mkdir(argv[1],0777);
    if(!ret)
    {
        printf("unable to create directory\n");
    }
    else{
        printf("Directory is created\n");
    }
 

    return 0;
}