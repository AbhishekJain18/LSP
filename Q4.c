//delete empty files from directory 
#include<stdio.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
    DIR *ptrdir = NULL
    struct stat sobj;    
    struct dirent *ptrDirent = NULL;
    

    if(argc != 2)
    {
        printf("Insuffient arguemnts\n");
        return -1;
    }

    ptrdir = opendir(argv[1]);
    if(prtdie == NULL)
    {
        printf("unable to open directory\n");
        return -1;
    }

    while((ptrDirent = readdir(ptrdir)) != NULL)
    {
        stat(ptrDirent->d_name,&sobj);
        if(sobj.st_size == 0)
        {
            remove(ptrDirent->d_name);
        }      /// use stat struct for size of file 
    }

    closedir(ptrdir);

    return 0;
}