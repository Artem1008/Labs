#include "main.h"

void task5()
{
    std::string text="Александр             Македонский герой,\tно зачем                же стулья\t                       ломать";

     for(int i=1;i<=(int)text.length();i++)
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
