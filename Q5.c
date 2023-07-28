// largest file in directory
#include <stdio.h>
#include <sys/dir.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char * argv[])
{
    int Maxsize = 0;
    char DirecotryName[20] = {'\0'};
    char name[276]  = {'\0'};
    char largestFileName[276] = {'\0'};
    DIR *dirobj = NULL;
    struct dirent *direntObj = NULL;
    struct stat sobj;

    printf("Enter directory name : \n");
    scanf("%s", DirecotryName);

    dirobj = opendir(DirecotryName);
    if(dirobj == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((direntObj = readdir(dirobj)) != NULL)
    {
        sprintf(name,"%s/%s",DirecotryName,direntObj->d_name);
        stat(name,&sobj);
        if( (sobj.st_size > Maxsize) &&         // maximum condition 
            S_ISREG(sobj.st_mode) )             // checking file type to avoid . and ..
        {
            printf("file name : %s File size : %d \n",name,sobj.st_size);
            Maxsize = sobj.st_size;
            strcpy(largestFileName,name);
        }
    }

    printf("%s is the largest file in directory\n",largestFileName);

    return 0;
}