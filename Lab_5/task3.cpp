#include "main.h"

struct Continent
{
    std::string name;
};
struct Country
{
    std::string Capital;
    std::string name;
};
struct Region
{
    std::string name;
};
struct City
{
    std::string name;
    Region myRegion;
    Country myCountry;
    Continent myContinent;
};
void InitWorld( std::map<std::string, City> &mCity,City* pCity)
{
    mCity["Город 1"]={"Город 1",{"Провинция 1"},{"Столица 1","Городостан 1"},{"Атлантида 1"}};
    mCity["Город 2"]={"Город 2",{"Провинция 1"},{"Столица 1","Городостан 1"},{"Атлантида 1"}};
    mCity["Город 3"]={"Город 3",{"Провинция 3"},{"Столица 3","Городостан 3"},{"Атлантида 3"}};
    mCity["Город 4"]={"Город 4",{"Провинция 4"},{"Столица 4","Городостан 4"},{"Атлантида 4"}};
    mCity["Город 5"]={"Город 5",{"Провинция 5"},{"Столица 5","Городостан 5"},{"Атлантида 5"}};
    mCity["Город 6"]={"Город 6",{"Провинция 6"},{"Столица 6","Городостан 6"},{"Атлантида 6"}};
    mCity["Город 7"]={"Город 7",{"Провинция 7"},{"Столица 7","Городостан 7"},{"Атлантида 7"}};
    mCity["Город 8"]={"Город 8",{"Провинция 8"},{"Столица 8","Городостан 8"},{"Атлантида 8"}};
    mCity["Город 9"]={"Город 9",{"Провинция 9"},{"Столица 9","Городостан 9"},{"Атлантида 9"}};
    mCity["Город 10"]={"Город 10",{"Провинция 10"},{"Столица 10","Городостан 10"},{"Атлантида 10"}};

    pCity[0]={"Город 1",{"Провинция 1"},{"Столица 1","Городостан 1"},{"Атлантида 1"}};
    pCity[1]={"Город 2",{"Провинция 2"},{"Столица 2","Городостан 2"},{"Атлантида 2"}};
    pCity[2]={"Город 3",{"Провинция 3"},{"Столица 3","Городостан 3"},{"Атлантида 3"}};
    pCity[3]={"Город 4",{"Провинция 4"},{"Столица 4","Городостан 4"},{"Атлантида 4"}};
    pCity[4]={"Город 5",{"Провинция 5"},{"Столица 5","Городостан 5"},{"Атлантида 5"}};
    pCity[5]={"Город 6",{"Провинция 6"},{"Столица 6","Городостан 6"},{"Атлантида 6"}};
    pCity[6]={"Город 7",{"Провинция 7"},{"Столица 7","Городостан 7"},{"Атлантида 7"}};
    pCity[7]={"Город 8",{"Провинция 8"},{"Столица 8","Городостан 8"},{"Атлантида 8"}};
    pCity[8]={"Город 9",{"Провинция 9"},{"Столица 9","Городостан 9"},{"Атлантида 9"}};
    pCity[9]={"Город 10",{"Провинция 10"},{"Столица 10","Городостан 10"},{"Атлантида 10"}};

    for(auto v:mCity)
    {
        std::cout<< v.second.myContinent.name<<" "<<v.second.myRegion.name<<" "<<v.second.myCountry.Capital<<" "<<v.second.myCountry.name<<" "<<v.second.name<<'\n';
    }
    printf("\n");
    for(int i=0;i<10;i++)
    {
        std::cout<<pCity[i].myContinent.name<<" "<<pCity[i].myRegion.name<<" "<<pCity[i].myCountry.Capital<<" "<<pCity[i].myCountry.name<<" "<<pCity[i].name<<'\n';
    }
}
void SeekCity(City* pCity,std::string UserCity,int size)
{
    for(int i=0;i<size;i++)
    {
        if (pCity[i].name==UserCity)
        {
            std::cout<<pCity[i].myContinent.name<<" "<<pCity[i].myRegion.name<<" "<<pCity[i].myCountry.Capital<<" "<<pCity[i].myCountry.name<<" "<<pCity[i].name<<'\n';
            return;
        }
    }
}
void task3()
{
    std::string UserCity;
    std::map<std::string, City> mCity;
    City* pCity= new City[10];
    InitWorld(mCity,pCity);
    printf("Введите город или q для выхода:");
    std::getline(std::cin,UserCity);
    if (UserCity=="q") exit(0);
    std::cout<<  mCity[UserCity].myContinent.name<<" "<<mCity[UserCity].myRegion.name<<" "<<mCity[UserCity].myCountry.Capital<<" "<<mCity[UserCity].myCountry.name<<" "<<mCity[UserCity].name<<'\n';
    SeekCity(pCity,UserCity,10);
}

