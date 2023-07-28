//write and then read structure from file 
#pragma pack(1)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

struct Employee{
int iEmployeeID
char Name[20];
char Position[4];
};

int main(int agrc, char* argv[])
{

    struct Employee eobj;
    int fd = 0;
    eobj.iEmployeeID = 49400;

    strcpy(eobj.Name,"Abhishek");
    strcpy(eobj.Position,"DEV");

    fd = creat(argv[1], 0777);
    write(fd,&eobj,sizeof(sobj));

    ret = read(fd,&eobj,sizeof(eobj));

    printf("roll NO : %d \n",eobj.iEmployeeID);
	printf("roll NO : %s \n",eobj.Name);
    printf("roll NO : %s \n",eobj.Position);
 

    return 0;
}