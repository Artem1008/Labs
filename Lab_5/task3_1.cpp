#include "main.h"

void task3_1()
{
    std::string text="����ᠭ��             �������᪨� ��ன,\t�� ��祬                �� �����\t                       ������";

    for(int i=0;i<=(int)text.length();i++)
    {
        if (text[i]=='\t') text[i]=' ';
        if ((text[i]==' ')&&(text[i-1]==' '))
        {
            i--;
            text.erase(i,1);
        }
    }
    std::cout<<text;
}
