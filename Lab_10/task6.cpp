#include "henfactory.h"
#include<iostream>

int task6()
{
    counrtynum counrty;
    printf("�롥�� ����� ��࠭��:\n");
    printf("%d. �����\n",Russian);
    printf("%d. ��ࠨ��\n",Ukrainian);
    printf("%d. �������\n",Moldovan);
    printf("%d. ��������\n",Belarusian);
    scanf("%d",&counrty);
    HenFactory farm;
    if (counrty<=Belarusian)
    std::cout<<farm.getHen(counrty)->getDescription()<<'\n';
    return 1;
}
