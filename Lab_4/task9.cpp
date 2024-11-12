#include "main.h"

int task9()
{
    char* pChar;
    int size=11;
    CreateArray(pChar,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",pChar[i]);
    }
    printf("\n");
    FuncSwap(pChar,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",pChar[i]);
    }
}
void FuncSwap(char* &pArr,int size)
{
    for(int i=1; i<size;i=i+2)
    {
        std::swap(pArr[i-1],pArr[i]);
    }
}
