//program which accepts to directory from user and move file from one directory to other 
#include <stdio.h>
#include <sys/dir.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR * ptrdir = NULL;
    struct dirent *ptrDirent = NULL;
    char OldFileName[275] = {'\0'};
    char NewFileName[275] = {'\0'};

    if(argc != 3)
    {
        printf("Insuffuient arguments\n");
        return -1;
    }
    
    ptrdir = opendir(argv[1]);
    if(ptrdir == NULL)
    {
        printf("unable to open directory\n");
        return -1;
    }

    while((ptrDirent = readdir(ptrdir))!=NULL)
    {
        sprintf(OldFileName,"%s/%s",argv[1],ptrDirent->d_name);     // creating file name
        sprintf(NewFileName,"%s/%s",argv[2],ptrDirent->d_name);     // creating file name

        rename(OldFileName,NewFileName);                            // renaming it 

        memset(OldFileName,0,sizeof(OldFileName));
        memset(NewFileName,0,sizeof(NewFileName));
    }
    

    closedir(ptrdir);

    return 0;
}
