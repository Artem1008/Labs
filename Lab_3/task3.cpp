#include <iostream>
#include <typeinfo>

auto Initialization()->int
{
    int iValue=1;
    bool bValue(1);
    char cValue{3};
    auto lValue=3147483647;
    std::cout << typeid(iValue).name()<<" "<<typeid(bValue).name()<<" "<<typeid(cValue).name()<<" "<<typeid(lValue).name()<<'\n';
    return 'a';
}

