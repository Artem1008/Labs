#include "main.h"
#include <cstring>

#define MAX_CHAR 80

void task4()
{
     char text[25][MAX_CHAR];
     int line=0;
     std::cout<<"Введите строки\n";
     for(int i=0;i<25;i++)
     {
         std::cin.getline(text[i], MAX_CHAR);
         if (text[i][0]=='\0')
         {
             line=i;
             break;
         }
     }
     SortSting(text[0],line);
     PrintfSting(text[0],line);
}
int SortSting(char ch[] ,int line)
{
    int type;
    printf("Введите тип сортировки:\n");
    printf("1. По длине\n");
    printf("2. По алфавиту\n");
    if(ChekValue(type)==-1) return -1;
    switch(type)
    {
    case 1:
        SortLength(ch,line);
        break;
    case 2:
         SortABC(ch,line);
        break;
    default:
         printf("неверно ввели тип");
    }
}
void SortABC(char ch[] ,int line)
{
    for(int i = 0; i < line; i++)
    {
        int LittlePosition = LookLittleABC(ch, i, line);
        CharSwap(ch, i,LittlePosition);
    }
}
int LookLittleABC(char ch[],int start, int size)
{
    int LittlePosition=start;
    for(int i=start;i<size;i++)
    {
        for(int j=0;j<MAX_CHAR;j++)
        {
            char temp1=ch[LittlePosition*MAX_CHAR+j];
            char temp2=ch[i*MAX_CHAR+j];
            if(temp1=='\0'||temp2=='\0') break;
            if(temp1>temp2)
             {
                LittlePosition=i;
             }
        }
    }
    return LittlePosition;
}

void SortLength(char ch[] ,int line)
{
    for(int i = 0; i < line; i++)
    {
        int LittlePosition = LookLittleLength(ch, i, line);
        CharSwap(ch, i,LittlePosition);
    }
}
void CharSwap(char* ch1,int begin,int end)
{
    char* temp=(char*)malloc(MAX_CHAR);
    strcpy(temp,ch1+begin*MAX_CHAR);
    strcpy(ch1+begin*MAX_CHAR,ch1+end*MAX_CHAR);
    strcpy(ch1+end*MAX_CHAR,temp);
}
int LookLittleLength(char ch[],int start, int size)
{
    std::string temp1;
    std::string temp2;
    int LittlePosition=start;
    for(int i=start;i<size;i++)
    {
        temp1=&ch[LittlePosition*MAX_CHAR];
        temp2=&ch[i*MAX_CHAR];
        if(temp1.length()>temp2.length()) LittlePosition=i;
    }
    return LittlePosition;
}
void PrintfSting(const char ch[] ,int line)
{
    for(int i=0;i<line;i++)
    {
         std::cout<<&ch[i*MAX_CHAR]<<'\n';
    }
}
template<typename T>
int ChekValue(T &Value)
{
    int count=5;
    for(;count>=0;count--)
    {
        std::cin>>Value;
        std::cin.ignore(32767,'\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout<<"Вы ввели некоректное значение\n";
        }
        else return 1;
    }
    std::cout<<"Привышено число попыток ввода данных\n";
    return -1;
}
