#include "henfactory.h"
#include<iostream>

int task6()
{
    counrtynum counrty;
    printf("Выберите номер странны:\n");
    printf("%d. Россия\n",Russian);
    printf("%d. Украина\n",Ukrainian);
    printf("%d. Молдова\n",Moldovan);
    printf("%d. Беларусь\n",Belarusian);
    scanf("%d",&counrty);
    HenFactory farm;
    if (counrty<=Belarusian)
    std::cout<<farm.getHen(counrty)->getDescription()<<'\n';
    return 1;
}
