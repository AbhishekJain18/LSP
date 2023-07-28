//write a structure in file 
#pragma pack(1)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

struct Student{
int iRollNo;
char Sname[20];
float fMarks;
};

int main(int agrc, char* argv[])
{

    struct Student sobj;
    int fd = 0;
    sobj.RollNo = 21;
    sobj.Marks = 92.39;

    strcpy(sobj.Sname,"Abhishek");


    fd = creat(argv[1], 0777);
    write(fd,&sobj,sizeof(sobj));

    

    return 0;
}