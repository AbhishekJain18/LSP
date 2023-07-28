#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define MAXFLESZE 1024

int main(int argc, char* argv[])
{

    int fdsrc = 0, fdDest = 0;
    int retRead = 0;
    char BufferSrc[MAXFLESZE] ={'\0'};
    
    if(argc != 3 )
    {
        printf("insufficent arguments\n");
        return -1;
    }    

    fdsrc = open(argv[1],O_RDONLY);
    fdDest = creat(argv[2], 0777);

    if(fdsrc== -1)
    {
        printf("unable to open the file\n");
        return -1;
    }

    if(fdDest == -1)
    {
        printf("unable to create file\n");
        close(fdsrc);
        return -1;
    }

    while((retRead = read(fdsrc,BufferSrc,sizeof(BufferSrc))) != 0)
    {
        write(fdDest,BufferSrc,sizeof(BufferSrc));
        memset(BufferSrc,0,sizeof(BufferSrc));
    }

    close(fdsrc);
    close(fdDest);
    
    return 0;
}