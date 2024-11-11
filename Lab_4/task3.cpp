#include "main.h"

void task3()
{
    printf("%10s","Алфавит");
    printf("%30s\n","Десятичный код символа");
    for(char i=65;i<91;i++)
    {
         printf("%10c%30i\n",i,i);
    }
    for(char i=97;i<123;i++)
    {
         printf("%10c%30i\n",i,i);
    }
}
