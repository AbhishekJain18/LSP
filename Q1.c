#include <stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iAns = 0;
    scanf("%d", &iNo1);     // taking values from file

    scanf("%d", &iNo2);     // taking values from file

    iAns = iNo1 + iNo2;

    printf("Addition is : %d\n", iAns);  

    return 0;
}