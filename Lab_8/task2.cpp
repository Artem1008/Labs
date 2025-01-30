#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <myfuct.h>

#define COUNTPAIR 3
void Algtask2(std::vector<int>& vec,const std::list<int>& list);

void task2()
{
    std::vector<int> vec;
    CreateCont(vec,10);
    std::cout<<"Вестор:\n"<<vec;
    std::list<int> list;
    CreateCont(list,10);
    std::cout<<"Список:\n"<<list;
    Algtask2(vec,list);
    std::cout<<"Смешанный вектор:\n"<<vec;
    //b
    vec.push_back(Average(vec));
    std::cout<<"Среднее:\n"<<vec.back();
    //c
    std::map<int,char*> map;
    int num;
    char * text;
    printf("\n");

    int count=COUNTPAIR;
    while(count--)
    {
        printf("Введите свои любимые \"чего-нибудь\" в виде \"номер строка\":");
        if(scanf("%d%s",&num,&text)==0)
        {
            printf("Ошибка ввода, попробуйте ещё раз\n");
            fflush(stdin);
            count++;
        }
        else
        {
            map[num]=text;
        }
    }
    printf("Топ-3 Вашего любимого чего-нибудь:\n");
    for(auto& var:map)
    {
        printf("%d. %s\n",var.first,&var.second);
    }
}

void Algtask2(std::vector<int>& vec,const std::list<int>& list)
{
    std::vector<int>::iterator itvec=vec.begin()+1;
    std::list<int>::const_iterator itlist=list.cbegin();
    while(itvec!=vec.end()&&itlist!=list.cend())
    {
        *itvec=*itlist;
        std::advance( itvec, 2 );
        std::advance( itlist, 2 );
    }
}
