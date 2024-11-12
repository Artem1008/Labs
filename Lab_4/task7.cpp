#include "main.h"

int task7()
{
    std::string Engine="UVW";
    int size=Engine.length();
   for(int a1=0; a1<size;a1++)
    {
        for(int a2=0; a2<size;a2++)
        {
            if(a1!=a2)
            {
                for(int a3=0; a3<size;a3++)
                {
                    if(a2!=a3&&a1!=a3)
                    {
                        printf("%c %c %c\n",Engine[a1],Engine[a2],Engine[a3]);
                    }
                }
            }
        }
    }
}
